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
    void joinRoom(int );
protected slots:
    void newParticipant(User *);
    void participantLeft(int Id);
private:
    Ui::Widget *ui;
    ClientTcpSocket * tcpSocket;
    QUdpSocket * udpSocket;
    qint16 port;
    User * Self;    //�û��Լ����ڵ�¼�����¼�ɹ�������ڴ�ռ䲢�����������棬֮��һֱ���ڣ�ֱ���������
    UserList *onlineUsers;
private slots:
    void process(UserList *);
    void doubleClicked(QTableWidgetItem *);
    void HandlenewRoom(int,QString,int,int);
    void initialize(User *);
    void on_commandLinkButton_clicked();
    void roomdoubleClicked(QTableWidgetItem*);
};

#endif // WIDGET_H
