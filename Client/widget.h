#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "user.h"
#include "clienttcpsocket.h"
#include "userlist.h"
#include "widget_p2p.h"
#include<QtNetwork>
#include<QTableWidget>
#include<QMouseEvent>
#include <QPoint>

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
    User * Self;    //�û��Լ����ڵ�¼�����¼�ɹ�������ڴ�ռ䲢�����������棬֮��һֱ���ڣ�ֱ���������
    QList<Widget_p2p *> ChattingList;
    QPoint offset;
protected:
    void closeEvent(QCloseEvent *);
    void mouseMoveEvent(QMouseEvent *);
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
    void MsgPromt(int,int);
    void KIllp2pWidget(Widget_p2p*);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // WIDGET_H
