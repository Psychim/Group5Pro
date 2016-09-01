/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created: Thu Sep 1 22:05:35 2016
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
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *UsernameLabel;
    QLineEdit *UsernameLineEdit;
    QFormLayout *formLayout_2;
    QLabel *PasswordLabel;
    QLineEdit *PasswordLineEdit;
    QLabel *StatusLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *LoginButton;
    QPushButton *RegisterButton;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(300, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginDialog->sizePolicy().hasHeightForWidth());
        LoginDialog->setSizePolicy(sizePolicy);
        LoginDialog->setMinimumSize(QSize(300, 200));
        LoginDialog->setMaximumSize(QSize(300, 200));
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(50, -1, 50, -1);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignCenter);
        UsernameLabel = new QLabel(LoginDialog);
        UsernameLabel->setObjectName(QString::fromUtf8("UsernameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, UsernameLabel);

        UsernameLineEdit = new QLineEdit(LoginDialog);
        UsernameLineEdit->setObjectName(QString::fromUtf8("UsernameLineEdit"));
        sizePolicy.setHeightForWidth(UsernameLineEdit->sizePolicy().hasHeightForWidth());
        UsernameLineEdit->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, UsernameLineEdit);


        verticalLayout->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignCenter);
        formLayout_2->setFormAlignment(Qt::AlignCenter);
        PasswordLabel = new QLabel(LoginDialog);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, PasswordLabel);

        PasswordLineEdit = new QLineEdit(LoginDialog);
        PasswordLineEdit->setObjectName(QString::fromUtf8("PasswordLineEdit"));
        sizePolicy.setHeightForWidth(PasswordLineEdit->sizePolicy().hasHeightForWidth());
        PasswordLineEdit->setSizePolicy(sizePolicy);
        PasswordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, PasswordLineEdit);


        verticalLayout->addLayout(formLayout_2);

        StatusLabel = new QLabel(LoginDialog);
        StatusLabel->setObjectName(QString::fromUtf8("StatusLabel"));

        verticalLayout->addWidget(StatusLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LoginButton = new QPushButton(LoginDialog);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));
        LoginButton->setEnabled(false);
        sizePolicy.setHeightForWidth(LoginButton->sizePolicy().hasHeightForWidth());
        LoginButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(LoginButton);

        RegisterButton = new QPushButton(LoginDialog);
        RegisterButton->setObjectName(QString::fromUtf8("RegisterButton"));
        sizePolicy.setHeightForWidth(RegisterButton->sizePolicy().hasHeightForWidth());
        RegisterButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(RegisterButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        UsernameLabel->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        PasswordLabel->setText(QApplication::translate("LoginDialog", "\345\257\206  \347\240\201", 0, QApplication::UnicodeUTF8));
        StatusLabel->setText(QApplication::translate("LoginDialog", "\346\255\243\345\234\250\345\210\235\345\247\213\345\214\226...", 0, QApplication::UnicodeUTF8));
        LoginButton->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        RegisterButton->setText(QApplication::translate("LoginDialog", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
