#include "camthread.h"
CamThread::CamThread(QObject *parent) :
    QThread(parent)
{
    this->flag=false;
    vd=new VideoDevice(this);
    //û�����������ͻ������Ϊʲô��
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
