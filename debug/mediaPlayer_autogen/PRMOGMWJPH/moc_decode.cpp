/****************************************************************************
** Meta object code from reading C++ file 'decode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/core/decode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'decode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Decoder_t {
    QByteArrayData data[9];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Decoder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Decoder_t qt_meta_stringdata_Decoder = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Decoder"
QT_MOC_LITERAL(1, 8, 17), // "videoFrameDecoded"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "frame"
QT_MOC_LITERAL(4, 33, 3), // "pts"
QT_MOC_LITERAL(5, 37, 18), // "audioBufferDecoded"
QT_MOC_LITERAL(6, 56, 6), // "buffer"
QT_MOC_LITERAL(7, 63, 8), // "finished"
QT_MOC_LITERAL(8, 72, 5) // "check"

    },
    "Decoder\0videoFrameDecoded\0\0frame\0pts\0"
    "audioBufferDecoded\0buffer\0finished\0"
    "check"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Decoder[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    2,   39,    2, 0x06 /* Public */,
       7,    0,   44,    2, 0x06 /* Public */,
       8,    0,   45,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::LongLong,    3,    4,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::LongLong,    6,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Decoder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Decoder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->videoFrameDecoded((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: _t->audioBufferDecoded((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 2: _t->finished(); break;
        case 3: _t->check(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Decoder::*)(const QImage & , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Decoder::videoFrameDecoded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Decoder::*)(const QByteArray & , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Decoder::audioBufferDecoded)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Decoder::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Decoder::finished)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Decoder::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Decoder::check)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Decoder::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_Decoder.data,
    qt_meta_data_Decoder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Decoder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Decoder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Decoder.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Decoder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Decoder::videoFrameDecoded(const QImage & _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Decoder::audioBufferDecoded(const QByteArray & _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Decoder::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Decoder::check()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
