#include "sender.h"
#include "ui_sender.h"
#include<QtNetwork>
#include<QDataStream>
Sender::Sender(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sender)
{
    ui->setupUi(this);
    sender=new QUdpSocket(this);
    sender->bind(45454,QUdpSocket::ShareAddress| QUdpSocket::ReuseAddressHint);
    connect(sender,SIGNAL(readyRead()),this,SLOT(ReadMessage()));

}

Sender::~Sender()
{
    delete ui;
}

void Sender::on_pushButton_clicked()
{
    QByteArray datagram;
    QString str="hello world!";
    QDataStream out(&datagram,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out<<(quint16)0;
    out<<str;
    out.device()->seek(0);
    out<<(quint16)(datagram.size()-sizeof(quint16));
    sender->writeDatagram(datagram,QHostAddress(getlocalIP()),45454);

}
QString Sender::getlocalIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    QString tmp1;
    QString holdaddr="169.254.";
    foreach (QHostAddress address,list){
       if(address.protocol() == QAbstractSocket::IPv4Protocol){
                tmp1=address.toString();
                if(!(tmp1.contains(holdaddr))){    //Ìø¹ý±£ÁôµØÖ·
                    qDebug()<<tmp1;
                    return tmp1;
                }
       }
    }
    return "";
}

void Sender::ReadMessage()
{
    while(sender->hasPendingDatagrams()){
        QByteArray data;
        data.resize(sender->pendingDatagramSize());
        sender->readDatagram(data.data(),data.size());
        QString str;
        quint16 size;
        QDataStream in(&data,QIODevice::ReadOnly);
        in.setVersion(QDataStream::Qt_4_6);
        in>>size;
        in>>str;
        ui->label->setText(str);
    }
}
