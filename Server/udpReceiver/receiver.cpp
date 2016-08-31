#include "receiver.h"
#include "ui_receiver.h"
#include<QtNetwork>
Receiver::Receiver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Receiver)
{
    ui->setupUi(this);
    receiver=new QUdpSocket(this);
    receiver->bind(45454,QUdpSocket::ShareAddress| QUdpSocket::ReuseAddressHint );
    connect(receiver,SIGNAL(readyRead()),this,SLOT(processPendingDatagram()));
}

Receiver::~Receiver()
{
    delete ui;
}

void Receiver::processPendingDatagram()
{
    while(receiver->hasPendingDatagrams()){
        QByteArray data;
        data.resize(receiver->pendingDatagramSize());
        receiver->readDatagram(data.data(),data.size());
        QString str;
        quint16 size;
        QDataStream in(&data,QIODevice::ReadOnly);
        in.setVersion(QDataStream::Qt_4_6);
        in>>size;
        in>>str;
        ui->label->setText(str);
    }
}
