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


ChatWidget::ChatWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWidget)
{
    ui->setupUi(this);
    udpSocket=new QUdpSocket(this);
    server=new TcpServer(this);
    port=25252;
    udpSocket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams())); // readyRead（）在哪里
    connect(server,SIGNAL(sendFileName(QString)),this,SLOT(getFileName(QString))); // 怎么回事，sendFileName在哪里
    connect(ui->messageTextEdit,SIGNAL(currentCharFormatChanged(QTextCharFormat)),this,SLOT(currentFormatChanged(QTextCharFormat)));
    sendMessage(MessageType::NewParticipant);
}

ChatWidget::~ChatWidget()
{
    delete ui;
}

// 发送信息，在信息处理是，根据私聊和群聊来做不同修改
void ChatWidget::sendMessage(MessageType::MessageType type,QString serverAddress)
{
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    out.setVersion(VERSION);
    QString localHostName=QHostInfo::localHostName();
    QString address=getIP();
    out<<type<<getUserName()<<localHostName; // 在data的前面先加一个标志代表群聊，再加一个int类型的变量来标记聊天室
    //out<<某个标志<<room<<type<<getUserName()<<localHostName;
    switch(type)
    {
    case MessageType::Message:
    {if(ui->messageTextEdit->toPlainText()=="")
        {
            QMessageBox::warning(0,tr("警告"),tr("发送内容不能为空"),QMessageBox::Ok);
            return;
        }
        out<<address<<getMessage();
        ui->messageBrowser->verticalScrollBar()->setValue(ui->messageBrowser->verticalScrollBar()->maximum());
        break;}

    case MessageType::NewParticipant:
    {out<<address;
        break;}

    case MessageType::ParticipantLeft:
        break;

    case MessageType::FileName:
    {int row=ui->userTableWidget->currentRow();
        QString clientAddress=ui->userTableWidget->item(row,2)->text();
        out<<address<<clientAddress<<fileName;
        break;}

    case MessageType::Refuse:
      {  out<<serverAddress;
        break;}
    }
    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast,port);
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
        QString userName,localHostName,ipAddress,message;
        QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

        switch(messageType)
        {
        case MessageType::Message:
        {in>>userName>>localHostName>>ipAddress>>message;
            ui->messageBrowser->setTextColor(Qt::blue);
            ui->messageBrowser->setCurrentFont(QFont("Times New Roman",12));
            ui->messageBrowser->append("["+userName+"]"+time);
            ui->messageBrowser->append(message);
            break;}

        case MessageType::NewParticipant:
           { in>>userName>>localHostName>>ipAddress;
            newParticipant(userName,localHostName,ipAddress);
            break;}

        case MessageType::ParticipantLeft:
           { in>>userName>>localHostName;
            participantLeft(userName,localHostName,time);
            break;}

        case MessageType::FileName:
        {in>>userName>>localHostName>>ipAddress;
            QString clientAddress,fileName;
            in>>clientAddress>>fileName;
            hasPendingFile(userName,ipAddress,clientAddress,fileName);
            break;}

        case MessageType::Refuse:
        {in>>userName>>localHostName;
            QString serverAddress;
            in>>serverAddress;
            QString ipAddress=getIP();
            if(ipAddress==serverAddress)
                server->refused();
            break;}
        }

        //}
    }
}

// 新用户加入时的操作，私聊不需要，群聊部分修改
void ChatWidget::newParticipant(QString userName,QString localHostName,QString ipAddress)
{
    bool isEmpty=ui->userTableWidget->findItems(localHostName,Qt::MatchExactly).isEmpty();
    if(isEmpty)
    {
        QTableWidgetItem* user=new QTableWidgetItem(userName);
        QTableWidgetItem* host=new QTableWidgetItem(localHostName);
        QTableWidgetItem* ip=new QTableWidgetItem(ipAddress);

        ui->userTableWidget->insertRow(0);
        ui->userTableWidget->setItem(0,0,user);
        ui->userTableWidget->setItem(0,1,host);
        ui->userTableWidget->setItem(0,2,ip);

        ui->messageBrowser->setTextColor(Qt::gray);
        ui->messageBrowser->setCurrentFont(QFont("Times New Roman",10));
        ui->messageBrowser->append(tr("%1在线！").arg(userName));

        ui->userNumberLabel->setText(tr("在线人数:%1").arg(ui->userTableWidget->rowCount()));

        sendMessage(MessageType::NewParticipant);

    }
}

// 新用户离开时的操作，私聊不需要，群聊部分修改
void ChatWidget::participantLeft(QString userName,QString localHostName,QString time)
{
    int rowNum=ui->userTableWidget->findItems(localHostName,Qt::MatchExactly).first()->row();

    ui->userTableWidget->removeRow(rowNum);
    ui->messageBrowser->setTextColor(Qt::gray);
    ui->messageBrowser->setCurrentFont(QFont("Times New Roman",10));
    ui->messageBrowser->append(tr("%1于%2离开！").arg(userName).arg(time));
    ui->userNumberLabel->setText(tr("在线人数：%1").arg(ui->userTableWidget->rowCount()));
}


void ChatWidget::hasPendingFile(QString userName,QString serverAddress,QString clientAddress,QString fileName)
{
    QString ipAddress=getIP();
    if(ipAddress==clientAddress)
    {
        int btn=QMessageBox::information(this,tr("接收文件"),tr("来自%1(%2)的文件:%3，是否接受？").arg(userName).arg(serverAddress).arg(fileName),QMessageBox::Yes,QMessageBox::No);
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

QString ChatWidget::getIP()
{
    QList<QHostAddress>list=QNetworkInterface::allAddresses();
    foreach(QHostAddress address,list)
    {
        if(address.protocol()==QAbstractSocket::IPv4Protocol)
            return address.toString();
    }
    return 0;
}

QString ChatWidget::getUserName()
{
    QStringList envVariables;
    envVariables<<"USERNAME.*"<<"USER.*"<<"USERDOMAIN.*"<<"HOSTNAME.*"<<"DOMAINNAME.*";
    QStringList environment=QProcess::systemEnvironment();
    foreach(QString string,envVariables)
    {
        int index=environment.indexOf(QRegExp(string));
        if(index!=-1)
        {
            QStringList stringList=environment.at(index).split("="); // 完全搞不懂
            if(stringList.size()==2)
            {
                return stringList.at(1);
                break;
            }
        }
    }
    return "unknown";
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
