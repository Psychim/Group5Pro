/****************************************************************************
** Meta object code from reading C++ file 'tcpclient.h'
**
** Created: Fri Sep 2 09:20:13 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/tcpclient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TcpClient[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      43,   10,   10,   10, 0x08,
      74,   10,   10,   10, 0x08,
      87,   10,   10,   10, 0x08,
     101,   10,   10,   10, 0x08,
     144,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TcpClient[] = {
    "TcpClient\0\0on_tcpClientCancelBtn_clicked()\0"
    "on_tcpClientCloseBtn_clicked()\0"
    "newConnect()\0readMessage()\0"
    "displayError(QAbstractSocket::SocketError)\0"
    "on_tcpClientCancelBtm_clicked()\0"
};

const QMetaObject TcpClient::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TcpClient,
      qt_meta_data_TcpClient, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TcpClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TcpClient))
        return static_cast<void*>(const_cast< TcpClient*>(this));
    return QDialog::qt_metacast(_clname);
}

int TcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_tcpClientCancelBtn_clicked(); break;
        case 1: on_tcpClientCloseBtn_clicked(); break;
        case 2: newConnect(); break;
        case 3: readMessage(); break;
        case 4: displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: on_tcpClientCancelBtn_clicked(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
