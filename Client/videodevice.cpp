#include "videodevice.h"
VideoDevice::VideoDevice(QObject *parent) :
    QObject(parent)
{
    Opened=false;
    devicenum=videoInput::listDevices();
    vi=new videoInput;
    buffer=NULL;
}
VideoDevice::~VideoDevice(){
    delete buffer;
    delete vi;
}

bool VideoDevice::OpenCamera()
{
    if(Opened) return false;
   // cp=cvCreateCameraCapture(-1);
    for(runningDevice=0;runningDevice<devicenum;runningDevice++){
        if(vi->setupDevice(runningDevice)){
            Opened=true;
            width=vi->getWidth(runningDevice);
            height=vi->getHeight(runningDevice);
            buffer=new unsigned char[vi->getSize(runningDevice)];
            break;
        }
    }
    return Opened;

}

void VideoDevice::CloseCamera()
{
    vi->stopDevice(runningDevice);
    delete buffer;
    Opened=false;
}

QImage VideoDevice::GetFrame()
{
    if(vi->isFrameNew(runningDevice)){
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
