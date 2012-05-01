#ifndef _NIR_TAB_MAIN_
#define _NIR_TAB_MAIN_

#include <QtGui>
#include <QString>
#include <QVector>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>

#include <QStackedLayout>



#include "nirTabFamily.h"
#include "nirTabAlign.h"


//*************************************************************************
//          BASIC TAB WIDGET
//*************************************************************************
class MyTabWidgetMain:public QTabWidget
{
  Q_OBJECT
public:
  MyTabWidgetMain(QWidget* parent = 0);

private:
  //Family
  MyTabWidgetFamily*  ptab1;
  //Align
  MyTabWidgetAlign*   ptab2;
  //Algorithms
  //TabEditFamily*  ptab3;

  QVector<FamilyButton*>* vbFamilyNew;
  QVector<int>* vnProtNew;



signals:
  void changeToTab1(int idFam, int nProt);
  void saveFam();

public slots:


};



#endif