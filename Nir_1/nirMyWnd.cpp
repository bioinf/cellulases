#include "nirMyWnd.h"

//*************************************************************************
//          MAIN WINDOW
//*************************************************************************
MyWnd::MyWnd(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
  //INIT
  ptabwMain = new MyTabWidgetMain();
  
  // CONNECT
  
  // ACTIONS

  // LAYOUT
  QBoxLayout* layout = new QBoxLayout(QBoxLayout::TopToBottom);
  layout->addWidget(ptabwMain);
  setLayout(layout);
}

MyWnd::~MyWnd()
{

}



////*************************************************************************
////          FAMILY BUTTON
////*************************************************************************
//FamilyButton::FamilyButton(int idFam, QString s, QString sColL, QString sColG, QWidget *parent)
//    :QWidget(parent)
//{
//  // INIT
//  id      = idFam;
//  sName   = s;
//  pbtn    = new QPushButton(s);
//  iState  = 0;
//  sColorL = sColL;
//  sColorG = sColG;
//
//  
//
//  //  CONNECTORS
//  connect(pbtn, SIGNAL(clicked()),
//          this, SLOT(changeStatePush()) );
//
//  //ACTIONS
//  pbtn->resize(15,15);
//  pbtn->setStyleSheet("* { background-color: rgb" + sColorG +";border-style: solid;border-width: 5px;border-color: rgb" + sColorL +";min-width: 4em;min-height: 2em;}");
//
//  // LAYOUT
//  QVBoxLayout *layout = new QVBoxLayout;
//  layout->setMargin(0);
//  layout->setSpacing(0);
//  layout->addWidget(pbtn);
//  setLayout(layout);
//}
////*************************************************************************
////          FAMILY BUTTON FUNCTIONS
////*************************************************************************
//void FamilyButton::changeStateGrey()
//{
//  pbtn->setStyleSheet("* { background-color: rgb" + sColorG +";border-style: solid;border-width: 5px;border-color: rgb" + sColorL +";min-width: 4em;min-height: 2em;}");
//  iState = 0;
//}
////*************************************************************************
////          FAMILY BUTTON SLOTS
////*************************************************************************
//void FamilyButton::changeStatePush()
//{
//  if (iState == 0)
//  {
//    pbtn->setStyleSheet("* { background-color: rgb" + sColorL +";border-style: solid;border-width: 5px;border-color: rgb" + sColorL +";min-width: 4em;min-height: 2em;}");
//    iState = 1;
//    emit selectFam(id);
//  }
//}
