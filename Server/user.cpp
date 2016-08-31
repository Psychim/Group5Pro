#include "user.h"
User::User(QObject *parent) :
    QObject(parent)
{
    Status=Offline;
    ID=0;
    Nickname="";
    IpAddress="127.0.0.1";
}
User::User(QObject *parent,int i,QString name,QString ad,UserStatus stat):
    QObject(parent)
{
    ID=i;
    IpAddress=ad;
    Nickname=name;
    Status=stat;
}
User& User::setNickname(QString name){
    Nickname=name;
    return *this;
}

User& User::setID(int i){
    ID=i;
    return *this;
}

User& User::setIpAddress(QString ad){
    IpAddress=ad;
    return *this;
}

User& User::setStatus(UserStatus stat){
    Status=stat;
    return *this;
}
User& User::readNickname(QDataStream &in){
    in>>Nickname;
    return *this;
}
User& User::readID(QDataStream &in){
    QString buf;
    in>>buf;
    ID=buf.toInt();
    return *this;
}
User& User::readIpAddress(QDataStream &in){
    in>>IpAddress;
    return *this;
}
User& User::readStatus(QDataStream &in){
    QString buf;
    in>>buf;
    Status=(User::UserStatus)buf.toInt();
    return *this;
}

int User::getID()
{
    return ID;
}

User::UserStatus User::getStatus()
{
    return Status;
}

QString User::getNickname()
{
    return Nickname;
}

QString User::getIpAddress()
{
    if(Status==User::Online)
        return IpAddress;
    else return NULL;
}
