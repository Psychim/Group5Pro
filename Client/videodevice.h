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
    void CloseCamera();
    QImage GetFrame();
private:
    CvCapture *cp;
    IplImage *frame;
signals:

public slots:

};

#endif // VIDEODEVICE_H
