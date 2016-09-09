#include <QtGui/QApplication>
#include "logindialog.h"
#include<QTextCodec>
#include<QtNetwork>
#include<QDebug>
#include<QCleanlooksStyle>
#include"widget.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle(new QCleanlooksStyle);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    LoginDialog w;
    w.show();
    int ret=app.exec();
    return ret;
}
