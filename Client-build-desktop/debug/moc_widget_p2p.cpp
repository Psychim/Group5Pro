/****************************************************************************
** Meta object code from reading C++ file 'widget_p2p.h'
**
** Created: Mon Sep 12 19:12:27 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/widget_p2p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget_p2p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget_p2p[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x05,
      34,   11,   11,   11, 0x05,
      65,   54,   11,   11, 0x05,
      92,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     104,   11,   11,   11, 0x0a,
     119,   54,   11,   11, 0x0a,
     144,   11,   11,   11, 0x08,
     170,   11,   11,   11, 0x08,
     194,   11,   11,   11, 0x08,
     215,   11,   11,   11, 0x08,
     242,  240,   11,   11, 0x08,
     289,  284,   11,   11, 0x08,
     342,  334,   11,   11, 0x08,
     371,  334,   11,   11, 0x08,
     402,  334,   11,   11, 0x08,
     436,   11,   11,   11, 0x08,
     469,  462,   11,   11, 0x08,
     507,   11,   11,   11, 0x08,
     532,   11,   11,   11, 0x08,
     558,   11,   11,   11, 0x08,
     582,   11,   11,   11, 0x08,
     625,   11,   11,   11, 0x08,
     654,   11,   11,   11, 0x08,
     678,   11,   11,   11, 0x08,
     704,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget_p2p[] = {
    "Widget_p2p\0\0,\0newMessage(int,int)\0"
    "closed(Widget_p2p*)\0byte_array\0"
    "signalSendData(QByteArray)\0stopVoice()\0"
    "slotSendData()\0slotReadData(QByteArray)\0"
    "processPendingDatagrams()\0"
    "on_sendButton_clicked()\0getFileName(QString)\0"
    "on_sendToolBtn_clicked()\0f\0"
    "on_fontComboBox_currentFontChanged(QFont)\0"
    "size\0on_sizeComboBox_currentIndexChanged(QString)\0"
    "checked\0on_boldToolBtn_clicked(bool)\0"
    "on_italicToolBtn_clicked(bool)\0"
    "on_underlineToolBtn_clicked(bool)\0"
    "on_colorToolBtn_clicked()\0format\0"
    "currentFormatChanged(QTextCharFormat)\0"
    "on_saveToolBtn_clicked()\0"
    "on_clearToolBtn_clicked()\0"
    "on_exitButton_clicked()\0"
    "on_messageTextEdit_cursorPositionChanged()\0"
    "on_OpenVideoButton_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0stopThread()\0"
};

const QMetaObject Widget_p2p::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget_p2p,
      qt_meta_data_Widget_p2p, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget_p2p::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget_p2p::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget_p2p::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_p2p))
        return static_cast<void*>(const_cast< Widget_p2p*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget_p2p::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: closed((*reinterpret_cast< Widget_p2p*(*)>(_a[1]))); break;
        case 2: signalSendData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 3: stopVoice(); break;
        case 4: slotSendData(); break;
        case 5: slotReadData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 6: processPendingDatagrams(); break;
        case 7: on_sendButton_clicked(); break;
        case 8: getFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: on_sendToolBtn_clicked(); break;
        case 10: on_fontComboBox_currentFontChanged((*reinterpret_cast< QFont(*)>(_a[1]))); break;
        case 11: on_sizeComboBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: on_boldToolBtn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: on_italicToolBtn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: on_underlineToolBtn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: on_colorToolBtn_clicked(); break;
        case 16: currentFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 17: on_saveToolBtn_clicked(); break;
        case 18: on_clearToolBtn_clicked(); break;
        case 19: on_exitButton_clicked(); break;
        case 20: on_messageTextEdit_cursorPositionChanged(); break;
        case 21: on_OpenVideoButton_clicked(); break;
        case 22: on_pushButton_clicked(); break;
        case 23: on_pushButton_2_clicked(); break;
        case 24: stopThread(); break;
        default: ;
        }
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void Widget_p2p::newMessage(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget_p2p::closed(Widget_p2p * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Widget_p2p::signalSendData(const QByteArray & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Widget_p2p::stopVoice()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
