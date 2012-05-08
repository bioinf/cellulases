#include "nirTabMain.h"

//*************************************************************************
//          BASIC TAB WIDGET MAIN
//*************************************************************************


MyTabWidgetMain::MyTabWidgetMain(QWidget* parent)
    :QTabWidget(parent)
{
  // INIT
  ptab1 = new MyTabWidgetFamily();
  vbFamilyNew = ptab1->vbFamilyNew;
  vnProtNew   = ptab1->vnProtNew;
  //Align
  ptab2 = new MyTabWidgetAlign(vbFamilyNew, vnProtNew);
  ptab3 = new MyTabWidgetAlg(vbFamilyNew, vnProtNew);

  //ACTIONS

  // LAYOUT
  this->addTab(ptab1, "Family");
  this->addTab(ptab2, "Align");
  this->addTab(ptab3, "Algorithms");


  this->setStyleSheet(
      //"QTabBar { background-color: rgb(255,213,191);"
      "QTabBar::tab { background: lightgray; color: #303070; padding: 8px;"
                     "border-top-left-radius: 4px;"
                     "border-top-right-radius: 4px;"
                     "min-width: 7em;"
                     "max-width: 7em;} "
      "QTabBar::tab:selected { background: white; border: 1px solid #808090; border-bottom: solid 0px} "
      "QTabBar::tab:!selected { background: lightgray; border: 1px solid #808090;} "
      "QTabWidget::tab-bar { left: 0em; }");

  
}
