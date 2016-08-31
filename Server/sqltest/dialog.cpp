#include "dialog.h"
#include "ui_dialog.h"
#include<QSqlQueryModel>
#include<QSqlTableModel>
#include<QSqlRelationalTableModel>
#include<QTableView>
#include<QDebug>
#include<QMessageBox>
#include<QSqlError>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("select * from student");
    model->setHeaderData(0,Qt::Horizontal,tr("ѧ��"));
    model->setHeaderData(1,Qt::Horizontal,tr("����"));
    model->setHeaderData(2,Qt::Horizontal,tr("�γ�"));
    QTableView * view=new QTableView(this);
    view->setModel(model);
    setCentralWidget(view);
}

Dialog::~Dialog()
{
    delete ui;
}
