#include "nirTabAlg.h"

//*************************************************************************
//          TAB0 PREPARE
//*************************************************************************
TabPrepare::TabPrepare(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew, QWidget *parent)
    :QWidget(parent)
{
  pPanelFamily = new PanelFamily(QBoxLayout::TopToBottom, 0);
  // LAYOUT
  QHBoxLayout* layout = new QHBoxLayout();
  layout->addWidget(pPanelFamily);
  setLayout(layout);
};
//*************************************************************************
//          TAB1 ALGORITHM1
//*************************************************************************
TabAlg1::TabAlg1(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew, QWidget *parent) 
   :QWidget(parent)
{
  // INIT

  // CONNECT

  // LAYOUT
  QHBoxLayout* layout = new QHBoxLayout();
  setLayout(layout);
};
//*************************************************************************
//          TAB2 ALGORITHM2
//*************************************************************************
TabAlg2::TabAlg2(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew, QWidget *parent) 
   :QWidget(parent)
{
  // INIT

  // CONNECT

  // LAYOUT
  QHBoxLayout* layout = new QHBoxLayout();
  setLayout(layout);
};
//*************************************************************************
//          TAB3 ALGORITHM3
//*************************************************************************
TabAlg3::TabAlg3(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew, QWidget *parent) 
   :QWidget(parent)
{
  // INIT

  // CONNECT

  // LAYOUT
  QHBoxLayout* layout = new QHBoxLayout();
  setLayout(layout);
};


//*************************************************************************
//          BASIC TAB WIDGET
//*************************************************************************


MyTabWidgetAlg::MyTabWidgetAlg(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew,QWidget* parent)
    :QTabWidget(parent)
{
  // INIT
  ptab0 = new TabPrepare(vbFamilyNew, vnProtNew);
  ptab1 = new TabAlg1(vbFamilyNew, vnProtNew);
  ptab2 = new TabAlg2(vbFamilyNew, vnProtNew);
  ptab3 = new TabAlg3(vbFamilyNew, vnProtNew);


  //  CONNECTORS
  //connect(ptab4, SIGNAL(sendImport(QString& , QString& )),
  //        ptab5, SLOT(setImport(QString& , QString& )) );
  //connect(ptab4, SIGNAL(sendImport(QString& , QString& )),
  //        this,  SLOT(setView(QString& , QString& )) );
  //connect(ptab5, SIGNAL(setSave(QString& , QString& )),
  //        ptab4, SLOT(loadFromViewTab(QString& , QString& )) );

  //ACTIONS

  // LAYOUT
  this->addTab(ptab0, "Preparation");
  this->addTab(ptab1, "Algorithm1");
  this->addTab(ptab2, "Algorithm2");
  this->addTab(ptab3, "Algorithm3");


  this->setStyleSheet(
      "QTabBar::tab { background: lightgray; color: #303070; padding: 8px;"
                     "border-top-left-radius: 4px;"
                     "border-top-right-radius: 4px;"
                     "min-width: 7em;"
                     "max-width: 7em;} "
      "QTabBar::tab:selected { background: white; border: 1px solid #808090; border-bottom: solid 0px} "
      "QTabBar::tab:!selected { background: lightgray; border: 1px solid #808090;} "
      "QTabWidget::tab-bar { left: 7em; }");
}