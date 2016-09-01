#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include "userlist.h"
class Room : public QObject
{
    Q_OBJECT
public:
    explicit Room(QObject *parent = 0,int ID=0,QString name="");
    int getID();
    QString getName();
    void setID(int);
    void setName(QString);
    bool NewPtcp(User *);
    bool PtcpLeft(int);
private:
    int roomID;
    QString roomName;
public:
    UserList ChattingUsers;

signals:

public slots:

};

#endif // ROOM_H
