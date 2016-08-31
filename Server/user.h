#ifndef USER_H
#define USER_H

#include <QObject>
class User : public QObject
{
    Q_OBJECT
public:
    enum UserStatus{
        Online=0x0141,
        Offline=0x0142
    };
    explicit User(QObject *parent = 0);
    explicit User(QObject *parent,int i,QString name,QString ad,UserStatus stat);
    User& setNickname(QString);
    User& setID(int);
    User& setIpAddress(QString);
    User& setStatus(UserStatus);
    User& readNickname(QDataStream &);
    User& readID(QDataStream &);
    User& readIpAddress(QDataStream &);
    User& readStatus(QDataStream &);
    int getID();
    UserStatus getStatus();
    QString getNickname();
    QString getIpAddress();
private:
    int ID;
    UserStatus Status;
    QString Nickname;
    QString IpAddress;
signals:

public slots:

};

#endif // USER_H
