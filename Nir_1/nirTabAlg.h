#ifndef _NIR_TAB_ALGORITHMS_
#define _NIR_TAB_ALGORITHMS_

#include <QtGui>
#include <QString>
#include <QVector>
#include <QList>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>

#include <QStackedLayout>

#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QFont>
#include <QColor>

#include "nirPanelFamily.h"
#include "nirProtButt.h"
#include "nirFilter.h"
#include "nirFamilyInfo.h"

//*************************************************************************
//          GRAPH OF GROUPS
//*************************************************************************
struct GroupGraphNode : public QWidget
{
  GroupGraphNode(int msk, QString s)
  {
    n = 1;
    mask = msk;
    vProtId = new QVector<QString>;
    vProtId->push_back(s);
    flgPainted = 0;
  }
  GroupGraphNode(int msk, QVector<QString>* ps)
  {
    n = ps->size();
    mask = msk;
    vProtId = ps;
    flgPainted = 0;
  }
  GroupGraphNode(int msk)
  {
    n = 0;
    mask = msk;
    vProtId = new QVector<QString>;
    flgPainted = 0;
  }

public:
  bool flgPainted;
  int nGeneration;
  int x;
  int y;
  int n; // number of nodes in node
  int mask;
  QVector<QString>*                vProtId;
  QVector<GroupGraphNode*>    vParent; // node(nd) Parent
  QVector<GroupGraphNode*>    vChild;
  

};

//*************************************************************************
//          PANEL GROUP OF ACTIVITY
//*************************************************************************
class PanelGroupAct : public QWidget
{
  Q_OBJECT
public:
  PanelGroupAct(int mask, int numb, QWidget *parent = 0);
  GroupGraphNode* node;

};


//*************************************************************************
//          TAB0 PREPARE
//*************************************************************************
class TabPrepare : public QWidget
{
  Q_OBJECT
public:
  TabPrepare(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew, QWidget *parent = 0);

private:
  PanelFamily* pPanelFamily;
  QPushButton* pbtnMkGraph;
  QPushButton* pbtnImport;

  QVector<FamilyInfo*> vFamInfo;
  GroupGraphNode* root;
  QVector<int>* vnProt;

  //QVBoxLayout* layoutGroups;
  QWidget*     pfrmGroups;
  QLabel* plActivGroups;
  QVector<PanelGroupAct*> vPanelGroup;
  QVector<QVector<QString>*> vProtId;
  int vvGeneration[7][64];

  void makeGeneration();
  void setMoveCords(int stepx[7], int gapx[7], int& shift, int& stepy);
  void setPanelGroup(GroupGraphNode* node, QWidget* parent);
  void clearNode(GroupGraphNode*);

protected:
    virtual void paintEvent ( QPaintEvent * ) ;
    void paintGraph();

signals:
  void importGraph();

public slots:
  void makeGragh();

};
//*************************************************************************
//          TAB1 ALGORITHM1
//*************************************************************************
class TabAlg1 : public QWidget
{
  Q_OBJECT
public:
  TabAlg1(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew, QWidget *parent = 0); 

  void func();
  
protected:
    virtual void paintEvent ( QPaintEvent * ) ;
    bool flag;
private:
  

signals:

public slots:
  void setButton();


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