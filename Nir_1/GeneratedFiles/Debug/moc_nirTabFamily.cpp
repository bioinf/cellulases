/****************************************************************************
** Meta object code from reading C++ file 'nirTabFamily.h'
**
** Created: Thu 17. May 02:26:24 2012
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
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      37,   25,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   25,   14,   14, 0x0a,
      79,   77,   14,   14, 0x0a,
      99,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TabNewProtein[] = {
    "TabNewProtein\0\0saveFam()\0idFam,nProt\0"
    "changeFamId(int,int)\0changeFam(int,int)\0"
    ",\0changeById(int,int)\0saveProt()\0"
};

void TabNewProtein::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TabNewProtein *_t = static_cast<TabNewProtein *>(_o);
        switch (_id) {
        case 0: _t->saveFam(); break;
        case 1: _t->changeFamId((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->changeFam((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->changeById((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->saveProt(); break;
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TabNewProtein::saveFam()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TabNewProtein::changeFamId(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_TabEditProtein[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   16,   15,   15, 0x0a,
      70,   68,   15,   15, 0x0a,
      90,   15,   15,   15, 0x0a,
     116,  107,   15,   15, 0x0a,
     134,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TabEditProtein[] = {
    "TabEditProtein\0\0idFam,nProt\0"
    "changeFamId(int,int)\0changeFam(int,int)\0"
    ",\0changeById(int,int)\0changeNumbProt()\0"
    "nameProt\0openProt(QString)\0saveProt()\0"
};

void TabEditProtein::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TabEditProtein *_t = static_cast<TabEditProtein *>(_o);
        switch (_id) {
        case 0: _t->changeFamId((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->changeFam((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->changeById((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->changeNumbProt(); break;
        case 4: _t->openProt((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->saveProt(); break;
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TabEditProtein::changeFamId(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_TabEditFamily[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   15,   14,   14, 0x0a,
      69,   67,   14,   14, 0x0a,
      89,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TabEditFamily[] = {
    "TabEditFamily\0\0idFam,nProt\0"
    "changeFamId(int,int)\0changeFam(int,int)\0"
    ",\0changeById(int,int)\0saveProt()\0"
};

void TabEditFamily::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TabEditFamily *_t = static_cast<TabEditFamily *>(_o);
        switch (_id) {
        case 0: _t->changeFamId((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->changeFam((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->changeById((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->saveProt(); break;
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TabEditFamily::changeFamId(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
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
      52,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   19,   18,   18, 0x0a,
      81,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyTabWidgetFamily[] = {
    "MyTabWidgetFamily\0\0idFam,nProt\0"
    "changeFamId(int,int)\0saveFam()\0"
    "changeFam(int,int)\0saveFamToMain()\0"
};

void MyTabWidgetFamily::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyTabWidgetFamily *_t = static_cast<MyTabWidgetFamily *>(_o);
        switch (_id) {
        case 0: _t->changeFamId((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->saveFam(); break;
        case 2: _t->changeFam((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
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
void MyTabWidgetFamily::changeFamId(int _t1, int _t2)
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
