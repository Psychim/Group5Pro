/****************************************************************************
** Meta object code from reading C++ file 'cudpthread.h'
**
** Created: Mon Sep 12 19:13:21 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/cudpthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cudpthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CUdpThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   12,   11,   11, 0x05,
      50,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,   11,   11,   11, 0x08,
      86,   11,   11,   11, 0x08,
      92,   12,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CUdpThread[] = {
    "CUdpThread\0\0byte_array\0"
    "signalSendData(QByteArray)\0stopThread()\0"
    "ReadPendingDatagrams()\0run()\0"
    "slotSendData(QByteArray)\0stopSocket()\0"
};

const QMetaObject CUdpThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CUdpThread,
      qt_meta_data_CUdpThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CUdpThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CUdpThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CUdpThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CUdpThread))
        return static_cast<void*>(const_cast< CUdpThread*>(this));
    return QObject::qt_metacast(_clname);
}

int CUdpThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalSendData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: stopThread(); break;
        case 2: ReadPendingDatagrams(); break;
        case 3: run(); break;
        case 4: slotSendData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 5: stopSocket(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CUdpThread::signalSendData(const QByteArray & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CUdpThread::stopThread()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
