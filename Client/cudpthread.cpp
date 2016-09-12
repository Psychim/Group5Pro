#include "cudpthread.h"
#include <QDebug>
#include<QThread>

//QString CUdpThread::IpAddress;

CUdpThread::CUdpThread()
{
    //needStop=0;
}
CUdpThread::~CUdpThread()
{
    //needStop=1;
    //quit();
    //wait();
}

void CUdpThread::run()
{
    udpsocketSend=new QUdpSocket(this);
    udpSocketRecv = new QUdpSocket(this);
    udpSocketRecv->bind(25000, QUdpSocket::ShareAddress); // 端口号25000，有待修改
    connect(udpSocketRecv, SIGNAL(readyRead()), this, SLOT(ReadPendingDatagrams()),Qt::DirectConnection);
//    while(needStop)
//    {
//        delete udpsocketSend;
//        delete udpSocketRecv;
//        break;
//    }
}

void CUdpThread::ReadPendingDatagrams() // 通过CUdpThread这个类的这个函数来接受对方传来的信息，然后再传给widget来进行处理，播放
{
    QByteArray datagram;
    while (udpSocketRecv->hasPendingDatagrams())
    {
           datagram.resize(udpSocketRecv->pendingDatagramSize());
           QHostAddress sender;
           quint16 senderPort;

           udpSocketRecv->readDatagram(
           datagram.data(),
           datagram.size(),
           &sender,
           &senderPort);
           if(datagram.size()>0)
           {
               emit signalSendData(datagram);
           }
     }
}

void CUdpThread::slotSendData(const QByteArray &byte_array) // 通过CUdpThread这个类来把从Widget类传来的编过码的消息向外发送
{
    udpsocketSend->writeDatagram(byte_array,QHostAddress(IpAddress), 25000); // 端口号25000
}

void CUdpThread::setIpAddress(QString ip)
{
    IpAddress=ip;
}


void CUdpThread::stopSocket()
{
    if(udpSocketRecv->state()==QUdpSocket::BoundState)
        udpSocketRecv->abort();
    emit stopThread();
}
