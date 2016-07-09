/****************************************************************************
** Meta object code from reading C++ file 'Replier.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/reqrep/Replier.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Replier.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_nzmqt__samples__reqrep__Replier_t {
    QByteArrayData data[7];
    char stringdata[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_nzmqt__samples__reqrep__Replier_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_nzmqt__samples__reqrep__Replier_t qt_meta_stringdata_nzmqt__samples__reqrep__Replier = {
    {
QT_MOC_LITERAL(0, 0, 31),
QT_MOC_LITERAL(1, 32, 15),
QT_MOC_LITERAL(2, 48, 0),
QT_MOC_LITERAL(3, 49, 17),
QT_MOC_LITERAL(4, 67, 7),
QT_MOC_LITERAL(5, 75, 9),
QT_MOC_LITERAL(6, 85, 14)
    },
    "nzmqt::samples::reqrep::Replier\0"
    "requestReceived\0\0QList<QByteArray>\0"
    "request\0replySent\0receiveRequest\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nzmqt__samples__reqrep__Replier[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06,
       5,    1,   32,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    1,   35,    2, 0x09,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void nzmqt::samples::reqrep::Replier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Replier *_t = static_cast<Replier *>(_o);
        switch (_id) {
        case 0: _t->requestReceived((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        case 1: _t->replySent((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        case 2: _t->receiveRequest((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QByteArray> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QByteArray> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QByteArray> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Replier::*_t)(const QList<QByteArray> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Replier::requestReceived)) {
                *result = 0;
            }
        }
        {
            typedef void (Replier::*_t)(const QList<QByteArray> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Replier::replySent)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject nzmqt::samples::reqrep::Replier::staticMetaObject = {
    { &SampleBase::staticMetaObject, qt_meta_stringdata_nzmqt__samples__reqrep__Replier.data,
      qt_meta_data_nzmqt__samples__reqrep__Replier,  qt_static_metacall, 0, 0}
};


const QMetaObject *nzmqt::samples::reqrep::Replier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nzmqt::samples::reqrep::Replier::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_nzmqt__samples__reqrep__Replier.stringdata))
        return static_cast<void*>(const_cast< Replier*>(this));
    return SampleBase::qt_metacast(_clname);
}

int nzmqt::samples::reqrep::Replier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SampleBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void nzmqt::samples::reqrep::Replier::requestReceived(const QList<QByteArray> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void nzmqt::samples::reqrep::Replier::replySent(const QList<QByteArray> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
