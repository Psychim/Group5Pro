/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Mon Sep 12 20:22:25 2016
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QLineEdit *nickname;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLabel *idlabel;
    QSpacerItem *horizontalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *userTableWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QCommandLinkButton *commandLinkButton;
    QTableWidget *roomtableWidget;
    QLabel *userNumLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setWindowModality(Qt::NonModal);
        Widget->resize(353, 572);
        Widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	\n"
"	\n"
"}\n"
""));
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 0, 1, 0);
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(351, 30));
        frame->setMaximumSize(QSize(351, 30));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 91, 16));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 0, 30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icon/images/minmin.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 0, 30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icon/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);

        verticalLayout_2->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        nickname = new QLineEdit(Widget);
        nickname->setObjectName(QString::fromUtf8("nickname"));
        nickname->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nickname->sizePolicy().hasHeightForWidth());
        nickname->setSizePolicy(sizePolicy);
        nickname->setAutoFillBackground(false);
        nickname->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(240, 240, 240);"));
        nickname->setFrame(false);
        nickname->setReadOnly(false);

        horizontalLayout->addWidget(nickname);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        idlabel = new QLabel(Widget);
        idlabel->setObjectName(QString::fromUtf8("idlabel"));
        idlabel->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(idlabel->sizePolicy().hasHeightForWidth());
        idlabel->setSizePolicy(sizePolicy1);
        idlabel->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(idlabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget{border-radius:10px;\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        userTableWidget = new QTableWidget(tab);
        if (userTableWidget->columnCount() < 3)
            userTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        userTableWidget->setObjectName(QString::fromUtf8("userTableWidget"));
        userTableWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/new/icon/images/1354184767490.jpg);\n"
"color: rgb(255, 255, 255);"));
        userTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        userTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        userTableWidget->setShowGrid(false);

        verticalLayout_3->addWidget(userTableWidget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        commandLinkButton = new QCommandLinkButton(tab_2);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(commandLinkButton->sizePolicy().hasHeightForWidth());
        commandLinkButton->setSizePolicy(sizePolicy2);
        commandLinkButton->setStyleSheet(QString::fromUtf8("QCommandLinkButton{border-radius:10px;\n"
"\n"
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

        verticalLayout->addWidget(commandLinkButton);

        roomtableWidget = new QTableWidget(tab_2);
        if (roomtableWidget->columnCount() < 3)
            roomtableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        roomtableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        roomtableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        roomtableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        roomtableWidget->setObjectName(QString::fromUtf8("roomtableWidget"));
        roomtableWidget->setStyleSheet(QString::fromUtf8("border-image: url(:/new/icon/images/1354184767490.jpg);"));

        verticalLayout->addWidget(roomtableWidget);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);

        userNumLabel = new QLabel(Widget);
        userNumLabel->setObjectName(QString::fromUtf8("userNumLabel"));

        verticalLayout_2->addWidget(userNumLabel);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\345\261\200\345\237\237\347\275\221\350\201\212\345\244\251\345\267\245\345\205\267", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "Easy Chat", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label->setText(QApplication::translate("Widget", "\346\230\265\347\247\260\357\274\232", 0, QApplication::UnicodeUTF8));
        nickname->setText(QApplication::translate("Widget", "\346\230\265\347\247\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "ID:", 0, QApplication::UnicodeUTF8));
        idlabel->setText(QApplication::translate("Widget", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = userTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = userTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = userTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "\346\266\210\346\201\257\346\217\220\351\206\222", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\345\234\250\347\272\277\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        commandLinkButton->setText(QApplication::translate("Widget", "\346\226\260\345\273\272\346\210\277\351\227\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = roomtableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget", "\346\210\277\351\227\264\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = roomtableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget", "\346\210\277\351\227\264\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = roomtableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget", "\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\347\276\244\350\201\212", 0, QApplication::UnicodeUTF8));
        userNumLabel->setText(QApplication::translate("Widget", "\345\234\250\347\272\277\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
