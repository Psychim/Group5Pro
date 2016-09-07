#include "videolabel.h"

VideoLabel::VideoLabel(QWidget *parent) :
    QLabel(parent)
{
}

void VideoLabel::ShowImage(QImage image)
{
    if(image.isNull())  return;
    image=image.scaledToWidth(width());
    image=image.scaledToHeight(height());
    setPixmap(QPixmap::fromImage(image));
}
