#ifndef USERLIST_H
#define USERLIST_H

#include <QObject>
#include<QList>
#include "user.h"
class UserList : public QObject
{
    Q_OBJECT
public:
    explicit UserList(QObject *parent = 0);
    User * searchByID(int ID);
    User * searchByIP(QString);
    bool insertByID(User *);
    User * removeAt(int);
    User * removeByID(int);
    bool isEmpty();
    int size();
    User * operator[] (int);
private:
    QList<User *> users;
signals:

public slots:

};

#endif // USERLIST_H
