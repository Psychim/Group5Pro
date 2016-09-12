#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include<QtNetwork>
#include"user.h"
#include"clienttcpsocket.h"
#include "registerdialog.h"
#include"widget.h"
#include <QPoint>
#include <QMouseEvent>
namespace Ui {
    class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

public slots:
    void on_LoginButton_clicked();
    void on_RegisterButton_clicked();
    void HandleLoginFailed(QString);
    void HandleLoginSuccess(User *);
    void DialogInit();
protected:
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
private:
    Ui::LoginDialog *ui;
    ClientTcpSocket *tcpSocket;
    QPoint offset;
signals:
    void LoginSuccess(User *);
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // DIALOG_H
