
#include "clienttcpsocket.h"
#include "global.h"
#include<QMessageBox>
#include "userlist.h"
QString ClientTcpSocket::ServerHost="";
int ClientTcpSocket::TCPPort=6666;
int ClientTcpSocket::UDPPort=25252;
ClientTcpSocket::ClientTcpSocket(QObject *parent) :
    QTcpSocket(parent)
{
    in.setDevice(this);
    in.setVersion(VERSION);
    udpsocket=new QUdpSocket(this);
    udpsocket->bind(UDPPort,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    connect(this,SIGNAL(readyRead()),this,SLOT(ReadMessage()));
    connect(this,SIGNAL(connectFailed()),this,SLOT(HandleConnectFailed()));
    connect(this,SIGNAL(NoRespond()),this,SLOT(HandleNoRespond()));
    connect(this,SIGNAL(InvalidMessage()),this,SLOT(HandleInvalidMessage()));
    connect(udpsocket,SIGNAL(readyRead()),this,SLOT(UDPReadMessage()));
    connect(this,SIGNAL(ServerError(QDataStream&)),this,SLOT(HandleServerError(QDataStream&)));
    if(ServerHost=="")
        findServer();
}
bool ClientTcpSocket::connectToServer(){
    abort();
    if(ServerHost=="")
        findServer();
    connectToHost(ServerHost,TCPPort);
    if(waitForConnected())
        return true;
    else{
        emit connectFailed();
        return false;
    }
}

void ClientTcpSocket::ReadMessage(){
    bool flag;
    QDataStream in(this);
    in.setVersion(VERSION);
    MessageSize bufferSize=0;
    int type;
    if(bytesAvailable()<(int)sizeof(MessageSize)){
      // emit InvalidMessage();
        return;
    }
    in>>bufferSize;
    if(bufferSize>bytesAvailable()){
       // emit InvalidMessage();
        return;
    }
    in>>type;
    switch(type){
    case MessageType::Login:
        in>>flag;
        if(flag){
            User *user=new User;
            (*user).readID(in).readNickname(in).readIpAddress(in);
            emit LoginSuccess(user);
        }
        else{
            QString errorString;
            in>>errorString;
            emit LoginFailed(errorString);
        }
        break;
    case MessageType::Register:
        in>>flag;
        if(flag){
            emit RegisterSuccess();

        }
        else{
            QString errorString;
            in>>errorString;
            emit RegisterFailed(errorString);
        }
        break;
    case MessageType::UserList:
        ReceiveUserList(in);
        break;
    case MessageType::Error:
        emit ServerError(in);
        break;
    case MessageType::NicknameUpdate:
    {
        bool flag;
        in>>flag;
        if(!flag){
            QString err;
            in>>err;
            QMessageBox::warning(0,"�޸��ǳ�ʧ��",err);
        }
    }
    break;
    default:
        emit InvalidMessage();
    }
}
void ClientTcpSocket::HandleNoRespond()
{
    QMessageBox::critical(0,"������δ��Ӧ","������δ��Ӧ",QMessageBox::Cancel);
}

void ClientTcpSocket::HandleConnectFailed()
{
    QMessageBox::critical(0,"δ���ӵ�������","δ���ӵ�������",QMessageBox::Cancel);
}

void ClientTcpSocket::WriteAndWait(QByteArray &buffer, int timeout){
    if(!(state()==QAbstractSocket::ConnectedState))
        connectToServer();
    if(!(state()==QAbstractSocket::ConnectedState))
        return;
    write(buffer);
    waitForBytesWritten();
    if(!waitForReadyRead(timeout))
        emit NoRespond();
}

void ClientTcpSocket::HandleInvalidMessage(){
    QMessageBox::warning(0,"δ���յ���Ч����","δ���յ���Ч����");
}

void ClientTcpSocket::HandleServerError(QDataStream &in){
    QString ErrStr;
    in>>ErrStr;
    QMessageBox::warning(0,"����",ErrStr);
}

void ClientTcpSocket::findServer(){

    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    out.setVersion(VERSION);
    out<<MessageType::GetServer;
    out<<0;
    out<<getlocalIP();
    udpsocket->writeDatagram(buffer,QHostAddress::Broadcast,UDPPort);
    //�����ܻ��յ��Լ���UDP�㲥������waitForReadyRead()û������
}

QString ClientTcpSocket::getlocalIP(){
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    QString tmp1;
    QString holdaddr="169.254.";
    qDebug()<<list;
    foreach (QHostAddress address,list){
       if(address.protocol() == QAbstractSocket::IPv4Protocol){
                tmp1=address.toString();
                if(!(tmp1.contains(holdaddr)))      //����������ַ
                    return tmp1;
       }
    }
    return "";
}

void ClientTcpSocket::UDPReadMessage(){
    while(udpsocket->hasPendingDatagrams()){
        QByteArray buffer;
        buffer.resize(udpsocket->pendingDatagramSize());
        udpsocket->readDatagram(buffer.data(),buffer.size());
        QDataStream in(&buffer,QIODevice::ReadOnly);
        in.setVersion(VERSION);
        int type;
        QString tmp;
        in>>type;
        switch(type){
        case MessageType::GetServer:
        {   int flag;   //����ʶ����Ϣ�Ƿ��ɷ���˷���
            in>>flag;
            if(flag==1){
                in>>tmp;
                ServerHost=tmp;
                emit IniSuccess();
            }
            break;
        }
        case MessageType::UserStatusUpdate:
            ReceiveUpdate(in);
            break;
        case MessageType::CreateRoom:
            ReceiveNewRoom(in);
            break;
        case MessageType::NewParticipant:
        {
            int room,size,ID;
            in>>room>>size>>ID;
            emit UpdateUserNumber(room,size);
            break;
        }
        case MessageType::ParticipantLeft:
        {
            int room,size,ID;
            in>>room>>size>>ID;
            emit UpdateUserNumber(room,size);
            break;
        }
        case MessageType::DeleteRoom:
        {
            int room;
            in>>room;
            emit DeleteRoom(room);
            break;
        }
        case MessageType::NicknameUpdate:
        {
            int ID;
            QString NewNick;
            in>>ID>>NewNick;
            emit NicknameUpdate(ID,NewNick);
        }
        default:
            break;
        }
    }
}

void ClientTcpSocket::ReceiveUserList(QDataStream &in){
    int num;
    in>>num;
    UserList *users=new UserList(this);
    for(int i=0;i<num;i++){
        User *user=new User;
        (*user).readID(in).readNickname(in).readIpAddress(in).readStatus(in);
        users->insertByID(user);
    }
    emit ULReceived(users);
    in>>num;
    for(int i=0;i<num;i++){
        int roomID,UsrNum;
        QString roomName;
        in>>roomID>>roomName>>UsrNum;
        emit newRoom(roomID,roomName,UsrNum,-1);
    }
}

void ClientTcpSocket::ReceiveUpdate(QDataStream &in){
    User *user=new User;
    user->readStatus(in);
    switch(user->getStatus()){
    case User::Online:
        (*user).readID(in).readNickname(in).readIpAddress(in);
        emit newPtcp(user);
        break;
    case User::Offline:
        int id;
        in>>id;
        emit PtcpLeft(id);
        break;
    }

}

void ClientTcpSocket::ReceiveNewRoom(QDataStream &in)
{
    //out<<type<<����ID<<������<<��������<<������ID
    int roomID,size,userID;
    QString roomName;
    in>>roomID>>roomName>>size>>userID;
    emit newRoom(roomID,roomName,size,userID);
}


