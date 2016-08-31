/********************************************************************************
** Form generated from reading UI file 'receiver.ui'
**
** Created: Sat Aug 27 10:53:14 2016
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVER_H
#define UI_RECEIVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Receiver
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QDialog *Receiver)
    {
        if (Receiver->objectName().isEmpty())
            Receiver->setObjectName(QString::fromUtf8("Receiver"));
        Receiver->resize(400, 300);
        horizontalLayout = new QHBoxLayout(Receiver);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Receiver);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);


        retranslateUi(Receiver);

        QMetaObject::connectSlotsByName(Receiver);
    } // setupUi

    void retranslateUi(QDialog *Receiver)
    {
        Receiver->setWindowTitle(QApplication::translate("Receiver", "Receiver", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Receiver", "\347\255\211\345\276\205\346\216\245\346\224\266\346\225\260\346\215\256\357\274\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Receiver: public Ui_Receiver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVER_H
