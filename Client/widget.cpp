#include "widget.h"
#include "ui_widget.h"
#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>
#include <global.h>
#include"widget_p2p.h"
#include "chatwidget.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->userTableWidget,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(doubleClicked(QTableWidgetItem*)));
    Self=NULL;
}
Widget::~Widget(){
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    out<<(MessageSize)0;
    out<<MessageType::UserStatusUpdate;
    out<<User::Offline;
    out<<Self->getID();
    out.device()->seek(0);
    out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
    tcpSocket->abort();
    tcpSocket->connectToServer();
    tcpSocket->waitForConnected();
    tcpSocket->write(buffer);
    tcpSocket->waitForBytesWritten();
}

void Widget::process(UserList *users)
{
    while(!users->isEmpty()){
        newParticipant((*users)[0]);
        users->removeAt(0);
    }
}

void Widget::newParticipant(User *user)
{
    onlineUsers->insertByID(user);
    QTableWidgetItem *id=new QTableWidgetItem(QString::number(user->getID()));
    QTableWidgetItem *nickname=new QTableWidgetItem(user->getNickname());
    id->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    nickname->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    ui->userTableWidget->insertRow(0);
    ui->userTableWidget->setItem(0,0,id);
    ui->userTableWidget->setItem(0,1,nickname);
    ui->userTableWidget->sortByColumn(0,Qt::AscendingOrder);
    ui->userNumLabel->setText(tr("在线人数：%1").arg(ui->userTableWidget->rowCount()));
}

void Widget::participantLeft(int Id){
    int rowNum=ui->userTableWidget->findItems(QString::number(Id),Qt::MatchExactly).first()->row();
    ui->userTableWidget->removeRow(rowNum);
    onlineUsers->removeByID(Id);
    ui->userNumLabel->setText(tr("在线人数：%1").arg(ui->userTableWidget->rowCount()));

}

void Widget::doubleClicked(QTableWidgetItem * item)
{
    int row=item->row();
    QTableWidgetItem * itm_ID=ui->userTableWidget->item(row,0);
    int ID=itm_ID->text().toInt();
    User *user=onlineUsers->searchByID(ID);
    Widget_p2p *w=new Widget_p2p(this);
    w->setPartner(user);
    w->setSelf(Self);
    //w->readmessage(QByteArray buffer);
    w->show();
}

void Widget::initialize(User * user)
{
    tcpSocket=new ClientTcpSocket(this);
    onlineUsers=new UserList(this);
    connect(tcpSocket,SIGNAL(ULReceived(UserList*)),this,SLOT(process(UserList*)));
    connect(tcpSocket,SIGNAL(newPtcp(User*)),this,SLOT(newParticipant(User*)));
    connect(tcpSocket,SIGNAL(PtcpLeft(int)),this,SLOT(participantLeft(int)));
    Self=user;
    Self->setParent(this);
    ui->nickname->setText(Self->getNickname());
    ui->idlabel->setText(QString::number(Self->getID()));
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    out<<(MessageSize)0;
    out<<MessageType::UserList;
    out.device()->seek(0);
    out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
    tcpSocket->WriteAndWait(buffer);
    show();
}

void Widget::on_commandLinkButton_clicked()
{
    ChatWidget * Chatroom=new ChatWidget(this);
    Chatroom->setSelf(Self);
    Chatroom->show();
}
