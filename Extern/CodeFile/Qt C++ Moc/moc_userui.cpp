/****************************************************************************
** Meta object code from reading C++ file 'userui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../userui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_userUI_t {
    QByteArrayData data[21];
    char stringdata0[328];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_userUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_userUI_t qt_meta_stringdata_userUI = {
    {
QT_MOC_LITERAL(0, 0, 6), // "userUI"
QT_MOC_LITERAL(1, 7, 9), // "quit_user"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 15), // "user_show_login"
QT_MOC_LITERAL(4, 34, 15), // "on_quit_clicked"
QT_MOC_LITERAL(5, 50, 19), // "on_t_search_clicked"
QT_MOC_LITERAL(6, 70, 22), // "on_time_search_clicked"
QT_MOC_LITERAL(7, 93, 17), // "on_create_clicked"
QT_MOC_LITERAL(8, 111, 14), // "on_add_clicked"
QT_MOC_LITERAL(9, 126, 17), // "on_remove_clicked"
QT_MOC_LITERAL(10, 144, 22), // "on_quitMeeting_clicked"
QT_MOC_LITERAL(11, 167, 20), // "on_delete_me_clicked"
QT_MOC_LITERAL(12, 188, 21), // "on_delete_all_clicked"
QT_MOC_LITERAL(13, 210, 20), // "on_resetInfo_clicked"
QT_MOC_LITERAL(14, 231, 19), // "on_resetPsd_clicked"
QT_MOC_LITERAL(15, 251, 23), // "on_delete_title_clicked"
QT_MOC_LITERAL(16, 275, 17), // "receive_show_user"
QT_MOC_LITERAL(17, 293, 6), // "string"
QT_MOC_LITERAL(18, 300, 4), // "user"
QT_MOC_LITERAL(19, 305, 10), // "timeUpdate"
QT_MOC_LITERAL(20, 316, 11) // "matchedTime"

    },
    "userUI\0quit_user\0\0user_show_login\0"
    "on_quit_clicked\0on_t_search_clicked\0"
    "on_time_search_clicked\0on_create_clicked\0"
    "on_add_clicked\0on_remove_clicked\0"
    "on_quitMeeting_clicked\0on_delete_me_clicked\0"
    "on_delete_all_clicked\0on_resetInfo_clicked\0"
    "on_resetPsd_clicked\0on_delete_title_clicked\0"
    "receive_show_user\0string\0user\0timeUpdate\0"
    "matchedTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_userUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    1,  113,    2, 0x08 /* Private */,
      19,    0,  116,    2, 0x08 /* Private */,
      20,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

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
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void userUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        userUI *_t = static_cast<userUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->quit_user(); break;
        case 1: _t->user_show_login(); break;
        case 2: _t->on_quit_clicked(); break;
        case 3: _t->on_t_search_clicked(); break;
        case 4: _t->on_time_search_clicked(); break;
        case 5: _t->on_create_clicked(); break;
        case 6: _t->on_add_clicked(); break;
        case 7: _t->on_remove_clicked(); break;
        case 8: _t->on_quitMeeting_clicked(); break;
        case 9: _t->on_delete_me_clicked(); break;
        case 10: _t->on_delete_all_clicked(); break;
        case 11: _t->on_resetInfo_clicked(); break;
        case 12: _t->on_resetPsd_clicked(); break;
        case 13: _t->on_delete_title_clicked(); break;
        case 14: _t->receive_show_user((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 15: _t->timeUpdate(); break;
        case 16: _t->matchedTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (userUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&userUI::quit_user)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (userUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&userUI::user_show_login)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject userUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_userUI.data,
      qt_meta_data_userUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *userUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *userUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_userUI.stringdata0))
        return static_cast<void*>(const_cast< userUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int userUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void userUI::quit_user()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void userUI::user_show_login()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
