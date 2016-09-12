/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created: Mon Sep 12 10:07:27 2016
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QPushButton *RegisterButton;
    QPushButton *LoginButton;
    QLabel *StatusLabel;
    QLineEdit *UsernameLineEdit;
    QLineEdit *PasswordLineEdit;
    QListWidget *listWidget;
    QFrame *frame;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(500, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginDialog->sizePolicy().hasHeightForWidth());
        LoginDialog->setSizePolicy(sizePolicy);
        LoginDialog->setMinimumSize(QSize(500, 400));
        LoginDialog->setMaximumSize(QSize(500, 400));
        LoginDialog->setStyleSheet(QString::fromUtf8("QDialog{\n"
"	\n"
"	\n"
"	\n"
"	background-color: rgb(238, 238, 238);\n"
"	\n"
"}"));
        RegisterButton = new QPushButton(LoginDialog);
        RegisterButton->setObjectName(QString::fromUtf8("RegisterButton"));
        RegisterButton->setGeometry(QRect(310, 340, 91, 30));
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
"}"));
        LoginButton = new QPushButton(LoginDialog);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));
        LoginButton->setEnabled(true);
        LoginButton->setGeometry(QRect(120, 340, 91, 30));
        sizePolicy.setHeightForWidth(LoginButton->sizePolicy().hasHeightForWidth());
        LoginButton->setSizePolicy(sizePolicy);
        LoginButton->setStyleSheet(QString::fromUtf8("QPushButton{border-radius:10px;\n"
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
        StatusLabel = new QLabel(LoginDialog);
        StatusLabel->setObjectName(QString::fromUtf8("StatusLabel"));
        StatusLabel->setGeometry(QRect(210, 230, 161, 31));
        StatusLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	rgb(7, 7, 7)\n"
"border-radius:10px;\n"
"font: 9pt \"Consolas\";\n"
"}"));
        UsernameLineEdit = new QLineEdit(LoginDialog);
        UsernameLineEdit->setObjectName(QString::fromUtf8("UsernameLineEdit"));
        UsernameLineEdit->setGeometry(QRect(70, 270, 171, 21));
        sizePolicy.setHeightForWidth(UsernameLineEdit->sizePolicy().hasHeightForWidth());
        UsernameLineEdit->setSizePolicy(sizePolicy);
        UsernameLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"font: 9pt \"Consolas\";"));
        PasswordLineEdit = new QLineEdit(LoginDialog);
        PasswordLineEdit->setObjectName(QString::fromUtf8("PasswordLineEdit"));
        PasswordLineEdit->setGeometry(QRect(280, 270, 171, 21));
        sizePolicy.setHeightForWidth(PasswordLineEdit->sizePolicy().hasHeightForWidth());
        PasswordLineEdit->setSizePolicy(sizePolicy);
        PasswordLineEdit->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"font: 9pt \"Consolas\";"));
        PasswordLineEdit->setEchoMode(QLineEdit::Password);
        listWidget = new QListWidget(LoginDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 30, 501, 200));
        listWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/new/icon/images/FqUdUKG3OWBOdEHBVrM4HQ9VqiBc.jpg);"));
        frame = new QFrame(LoginDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 501, 31));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 0, 30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icon/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(440, 0, 31, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icon/images/minmin.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 72, 16));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        RegisterButton->setText(QApplication::translate("LoginDialog", "Register", 0, QApplication::UnicodeUTF8));
        LoginButton->setText(QApplication::translate("LoginDialog", "Login", 0, QApplication::UnicodeUTF8));
        StatusLabel->setText(QApplication::translate("LoginDialog", "Waiting..", 0, QApplication::UnicodeUTF8));
        UsernameLineEdit->setPlaceholderText(QApplication::translate("LoginDialog", "User Name", 0, QApplication::UnicodeUTF8));
        PasswordLineEdit->setPlaceholderText(QApplication::translate("LoginDialog", "Passcode", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label->setText(QApplication::translate("LoginDialog", "Chat", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
