#include "server.h"
#include"user.h"
#include"global.h"
#include<QtNetwork>
#include<QSqlQuery>
#include<QSqlRecord>
#include<QMessageBox>
#include<QDebug>
#include<QSqlError>
#include<QSqlResult>
#include"userlist.h"
#include"roomlist.h"
Server::Server(QObject *parent) :
    QTcpServer(parent)
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("MainDB.db");
    ServerTcpSocket=NULL;
    OnlineUsers=new UserList(this);
    ActiveRooms=new RoomList(this);
    ServerUdpSocket=new QUdpSocket(this);
    TCPPort=6666;
    UDPPort=25252;
    connect(this,SIGNAL(Error(QString)),this,SLOT(HandleError(QString)));
    connect(ServerUdpSocket,SIGNAL(readyRead()),this,SLOT(UdpReadMessage()));
    connect(this,SIGNAL(UserStatusUpdate(User*)),this,SLOT(StatusBroadcast(User*)));

}
//��ѯ���ڵ�¼���û�
User * Server::LoginQuery(QMap<QString,QString> Info){
    if(!db.isOpen())
        return NULL;
    QSqlQuery * query=new QSqlQuery;
    query->prepare("SELECT * FROM users WHERE username = :username AND "
                       "password = :password");
    query->bindValue(":username", Info["username"]);
    query->bindValue(":password",Info["password"]);
    query->exec();
    qDebug()<<query->last()<<endl<<query->lastError();
    if(query->isValid()){
        QSqlRecord rec=query->record();
        int id=query->value(rec.indexOf("id")).toInt();
        QString name=query->value(rec.indexOf("nickname")).toString();
        User * LoggedUser=new User(this,id,name,Info["IpAddress"],User::Online);

        return LoggedUser;
    }
    else
        return NULL;
}
//�����û���¼
void Server::HandleUserLogin(QDataStream &in){
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    QMap<QString,QString> userdata;
    QString tmp;
    QString errorstr;
    bool flag=true;
    in>>tmp;
    userdata["username"]=tmp;
    in>>tmp;
    userdata["password"]=tmp;
    userdata["IpAddress"]=ServerTcpSocket->peerAddress().toString();
    User *Result=LoginQuery(userdata);
    out.setVersion(VERSION);
    out<<(MessageSize)0;
    out<<MessageType::Login;
    if(Result){
        if(OnlineUsers->searchByID(Result->getID())==NULL){
            OnlineUsers->insertByID(Result);
            Result->setParent(this);
            emit UserStatusUpdate(Result);
        }
        else {
            flag=false;
            errorstr=tr("�û��ѵ�¼");
        }
    }
    else {
        flag=false;
        errorstr=tr("�û������������");
    }
    if(flag){
        out<<true;
        out<<Result->getID()<<Result->getNickname()<<Result->getIpAddress();

    }
    else{
        out<<false;
        out<<errorstr;
    }
    out.device()->seek(0);
    out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
    ServerTcpSocket->write(buffer);
}

bool Server::connectToDb(){
    if(db.open()){
        QSqlQuery query;
        query.exec("create table users(id integer primary key, username varchar(20) not null,"
                   "nickname varchar(30) not null,password varchar(255) not null)");
        qDebug()<<query.lastError();
        return true;
    }
    else
        return false;
}
void Server::acceptConnection(){
    ServerTcpSocket=nextPendingConnection();
    connect(ServerTcpSocket,SIGNAL(readyRead()),this,SLOT(TcpReadMessage()));
    connect(ServerTcpSocket,SIGNAL(disconnected()),ServerTcpSocket,SLOT(deleteLater()));
}
void Server::TcpReadMessage(){
    QDataStream in(ServerTcpSocket);
    in.setVersion(VERSION);
    MessageSize bufferSize=0;
    int type;
    if(ServerTcpSocket->bytesAvailable()<(int)sizeof(MessageSize)){
        emit Error(tr("��Ч����Ϣ"));
        return;
    }
    in>>bufferSize;
    if(bufferSize>ServerTcpSocket->bytesAvailable()){
        emit Error(tr("��Ч����Ϣ"));
        return;
    }
    in>>type;
    switch(type){
    case MessageType::Login:
        HandleUserLogin(in);
        break;
    case MessageType::Register:
        HandleUserRegister(in);
        break;
    case MessageType::UserList:
        Respond(MessageType::UserList);
        break;
    case MessageType::NewParticipant:
    {
        HandleNewPtcp(in);
        break;
    }
    case MessageType::ParticipantLeft:
        HandlePtcpLeft(in);
        break;
    case MessageType::CreateRoom:
        HandleCreateRoom(in);
        break;
    case MessageType::UserStatusUpdate:
        int change;
        in>>change;
        switch(change){
        //case User::Online: �û����߻��ڴ����¼���ֽ��д���

        case User::Offline:
        {
            int tmp_ID;
            in>>tmp_ID;
            QString peerIP=ServerTcpSocket->peerAddress().toString();
            User *tmp_User=OnlineUsers->searchByID(tmp_ID);
            if(peerIP==tmp_User->getIpAddress()){   //У��IP��ַ��ȷ����Ϣ���ɱ��˷���
                OnlineUsers->removeByID(tmp_ID);
                tmp_User->setStatus(User::Offline);
                emit UserStatusUpdate(tmp_User);
            }
        }
            break;
        }
        break;
    default:
        emit Error(tr("��Ч����Ϣ"));
    }
}
//�����û�ע��
void Server::HandleUserRegister(QDataStream &in)
{
    QMap<QString,QString> userdata;
    QString tmp;
    QString errorstr="";
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    in>>tmp;
    if(tmp=="")
        errorstr=tr("�û�������Ϊ��");
    userdata["username"]=tmp;
    in>>tmp;
    if(tmp=="")
        errorstr=tr("�ǳƲ���Ϊ��");
    userdata["nickname"]=tmp;
    in>>tmp;
    if(tmp=="")
        errorstr=tr("���벻��Ϊ��");
    userdata["password"]=tmp;
    out.setVersion(VERSION);
    out<<(MessageSize)0;
    out<<MessageType::Register;
    if(errorstr==QString("")){
        tmp="";
        out<<RegisterQuery(userdata,&tmp);
        if(tmp!=QString(""))
            out<<tmp;
    }
    else{
        out<<false<<errorstr;
    }
    out.device()->seek(0);
    out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
    ServerTcpSocket->write(buffer);
}
//�����û���Ϣ��ӽ����ݿ�
bool Server::RegisterQuery(QMap<QString, QString>Info,QString *errorinfo)
{
    if(!db.isOpen())
        return NULL;
    QSqlQuery * query=new QSqlQuery;
    query->prepare("select * from users where username=:username");
    query->bindValue(":username",Info["username"]);
    query->exec();
    query->next();
    if(query->isValid()){
        *errorinfo=tr("�û����Ѵ���");
        return false;
    }
    query->prepare("INSERT INTO users (username,nickname,password) values(:username,:nickname,"
                       ":password)");
    query->bindValue(":username", Info["username"]);
     query->bindValue(":nickname", Info["nickname"]);
    query->bindValue(":password",Info["password"]);
    query->exec();
    qDebug()<<query->lastError();
    if(LoginQuery(Info)){
        return true;
    }
    else{
        *errorinfo=query->lastError().text();
        return false;
    }
}

void Server::Query(QString statement)
{
    QSqlQuery query;
    query.exec(statement);
    qDebug()<<query.lastError();
}
//����Ҫ�ڷ���˴������ݵ���Ϣ����ʹ�øú�����Ӧ��Ϣ
void Server::Respond(MessageType::MessageType type,QString str)
{
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    out.setVersion(VERSION);
    out<<(MessageSize)0;
    out<<type;
    switch(type){
    case MessageType::Error:
        out<<str;
        break;
    case MessageType::UserList:
        out<<OnlineUsers->size();
        for(int i=0;i<OnlineUsers->size();i++){
            User * tmp=(*OnlineUsers)[i];
            out<<tmp->getID()<<tmp->getNickname()<<tmp->getIpAddress();
            out<<tmp->getStatus();
        }
        break;
    default:
        return;
    }
    out.device()->seek(0);
    out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
    ServerTcpSocket->write(buffer);
}

void Server::HandleError(QString str)
{
    Respond(MessageType::Error,str);
}
//�����û�״̬�ı�ʱ���й㲥
void Server::StatusBroadcast(User *user)
{
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    out.setVersion(VERSION);
    out<<MessageType::UserStatusUpdate;
    out<<user->getStatus();
    switch(user->getStatus()){
    case User::Online:
        out<<user->getID()<<user->getNickname()<<user->getIpAddress();
        break;
    case User::Offline:
        out<<user->getID();
        break;
    }
    ServerUdpSocket->writeDatagram(buffer,QHostAddress::Broadcast,25252);
}
//��������ʼ��
void Server::Init()
{
    if(!listen(QHostAddress::Any,TCPPort)){
        QMessageBox::critical(0,"�޷���ʼ����",
                              "�޷���ʼ����",QMessageBox::Cancel);
        return;
    }
    if(!connectToDb()){
        QMessageBox::critical(0,"�޷������ݿ�",
                              "�������ݿ�����ʧ��",QMessageBox::Cancel);
        return;
     }
    ServerUdpSocket->bind(UDPPort,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
}

void Server::UdpReadMessage()
{
    while(ServerUdpSocket->hasPendingDatagrams()){
        QByteArray bufferin,bufferout;
        QString peerHost;
        int flag;
        int type;
        bufferin.resize(ServerUdpSocket->pendingDatagramSize());
        ServerUdpSocket->readDatagram(bufferin.data(),bufferin.size());
        QDataStream in(&bufferin,QIODevice::ReadOnly);
        QDataStream out(&bufferout,QIODevice::WriteOnly);
        in.setVersion(VERSION);
        out.setVersion(VERSION);
        in>>type;
        switch(type){
        case MessageType::GetServer:
            in>>flag;
            if(flag==1)
                break;
            else{
                in>>peerHost;
                out<<type;
                out<<1;
                out<<getlocalIP();
                ServerUdpSocket->writeDatagram(bufferout,QHostAddress::Broadcast,UDPPort);
            }
        }
    }
}
//��ȡ����IP
QString Server::getlocalIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    QString tmp1;
    QString holdaddr="169.254.";
    foreach (QHostAddress address,list){
       if(address.protocol() == QAbstractSocket::IPv4Protocol){
                tmp1=address.toString();
                if(!(tmp1.contains(holdaddr))){    //����������ַ
                    qDebug()<<tmp1;
                    return tmp1;
                }
       }
    }
    return "";
}
//��ֹ������������
void Server::Stop()
{
    close();
    db.close();
    ServerUdpSocket->abort();
    if(ServerTcpSocket!=NULL)
        ServerTcpSocket->abort();
}
//�����£������������û����������û������¼����û�������Ӧ�������ң��㲥���û��������Ϣ
void Server::HandleNewPtcp(QDataStream &in)
{
    int roomID;
    int ID;
    in>>roomID>>ID;
    Room *room=ActiveRooms->searchByID(roomID);
    User *user=OnlineUsers->searchByID(ID);
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    out.setVersion(VERSION);
    out<<(MessageSize)0;
    if(room==NULL){
        out<<MessageType::Error;
        out<<tr("���䲻����");
        out.device()->seek(0);
        out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
        ServerTcpSocket->write(buffer);
        return;
    }
    if(user==NULL){
        out<<MessageType::Error;
        out<<tr("�û������ڻ�������");
        out.device()->seek(0);
        out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
        ServerTcpSocket->write(buffer);
        return;
    }
    if(room->ChattingUsers.searchByID(ID)){
        out<<MessageType::Error;
        out<<tr("�û��Ѽ���������");
        out.device()->seek(0);
        out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
        ServerTcpSocket->write(buffer);
        return;
    }
    out<<MessageType::NewParticipant;
    out<<roomID;
    for(int i=0;i<room->ChattingUsers.size();i++){
        User *user=room->ChattingUsers[i];
        out<<user->getID();
    }
    out.device()->seek(0);
    out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
    ServerTcpSocket->write(buffer);

    room->NewPtcp(user);

    QByteArray udpbuffer;
    QDataStream udpout(&udpbuffer,QIODevice::WriteOnly);
    udpout.setVersion(VERSION);
    udpout<<MessageType::NewParticipant;
    udpout<<roomID<<room->ChattingUsers.size()<<ID;
    ServerUdpSocket->writeDatagram(udpbuffer,QHostAddress::Broadcast,UDPPort);
    ServerUdpSocket->waitForBytesWritten();
    ServerUdpSocket->writeDatagram(udpbuffer,QHostAddress::Broadcast,UDPPort+2);
    ServerUdpSocket->waitForBytesWritten();
}
//���մ�����ID�ͷ������������������ң����㲥��������Ϣ�ʹ�����ID
void Server::HandleCreateRoom(QDataStream & in)
{
    int ID;
    QString roomName;
    in>>ID>>roomName;
    Room *room=ActiveRooms->NewRoom(roomName);
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    out<<MessageType::CreateRoom;
    out<<room->getID()<<room->getName()<<room->ChattingUsers.size()<<ID;
    ServerUdpSocket->writeDatagram(buffer,QHostAddress::Broadcast,UDPPort);
    ServerUdpSocket->waitForBytesWritten();
}

void Server::HandlePtcpLeft(QDataStream &in)
{
    int roomID,userID;
    in>>roomID>>userID;
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    out.setVersion(VERSION);
    Room *room=ActiveRooms->searchByID(roomID);
    if(room==NULL){
        qDebug()<<tr("In HandlePtcpLeft: δ�ҵ�����");
        return;
    }
    room->PtcpLeft(userID);
    out<<MessageType::ParticipantLeft;
    out<<roomID<<room->ChattingUsers.size()<<userID;
    ServerUdpSocket->writeDatagram(buffer,QHostAddress::Broadcast,UDPPort);
    ServerUdpSocket->waitForBytesWritten();
    ServerUdpSocket->writeDatagram(buffer,QHostAddress::Broadcast,UDPPort+2);
    ServerUdpSocket->waitForBytesWritten();
    if(room->ChattingUsers.size()==0){
        ActiveRooms->DeleteRoomByID(roomID);
        //buffer.clear();   �ᵼ�½�����д�����Ϣ�����⣬Ϊʲô��
        QByteArray buffer2;
        QDataStream out2(&buffer2,QIODevice::WriteOnly);
        out2<<MessageType::DeleteRoom;
        out2<<roomID;
        ServerUdpSocket->writeDatagram(buffer2,QHostAddress::Broadcast,UDPPort);
        ServerUdpSocket->waitForBytesWritten();
    }
}
