#ifndef VIDEODEVICE_H
#define VIDEODEVICE_H

#include <QObject>
#include<cv.h>
#include<highgui.h>
#include<QImage>
class VideoDevice : public QObject
{
    Q_OBJECT
public:
    explicit VideoDevice(QObject *parent = 0);
    void OpenCamera();
    ~VideoDevice();
    QImage GetFrame();
    bool isOpen();
private:
    CvCapture *cp;
    IplImage *frame;
    bool Opened;
signals:

public slots:
    void CloseCamera();
};

#endif // VIDEODEVICE_H
