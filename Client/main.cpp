#include <QtGui/QApplication>
#include "logindialog.h"
#include<QTextCodec>
#include<QtNetwork>
#include<QDebug>
#include"widget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    LoginDialog w;
    w.show();
    int ret=a.exec();
    return ret;
}
