/****************************************************************************
** Meta object code from reading C++ file 'settingwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Client/settingwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_settingWidget_t {
    QByteArrayData data[22];
    char stringdata0[369];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_settingWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_settingWidget_t qt_meta_stringdata_settingWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "settingWidget"
QT_MOC_LITERAL(1, 14, 16), // "defectSizeChange"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "send_message"
QT_MOC_LITERAL(4, 45, 11), // "std::string"
QT_MOC_LITERAL(5, 57, 26), // "send_warning_generator_msg"
QT_MOC_LITERAL(6, 84, 11), // "update_bank"
QT_MOC_LITERAL(7, 96, 20), // "on_cancelBtn_clicked"
QT_MOC_LITERAL(8, 117, 18), // "on_saveBtn_clicked"
QT_MOC_LITERAL(9, 136, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(10, 161, 4), // "arg1"
QT_MOC_LITERAL(11, 166, 23), // "on_top_text_textChanged"
QT_MOC_LITERAL(12, 190, 23), // "on_bot_text_textChanged"
QT_MOC_LITERAL(13, 214, 22), // "on_lineEdit_textEdited"
QT_MOC_LITERAL(14, 237, 24), // "on_lineEdit_2_textEdited"
QT_MOC_LITERAL(15, 262, 15), // "tableItem_click"
QT_MOC_LITERAL(16, 278, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(17, 296, 21), // "on_checkBox_2_toggled"
QT_MOC_LITERAL(18, 318, 7), // "checked"
QT_MOC_LITERAL(19, 326, 7), // "init_Ui"
QT_MOC_LITERAL(20, 334, 16), // "parse_force_mode"
QT_MOC_LITERAL(21, 351, 17) // "warning_generator"

    },
    "settingWidget\0defectSizeChange\0\0"
    "send_message\0std::string\0"
    "send_warning_generator_msg\0update_bank\0"
    "on_cancelBtn_clicked\0on_saveBtn_clicked\0"
    "on_checkBox_stateChanged\0arg1\0"
    "on_top_text_textChanged\0on_bot_text_textChanged\0"
    "on_lineEdit_textEdited\0on_lineEdit_2_textEdited\0"
    "tableItem_click\0QTableWidgetItem*\0"
    "on_checkBox_2_toggled\0checked\0init_Ui\0"
    "parse_force_mode\0warning_generator"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_settingWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       3,    3,   87,    2, 0x06 /* Public */,
       5,    2,   94,    2, 0x06 /* Public */,
       6,    1,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  102,    2, 0x08 /* Private */,
       8,    0,  103,    2, 0x08 /* Private */,
       9,    1,  104,    2, 0x08 /* Private */,
      11,    0,  107,    2, 0x08 /* Private */,
      12,    0,  108,    2, 0x08 /* Private */,
      13,    1,  109,    2, 0x08 /* Private */,
      14,    1,  112,    2, 0x08 /* Private */,
      15,    1,  115,    2, 0x08 /* Private */,
      17,    1,  118,    2, 0x08 /* Private */,
      19,    2,  121,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    2,    2,
    QMetaType::Void, QMetaType::QStringList,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 21,    2,    2,

       0        // eod
};

void settingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<settingWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->defectSizeChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->send_message((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const bool(*)>(_a[3]))); break;
        case 2: _t->send_warning_generator_msg((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 3: _t->update_bank((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->on_cancelBtn_clicked(); break;
        case 5: _t->on_saveBtn_clicked(); break;
        case 6: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_top_text_textChanged(); break;
        case 8: _t->on_bot_text_textChanged(); break;
        case 9: _t->on_lineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_lineEdit_2_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->tableItem_click((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 12: _t->on_checkBox_2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->init_Ui((*reinterpret_cast< const parse_force_mode(*)>(_a[1])),(*reinterpret_cast< const warning_generator(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (settingWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&settingWidget::defectSizeChange)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (settingWidget::*)(const std::string & , const std::string & , const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&settingWidget::send_message)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (settingWidget::*)(const std::string & , const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&settingWidget::send_warning_generator_msg)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (settingWidget::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&settingWidget::update_bank)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject settingWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_settingWidget.data,
    qt_meta_data_settingWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *settingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *settingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_settingWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int settingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void settingWidget::defectSizeChange(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void settingWidget::send_message(const std::string & _t1, const std::string & _t2, const bool & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void settingWidget::send_warning_generator_msg(const std::string & _t1, const std::string & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void settingWidget::update_bank(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
