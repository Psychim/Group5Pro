#include <QtGui/QApplication>
#include "mainwindow.h"
#include<QTextCodec>
#include"connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    if(!createConnection()) return 1;
    MainWindow w;
    w.show();

    return a.exec();
}
