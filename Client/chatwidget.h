#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include<QTextCharFormat>
#include "global.h"
#include "user.h"
#include "userlist.h"
class QUdpSocket;
class TcpServer;

namespace Ui {
    class ChatWidget;
}

class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidget(QWidget *parent = 0,User *user = NULL,int roomID=-1);
    ~ChatWidget();
    void setSelf(User *);
    void setRoomNum(int);

protected:
    void newParticipant(User* user,QString time);
    void participantLeft(int ID,QString time);
    void sendMessage(MessageType::MessageType type,QString serverAddress="");
    void hasPendingFile(int ID,QString nickName,QString serverAddress,QString clientAddress,QString fileName);
    bool saveFile(const QString& fileName);
    void closeEvent(QCloseEvent*);

    QString getIP();
    QString getUserName();
    QString getMessage();

private:
    Ui::ChatWidget *ui;
    QUdpSocket* udpSocket;
    qint16 port;
    QString fileName;
    TcpServer* server;
    QColor color;
    UserList * ChattingUsers;  //�������ҵ��û�����
    User * Self;    //�û��Լ��������������洫��
    int room;
signals:
    void Selfsetted();


private slots:
    void processPendingDatagrams();
    void on_sendButton_clicked();
    void getFileName(QString);
    void on_sendToolBtn_clicked();
    void on_fontComboBox_currentFontChanged(QFont f);
    void on_sizeComboBox_currentIndexChanged(QString size);
    void on_boldToolBtn_clicked(bool checked);
    void on_italicToolBtn_clicked(bool checked);
    void on_underlineToolBtn_clicked(bool checked);
    void on_colorToolBtn_clicked();
    void currentFormatChanged(const QTextCharFormat &format);
    void on_saveToolBtn_clicked();
    void on_clearToolBtn_clicked();
    void on_exitButton_clicked();
    void NewPtcp();
};

#endif // CHATWIDGET_H
