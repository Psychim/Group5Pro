#include "videodevice.h"
VideoDevice::VideoDevice(QObject *parent) :
    QObject(parent)
{
    Opened=false;

}
VideoDevice::~VideoDevice(){
    if(Opened)
        cvReleaseCapture(&cp);
}

void VideoDevice::OpenCamera()
{
    cp=cvCreateCameraCapture(-1);
    cvSetCaptureProperty(cp,CV_CAP_PROP_FRAME_WIDTH,640);
    cvSetCaptureProperty(cp,CV_CAP_PROP_FRAME_HEIGHT,480);
    Opened=true;
}

void VideoDevice::CloseCamera()
{
    cvReleaseCapture(&cp);
    Opened=false;
}

QImage VideoDevice::GetFrame()
{
    frame=cvQueryFrame(cp);
    cvCvtColor(frame,frame,CV_BGR2RGB);
    QImage image((const uchar *)frame->imageData,frame->width,frame->height,QImage::Format_RGB888);
    return image;
}

bool VideoDevice::isOpen()
{
    return Opened;
}
