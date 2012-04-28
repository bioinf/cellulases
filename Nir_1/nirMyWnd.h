#ifndef _NIR_MY_WND_
#define _NIR_MY_WND_

#include <QtGui/QMainWindow>
#include <QtGui>
#include <QVector>
#include <QString>
#include <QFile>
#include <QTextStream>

#include "nirTab.h"


//*************************************************************************
//          MAIN WINDOW
//*************************************************************************
class MyWnd : public QWidget
{

	Q_OBJECT

public:
	MyWnd(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MyWnd();

  void loadFileFamily();
  void loadFileProtein();
private:

  QString                sfFamily;
  QVector<FamilyButton*> vbFamily;
  QVector<int>           vnProt;    // vector of nubmers of proteins in each family
  int                    idFamCurr; // id of current family;

  QString                sfProt;
  int                    nProtTotal; //number of proteins

  MyTabWidget*           pTabWidget;

signals:
  void setFamily(int idFam, int nProt);

public slots:
  void changeFamily(int id);
  void saveInitProt();

};



#endif // _NIR_MY_WND_
