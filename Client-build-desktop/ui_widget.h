/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Thu Sep 1 15:39:03 2016
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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *userNumLabel;
    QLabel *nickname;
    QLabel *idlabel;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *userTableWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QCommandLinkButton *commandLinkButton;
    QTableWidget *roomtableWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setWindowModality(Qt::NonModal);
        Widget->resize(343, 572);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        userNumLabel = new QLabel(Widget);
        userNumLabel->setObjectName(QString::fromUtf8("userNumLabel"));

        gridLayout->addWidget(userNumLabel, 3, 0, 1, 1);

        nickname = new QLabel(Widget);
        nickname->setObjectName(QString::fromUtf8("nickname"));

        gridLayout->addWidget(nickname, 0, 1, 1, 1);

        idlabel = new QLabel(Widget);
        idlabel->setObjectName(QString::fromUtf8("idlabel"));

        gridLayout->addWidget(idlabel, 1, 1, 1, 1);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        userTableWidget = new QTableWidget(tab);
        if (userTableWidget->columnCount() < 2)
            userTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        userTableWidget->setObjectName(QString::fromUtf8("userTableWidget"));
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
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(commandLinkButton->sizePolicy().hasHeightForWidth());
        commandLinkButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(commandLinkButton);

        roomtableWidget = new QTableWidget(tab_2);
        if (roomtableWidget->columnCount() < 3)
            roomtableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        roomtableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        roomtableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        roomtableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        roomtableWidget->setObjectName(QString::fromUtf8("roomtableWidget"));

        verticalLayout->addWidget(roomtableWidget);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 2, 0, 1, 5);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\345\261\200\345\237\237\347\275\221\350\201\212\345\244\251\345\267\245\345\205\267", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "\346\230\265\347\247\260\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "ID:", 0, QApplication::UnicodeUTF8));
        userNumLabel->setText(QApplication::translate("Widget", "\345\234\250\347\272\277\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        nickname->setText(QApplication::translate("Widget", "\346\230\265\347\247\260", 0, QApplication::UnicodeUTF8));
        idlabel->setText(QApplication::translate("Widget", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = userTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = userTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\345\234\250\347\272\277\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        commandLinkButton->setText(QApplication::translate("Widget", "\346\226\260\345\273\272\346\210\277\351\227\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = roomtableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "\346\210\277\351\227\264\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = roomtableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget", "\346\210\277\351\227\264\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = roomtableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget", "\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\347\276\244\350\201\212", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
