/****************************************************************************
** Meta object code from reading C++ file 'adminhome.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../16Cycles/adminhome.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminhome.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdminHome_t {
    QByteArrayData data[8];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminHome_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminHome_t qt_meta_stringdata_AdminHome = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AdminHome"
QT_MOC_LITERAL(1, 10, 28), // "on_adminLogOutButton_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 26), // "on_staffViewButton_clicked"
QT_MOC_LITERAL(4, 67, 25), // "on_staffAddButton_clicked"
QT_MOC_LITERAL(5, 93, 28), // "on_staffRemoveButton_clicked"
QT_MOC_LITERAL(6, 122, 28), // "on_staffUpdateButton_clicked"
QT_MOC_LITERAL(7, 151, 30) // "on_resetPasswordButton_clicked"

    },
    "AdminHome\0on_adminLogOutButton_clicked\0"
    "\0on_staffViewButton_clicked\0"
    "on_staffAddButton_clicked\0"
    "on_staffRemoveButton_clicked\0"
    "on_staffUpdateButton_clicked\0"
    "on_resetPasswordButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminHome[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AdminHome::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdminHome *_t = static_cast<AdminHome *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_adminLogOutButton_clicked(); break;
        case 1: _t->on_staffViewButton_clicked(); break;
        case 2: _t->on_staffAddButton_clicked(); break;
        case 3: _t->on_staffRemoveButton_clicked(); break;
        case 4: _t->on_staffUpdateButton_clicked(); break;
        case 5: _t->on_resetPasswordButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AdminHome::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AdminHome.data,
      qt_meta_data_AdminHome,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AdminHome::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminHome::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminHome.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AdminHome::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
