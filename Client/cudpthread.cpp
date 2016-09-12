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
    udpSocketRecv->bind(25000, QUdpSocket::ShareAddress); // �˿ں�25000���д��޸�
    connect(udpSocketRecv, SIGNAL(readyRead()), this, SLOT(ReadPendingDatagrams()),Qt::DirectConnection);
//    while(needStop)
//    {
//        delete udpsocketSend;
//        delete udpSocketRecv;
//        break;
//    }
}

void CUdpThread::ReadPendingDatagrams() // ͨ��CUdpThread������������������ܶԷ���������Ϣ��Ȼ���ٴ���widget�����д�������
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

void CUdpThread::slotSendData(const QByteArray &byte_array) // ͨ��CUdpThread��������Ѵ�Widget�ഫ���ı�������Ϣ���ⷢ��
{
    udpsocketSend->writeDatagram(byte_array,QHostAddress(IpAddress), 25000); // �˿ں�25000
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
