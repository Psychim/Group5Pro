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
//查询正在登录的用户
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
//处理用户登录
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
            errorstr=tr("用户已登录");
        }
    }
    else {
        flag=false;
        errorstr=tr("用户名或密码错误");
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
        emit Error(tr("无效的消息"));
        return;
    }
    in>>bufferSize;
    if(bufferSize>ServerTcpSocket->bytesAvailable()){
        emit Error(tr("无效的消息"));
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
        //case User::Online: 用户上线会在处理登录部分进行处理

        case User::Offline:
        {
            int tmp_ID;
            in>>tmp_ID;
            QString peerIP=ServerTcpSocket->peerAddress().toString();
            User *tmp_User=OnlineUsers->searchByID(tmp_ID);
            if(peerIP==tmp_User->getIpAddress()){   //校验IP地址，确保消息是由本人发出
                OnlineUsers->removeByID(tmp_ID);
                tmp_User->setStatus(User::Offline);
                emit UserStatusUpdate(tmp_User);
            }
        }
            break;
        }
        break;
    default:
        emit Error(tr("无效的消息"));
    }
}
//处理用户注册
void Server::HandleUserRegister(QDataStream &in)
{
    QMap<QString,QString> userdata;
    QString tmp;
    QString errorstr="";
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    in>>tmp;
    if(tmp=="")
        errorstr=tr("用户名不能为空");
    userdata["username"]=tmp;
    in>>tmp;
    if(tmp=="")
        errorstr=tr("昵称不能为空");
    userdata["nickname"]=tmp;
    in>>tmp;
    if(tmp=="")
        errorstr=tr("密码不能为空");
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
//将新用户信息添加进数据库
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
        *errorinfo=tr("用户名已存在");
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
//不需要在服务端处理数据的消息类型使用该函数回应消息
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
        out<<ActiveRooms->size();
        for(int i=0;i<ActiveRooms->size();i++){
            Room *tmp= (*ActiveRooms)[i];
            out<<tmp->getID()<<tmp->getName()<<tmp->ChattingUsers.size();
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
//任意用户状态改变时进行广播
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
//服务器初始化
void Server::Init()
{
    if(!listen(QHostAddress::Any,TCPPort)){
        QMessageBox::critical(0,"无法开始监听",
                              "无法开始监听",QMessageBox::Cancel);
        return;
    }
    if(!connectToDb()){
        QMessageBox::critical(0,"无法打开数据库",
                              "建立数据库连接失败",QMessageBox::Cancel);
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
//获取本机IP
QString Server::getlocalIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    QString tmp1;
    QString holdaddr="169.254.";
    foreach (QHostAddress address,list){
       if(address.protocol() == QAbstractSocket::IPv4Protocol){
                tmp1=address.toString();
                if(!(tmp1.contains(holdaddr))){    //跳过保留地址
                    qDebug()<<tmp1;
                    return tmp1;
                }
       }
    }
    return "";
}
//终止服务器的运行
void Server::Stop()
{
    close();
    db.close();
    ServerUdpSocket->abort();
    if(ServerTcpSocket!=NULL)
        ServerTcpSocket->abort();
}
//三件事：返回聊天室用户名单给该用户；将新加入用户加入响应的聊天室；广播该用户加入的消息
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
        out<<tr("房间不存在");
        out.device()->seek(0);
        out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
        ServerTcpSocket->write(buffer);
        return;
    }
    if(user==NULL){
        out<<MessageType::Error;
        out<<tr("用户不存在或已下线");
        out.device()->seek(0);
        out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
        ServerTcpSocket->write(buffer);
        return;
    }
    if(room->ChattingUsers.searchByID(ID)){
        out<<MessageType::Error;
        out<<tr("用户已加入聊天室");
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
//接收创建者ID和房间名，创建新聊天室，并广播聊天室信息和创建者ID
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
        qDebug()<<tr("In HandlePtcpLeft: 未找到房间");
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
        //buffer.clear();   会导致接下来写入的信息有问题，为什么？
        QByteArray buffer2;
        QDataStream out2(&buffer2,QIODevice::WriteOnly);
        out2<<MessageType::DeleteRoom;
        out2<<roomID;
        ServerUdpSocket->writeDatagram(buffer2,QHostAddress::Broadcast,UDPPort);
        ServerUdpSocket->waitForBytesWritten();
    }
}
