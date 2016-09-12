/****************************************************************************
** Meta object code from reading C++ file 'clienttcpsocket.h'
**
** Created: Sun Sep 11 19:10:11 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/clienttcpsocket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clienttcpsocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClientTcpSocket[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      37,   16,   16,   16, 0x05,
      58,   16,   16,   16, 0x05,
      76,   16,   16,   16, 0x05,
     100,   16,   16,   16, 0x05,
     112,   16,   16,   16, 0x05,
     128,   16,   16,   16, 0x05,
     145,   16,   16,   16, 0x05,
     171,   16,   16,   16, 0x05,
     184,   16,   16,   16, 0x05,
     206,   16,   16,   16, 0x05,
     221,   16,   16,   16, 0x05,
     239,  235,   16,   16, 0x05,
     270,  268,   16,   16, 0x05,
     296,   16,   16,   16, 0x05,
     312,  268,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     340,   16,   16,   16, 0x0a,
     354,   16,   16,   16, 0x0a,
     371,   16,   16,   16, 0x0a,
     389,   16,   16,   16, 0x0a,
     411,   16,   16,   16, 0x0a,
     434,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ClientTcpSocket[] = {
    "ClientTcpSocket\0\0LoginSuccess(User*)\0"
    "LoginFailed(QString)\0RegisterSuccess()\0"
    "RegisterFailed(QString)\0NoRespond()\0"
    "connectFailed()\0InvalidMessage()\0"
    "ServerError(QDataStream&)\0IniSuccess()\0"
    "ULReceived(UserList*)\0newPtcp(User*)\0"
    "PtcpLeft(int)\0,,,\0newRoom(int,QString,int,int)\0"
    ",\0UpdateUserNumber(int,int)\0DeleteRoom(int)\0"
    "NicknameUpdate(int,QString)\0ReadMessage()\0"
    "UDPReadMessage()\0HandleNoRespond()\0"
    "HandleConnectFailed()\0HandleInvalidMessage()\0"
    "HandleServerError(QDataStream&)\0"
};

const QMetaObject ClientTcpSocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_ClientTcpSocket,
      qt_meta_data_ClientTcpSocket, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClientTcpSocket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClientTcpSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClientTcpSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientTcpSocket))
        return static_cast<void*>(const_cast< ClientTcpSocket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int ClientTcpSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: LoginSuccess((*reinterpret_cast< User*(*)>(_a[1]))); break;
        case 1: LoginFailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: RegisterSuccess(); break;
        case 3: RegisterFailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: NoRespond(); break;
        case 5: connectFailed(); break;
        case 6: InvalidMessage(); break;
        case 7: ServerError((*reinterpret_cast< QDataStream(*)>(_a[1]))); break;
        case 8: IniSuccess(); break;
        case 9: ULReceived((*reinterpret_cast< UserList*(*)>(_a[1]))); break;
        case 10: newPtcp((*reinterpret_cast< User*(*)>(_a[1]))); break;
        case 11: PtcpLeft((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: newRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 13: UpdateUserNumber((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: DeleteRoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: NicknameUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 16: ReadMessage(); break;
        case 17: UDPReadMessage(); break;
        case 18: HandleNoRespond(); break;
        case 19: HandleConnectFailed(); break;
        case 20: HandleInvalidMessage(); break;
        case 21: HandleServerError((*reinterpret_cast< QDataStream(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void ClientTcpSocket::LoginSuccess(User * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientTcpSocket::LoginFailed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClientTcpSocket::RegisterSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ClientTcpSocket::RegisterFailed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ClientTcpSocket::NoRespond()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void ClientTcpSocket::connectFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void ClientTcpSocket::InvalidMessage()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void ClientTcpSocket::ServerError(QDataStream & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ClientTcpSocket::IniSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void ClientTcpSocket::ULReceived(UserList * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ClientTcpSocket::newPtcp(User * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void ClientTcpSocket::PtcpLeft(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void ClientTcpSocket::newRoom(int _t1, QString _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void ClientTcpSocket::UpdateUserNumber(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void ClientTcpSocket::DeleteRoom(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void ClientTcpSocket::NicknameUpdate(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}
QT_END_MOC_NAMESPACE
