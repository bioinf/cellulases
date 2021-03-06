#ifndef _NIR_PANEL_FAMILY_
#define _NIR_PANEL_FAMILY_

#include <QtGui>
#include <QString>
#include <QVector>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>

#include <QStackedLayout>

//*************************************************************************
//          FAMILY BUTTON
//*************************************************************************
class FamilyButton : public QWidget
{
  Q_OBJECT
public:
  FamilyButton(int idFam, QString s, QString sColL, QString sColG, QWidget *parent = 0);

  void changeStateGrey();
  void changeStateLight();
  int           id;

//private:
  QPushButton * pbtn;
  QString       sName;
  int           iState; // 0 - light,
                        // 1 - grey
  QString sColorL;
  QString sColorG;

signals:
  void selectFam(int idFam);

public slots:
  void changeStatePush();
};

//*************************************************************************
//          FAMILY PANEL
//*************************************************************************
class PanelFamily : public QWidget
{

	Q_OBJECT

public:
	PanelFamily(int iLoutDir, bool bMltPush, QWidget *parent = 0, Qt::WFlags flags = 0);

  void            loadFileFamily();
  void            loadFileProtein();
  QVector<int>*   isPushed();
public:

  QVector<int>          viIsPushed;

  QVector<FamilyButton*> vbFamily;
  QVector<int>           vnProt;    // vector of nubmers of proteins in each family

  void changeFamilyId(int id);
private:
  QString                sfFamily;
  int                    idFamCurr; // id of current family;
  QString                sfProt;
  int                    nProtTotal; //number of proteins
  // flags of view
  int                    iLayoutDir; // This type is used to determine the direction of a box layout.
  bool                   bMultiPush; // 0 - single Push; 1 - multiPush

  

signals:
  void setFamily(int idFam, int nProt);

public slots:
  void changeFamily(int id);
  void saveInitProt();

};


#endif
