/********************************************************************************
** Form generated from reading UI file 'sender.ui'
**
** Created: Sat Aug 27 11:13:44 2016
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDER_H
#define UI_SENDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Sender
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *Sender)
    {
        if (Sender->objectName().isEmpty())
            Sender->setObjectName(QString::fromUtf8("Sender"));
        Sender->resize(400, 300);
        pushButton = new QPushButton(Sender);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 170, 75, 23));
        label = new QLabel(Sender);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 140, 54, 12));

        retranslateUi(Sender);

        QMetaObject::connectSlotsByName(Sender);
    } // setupUi

    void retranslateUi(QDialog *Sender)
    {
        Sender->setWindowTitle(QApplication::translate("Sender", "Sender", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Sender", "PushButton", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Sender", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Sender: public Ui_Sender {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDER_H
