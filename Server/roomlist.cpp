#include "roomlist.h"

RoomList::RoomList(QObject *parent) :
    QObject(parent)
{
    MinEmpty=0;
}

QList<Room *>::iterator RoomList::InsertByID(Room *room)
{
    if(room){
        room->setParent(this);
        if(rooms.size()==0){
            rooms.append(room);
        }
        else{
            QList<Room *>::iterator ite=rooms.begin();
            QList<Room *>::iterator end=rooms.end();
            while(ite!=end&&(*ite)->getID()<room->getID())
                ite++;
            if(ite!=end&&(*ite)->getID()==room->getID()){
                rooms.insert(ite,room);
                return ite-1;
            }
        }
    }
    return rooms.end();
}
Room* RoomList::NewRoom(QString name)
{
    Room *room=new Room(this,MinEmpty,name);
    QList<Room *>::Iterator ite=InsertByID(room);
    while(ite!=rooms.end()&&MinEmpty==(*ite)->getID()){
        MinEmpty++;
    }
    return room;
}

Room * RoomList::searchByID(int ID)
{
    if(rooms.size()==0) return NULL;
    int q=rooms.size()-1;
    int p=0;
    int r=(q+p)/2;
    while(p!=q&&rooms[r]->getID()!=ID){
        if(rooms[r]->getID()>ID){
            q=r;
        }
        else{
            p=r+1;
        }
        r=(p+q)/2;
    }
    if(rooms[r]->getID()==ID){
        return rooms[r];
    }
    else return NULL;
}

void RoomList::DeleteRoomByID(int ID)
{
    if(rooms.size()==0) return;
    int q=rooms.size()-1;
    int p=0;
    int r=(q+p)/2;
    while(p!=q&&rooms[r]->getID()!=ID){
        if(rooms[r]->getID()>ID){
            q=r;
        }
        else{
            p=r+1;
        }
        r=(p+q)/2;
    }
    if(rooms[r]->getID()==ID){
        Room *tmp=rooms[r];
        rooms.removeAt(r);
        if(MinEmpty>tmp->getID())
            MinEmpty=tmp->getID();
        delete tmp;
    }
}
