
QT       += core gui\
            network
INCLUDEPATH +=F:\OpenCV2.1\include\opencv \
    F:/OpenCV2.1/include

LIBS +=F:/OpenCV2.1/lib/*

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
    chatwidget.h \
    videodevice.h \
    camthread.h \
    videolabel.h

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
    chatwidget.cpp \
    videodevice.cpp \
    camthread.cpp \
    videolabel.cpp

FORMS += \
    widget_p2p.ui \
    widget.ui \
    tcpserver.ui \
    tcpclient.ui \
    registerdialog.ui \
    logindialog.ui \
    chatwidget.ui

RESOURCES += \
    IconSources.qrc
