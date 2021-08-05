/****************************************************************************
** Meta object code from reading C++ file 'defectpreview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Client/defectpreview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'defectpreview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DefectPreview_t {
    QByteArrayData data[19];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DefectPreview_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DefectPreview_t qt_meta_stringdata_DefectPreview = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DefectPreview"
QT_MOC_LITERAL(1, 14, 18), // "currentPanelChange"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 13), // "QList<QPoint>"
QT_MOC_LITERAL(4, 48, 5), // "coord"
QT_MOC_LITERAL(5, 54, 17), // "QVector<QPolygon>"
QT_MOC_LITERAL(6, 72, 14), // "showNextCircle"
QT_MOC_LITERAL(7, 87, 22), // "on_forward_btn_clicked"
QT_MOC_LITERAL(8, 110, 21), // "on_behind_btn_clicked"
QT_MOC_LITERAL(9, 132, 20), // "on_again_btn_clicked"
QT_MOC_LITERAL(10, 153, 18), // "on_set_btn_clicked"
QT_MOC_LITERAL(11, 172, 19), // "on_page_btn_clicked"
QT_MOC_LITERAL(12, 192, 19), // "on_find_btn_clicked"
QT_MOC_LITERAL(13, 212, 19), // "on_exit_btn_clicked"
QT_MOC_LITERAL(14, 232, 21), // "on_before_btn_clicked"
QT_MOC_LITERAL(15, 254, 20), // "on_after_btn_clicked"
QT_MOC_LITERAL(16, 275, 17), // "on_up_btn_clicked"
QT_MOC_LITERAL(17, 293, 22), // "on_refrush_btn_clicked"
QT_MOC_LITERAL(18, 316, 21) // "on_modify_btn_clicked"

    },
    "DefectPreview\0currentPanelChange\0\0"
    "QList<QPoint>\0coord\0QVector<QPolygon>\0"
    "showNextCircle\0on_forward_btn_clicked\0"
    "on_behind_btn_clicked\0on_again_btn_clicked\0"
    "on_set_btn_clicked\0on_page_btn_clicked\0"
    "on_find_btn_clicked\0on_exit_btn_clicked\0"
    "on_before_btn_clicked\0on_after_btn_clicked\0"
    "on_up_btn_clicked\0on_refrush_btn_clicked\0"
    "on_modify_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DefectPreview[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   84,    2, 0x06 /* Public */,
       6,    1,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,
      17,    0,  104,    2, 0x08 /* Private */,
      18,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, 0x80000000 | 5,    4,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
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

       0        // eod
};

void DefectPreview::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DefectPreview *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentPanelChange((*reinterpret_cast< const QList<QPoint>(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const QVector<QPolygon>(*)>(_a[3]))); break;
        case 1: _t->showNextCircle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_forward_btn_clicked(); break;
        case 3: _t->on_behind_btn_clicked(); break;
        case 4: _t->on_again_btn_clicked(); break;
        case 5: _t->on_set_btn_clicked(); break;
        case 6: _t->on_page_btn_clicked(); break;
        case 7: _t->on_find_btn_clicked(); break;
        case 8: _t->on_exit_btn_clicked(); break;
        case 9: _t->on_before_btn_clicked(); break;
        case 10: _t->on_after_btn_clicked(); break;
        case 11: _t->on_up_btn_clicked(); break;
        case 12: _t->on_refrush_btn_clicked(); break;
        case 13: _t->on_modify_btn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QPoint> >(); break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QPolygon> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DefectPreview::*)(const QList<QPoint> & , const int , const QVector<QPolygon> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DefectPreview::currentPanelChange)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DefectPreview::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DefectPreview::showNextCircle)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DefectPreview::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DefectPreview.data,
    qt_meta_data_DefectPreview,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DefectPreview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DefectPreview::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DefectPreview.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DefectPreview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void DefectPreview::currentPanelChange(const QList<QPoint> & _t1, const int _t2, const QVector<QPolygon> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DefectPreview::showNextCircle(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
