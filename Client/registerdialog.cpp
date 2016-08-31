#include "registerdialog.h"
#include "ui_registerdialog.h"
#include"global.h"
#include<QMessageBox>
RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    tcpSocket=new ClientTcpSocket(this);
    connect(tcpSocket,SIGNAL(readyRead()),tcpSocket,SLOT(ReadMessage()));
    connect(tcpSocket,SIGNAL(RegisterSuccess()),this,SLOT(HandleRegisterSuccess()));
    connect(tcpSocket,SIGNAL(RegisterFailed(QString)),this,SLOT(HandleRegisterFailed(QString)));
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_BackButton_clicked()
{
    tcpSocket->abort();
    close();
}
void RegisterDialog::on_RegisterButton_clicked()
{
    if(ui->UsernameLineEdit->text()==""){
        ui->StatusLabel->setText(tr("用户名不能为空"));
    }
    else if(ui->NicknameLineEdit->text()==""){
        ui->StatusLabel->setText(tr("昵称不能为空"));
    }
    else if(ui->PasswordLineEdit->text()==""){
        ui->StatusLabel->setText(tr("密码不能为空"));
    }
    else if(ui->PasswordCheckLineEdit->text()!=ui->PasswordLineEdit->text()){
        ui->StatusLabel->setText(tr("两次密码输入不一致，请重新输入"));
    }
    else{
        if(!tcpSocket->connectToServer()){
            return;
        }
        QByteArray buffer;
        QDataStream out(&buffer,QIODevice::WriteOnly);
        out<<(MessageSize)0;
        out<<MessageType::Register;
        out<<ui->UsernameLineEdit->text();
        out<<ui->NicknameLineEdit->text();
        out<<ui->PasswordLineEdit->text();
        out.device()->seek(0);
        out<<(MessageSize)(buffer.size()-sizeof(MessageSize));
        tcpSocket->WriteAndWait(buffer);
        return;
    }
    ui->PasswordCheckLineEdit->setText("");
    ui->PasswordLineEdit->setText("");
}
void RegisterDialog::HandleRegisterFailed(QString error){
    QMessageBox::critical(0,"注册失败",
                          error,QMessageBox::Cancel);
}

void RegisterDialog::HandleRegisterSuccess()
{
    QMessageBox::information(0,"注册成功","注册成功");
    on_BackButton_clicked();
}
