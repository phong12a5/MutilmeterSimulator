/****************************************************************************
** Meta object code from reading C++ file 'ModelData.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MultimeterSimulator/ModelData.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModelData.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommonObject_t {
    QByteArrayData data[24];
    char stringdata0[373];
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
QT_MOC_LITERAL(6, 80, 20), // "positivePointChanged"
QT_MOC_LITERAL(7, 101, 20), // "negativePointChanged"
QT_MOC_LITERAL(8, 122, 18), // "extendPointChanged"
QT_MOC_LITERAL(9, 141, 23), // "posConnectedWireChanged"
QT_MOC_LITERAL(10, 165, 24), // "negaConnectedWireChanged"
QT_MOC_LITERAL(11, 190, 23), // "extConnectedWireChanged"
QT_MOC_LITERAL(12, 214, 17), // "onOffStateChanged"
QT_MOC_LITERAL(13, 232, 3), // "idx"
QT_MOC_LITERAL(14, 236, 10), // "objectName"
QT_MOC_LITERAL(15, 247, 10), // "objectType"
QT_MOC_LITERAL(16, 258, 11), // "sourceImage"
QT_MOC_LITERAL(17, 270, 13), // "positivePoint"
QT_MOC_LITERAL(18, 284, 13), // "negativePoint"
QT_MOC_LITERAL(19, 298, 11), // "extendPoint"
QT_MOC_LITERAL(20, 310, 16), // "posConnectedWire"
QT_MOC_LITERAL(21, 327, 17), // "negaConnectedWire"
QT_MOC_LITERAL(22, 345, 16), // "extConnectedWire"
QT_MOC_LITERAL(23, 362, 10) // "onOffState"

    },
    "CommonObject\0idxChanged\0\0objectNameChanged\0"
    "objectTypeChanged\0sourceImageChanged\0"
    "positivePointChanged\0negativePointChanged\0"
    "extendPointChanged\0posConnectedWireChanged\0"
    "negaConnectedWireChanged\0"
    "extConnectedWireChanged\0onOffStateChanged\0"
    "idx\0objectName\0objectType\0sourceImage\0"
    "positivePoint\0negativePoint\0extendPoint\0"
    "posConnectedWire\0negaConnectedWire\0"
    "extConnectedWire\0onOffState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommonObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
      11,   80, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    0,   72,    2, 0x06 /* Public */,
       6,    0,   73,    2, 0x06 /* Public */,
       7,    0,   74,    2, 0x06 /* Public */,
       8,    0,   75,    2, 0x06 /* Public */,
       9,    0,   76,    2, 0x06 /* Public */,
      10,    0,   77,    2, 0x06 /* Public */,
      11,    0,   78,    2, 0x06 /* Public */,
      12,    0,   79,    2, 0x06 /* Public */,

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
    QMetaType::Void,

 // properties: name, type, flags
      13, QMetaType::Int, 0x00495103,
      14, QMetaType::QString, 0x00495103,
      15, QMetaType::Int, 0x00495103,
      16, QMetaType::QString, 0x00495103,
      17, QMetaType::QVariant, 0x00495001,
      18, QMetaType::QVariant, 0x00495001,
      19, QMetaType::QVariant, 0x00495001,
      20, QMetaType::Int, 0x00495103,
      21, QMetaType::Int, 0x00495103,
      22, QMetaType::Int, 0x00495103,
      23, QMetaType::Bool, 0x00495103,

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
      10,

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
        case 4: _t->positivePointChanged(); break;
        case 5: _t->negativePointChanged(); break;
        case 6: _t->extendPointChanged(); break;
        case 7: _t->posConnectedWireChanged(); break;
        case 8: _t->negaConnectedWireChanged(); break;
        case 9: _t->extConnectedWireChanged(); break;
        case 10: _t->onOffStateChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CommonObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommonObject::idxChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CommonObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommonObject::objectNameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CommonObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommonObject::objectTypeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CommonObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommonObject::sourceImageChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CommonObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommonObject::positivePointChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (CommonObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommonObject::negativePointChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (CommonObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommonObject::extendPointChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (CommonObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommonObject::posConnectedWireChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (CommonObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommonObject::negaConnectedWireChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (CommonObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommonObject::extConnectedWireChanged)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (CommonObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommonObject::onOffStateChanged)) {
                *result = 10;
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
        case 4: *reinterpret_cast< QVariant*>(_v) = _t->positivePoint(); break;
        case 5: *reinterpret_cast< QVariant*>(_v) = _t->negativePoint(); break;
        case 6: *reinterpret_cast< QVariant*>(_v) = _t->extendPoint(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->posConnectedWire(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->negaConnectedWire(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->extConnectedWire(); break;
        case 10: *reinterpret_cast< bool*>(_v) = _t->onOffState(); break;
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
        case 7: _t->setPosConnectedWire(*reinterpret_cast< int*>(_v)); break;
        case 8: _t->setNegaConnectedWire(*reinterpret_cast< int*>(_v)); break;
        case 9: _t->setExtConnectedWire(*reinterpret_cast< int*>(_v)); break;
        case 10: _t->setOnOffState(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject CommonObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CommonObject.data,
      qt_meta_data_CommonObject,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CommonObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommonObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CommonObject.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CommonObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 11;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CommonObject::idxChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CommonObject::objectNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CommonObject::objectTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CommonObject::sourceImageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CommonObject::positivePointChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CommonObject::negativePointChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void CommonObject::extendPointChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void CommonObject::posConnectedWireChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void CommonObject::negaConnectedWireChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void CommonObject::extConnectedWireChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void CommonObject::onOffStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
struct qt_meta_stringdata_MultimeterObject_t {
    QByteArrayData data[30];
    char stringdata0[469];
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
QT_MOC_LITERAL(7, 101, 22), // "activedPositiveChanged"
QT_MOC_LITERAL(8, 124, 22), // "activedNegativeChanged"
QT_MOC_LITERAL(9, 147, 19), // "redSourceImgChanged"
QT_MOC_LITERAL(10, 167, 21), // "blackSourceImgChanged"
QT_MOC_LITERAL(11, 189, 22), // "currentRotationChanged"
QT_MOC_LITERAL(12, 212, 19), // "nextRotationChanged"
QT_MOC_LITERAL(13, 232, 23), // "runningAnimationChanged"
QT_MOC_LITERAL(14, 256, 24), // "animationDurationChanged"
QT_MOC_LITERAL(15, 281, 3), // "idx"
QT_MOC_LITERAL(16, 285, 10), // "objectName"
QT_MOC_LITERAL(17, 296, 10), // "objectType"
QT_MOC_LITERAL(18, 307, 7), // "soureBg"
QT_MOC_LITERAL(19, 315, 13), // "sourcePointer"
QT_MOC_LITERAL(20, 329, 15), // "activedPositive"
QT_MOC_LITERAL(21, 345, 15), // "activedNegative"
QT_MOC_LITERAL(22, 361, 12), // "redSourceImg"
QT_MOC_LITERAL(23, 374, 14), // "blackSourceImg"
QT_MOC_LITERAL(24, 389, 10), // "maskSource"
QT_MOC_LITERAL(25, 400, 4), // "line"
QT_MOC_LITERAL(26, 405, 15), // "currentRotation"
QT_MOC_LITERAL(27, 421, 12), // "nextRotation"
QT_MOC_LITERAL(28, 434, 16), // "runningAnimation"
QT_MOC_LITERAL(29, 451, 17) // "animationDuration"

    },
    "MultimeterObject\0idxChanged\0\0"
    "objectNameChanged\0objectTypeChanged\0"
    "soureBgChanged\0sourcePointerChanged\0"
    "activedPositiveChanged\0activedNegativeChanged\0"
    "redSourceImgChanged\0blackSourceImgChanged\0"
    "currentRotationChanged\0nextRotationChanged\0"
    "runningAnimationChanged\0"
    "animationDurationChanged\0idx\0objectName\0"
    "objectType\0soureBg\0sourcePointer\0"
    "activedPositive\0activedNegative\0"
    "redSourceImg\0blackSourceImg\0maskSource\0"
    "line\0currentRotation\0nextRotation\0"
    "runningAnimation\0animationDuration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MultimeterObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
      15,   92, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    0,   83,    2, 0x06 /* Public */,
       7,    0,   84,    2, 0x06 /* Public */,
       8,    0,   85,    2, 0x06 /* Public */,
       9,    0,   86,    2, 0x06 /* Public */,
      10,    0,   87,    2, 0x06 /* Public */,
      11,    0,   88,    2, 0x06 /* Public */,
      12,    0,   89,    2, 0x06 /* Public */,
      13,    0,   90,    2, 0x06 /* Public */,
      14,    0,   91,    2, 0x06 /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      15, QMetaType::Int, 0x00495103,
      16, QMetaType::QString, 0x00495103,
      17, QMetaType::Int, 0x00495103,
      18, QMetaType::QString, 0x00495103,
      19, QMetaType::QString, 0x00495103,
      20, QMetaType::Bool, 0x00495103,
      21, QMetaType::Bool, 0x00495103,
      22, QMetaType::QString, 0x00495103,
      23, QMetaType::QString, 0x00495103,
      24, QMetaType::QString, 0x00095401,
      25, QMetaType::QString, 0x00095401,
      26, QMetaType::Int, 0x00495103,
      27, QMetaType::Int, 0x00495103,
      28, QMetaType::Bool, 0x00495103,
      29, QMetaType::Int, 0x00495103,

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
       0,
       0,
       9,
      10,
      11,
      12,

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
        case 5: _t->activedPositiveChanged(); break;
        case 6: _t->activedNegativeChanged(); break;
        case 7: _t->redSourceImgChanged(); break;
        case 8: _t->blackSourceImgChanged(); break;
        case 9: _t->currentRotationChanged(); break;
        case 10: _t->nextRotationChanged(); break;
        case 11: _t->runningAnimationChanged(); break;
        case 12: _t->animationDurationChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultimeterObject::idxChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultimeterObject::objectNameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultimeterObject::objectTypeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultimeterObject::soureBgChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultimeterObject::sourcePointerChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultimeterObject::activedPositiveChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultimeterObject::activedNegativeChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultimeterObject::redSourceImgChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultimeterObject::blackSourceImgChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultimeterObject::currentRotationChanged)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultimeterObject::nextRotationChanged)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultimeterObject::runningAnimationChanged)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (MultimeterObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultimeterObject::animationDurationChanged)) {
                *result = 12;
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
        case 5: *reinterpret_cast< bool*>(_v) = _t->activedPositive(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->activedNegative(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->redSourceImg(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->blackSourceImg(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->maskSource(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->line(); break;
        case 11: *reinterpret_cast< int*>(_v) = _t->currentRotation(); break;
        case 12: *reinterpret_cast< int*>(_v) = _t->nextRotation(); break;
        case 13: *reinterpret_cast< bool*>(_v) = _t->runningAnimation(); break;
        case 14: *reinterpret_cast< int*>(_v) = _t->animationDuration(); break;
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
        case 5: _t->setActivedPositive(*reinterpret_cast< bool*>(_v)); break;
        case 6: _t->setActivedNegative(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setRedSourceImg(*reinterpret_cast< QString*>(_v)); break;
        case 8: _t->setBlackSourceImg(*reinterpret_cast< QString*>(_v)); break;
        case 11: _t->setCurrentRotation(*reinterpret_cast< int*>(_v)); break;
        case 12: _t->setNextRotation(*reinterpret_cast< int*>(_v)); break;
        case 13: _t->setRunningAnimation(*reinterpret_cast< bool*>(_v)); break;
        case 14: _t->setAnimationDuration(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject MultimeterObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MultimeterObject.data,
      qt_meta_data_MultimeterObject,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MultimeterObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MultimeterObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MultimeterObject.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MultimeterObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 15;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 15;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 15;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 15;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 15;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MultimeterObject::idxChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MultimeterObject::objectNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MultimeterObject::objectTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MultimeterObject::soureBgChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MultimeterObject::sourcePointerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MultimeterObject::activedPositiveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MultimeterObject::activedNegativeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MultimeterObject::redSourceImgChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void MultimeterObject::blackSourceImgChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void MultimeterObject::currentRotationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void MultimeterObject::nextRotationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void MultimeterObject::runningAnimationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void MultimeterObject::animationDurationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}
struct qt_meta_stringdata_ModelData_t {
    QByteArrayData data[47];
    char stringdata0[721];
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
QT_MOC_LITERAL(11, 192, 13), // "redLedChanged"
QT_MOC_LITERAL(12, 206, 15), // "greenLedChanged"
QT_MOC_LITERAL(13, 222, 17), // "multimeterChanged"
QT_MOC_LITERAL(14, 240, 18), // "pointerModeChanged"
QT_MOC_LITERAL(15, 259, 21), // "activedDevicedChanged"
QT_MOC_LITERAL(16, 281, 16), // "listModelChanged"
QT_MOC_LITERAL(17, 298, 19), // "fingerSourceChanged"
QT_MOC_LITERAL(18, 318, 11), // "logoChanged"
QT_MOC_LITERAL(19, 330, 19), // "rstBtnSourceChanged"
QT_MOC_LITERAL(20, 350, 23), // "onCapNormalTimerTrigged"
QT_MOC_LITERAL(21, 374, 25), // "onCapAbnormalTimerTrigged"
QT_MOC_LITERAL(22, 400, 19), // "updateActivedDevice"
QT_MOC_LITERAL(23, 420, 7), // "actived"
QT_MOC_LITERAL(24, 428, 5), // "index"
QT_MOC_LITERAL(25, 434, 16), // "posConnectedWire"
QT_MOC_LITERAL(26, 451, 17), // "negaConnectedWire"
QT_MOC_LITERAL(27, 469, 16), // "extConnectedWire"
QT_MOC_LITERAL(28, 486, 9), // "resistor1"
QT_MOC_LITERAL(29, 496, 9), // "resistor2"
QT_MOC_LITERAL(30, 506, 15), // "capictor_normal"
QT_MOC_LITERAL(31, 522, 17), // "capictor_abnormal"
QT_MOC_LITERAL(32, 540, 15), // "cappictor_error"
QT_MOC_LITERAL(33, 556, 15), // "condutor_normal"
QT_MOC_LITERAL(34, 572, 14), // "condutor_error"
QT_MOC_LITERAL(35, 587, 5), // "diode"
QT_MOC_LITERAL(36, 593, 10), // "transistor"
QT_MOC_LITERAL(37, 604, 10), // "multimeter"
QT_MOC_LITERAL(38, 615, 8), // "greenLed"
QT_MOC_LITERAL(39, 624, 6), // "redLed"
QT_MOC_LITERAL(40, 631, 11), // "pointerMode"
QT_MOC_LITERAL(41, 643, 14), // "activedDeviced"
QT_MOC_LITERAL(42, 658, 9), // "listModel"
QT_MOC_LITERAL(43, 668, 15), // "QList<QObject*>"
QT_MOC_LITERAL(44, 684, 12), // "fingerSource"
QT_MOC_LITERAL(45, 697, 10), // "logoSource"
QT_MOC_LITERAL(46, 708, 12) // "rstBtnSource"

    },
    "ModelData\0resistor1Changed\0\0"
    "resistor2Changed\0capictor_normalChanged\0"
    "capictor_abnormalChanged\0"
    "cappictor_errorChanged\0condutor_normalChanged\0"
    "condutor_errorChanged\0diodeChanged\0"
    "transistorChanged\0redLedChanged\0"
    "greenLedChanged\0multimeterChanged\0"
    "pointerModeChanged\0activedDevicedChanged\0"
    "listModelChanged\0fingerSourceChanged\0"
    "logoChanged\0rstBtnSourceChanged\0"
    "onCapNormalTimerTrigged\0"
    "onCapAbnormalTimerTrigged\0updateActivedDevice\0"
    "actived\0index\0posConnectedWire\0"
    "negaConnectedWire\0extConnectedWire\0"
    "resistor1\0resistor2\0capictor_normal\0"
    "capictor_abnormal\0cappictor_error\0"
    "condutor_normal\0condutor_error\0diode\0"
    "transistor\0multimeter\0greenLed\0redLed\0"
    "pointerMode\0activedDeviced\0listModel\0"
    "QList<QObject*>\0fingerSource\0logoSource\0"
    "rstBtnSource"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
      18,  150, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      18,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x06 /* Public */,
       3,    0,  120,    2, 0x06 /* Public */,
       4,    0,  121,    2, 0x06 /* Public */,
       5,    0,  122,    2, 0x06 /* Public */,
       6,    0,  123,    2, 0x06 /* Public */,
       7,    0,  124,    2, 0x06 /* Public */,
       8,    0,  125,    2, 0x06 /* Public */,
       9,    0,  126,    2, 0x06 /* Public */,
      10,    0,  127,    2, 0x06 /* Public */,
      11,    0,  128,    2, 0x06 /* Public */,
      12,    0,  129,    2, 0x06 /* Public */,
      13,    0,  130,    2, 0x06 /* Public */,
      14,    0,  131,    2, 0x06 /* Public */,
      15,    0,  132,    2, 0x06 /* Public */,
      16,    0,  133,    2, 0x06 /* Public */,
      17,    0,  134,    2, 0x06 /* Public */,
      18,    0,  135,    2, 0x06 /* Public */,
      19,    0,  136,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    0,  137,    2, 0x0a /* Public */,
      21,    0,  138,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      22,    5,  139,    2, 0x02 /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   23,   24,   25,   26,   27,

 // properties: name, type, flags
      28, QMetaType::QObjectStar, 0x00495001,
      29, QMetaType::QObjectStar, 0x00495001,
      30, QMetaType::QObjectStar, 0x00495001,
      31, QMetaType::QObjectStar, 0x00495001,
      32, QMetaType::QObjectStar, 0x00495001,
      33, QMetaType::QObjectStar, 0x00495001,
      34, QMetaType::QObjectStar, 0x00495001,
      35, QMetaType::QObjectStar, 0x00495001,
      36, QMetaType::QObjectStar, 0x00495001,
      37, QMetaType::QObjectStar, 0x00495001,
      38, QMetaType::QObjectStar, 0x00495001,
      39, QMetaType::QObjectStar, 0x00495001,
      40, QMetaType::Int, 0x00495103,
      41, QMetaType::Int, 0x00495103,
      42, 0x80000000 | 43, 0x00495009,
      44, QMetaType::QString, 0x00495001,
      45, QMetaType::QString, 0x00495001,
      46, QMetaType::QString, 0x00495001,

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
      11,
      10,
       9,
      12,
      13,
      14,
      15,
      16,
      17,

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
        case 9: _t->redLedChanged(); break;
        case 10: _t->greenLedChanged(); break;
        case 11: _t->multimeterChanged(); break;
        case 12: _t->pointerModeChanged(); break;
        case 13: _t->activedDevicedChanged(); break;
        case 14: _t->listModelChanged(); break;
        case 15: _t->fingerSourceChanged(); break;
        case 16: _t->logoChanged(); break;
        case 17: _t->rstBtnSourceChanged(); break;
        case 18: _t->onCapNormalTimerTrigged(); break;
        case 19: _t->onCapAbnormalTimerTrigged(); break;
        case 20: _t->updateActivedDevice((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::resistor1Changed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::resistor2Changed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::capictor_normalChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::capictor_abnormalChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::cappictor_errorChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::condutor_normalChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::condutor_errorChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::diodeChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::transistorChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::redLedChanged)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::greenLedChanged)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::multimeterChanged)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::pointerModeChanged)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::activedDevicedChanged)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::listModelChanged)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::fingerSourceChanged)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::logoChanged)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (ModelData::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModelData::rstBtnSourceChanged)) {
                *result = 17;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
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
        case 10: *reinterpret_cast< QObject**>(_v) = _t->greenLed(); break;
        case 11: *reinterpret_cast< QObject**>(_v) = _t->redLed(); break;
        case 12: *reinterpret_cast< int*>(_v) = _t->pointerMode(); break;
        case 13: *reinterpret_cast< int*>(_v) = _t->activedDeviced(); break;
        case 14: *reinterpret_cast< QList<QObject*>*>(_v) = _t->listModel(); break;
        case 15: *reinterpret_cast< QString*>(_v) = _t->fingerSource(); break;
        case 16: *reinterpret_cast< QString*>(_v) = _t->logoSource(); break;
        case 17: *reinterpret_cast< QString*>(_v) = _t->rstBtnSource(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ModelData *_t = static_cast<ModelData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 12: _t->setPointerMode(*reinterpret_cast< int*>(_v)); break;
        case 13: _t->setActivedDeviced(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ModelData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ModelData.data,
      qt_meta_data_ModelData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ModelData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModelData.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ModelData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 18;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ModelData::resistor1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ModelData::resistor2Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ModelData::capictor_normalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ModelData::capictor_abnormalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ModelData::cappictor_errorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ModelData::condutor_normalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ModelData::condutor_errorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void ModelData::diodeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void ModelData::transistorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void ModelData::redLedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void ModelData::greenLedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void ModelData::multimeterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void ModelData::pointerModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void ModelData::activedDevicedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void ModelData::listModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void ModelData::fingerSourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void ModelData::logoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void ModelData::rstBtnSourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
