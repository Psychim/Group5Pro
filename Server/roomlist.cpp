#include "roomlist.h"

RoomList::RoomList(QObject *parent) :
    QObject(parent)
{
    MinEmpty=1;
}

bool RoomList::InsertByID(Room *room)
{
    if(room){
        //room->setParent(this);
        if(rooms.size()==0){
            rooms.append(room);
            MinEmpty++;
        }
        else{
            QList<Room *>::iterator ite=rooms.begin();
            QList<Room *>::iterator end=rooms.end();
            while(ite!=end&&(*ite)->getID()<room->getID())
                ite++;
            if(ite!=end&&(*ite)->getID()==room->getID())
                return false;
            ite=rooms.insert(ite,room);
            while(ite!=end&&(*ite)->getID()==MinEmpty){ //¸üÐÂMinEmpty
                MinEmpty++;
                ite++;
            }
        }
    }
    return true;
}
Room* RoomList::NewRoom(QString name)
{
    Room *room=new Room(this,MinEmpty,name);
    if(InsertByID(room))
        return room;
    else
        return NULL;
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

Room * RoomList::operator[](int index)
{
    if(index>rooms.size()||index<0)
        return NULL;
    else return rooms[index];
}

int RoomList::size()
{
    return rooms.size();
}
