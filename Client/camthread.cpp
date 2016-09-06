#include "camthread.h"
CamThread::CamThread(QObject *parent) :
    QThread(parent)
{
    this->flag=false;
    vd=new VideoDevice(this);
    //û�����������ͻ������Ϊʲô��
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
        this->msleep(1000/30);
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
