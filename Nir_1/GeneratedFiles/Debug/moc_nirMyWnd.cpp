/****************************************************************************
** Meta object code from reading C++ file 'nirMyWnd.h'
**
** Created: Mon 9. Apr 13:02:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nirMyWnd.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nirMyWnd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyWnd[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,    7,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   38,    6,    6, 0x0a,
      59,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyWnd[] = {
    "MyWnd\0\0idFam,nProt\0setFamily(int,int)\0"
    "id\0changeFamily(int)\0saveInitProt()\0"
};

void MyWnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyWnd *_t = static_cast<MyWnd *>(_o);
        switch (_id) {
        case 0: _t->setFamily((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->changeFamily((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->saveInitProt(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyWnd::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyWnd::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyWnd,
      qt_meta_data_MyWnd, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyWnd::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyWnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyWnd::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyWnd))
        return static_cast<void*>(const_cast< MyWnd*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyWnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MyWnd::setFamily(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
