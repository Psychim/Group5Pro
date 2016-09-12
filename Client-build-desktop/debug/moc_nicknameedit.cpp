/****************************************************************************
** Meta object code from reading C++ file 'nicknameedit.h'
**
** Created: Sun Sep 11 18:01:43 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/nicknameedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nicknameedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NicknameEdit[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_NicknameEdit[] = {
    "NicknameEdit\0"
};

const QMetaObject NicknameEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_NicknameEdit,
      qt_meta_data_NicknameEdit, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NicknameEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NicknameEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NicknameEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NicknameEdit))
        return static_cast<void*>(const_cast< NicknameEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int NicknameEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
