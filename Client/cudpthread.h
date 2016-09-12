#ifndef CUDPTHREAD_H
#define CUDPTHREAD_H

#include <QObject>
#include <QQueue>
#include <QMutex>
#include <QByteArray>
#include <QUdpSocket>
#include <QThread>
class CUdpThread : public QObject // ¿ØÖÆÏß³Ì
{
    Q_OBJECT

public:
    CUdpThread();
    ~CUdpThread();
    void setIpAddress(QString);
    //int needStop;

    QUdpSocket * udpsocketSend;
    QUdpSocket * udpSocketRecv;
private:

    bool stopFlag;
    QString IpAddress;

private slots:
     void ReadPendingDatagrams();
     void run();
     void slotSendData(const QByteArray &byte_array);
     void stopSocket();
signals:
     void signalSendData(const QByteArray &byte_array);
     void stopThread();
};

#endif // CUDPTHREAD_H
