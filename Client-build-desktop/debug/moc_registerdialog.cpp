/****************************************************************************
** Meta object code from reading C++ file 'registerdialog.h'
**
** Created: Wed Aug 31 16:37:36 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/registerdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registerdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RegisterDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      40,   15,   15,   15, 0x0a,
      68,   15,   15,   15, 0x0a,
      98,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RegisterDialog[] = {
    "RegisterDialog\0\0on_BackButton_clicked()\0"
    "on_RegisterButton_clicked()\0"
    "HandleRegisterFailed(QString)\0"
    "HandleRegisterSuccess()\0"
};

const QMetaObject RegisterDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RegisterDialog,
      qt_meta_data_RegisterDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RegisterDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RegisterDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RegisterDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RegisterDialog))
        return static_cast<void*>(const_cast< RegisterDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int RegisterDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_BackButton_clicked(); break;
        case 1: on_RegisterButton_clicked(); break;
        case 2: HandleRegisterFailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: HandleRegisterSuccess(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE