/****************************************************************************
** Meta object code from reading C++ file 'nirProtButt.h'
**
** Created: Tue 10. Apr 11:08:15 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nirProtButt.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nirProtButt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FamilyButton[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FamilyButton[] = {
    "FamilyButton\0\0idFam\0selectFam(int)\0"
    "changeStatePush()\0"
};

void FamilyButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FamilyButton *_t = static_cast<FamilyButton *>(_o);
        switch (_id) {
        case 0: _t->selectFam((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeStatePush(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FamilyButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FamilyButton::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FamilyButton,
      qt_meta_data_FamilyButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FamilyButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FamilyButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FamilyButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FamilyButton))
        return static_cast<void*>(const_cast< FamilyButton*>(this));
    return QWidget::qt_metacast(_clname);
}

int FamilyButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void FamilyButton::selectFam(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_ProtButton[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ProtButton[] = {
    "ProtButton\0\0idFam,iState\0selectFam(int,int)\0"
    "changeStatePush()\0"
};

void ProtButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ProtButton *_t = static_cast<ProtButton *>(_o);
        switch (_id) {
        case 0: _t->selectFam((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->changeStatePush(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ProtButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ProtButton::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ProtButton,
      qt_meta_data_ProtButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ProtButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ProtButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ProtButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProtButton))
        return static_cast<void*>(const_cast< ProtButton*>(this));
    return QWidget::qt_metacast(_clname);
}

int ProtButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ProtButton::selectFam(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE