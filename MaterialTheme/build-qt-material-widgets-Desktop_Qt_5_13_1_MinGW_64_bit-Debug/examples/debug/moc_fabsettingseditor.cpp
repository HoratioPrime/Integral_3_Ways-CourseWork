/****************************************************************************
** Meta object code from reading C++ file 'fabsettingseditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../qt-material-widgets/examples/fabsettingseditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fabsettingseditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FloatingActionButtonSettingsEditor_t {
    QByteArrayData data[5];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FloatingActionButtonSettingsEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FloatingActionButtonSettingsEditor_t qt_meta_stringdata_FloatingActionButtonSettingsEditor = {
    {
QT_MOC_LITERAL(0, 0, 34), // "FloatingActionButtonSettingsE..."
QT_MOC_LITERAL(1, 35, 9), // "setupForm"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 12), // "updateWidget"
QT_MOC_LITERAL(4, 59, 11) // "selectColor"

    },
    "FloatingActionButtonSettingsEditor\0"
    "setupForm\0\0updateWidget\0selectColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FloatingActionButtonSettingsEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x09 /* Protected */,
       3,    0,   30,    2, 0x09 /* Protected */,
       4,    0,   31,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FloatingActionButtonSettingsEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FloatingActionButtonSettingsEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setupForm(); break;
        case 1: _t->updateWidget(); break;
        case 2: _t->selectColor(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject FloatingActionButtonSettingsEditor::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FloatingActionButtonSettingsEditor.data,
    qt_meta_data_FloatingActionButtonSettingsEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FloatingActionButtonSettingsEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FloatingActionButtonSettingsEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FloatingActionButtonSettingsEditor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FloatingActionButtonSettingsEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
