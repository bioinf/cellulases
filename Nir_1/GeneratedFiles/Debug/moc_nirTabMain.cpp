/****************************************************************************
** Meta object code from reading C++ file 'nirTabMain.h'
**
** Created: Mon 7. May 20:00:42 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nirTabMain.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nirTabMain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyTabWidgetMain[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   17,   16,   16, 0x05,
      51,   16,   16,   16, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_MyTabWidgetMain[] = {
    "MyTabWidgetMain\0\0idFam,nProt\0"
    "changeToTab1(int,int)\0saveFam()\0"
};

void MyTabWidgetMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyTabWidgetMain *_t = static_cast<MyTabWidgetMain *>(_o);
        switch (_id) {
        case 0: _t->changeToTab1((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->saveFam(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyTabWidgetMain::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyTabWidgetMain::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_MyTabWidgetMain,
      qt_meta_data_MyTabWidgetMain, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyTabWidgetMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyTabWidgetMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyTabWidgetMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyTabWidgetMain))
        return static_cast<void*>(const_cast< MyTabWidgetMain*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int MyTabWidgetMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MyTabWidgetMain::changeToTab1(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyTabWidgetMain::saveFam()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
