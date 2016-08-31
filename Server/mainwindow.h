#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"server.h"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Server *MainServer;
public slots:
    void StartListen();
    void StopListen();
    void on_Start_triggered();
private slots:
    void on_QueryButton_clicked();
    void on_freshaction_triggered();
    void on_QueryLineEdit_returnPressed();
    void on_Stop_triggered();
};

#endif // MAINWINDOW_H
