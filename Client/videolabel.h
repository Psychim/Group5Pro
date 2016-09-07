#ifndef VIDEOLABEL_H
#define VIDEOLABEL_H

#include <QLabel>

class VideoLabel : public QLabel
{
    Q_OBJECT
public:
    explicit VideoLabel(QWidget *parent = 0);

signals:
    void ImageFreshed();
public slots:
    void ShowImage(QImage);
};

#endif // VIDEOLABEL_H
