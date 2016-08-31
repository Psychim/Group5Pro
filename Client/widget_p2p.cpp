#include "widget_p2p.h"
#include "ui_widget_p2p.h"
#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>
#include "global.h"
#include "tcpserver.h"
#include "tcpclient.h"
#include <QFileDialog>

#include <QColorDialog>

Widget_p2p::Widget_p2p(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_p2p)
{
    setWindowFlags(Qt::Window);
    ui->setupUi(this);
    Partner=new User(this);
    Self=new User(this);
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
}

Widget_p2p::~Widget_p2p()
{
    delete ui;
    qDebug()<<1;
}


void Widget_p2p::sendMessage(MessageType::MessageType type, QString serverAddress)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(VERSION);
    //QString localHostName = QHostInfo::localHostName();
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
        in >> messageType;
        QString userName,ipAddress,message;
        int PartnerID,SelfID;
        QString time = QDateTime::currentDateTime()
                .toString("yyyy-MM-dd hh:mm:ss");
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

/*QString Widget_p2p::getUserName()
{
    QStringList envVariables;
    envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
                 << "HOSTNAME.*" << "DOMAINNAME.*";
    QStringList environment = QProcess::systemEnvironment();
    foreach (QString string, envVariables) {
        int index = environment.indexOf(QRegExp(string));
        if (index != -1) {
            QStringList stringList = environment.at(index).split('=');
            if (stringList.size() == 2) {
                return stringList.at(1);
                break;
            }
        }
    }
    return "unknown";
}*/

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
    ui->messageTextEdit->setCurrentFont(f);
    ui->messageTextEdit->setFocus();
}

void Widget_p2p::on_sizeComboBox_currentIndexChanged(QString size)
{
    ui->messageTextEdit->setFontPointSize(size.toDouble());
    ui->messageTextEdit->setFocus();
}

void Widget_p2p::on_boldToolBtn_clicked(bool checked)
{
    if(checked)
        ui->messageTextEdit->setFontWeight(QFont::Bold);
    else
        ui->messageTextEdit->setFontWeight(QFont::Normal);
    ui->messageTextEdit->setFocus();
}

void Widget_p2p::on_italicToolBtn_clicked(bool checked)
{
    ui->messageTextEdit->setFontItalic(checked);
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
    ui->fontComboBox->setCurrentFont(format.font());

    // 如果字体大小出错(因为我们最小的字体为9)，使用12
    if (format.fontPointSize() < 9) {
        ui->sizeComboBox->setCurrentIndex(3);
    } else {
        ui->sizeComboBox->setCurrentIndex( ui->sizeComboBox
                                          ->findText(QString::number(format.fontPointSize())));
    }
    ui->boldToolBtn->setChecked(format.font().bold());
    ui->italicToolBtn->setChecked(format.font().italic());
    ui->underlineToolBtn->setChecked(format.font().underline());
    color = format.foreground().color();
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

void Widget_p2p::closeEvent(QCloseEvent *e)
{
    sendMessage(MessageType::ParticipantLeft);
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
}

void Widget_p2p::setSelf(User *user)
{
    Self->setID(user->getID());
    Self->setIpAddress(user->getIpAddress());
    Self->setNickname(user->getNickname());
    Self->setStatus(user->getStatus());
}
