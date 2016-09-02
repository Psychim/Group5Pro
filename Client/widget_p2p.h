#ifndef WIDGET_P2P_H
#define WIDGET_P2P_H

#include <QWidget>
#include<QTextCharFormat>
#include "global.h"
#include "user.h"
class QUdpSocket;
class TcpServer;

namespace Ui {
    class Widget_p2p;
}


class Widget_p2p : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_p2p(QWidget *parent = 0);
    ~Widget_p2p();
    void setPartner(User *);
    void setPartnerAddress(QString);
    void setPartnerID(int);
    void setPartnerNickname(QString);
    void readMessage(QByteArray);
    void setSelf(User *);
    int getPartnerID();
protected:
    //void newParticipant(QString userName,QString localHostName,QString ipAddress);
    void participantLeft(QString userName,QString time);
    void sendMessage(MessageType::MessageType type,QString serverAddress="");
    void hasPendingFile(QString userName,QString serverAddress,QString clientAddress,QString fileName);
    bool saveFile(const QString& fileName);
    void closeEvent(QCloseEvent*);

    //QString getUserName();
    QString getMessage();
    void showEvent(QShowEvent *);
private:
    Ui::Widget_p2p *ui;
    QUdpSocket* udpSocket;
    qint16 port;
    QString fileName;
    TcpServer* server;
    QColor color;
    User * Partner;
    User * Self;
    int MsgNotRcved;
    bool isOpen;
signals:
    void newMessage(int,int);
    void closed(Widget_p2p*);
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
    void on_messageTextEdit_cursorPositionChanged();
};

#endif // WIDGET_P2P_H
