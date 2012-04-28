#include "nirProtButt.h"

//*************************************************************************
//          PROTEIN BUTTON
//*************************************************************************
ProtButton::ProtButton(int idFamNew, QString sNameProt, QString sColL, QString sColG, int flagFP, QWidget *parent)
    :QWidget(parent)
{
  // INIT
  idFam   = idFamNew;
  sName   = sNameProt;
  pbtn    = new QPushButton(sName);
  iState  = 0;
  sColorL = sColL;
  sColorG = sColG;
  iFlagFP = flagFP;


  //  CONNECTORS
  connect(pbtn, SIGNAL(clicked()),
          this, SLOT(changeStatePush()) );

  //ACTIONS
  pbtn->resize(15,15);
  pbtn->setStyleSheet("* { background-color: rgb" + sColorG +";border-style: solid;border-width: 3px;border-color: rgb" + sColorL +";min-width: 4em;min-height: 1em;}");

  // LAYOUT
  QVBoxLayout *layout = new QVBoxLayout;
  layout->setMargin(0);
  layout->setSpacing(0);
  layout->addWidget(pbtn);
  setLayout(layout);
}
//*************************************************************************
//          FAMILY BUTTON FUNCTIONS
//*************************************************************************
void ProtButton::changeStateGrey()
{
  pbtn->setStyleSheet("* { background-color: rgb" + sColorG +";border-style: solid;border-width: 3px;border-color: rgb" + sColorL +";min-width: 4em;min-height: 1em;}");
  iState = 0;
  pbtn->setEnabled(true);
}
void ProtButton::changeStateLight()
{
  pbtn->setStyleSheet("* { background-color: rgb" + sColorL +";border-style: solid;border-width: 3px;border-color: rgb" + sColorL +";min-width: 4em;min-height: 1em;}");
  iState = 1;
  pbtn->setEnabled(true);
}
void ProtButton::changeStateBlack()
{
  pbtn->setStyleSheet("* { background-color: rgb (0,0,0) ;border-style: solid;border-width: 3px;border-color: rgb" + sColorL +";min-width: 4em;min-height: 1em;}");
  iState = 0;
  pbtn->setEnabled(false);
}
//*************************************************************************
//          FAMILY BUTTON SLOTS
//*************************************************************************
void ProtButton::changeStatePush()
{
  if (iState == 0)
  {
    pbtn->setStyleSheet("* { background-color: rgb" + sColorL +";border-style: solid;border-width: 3px;border-color: rgb" + sColorL +";min-width: 4em;min-height: 1em;}");
    iState = 1;
    
  }
  else
  {
    pbtn->setStyleSheet("* { background-color: rgb" + sColorG +";border-style: solid;border-width: 3px;border-color: rgb" + sColorL +";min-width: 4em;min-height: 1em;}");
    iState = 0;
    
  }
  if (iFlagFP == 0)
    emit selectFam(idFam, iState);
}
