#include "camthread.h"
CamThread::CamThread(QObject *parent) :
    QThread(parent)
{
    this->flag=false;
    vd=new VideoDevice(this);
    //û�����������ͻ������Ϊʲô��
     vd->OpenCamera();
     QImage image;
     do{
         image=vd->GetFrame();
         msleep(1000/30);
     }while(image.allGray());

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
        msleep(1000/30);
    }
}
void CamThread::stop()
{
  //  mutex.lock();
    this->flag = false;
    vd->CloseCamera();
   // mutex.unlock();
}
