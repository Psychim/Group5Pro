#include<QtGui/QApplication>
#include<QTextCodec>
#include"server.h"
#include"mainwindow.h"
int main(int argc,char *argv[]){
    QApplication MainApp(argc,argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    MainWindow mw;
    mw.show();
    return MainApp.exec();
}
