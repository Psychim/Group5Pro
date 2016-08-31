#ifndef SERVER_H
#define SERVER_H
#include<QtNetwork>
#include<QSqlDatabase>
#include"global.h"
#include"user.h"
#include"userlist.h"
class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    bool connectToDb();
    void Query(QString);
    void Init();
    void Stop();
    QString getlocalIP();
private:
    QSqlDatabase db;
    QTcpSocket *ServerTcpSocket;
    UserList *OnlineUsers;
    QUdpSocket *ServerUdpSocket;
    int TCPPort;
    int UDPPort;
private:
    void HandleUserRegister(QDataStream &);
    void HandleUserLogin(QDataStream &);
    User *LoginQuery(QMap<QString,QString>);
    bool RegisterQuery(QMap<QString,QString>,QString *);
    void Respond(MessageType::MessageType);
signals:
    void InvalidMessage();
    void UserStatusUpdate(User *);
public slots:
    void acceptConnection();
    void TcpReadMessage();
    void UdpReadMessage();
    void HandleInvalidMessage();
    void StatusBroadcast(User *);
};

#endif // SERVER_H
