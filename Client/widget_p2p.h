#ifndef WIDGET_P2P_H
#define WIDGET_P2P_H

#include <QWidget>
#include<QTextCharFormat>
#include "global.h"
#include "user.h"
#include "camthread.h"
#include"imgsktthread.h"
#include <QAudioInput>
#include <QAudioOutput>
#include <QByteArray>
#include "cg729encoder.h"
#include "cg729decoder.h"
#include "cudpthread.h"
#include <QThread>
#include <QMouseEvent>
#include <QPoint>
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
    void VideoRequestReceived(int);

public slots:

    // 此处是与音频传输相关的槽
    void slotSendData();
    void slotReadData(const QByteArray &byte_array);

protected:
    //void newParticipant(QString userName,QString localHostName,QString ipAddress);
    void participantLeft(QString userName,QString time);
    void sendMessage(MessageType::MessageType type,QString serverAddress="");
    void sendMessage(MessageType::MessageType type,int step);
    void hasPendingFile(QString userName,QString serverAddress,QString clientAddress,QString fileName);
    bool saveFile(const QString& fileName);
    void closeEvent(QCloseEvent*);
    void mouseMoveEvent(QMouseEvent *);
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
    bool VideoOpened;
    CamThread *cm;
    ImgSktThread *imgskt;
    QPoint offset;
    // 此处是与编码音频有关的变量
    CG729Encoder cg729Encoder;
    QAudioInput* audioInput;
    QIODevice * streamIn;

    // 此处是与解码音频有关的变量
    CG729Decoder cg729Decoder;
    QAudioOutput* audioOutput;
    QIODevice * streamOut;

    //记录数据的变量
    QByteArray tempBuffer;
    QByteArray tempframe;

    // 线程
    QThread * udpThreadFather;
    CUdpThread* udpThread;

signals:
    void newMessage(int,int);
    void closed(Widget_p2p*);
    void signalSendData(const QByteArray &byte_array); // 与音频传输相关
    void stopVoice();

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
    void on_OpenVideoButton_clicked();

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void stopThread();
};

#endif // WIDGET_P2P_H
