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

  //ACTIONS

  // LAYOUT
  this->addTab(ptab1, "Family");
  this->addTab(ptab2, "Align");


  this->setStyleSheet(
      "QTabBar::tab { background: gray; color: white; padding: 10px; } "
      "QTabBar::tab:selected { background: lightgray; } "
      /*"QTabWidget::pane { border: 0; } "*/
      /*"QWidget { background: lightgray; } "*/);
}
