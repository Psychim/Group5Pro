/****************************************************************************
** Meta object code from reading C++ file 'camthread.h'
**
** Created: Wed Sep 7 10:42:31 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/camthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CamThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CamThread[] = {
    "CamThread\0\0ImageProducted(QImage)\0"
    "stop()\0"
};

const QMetaObject CamThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_CamThread,
      qt_meta_data_CamThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CamThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CamThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CamThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CamThread))
        return static_cast<void*>(const_cast< CamThread*>(this));
    return QThread::qt_metacast(_clname);
}

int CamThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ImageProducted((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: stop(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CamThread::ImageProducted(QImage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE