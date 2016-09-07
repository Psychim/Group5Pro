#include "imgsktthread.h"
#include<QBuffer>
ImgSktThread::ImgSktThread(QObject *parent) :
    QThread(parent)
{
    udpsocket= new QUdpSocket(this);
    port=25255;
    udpsocket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    connect(udpsocket,SIGNAL(readyRead()),this,SLOT(ReadImage()));
    flag=false;
    room=0;
    Self=NULL;
    Partner=NULL;
}

void ImgSktThread::run()
{
    mutex.lock();
    flag=true;
    mutex.unlock();
    while(flag){
        udpsocket->waitForReadyRead(1000/30);
    }
}

void ImgSktThread::stop()
{
    mutex.lock();
    flag=false;
    udpsocket->abort();
    wait(1000);
    mutex.unlock();
}

void ImgSktThread::ReadImage()
{
    while(udpsocket->hasPendingDatagrams()){
        QByteArray datagram;
        QByteArray imagebuffer;
        datagram.resize(udpsocket->pendingDatagramSize());
        udpsocket->readDatagram(datagram.data(), datagram.size());
        QDataStream in(&datagram,QIODevice::ReadOnly);
        in.setVersion(VERSION);
        int flag;
        in>>flag;
        if(flag==1){
            if(room==0) return;
            int rmid,sid;
            in>>rmid>>sid;
            if(rmid!=room)
                return;
        }
        if(flag==0){
            if(Partner==NULL)   return;
            int sid,pid;
            in>>pid>>sid;
            if(pid!=Partner->getID()||sid!=Self->getID())
                return;
        }
        in>>imagebuffer;
        QImage image;
        image.loadFromData(imagebuffer,"JPG");
        emit ImageReceived(image);
    }
}

void ImgSktThread::SendImage(QImage image)
{
    QByteArray datagram;
    QByteArray imagebuffer;
    QBuffer buffer(&imagebuffer);
    QDataStream out(&datagram,QIODevice::WriteOnly);
    out.setVersion(VERSION);
    if(Partner==NULL){
        out<<1<<room<<Self->getID();
    }
    else{
        out<<0<<Self->getID()<<Partner->getID();
    }
    image=image.scaledToHeight(240);
    image=image.scaledToWidth(180);
    image.save(&buffer,"JPG");
    out<<imagebuffer;
    udpsocket->writeDatagram(datagram,QHostAddress::Broadcast,port);
}

void ImgSktThread::setSelf(User *user)
{
    Self=user;
}

void ImgSktThread::setPartner(User *user)
{
    Partner=user;
}

void ImgSktThread::setroom(int id)
{
    room=id;
}

void ImgSktThread::setport(int p)
{
    port=p;
}
