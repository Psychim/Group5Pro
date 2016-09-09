
QT       += core gui\
            network
INCLUDEPATH +=F:\OpenCV2.1\include\opencv \
    F:/OpenCV2.1/include \
    F:\Group5Pro\Client\libs\DShow\include
LIBS +=-LF:/OpenCV2.1/lib/ -lcv210 -lcvaux210 -lcxcore210 -lhighgui210 -lml210 -lopencv_ffmpeg210
LIBS +=-LF:\videoInput\compiledLib\vs2012 -lvideoInput -lvideoInputD
LIBS += -LF:\videoInput\videoInputSrcAndDemos\libs\DShow\lib -lddraw -ldxguid -lole32 -loleaut32 -lstrmbasd -lstrmiids -luuid
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
    libs/videoInput/videoInput.h

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
    libs/videoInput/videoInput.cpp

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
