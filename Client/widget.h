#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "user.h"
#include "clienttcpsocket.h"
#include "userlist.h"
#include<QtNetwork>
#include<QTableWidget>

namespace Ui {
    class Widget;
}

//enum statusOfParticipants{User::Online,User::Offline};


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void joinRoom(int ,QString);
protected slots:
    void newParticipant(User *);
    void participantLeft(int Id);
private:
    Ui::Widget *ui;
    ClientTcpSocket * tcpSocket;
    QUdpSocket * udpSocket;
    qint16 port;
    User * Self;    //用户自己，在登录界面登录成功后分配内存空间并传递至主界面，之后一直存在，直到程序结束
public:
    static UserList *onlineUsers;
private slots:
    void process(UserList *);
    void doubleClicked(QTableWidgetItem *);
    void HandlenewRoom(int,QString,int,int);
    void initialize(User *);
    void on_commandLinkButton_clicked();
    void roomdoubleClicked(QTableWidgetItem*);
    void UpdateRoomInfo(int ,int);
    void DeleteRoom(int);
};

#endif // WIDGET_H
