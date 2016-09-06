#include "videolabel.h"

VideoLabel::VideoLabel(QWidget *parent) :
    QLabel(parent)
{
}

void VideoLabel::ShowImage(QImage image)
{
    image.scaledToWidth(width());
    image.scaledToHeight(height());
    setPixmap(QPixmap::fromImage(image));
}
