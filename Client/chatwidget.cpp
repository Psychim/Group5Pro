#include "chatwidget.h"
#include "ui_chatwidget.h"
#include"tcpserver.h"
#include"tcpclient.h"
#include "clienttcpsocket.h"
#include "widget.h"
#include<QFileDialog>
#include<QtNetwork>
#include<QHostInfo>
#include<QMessageBox>
#include<QScrollBar>
#include<QDateTime>
#include<QNetworkInterface>
#include<QProcess>
#include<QWidget>
#include<QColorDialog>


ChatWidget::ChatWidget(QWidget *parent,User *user,int roomID,QString roomName) :
    QWidget(parent),
    ui(new Ui::ChatWidget)
{
    setWindowFlags(Qt::Window);
    ui->setupUi(this);
    udpSocket=new QUdpSocket(this);
    server=new TcpServer(this);
    Self=NULL;
    ChattingUsers = new UserList(this);
    port=25254;
    room=roomID;
    name=roomName;
    udpSocket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
    connect(server,SIGNAL(sendFileName(QString)),this,SLOT(getFileName(QString)));
    connect(ui->messageTextEdit,SIGNAL(currentCharFormatChanged(QTextCharFormat)),this,SLOT(currentFormatChanged(QTextCharFormat)));
    connect(this,SIGNAL(Selfsetted()),this,SLOT(NewPtcp()));
    if(user){
        setSelf(user);
        emit Selfsetted();
    }
}

ChatWidget::~ChatWidget()
{
    delete ui;
}

// ������Ϣ������Ϣ�����ǣ�����˽�ĺ�Ⱥ��������ͬ�޸�
//��ʽ��<<type<<room<<ID[<<nickName][<<MyIP][<<PartnerIP][<<Message]
void ChatWidget::sendMessage(MessageType::MessageType type,QString serverAddress)
{
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    out.setVersion(VERSION);
    QString address=Self->getIpAddress();
    if(Self==NULL)  {
        QMessageBox::critical(0,"��������ʧ��","ȱ���û���Ϣ",QMessageBox::Cancel);
        return;
    }
    out<<type<<room<<Self->getID(); // ��data��ǰ���ȼ�һ����־����Ⱥ�ģ��ټ�һ��int���͵ı��������������(Ŀǰֻ��һ��������)
    //out<<ĳ����־<<room<<type<<getUserName()<<localHostName;
    switch(type)
    {
    case MessageType::Message:
    {if(ui->messageTextEdit->toPlainText()=="")
        {
            QMessageBox::warning(0,tr("����"),tr("�������ݲ���Ϊ��"),QMessageBox::Ok);
            return;
        }
        out<<Self->getNickname()<<getMessage();
        ui->messageBrowser->verticalScrollBar()->setValue(ui->messageBrowser->verticalScrollBar()->maximum());
        break;}
    //�ⲿ�ֲ����Լ��㲥��������֪ͨ�����������ɷ������㲥
   /* case MessageType::NewParticipant:
        out<<Self->getNickname()<<Self->getIpAddress();
        break;

    case MessageType::ParticipantLeft:
        break;
    */
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

//������Ҫ�������Ϣʱ�Ĳ���������Ϣ����ʱ������˽�ĺ�Ⱥ��������ͬ�޸�
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
        //if(sign==ĳ����־&&roomnum==room��
        //{

        int messageType,roomIDrcved;
        in>>messageType>>roomIDrcved;
        if(roomIDrcved!=room)   return;     //���Ǳ��������Ϣ��return
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
           {int size;
            in>>size>>ID;
                User *user=Widget::onlineUsers->searchByID(ID);
                newParticipant(user,time);
            break;
        }

        case MessageType::ParticipantLeft:
           {int size;
            in>>size>>ID;
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

// ���û�����ʱ�Ĳ�����˽�Ĳ���Ҫ��Ⱥ�Ĳ����޸�
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
    //ui->userTableWidget->sortByColumn(0,Qt::AscendingOrder);
    ui->messageBrowser->setTextColor(Qt::gray);
    ui->messageBrowser->setCurrentFont(QFont("Times New Roman",10));
    ui->messageBrowser->append(tr("%1(ID:%2)��%3���룡").arg(user->getNickname()).arg(QString::number(user->getID())).arg(time));
    ui->userNumberLabel->setText(tr("����������%1").arg(ui->userTableWidget->rowCount()));
}

// ���û��뿪ʱ�Ĳ�����˽�Ĳ���Ҫ��Ⱥ�Ĳ����޸�
void ChatWidget::participantLeft(int ID,QString time)
{
    int rowNum=ui->userTableWidget->findItems(QString::number(ID),Qt::MatchExactly).first()->row();
    ui->userTableWidget->removeRow(rowNum);
    User * user=ChattingUsers->removeByID(ID);
    if(user==NULL)  return;
    ui->messageBrowser->setTextColor(Qt::gray);
    ui->messageBrowser->setCurrentFont(QFont("Times New Roman",10));
    ui->messageBrowser->append(tr("%1(ID:%2)��%3�뿪��").arg(user->getNickname()).arg(QString::number(ID)).arg(time));
    ui->userNumberLabel->setText(tr("����������%1").arg(ui->userTableWidget->rowCount()));
}


void ChatWidget::hasPendingFile(int ID,QString nickName,QString serverAddress,QString clientAddress,QString fileName)
{
    QString ipAddress=Self->getIpAddress();
    if(ipAddress==clientAddress)
    {
        int btn=QMessageBox::information(this,tr("�����ļ�"),tr("����%1(ID:%2)���ļ�:%3���Ƿ���ܣ�").arg(nickName).arg(ID).arg(fileName),QMessageBox::Yes,QMessageBox::No);
        if(btn==QMessageBox::Yes)
        {
            QString name=QFileDialog::getSaveFileName(0,tr("�����ļ�"),fileName);
            if(!name.isEmpty())
            {
                static TcpClient* client=new TcpClient(this);
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
        QMessageBox::warning(0,tr("ѡ���û�"),tr("���ȴ��û��б�ѡ��Ҫ���͵��û�"),QMessageBox::Ok);
        return;
    }
    server->show();
    server->initServer();
}


void ChatWidget::on_fontComboBox_currentFontChanged(QFont f)
{
 //   QTextCursor cursor=ui->messageTextEdit->textCursor();
 //   ui->messageTextEdit->selectAll();
    ui->messageTextEdit->setCurrentFont(f);
//    ui->messageTextEdit->setTextCursor(cursor);
    ui->messageTextEdit->setFocus();
}

void ChatWidget::on_sizeComboBox_currentIndexChanged(QString size)
{
  //  QTextCursor cursor=ui->messageTextEdit->textCursor();
  //  ui->messageTextEdit->selectAll();
    ui->messageTextEdit->setFontPointSize(size.toDouble());
 //   ui->messageTextEdit->setTextCursor(cursor);
    ui->messageTextEdit->setFocus();
}

void ChatWidget::on_boldToolBtn_clicked(bool checked)
{
  //  QTextCursor cursor=ui->messageTextEdit->textCursor();
 //   ui->messageTextEdit->selectAll();
    if(checked)
    {
        ui->messageTextEdit->setFontWeight(QFont::Bold);
    }
    else
        ui->messageTextEdit->setFontWeight(QFont::Normal);
//   ui->messageTextEdit->setTextCursor(cursor);
    ui->messageTextEdit->setFocus();
}

void ChatWidget::on_italicToolBtn_clicked(bool checked)
{
  //  QTextCursor cursor=ui->messageTextEdit->textCursor();
  //  ui->messageTextEdit->selectAll();
    ui->messageTextEdit->setFontItalic(checked);
 //  ui->messageTextEdit->setTextCursor(cursor);
    ui->messageTextEdit->setFocus();
}

void ChatWidget::on_underlineToolBtn_clicked(bool checked)
{
  // QTextCursor cursor=ui->messageTextEdit->textCursor();
 //  ui->messageTextEdit->selectAll();
   ui->messageTextEdit->setFontUnderline(checked);
 //  ui->messageTextEdit->setTextCursor(cursor);
   ui->messageTextEdit->setFocus();
}

void ChatWidget::on_colorToolBtn_clicked()
{
    color=QColorDialog::getColor(color,this);
    if(color.isValid())
    {
    //    QTextCursor cursor=ui->messageTextEdit->textCursor();
    //    ui->messageTextEdit->selectAll();
        ui->messageTextEdit->setTextColor(color);
   //     ui->messageTextEdit->setTextCursor(cursor);
        ui->messageTextEdit->setFocus();
    }
}

void ChatWidget::currentFormatChanged(const QTextCharFormat &format)
{
    QTextCursor cursor=ui->messageTextEdit->textCursor();
    ui->messageTextEdit->selectAll();
    ui->messageTextEdit->setCurrentCharFormat(format);
    ui->messageTextEdit->setTextCursor(cursor);
}

void ChatWidget::on_saveToolBtn_clicked()
{
    if(ui->messageBrowser->document()->isEmpty())
    {
        QMessageBox::warning(0,tr("����"),tr("�����¼Ϊ�գ��޷�����"),QMessageBox::Ok);
    }
    else
    {
        QString fileName=QFileDialog::getSaveFileName(this,tr("���������¼"),tr("�����¼"),tr("�ı�(*.txt)::All File(*.*)"));
        if(!fileName.isEmpty())
            saveFile(fileName);
    }
}

bool ChatWidget::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,tr("�����ļ�"),tr("�޷������ļ� %1:\n%2").arg(fileName).arg(file.errorString()));
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
    QTcpSocket *tcpSocket=new QTcpSocket(this);
    tcpSocket->connectToHost(ClientTcpSocket::ServerHost,ClientTcpSocket::TCPPort);
    if(!tcpSocket->waitForConnected()){
        QMessageBox::warning(this,tr("���ӳ�ʱ"),tr("���ӷ�������ʱ"));
        return;
    }
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    out.setVersion(VERSION);
    out<<(MessageSize)0;
    out<<MessageType::ParticipantLeft;
    out<<room<<Self->getID();
    out.device()->seek(0);
    out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
    tcpSocket->write(buffer);
    tcpSocket->waitForBytesWritten();
    tcpSocket->abort();
    QWidget::closeEvent(e);
}

void ChatWidget::setRoomNum(int num)
{
    room=num;
}

void ChatWidget::setSelf(User *user)
{
    Self=user;

}

void ChatWidget::NewPtcp()
{
    static QTcpSocket *tcpSocket=new QTcpSocket(this);
    tcpSocket->abort();
    tcpSocket->connectToHost(ClientTcpSocket::ServerHost,ClientTcpSocket::TCPPort);
    if(!tcpSocket->waitForConnected()){
        QMessageBox::warning(this,tr("���ӳ�ʱ"),tr("���ӷ�������ʱ"));
        return;
    }
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    out.setVersion(VERSION);
    out<<(MessageSize)0;
    out<<MessageType::NewParticipant;
    out<<room<<Self->getID();
    out.device()->seek(0);
    out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
    tcpSocket->write(buffer);
    if(!tcpSocket->waitForReadyRead()){
        QMessageBox::warning(0,"��������ʱ","��������ʱ");
        return;
    }
    QDataStream in(tcpSocket);
    in.setVersion(VERSION);
    MessageSize bufferSize;
    int type;
    int roomIDrcved;
    if(tcpSocket->bytesAvailable()<(int)sizeof(MessageSize)){
      //  emit InvalidMessage();
        return;
    }
    in>>bufferSize;
    if(bufferSize>tcpSocket->bytesAvailable()){
       // emit InvalidMessage();
        return;
    }
    in>>type;
    switch(type){
    case MessageType::NewParticipant:
    {
        in>>roomIDrcved;
            if(roomIDrcved==room){   //��֤�Ƿ����Լ���������
                while(!in.atEnd()){     //�����Ѿ��������ҵ��û�����
                    int ID;
                    in>>ID;
                    User *user=Widget::onlineUsers->searchByID(ID);
                    newParticipant(user,"֮ǰ");
                }
            }
            setWindowTitle(tr("������%1��%2 - %3(ID:%4)").arg(room).arg(name).arg(Self->getNickname()).arg(Self->getID()));
        show();
        break;
    }
    case MessageType::Error:
        QString err;
        in>>err;
        QMessageBox::warning(0,"����",err);
        deleteLater();
    }
    tcpSocket->abort();
}

void ChatWidget::on_messageTextEdit_cursorPositionChanged()
{
    ui->messageTextEdit->setCurrentFont(ui->fontComboBox->currentFont());
    ui->messageTextEdit->setFontPointSize(ui->sizeComboBox->currentText().toDouble());
    ui->messageTextEdit->setFontUnderline(ui->underlineToolBtn->isChecked());
    ui->messageTextEdit->setFontItalic(ui->italicToolBtn->isChecked());
    if(ui->boldToolBtn->isChecked())
        ui->messageTextEdit->setFontWeight(QFont::Bold);
    else
        ui->messageTextEdit->setFontWeight(QFont::Normal);
    ui->messageTextEdit->setTextColor(color);
}
