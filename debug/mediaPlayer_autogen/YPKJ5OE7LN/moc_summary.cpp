/****************************************************************************
** Meta object code from reading C++ file 'summary.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/ui/summary.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'summary.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Summary_t {
    QByteArrayData data[19];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Summary_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Summary_t qt_meta_stringdata_Summary = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Summary"
QT_MOC_LITERAL(1, 8, 16), // "on_first_clicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "on_second_clicked"
QT_MOC_LITERAL(4, 44, 16), // "on_third_clicked"
QT_MOC_LITERAL(5, 61, 6), // "addRow"
QT_MOC_LITERAL(6, 68, 7), // "editRow"
QT_MOC_LITERAL(7, 76, 3), // "row"
QT_MOC_LITERAL(8, 80, 9), // "deleteRow"
QT_MOC_LITERAL(9, 90, 19), // "on_like_itemClicked"
QT_MOC_LITERAL(10, 110, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(11, 127, 4), // "item"
QT_MOC_LITERAL(12, 132, 22), // "on_addButton_2_clicked"
QT_MOC_LITERAL(13, 155, 22), // "on_dislike_itemClicked"
QT_MOC_LITERAL(14, 178, 22), // "on_addButton_3_clicked"
QT_MOC_LITERAL(15, 201, 25), // "on_checkBox1_stateChanged"
QT_MOC_LITERAL(16, 227, 5), // "state"
QT_MOC_LITERAL(17, 233, 25), // "on_checkBox2_stateChanged"
QT_MOC_LITERAL(18, 259, 25) // "on_checkBox3_stateChanged"

    },
    "Summary\0on_first_clicked\0\0on_second_clicked\0"
    "on_third_clicked\0addRow\0editRow\0row\0"
    "deleteRow\0on_like_itemClicked\0"
    "QListWidgetItem*\0item\0on_addButton_2_clicked\0"
    "on_dislike_itemClicked\0on_addButton_3_clicked\0"
    "on_checkBox1_stateChanged\0state\0"
    "on_checkBox2_stateChanged\0"
    "on_checkBox3_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Summary[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    1,   83,    2, 0x08 /* Private */,
       8,    1,   86,    2, 0x08 /* Private */,
       9,    1,   89,    2, 0x08 /* Private */,
      12,    0,   92,    2, 0x08 /* Private */,
      13,    1,   93,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    1,   97,    2, 0x08 /* Private */,
      17,    1,  100,    2, 0x08 /* Private */,
      18,    1,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void Summary::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Summary *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_first_clicked(); break;
        case 1: _t->on_second_clicked(); break;
        case 2: _t->on_third_clicked(); break;
        case 3: _t->addRow(); break;
        case 4: _t->editRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->deleteRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_like_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->on_addButton_2_clicked(); break;
        case 8: _t->on_dislike_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->on_addButton_3_clicked(); break;
        case 10: _t->on_checkBox1_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_checkBox2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_checkBox3_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Summary::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Summary.data,
    qt_meta_data_Summary,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Summary::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Summary::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Summary.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Summary::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
