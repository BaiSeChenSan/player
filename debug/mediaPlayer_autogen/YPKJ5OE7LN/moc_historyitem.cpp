/****************************************************************************
** Meta object code from reading C++ file 'historyitem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/ui/historyitem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'historyitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HistoryItem_t {
    QByteArrayData data[20];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HistoryItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HistoryItem_t qt_meta_stringdata_HistoryItem = {
    {
QT_MOC_LITERAL(0, 0, 11), // "HistoryItem"
QT_MOC_LITERAL(1, 12, 11), // "itemClicked"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "QString&"
QT_MOC_LITERAL(4, 34, 8), // "fileName"
QT_MOC_LITERAL(5, 43, 13), // "aiItemclicked"
QT_MOC_LITERAL(6, 57, 15), // "likeItemClicked"
QT_MOC_LITERAL(7, 73, 7), // "isliked"
QT_MOC_LITERAL(8, 81, 9), // "isUnliked"
QT_MOC_LITERAL(9, 91, 17), // "unlikeItemClicked"
QT_MOC_LITERAL(10, 109, 15), // "downloadClicked"
QT_MOC_LITERAL(11, 125, 10), // "isDownLoad"
QT_MOC_LITERAL(12, 136, 9), // "addToList"
QT_MOC_LITERAL(13, 146, 8), // "duration"
QT_MOC_LITERAL(14, 155, 10), // "removeItem"
QT_MOC_LITERAL(15, 166, 10), // "changeToAi"
QT_MOC_LITERAL(16, 177, 4), // "like"
QT_MOC_LITERAL(17, 182, 6), // "unlike"
QT_MOC_LITERAL(18, 189, 8), // "download"
QT_MOC_LITERAL(19, 198, 9) // "addTolist"

    },
    "HistoryItem\0itemClicked\0\0QString&\0"
    "fileName\0aiItemclicked\0likeItemClicked\0"
    "isliked\0isUnliked\0unlikeItemClicked\0"
    "downloadClicked\0isDownLoad\0addToList\0"
    "duration\0removeItem\0changeToAi\0like\0"
    "unlike\0download\0addTolist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HistoryItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    1,   77,    2, 0x06 /* Public */,
       6,    3,   80,    2, 0x06 /* Public */,
       9,    3,   87,    2, 0x06 /* Public */,
      10,    2,   94,    2, 0x06 /* Public */,
      12,    2,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  104,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,
      16,    0,  106,    2, 0x08 /* Private */,
      17,    0,  107,    2, 0x08 /* Private */,
      18,    0,  108,    2, 0x08 /* Private */,
      19,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool, QMetaType::Bool,    4,    7,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool, QMetaType::Bool,    4,    7,    8,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,   11,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HistoryItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HistoryItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->itemClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->aiItemclicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->likeItemClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->unlikeItemClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: _t->downloadClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->addToList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->removeItem(); break;
        case 7: _t->changeToAi(); break;
        case 8: _t->like(); break;
        case 9: _t->unlike(); break;
        case 10: _t->download(); break;
        case 11: _t->addTolist(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HistoryItem::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HistoryItem::itemClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HistoryItem::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HistoryItem::aiItemclicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HistoryItem::*)(QString & , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HistoryItem::likeItemClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (HistoryItem::*)(QString & , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HistoryItem::unlikeItemClicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (HistoryItem::*)(QString & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HistoryItem::downloadClicked)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (HistoryItem::*)(QString & , QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HistoryItem::addToList)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HistoryItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_HistoryItem.data,
    qt_meta_data_HistoryItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HistoryItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HistoryItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HistoryItem.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HistoryItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void HistoryItem::itemClicked(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HistoryItem::aiItemclicked(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HistoryItem::likeItemClicked(QString & _t1, bool _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void HistoryItem::unlikeItemClicked(QString & _t1, bool _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void HistoryItem::downloadClicked(QString & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void HistoryItem::addToList(QString & _t1, QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
