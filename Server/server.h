#ifndef SERVER_H
#define SERVER_H
#include<QtNetwork>
#include<QSqlDatabase>
#include"global.h"
#include"user.h"
#include"userlist.h"
#include "roomlist.h"
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
    RoomList *ActiveRooms;
    QUdpSocket *ServerUdpSocket;
    int TCPPort;
    int UDPPort;
private:
    void HandleUserRegister(QDataStream &);
    void HandleUserLogin(QDataStream &);
    void HandleNewPtcp(QDataStream &);
    void HandleCreateRoom(QDataStream &);
    void HandlePtcpLeft(QDataStream &);
    User *LoginQuery(QMap<QString,QString>);
    bool RegisterQuery(QMap<QString,QString>,QString *);
    void Respond(MessageType::MessageType,QString = "");
    void HandleNicknameUpdate(QDataStream &);
signals:
    void Error(QString);
    void UserStatusUpdate(User *);
public slots:
    void acceptConnection();
    void TcpReadMessage();
    void UdpReadMessage();
    void HandleError(QString);
    void StatusBroadcast(User *);
};

#endif // SERVER_H
