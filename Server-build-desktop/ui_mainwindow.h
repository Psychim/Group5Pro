/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Sep 1 08:59:02 2016
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Start;
    QAction *freshaction;
    QAction *Stop;
    QAction *Log;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QTextEdit *textEdit;
    QLabel *serverStatuslabel;
    QLineEdit *QueryLineEdit;
    QPushButton *QueryButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(399, 411);
        Start = new QAction(MainWindow);
        Start->setObjectName(QString::fromUtf8("Start"));
        freshaction = new QAction(MainWindow);
        freshaction->setObjectName(QString::fromUtf8("freshaction"));
        Stop = new QAction(MainWindow);
        Stop->setObjectName(QString::fromUtf8("Stop"));
        Log = new QAction(MainWindow);
        Log->setObjectName(QString::fromUtf8("Log"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        serverStatuslabel = new QLabel(centralwidget);
        serverStatuslabel->setObjectName(QString::fromUtf8("serverStatuslabel"));

        verticalLayout->addWidget(serverStatuslabel);

        QueryLineEdit = new QLineEdit(centralwidget);
        QueryLineEdit->setObjectName(QString::fromUtf8("QueryLineEdit"));

        verticalLayout->addWidget(QueryLineEdit);

        QueryButton = new QPushButton(centralwidget);
        QueryButton->setObjectName(QString::fromUtf8("QueryButton"));

        verticalLayout->addWidget(QueryButton);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 399, 22));
        MainWindow->setMenuBar(menubar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(Start);
        mainToolBar->addAction(Stop);
        mainToolBar->addAction(Log);
        mainToolBar->addAction(freshaction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        Start->setText(QApplication::translate("MainWindow", "\345\274\200\345\220\257", 0, QApplication::UnicodeUTF8));
        freshaction->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        Stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        Log->setText(QApplication::translate("MainWindow", "\346\227\245\345\277\227", 0, QApplication::UnicodeUTF8));
        serverStatuslabel->setText(QApplication::translate("MainWindow", "\346\255\243\345\234\250\345\210\235\345\247\213\345\214\226...", 0, QApplication::UnicodeUTF8));
        QueryButton->setText(QApplication::translate("MainWindow", "Query", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
