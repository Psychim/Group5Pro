#include "logindialog.h"
#include "ui_logindialog.h"
#include"global.h"
#include <QShowEvent>
#include <QMouseEvent>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    tcpSocket=new ClientTcpSocket(this);
    connect(tcpSocket,SIGNAL(LoginSuccess(User*)),this,SLOT(HandleLoginSuccess(User*)));
    connect(tcpSocket,SIGNAL(LoginFailed(QString)),this,SLOT(HandleLoginFailed(QString)));
    connect(tcpSocket,SIGNAL(IniSuccess()),this,SLOT(DialogInit()));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons()&Qt::LeftButton)
    {
        if(event->y()<=ui->frame->height())
        {QPoint temp;
        temp=event->globalPos()-offset;
        move(temp);
        }
    }
}

void LoginDialog::on_LoginButton_clicked()
{
    if(!tcpSocket->connectToServer()){
        ui->PasswordLineEdit->setText("");
        return;
    }
    QString username=ui->UsernameLineEdit->text();
    QString password=ui->PasswordLineEdit->text();
    QByteArray buffer;
    QDataStream out(&buffer,QIODevice::WriteOnly);
    out.setVersion(VERSION);
    out<<(MessageSize)0;
    out<<MessageType::Login;
    out<<username<<password;
    out.device()->seek(0);
    out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
    tcpSocket->WriteAndWait(buffer,1000);
}

void LoginDialog::on_RegisterButton_clicked()
{
    hide();
    tcpSocket->abort();
    RegisterDialog *regdialog=new RegisterDialog;
    regdialog->exec();
    delete regdialog;
    show();
}
void LoginDialog::HandleLoginFailed(QString error){
    ui->StatusLabel->setText(error);
}

void LoginDialog::HandleLoginSuccess(User * user)
{
    ui->StatusLabel->setText(tr("登录成功"));
    tcpSocket->abort();
    Widget *MainWidget=new Widget;
    connect(this,SIGNAL(LoginSuccess(User*)),MainWidget,SLOT(initialize(User*)));
    emit LoginSuccess(user);
    close();
}

void LoginDialog::DialogInit()
{
    ui->StatusLabel->setText(tr("请输入用户名和密码"));
    ui->LoginButton->setEnabled(true);
}

void LoginDialog::on_pushButton_2_clicked()
{
    showMinimized();
}

void LoginDialog::on_pushButton_clicked()
{
    close();
}
