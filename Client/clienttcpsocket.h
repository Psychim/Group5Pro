#ifndef CLIENTTCPSOCKET_H
#define CLIENTTCPSOCKET_H

#include <QtNetwork>
#include "user.h"
#include "userlist.h"
class ClientTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit ClientTcpSocket(QObject *parent = 0);
    bool connectToServer();
    void WriteAndWait(QByteArray &,int =30000);
    void findServer();
    QString getlocalIP();
    void ReceiveUserList(QDataStream &);
    void ReceiveUpdate(QDataStream &);
    void ReceiveNewRoom(QDataStream &);
signals:
    void LoginSuccess(User *);
    void LoginFailed(QString);
    void RegisterSuccess();
    void RegisterFailed(QString);
    void NoRespond();
    void connectFailed();
    void InvalidMessage();
    void SendFailed();
    void IniSuccess();
    void ULReceived(UserList *);
    void newPtcp(User *);
    void PtcpLeft(int);
    void newRoom(int,QString,int,int);
public slots:
    void ReadMessage();
    void UDPReadMessage();
    void HandleNoRespond();
    void HandleConnectFailed();
    void HandleInvalidMessage();
    void HandleSendFailed();
private:
    QDataStream in;
    QUdpSocket *udpsocket;

public:
    static int TCPPort;
    static int UDPPort;
    static QString ServerHost;
};

#endif // CLIENTTCPSOCKET_H
