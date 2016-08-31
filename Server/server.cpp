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
Server::Server(QObject *parent) :
    QTcpServer(parent)
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("MainDB.db");
    ServerTcpSocket=NULL;
    OnlineUsers=new UserList(this);
    ServerUdpSocket=new QUdpSocket(this);
    TCPPort=6666;
    UDPPort=25252;
    connect(this,SIGNAL(InvalidMessage()),this,SLOT(HandleInvalidMessage()));
    connect(ServerUdpSocket,SIGNAL(readyRead()),this,SLOT(UdpReadMessage()));
    connect(this,SIGNAL(UserStatusUpdate(User*)),this,SLOT(StatusBroadcast(User*)));
    connect(ServerTcpSocket,SIGNAL(disconnected()),ServerTcpSocket,SLOT(deleteLater()));
}
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

}
void Server::TcpReadMessage(){
    QDataStream in(ServerTcpSocket);
    in.setVersion(VERSION);
    MessageSize bufferSize=0;
    int type;
    if(ServerTcpSocket->bytesAvailable()<(int)sizeof(MessageSize)){
        emit InvalidMessage();
        return;
    }
    in>>bufferSize;
    if(bufferSize>ServerTcpSocket->bytesAvailable()){
        emit InvalidMessage();
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
    case MessageType::UserStatusUpdate:
        int change;
        in>>change;
        switch(change){
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
        emit InvalidMessage();
    }
}

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

void Server::Respond(MessageType::MessageType type)
{
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    out.setVersion(VERSION);
    out<<(MessageSize)0;
    out<<type;
    switch(type){
    case MessageType::InvalidMessage:
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

void Server::HandleInvalidMessage()
{
    Respond(MessageType::InvalidMessage);
}

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

void Server::Stop()
{
    close();
    db.close();
    ServerUdpSocket->abort();
    if(ServerTcpSocket!=NULL)
        ServerTcpSocket->abort();
}
