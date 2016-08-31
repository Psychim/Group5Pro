/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created: Wed Aug 31 16:37:00 2016
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TcpServer
{
public:
    QLabel *serverStatusLabel;
    QProgressBar *progressBar;
    QPushButton *serverOpenBtn;
    QPushButton *serverSendBtn;
    QPushButton *serverCloseBtn;

    void setupUi(QDialog *TcpServer)
    {
        if (TcpServer->objectName().isEmpty())
            TcpServer->setObjectName(QString::fromUtf8("TcpServer"));
        TcpServer->resize(400, 300);
        serverStatusLabel = new QLabel(TcpServer);
        serverStatusLabel->setObjectName(QString::fromUtf8("serverStatusLabel"));
        serverStatusLabel->setGeometry(QRect(0, 50, 401, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        serverStatusLabel->setFont(font);
        serverStatusLabel->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(TcpServer);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(90, 130, 211, 23));
        progressBar->setValue(0);
        serverOpenBtn = new QPushButton(TcpServer);
        serverOpenBtn->setObjectName(QString::fromUtf8("serverOpenBtn"));
        serverOpenBtn->setGeometry(QRect(40, 200, 75, 23));
        serverSendBtn = new QPushButton(TcpServer);
        serverSendBtn->setObjectName(QString::fromUtf8("serverSendBtn"));
        serverSendBtn->setGeometry(QRect(160, 200, 75, 23));
        serverCloseBtn = new QPushButton(TcpServer);
        serverCloseBtn->setObjectName(QString::fromUtf8("serverCloseBtn"));
        serverCloseBtn->setGeometry(QRect(280, 200, 75, 23));

        retranslateUi(TcpServer);

        QMetaObject::connectSlotsByName(TcpServer);
    } // setupUi

    void retranslateUi(QDialog *TcpServer)
    {
        TcpServer->setWindowTitle(QApplication::translate("TcpServer", "\345\217\221\351\200\201\347\253\257", 0, QApplication::UnicodeUTF8));
        serverStatusLabel->setText(QApplication::translate("TcpServer", "\350\257\267\351\200\211\346\213\251\350\246\201\345\217\221\351\200\201\347\232\204\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        serverOpenBtn->setText(QApplication::translate("TcpServer", "\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
        serverSendBtn->setText(QApplication::translate("TcpServer", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        serverCloseBtn->setText(QApplication::translate("TcpServer", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TcpServer: public Ui_TcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
