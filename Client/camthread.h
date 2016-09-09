#ifndef CAMTHREAD_H
#define CAMTHREAD_H

#include <QThread>
#include<videodevice.h>
#include<QByteArray>
#include<QBuffer>
#include<QMutex>
#include<QImage>
class CamThread : public QThread
{
    Q_OBJECT
public:
    explicit CamThread(QObject *parent=0);
    void run();
    ~CamThread();

    VideoDevice *vd;
    bool flag;
    QMutex mutex;
signals:
    void ImageProducted(QImage);
public slots:
    void stop();
};

#endif // CAMTHREAD_H
