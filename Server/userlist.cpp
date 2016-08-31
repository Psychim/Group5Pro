#include "userlist.h"
#include"user.h"
UserList::UserList(QObject *parent) :
    QObject(parent)
{
}

bool UserList::insertByID(User * user)
{
    if(user){
        user->setParent(this);
        if(users.size()==0){
            users.append(user);
        }
        else{
            QList<User *>::iterator ite=users.begin();
            QList<User *>::iterator end=users.end();
            while(ite!=end&&(*ite)->getID()<user->getID())
                ite++;
            if(ite!=end&&(*ite)->getID()==user->getID())
                return false;
            users.insert(ite,user);
        }
    }
    return true;
}

User * UserList::searchByID(int ID)
{
    if(users.size()==0) return NULL;
    int q=users.size()-1;
    int p=0;
    int r=(q+p)/2;
    while(p!=q&&users[r]->getID()!=ID){
        if(users[r]->getID()>ID){
            q=r;
        }
        else{
            p=r+1;
        }
        r=(p+q)/2;
    }
    if(users[r]->getID()==ID){
        return users[r];
    }
    else return NULL;
}

int UserList::size()
{
    return users.size();
}

User * UserList::operator[](int index)
{
    if(index>=users.size()||index<0)
        return NULL;
    else
        return users[index];
}
User * UserList::removeAt(int index)
{
    if(index>=users.size()||index<0)
        return NULL;
    else{
        User * tmp=users.at(index);
        users.removeAt(index);
        return tmp;
    }
}
bool UserList::isEmpty()
{
    return users.isEmpty();
}
User * UserList::removeByID(int ID)
{
    if(users.size()==0) return NULL;
    int q=users.size()-1;
    int p=0;
    int r=(q+p)/2;
    while(p!=q&&users[r]->getID()!=ID){
        if(users[r]->getID()>ID){
            q=r;
        }
        else{
            p=r+1;
        }
        r=(p+q)/2;
    }
    if(users[r]->getID()==ID){
        User *tmp=users[r];
        users.removeAt(r);
        return tmp;
    }
    else return NULL;
}
User * UserList::searchByIP(QString IP)
{
    for(int i=0;i<users.size();i++){
        if(IP==users[i]->getIpAddress())
            return users[i];
    }
    return NULL;
}
