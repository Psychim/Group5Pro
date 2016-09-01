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
    bool InsertByID(Room *);
    Room * searchByID(int);
    Room * NewRoom(QString);
    void DeleteRoomByID(int);
    Room * operator[](int);
    int size();
private:
    QList<Room *> rooms;
    int MinEmpty;
signals:

public slots:

};

#endif // ROOMLIST_H
