/****************************************************************************
** Meta object code from reading C++ file 'nirTabFamily.h'
**
** Created: Mon 7. May 20:00:43 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nirTabFamily.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nirTabFamily.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TabNewProtein[] = {

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
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      27,   25,   14,   14, 0x0a,
      47,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TabNewProtein[] = {
    "TabNewProtein\0\0saveFam()\0,\0"
    "changeById(int,int)\0saveProt()\0"
};

void TabNewProtein::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TabNewProtein *_t = static_cast<TabNewProtein *>(_o);
        switch (_id) {
        case 0: _t->saveFam(); break;
        case 1: _t->changeById((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->saveProt(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TabNewProtein::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TabNewProtein::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TabNewProtein,
      qt_meta_data_TabNewProtein, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TabNewProtein::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TabNewProtein::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TabNewProtein::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TabNewProtein))
        return static_cast<void*>(const_cast< TabNewProtein*>(this));
    return QWidget::qt_metacast(_clname);
}

int TabNewProtein::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void TabNewProtein::saveFam()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_TabEditProtein[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   16,   15,   15, 0x0a,
      38,   15,   15,   15, 0x0a,
      64,   55,   15,   15, 0x0a,
      82,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TabEditProtein[] = {
    "TabEditProtein\0\0,\0changeById(int,int)\0"
    "changeNumbProt()\0nameProt\0openProt(QString)\0"
    "saveProt()\0"
};

void TabEditProtein::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TabEditProtein *_t = static_cast<TabEditProtein *>(_o);
        switch (_id) {
        case 0: _t->changeById((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->changeNumbProt(); break;
        case 2: _t->openProt((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->saveProt(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TabEditProtein::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TabEditProtein::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TabEditProtein,
      qt_meta_data_TabEditProtein, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TabEditProtein::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TabEditProtein::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TabEditProtein::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TabEditProtein))
        return static_cast<void*>(const_cast< TabEditProtein*>(this));
    return QWidget::qt_metacast(_clname);
}

int TabEditProtein::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_TabEditFamily[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   15,   14,   14, 0x0a,
      37,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TabEditFamily[] = {
    "TabEditFamily\0\0,\0changeById(int,int)\0"
    "saveProt()\0"
};

void TabEditFamily::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TabEditFamily *_t = static_cast<TabEditFamily *>(_o);
        switch (_id) {
        case 0: _t->changeById((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->saveProt(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TabEditFamily::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TabEditFamily::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TabEditFamily,
      qt_meta_data_TabEditFamily, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TabEditFamily::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TabEditFamily::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TabEditFamily::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TabEditFamily))
        return static_cast<void*>(const_cast< TabEditFamily*>(this));
    return QWidget::qt_metacast(_clname);
}

int TabEditFamily::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
static const uint qt_meta_data_MyTabWidgetFamily[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   19,   18,   18, 0x05,
      53,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,   19,   18,   18, 0x0a,
      83,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyTabWidgetFamily[] = {
    "MyTabWidgetFamily\0\0idFam,nProt\0"
    "changeToTab1(int,int)\0saveFam()\0"
    "changeTab1(int,int)\0saveFamToMain()\0"
};

void MyTabWidgetFamily::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyTabWidgetFamily *_t = static_cast<MyTabWidgetFamily *>(_o);
        switch (_id) {
        case 0: _t->changeToTab1((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->saveFam(); break;
        case 2: _t->changeTab1((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->saveFamToMain(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyTabWidgetFamily::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyTabWidgetFamily::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_MyTabWidgetFamily,
      qt_meta_data_MyTabWidgetFamily, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyTabWidgetFamily::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyTabWidgetFamily::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyTabWidgetFamily::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyTabWidgetFamily))
        return static_cast<void*>(const_cast< MyTabWidgetFamily*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int MyTabWidgetFamily::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MyTabWidgetFamily::changeToTab1(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyTabWidgetFamily::saveFam()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
