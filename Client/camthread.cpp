#include "camthread.h"
CamThread::CamThread(QObject *parent) :
    QThread(parent)
{
    this->flag=false;
    vd=NULL;
    mutex=new QMutex;
}
void CamThread::run()
{
    vd=new VideoDevice(this);
    vd->OpenCamera();
    this->flag=true;
    mutex->lock();
    while (flag)
    {
        mutex->unlock();
        emit ImageProducted(vd->GetFrame());
        this->msleep(40);
    }
}
void CamThread::stop()
{
    mutex->lock();
    this->flag = false;
    wait(1000);
    vd->CloseCamera();
    mutex->unlock();
}
