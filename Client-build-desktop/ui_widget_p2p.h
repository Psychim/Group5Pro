/********************************************************************************
** Form generated from reading UI file 'widget_p2p.ui'
**
** Created: Fri Sep 2 10:10:09 2016
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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_p2p
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *messageBrowser;
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
    QPushButton *sendButton;
    QPushButton *exitButton;
    QLabel *id;
    QLabel *label;
    QLabel *nickname;
    QLabel *label_2;

    void setupUi(QWidget *Widget_p2p)
    {
        if (Widget_p2p->objectName().isEmpty())
            Widget_p2p->setObjectName(QString::fromUtf8("Widget_p2p"));
        Widget_p2p->resize(600, 450);
        gridLayout = new QGridLayout(Widget_p2p);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        messageBrowser = new QTextBrowser(Widget_p2p);
        messageBrowser->setObjectName(QString::fromUtf8("messageBrowser"));

        gridLayout->addWidget(messageBrowser, 0, 0, 2, 9);

        fontComboBox = new QFontComboBox(Widget_p2p);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        gridLayout->addWidget(fontComboBox, 2, 0, 1, 1);

        sizeComboBox = new QComboBox(Widget_p2p);
        sizeComboBox->setObjectName(QString::fromUtf8("sizeComboBox"));

        gridLayout->addWidget(sizeComboBox, 2, 1, 1, 1);

        boldToolBtn = new QToolButton(Widget_p2p);
        boldToolBtn->setObjectName(QString::fromUtf8("boldToolBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icon/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldToolBtn->setIcon(icon);
        boldToolBtn->setIconSize(QSize(22, 22));
        boldToolBtn->setCheckable(true);
        boldToolBtn->setAutoRaise(true);

        gridLayout->addWidget(boldToolBtn, 2, 2, 1, 1);

        italicToolBtn = new QToolButton(Widget_p2p);
        italicToolBtn->setObjectName(QString::fromUtf8("italicToolBtn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icon/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicToolBtn->setIcon(icon1);
        italicToolBtn->setIconSize(QSize(22, 22));
        italicToolBtn->setCheckable(true);
        italicToolBtn->setAutoRaise(true);

        gridLayout->addWidget(italicToolBtn, 2, 3, 1, 1);

        underlineToolBtn = new QToolButton(Widget_p2p);
        underlineToolBtn->setObjectName(QString::fromUtf8("underlineToolBtn"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icon/images/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlineToolBtn->setIcon(icon2);
        underlineToolBtn->setIconSize(QSize(22, 22));
        underlineToolBtn->setCheckable(true);
        underlineToolBtn->setAutoRaise(true);

        gridLayout->addWidget(underlineToolBtn, 2, 4, 1, 1);

        colorToolBtn = new QToolButton(Widget_p2p);
        colorToolBtn->setObjectName(QString::fromUtf8("colorToolBtn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/icon/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorToolBtn->setIcon(icon3);
        colorToolBtn->setIconSize(QSize(22, 22));
        colorToolBtn->setAutoRaise(true);

        gridLayout->addWidget(colorToolBtn, 2, 5, 1, 1);

        sendToolBtn = new QToolButton(Widget_p2p);
        sendToolBtn->setObjectName(QString::fromUtf8("sendToolBtn"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/icon/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendToolBtn->setIcon(icon4);
        sendToolBtn->setIconSize(QSize(22, 22));
        sendToolBtn->setAutoRaise(true);

        gridLayout->addWidget(sendToolBtn, 2, 6, 1, 3);

        saveToolBtn = new QToolButton(Widget_p2p);
        saveToolBtn->setObjectName(QString::fromUtf8("saveToolBtn"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/icon/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveToolBtn->setIcon(icon5);
        saveToolBtn->setIconSize(QSize(22, 22));
        saveToolBtn->setAutoRaise(true);

        gridLayout->addWidget(saveToolBtn, 2, 9, 1, 1);

        clearToolBtn = new QToolButton(Widget_p2p);
        clearToolBtn->setObjectName(QString::fromUtf8("clearToolBtn"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../chat/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearToolBtn->setIcon(icon6);
        clearToolBtn->setIconSize(QSize(22, 22));
        clearToolBtn->setAutoRaise(true);

        gridLayout->addWidget(clearToolBtn, 2, 10, 1, 1);

        messageTextEdit = new QTextEdit(Widget_p2p);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));
        messageTextEdit->setAutoFormatting(QTextEdit::AutoNone);
        messageTextEdit->setUndoRedoEnabled(false);
        messageTextEdit->setLineWrapMode(QTextEdit::WidgetWidth);

        gridLayout->addWidget(messageTextEdit, 3, 0, 1, 11);

        sendButton = new QPushButton(Widget_p2p);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        gridLayout->addWidget(sendButton, 4, 1, 1, 1);

        exitButton = new QPushButton(Widget_p2p);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        gridLayout->addWidget(exitButton, 4, 6, 1, 4);

        id = new QLabel(Widget_p2p);
        id->setObjectName(QString::fromUtf8("id"));

        gridLayout->addWidget(id, 0, 10, 1, 1);

        label = new QLabel(Widget_p2p);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 9, 1, 1);

        nickname = new QLabel(Widget_p2p);
        nickname->setObjectName(QString::fromUtf8("nickname"));

        gridLayout->addWidget(nickname, 1, 10, 1, 1);

        label_2 = new QLabel(Widget_p2p);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 9, 1, 1);


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
        sendButton->setText(QApplication::translate("Widget_p2p", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("Widget_p2p", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        id->setText(QApplication::translate("Widget_p2p", "TextLabel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget_p2p", "\345\257\271\346\226\271ID:", 0, QApplication::UnicodeUTF8));
        nickname->setText(QApplication::translate("Widget_p2p", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget_p2p", "\345\257\271\346\226\271\346\230\265\347\247\260:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget_p2p: public Ui_Widget_p2p {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_P2P_H
