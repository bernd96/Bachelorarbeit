/****************************************************************************
** Meta object code from reading C++ file 'trajectory_msg_display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/fub_trajectory_msgs_rviz_plugin/src/trajectory_msg_display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trajectory_msg_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_rviz__TrajectoryDisplay_t {
    QByteArrayData data[5];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rviz__TrajectoryDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rviz__TrajectoryDisplay_t qt_meta_stringdata_rviz__TrajectoryDisplay = {
    {
QT_MOC_LITERAL(0, 0, 23), // "rviz::TrajectoryDisplay"
QT_MOC_LITERAL(1, 24, 18), // "updateBufferLength"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 15), // "updateLineWidth"
QT_MOC_LITERAL(4, 60, 12) // "updateOffset"

    },
    "rviz::TrajectoryDisplay\0updateBufferLength\0"
    "\0updateLineWidth\0updateOffset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rviz__TrajectoryDisplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void rviz::TrajectoryDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TrajectoryDisplay *_t = static_cast<TrajectoryDisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateBufferLength(); break;
        case 1: _t->updateLineWidth(); break;
        case 2: _t->updateOffset(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject rviz::TrajectoryDisplay::staticMetaObject = {
    { &MessageFilterDisplay<fub_trajectory_msgs::Trajectory>::staticMetaObject, qt_meta_stringdata_rviz__TrajectoryDisplay.data,
      qt_meta_data_rviz__TrajectoryDisplay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *rviz::TrajectoryDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rviz::TrajectoryDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_rviz__TrajectoryDisplay.stringdata0))
        return static_cast<void*>(const_cast< TrajectoryDisplay*>(this));
    return MessageFilterDisplay<fub_trajectory_msgs::Trajectory>::qt_metacast(_clname);
}

int rviz::TrajectoryDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MessageFilterDisplay<fub_trajectory_msgs::Trajectory>::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
