#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"server.h"
#include<QMessageBox>
#include<QSqlQueryModel>
#include<QTableView>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainServer = new Server(this);
    ui->serverStatuslabel->setText(tr("初始化成功！"));
    connect(MainServer,SIGNAL(newConnection()),MainServer,SLOT(acceptConnection()));
    StartListen();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::StartListen(){
    MainServer->close();
    MainServer->Init();
    ui->serverStatuslabel->setText(tr("正在监听..."));
    QAction *tmp=ui->mainToolBar->actions().at(0);
    tmp->setEnabled(false);
    tmp=ui->mainToolBar->actions().at(1);
    tmp->setEnabled(true);
    on_freshaction_triggered();
}

void MainWindow::on_Start_triggered()
{
    StartListen();
}

void MainWindow::on_QueryButton_clicked()
{
    QString statement=ui->QueryLineEdit->text();
    MainServer->Query(statement);
    on_freshaction_triggered();
}

void MainWindow::on_freshaction_triggered()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("select id,username,nickname from users");
    ui->tableView->setModel(model);
}

void MainWindow::on_QueryLineEdit_returnPressed()
{
    on_QueryButton_clicked();
}

void MainWindow::on_Stop_triggered()
{
    StopListen();
}

void MainWindow::StopListen()
{
    MainServer->Stop();
    QAction *tmp=ui->mainToolBar->actions().at(1);
    tmp->setEnabled(false);
    tmp=ui->mainToolBar->actions().at(0);
    tmp->setEnabled(true);
}
