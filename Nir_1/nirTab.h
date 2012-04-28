#ifndef _NIR_TAB_
#define _NIR_TAB_



#include <QtGui>
#include <QString>
#include <QVector>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>

 #include <QStackedLayout>

#include "nirProtButt.h"
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
//          TAB4 ALIGNMENT
//*************************************************************************
class TabAlignment : public QWidget
{
  Q_OBJECT
public:
  TabAlignment(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew, QWidget *parent = 0);

  void loadHydrolytic();
  void loadHystory();

private:

  QTextEdit*         ptEditFasta;
  QTextEdit*         ptEditAlign;
  QTextEdit*         ptEditNote;
  QLabel*            plFam;
  QPushButton*       pbtnSave;
  QPushButton*       pbtnImport;
  QPushButton*       pbtnFasta;
  QPushButton*       pbtnReFasta;

  QVector<FamilyButton*>* pvbFamily;
  QVector<int>* pvnProt;
  QVector<QVector<ProtButton*>*> vvbProt; // vector of vector of Protein Buttons
  QVector<ProtButton*>  vbFamily;
  QVector<QVBoxLayout*> vLayoutProts;

  int nFam;

  FilterWidget* pFilter;
  QLabel*       plAlingCode;

  QString sAlignFile;

  QVector<QString> vAlignUsed;
  QComboBox*       cbAlignUsed;
  QString          sFileHystory;


signals:
  void sendImport(QString& , QString& );

public slots:
  void loadFromViewTab(QString& sRes, QString& sNote);
  void setFromFile(const QString &);
  void setAlign();
  void resetAlign();
  void saveAlign();

  void selectAll(int, int );
  void setFilter(int);

  void prepareImport();

};

//*************************************************************************
//          TAB5 IMPORT
//*************************************************************************
class TabImport : public QWidget
{
  Q_OBJECT
public:
  TabImport(QWidget *parent = 0);

private:


  QTextEdit*         ptEditRes;
  QTextEdit*         ptEditNote;

  QPushButton*       pbtnSave;


signals:
  void setSave(QString& sRes, QString& sNote);

public slots:
  void pushSave()
  {
    emit setSave(ptEditRes->toPlainText(), ptEditNote->toPlainText());
  }
  void setImport(QString& sRes, QString& sNote)
  {
    ptEditRes->clear();
    ptEditNote->clear();
    ptEditRes->setText(sRes);
    ptEditNote->setText(sNote);
  }

};

//*************************************************************************
//          BASIC TAB WIDGET
//*************************************************************************
class MyTabWidget:public QTabWidget
{
  Q_OBJECT
public:
  MyTabWidget(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew,QWidget* parent = 0);

private:
  TabNewProtein*  ptab1;
  TabEditProtein* ptab2;
  TabEditFamily*  ptab3;
  TabAlignment*   ptab4;
  TabImport*      ptab5;


signals:
  void changeToTab1(int idFam, int nProt);
  void saveFam();

public slots:
  void changeTab1(int idFam, int nProt)
  { emit changeToTab1(idFam, nProt);};
  void saveFamToMain()
  { emit saveFam();};
  void setView(QString& s1, QString& s2)
  {
    this->setCurrentIndex(4);
  }

};


#endif // _NIR_TAB_