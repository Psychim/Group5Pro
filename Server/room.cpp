#include "room.h"

Room::Room(QObject *parent,int ID,QString name) :
    QObject(parent)
{
    setID(ID);
    setName(name);
}

void Room::setID(int ID)
{
    roomID=ID;
}

void Room::setName(QString name)
{
    roomName=name;
}

bool Room::NewPtcp(User *user)
{
    if(ChattingUsers.searchByID(user->getID()))
        return false;
    else{
        ChattingUsers.insertByID(user);
        return true;
    }
}

int Room::getID()
{
    return roomID;
}

QString Room::getName()
{
    return roomName;
}

bool Room::PtcpLeft(int ID)
{
    if(ChattingUsers.removeByID(ID))
        return true;
    else return false;

}
