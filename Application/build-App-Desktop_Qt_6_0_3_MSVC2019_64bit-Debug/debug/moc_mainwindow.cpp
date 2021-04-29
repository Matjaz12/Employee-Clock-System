/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../App/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[54];
    char stringdata0[571];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 30), // "intialize_employee_scroll_area"
QT_MOC_LITERAL(42, 0), // ""
QT_MOC_LITERAL(43, 36), // "intialize_employee_clock_scro..."
QT_MOC_LITERAL(80, 28), // "create_switch_widget_buttons"
QT_MOC_LITERAL(109, 13), // "set_up_widget"
QT_MOC_LITERAL(123, 11), // "widgetIndex"
QT_MOC_LITERAL(135, 31), // "append_to_employees_scroll_area"
QT_MOC_LITERAL(167, 25), // "std::vector<std::string>&"
QT_MOC_LITERAL(193, 4), // "data"
QT_MOC_LITERAL(198, 36), // "append_to_employee_clock_scro..."
QT_MOC_LITERAL(235, 17), // "create_pop_up_msg"
QT_MOC_LITERAL(253, 11), // "std::string"
QT_MOC_LITERAL(265, 3), // "msg"
QT_MOC_LITERAL(269, 31), // "on_switch_widget_button_clicked"
QT_MOC_LITERAL(301, 30), // "on_submit_deletion_btn_clicked"
QT_MOC_LITERAL(332, 34), // "on_submit_registration_btn_cl..."
QT_MOC_LITERAL(367, 27), // "on_submit_clock_btn_clicked"
QT_MOC_LITERAL(395, 15), // "getAllEmployees"
QT_MOC_LITERAL(411, 24), // "std::vector<std::string>"
QT_MOC_LITERAL(436, 16), // "getEmployeeClock"
QT_MOC_LITERAL(453, 16), // "registerEmployee"
QT_MOC_LITERAL(470, 14), // "deleteEmployee"
QT_MOC_LITERAL(485, 18), // "extractDataFromMsg"
QT_MOC_LITERAL(504, 6), // "rawMsg"
QT_MOC_LITERAL(511, 26), // "clear_employee_scroll_area"
QT_MOC_LITERAL(538, 32) // "clear_employee_clock_scroll_area"

    },
    "MainWindow\0intialize_employee_scroll_area\0"
    "\0intialize_employee_clock_scroll_area\0"
    "create_switch_widget_buttons\0set_up_widget\0"
    "widgetIndex\0append_to_employees_scroll_area\0"
    "std::vector<std::string>&\0data\0"
    "append_to_employee_clock_scroll_area\0"
    "create_pop_up_msg\0std::string\0msg\0"
    "on_switch_widget_button_clicked\0"
    "on_submit_deletion_btn_clicked\0"
    "on_submit_registration_btn_clicked\0"
    "on_submit_clock_btn_clicked\0getAllEmployees\0"
    "std::vector<std::string>\0getEmployeeClock\0"
    "registerEmployee\0deleteEmployee\0"
    "extractDataFromMsg\0rawMsg\0"
    "clear_employee_scroll_area\0"
    "clear_employee_clock_scroll_area"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  122,    2, 0x08,    0 /* Private */,
       3,    0,  123,    2, 0x08,    1 /* Private */,
       4,    0,  124,    2, 0x08,    2 /* Private */,
       5,    1,  125,    2, 0x08,    3 /* Private */,
       7,    1,  128,    2, 0x08,    5 /* Private */,
      10,    1,  131,    2, 0x08,    7 /* Private */,
      11,    1,  134,    2, 0x08,    9 /* Private */,
      14,    0,  137,    2, 0x08,   11 /* Private */,
      15,    0,  138,    2, 0x08,   12 /* Private */,
      16,    0,  139,    2, 0x08,   13 /* Private */,
      17,    0,  140,    2, 0x08,   14 /* Private */,
      18,    0,  141,    2, 0x08,   15 /* Private */,
      20,    1,  142,    2, 0x08,   16 /* Private */,
      21,    1,  145,    2, 0x08,   18 /* Private */,
      22,    1,  148,    2, 0x08,   20 /* Private */,
      23,    1,  151,    2, 0x08,   22 /* Private */,
      25,    0,  154,    2, 0x08,   24 /* Private */,
      26,    0,  155,    2, 0x08,   25 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 19,
    0x80000000 | 19, 0x80000000 | 12,    9,
    0x80000000 | 19, 0x80000000 | 12,    9,
    0x80000000 | 19, 0x80000000 | 12,    9,
    0x80000000 | 12, 0x80000000 | 12,   24,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->intialize_employee_scroll_area(); break;
        case 1: _t->intialize_employee_clock_scroll_area(); break;
        case 2: _t->create_switch_widget_buttons(); break;
        case 3: _t->set_up_widget((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 4: _t->append_to_employees_scroll_area((*reinterpret_cast< std::vector<std::string>(*)>(_a[1]))); break;
        case 5: _t->append_to_employee_clock_scroll_area((*reinterpret_cast< std::vector<std::string>(*)>(_a[1]))); break;
        case 6: _t->create_pop_up_msg((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 7: _t->on_switch_widget_button_clicked(); break;
        case 8: _t->on_submit_deletion_btn_clicked(); break;
        case 9: _t->on_submit_registration_btn_clicked(); break;
        case 10: _t->on_submit_clock_btn_clicked(); break;
        case 11: { std::vector<std::string> _r = _t->getAllEmployees();
            if (_a[0]) *reinterpret_cast< std::vector<std::string>*>(_a[0]) = std::move(_r); }  break;
        case 12: { std::vector<std::string> _r = _t->getEmployeeClock((*reinterpret_cast< std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::vector<std::string>*>(_a[0]) = std::move(_r); }  break;
        case 13: { std::vector<std::string> _r = _t->registerEmployee((*reinterpret_cast< std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::vector<std::string>*>(_a[0]) = std::move(_r); }  break;
        case 14: { std::vector<std::string> _r = _t->deleteEmployee((*reinterpret_cast< std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::vector<std::string>*>(_a[0]) = std::move(_r); }  break;
        case 15: { std::string _r = _t->extractDataFromMsg((*reinterpret_cast< std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->clear_employee_scroll_area(); break;
        case 17: _t->clear_employee_clock_scroll_area(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const unsigned int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::string> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::string> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::string>, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::string>, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::string>, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::string>, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
