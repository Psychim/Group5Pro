#include <QtGui/QApplication>
#include "sender.h"
#include<QtNetwork>
#include<QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sender w;
    w.show();

    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach (QHostAddress address, list)
    {
       if(address.protocol() == QAbstractSocket::IPv4Protocol)
           qDebug()<<address;
    }

    return a.exec();
}
