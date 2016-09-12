
QT       += core gui\
            network
QT       += multimedia
INCLUDEPATH +=..\OpenCV2.1\include\opencv \
    ..\videoInput\libs\DShow\include
LIBS +=-L..\OpenCV2.1\lib\ -lcv210 -lcvaux210 -lcxcore210 -lhighgui210 -lml210 -lopencv_ffmpeg210
#LIBS +=-LF:\videoInput\compiledLib\vs2012 -lvideoInput -lvideoInputD
LIBS += -L..\videoInput\libs\DShow\lib -lddraw -ldxguid -lole32 -loleaut32 -lstrmbasd -lstrmiids -luuid
LIBS+=-L..\va_g729a -lva_g729a

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
    va_g729a.h \
    videoInput.h

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
    cudpthread.cpp \
    videoInput.cpp

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
