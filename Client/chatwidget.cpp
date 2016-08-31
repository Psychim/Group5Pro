#include "chatwidget.h"
#include "ui_chatwidget.h"
#include"tcpserver.h"
#include"tcpclient.h"
#include<QFileDialog>
#include<QUdpSocket>
#include<QHostInfo>
#include<QMessageBox>
#include<QScrollBar>
#include<QDateTime>
#include<QNetworkInterface>
#include<QProcess>
#include<QWidget>
#include<QColorDialog>


ChatWidget::ChatWidget(QWidget *parent,User *user) :
    QWidget(parent),
    ui(new Ui::ChatWidget)
{
    setWindowFlags(Qt::Window);
    ui->setupUi(this);
    udpSocket=new QUdpSocket(this);
    server=new TcpServer(this);
    Self=new User(this);

    ChattingUsers = new UserList(this);
    port=25254;
    udpSocket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
    connect(server,SIGNAL(sendFileName(QString)),this,SLOT(getFileName(QString)));
    connect(ui->messageTextEdit,SIGNAL(currentCharFormatChanged(QTextCharFormat)),this,SLOT(currentFormatChanged(QTextCharFormat)));
    connect(this,SIGNAL(Selfsetted()),this,SLOT(BroadCastNewPtcp()));
    if(user){
        setSelf(user);
        emit Selfsetted();
    }
}

ChatWidget::~ChatWidget()
{
    delete ui;
}

// 发送信息，在信息处理是，根据私聊和群聊来做不同修改
//格式：<<type<<ID[<<nickName][<<MyIP][<<PartnerIP][<<Message]
void ChatWidget::sendMessage(MessageType::MessageType type,QString serverAddress)
{
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    out.setVersion(VERSION);
    QString address=Self->getIpAddress();
    if(Self==NULL)  {
        QMessageBox::critical(0,"发送数据失败","缺少用户信息",QMessageBox::Cancel);
        return;
    }
    out<<type<<Self->getID(); // 在data的前面先加一个标志代表群聊，再加一个int类型的变量来标记聊天室(目前只有一个聊天室)
    //out<<某个标志<<room<<type<<getUserName()<<localHostName;
    switch(type)
    {
    case MessageType::Message:
    {if(ui->messageTextEdit->toPlainText()=="")
        {
            QMessageBox::warning(0,tr("警告"),tr("发送内容不能为空"),QMessageBox::Ok);
            return;
        }
        out<<Self->getNickname()<<getMessage();
        ui->messageBrowser->verticalScrollBar()->setValue(ui->messageBrowser->verticalScrollBar()->maximum());
        break;}

    case MessageType::NewParticipant:
        out<<Self->getNickname()<<Self->getIpAddress();
        break;

    case MessageType::ParticipantLeft:
        break;

    case MessageType::FileName:
    {
        int row=ui->userTableWidget->currentRow();
        int ID=ui->userTableWidget->item(row,0)->text().toInt();
        User *user=ChattingUsers->searchByID(ID);
        QString clientAddress=user->getIpAddress();
        out<<Self->getNickname()<<address<<clientAddress<<fileName;
        break;
    }

    case MessageType::Refuse:
      {  out<<serverAddress;
        break;}
    default:
        break;
    }
    udpSocket->writeDatagram(data,QHostAddress::Broadcast,port);
}

//存在需要解决的信息时的操作，在信息处理时，根据私聊和群聊来做不同修改
void ChatWidget::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
        QDataStream in(&datagram,QIODevice::ReadOnly);
        in.setVersion(VERSION);
        //int sign;
        //in>>sign;
        // int roomnum;
        //in>>roomnum;
        //if(sign==某个标志&&roomnum==room）
        //{

        int messageType;
        in>>messageType;
        int ID;
        QString nickName,ipAddress,message;
        QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

        switch(messageType)
        {
        case MessageType::Message:
        {in>>ID>>nickName>>message;
            ui->messageBrowser->setTextColor(Qt::blue);
            ui->messageBrowser->setCurrentFont(QFont("Times New Roman",12));
            ui->messageBrowser->append("["+nickName+"]"+time);
            ui->messageBrowser->append(message);
            break;}

        case MessageType::NewParticipant:
           { in>>ID>>nickName>>ipAddress;
            User *user=new User(0,ID,nickName,ipAddress,User::Online);
            newParticipant(user,time);
            break;
        }

        case MessageType::ParticipantLeft:
           { in>>ID;
            participantLeft(ID,time);
            break;}

        case MessageType::FileName:
        {QString clientAddress,fileName;
            in>>ID>>nickName>>ipAddress;
            in>>clientAddress>>fileName;
            hasPendingFile(ID,nickName,ipAddress,clientAddress,fileName);
            break;
        }

        case MessageType::Refuse:
        {in>>ID;
            QString serverAddress;
            in>>serverAddress;
            QString ipAddress=Self->getIpAddress();
            if(ipAddress==serverAddress)
                server->refused();
            break;}
        }

        //}
    }
}

// 新用户加入时的操作，私聊不需要，群聊部分修改
void ChatWidget::newParticipant(User *user,QString time)
{
    ChattingUsers->insertByID(user);
    QTableWidgetItem *id=new QTableWidgetItem(QString::number(user->getID()));
    QTableWidgetItem *nickname=new QTableWidgetItem(user->getNickname());
    id->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    nickname->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    ui->userTableWidget->insertRow(0);
    ui->userTableWidget->setItem(0,0,id);
    ui->userTableWidget->setItem(0,1,nickname);
    ui->userTableWidget->sortByColumn(0,Qt::AscendingOrder);
    ui->messageBrowser->setTextColor(Qt::gray);
    ui->messageBrowser->setCurrentFont(QFont("Times New Roman",10));
    ui->messageBrowser->append(tr("%1(ID:%2)于%3加入！").arg(user->getNickname()).arg(QString::number(user->getID())).arg(time));
    ui->userNumberLabel->setText(tr("在线人数：%1").arg(ui->userTableWidget->rowCount()));
}

// 新用户离开时的操作，私聊不需要，群聊部分修改
void ChatWidget::participantLeft(int ID,QString time)
{
    int rowNum=ui->userTableWidget->findItems(QString::number(ID),Qt::MatchExactly).first()->row();
    ui->userTableWidget->removeRow(rowNum);
    User * user=ChattingUsers->removeByID(ID);
    ui->messageBrowser->setTextColor(Qt::gray);
    ui->messageBrowser->setCurrentFont(QFont("Times New Roman",10));
    ui->messageBrowser->append(tr("%1(ID:%2)于%3离开！").arg(user->getNickname()).arg(QString::number(ID)).arg(time));
    ui->userNumberLabel->setText(tr("在线人数：%1").arg(ui->userTableWidget->rowCount()));
}


void ChatWidget::hasPendingFile(int ID,QString nickName,QString serverAddress,QString clientAddress,QString fileName)
{
    QString ipAddress=Self->getIpAddress();
    if(ipAddress==clientAddress)
    {
        int btn=QMessageBox::information(this,tr("接收文件"),tr("来自%1(ID:%2)的文件:%3，是否接受？").arg(nickName).arg(ID).arg(fileName),QMessageBox::Yes,QMessageBox::No);
        if(btn==QMessageBox::Yes)
        {
            QString name=QFileDialog::getSaveFileName(0,tr("保存文件"),fileName);
            if(!name.isEmpty())
            {
                TcpClient* client=new TcpClient(this);
                client->setFileName(name);
                client->setHostAddress(QHostAddress(serverAddress));
                client->show();
            }
        }
        else
            sendMessage(MessageType::Refuse,serverAddress);
    }
}
QString ChatWidget::getMessage()
{
    QString msg=ui->messageTextEdit->toHtml();
    ui->messageTextEdit->clear();
    ui->messageTextEdit->setFocus();
    return msg;
}

void ChatWidget::on_sendButton_clicked()
{
    sendMessage(MessageType::Message);
}

void ChatWidget::getFileName(QString name)
{
    fileName=name;
    sendMessage(MessageType::FileName);
}

void ChatWidget::on_sendToolBtn_clicked()
{
    if(ui->userTableWidget->selectedItems().isEmpty())
    {
        QMessageBox::warning(0,tr("选择用户"),tr("请先从用户列表选择要传送的用户"),QMessageBox::Ok);
        return;
    }
    server->show();
    server->initServer();
}


void ChatWidget::on_fontComboBox_currentFontChanged(QFont f)
{
    ui->messageTextEdit->setCurrentFont(f);
    ui->messageTextEdit->setFocus();
}

void ChatWidget::on_sizeComboBox_currentIndexChanged(QString size)
{
    ui->messageTextEdit->setFontPointSize(size.toDouble());
    ui->messageTextEdit->setFocus();
}

void ChatWidget::on_boldToolBtn_clicked(bool checked)
{
    if(checked)
    {
        ui->messageTextEdit->setFontWeight(QFont::Bold);
    }
    else
        ui->messageTextEdit->setFontWeight(QFont::Normal);
    ui->messageTextEdit->setFocus();
}

void ChatWidget::on_italicToolBtn_clicked(bool checked)
{
    ui->messageTextEdit->setFontItalic(checked);
    ui->messageTextEdit->setFocus();
}

void ChatWidget::on_underlineToolBtn_clicked(bool checked)
{
   ui->messageTextEdit->setFontUnderline(checked);
   ui->messageTextEdit->setFocus();
}

void ChatWidget::on_colorToolBtn_clicked()
{
    color=QColorDialog::getColor(color,this);
    if(color.isValid())
    {
        ui->messageTextEdit->setTextColor(color);
        ui->messageTextEdit->setFocus();
    }
}

void ChatWidget::currentFormatChanged(const QTextCharFormat &format)
{
    ui->fontComboBox->setCurrentFont(format.font());
    if(format.fontPointSize()<9)
    {
        ui->sizeComboBox->setCurrentIndex(3);
    }
    else
    {
        ui->sizeComboBox->setCurrentIndex(ui->sizeComboBox->findText(QString::number(format.fontPointSize())));
    }
    ui->boldToolBtn->setChecked(format.font().bold());
    ui->italicToolBtn->setChecked(format.font().italic());
    ui->underlineToolBtn->setChecked(format.font().underline());
    color=format.foreground().color();
}

void ChatWidget::on_saveToolBtn_clicked()
{
    if(ui->messageBrowser->document()->isEmpty())
    {
        QMessageBox::warning(0,tr("警告"),tr("聊天记录为空，无法保存"),QMessageBox::Ok);
    }
    else
    {
        QString fileName=QFileDialog::getSaveFileName(this,tr("保存聊天记录"),tr("聊天记录"),tr("文本(*.txt)::All File(*.*)"));
        if(!fileName.isEmpty())
            saveFile(fileName);
    }
}

bool ChatWidget::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,tr("保存文件"),tr("无法保存文件 %1:\n%2").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out<<ui->messageBrowser->toPlainText();
    return true;
}

void ChatWidget::on_clearToolBtn_clicked()
{
    ui->messageBrowser->clear();
}

void ChatWidget::on_exitButton_clicked()
{
    close();
}

void ChatWidget::closeEvent(QCloseEvent *e)
{
    sendMessage(MessageType::ParticipantLeft);
    QWidget::closeEvent(e);
}

void ChatWidget::setRoomNum(int num)
{
    room=num;
}

void ChatWidget::setSelf(User *user)
{
    Self->setID(user->getID());
    Self->setNickname(user->getNickname());
    Self->setIpAddress(user->getIpAddress());
    Self->setStatus(user->getStatus());
    emit Selfsetted();
}

void ChatWidget::BroadCastNewPtcp()
{
    sendMessage(MessageType::NewParticipant);
}
