#ifndef _NIR_TAB_ALIGN_
#define _NIR_TAB_ALIGN_

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
//          BASIC TAB WIDGET ALIGN
//*************************************************************************
class MyTabWidgetAlign:public QTabWidget
{
  Q_OBJECT
public:
  MyTabWidgetAlign(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew,QWidget* parent = 0);

private:

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

#endif // _NIR_TAB_ALIGN_