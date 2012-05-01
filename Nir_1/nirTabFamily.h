#ifndef _NIR_TAB_FAMILY_
#define _NIR_TAB_FAMILY_



#include <QtGui>
#include <QString>
#include <QVector>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>

 #include <QStackedLayout>

#include "nirProtButt.h"
#include "nirPanelFamily.h"
#include "nirFilter.h"

//*************************************************************************
//          TAB1 NEW PROTEIN
//*************************************************************************
class TabNewProtein : public QWidget
{
  Q_OBJECT
public:
  TabNewProtein(QWidget *parent = 0);

  int           idFam;
  int           nProt;

private:
  QTextEdit*    ptEditProt;
  QLabel*       plProt;
  QTextEdit*    ptEditNote;
  QLabel*       plNote;
  QPushButton*  pbtnSave;

  //QAction*      actSave;

signals:
  void saveFam();


public slots:
  void changeById(int , int );
  void saveProt();
};
//*************************************************************************
//          TAB2 EDIT PROTEIN
//*************************************************************************
class TabEditProtein : public QWidget
{
  Q_OBJECT
public:
  TabEditProtein(QWidget *parent = 0);

  int           idFam;
  int           nProt;

private:
  QTextEdit*         ptEditProt;
  QLabel*            plProt;
  QTextEdit*         ptEditNote;
  QLabel*            plNote;
  QPushButton*       pbtnSave;
  QComboBox*         cbProtein;

  QString            sNameProt;

signals:

public slots:
  void changeById(int , int );
  void changeNumbProt();
  void openProt(const QString & nameProt);
  void saveProt();

};
//*************************************************************************
//          TAB3 EDIT FAMILY
//*************************************************************************
class TabEditFamily : public QWidget
{
  Q_OBJECT
public:
  TabEditFamily(QWidget *parent = 0);
  int                idFam;
  int                nProt;

private:
  QTextEdit*         ptEditFam;
  QLabel*            plFam;
  QPushButton*       pbtnSave;
  QString            sNameProt;

signals:

public slots:
  void changeById(int , int );
  void saveProt();

};

//*************************************************************************
//          BASIC TAB WIDGET FAMILY
//*************************************************************************
class MyTabWidgetFamily:public QTabWidget
{
  Q_OBJECT
public:
  MyTabWidgetFamily(QWidget* parent = 0);

private:
  PanelFamily*    pPanelFamily;
  QTabWidget*     ptwidget;

  TabNewProtein*  ptab1;
  TabEditProtein* ptab2;
  TabEditFamily*  ptab3;

public:
  QVector<FamilyButton*>* vbFamilyNew;
  QVector<int>* vnProtNew;


signals:
  void changeToTab1(int idFam, int nProt);
  void saveFam();

public slots:
  void changeTab1(int idFam, int nProt)
  { emit changeToTab1(idFam, nProt);};
  void saveFamToMain()
  { emit saveFam();};

};


#endif // _NIR_TAB_FAMILY_