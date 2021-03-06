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
#include <QAudioInput>
#include <QAudioOutput>
#include <QByteArray>
#include "cg729encoder.h"
#include "cg729decoder.h"
#include "cudpthread.h"
#include <QThread>

// 一个与音频聊天相关的变量
const int BUFFER_SIZE = 1024*64;

Widget_p2p::Widget_p2p(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_p2p)
{
   // this->setWindowFlags();
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    ui->setupUi(this);

    Partner=new User(this);
    Self=NULL;
    isOpen=false;
    MsgNotRcved=0;
    udpSocket = new QUdpSocket(this);
    port = 25253;
    if(!udpSocket->bind(port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint)){
        QMessageBox::warning(0, tr("警告"), tr("无法绑定端口"), QMessageBox::Ok);
    }
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
   //sendMessage(NewParticipant);

   server = new TcpServer(this);
   connect(server, SIGNAL(sendFileName(QString)), this, SLOT(getFileName(QString)));
   connect(ui->messageTextEdit, SIGNAL(currentCharFormatChanged(QTextCharFormat)),
               this, SLOT(currentFormatChanged(const QTextCharFormat)));
   //视频对话部分
   ui->PartnerVideo->hide();
   ui->MyVideo->hide();
   VideoOpened=false;
   cm=NULL;
   imgskt=NULL;

   // 音频对话部分
   //设置采样格式
   QAudioFormat audioFormat;
   //设置采样率
   audioFormat.setSampleRate(8000);
   //设置通道数
   audioFormat.setChannelCount(1);
   //设置采样大小，一般为8位或16位
   audioFormat.setSampleSize(16);
   //设置编码方式
   audioFormat.setCodec("audio/pcm");
   //设置字节序
   audioFormat.setByteOrder(QAudioFormat::LittleEndian);
   //设置样本数据类型
   audioFormat.setSampleType(QAudioFormat::UnSignedInt);

   //获取设备信息
   QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
   if (!info.isFormatSupported(audioFormat))
   {
       qDebug()<<"default format not supported try to use nearest";
       audioFormat = info.nearestFormat(audioFormat);
   }

   info = QAudioDeviceInfo::defaultOutputDevice();
   if (!info.isFormatSupported(audioFormat)) {
       qDebug()<<"default format not supported try to use nearest";
       audioFormat = info.nearestFormat(audioFormat);
   }

   audioInput = new QAudioInput(audioFormat, this);
   //将麦克风的音频数据传输到输入设备
   streamIn = audioInput->start();

   //当输入设备检测到数据时，调用槽函数slotSendData
   connect(streamIn, SIGNAL(readyRead()),this, SLOT(slotSendData()));

   audioOutput = new QAudioOutput(audioFormat, this);
   //将音频数据传输到输出设备，再由输出设备写入到扬声器
   streamOut = audioOutput->start();

   // 以下部分是与音频传输有关的，开启音频传输的线程

}

Widget_p2p::~Widget_p2p()
{
    delete ui;
    delete cm;
    delete udpThreadFather;
}


void Widget_p2p::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons()&Qt::LeftButton)
    {
     //   if(event->y()<=ui->frame->height())
     //   {
            QPoint temp;
            temp=event->globalPos()-offset;
            move(temp);
    //    }
    }
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
            QMessageBox::warning(0,tr("警告"),tr("发送内容不能为空"),QMessageBox::Ok);
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

    case MessageType::FileName : { // 此处需要主界面传来的IP地址 ！！！
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
    udpSocket->writeDatagram(data,QHostAddress::Broadcast, port); // 单播无法解决端口冲突问题，故广播
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
    udpSocket->writeDatagram(data,QHostAddress::Broadcast, port); // 单播无法解决端口冲突问题，故广播
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

        case MessageType::ParticipantLeft: // 有待解决
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
    ui->messageBrowser->append(tr("%1 于 %2 离开！").arg(userName).arg(time));
    //ui->userNumLabel->setText(tr("在线人数：%1").arg(ui->userTableWidget->rowCount()));
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
        QMessageBox::warning(0, tr("选择用户"),
                             tr("请先从用户列表选择要传送的用户！"), QMessageBox::Ok);
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
        int btn = QMessageBox::information(this,tr("接受文件"),
                                           tr("来自%1(%2)的文件：%3,是否接收？")
                                           .arg(userName).arg(serverAddress).arg(fileName),
                                           QMessageBox::Yes,QMessageBox::No);
        if (btn == QMessageBox::Yes) {
            QString name = QFileDialog::getSaveFileName(0,tr("保存文件"),fileName);
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
        QMessageBox::warning(0, tr("警告"), tr("聊天记录为空，无法保存！"), QMessageBox::Ok);
    } else {
        QString fileName = QFileDialog::getSaveFileName(this,
                                                        tr("保存聊天记录"), tr("聊天记录"), tr("文本(*.txt);;All File(*.*)"));
        if(!fileName.isEmpty())
            saveFile(fileName);
    }
}

bool Widget_p2p::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("保存文件"),
                             tr("无法保存文件 %1:\n %2").arg(fileName)
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
    Partner=user;
    ui->id->setText(QString::number(Partner->getID()));
    ui->nickname->setText(Partner->getNickname());
    ui->label_3->setText(tr("与%1(ID:%2)聊天中").arg(user->getNickname()).arg(user->getID()));
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
        ui->OpenVideoButton->setText(tr("结束视频"));
        ui->PartnerVideo->setText(tr("正在等待对方接受..."));
        sendMessage(MessageType::Video,0);
        cm->start();


        udpThread=new CUdpThread();
        udpThreadFather=new QThread();
        udpThread->moveToThread(udpThreadFather);
        connect(udpThreadFather,SIGNAL(started()),udpThread,SLOT(run()));

        udpThreadFather->start();

        connect(this,SIGNAL(signalSendData(const QByteArray &)),udpThread,SLOT(slotSendData(const QByteArray &)));
        connect(udpThread,SIGNAL(signalSendData(const QByteArray &)),this,SLOT(slotReadData(const QByteArray &)));


        udpThread->setIpAddress(Partner->getIpAddress());

    }
    else{
        VideoOpened=false;
        if(imgskt!=NULL){
            delete imgskt;
            imgskt=NULL;
        }
        //停止cm会导致ShowImage()里的scaledToWidth(width())出错

        if(cm!=NULL){
            cm->terminate();
            cm->wait();

         //   cm->stop();
        //    delete cm;
        //    cm==NULL;
        }


        connect(this,SIGNAL(stopVoice()),udpThread,SLOT(stopSocket()));
        connect(udpThread,SIGNAL(stopThread()),this,SLOT(stopThread()));
        emit stopVoice();
        // 结束音频聊天线程
        //delete udpThread;
        //udpThreadFather->terminate();
        //udpThreadFather->wait();
        // 音频聊天线程已结束

        ui->OpenVideoButton->setText(tr("视频对话"));
        ui->PartnerVideo->clear();
        ui->PartnerVideo->hide();
        ui->MyVideo->clear();
        ui->MyVideo->hide();
        QTimer::singleShot(500,cm,SLOT(stop()));
        sendMessage(MessageType::Video,3);
    }
}

void Widget_p2p::VideoRequestReceived(int step)
{
    if(step==0){    //对方发来了视频对话请求
        int ok=QMessageBox::question(0,tr("视频对话请求"),tr("%1(ID:%2)发来视频对话请求，接受吗？").arg(Partner->getNickname()).arg(Partner->getID()),QMessageBox::Yes,QMessageBox::No);
        if(ok==QMessageBox::Yes){
            sendMessage(MessageType::Video,1);
            VideoOpened=true;
            ui->PartnerVideo->show();
            ui->MyVideo->show();
            ui->OpenVideoButton->setText(tr("结束视频"));
            if(cm==NULL){
                cm=new CamThread(this);
            }
            cm->start();
            if(imgskt==NULL){
                imgskt=new ImgSktThread(this);
                imgskt->setPartner(Partner);
                imgskt->setSelf(Self);
            }
      //      imgskt->start();      不需要，用新的线程反而会卡
            connect(cm,SIGNAL(ImageProducted(QImage)),ui->MyVideo,SLOT(ShowImage(QImage)));
            connect(cm,SIGNAL(ImageProducted(QImage)),imgskt,SLOT(SendImage(QImage)));
            connect(imgskt,SIGNAL(ImageReceived(QImage)),ui->PartnerVideo,SLOT(ShowImage(QImage)));
            show();
        }
        else{
            sendMessage(MessageType::Video,2);
        }
    }
    else if(step==1){       //对方接受了请求
        if(imgskt==NULL){
            imgskt=new ImgSktThread(this);
            imgskt->setPartner(Partner);
            imgskt->setSelf(Self);
        }
       //      imgskt->start();      不需要，用新的线程反而会卡
        connect(cm,SIGNAL(ImageProducted(QImage)),imgskt,SLOT(SendImage(QImage)));
        connect(imgskt,SIGNAL(ImageReceived(QImage)),ui->PartnerVideo,SLOT(ShowImage(QImage)));
    }
    else if(step==2){       //对方拒绝了请求
        ui->messageBrowser->setTextColor(Qt::red);
        ui->messageBrowser->setCurrentFont(QFont("Times New Roman", 10));
        ui->messageBrowser->append(tr("对方拒绝了视频对话请求！"));
        if(VideoOpened)
            on_OpenVideoButton_clicked();
    }
    else if(step==3){       //对方关闭了视频对话
        ui->messageBrowser->setTextColor(Qt::red);
        ui->messageBrowser->setCurrentFont(QFont("Times New Roman", 10));
        ui->messageBrowser->append(tr("对方关闭了视频对话"));
        if(VideoOpened)
            on_OpenVideoButton_clicked();
    }
}



// 以下是与音频相关

void Widget_p2p::slotSendData()
{

    short srcAudio[L_FRAME]={0};
    unsigned char dstAudio[L_FRAME_COMPRESSED]={'\0'};
    if (!audioInput)
    {
        qDebug() << "AudioInput Error";
        return;
    }

    QByteArray dataBuffer(BUFFER_SIZE,0);
    qint64 len1 = audioInput->bytesReady();

    if (len1 > BUFFER_SIZE)
    {
        qDebug()<<"BUFFER_SIZE too small";
        return;
    }
    qint64 len2 = streamIn->read(dataBuffer.data(), len1);

    tempBuffer.append(dataBuffer.data(),len2);

    for(int i=0;i<tempBuffer.length()/(L_FRAME*2);i++)
    {
        //char转short
        memcpy(srcAudio,tempBuffer.data()+i*L_FRAME*2,L_FRAME*2);
        //编码
        cg729Encoder.encode(srcAudio, dstAudio);
        QByteArray frame;
        //reinterpret_cast用于强制转换，这里将unsigned char *转换为const char *
        frame.append(reinterpret_cast<const char*>(dstAudio),L_FRAME_COMPRESSED);
        emit signalSendData(frame);
    }
    tempBuffer.clear();
}


void Widget_p2p::slotReadData(const QByteArray &byte_array)
{

    for(int i=0;i<byte_array.length()/L_FRAME_COMPRESSED;i++)
    {
        unsigned char srcAudio[L_FRAME_COMPRESSED]={'\0'};
        short dstAudio[L_FRAME]={0};
        memcpy(srcAudio,(unsigned char*)byte_array.data()+i * L_FRAME_COMPRESSED,L_FRAME_COMPRESSED);
        //G729解码
        cg729Decoder.decode(srcAudio,dstAudio,0);
        //short转char
        tempframe.append((char *)dstAudio,L_FRAME * 2);

        if(audioOutput&&audioOutput->state()!=QAudio::StoppedState&&
                audioOutput->state()!=QAudio::SuspendedState)
        {
              int chunks = audioOutput->bytesFree()/audioOutput->periodSize();
              while (chunks)
              {
                  if (tempframe.length() >= audioOutput->periodSize())
                  {
                      //写入到扬声器
                      streamOut->write(tempframe.data(),audioOutput->periodSize());
                      tempframe = tempframe.mid(audioOutput->periodSize());
                  }
                  else
                  {
                      //写入到扬声器
                      streamOut->write(tempframe);
                      tempframe.clear();
                      break;
                  }
                  --chunks;
              }
         }
    }
}

void Widget_p2p::on_pushButton_clicked()
{
    showMinimized();
}

void Widget_p2p::on_pushButton_2_clicked()
{
    close();
}

void Widget_p2p::stopThread()
{
    udpThreadFather->terminate();
    udpThreadFather->wait();
}
void Widget_p2p::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
        if(event->y()<=ui->frame->height())
            offset=event->globalPos()-pos();
}
