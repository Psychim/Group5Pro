#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include<QtNetwork>
#include"user.h"
#include"clienttcpsocket.h"
namespace Ui {
    class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = 0);
    ~RegisterDialog();

public slots:
    void on_BackButton_clicked();
    void on_RegisterButton_clicked();
    void HandleRegisterFailed(QString);
    void HandleRegisterSuccess();
private:
    Ui::RegisterDialog *ui;
    ClientTcpSocket *tcpSocket;
signals:

};

#endif // REGISTERDIALOG_H
