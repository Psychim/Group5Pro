#include "camthread.h"
CamThread::CamThread(QObject *parent) :
    QThread(parent)
{
    this->flag=false;
    vd=new VideoDevice(this);
    //没有这两条语句就会黑屏，为什么？
     vd->OpenCamera();
     vd->GetFrame();
}
void CamThread::run()
{
    mutex.lock();
    vd->OpenCamera();
    this->flag=true;
    mutex.unlock();
    while (flag)
    {
        emit ImageProducted(vd->GetFrame());
        this->msleep(40);
    }
}
void CamThread::stop()
{
    mutex.lock();
    this->flag = false;
    wait(1000);
    vd->CloseCamera();
    mutex.unlock();
}
