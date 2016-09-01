#ifndef ROOMLIST_H
#define ROOMLIST_H

#include <QObject>
#include"room.h"
#include<QList>
class RoomList : public QObject
{
    Q_OBJECT
public:
    explicit RoomList(QObject *parent = 0);
    QList<Room *>::iterator InsertByID(Room *);
    Room * searchByID(int);
    Room * NewRoom(QString,User *);
private:
    QList<Room *> rooms;
    int MinEmpty;
signals:

public slots:

};

#endif // ROOMLIST_H
