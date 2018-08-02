/****************************************************************************
** Meta object code from reading C++ file 'DefineModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MultimeterSimulator/DefineModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DefineModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DefineModel_t {
    QByteArrayData data[15];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DefineModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DefineModel_t qt_meta_stringdata_DefineModel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DefineModel"
QT_MOC_LITERAL(1, 12, 12), // "WIDGET_WIDTH"
QT_MOC_LITERAL(2, 25, 13), // "WIDGET_HEIGHT"
QT_MOC_LITERAL(3, 39, 20), // "multiImg_sourcwWidth"
QT_MOC_LITERAL(4, 60, 21), // "multiImg_sourcwHeight"
QT_MOC_LITERAL(5, 82, 23), // "multiPointerStartXPoint"
QT_MOC_LITERAL(6, 106, 23), // "multiPointerStartYPoint"
QT_MOC_LITERAL(7, 130, 17), // "multiPointerRaius"
QT_MOC_LITERAL(8, 148, 15), // "multiMeterWidth"
QT_MOC_LITERAL(9, 164, 15), // "indicatorXpoint"
QT_MOC_LITERAL(10, 180, 15), // "indicatorYpoint"
QT_MOC_LITERAL(11, 196, 10), // "maskXpoint"
QT_MOC_LITERAL(12, 207, 10), // "maskYpoint"
QT_MOC_LITERAL(13, 218, 9), // "maskWidth"
QT_MOC_LITERAL(14, 228, 10) // "maskHeight"

    },
    "DefineModel\0WIDGET_WIDTH\0WIDGET_HEIGHT\0"
    "multiImg_sourcwWidth\0multiImg_sourcwHeight\0"
    "multiPointerStartXPoint\0multiPointerStartYPoint\0"
    "multiPointerRaius\0multiMeterWidth\0"
    "indicatorXpoint\0indicatorYpoint\0"
    "maskXpoint\0maskYpoint\0maskWidth\0"
    "maskHeight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DefineModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      14,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095401,
       2, QMetaType::Int, 0x00095401,
       3, QMetaType::Int, 0x00095401,
       4, QMetaType::Int, 0x00095401,
       5, QMetaType::Int, 0x00095401,
       6, QMetaType::Int, 0x00095401,
       7, QMetaType::Int, 0x00095401,
       8, QMetaType::Int, 0x00095401,
       9, QMetaType::Int, 0x00095401,
      10, QMetaType::Int, 0x00095401,
      11, QMetaType::Int, 0x00095401,
      12, QMetaType::Int, 0x00095401,
      13, QMetaType::Int, 0x00095401,
      14, QMetaType::Int, 0x00095401,

       0        // eod
};

void DefineModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        DefineModel *_t = static_cast<DefineModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->WIDGET_WIDTH(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->WIDGET_HEIGHT(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->multiImg_sourcwWidth(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->multiImg_sourcwHeight(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->multiPointerStartXPoint(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->multiPointerStartYPoint(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->multiPointerRaius(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->multiMeterWidth(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->indicatorXpoint(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->indicatorYpoint(); break;
        case 10: *reinterpret_cast< int*>(_v) = _t->maskXpoint(); break;
        case 11: *reinterpret_cast< int*>(_v) = _t->maskYpoint(); break;
        case 12: *reinterpret_cast< int*>(_v) = _t->maskWidth(); break;
        case 13: *reinterpret_cast< int*>(_v) = _t->maskHeight(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DefineModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DefineModel.data,
      qt_meta_data_DefineModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DefineModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DefineModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DefineModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DefineModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 14;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
