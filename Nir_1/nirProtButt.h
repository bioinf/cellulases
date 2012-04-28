#ifndef _NIR_PROT_BUTT_
#define _NIR_PROT_BUTT_

#include <QtGui>
#include <QString>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>

//*************************************************************************
//          FAMILY BUTTON
//*************************************************************************
class FamilyButton : public QWidget
{
  Q_OBJECT
public:
  FamilyButton(int idFam, QString s, QString sColL, QString sColG, QWidget *parent = 0);

  void changeStateGrey();
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
//          PROTEIN BUTTON
//*************************************************************************
class ProtButton : public QWidget
{
  Q_OBJECT
public:
  ProtButton(int idFam, QString s, QString sColL, QString sColG, int flagFP, QWidget *parent = 0);

  void changeStateGrey();
  void changeStateLight();
  void changeStateBlack();


  

  QString getName()
  { return QString::number(idFam) + sName; }
  int     getState()
  { return iState; }

  int           iHydrolytic;
//private:
  QPushButton * pbtn;
  QString       sName;
  int           idFam;
  int           iState; // 1 - light,
                        // 0 - grey
  int           iFlagFP; // 0 - Family;
                         // 1 - Protein
  
  QString       sColorL;
  QString       sColorG;

signals:
  void selectFam(int idFam, int iState);

public slots:
  void changeStatePush();
};

#endif // _NIR_PROT_BUTT_