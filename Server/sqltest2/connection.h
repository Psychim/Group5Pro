#ifndef CONNECTION_H
#define CONNECTION_H
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
static bool createConnection(){
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("123456");
    if(!db.open()){
        QMessageBox::critical(0,"Cannot open database1",
                              "Unable to establish a database connection.",QMessageBox::Cancel);
        return false;
    }
    /*QSqlQuery query;
    query.exec(QString("create table student (id int primary key,"
                       "name varchar, course int)"));
    query.exec(QString("insert into student values(1,'李强',11)"));
    query.exec(QString("insert into student values(2,'马亮',11)"));
    query.exec(QString("insert into student values(3,'李强',12)"));
    query.exec(QString("create table course(id int primary key,"
                       "name varchar, teacher varchar)"));
    query.exec(QString("insert into course values(10,'数学','王老师')"));
    query.exec(QString("insert into course values(11,'英语','张老师')"));
    query.exec(QString("insert into course values(12,'计算机','白老师')"));*/
    return true;

}

#endif // CONNECTION_H
