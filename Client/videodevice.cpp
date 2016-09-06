#include "videodevice.h"
VideoDevice::VideoDevice(QObject *parent) :
    QObject(parent)
{
}

void VideoDevice::OpenCamera()
{
    cp=cvCreateCameraCapture(0);
}

void VideoDevice::CloseCamera()
{
    cvReleaseCapture(&cp);
}

QImage VideoDevice::GetFrame()
{
    frame=cvQueryFrame(cp);
    cvCvtColor(frame,frame,CV_BGR2RGB);
    QImage image((const uchar *)frame->imageData,frame->width,frame->height,QImage::Format_RGB888);
    return image;
}
