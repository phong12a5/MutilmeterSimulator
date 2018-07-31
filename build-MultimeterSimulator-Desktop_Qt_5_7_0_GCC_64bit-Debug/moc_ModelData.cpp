/****************************************************************************
** Meta object code from reading C++ file 'ModelData.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MultimeterSimulator/ModelData.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModelData.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CommonObject_t {
    QByteArrayData data[10];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommonObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommonObject_t qt_meta_stringdata_CommonObject = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CommonObject"
QT_MOC_LITERAL(1, 13, 10), // "idxChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 17), // "objectNameChanged"
QT_MOC_LITERAL(4, 43, 17), // "objectTypeChanged"
QT_MOC_LITERAL(5, 61, 18), // "sourceImageChanged"
QT_MOC_LITERAL(6, 80, 3), // "idx"
QT_MOC_LITERAL(7, 84, 10), // "objectName"
QT_MOC_LITERAL(8, 95, 10), // "objectType"
QT_MOC_LITERAL(9, 106, 11) // "sourceImage"

    },
    "CommonObject\0idxChanged\0\0objectNameChanged\0"
    "objectTypeChanged\0sourceImageChanged\0"
    "idx\0objectName\0objectType\0sourceImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommonObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       4,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::Int, 0x00495103,
       7, QMetaType::QString, 0x00495103,
       8, QMetaType::Int, 0x00495103,
       9, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void CommonObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CommonObject *_t = static_cast<CommonObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->idxChanged(); break;
        case 1: _t->objectNameChanged(); break;
        case 2: _t->objectTypeChanged(); break;
        case 3: _t->sourceImageChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CommonObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommonObject::idxChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CommonObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommonObject::objectNameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CommonObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommonObject::objectTypeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CommonObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommonObject::sourceImageChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CommonObject *_t = static_cast<CommonObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->idx(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->objectName(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->objectType(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->sourceImage(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CommonObject *_t = static_cast<CommonObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIdx(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setObjectName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setObjectType(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setSourceImage(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject CommonObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CommonObject.data,
      qt_meta_data_CommonObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CommonObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommonObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CommonObject.stringdata0))
        return static_cast<void*>(const_cast< CommonObject*>(this));
    return QObject::qt_metacast(_clname);
}

int CommonObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CommonObject::idxChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CommonObject::objectNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CommonObject::objectTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void CommonObject::sourceImageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
struct qt_meta_stringdata_MultimeterObject_t {
    QByteArrayData data[12];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MultimeterObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MultimeterObject_t qt_meta_stringdata_MultimeterObject = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MultimeterObject"
QT_MOC_LITERAL(1, 17, 10), // "idxChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 17), // "objectNameChanged"
QT_MOC_LITERAL(4, 47, 17), // "objectTypeChanged"
QT_MOC_LITERAL(5, 65, 14), // "soureBgChanged"
QT_MOC_LITERAL(6, 80, 20), // "sourcePointerChanged"
QT_MOC_LITERAL(7, 101, 3), // "idx"
QT_MOC_LITERAL(8, 105, 10), // "objectName"
QT_MOC_LITERAL(9, 116, 10), // "objectType"
QT_MOC_LITERAL(10, 127, 7), // "soureBg"
QT_MOC_LITERAL(11, 135, 13) // "sourcePointer"

    },
    "MultimeterObject\0idxChanged\0\0"
    "objectNameChanged\0objectTypeChanged\0"
    "soureBgChanged\0sourcePointerChanged\0"
    "idx\0objectName\0objectType\0soureBg\0"
    "sourcePointer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MultimeterObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       5,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,
       6,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::Int, 0x00495103,
       8, QMetaType::QString, 0x00495103,
       9, QMetaType::Int, 0x00495103,
      10, QMetaType::QString, 0x00495103,
      11, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void MultimeterObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MultimeterObject *_t = static_cast<MultimeterObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->idxChanged(); break;
        case 1: _t->objectNameChanged(); break;
        case 2: _t->objectTypeChanged(); break;
        case 3: _t->soureBgChanged(); break;
        case 4: _t->sourcePointerChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultimeterObject::idxChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultimeterObject::objectNameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultimeterObject::objectTypeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultimeterObject::soureBgChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultimeterObject::sourcePointerChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        MultimeterObject *_t = static_cast<MultimeterObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->idx(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->objectName(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->objectType(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->soureBg(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->sourcePointer(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        MultimeterObject *_t = static_cast<MultimeterObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIdx(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setObjectName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setObjectType(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setSoureBg(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setSourcePointer(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject MultimeterObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MultimeterObject.data,
      qt_meta_data_MultimeterObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MultimeterObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MultimeterObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MultimeterObject.stringdata0))
        return static_cast<void*>(const_cast< MultimeterObject*>(this));
    return QObject::qt_metacast(_clname);
}

int MultimeterObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MultimeterObject::idxChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MultimeterObject::objectNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MultimeterObject::objectTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MultimeterObject::soureBgChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MultimeterObject::sourcePointerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
struct qt_meta_stringdata_ModelData_t {
    QByteArrayData data[22];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModelData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModelData_t qt_meta_stringdata_ModelData = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ModelData"
QT_MOC_LITERAL(1, 10, 16), // "resistor1Changed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "resistor2Changed"
QT_MOC_LITERAL(4, 45, 22), // "capictor_normalChanged"
QT_MOC_LITERAL(5, 68, 24), // "capictor_abnormalChanged"
QT_MOC_LITERAL(6, 93, 22), // "cappictor_errorChanged"
QT_MOC_LITERAL(7, 116, 22), // "condutor_normalChanged"
QT_MOC_LITERAL(8, 139, 21), // "condutor_errorChanged"
QT_MOC_LITERAL(9, 161, 12), // "diodeChanged"
QT_MOC_LITERAL(10, 174, 17), // "transistorChanged"
QT_MOC_LITERAL(11, 192, 17), // "multimeterChanged"
QT_MOC_LITERAL(12, 210, 9), // "resistor1"
QT_MOC_LITERAL(13, 220, 9), // "resistor2"
QT_MOC_LITERAL(14, 230, 15), // "capictor_normal"
QT_MOC_LITERAL(15, 246, 17), // "capictor_abnormal"
QT_MOC_LITERAL(16, 264, 15), // "cappictor_error"
QT_MOC_LITERAL(17, 280, 15), // "condutor_normal"
QT_MOC_LITERAL(18, 296, 14), // "condutor_error"
QT_MOC_LITERAL(19, 311, 5), // "diode"
QT_MOC_LITERAL(20, 317, 10), // "transistor"
QT_MOC_LITERAL(21, 328, 10) // "multimeter"

    },
    "ModelData\0resistor1Changed\0\0"
    "resistor2Changed\0capictor_normalChanged\0"
    "capictor_abnormalChanged\0"
    "cappictor_errorChanged\0condutor_normalChanged\0"
    "condutor_errorChanged\0diodeChanged\0"
    "transistorChanged\0multimeterChanged\0"
    "resistor1\0resistor2\0capictor_normal\0"
    "capictor_abnormal\0cappictor_error\0"
    "condutor_normal\0condutor_error\0diode\0"
    "transistor\0multimeter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
      10,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,
       7,    0,   69,    2, 0x06 /* Public */,
       8,    0,   70,    2, 0x06 /* Public */,
       9,    0,   71,    2, 0x06 /* Public */,
      10,    0,   72,    2, 0x06 /* Public */,
      11,    0,   73,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      12, QMetaType::QObjectStar, 0x00495001,
      13, QMetaType::QObjectStar, 0x00495001,
      14, QMetaType::QObjectStar, 0x00495001,
      15, QMetaType::QObjectStar, 0x00495001,
      16, QMetaType::QObjectStar, 0x00495001,
      17, QMetaType::QObjectStar, 0x00495001,
      18, QMetaType::QObjectStar, 0x00495001,
      19, QMetaType::QObjectStar, 0x00495001,
      20, QMetaType::QObjectStar, 0x00495001,
      21, QMetaType::QObjectStar, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,
       9,

       0        // eod
};

void ModelData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModelData *_t = static_cast<ModelData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resistor1Changed(); break;
        case 1: _t->resistor2Changed(); break;
        case 2: _t->capictor_normalChanged(); break;
        case 3: _t->capictor_abnormalChanged(); break;
        case 4: _t->cappictor_errorChanged(); break;
        case 5: _t->condutor_normalChanged(); break;
        case 6: _t->condutor_errorChanged(); break;
        case 7: _t->diodeChanged(); break;
        case 8: _t->transistorChanged(); break;
        case 9: _t->multimeterChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelData::resistor1Changed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelData::resistor2Changed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelData::capictor_normalChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelData::capictor_abnormalChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelData::cappictor_errorChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelData::condutor_normalChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelData::condutor_errorChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelData::diodeChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelData::transistorChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelData::multimeterChanged)) {
                *result = 9;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ModelData *_t = static_cast<ModelData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QObject**>(_v) = _t->resistor1(); break;
        case 1: *reinterpret_cast< QObject**>(_v) = _t->resistor2(); break;
        case 2: *reinterpret_cast< QObject**>(_v) = _t->capictor_normal(); break;
        case 3: *reinterpret_cast< QObject**>(_v) = _t->capictor_abnormal(); break;
        case 4: *reinterpret_cast< QObject**>(_v) = _t->cappictor_error(); break;
        case 5: *reinterpret_cast< QObject**>(_v) = _t->condutor_normal(); break;
        case 6: *reinterpret_cast< QObject**>(_v) = _t->condutor_error(); break;
        case 7: *reinterpret_cast< QObject**>(_v) = _t->diode(); break;
        case 8: *reinterpret_cast< QObject**>(_v) = _t->transistor(); break;
        case 9: *reinterpret_cast< QObject**>(_v) = _t->multimeter(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject ModelData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ModelData.data,
      qt_meta_data_ModelData,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ModelData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelData::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ModelData.stringdata0))
        return static_cast<void*>(const_cast< ModelData*>(this));
    return QObject::qt_metacast(_clname);
}

int ModelData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ModelData::resistor1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ModelData::resistor2Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ModelData::capictor_normalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ModelData::capictor_abnormalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void ModelData::cappictor_errorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void ModelData::condutor_normalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void ModelData::condutor_errorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void ModelData::diodeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void ModelData::transistorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void ModelData::multimeterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
