/********************************************************************************
** Form generated from reading UI file 'widget_p2p.ui'
**
** Created: Mon Sep 12 20:11:45 2016
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_P2P_H
#define UI_WIDGET_P2P_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "videolabel.h"

QT_BEGIN_NAMESPACE

class Ui_Widget_p2p
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QFontComboBox *fontComboBox;
    QComboBox *sizeComboBox;
    QToolButton *boldToolBtn;
    QToolButton *italicToolBtn;
    QToolButton *underlineToolBtn;
    QToolButton *colorToolBtn;
    QToolButton *sendToolBtn;
    QToolButton *saveToolBtn;
    QToolButton *clearToolBtn;
    QSpacerItem *horizontalSpacer;
    QTextEdit *messageTextEdit;
    VideoLabel *MyVideo;
    QPushButton *sendButton;
    QPushButton *exitButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *messageBrowser;
    QFormLayout *formLayout;
    QLabel *id;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QLabel *nickname;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    VideoLabel *PartnerVideo;
    QFrame *frame;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *OpenVideoButton;

    void setupUi(QWidget *Widget_p2p)
    {
        if (Widget_p2p->objectName().isEmpty())
            Widget_p2p->setObjectName(QString::fromUtf8("Widget_p2p"));
        Widget_p2p->resize(664, 500);
        Widget_p2p->setMinimumSize(QSize(650, 500));
        Widget_p2p->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(Widget_p2p);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(10, 0, 10, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        fontComboBox = new QFontComboBox(Widget_p2p);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fontComboBox->sizePolicy().hasHeightForWidth());
        fontComboBox->setSizePolicy(sizePolicy);
        fontComboBox->setEditable(false);

        horizontalLayout_2->addWidget(fontComboBox);

        sizeComboBox = new QComboBox(Widget_p2p);
        sizeComboBox->setObjectName(QString::fromUtf8("sizeComboBox"));
        sizePolicy.setHeightForWidth(sizeComboBox->sizePolicy().hasHeightForWidth());
        sizeComboBox->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(sizeComboBox);

        boldToolBtn = new QToolButton(Widget_p2p);
        boldToolBtn->setObjectName(QString::fromUtf8("boldToolBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icon/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldToolBtn->setIcon(icon);
        boldToolBtn->setIconSize(QSize(22, 22));
        boldToolBtn->setCheckable(true);
        boldToolBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(boldToolBtn);

        italicToolBtn = new QToolButton(Widget_p2p);
        italicToolBtn->setObjectName(QString::fromUtf8("italicToolBtn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icon/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicToolBtn->setIcon(icon1);
        italicToolBtn->setIconSize(QSize(22, 22));
        italicToolBtn->setCheckable(true);
        italicToolBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(italicToolBtn);

        underlineToolBtn = new QToolButton(Widget_p2p);
        underlineToolBtn->setObjectName(QString::fromUtf8("underlineToolBtn"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icon/images/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlineToolBtn->setIcon(icon2);
        underlineToolBtn->setIconSize(QSize(22, 22));
        underlineToolBtn->setCheckable(true);
        underlineToolBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(underlineToolBtn);

        colorToolBtn = new QToolButton(Widget_p2p);
        colorToolBtn->setObjectName(QString::fromUtf8("colorToolBtn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/icon/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorToolBtn->setIcon(icon3);
        colorToolBtn->setIconSize(QSize(22, 22));
        colorToolBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(colorToolBtn);

        sendToolBtn = new QToolButton(Widget_p2p);
        sendToolBtn->setObjectName(QString::fromUtf8("sendToolBtn"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/icon/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendToolBtn->setIcon(icon4);
        sendToolBtn->setIconSize(QSize(22, 22));
        sendToolBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(sendToolBtn);

        saveToolBtn = new QToolButton(Widget_p2p);
        saveToolBtn->setObjectName(QString::fromUtf8("saveToolBtn"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/icon/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveToolBtn->setIcon(icon5);
        saveToolBtn->setIconSize(QSize(22, 22));
        saveToolBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(saveToolBtn);

        clearToolBtn = new QToolButton(Widget_p2p);
        clearToolBtn->setObjectName(QString::fromUtf8("clearToolBtn"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/icon/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearToolBtn->setIcon(icon6);
        clearToolBtn->setIconSize(QSize(22, 22));
        clearToolBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(clearToolBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 3);

        messageTextEdit = new QTextEdit(Widget_p2p);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(messageTextEdit->sizePolicy().hasHeightForWidth());
        messageTextEdit->setSizePolicy(sizePolicy1);
        messageTextEdit->setMinimumSize(QSize(0, 150));
        messageTextEdit->setMaximumSize(QSize(16777215, 150));
        messageTextEdit->setAutoFormatting(QTextEdit::AutoNone);
        messageTextEdit->setUndoRedoEnabled(false);
        messageTextEdit->setLineWrapMode(QTextEdit::WidgetWidth);

        gridLayout->addWidget(messageTextEdit, 4, 0, 1, 2);

        MyVideo = new VideoLabel(Widget_p2p);
        MyVideo->setObjectName(QString::fromUtf8("MyVideo"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(MyVideo->sizePolicy().hasHeightForWidth());
        MyVideo->setSizePolicy(sizePolicy2);
        MyVideo->setMinimumSize(QSize(64, 48));
        MyVideo->setMaximumSize(QSize(64, 48));

        gridLayout->addWidget(MyVideo, 4, 2, 1, 1);

        sendButton = new QPushButton(Widget_p2p);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sizePolicy.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy);
        sendButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(sendButton, 5, 1, 1, 1);

        exitButton = new QPushButton(Widget_p2p);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        sizePolicy.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy);
        exitButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(exitButton, 5, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(447, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        messageBrowser = new QTextBrowser(Widget_p2p);
        messageBrowser->setObjectName(QString::fromUtf8("messageBrowser"));
        sizePolicy1.setHeightForWidth(messageBrowser->sizePolicy().hasHeightForWidth());
        messageBrowser->setSizePolicy(sizePolicy1);
        messageBrowser->setMinimumSize(QSize(0, 180));
        messageBrowser->setMaximumSize(QSize(16777215, 180));

        horizontalLayout->addWidget(messageBrowser);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        id = new QLabel(Widget_p2p);
        id->setObjectName(QString::fromUtf8("id"));

        formLayout->setWidget(1, QFormLayout::FieldRole, id);

        verticalSpacer = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::LabelRole, verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::FieldRole, verticalSpacer_2);

        label_2 = new QLabel(Widget_p2p);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        nickname = new QLabel(Widget_p2p);
        nickname->setObjectName(QString::fromUtf8("nickname"));

        formLayout->setWidget(3, QFormLayout::FieldRole, nickname);

        label = new QLabel(Widget_p2p);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::LabelRole, verticalSpacer_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::FieldRole, verticalSpacer_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::LabelRole, verticalSpacer_5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::FieldRole, verticalSpacer_6);


        horizontalLayout->addLayout(formLayout);

        PartnerVideo = new VideoLabel(Widget_p2p);
        PartnerVideo->setObjectName(QString::fromUtf8("PartnerVideo"));
        PartnerVideo->setMinimumSize(QSize(160, 120));
        PartnerVideo->setMaximumSize(QSize(640, 480));

        horizontalLayout->addWidget(PartnerVideo);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 3);

        frame = new QFrame(Widget_p2p);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(650, 31));
        frame->setMaximumSize(QSize(650, 31));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 10, 91, 16));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(590, 0, 30, 30));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/icon/images/minmin.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon7);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(620, 0, 30, 30));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/icon/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon8);

        gridLayout->addWidget(frame, 0, 0, 1, 3);

        OpenVideoButton = new QPushButton(Widget_p2p);
        OpenVideoButton->setObjectName(QString::fromUtf8("OpenVideoButton"));
        sizePolicy.setHeightForWidth(OpenVideoButton->sizePolicy().hasHeightForWidth());
        OpenVideoButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(OpenVideoButton, 1, 0, 1, 1);

        messageTextEdit->raise();
        MyVideo->raise();
        sendButton->raise();
        exitButton->raise();
        frame->raise();
        OpenVideoButton->raise();

        retranslateUi(Widget_p2p);

        sizeComboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget_p2p);
    } // setupUi

    void retranslateUi(QWidget *Widget_p2p)
    {
        Widget_p2p->setWindowTitle(QApplication::translate("Widget_p2p", "\350\201\212\345\244\251\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
        sizeComboBox->clear();
        sizeComboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget_p2p", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_p2p", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_p2p", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_p2p", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_p2p", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_p2p", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_p2p", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_p2p", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_p2p", "17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_p2p", "18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_p2p", "19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_p2p", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_p2p", "21", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_p2p", "22", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        boldToolBtn->setToolTip(QApplication::translate("Widget_p2p", "\345\212\240\347\262\227", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        boldToolBtn->setText(QApplication::translate("Widget_p2p", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        italicToolBtn->setToolTip(QApplication::translate("Widget_p2p", "\345\200\276\346\226\234", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        italicToolBtn->setText(QApplication::translate("Widget_p2p", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        underlineToolBtn->setToolTip(QApplication::translate("Widget_p2p", "\344\270\213\345\210\222\347\272\277", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        underlineToolBtn->setText(QApplication::translate("Widget_p2p", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        colorToolBtn->setToolTip(QApplication::translate("Widget_p2p", "\346\233\264\346\224\271\345\255\227\344\275\223\351\242\234\350\211\262", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        colorToolBtn->setText(QApplication::translate("Widget_p2p", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        sendToolBtn->setToolTip(QApplication::translate("Widget_p2p", "\344\274\240\350\276\223\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        sendToolBtn->setText(QApplication::translate("Widget_p2p", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveToolBtn->setToolTip(QApplication::translate("Widget_p2p", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveToolBtn->setText(QApplication::translate("Widget_p2p", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        clearToolBtn->setToolTip(QApplication::translate("Widget_p2p", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        clearToolBtn->setText(QApplication::translate("Widget_p2p", "...", 0, QApplication::UnicodeUTF8));
        MyVideo->setText(QApplication::translate("Widget_p2p", "MyVideo here", 0, QApplication::UnicodeUTF8));
        sendButton->setText(QApplication::translate("Widget_p2p", "\345\217\221\351\200\201(&S)", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("Widget_p2p", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        id->setText(QApplication::translate("Widget_p2p", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget_p2p", "\345\257\271\346\226\271\346\230\265\347\247\260:", 0, QApplication::UnicodeUTF8));
        nickname->setText(QApplication::translate("Widget_p2p", "TextLabel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget_p2p", "\345\257\271\346\226\271ID:", 0, QApplication::UnicodeUTF8));
        PartnerVideo->setText(QApplication::translate("Widget_p2p", "PartnerVideo here", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget_p2p", "Easy Chat", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        OpenVideoButton->setText(QApplication::translate("Widget_p2p", "\350\247\206\351\242\221\345\257\271\350\257\235", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget_p2p: public Ui_Widget_p2p {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_P2P_H
