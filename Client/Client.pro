
QT       += core gui\
            network

HEADERS += \
    widget_p2p.h \
    widget.h \
    userlist.h \
    user.h \
    tcpserver.h \
    tcpclient.h \
    registerdialog.h \
    logindialog.h \
    global.h \
    clienttcpsocket.h \
    chatwidget.h

SOURCES += \
    widget_p2p.cpp \
    widget.cpp \
    userlist.cpp \
    user.cpp \
    tcpserver.cpp \
    tcpclient.cpp \
    registerdialog.cpp \
    main.cpp \
    logindialog.cpp \
    clienttcpsocket.cpp \
    chatwidget.cpp

FORMS += \
    widget_p2p.ui \
    widget.ui \
    tcpserver.ui \
    tcpclient.ui \
    registerdialog.ui \
    logindialog.ui \
    chatwidget.ui
