#include "widget.h"
#include "ui_widget.h"
#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>
#include <QInputDialog>
#include "global.h"
#include"widget_p2p.h"
#include "chatwidget.h"
UserList* Widget::onlineUsers=NULL;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    ui->nickname->setBackgroundRole(this->backgroundRole());
    connect(ui->userTableWidget,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(doubleClicked(QTableWidgetItem*)));
    connect(ui->roomtableWidget,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(roomdoubleClicked(QTableWidgetItem*)));
    Self=NULL;
}
Widget::~Widget(){

}

void Widget::process(UserList *users)
{
    while(!users->isEmpty()){
        newParticipant((*users)[0]);
        users->removeAt(0);
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons()&Qt::LeftButton)
    {

      //  if(event->y()<=ui->frame->height())
      // {
            QPoint temp;
            temp=event->globalPos()-offset;
            move(temp);
      //  }
    }
}

void Widget::newParticipant(User *user)
{
    onlineUsers->insertByID(user);
    user->setParent(this);
    QTableWidgetItem *id=new QTableWidgetItem(QString::number(user->getID()));
    QTableWidgetItem *nickname=new QTableWidgetItem(user->getNickname());
    id->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    nickname->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    ui->userTableWidget->insertRow(0);
    ui->userTableWidget->setItem(0,0,id);
    ui->userTableWidget->setItem(0,1,nickname);
    //ui->userTableWidget->sortByColumn(0,Qt::AscendingOrder);
    ui->userNumLabel->setText(tr("在线人数：%1").arg(ui->userTableWidget->rowCount()));
    Widget_p2p * tmp=new Widget_p2p(this);
    connect(tmp,SIGNAL(newMessage(int,int)),this,SLOT(MsgPromt(int,int)));
    tmp->setPartner(user);
    tmp->setSelf(Self);
    ChattingList.append(tmp);
}

void Widget::participantLeft(int Id){
    int rowNum=ui->userTableWidget->findItems(QString::number(Id),Qt::MatchExactly).first()->row();
    ui->userTableWidget->removeRow(rowNum);
    onlineUsers->removeByID(Id);
    ui->userNumLabel->setText(tr("在线人数：%1").arg(ui->userTableWidget->rowCount()));
    for(int i = 0;i<ChattingList.size();i++){
        if(ChattingList[i]->getPartnerID()==Id){
            Widget_p2p * tmp=ChattingList[i];
            ChattingList.removeAt(i);
            connect(tmp,SIGNAL(closed(Widget_p2p*)),this,SLOT(Killp2pWidget(Widget_p2p*)));
        }
    }
}

void Widget::doubleClicked(QTableWidgetItem * item)
{
    int row=item->row();
    QTableWidgetItem * itm_ID=ui->userTableWidget->item(row,0);
    QTableWidgetItem * Promt_itm=ui->userTableWidget->item(row,2);
    if(Promt_itm)
        Promt_itm->setText("");
    int ID=itm_ID->text().toInt();
    for(int i=0;i<ChattingList.size();i++){
        if(ChattingList[i]->getPartnerID()==ID){
            ChattingList[i]->show();

            break;
        }
    }
}

void Widget::initialize(User * user)
{
    tcpSocket=new ClientTcpSocket(this);
    onlineUsers=new UserList(this);
    connect(tcpSocket,SIGNAL(ULReceived(UserList*)),this,SLOT(process(UserList*)));
    connect(tcpSocket,SIGNAL(newPtcp(User*)),this,SLOT(newParticipant(User*)));
    connect(tcpSocket,SIGNAL(PtcpLeft(int)),this,SLOT(participantLeft(int)));
    connect(tcpSocket,SIGNAL(newRoom(int,QString,int,int)),this,SLOT(HandlenewRoom(int,QString,int,int)));
    connect(tcpSocket,SIGNAL(UpdateUserNumber(int,int)),this,SLOT(UpdateRoomInfo(int,int)));
    connect(tcpSocket,SIGNAL(DeleteRoom(int)),this,SLOT(DeleteRoom(int)));
    connect(tcpSocket,SIGNAL(NicknameUpdate(int,QString)),this,SLOT(UpdateOnesNickname(int,QString)));
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
    tcpSocket->abort();
    setWindowTitle(tr("%1(ID:%2)").arg(Self->getNickname()).arg(Self->getID()));
    show();
}

void Widget::on_commandLinkButton_clicked()
{
    QString roomName;
    if((roomName=QInputDialog::getText(this,tr("请输入房间名称"),tr("房间名称")))=="")
        return;
    if(!(tcpSocket->state()==QAbstractSocket::ConnectedState))
        tcpSocket->connectToServer();
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    out<<(MessageSize)0;
    out<<MessageType::CreateRoom;
    out<<Self->getID()<<roomName;
    out.device()->seek(0);
    out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
    tcpSocket->write(buffer);
    tcpSocket->waitForBytesWritten();
    tcpSocket->abort();
}

void Widget::HandlenewRoom(int roomID, QString roomName, int size, int userID)
{
    QTableWidgetItem *roomID_itm=new QTableWidgetItem(QString::number(roomID));
    QTableWidgetItem *roomName_itm=new QTableWidgetItem(roomName);
    QTableWidgetItem *size_itm=new QTableWidgetItem(QString::number(size));
    roomID_itm->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    roomName_itm->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    size_itm->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    ui->roomtableWidget->insertRow(0);
    ui->roomtableWidget->setItem(0,0,roomID_itm);
    ui->roomtableWidget->setItem(0,1,roomName_itm);
    ui->roomtableWidget->setItem(0,2,size_itm);
    ui->roomtableWidget->sortByColumn(0,Qt::AscendingOrder);
    if(userID==Self->getID())
        joinRoom(roomID,roomName);
}

void Widget::roomdoubleClicked(QTableWidgetItem * item)
{
    int row=item->row();
    QTableWidgetItem * itm_ID=ui->roomtableWidget->item(row,0);
    QTableWidgetItem * itm_name=ui->roomtableWidget->item(row,1);
    int ID=itm_ID->text().toInt();
    QString name=itm_name->text();
    joinRoom(ID,name);
}

void Widget::joinRoom(int ID,QString name)
{
    ChatWidget *w=new ChatWidget(this,Self,ID,name);
}

void Widget::UpdateRoomInfo(int room, int size)
{
    int row=ui->roomtableWidget->findItems(QString::number(room),Qt::MatchExactly).first()->row();
    QTableWidgetItem *size_itm=ui->roomtableWidget->item(row,2);
    size_itm->setText(QString::number(size));
}

void Widget::DeleteRoom(int room)
{
    QTableWidgetItem *itm=ui->roomtableWidget->findItems(QString::number(room),Qt::MatchExactly).first();
    if(itm==NULL)   return;
    int row=itm->row();
    ui->roomtableWidget->removeRow(row);
}
//消息提醒
void Widget::MsgPromt(int partnerID, int Msgnum)
{
    QTableWidgetItem *itm=ui->userTableWidget->findItems(QString::number(partnerID),Qt::MatchExactly).first();
    int row=itm->row();
    QTableWidgetItem *Promt_itm=new QTableWidgetItem(tr("有新消息(%1)").arg(Msgnum));
    ui->userTableWidget->setItem(row,2,Promt_itm);
}

void Widget::Killp2pWidget(Widget_p2p * widget)
{
    delete widget;
}

void Widget::closeEvent(QCloseEvent *e)
{
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
    tcpSocket->abort();
    QWidget::closeEvent(e);
}

void Widget::on_pushButton_clicked()
{
    showMinimized();
}

void Widget::on_pushButton_2_clicked()
{
    close();
}
void Widget::on_nickname_editingFinished()
{
    ui->nickname->setEnabled(false);
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    out.setVersion(VERSION);
    out<<(MessageSize)0;
    out<<MessageType::NicknameUpdate;
    out<<Self->getID();
    out<<ui->nickname->text();
    out.device()->seek(0);
    out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
    tcpSocket->WriteAndWait(buffer);
}

void Widget::mouseDoubleClickEvent(QMouseEvent *e)
{
    int x=e->x();
    int y=e->y();
    QRect nickrect=ui->nickname->geometry();
    if(x>=nickrect.x()&&x<=(nickrect.x()+nickrect.width())&&y>=nickrect.y()&&(y<=nickrect.y()+nickrect.height())){
        ui->nickname->setEnabled(true);
    }
    QWidget::mouseDoubleClickEvent(e);
}

void Widget::UpdateOnesNickname(int ID, QString NewNick)
{
    QTableWidgetItem *itm=ui->userTableWidget->findItems(QString::number(ID),Qt::MatchExactly).first();
    int row=itm->row();
    QTableWidgetItem *nick_itm=ui->userTableWidget->item(row,1);
    nick_itm->setText(NewNick);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
        if(event->y()<=ui->frame->height())
            offset=event->globalPos()-pos();
}
