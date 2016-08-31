#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "user.h"
#include "clienttcpsocket.h"
#include "userlist.h"
#include<QtNetwork>
#include<QTableWidget>
class QtcpSocket;

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

protected slots:
    void newParticipant(User *);
    void participantLeft(int Id);
private:
    Ui::Widget *ui;
    ClientTcpSocket * tcpSocket;
    QUdpSocket * udpSocket;
    qint16 port;
    User * Self;
    UserList *onlineUsers;
private slots:
    void process(UserList *);
    void doubleClicked(QTableWidgetItem *);
    void initialize(User *);
    void on_commandLinkButton_clicked();
};

#endif // WIDGET_H
