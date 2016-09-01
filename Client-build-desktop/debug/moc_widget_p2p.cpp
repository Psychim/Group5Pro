/****************************************************************************
** Meta object code from reading C++ file 'widget_p2p.h'
**
** Created: Thu Sep 1 20:05:11 2016
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
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      62,   11,   11,   11, 0x08,
      83,   11,   11,   11, 0x08,
     110,  108,   11,   11, 0x08,
     157,  152,   11,   11, 0x08,
     210,  202,   11,   11, 0x08,
     239,  202,   11,   11, 0x08,
     270,  202,   11,   11, 0x08,
     304,   11,   11,   11, 0x08,
     337,  330,   11,   11, 0x08,
     375,   11,   11,   11, 0x08,
     400,   11,   11,   11, 0x08,
     426,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget_p2p[] = {
    "Widget_p2p\0\0processPendingDatagrams()\0"
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
        case 0: processPendingDatagrams(); break;
        case 1: on_sendButton_clicked(); break;
        case 2: getFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: on_sendToolBtn_clicked(); break;
        case 4: on_fontComboBox_currentFontChanged((*reinterpret_cast< QFont(*)>(_a[1]))); break;
        case 5: on_sizeComboBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: on_boldToolBtn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: on_italicToolBtn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: on_underlineToolBtn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: on_colorToolBtn_clicked(); break;
        case 10: currentFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 11: on_saveToolBtn_clicked(); break;
        case 12: on_clearToolBtn_clicked(); break;
        case 13: on_exitButton_clicked(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
