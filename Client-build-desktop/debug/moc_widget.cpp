/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Wed Sep 7 14:13:28 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x09,
      33,   30,    7,    7, 0x09,
      54,    7,    7,    7, 0x08,
      73,    7,    7,    7, 0x08,
     110,  106,    7,    7, 0x08,
     145,    7,    7,    7, 0x08,
     163,    7,    7,    7, 0x08,
     194,    7,    7,    7, 0x08,
     233,  231,    7,    7, 0x08,
     257,    7,    7,    7, 0x08,
     273,  231,    7,    7, 0x08,
     291,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0newParticipant(User*)\0Id\0"
    "participantLeft(int)\0process(UserList*)\0"
    "doubleClicked(QTableWidgetItem*)\0,,,\0"
    "HandlenewRoom(int,QString,int,int)\0"
    "initialize(User*)\0on_commandLinkButton_clicked()\0"
    "roomdoubleClicked(QTableWidgetItem*)\0"
    ",\0UpdateRoomInfo(int,int)\0DeleteRoom(int)\0"
    "MsgPromt(int,int)\0KIllp2pWidget(Widget_p2p*)\0"
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newParticipant((*reinterpret_cast< User*(*)>(_a[1]))); break;
        case 1: participantLeft((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: process((*reinterpret_cast< UserList*(*)>(_a[1]))); break;
        case 3: doubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 4: HandlenewRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: initialize((*reinterpret_cast< User*(*)>(_a[1]))); break;
        case 6: on_commandLinkButton_clicked(); break;
        case 7: roomdoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 8: UpdateRoomInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: DeleteRoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: MsgPromt((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: KIllp2pWidget((*reinterpret_cast< Widget_p2p*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
