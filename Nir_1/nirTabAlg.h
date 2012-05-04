#ifndef _NIR_TAB_ALGORITHMS_
#define _NIR_TAB_ALGORITHMS_

#include <QtGui>
#include <QString>
#include <QVector>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>

#include <QStackedLayout>

#include "nirPanelFamily.h"
#include "nirProtButt.h"
#include "nirFilter.h"




//*************************************************************************
//          TAB0 PREPARE
//*************************************************************************
class TabPrepare : public QWidget
{
  Q_OBJECT
public:
  TabPrepare(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew, QWidget *parent = 0);

private:
  PanelFamily *pPanelFamily;

signals:

public slots:


};
//*************************************************************************
//          TAB1 ALGORITHM1
//*************************************************************************
class TabAlg1 : public QWidget
{
  Q_OBJECT
public:
  TabAlg1(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew, QWidget *parent = 0); 
  

private:

signals:

public slots:


};
//*************************************************************************
//          TAB2 ALGORITHM2
//*************************************************************************
class TabAlg2 : public QWidget
{
  Q_OBJECT
public:
  TabAlg2(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew, QWidget *parent = 0);

private:

signals:

public slots:


};
//*************************************************************************
//          TAB3 ALGORITHM3
//*************************************************************************
class TabAlg3 : public QWidget
{
  Q_OBJECT
public:
  TabAlg3(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew, QWidget *parent = 0);

private:

signals:

public slots:


};

//*************************************************************************
//          BASIC TAB WIDGET ALGORITHMS
//*************************************************************************
class MyTabWidgetAlg:public QTabWidget
{
  Q_OBJECT
public:
  MyTabWidgetAlg(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew,QWidget* parent = 0);

private:

  TabPrepare*   ptab0;
  TabAlg1*      ptab1;
  TabAlg2*      ptab2;
  TabAlg3*      ptab3;


signals:

public slots:

};

#endif