/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created: Mon Sep 12 19:10:40 2016
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QLineEdit *UsernameLineEdit;
    QLabel *NicknameLabel;
    QLineEdit *NicknameLineEdit;
    QLabel *PasswordLabel;
    QLineEdit *PasswordLineEdit;
    QLabel *PasswordCheckLabel;
    QLineEdit *PasswordCheckLineEdit;
    QLabel *UsernameLabel;
    QLabel *StatusLabel;
    QPushButton *RegisterButton;
    QPushButton *BackButton;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QString::fromUtf8("RegisterDialog"));
        RegisterDialog->resize(312, 237);
        RegisterDialog->setStyleSheet(QString::fromUtf8("QDialog{\n"
"	\n"
"	\n"
"	background-image: url(:/new/icon/images/26.jpg);\n"
"}"));
        UsernameLineEdit = new QLineEdit(RegisterDialog);
        UsernameLineEdit->setObjectName(QString::fromUtf8("UsernameLineEdit"));
        UsernameLineEdit->setGeometry(QRect(120, 50, 144, 21));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UsernameLineEdit->sizePolicy().hasHeightForWidth());
        UsernameLineEdit->setSizePolicy(sizePolicy);
        NicknameLabel = new QLabel(RegisterDialog);
        NicknameLabel->setObjectName(QString::fromUtf8("NicknameLabel"));
        NicknameLabel->setGeometry(QRect(50, 80, 30, 16));
        NicknameLineEdit = new QLineEdit(RegisterDialog);
        NicknameLineEdit->setObjectName(QString::fromUtf8("NicknameLineEdit"));
        NicknameLineEdit->setGeometry(QRect(120, 80, 144, 21));
        sizePolicy.setHeightForWidth(NicknameLineEdit->sizePolicy().hasHeightForWidth());
        NicknameLineEdit->setSizePolicy(sizePolicy);
        PasswordLabel = new QLabel(RegisterDialog);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));
        PasswordLabel->setGeometry(QRect(50, 110, 30, 16));
        PasswordLineEdit = new QLineEdit(RegisterDialog);
        PasswordLineEdit->setObjectName(QString::fromUtf8("PasswordLineEdit"));
        PasswordLineEdit->setGeometry(QRect(120, 110, 144, 21));
        sizePolicy.setHeightForWidth(PasswordLineEdit->sizePolicy().hasHeightForWidth());
        PasswordLineEdit->setSizePolicy(sizePolicy);
        PasswordLineEdit->setEchoMode(QLineEdit::Password);
        PasswordCheckLabel = new QLabel(RegisterDialog);
        PasswordCheckLabel->setObjectName(QString::fromUtf8("PasswordCheckLabel"));
        PasswordCheckLabel->setGeometry(QRect(40, 140, 60, 16));
        PasswordCheckLineEdit = new QLineEdit(RegisterDialog);
        PasswordCheckLineEdit->setObjectName(QString::fromUtf8("PasswordCheckLineEdit"));
        PasswordCheckLineEdit->setGeometry(QRect(120, 140, 144, 21));
        sizePolicy.setHeightForWidth(PasswordCheckLineEdit->sizePolicy().hasHeightForWidth());
        PasswordCheckLineEdit->setSizePolicy(sizePolicy);
        PasswordCheckLineEdit->setEchoMode(QLineEdit::Password);
        UsernameLabel = new QLabel(RegisterDialog);
        UsernameLabel->setObjectName(QString::fromUtf8("UsernameLabel"));
        UsernameLabel->setGeometry(QRect(40, 50, 45, 16));
        StatusLabel = new QLabel(RegisterDialog);
        StatusLabel->setObjectName(QString::fromUtf8("StatusLabel"));
        StatusLabel->setGeometry(QRect(10, 20, 105, 16));
        RegisterButton = new QPushButton(RegisterDialog);
        RegisterButton->setObjectName(QString::fromUtf8("RegisterButton"));
        RegisterButton->setGeometry(QRect(60, 190, 81, 31));
        sizePolicy.setHeightForWidth(RegisterButton->sizePolicy().hasHeightForWidth());
        RegisterButton->setSizePolicy(sizePolicy);
        RegisterButton->setStyleSheet(QString::fromUtf8("QPushButton{border-radius:10px;\n"
"font: 9pt \"Consolas\";\n"
"	background-color: rgb(170, 170, 255);\n"
"}\n"
"QPushButton:hover{\n"
"background-color:rgba(100,255,100,100);\n"
"border-color:rgba(255,225,255,200);\n"
"color:rgba(0,0,0,200);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color:rgba(100,255,100,200);\n"
"border-color:rgba(255,225,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"}\n"
""));
        BackButton = new QPushButton(RegisterDialog);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setGeometry(QRect(170, 190, 81, 31));
        sizePolicy.setHeightForWidth(BackButton->sizePolicy().hasHeightForWidth());
        BackButton->setSizePolicy(sizePolicy);
        BackButton->setStyleSheet(QString::fromUtf8("QPushButton{border-radius:10px;\n"
"font: 9pt \"Consolas\";\n"
"	background-color: rgb(170, 170, 255);\n"
"}\n"
"QPushButton:hover{\n"
"background-color:rgba(100,255,100,100);\n"
"border-color:rgba(255,225,255,200);\n"
"color:rgba(0,0,0,200);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color:rgba(100,255,100,200);\n"
"border-color:rgba(255,225,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"}\n"
""));

        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        NicknameLabel->setText(QApplication::translate("RegisterDialog", "\346\230\265\347\247\260", 0, QApplication::UnicodeUTF8));
        PasswordLabel->setText(QApplication::translate("RegisterDialog", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        PasswordCheckLabel->setText(QApplication::translate("RegisterDialog", "\345\257\206\347\240\201\351\252\214\350\257\201", 0, QApplication::UnicodeUTF8));
        UsernameLabel->setText(QApplication::translate("RegisterDialog", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        StatusLabel->setText(QApplication::translate("RegisterDialog", "\350\257\267\345\241\253\345\206\231\346\263\250\345\206\214\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        RegisterButton->setText(QApplication::translate("RegisterDialog", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        BackButton->setText(QApplication::translate("RegisterDialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
