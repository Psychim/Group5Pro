/****************************************************************************
** Meta object code from reading C++ file 'chatwidget.h'
**
** Created: Mon Sep 12 19:13:07 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/chatwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChatWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      25,   11,   11,   11, 0x08,
      51,   11,   11,   11, 0x08,
      75,   11,   11,   11, 0x08,
      96,   11,   11,   11, 0x08,
     123,  121,   11,   11, 0x08,
     170,  165,   11,   11, 0x08,
     223,  215,   11,   11, 0x08,
     252,  215,   11,   11, 0x08,
     283,  215,   11,   11, 0x08,
     317,   11,   11,   11, 0x08,
     350,  343,   11,   11, 0x08,
     388,   11,   11,   11, 0x08,
     413,   11,   11,   11, 0x08,
     439,   11,   11,   11, 0x08,
     463,   11,   11,   11, 0x08,
     473,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ChatWidget[] = {
    "ChatWidget\0\0Selfsetted()\0"
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
    "on_exitButton_clicked()\0NewPtcp()\0"
    "on_messageTextEdit_cursorPositionChanged()\0"
};

const QMetaObject ChatWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChatWidget,
      qt_meta_data_ChatWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChatWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChatWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChatWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChatWidget))
        return static_cast<void*>(const_cast< ChatWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChatWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Selfsetted(); break;
        case 1: processPendingDatagrams(); break;
        case 2: on_sendButton_clicked(); break;
        case 3: getFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: on_sendToolBtn_clicked(); break;
        case 5: on_fontComboBox_currentFontChanged((*reinterpret_cast< QFont(*)>(_a[1]))); break;
        case 6: on_sizeComboBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: on_boldToolBtn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: on_italicToolBtn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: on_underlineToolBtn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: on_colorToolBtn_clicked(); break;
        case 11: currentFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 12: on_saveToolBtn_clicked(); break;
        case 13: on_clearToolBtn_clicked(); break;
        case 14: on_exitButton_clicked(); break;
        case 15: NewPtcp(); break;
        case 16: on_messageTextEdit_cursorPositionChanged(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void ChatWidget::Selfsetted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
