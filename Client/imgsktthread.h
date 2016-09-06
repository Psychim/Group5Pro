#ifndef IMGSKTTHREAD_H
#define IMGSKTTHREAD_H
#include"user.h"
#include"global.h"
#include <QThread>
#include<QMutex>
#include<QUdpSocket>
#include<QImage>
class ImgSktThread : public QThread
{
    Q_OBJECT
public:
    explicit ImgSktThread(QObject *parent = 0);
    void setSelf(User *);
    void setPartner(User *);
    void setroom(int );
    void setport(int);
    void run();
    void stop();
private:
    QMutex mutex;
    QUdpSocket *udpsocket;
    bool flag;
    int port;
    User*Self;
    User*Partner;
    int room;
signals:
    void ImageReceived(QImage);
public slots:
    void ReadImage();
    void SendImage(QImage);
};

#endif // IMGSKTTHREAD_H
