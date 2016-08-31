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
        ui->StatusLabel->setText(tr("�û�������Ϊ��"));
    }
    else if(ui->NicknameLineEdit->text()==""){
        ui->StatusLabel->setText(tr("�ǳƲ���Ϊ��"));
    }
    else if(ui->PasswordLineEdit->text()==""){
        ui->StatusLabel->setText(tr("���벻��Ϊ��"));
    }
    else if(ui->PasswordCheckLineEdit->text()!=ui->PasswordLineEdit->text()){
        ui->StatusLabel->setText(tr("�����������벻һ�£�����������"));
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
    QMessageBox::critical(0,"ע��ʧ��",
                          error,QMessageBox::Cancel);
}

void RegisterDialog::HandleRegisterSuccess()
{
    QMessageBox::information(0,"ע��ɹ�","ע��ɹ�");
    on_BackButton_clicked();
}
