#ifndef VIDEODEVICE_H
#define VIDEODEVICE_H
#include <QObject>
#include<cv.h>
#include<highgui.h>
#include<QImage>
#include"videoInput.h"
class VideoDevice : public QObject
{
    Q_OBJECT
public:
    explicit VideoDevice(QObject *parent = 0);
    bool OpenCamera();
    ~VideoDevice();
    QImage GetFrame();
    bool isOpen();
    int width;
    int height;
private:
    CvCapture *cp;
    unsigned char *buffer;
    bool Opened;
    int devicenum;
    int runningDevice;
    videoInput *vi;
signals:

public slots:
    void CloseCamera();
};

#endif // VIDEODEVICE_H
