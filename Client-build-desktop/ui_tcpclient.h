/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created: Wed Aug 31 16:37:00 2016
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

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

class Ui_TcpClient
{
public:
    QPushButton *tcpClientCancelBtm;
    QPushButton *tcpClientCloseBtn;
    QProgressBar *progressBar;
    QLabel *tcpClientStatusLabel;

    void setupUi(QDialog *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName(QString::fromUtf8("TcpClient"));
        TcpClient->resize(400, 300);
        tcpClientCancelBtm = new QPushButton(TcpClient);
        tcpClientCancelBtm->setObjectName(QString::fromUtf8("tcpClientCancelBtm"));
        tcpClientCancelBtm->setGeometry(QRect(70, 230, 75, 23));
        tcpClientCloseBtn = new QPushButton(TcpClient);
        tcpClientCloseBtn->setObjectName(QString::fromUtf8("tcpClientCloseBtn"));
        tcpClientCloseBtn->setGeometry(QRect(250, 230, 75, 23));
        progressBar = new QProgressBar(TcpClient);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(110, 150, 191, 23));
        progressBar->setValue(0);
        tcpClientStatusLabel = new QLabel(TcpClient);
        tcpClientStatusLabel->setObjectName(QString::fromUtf8("tcpClientStatusLabel"));
        tcpClientStatusLabel->setGeometry(QRect(110, 80, 161, 16));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        tcpClientStatusLabel->setFont(font);
        tcpClientStatusLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QDialog *TcpClient)
    {
        TcpClient->setWindowTitle(QApplication::translate("TcpClient", "\346\216\245\346\224\266\347\253\257", 0, QApplication::UnicodeUTF8));
        tcpClientCancelBtm->setText(QApplication::translate("TcpClient", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        tcpClientCloseBtn->setText(QApplication::translate("TcpClient", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        tcpClientStatusLabel->setText(QApplication::translate("TcpClient", "\347\255\211\345\276\205\346\216\245\346\224\266\346\226\207\344\273\266......", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
