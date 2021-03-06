#include "nirPanelFamily.h"

//*************************************************************************
//           PANEL FAMILY 
//*************************************************************************
PanelFamily::PanelFamily(int iLoutDir, bool bMltPush, QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
  //INIT
  FamilyButton* pbFamily; 
  sfFamily = "initFam.txt";
  sfProt   = "initProt.txt";

  idFamCurr  = -1;
  iLayoutDir = iLoutDir;
  bMultiPush = bMltPush;

  loadFileFamily();
  loadFileProtein();

  // CONNECT
  for (int i = 0; i < vbFamily.size(); i++)
  {
    pbFamily = vbFamily.at(i);
    if ( bMultiPush == false)
    {
      connect(pbFamily,  SIGNAL(selectFam(int)),
            this,      SLOT(changeFamily(int)) );
    }
  }

  // ACTIONS

  // LAYOUT
  QBoxLayout* layout = new QBoxLayout((QBoxLayout::Direction)iLayoutDir);
  //QSplitter*  splFam = new QSplitter(Qt::Horizontal);
  for (int i = 0; i < vbFamily.size(); i++)
  {
    layout->addWidget(vbFamily.at(i));
  }
  //layout->addWidget(splFam);
  setLayout(layout);
  this->setStyleSheet("QWidget { background-color: white; } ");
}

//*************************************************************************
//           PANEL FAMILY FUNCTIONS
//*************************************************************************
void PanelFamily::loadFileFamily()
{
  QFile         file(sfFamily);
  file.open(QIODevice::ReadOnly | QIODevice::Text);
  QTextStream   pfMap(&file);

  bool    bEnd = 1;
  int     idFam;
  QString s;
  QString sNameFam;
  QString sColL;
  QString sColG;

  while(bEnd == 1)
  {
    pfMap>>s;
    if (s != "Family")
    { bEnd = 0; continue;}
    pfMap >> idFam;
    pfMap >> sNameFam;
    pfMap >> sColL;
    pfMap >> sColG;

    vbFamily.push_back(new FamilyButton(idFam, sNameFam, sColL, sColG));
  }
  file.close();
}
//*************************************************************************
//*************************************************************************
QVector<int>* PanelFamily::isPushed()
{
  viIsPushed.clear();
  for (int i = 0; i < 9; ++i)
  {
    if(vbFamily.at(i)->iState == 1)
      viIsPushed.push_back(i);
  }
  return &viIsPushed;

}
//*************************************************************************
//*************************************************************************
void PanelFamily::loadFileProtein()
{
  QFile         file(sfProt);
  file.open(QIODevice::ReadOnly | QIODevice::Text);
  QTextStream   pfMap(&file);

  bool    bEnd = 1;
  int     nFam;
  int     idF;
  int     nProt;

  QString s;
  pfMap>>s; //Family
  pfMap>>nFam;
  pfMap>>s; //Protein
  pfMap>>nProtTotal;
  pfMap>>s; //Table

  for (int i = 0; i < nFam; i++)
  {
    pfMap>>idF;
    pfMap>>nProt;
    vnProt.push_back(nProt);
  }
  file.close();
}
void PanelFamily::changeFamilyId(int id)
{
  if(idFamCurr != -1)
  {
    vbFamily.at(idFamCurr)->changeStateGrey();
  }
  vbFamily.at(id)->changeStateLight();
  idFamCurr = id;
}
//*************************************************************************
//           PANEL FAMILY SLOTS
//*************************************************************************
void PanelFamily::changeFamily(int id)
{
  if(idFamCurr != -1)
  {
    vbFamily.at(idFamCurr)->changeStateGrey();
  }
  idFamCurr = id;
  emit setFamily(idFamCurr, vnProt.at(idFamCurr));
}
void PanelFamily::saveInitProt()
{
  vnProt.replace(idFamCurr, vnProt.at(idFamCurr) + 1);
  nProtTotal++;
  
  // Saving
  QFile fileInitProt(sfProt);
  fileInitProt.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream streamProt(&fileInitProt);

  QString s;
  streamProt<<"Family\n";
  streamProt<<vnProt.size()<<"\n";
  streamProt<<"Protein\n";
  streamProt<<nProtTotal<<"\n";
  streamProt<<"Table\n";

  for (int i = 0; i < vnProt.size(); i++)
  {
    streamProt<<i<<"\t";
    streamProt<<vnProt.at(i)<<"\n";
  }

  fileInitProt.close();
}
//*************************************************************************
//          FAMILY BUTTON
//*************************************************************************
FamilyButton::FamilyButton(int idFam, QString s, QString sColL, QString sColG, QWidget *parent)
    :QWidget(parent)
{
  // INIT
  id      = idFam;
  sName   = s;
  pbtn    = new QPushButton(s);
  iState  = 0;
  sColorL = sColL;
  sColorG = sColG;

  

  //  CONNECTORS
  connect(pbtn, SIGNAL(clicked()),
          this, SLOT(changeStatePush()) );

  //ACTIONS
  pbtn->resize(15,15);
  pbtn->setStyleSheet("* { background-color: rgb" + sColorG +";"+
                          "border-style: solid;"+
                          "border-radius: 5px;" +
                          "border-width: 5px;"+
                          "border-color: rgb" + sColorL +";"+
                          "min-width: 4em;"+
                          "max-width: 30em;"+
                          "min-height: 1em;"+
                          "max-height: 2em;}");

  // LAYOUT
  QVBoxLayout *layout = new QVBoxLayout();//(QBoxLayout::RightToLeft);//(QBoxLayout::LeftToRight);
  layout->setMargin(0);
  layout->setSpacing(0);
  layout->addWidget(pbtn);
  setLayout(layout);
}
//*************************************************************************
//          FAMILY BUTTON FUNCTIONS
//*************************************************************************
void FamilyButton::changeStateGrey()
{
  pbtn->setStyleSheet("* { background-color: rgb" + sColorG +";"+
                          "border-style: solid;"+
                          "border-radius: 5px;" +
                          "border-width: 5px;"+
                          "border-color: rgb" + sColorL +";"+
                          "min-width: 4em;"+
                          "max-width: 30em;"+
                          "min-height: 1em;"+
                          "max-height: 2em;}");
  iState = 0;
}
void FamilyButton::changeStateLight()
{
  pbtn->setStyleSheet("* { background-color: rgb" + sColorL +";"+
                          "border-style: solid;"+
                          "border-radius: 5px;" +
                          "border-width: 5px;"+
                          "border-color: rgb" + sColorL +";"+
                          "min-width: 4em;"+
                          "max-width: 30em;"+
                          "min-height: 1em;"+
                          "max-height: 2em;}");
  iState = 0;
}
//*************************************************************************
//          FAMILY BUTTON SLOTS
//*************************************************************************
void FamilyButton::changeStatePush()
{
  if (iState == 0)
  {
    pbtn->setStyleSheet("* { background-color: rgb" + sColorL +";"+
                            "border-style: solid;"+
                            "border-radius: 5px;" +
                            "border-width: 5px;"+
                            "border-color: rgb" + sColorL +";"+
                            "min-width: 4em;"+
                            "max-width: 30em;"+
                            "min-height: 1em;"+
                            "max-height: 2em;}");
    iState = 1;
    emit selectFam(id);
  }
  else
  {
    pbtn->setStyleSheet("* { background-color: rgb" + sColorG +";"+
                            "border-style: solid;"+
                            "border-radius: 5px;" +
                            "border-width: 5px;"+
                            "border-color: rgb" + sColorL +";"+
                            "min-width: 4em;"+
                            "max-width: 30em;"+
                            "min-height: 1em;"+
                            "max-height: 2em;}");
    iState = 0;
  }
}
