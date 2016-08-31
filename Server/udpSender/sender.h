#ifndef SENDER_H
#define SENDER_H

#include <QDialog>
class QUdpSocket;
namespace Ui {
    class Sender;
}

class Sender : public QDialog
{
    Q_OBJECT

public:
    explicit Sender(QWidget *parent = 0);
    ~Sender();
    QString getlocalIP();
private slots:
    void on_pushButton_clicked();
    void ReadMessage();
private:
    Ui::Sender *ui;
    QUdpSocket *sender;
};

#endif // SENDER_H
