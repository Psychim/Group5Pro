/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created: Thu Sep 1 22:05:35 2016
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
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QFormLayout *formLayout;
    QLineEdit *UsernameLineEdit;
    QLabel *NicknameLabel;
    QLineEdit *NicknameLineEdit;
    QLabel *PasswordLabel;
    QLineEdit *PasswordLineEdit;
    QLabel *PasswordCheckLabel;
    QLineEdit *PasswordCheckLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *RegisterButton;
    QPushButton *BackButton;
    QLabel *UsernameLabel;
    QLabel *StatusLabel;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QString::fromUtf8("RegisterDialog"));
        RegisterDialog->resize(182, 173);
        formLayout = new QFormLayout(RegisterDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        UsernameLineEdit = new QLineEdit(RegisterDialog);
        UsernameLineEdit->setObjectName(QString::fromUtf8("UsernameLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UsernameLineEdit->sizePolicy().hasHeightForWidth());
        UsernameLineEdit->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, UsernameLineEdit);

        NicknameLabel = new QLabel(RegisterDialog);
        NicknameLabel->setObjectName(QString::fromUtf8("NicknameLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, NicknameLabel);

        NicknameLineEdit = new QLineEdit(RegisterDialog);
        NicknameLineEdit->setObjectName(QString::fromUtf8("NicknameLineEdit"));
        sizePolicy.setHeightForWidth(NicknameLineEdit->sizePolicy().hasHeightForWidth());
        NicknameLineEdit->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::FieldRole, NicknameLineEdit);

        PasswordLabel = new QLabel(RegisterDialog);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, PasswordLabel);

        PasswordLineEdit = new QLineEdit(RegisterDialog);
        PasswordLineEdit->setObjectName(QString::fromUtf8("PasswordLineEdit"));
        sizePolicy.setHeightForWidth(PasswordLineEdit->sizePolicy().hasHeightForWidth());
        PasswordLineEdit->setSizePolicy(sizePolicy);
        PasswordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, PasswordLineEdit);

        PasswordCheckLabel = new QLabel(RegisterDialog);
        PasswordCheckLabel->setObjectName(QString::fromUtf8("PasswordCheckLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, PasswordCheckLabel);

        PasswordCheckLineEdit = new QLineEdit(RegisterDialog);
        PasswordCheckLineEdit->setObjectName(QString::fromUtf8("PasswordCheckLineEdit"));
        sizePolicy.setHeightForWidth(PasswordCheckLineEdit->sizePolicy().hasHeightForWidth());
        PasswordCheckLineEdit->setSizePolicy(sizePolicy);
        PasswordCheckLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(4, QFormLayout::FieldRole, PasswordCheckLineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        RegisterButton = new QPushButton(RegisterDialog);
        RegisterButton->setObjectName(QString::fromUtf8("RegisterButton"));
        sizePolicy.setHeightForWidth(RegisterButton->sizePolicy().hasHeightForWidth());
        RegisterButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(RegisterButton);

        BackButton = new QPushButton(RegisterDialog);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        sizePolicy.setHeightForWidth(BackButton->sizePolicy().hasHeightForWidth());
        BackButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(BackButton);


        formLayout->setLayout(6, QFormLayout::SpanningRole, horizontalLayout_2);

        UsernameLabel = new QLabel(RegisterDialog);
        UsernameLabel->setObjectName(QString::fromUtf8("UsernameLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, UsernameLabel);

        StatusLabel = new QLabel(RegisterDialog);
        StatusLabel->setObjectName(QString::fromUtf8("StatusLabel"));

        formLayout->setWidget(5, QFormLayout::SpanningRole, StatusLabel);


        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        NicknameLabel->setText(QApplication::translate("RegisterDialog", "\346\230\265\347\247\260", 0, QApplication::UnicodeUTF8));
        PasswordLabel->setText(QApplication::translate("RegisterDialog", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        PasswordCheckLabel->setText(QApplication::translate("RegisterDialog", "\345\257\206\347\240\201\351\252\214\350\257\201", 0, QApplication::UnicodeUTF8));
        RegisterButton->setText(QApplication::translate("RegisterDialog", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        BackButton->setText(QApplication::translate("RegisterDialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        UsernameLabel->setText(QApplication::translate("RegisterDialog", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        StatusLabel->setText(QApplication::translate("RegisterDialog", "\350\257\267\345\241\253\345\206\231\346\263\250\345\206\214\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
