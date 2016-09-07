#include "camthread.h"
CamThread::CamThread(QObject *parent) :
    QThread(parent)
{
    this->flag=false;
    vd=new VideoDevice(this);
    //没有这两条语句就会黑屏，为什么？
     vd->OpenCamera();
     for(int i=0;i<5;i++){
         vd->GetFrame();
         msleep(10);
     }

}
CamThread::~CamThread(){
    vd->CloseCamera();
    delete vd;
}

void CamThread::run()
{
    mutex.lock();
    vd->OpenCamera();
    this->flag=true;
    QImage image;
    mutex.unlock();
    while (flag)
    {
        if(vd->isOpen())
            image=vd->GetFrame();
        emit ImageProducted(image);

    }
}
void CamThread::stop()
{
  //  mutex.lock();
    this->flag = false;
    vd->CloseCamera();
   // mutex.unlock();
}
