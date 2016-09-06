#include "videolabel.h"

VideoLabel::VideoLabel(QWidget *parent) :
    QLabel(parent)
{
}

void VideoLabel::ShowImage(QImage image)
{
    setPixmap(QPixmap::fromImage(image));
}
