/****************************************************************************
** Meta object code from reading C++ file 'jobdlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Client/jobdlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jobdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JobDlg_t {
    QByteArrayData data[17];
    char stringdata0[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JobDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JobDlg_t qt_meta_stringdata_JobDlg = {
    {
QT_MOC_LITERAL(0, 0, 6), // "JobDlg"
QT_MOC_LITERAL(1, 7, 10), // "updateBank"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 20), // "on_searchBtn_clicked"
QT_MOC_LITERAL(4, 40, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 62, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 86, 26), // "on_tableWidget_itemClicked"
QT_MOC_LITERAL(7, 113, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(8, 131, 4), // "item"
QT_MOC_LITERAL(9, 136, 33), // "on_tableWidget_currentItemCha..."
QT_MOC_LITERAL(10, 170, 7), // "current"
QT_MOC_LITERAL(11, 178, 8), // "previous"
QT_MOC_LITERAL(12, 187, 22), // "on_lineEdit_textEdited"
QT_MOC_LITERAL(13, 210, 4), // "arg1"
QT_MOC_LITERAL(14, 215, 28), // "on_tableWidget_2_itemClicked"
QT_MOC_LITERAL(15, 244, 11), // "getInitInfo"
QT_MOC_LITERAL(16, 256, 12) // "showSubItems"

    },
    "JobDlg\0updateBank\0\0on_searchBtn_clicked\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_tableWidget_itemClicked\0QTableWidgetItem*\0"
    "item\0on_tableWidget_currentItemChanged\0"
    "current\0previous\0on_lineEdit_textEdited\0"
    "arg1\0on_tableWidget_2_itemClicked\0"
    "getInitInfo\0showSubItems"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JobDlg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   67,    2, 0x08 /* Private */,
       4,    0,   68,    2, 0x08 /* Private */,
       5,    0,   69,    2, 0x08 /* Private */,
       6,    1,   70,    2, 0x08 /* Private */,
       9,    2,   73,    2, 0x08 /* Private */,
      12,    1,   78,    2, 0x08 /* Private */,
      14,    1,   81,    2, 0x08 /* Private */,
      15,    1,   84,    2, 0x0a /* Public */,
      16,    1,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,   10,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void JobDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JobDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateBank((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->on_searchBtn_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_tableWidget_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->on_tableWidget_currentItemChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTableWidgetItem*(*)>(_a[2]))); break;
        case 6: _t->on_lineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_tableWidget_2_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->getInitInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->showSubItems((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JobDlg::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JobDlg::updateBank)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject JobDlg::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_JobDlg.data,
    qt_meta_data_JobDlg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *JobDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JobDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JobDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int JobDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void JobDlg::updateBank(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
