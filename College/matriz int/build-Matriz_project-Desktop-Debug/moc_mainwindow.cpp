/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Matriz_project/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "on_criarA_botton_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 24), // "on_criarB_botton_clicked"
QT_MOC_LITERAL(4, 62, 35), // "on_comboBox_OpoesMatrizes_act..."
QT_MOC_LITERAL(5, 98, 4), // "arg1"
QT_MOC_LITERAL(6, 103, 15), // "on_soma_clicked"
QT_MOC_LITERAL(7, 119, 26), // "on_multiplicacao_activated"
QT_MOC_LITERAL(8, 146, 5), // "index"
QT_MOC_LITERAL(9, 152, 23), // "on_transopsta_activated"
QT_MOC_LITERAL(10, 176, 20), // "on_Escalar_activated"
QT_MOC_LITERAL(11, 197, 21), // "on_potencia_activated"
QT_MOC_LITERAL(12, 219, 20), // "on_subtracao_clicked"
QT_MOC_LITERAL(13, 240, 26), // "on_tabWidget_tabBarClicked"
QT_MOC_LITERAL(14, 267, 27) // "on_tableView_Result_clicked"

    },
    "MainWindow\0on_criarA_botton_clicked\0"
    "\0on_criarB_botton_clicked\0"
    "on_comboBox_OpoesMatrizes_activated\0"
    "arg1\0on_soma_clicked\0on_multiplicacao_activated\0"
    "index\0on_transopsta_activated\0"
    "on_Escalar_activated\0on_potencia_activated\0"
    "on_subtracao_clicked\0on_tabWidget_tabBarClicked\0"
    "on_tableView_Result_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    1,   71,    2, 0x08 /* Private */,
       6,    0,   74,    2, 0x08 /* Private */,
       7,    1,   75,    2, 0x08 /* Private */,
       9,    1,   78,    2, 0x08 /* Private */,
      10,    1,   81,    2, 0x08 /* Private */,
      11,    1,   84,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    1,   88,    2, 0x08 /* Private */,
      14,    1,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QModelIndex,    8,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_criarA_botton_clicked(); break;
        case 1: _t->on_criarB_botton_clicked(); break;
        case 2: _t->on_comboBox_OpoesMatrizes_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_soma_clicked(); break;
        case 4: _t->on_multiplicacao_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_transopsta_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_Escalar_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_potencia_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_subtracao_clicked(); break;
        case 9: _t->on_tabWidget_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_tableView_Result_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_END_MOC_NAMESPACE
