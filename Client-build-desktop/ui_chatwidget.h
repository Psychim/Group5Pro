/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created: Mon Sep 12 20:09:56 2016
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextBrowser *messageBrowser;
    QTableWidget *userTableWidget;
    QFontComboBox *fontComboBox;
    QComboBox *sizeComboBox;
    QToolButton *boldToolBtn;
    QToolButton *italicToolBtn;
    QToolButton *underlineToolBtn;
    QToolButton *colorToolBtn;
    QToolButton *sendToolBtn;
    QToolButton *saveToolBtn;
    QToolButton *clearToolBtn;
    QTextEdit *messageTextEdit;
    QLabel *userNumberLabel;
    QPushButton *sendButton;
    QPushButton *exitButton;

    void setupUi(QWidget *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName(QString::fromUtf8("ChatWidget"));
        ChatWidget->resize(929, 500);
        gridLayout = new QGridLayout(ChatWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(ChatWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(929, 40));
        frame->setMaximumSize(QSize(929, 40));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 111, 16));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(850, 0, 40, 40));
        pushButton->setMinimumSize(QSize(40, 40));
        pushButton->setMaximumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icon/images/minmin.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(890, 0, 40, 40));
        pushButton_2->setMinimumSize(QSize(40, 40));
        pushButton_2->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icon/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);

        gridLayout->addWidget(frame, 0, 0, 1, 11);

        messageBrowser = new QTextBrowser(ChatWidget);
        messageBrowser->setObjectName(QString::fromUtf8("messageBrowser"));

        gridLayout->addWidget(messageBrowser, 1, 0, 1, 9);

        userTableWidget = new QTableWidget(ChatWidget);
        if (userTableWidget->columnCount() < 2)
            userTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        userTableWidget->setObjectName(QString::fromUtf8("userTableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(userTableWidget->sizePolicy().hasHeightForWidth());
        userTableWidget->setSizePolicy(sizePolicy);
        userTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        userTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        userTableWidget->setShowGrid(false);

        gridLayout->addWidget(userTableWidget, 1, 9, 3, 2);

        fontComboBox = new QFontComboBox(ChatWidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        gridLayout->addWidget(fontComboBox, 2, 0, 1, 1);

        sizeComboBox = new QComboBox(ChatWidget);
        sizeComboBox->setObjectName(QString::fromUtf8("sizeComboBox"));

        gridLayout->addWidget(sizeComboBox, 2, 1, 1, 1);

        boldToolBtn = new QToolButton(ChatWidget);
        boldToolBtn->setObjectName(QString::fromUtf8("boldToolBtn"));
        boldToolBtn->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icon/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldToolBtn->setIcon(icon2);
        boldToolBtn->setIconSize(QSize(22, 22));
        boldToolBtn->setCheckable(true);
        boldToolBtn->setAutoRaise(true);

        gridLayout->addWidget(boldToolBtn, 2, 2, 1, 1);

        italicToolBtn = new QToolButton(ChatWidget);
        italicToolBtn->setObjectName(QString::fromUtf8("italicToolBtn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/icon/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicToolBtn->setIcon(icon3);
        italicToolBtn->setIconSize(QSize(22, 22));
        italicToolBtn->setCheckable(true);
        italicToolBtn->setAutoRaise(true);

        gridLayout->addWidget(italicToolBtn, 2, 3, 1, 1);

        underlineToolBtn = new QToolButton(ChatWidget);
        underlineToolBtn->setObjectName(QString::fromUtf8("underlineToolBtn"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/icon/images/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlineToolBtn->setIcon(icon4);
        underlineToolBtn->setIconSize(QSize(22, 22));
        underlineToolBtn->setCheckable(true);
        underlineToolBtn->setAutoRaise(true);

        gridLayout->addWidget(underlineToolBtn, 2, 4, 1, 1);

        colorToolBtn = new QToolButton(ChatWidget);
        colorToolBtn->setObjectName(QString::fromUtf8("colorToolBtn"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/icon/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorToolBtn->setIcon(icon5);
        colorToolBtn->setIconSize(QSize(22, 22));
        colorToolBtn->setAutoRaise(true);

        gridLayout->addWidget(colorToolBtn, 2, 5, 1, 1);

        sendToolBtn = new QToolButton(ChatWidget);
        sendToolBtn->setObjectName(QString::fromUtf8("sendToolBtn"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/icon/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendToolBtn->setIcon(icon6);
        sendToolBtn->setIconSize(QSize(22, 22));
        sendToolBtn->setAutoRaise(true);

        gridLayout->addWidget(sendToolBtn, 2, 6, 1, 1);

        saveToolBtn = new QToolButton(ChatWidget);
        saveToolBtn->setObjectName(QString::fromUtf8("saveToolBtn"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/icon/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveToolBtn->setIcon(icon7);
        saveToolBtn->setIconSize(QSize(22, 22));
        saveToolBtn->setAutoRaise(true);

        gridLayout->addWidget(saveToolBtn, 2, 7, 1, 1);

        clearToolBtn = new QToolButton(ChatWidget);
        clearToolBtn->setObjectName(QString::fromUtf8("clearToolBtn"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/icon/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearToolBtn->setIcon(icon8);
        clearToolBtn->setIconSize(QSize(22, 22));
        clearToolBtn->setAutoRaise(true);

        gridLayout->addWidget(clearToolBtn, 2, 8, 1, 1);

        messageTextEdit = new QTextEdit(ChatWidget);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));

        gridLayout->addWidget(messageTextEdit, 3, 0, 1, 9);

        userNumberLabel = new QLabel(ChatWidget);
        userNumberLabel->setObjectName(QString::fromUtf8("userNumberLabel"));

        gridLayout->addWidget(userNumberLabel, 4, 6, 1, 3);

        sendButton = new QPushButton(ChatWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(sendButton, 4, 9, 1, 1);

        exitButton = new QPushButton(ChatWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(exitButton, 4, 10, 1, 1);

        QWidget::setTabOrder(userTableWidget, fontComboBox);
        QWidget::setTabOrder(fontComboBox, sizeComboBox);
        QWidget::setTabOrder(sizeComboBox, messageBrowser);
        QWidget::setTabOrder(messageBrowser, boldToolBtn);
        QWidget::setTabOrder(boldToolBtn, italicToolBtn);
        QWidget::setTabOrder(italicToolBtn, underlineToolBtn);
        QWidget::setTabOrder(underlineToolBtn, colorToolBtn);
        QWidget::setTabOrder(colorToolBtn, sendToolBtn);
        QWidget::setTabOrder(sendToolBtn, saveToolBtn);
        QWidget::setTabOrder(saveToolBtn, clearToolBtn);
        QWidget::setTabOrder(clearToolBtn, messageTextEdit);

        retranslateUi(ChatWidget);

        sizeComboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatWidget)
    {
        ChatWidget->setWindowTitle(QApplication::translate("ChatWidget", "\345\261\200\345\237\237\347\275\221\350\201\212\345\244\251\345\267\245\345\205\267", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ChatWidget", "Chat Room", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = userTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ChatWidget", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = userTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ChatWidget", "\346\230\265\347\247\260", 0, QApplication::UnicodeUTF8));
        sizeComboBox->clear();
        sizeComboBox->insertItems(0, QStringList()
         << QApplication::translate("ChatWidget", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ChatWidget", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ChatWidget", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ChatWidget", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ChatWidget", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ChatWidget", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ChatWidget", "15", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        boldToolBtn->setToolTip(QApplication::translate("ChatWidget", "\345\212\240\347\262\227", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        boldToolBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        italicToolBtn->setToolTip(QApplication::translate("ChatWidget", "\345\200\276\346\226\234", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        italicToolBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        underlineToolBtn->setToolTip(QApplication::translate("ChatWidget", "\344\270\213\345\210\222\347\272\277", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        underlineToolBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        colorToolBtn->setToolTip(QApplication::translate("ChatWidget", "\346\233\264\346\224\271\345\255\227\344\275\223\351\242\234\350\211\262", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        colorToolBtn->setText(QApplication::translate("ChatWidget", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        sendToolBtn->setToolTip(QApplication::translate("ChatWidget", "\344\274\240\350\276\223\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        sendToolBtn->setText(QApplication::translate("ChatWidget", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveToolBtn->setToolTip(QApplication::translate("ChatWidget", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveToolBtn->setText(QApplication::translate("ChatWidget", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        clearToolBtn->setToolTip(QApplication::translate("ChatWidget", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        clearToolBtn->setText(QApplication::translate("ChatWidget", "...", 0, QApplication::UnicodeUTF8));
        userNumberLabel->setText(QApplication::translate("ChatWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        sendButton->setText(QApplication::translate("ChatWidget", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("ChatWidget", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
