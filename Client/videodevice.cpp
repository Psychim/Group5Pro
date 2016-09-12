#include "videodevice.h"
#include<QDebug>
VideoDevice::VideoDevice(QObject *parent) :
    QObject(parent)
{
    Opened=false;
    devicenum=videoInput::listDevices();
    vi=NULL;
    buffer=NULL;

}
VideoDevice::~VideoDevice(){
    CloseCamera();
}

bool VideoDevice::OpenCamera()
{
    if(Opened) return true;
    vi=new videoInput;
    for(runningDevice=0;runningDevice<devicenum;runningDevice++){
        if(vi->setupDevice(runningDevice)){
            Opened=true;
            width=vi->getWidth(runningDevice);
            height=vi->getHeight(runningDevice);
            if(buffer)  delete buffer;
                buffer=new unsigned char[vi->getSize(runningDevice)];
            break;
        }
    }
   // vi->showSettingsWindow(runningDevice);
    return Opened;

}

void VideoDevice::CloseCamera()
{
    vi->stopDevice(runningDevice);
    delete buffer;
    delete vi;
    buffer=NULL;
    Opened=false;
}

QImage VideoDevice::GetFrame()
{
    if(vi->isFrameNew(runningDevice)){
        qDebug()<<" succeed to get frame";
        vi->getPixels(runningDevice,buffer,true,true);
        QImage image((const uchar *)buffer,width,height,QImage::Format_RGB888);
        return image;
    }
    else{
        return QImage();
    }
}

bool VideoDevice::isOpen()
{
    return Opened;
}
