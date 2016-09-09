#include "widget_p2p.h"
#include "ui_widget_p2p.h"
#include "global.h"
#include "tcpserver.h"
#include "tcpclient.h"
#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>
#include <QFileDialog>
#include <QColorDialog>
#include<QTimer>
Widget_p2p::Widget_p2p(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_p2p)
{
    setWindowFlags(Qt::Window);
    ui->setupUi(this);
    Partner=new User(this);
    Self=NULL;
    isOpen=false;
    MsgNotRcved=0;
    udpSocket = new QUdpSocket(this);
    port = 25253;
    if(!udpSocket->bind(port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint)){
        QMessageBox::warning(0, tr("����"), tr("�޷��󶨶˿�"), QMessageBox::Ok);
    }
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
   //sendMessage(NewParticipant);

   server = new TcpServer(this);
   connect(server, SIGNAL(sendFileName(QString)), this, SLOT(getFileName(QString)));
   connect(ui->messageTextEdit, SIGNAL(currentCharFormatChanged(QTextCharFormat)),
               this, SLOT(currentFormatChanged(const QTextCharFormat)));
   //��Ƶ�Ի�����
   ui->PartnerVideo->hide();
   ui->MyVideo->hide();
   VideoOpened=false;
   cm=NULL;
   imgskt=NULL;
}

Widget_p2p::~Widget_p2p()
{
    delete ui;
    delete cm;
}


void Widget_p2p::sendMessage(MessageType::MessageType type, QString serverAddress)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(VERSION);
    QString address = Self->getIpAddress();
    QString userName=Self->getNickname();
    QString time = QDateTime::currentDateTime()
            .toString("yyyy-MM-dd hh:mm:ss");
    out << type << userName<<Self->getID()<<Partner->getID();

    switch(type)
    {
    case MessageType::Message :
    {if (ui->messageTextEdit->toPlainText() == "") {
            QMessageBox::warning(0,tr("����"),tr("�������ݲ���Ϊ��"),QMessageBox::Ok);
            return;
        }
        QString msg=getMessage();
        ui->messageBrowser->setTextColor(Qt::green);
        ui->messageBrowser->setCurrentFont(QFont("Times New Roman",12));
        ui->messageBrowser->append("[ " +userName+" ] "+ time);
        ui->messageBrowser->append(msg);
        out<< msg;
        ui->messageBrowser->verticalScrollBar()
                ->setValue(ui->messageBrowser->verticalScrollBar()->maximum());
        break;}

    case MessageType::ParticipantLeft :
        break;

    case MessageType::FileName : { // �˴���Ҫ�����洫����IP��ַ ������
        //int row = ui->userTableWidget->currentRow();
        //QString clientAddress = ui->userTableWidget->item(row, 2)->text();
        out << address << Partner->getIpAddress() << fileName;
        break;
    }

    case MessageType::Refuse :
        out << serverAddress;
        break;
    default:
        break;
    }
    udpSocket->writeDatagram(data,QHostAddress::Broadcast, port); // �����޷�����˿ڳ�ͻ���⣬�ʹ㲥
    udpSocket->waitForBytesWritten();
}
void Widget_p2p::sendMessage(MessageType::MessageType type,int step){
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(VERSION);
    out<<type<<Self->getNickname()<<Self->getID()<<Partner->getID();
    switch(type){
    case MessageType::Video:
        out<<step;
        break;
    default:
        break;
    }
    udpSocket->writeDatagram(data,QHostAddress::Broadcast, port); // �����޷�����˿ڳ�ͻ���⣬�ʹ㲥
    udpSocket->waitForBytesWritten();
}

void Widget_p2p::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        QDataStream in(&datagram, QIODevice::ReadOnly);
        in.setVersion(VERSION);
        int messageType;
        int PartnerID,SelfID;
        QString userName,ipAddress,message;
        QString time = QDateTime::currentDateTime()
                .toString("yyyy-MM-dd hh:mm:ss");
        in >> messageType;

        in >> userName >>PartnerID>>SelfID;
        if(PartnerID!=Partner->getID()||SelfID!=Self->getID())
            return;
        switch(messageType)
        {
        case MessageType::Message:
            in>> message;
            ui->messageBrowser->setTextColor(Qt::blue);
            ui->messageBrowser->setCurrentFont(QFont("Times New Roman",12));
            ui->messageBrowser->append("[ " +userName+" ] "+ time);
            ui->messageBrowser->append(message);
            if(isOpen==false){
                MsgNotRcved++;
                emit newMessage(PartnerID,MsgNotRcved);
            }
            break;

        case MessageType::ParticipantLeft: // �д����
            participantLeft(userName,time);
            break;

        case MessageType::FileName: {
            in >>ipAddress;
            QString clientAddress, fileName;
            in >> clientAddress >> fileName;
            hasPendingFile(userName, ipAddress, clientAddress, fileName);
            break;
        }

        case MessageType::Refuse: {
            QString serverAddress;
            in >> serverAddress;
            QString ipAddress = Self->getIpAddress();

            if(ipAddress == serverAddress)
            {
                server->refused();
            }
            break;
        }
        case MessageType::Video:{
            int step;
            in>>step;
            VideoRequestReceived(step);
            break;
        }
        }
    }
}

void Widget_p2p::participantLeft(QString userName,QString time)
{
    //int rowNum = ui->userTableWidget->findItems(localHostName, Qt::MatchExactly).first()->row();
    //ui->userTableWidget->removeRow(rowNum);
    ui->messageBrowser->setTextColor(Qt::gray);
    ui->messageBrowser->setCurrentFont(QFont("Times New Roman", 10));
    ui->messageBrowser->append(tr("%1 �� %2 �뿪��").arg(userName).arg(time));
    //ui->userNumLabel->setText(tr("����������%1").arg(ui->userTableWidget->rowCount()));
}
QString Widget_p2p::getMessage()
{
    QString msg = ui->messageTextEdit->toHtml();
    ui->messageTextEdit->clear();
    ui->messageTextEdit->setFocus();
    return msg;
}

void Widget_p2p::on_sendButton_clicked()
{
    sendMessage(MessageType::Message);
}

void Widget_p2p::getFileName(QString name)
{
    fileName = name;
    sendMessage(MessageType::FileName);
}

void Widget_p2p::on_sendToolBtn_clicked()
{
    /*if(ui->userTableWidget->selectedItems().isEmpty())
    {
        QMessageBox::warning(0, tr("ѡ���û�"),
                             tr("���ȴ��û��б�ѡ��Ҫ���͵��û���"), QMessageBox::Ok);
        return;
    }*/
    server->show();
    server->initServer();
}

void Widget_p2p::hasPendingFile(QString userName, QString serverAddress,
                            QString clientAddress, QString fileName)
{
    QString ipAddress = Self->getIpAddress();
    if(ipAddress == clientAddress)
    {
        int btn = QMessageBox::information(this,tr("�����ļ�"),
                                           tr("����%1(%2)���ļ���%3,�Ƿ���գ�")
                                           .arg(userName).arg(serverAddress).arg(fileName),
                                           QMessageBox::Yes,QMessageBox::No);
        if (btn == QMessageBox::Yes) {
            QString name = QFileDialog::getSaveFileName(0,tr("�����ļ�"),fileName);
            if(!name.isEmpty())
            {
                TcpClient *client = new TcpClient(this);
                client->setFileName(name);
                client->setHostAddress(QHostAddress(serverAddress));
                client->show();
            }
        } else {
            sendMessage(MessageType::Refuse, serverAddress);
        }
    }
}

void Widget_p2p::on_fontComboBox_currentFontChanged(QFont f)
{
  //  QTextCursor cursor=ui->messageTextEdit->textCursor();
  //  ui->messageTextEdit->selectAll();
    ui->messageTextEdit->setCurrentFont(f);
  // ui->messageTextEdit->setTextCursor(cursor);
    ui->messageTextEdit->setFocus();
}

void Widget_p2p::on_sizeComboBox_currentIndexChanged(QString size)
{
  //  QTextCursor cursor=ui->messageTextEdit->textCursor();
  //  ui->messageTextEdit->selectAll();
    ui->messageTextEdit->setFontPointSize(size.toDouble());
 //   ui->messageTextEdit->setTextCursor(cursor);
    ui->messageTextEdit->setFocus();
}

void Widget_p2p::on_boldToolBtn_clicked(bool checked)
{
  //  QTextCursor cursor=ui->messageTextEdit->textCursor();
  //  ui->messageTextEdit->selectAll();
    if(checked)
        ui->messageTextEdit->setFontWeight(QFont::Bold);
    else
        ui->messageTextEdit->setFontWeight(QFont::Normal);
//     ui->messageTextEdit->setTextCursor(cursor);
    ui->messageTextEdit->setFocus();
}

void Widget_p2p::on_italicToolBtn_clicked(bool checked)
{
 //   QTextCursor cursor=ui->messageTextEdit->textCursor();
 //   ui->messageTextEdit->selectAll();
    ui->messageTextEdit->setFontItalic(checked);
  //  ui->messageTextEdit->setTextCursor(cursor);
    ui->messageTextEdit->setFocus();
}

void Widget_p2p::on_underlineToolBtn_clicked(bool checked)
{
    ui->messageTextEdit->setFontUnderline(checked);
    ui->messageTextEdit->setFocus();
}

void Widget_p2p::on_colorToolBtn_clicked()
{

    color = QColorDialog::getColor(color, this);
    if (color.isValid()) {

        ui->messageTextEdit->setTextColor(color);

        ui->messageTextEdit->setFocus();
    }
}

void Widget_p2p::currentFormatChanged(const QTextCharFormat &format)
{
    QTextCursor cursor=ui->messageTextEdit->textCursor();
    ui->messageTextEdit->selectAll();
    ui->messageTextEdit->setCurrentCharFormat(format);
    ui->messageTextEdit->setTextCursor(cursor);
}

void Widget_p2p::on_saveToolBtn_clicked()
{
    if (ui->messageBrowser->document()->isEmpty()) {
        QMessageBox::warning(0, tr("����"), tr("�����¼Ϊ�գ��޷����棡"), QMessageBox::Ok);
    } else {
        QString fileName = QFileDialog::getSaveFileName(this,
                                                        tr("���������¼"), tr("�����¼"), tr("�ı�(*.txt);;All File(*.*)"));
        if(!fileName.isEmpty())
            saveFile(fileName);
    }
}

bool Widget_p2p::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("�����ļ�"),
                             tr("�޷������ļ� %1:\n %2").arg(fileName)
                             .arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out << ui->messageBrowser->toPlainText();

    return true;
}

void Widget_p2p::on_clearToolBtn_clicked()
{
    ui->messageBrowser->clear();
}

void Widget_p2p::on_exitButton_clicked()
{
    sendMessage(MessageType::ParticipantLeft);
    close();
}
void Widget_p2p::showEvent(QShowEvent *e){
    isOpen=true;
    MsgNotRcved=0;
    if(VideoOpened){

    }
    QWidget::showEvent(e);
}

void Widget_p2p::closeEvent(QCloseEvent *e)
{
    sendMessage(MessageType::ParticipantLeft);
    isOpen=false;
    ui->messageBrowser->clear();
    if(VideoOpened)
        on_OpenVideoButton_clicked();
    emit closed(this);
    QWidget::closeEvent(e);
}

void Widget_p2p::setPartnerAddress(QString add)
{
    Partner->setIpAddress(add);
}

void Widget_p2p::readMessage(QByteArray mes)
{
    QDataStream in(&mes,QIODevice::ReadOnly);
    QString username,time,message;
    while(!in.atEnd())
    {
        in>>username>>time>>message;
        ui->messageBrowser->setTextColor(Qt::blue);
        ui->messageBrowser->setCurrentFont(QFont("Times New Roman",12));
        ui->messageBrowser->append("[ " +username+" ] "+ time);
        ui->messageBrowser->append(message);
    }
}

void Widget_p2p::setPartnerID(int ID)
{
    Partner->setID(ID);
    ui->id->setText(QString::number(ID));
}

void Widget_p2p::setPartnerNickname(QString nickname)
{
    Partner->setNickname(nickname);
    ui->nickname->setText(nickname);
}

void Widget_p2p::setPartner(User *user)
{
    setPartnerAddress(user->getIpAddress());
    setPartnerID(user->getID());
    setPartnerNickname(user->getNickname());
    Partner->setStatus(user->getStatus());
    setWindowTitle(tr("��%1(ID:%2)������").arg(user->getNickname()).arg(user->getID()));
}

void Widget_p2p::setSelf(User *user)
{
    Self=user;

}

int Widget_p2p::getPartnerID()
{
    return Partner->getID();
}

void Widget_p2p::on_messageTextEdit_cursorPositionChanged()
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

void Widget_p2p::on_OpenVideoButton_clicked()
{
    if(cm==NULL){
        cm=new CamThread(this);
        connect(cm,SIGNAL(ImageProducted(QImage)),ui->MyVideo,SLOT(ShowImage(QImage)));

    }
    if(!VideoOpened){
        VideoOpened=true;
    //    ui->PartnerVideo->setWindowFlags(Qt::Window);
        ui->PartnerVideo->show();
        ui->MyVideo->show();
        ui->OpenVideoButton->setText(tr("������Ƶ"));
        ui->PartnerVideo->setText(tr("���ڵȴ��Է�����..."));
        sendMessage(MessageType::Video,0);
        cm->start();
    }
    else{
        VideoOpened=false;
        if(imgskt!=NULL){
            delete imgskt;
            imgskt=NULL;
        }
        //ֹͣcm�ᵼ��ShowImage()���scaledToWidth(width())����

        if(cm!=NULL){
            cm->terminate();
            cm->wait();
         //   cm->stop();
        //    delete cm;
        //    cm==NULL;
        }
        ui->OpenVideoButton->setText(tr("��Ƶ�Ի�"));
        ui->PartnerVideo->clear();
        ui->PartnerVideo->hide();
        ui->MyVideo->clear();
        ui->MyVideo->hide();
        //�����ر�����ͷ����ShowImage()�����г����ʵȴ�һ��ʱ��
        QTimer::singleShot(500,cm,SLOT(stop()));
        sendMessage(MessageType::Video,3);
    }
}

void Widget_p2p::VideoRequestReceived(int step)
{
    if(step==0){    //�Է���������Ƶ�Ի�����
        int ok=QMessageBox::question(0,tr("��Ƶ�Ի�����"),tr("%1(ID:%2)������Ƶ�Ի����󣬽�����").arg(Partner->getNickname()).arg(Partner->getID()),QMessageBox::Yes,QMessageBox::No);
        if(ok==QMessageBox::Yes){
            sendMessage(MessageType::Video,1);
            VideoOpened=true;
            ui->PartnerVideo->show();
            ui->MyVideo->show();
            ui->OpenVideoButton->setText(tr("������Ƶ"));
            if(cm==NULL){
                cm=new CamThread(this);
            }
            cm->start();
            if(imgskt==NULL){
                imgskt=new ImgSktThread(this);
                imgskt->setPartner(Partner);
                imgskt->setSelf(Self);
            }
      //      imgskt->start();      ����Ҫ�����µ��̷߳����Ῠ
            connect(cm,SIGNAL(ImageProducted(QImage)),ui->MyVideo,SLOT(ShowImage(QImage)));
            connect(cm,SIGNAL(ImageProducted(QImage)),imgskt,SLOT(SendImage(QImage)));
            connect(imgskt,SIGNAL(ImageReceived(QImage)),ui->PartnerVideo,SLOT(ShowImage(QImage)));
            show();
        }
        else{
            sendMessage(MessageType::Video,2);
        }
    }
    else if(step==1){       //�Է�����������
        if(imgskt==NULL){
            imgskt=new ImgSktThread(this);
            imgskt->setPartner(Partner);
            imgskt->setSelf(Self);
        }
       //      imgskt->start();      ����Ҫ�����µ��̷߳����Ῠ
        connect(cm,SIGNAL(ImageProducted(QImage)),imgskt,SLOT(SendImage(QImage)));
        connect(imgskt,SIGNAL(ImageReceived(QImage)),ui->PartnerVideo,SLOT(ShowImage(QImage)));
    }
    else if(step==2){       //�Է��ܾ�������
        ui->messageBrowser->setTextColor(Qt::red);
        ui->messageBrowser->setCurrentFont(QFont("Times New Roman", 10));
        ui->messageBrowser->append(tr("�Է��ܾ�����Ƶ�Ի�����"));
        if(VideoOpened)
            on_OpenVideoButton_clicked();
    }
    else if(step==3){       //�Է��ر�����Ƶ�Ի�
        ui->messageBrowser->setTextColor(Qt::red);
        ui->messageBrowser->setCurrentFont(QFont("Times New Roman", 10));
        ui->messageBrowser->append(tr("�Է��ر�����Ƶ�Ի�"));
        if(VideoOpened)
            on_OpenVideoButton_clicked();
    }
}
