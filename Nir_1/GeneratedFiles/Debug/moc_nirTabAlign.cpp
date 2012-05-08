/****************************************************************************
** Meta object code from reading C++ file 'nirTabAlign.h'
**
** Created: Mon 7. May 20:00:43 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../nirTabAlign.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nirTabAlign.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TabAlignment[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   46,   13,   13, 0x0a,
      92,   13,   13,   13, 0x0a,
     113,   13,   13,   13, 0x0a,
     124,   13,   13,   13, 0x0a,
     137,   13,   13,   13, 0x0a,
     149,   14,   13,   13, 0x0a,
     168,   13,   13,   13, 0x0a,
     183,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TabAlignment[] = {
    "TabAlignment\0\0,\0sendImport(QString&,QString&)\0"
    "sRes,sNote\0loadFromViewTab(QString&,QString&)\0"
    "setFromFile(QString)\0setAlign()\0"
    "resetAlign()\0saveAlign()\0selectAll(int,int)\0"
    "setFilter(int)\0prepareImport()\0"
};

void TabAlignment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TabAlignment *_t = static_cast<TabAlignment *>(_o);
        switch (_id) {
        case 0: _t->sendImport((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->loadFromViewTab((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->setFromFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setAlign(); break;
        case 4: _t->resetAlign(); break;
        case 5: _t->saveAlign(); break;
        case 6: _t->selectAll((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->setFilter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->prepareImport(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TabAlignment::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TabAlignment::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TabAlignment,
      qt_meta_data_TabAlignment, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TabAlignment::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TabAlignment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TabAlignment::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TabAlignment))
        return static_cast<void*>(const_cast< TabAlignment*>(this));
    return QWidget::qt_metacast(_clname);
}

int TabAlignment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void TabAlignment::sendImport(QString & _t1, QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_TabImport[] = {

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
      22,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   10,   10,   10, 0x0a,
      60,   11,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TabImport[] = {
    "TabImport\0\0sRes,sNote\0setSave(QString&,QString&)\0"
    "pushSave()\0setImport(QString&,QString&)\0"
};

void TabImport::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TabImport *_t = static_cast<TabImport *>(_o);
        switch (_id) {
        case 0: _t->setSave((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->pushSave(); break;
        case 2: _t->setImport((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TabImport::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TabImport::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TabImport,
      qt_meta_data_TabImport, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TabImport::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TabImport::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TabImport::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TabImport))
        return static_cast<void*>(const_cast< TabImport*>(this));
    return QWidget::qt_metacast(_clname);
}

int TabImport::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void TabImport::setSave(QString & _t1, QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_MyTabWidgetAlign[] = {

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
      30,   18,   17,   17, 0x05,
      52,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   18,   17,   17, 0x0a,
      82,   17,   17,   17, 0x0a,
     104,   98,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyTabWidgetAlign[] = {
    "MyTabWidgetAlign\0\0idFam,nProt\0"
    "changeToTab1(int,int)\0saveFam()\0"
    "changeTab1(int,int)\0saveFamToMain()\0"
    "s1,s2\0setView(QString&,QString&)\0"
};

void MyTabWidgetAlign::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyTabWidgetAlign *_t = static_cast<MyTabWidgetAlign *>(_o);
        switch (_id) {
        case 0: _t->changeToTab1((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->saveFam(); break;
        case 2: _t->changeTab1((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->saveFamToMain(); break;
        case 4: _t->setView((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyTabWidgetAlign::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyTabWidgetAlign::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_MyTabWidgetAlign,
      qt_meta_data_MyTabWidgetAlign, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyTabWidgetAlign::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyTabWidgetAlign::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyTabWidgetAlign::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyTabWidgetAlign))
        return static_cast<void*>(const_cast< MyTabWidgetAlign*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int MyTabWidgetAlign::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
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
void MyTabWidgetAlign::changeToTab1(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyTabWidgetAlign::saveFam()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
