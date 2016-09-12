
QT       += core gui\
            network
QT       += multimedia
INCLUDEPATH +=F:\OpenCV2.1\include\opencv \
    F:/OpenCV2.1/include

LIBS +=F:/OpenCV2.1/lib/*
LIBS+=-LF:\va_g729a -lva_g729a

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
    videolabel.h \
    imgsktthread.h \
    cg729decoder.h \
    cg729encoder.h \
    cudpthread.h \
    va_g729a.h

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
    videolabel.cpp \
    imgsktthread.cpp \
    cg729decoder.cpp \
    cg729encoder.cpp \
    cudpthread.cpp

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
