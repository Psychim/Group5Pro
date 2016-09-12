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
    explicit ChatWidget(QWidget *parent = 0,User *user = NULL,int roomID=-1,QString roomName="");
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
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    QString getIP();
    QString getUserName();
    QString getMessage();
    QPoint offset;
private:
    Ui::ChatWidget *ui;
    QUdpSocket* udpSocket;
    qint16 port;
    QString fileName;
    TcpServer* server;
    QColor color;
    UserList * ChattingUsers;  //在聊天室的用户名单
    User * Self;    //用户自己，属性由主界面传递
    int room;
    QString name;
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
    void on_messageTextEdit_cursorPositionChanged();
};

#endif // CHATWIDGET_H
