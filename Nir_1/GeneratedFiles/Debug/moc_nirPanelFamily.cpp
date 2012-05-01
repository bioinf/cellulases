/****************************************************************************
** Meta object code from reading C++ file 'nirPanelFamily.h'
**
** Created: Wed 2. May 01:42:17 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nirPanelFamily.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nirPanelFamily.h' doesn't include <QObject>."
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
static const uint qt_meta_data_PanelFamily[] = {

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
      25,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,   44,   12,   12, 0x0a,
      65,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PanelFamily[] = {
    "PanelFamily\0\0idFam,nProt\0setFamily(int,int)\0"
    "id\0changeFamily(int)\0saveInitProt()\0"
};

void PanelFamily::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PanelFamily *_t = static_cast<PanelFamily *>(_o);
        switch (_id) {
        case 0: _t->setFamily((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->changeFamily((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->saveInitProt(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PanelFamily::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PanelFamily::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PanelFamily,
      qt_meta_data_PanelFamily, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PanelFamily::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PanelFamily::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PanelFamily::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PanelFamily))
        return static_cast<void*>(const_cast< PanelFamily*>(this));
    return QWidget::qt_metacast(_clname);
}

int PanelFamily::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PanelFamily::setFamily(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
