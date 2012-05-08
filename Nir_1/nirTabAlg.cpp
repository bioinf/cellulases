#include "nirTabAlg.h"



bool pushMask(GroupGraphNode* node, int msk, QString s)
{
  bool flagSet = 0;
  if (node->mask == msk)
  {
    node->vProtId->push_back(s);
    node->n++;
    return true;
  }
  if((node->mask & msk) == msk)
  {
    for (int i = 0; i < node->vChild.size(); ++i)
    {
      if ( pushMask(node->vChild.at(i), msk, s))
        flagSet = true;
    }
    // new Child
    if (flagSet == false)
    {
      node->vChild.push_back(new GroupGraphNode(msk, s));
    }
  }
  else
    return false;

  return true;

}

//*************************************************************************
//          PANEL GROUP OF ACTIVITY
//*************************************************************************
PanelGroupAct::PanelGroupAct(int msk, int numb, QWidget *parent)
    :QWidget(parent)
{
  QHBoxLayout *layout = new QHBoxLayout();
  QHBoxLayout *layoutTmp;
  QHBoxLayout *layout1 = new QHBoxLayout();
  QHBoxLayout *layout2 = new QHBoxLayout();
  layout->setMargin(0);
  layout->setSpacing(0);
  QString sColor;
  QPushButton* pbtn;
  layoutTmp = layout1;
  for (int i = 0; i < 6; ++i)
  {
    if(i>=3)
      layoutTmp = layout2;

    if ( ((msk>>(2*i)) & ~((~0)<<2)) == 1) //if acvirity
      sColor = "(232,232,232)";
    else
      sColor = "(30,30,30)";
    pbtn = new QPushButton("");
    pbtn->setStyleSheet("* { background-color: rgb" + sColor +";"+
                          "border-style: solid;"+
                          "border-width: 1px;"+
                          "border-color: rgb(0,0,0);"+
                          "min-width: 1em;"+
                          "max-width: 1em;"+
                          "min-height: 1em;"+
                          "max-height: 1em;}");
    layoutTmp->addWidget(pbtn);
  }
  layout->addLayout(layout1);
  layout->addLayout(layout2);
  layout->addWidget(new QLabel(QString::number(numb)));
  setLayout(layout);
}

//*************************************************************************
//          TAB0 PREPARE
//*************************************************************************
TabPrepare::TabPrepare(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew, QWidget *parent)
    :QWidget(parent)
{
  // INIT
  root = NULL;
  vnProt = vnProtNew;

  pPanelFamily = new PanelFamily(QBoxLayout::TopToBottom, true);
  pbtnMkGraph  = new QPushButton("Make Graph");
  pbtnImport   = new QPushButton("Import Graph");

  pfrmGroups = new QWidget();
  plActivGroups = new QLabel("Alrive Groups:", pfrmGroups);
  //FamilyButton* pfb =  new FamilyButton(3, "anna", "(13,14,35)", "(154,154,36)",pfrmGroups);
  //pfb->move(100,100);
  //PanelGroupAct* ppg = new PanelGroupAct(3, 10, pfrmGroups);
  //ppg->move(400,400);



  for (int i = 0; i < 64; ++i)
    vProtId.push_back(new QVector<QString>);
  for (int i = 0; i < 7; ++i)
    for (int j = 0; j < 64; ++j)
      vvGeneration[i][j] = 0;
  makeGeneration();

  

  // CONNECT
  connect(pbtnMkGraph, SIGNAL(clicked()),
          this,        SLOT(makeGragh()) );

  // ACTIONS
  for (int id = 0; id < 9 ; ++id)
  {
    vFamInfo.push_back(new FamilyInfo(id, vnProtNew));
  }


  // LAYOUT
  QHBoxLayout* layout = new QHBoxLayout();
  QSplitter*   splAll = new QSplitter(Qt::Horizontal);

  QFrame*      pfrmButtons = new QFrame();
               
  QVBoxLayout* layoutButtons = new QVBoxLayout();
               //layoutGroups = new QVBoxLayout();
  pfrmButtons->setLayout(layoutButtons);
  //pfrmGroups->setLayout(layoutGroups);

  layoutButtons->addWidget(pbtnMkGraph);
  layoutButtons->addWidget(pbtnImport);

  //layoutGroups->addWidget(plActivGroups);

  splAll->addWidget(pPanelFamily);
  splAll->addWidget(pfrmButtons);
  splAll->addWidget(pfrmGroups);
  
  splAll->setStretchFactor(0, 1);
  splAll->setStretchFactor(1, 1);
  splAll->setStretchFactor(2, 1);
  splAll->setChildrenCollapsible(false);

  layout->addWidget(splAll);
  setLayout(layout);
};
//-------------------------------------------------------------------------
//         TAB 0 FUNCTIONS
//-------------------------------------------------------------------------
void TabPrepare::makeGeneration()
{
  // 0 <-> 6
  // 1 <-> 5
  // 2 <-> 4
  // 3 = ~(0+1+2+4+5+6)

  int ind;
  int mskCut6 = ~((~0)<<6);

  // 0 6
  ind = 0 & mskCut6;
  vvGeneration[0][ind] = 1;
  vvGeneration[6][~ind & mskCut6] = 1;
  vvGeneration[3][ind] = 1;
  vvGeneration[3][~ind & mskCut6] = 1;
  // 1 5
  for (int i = 0; i < 6; ++i)
  {
    ind  = 1<<i;
    vvGeneration[1][ind] = 1;
    vvGeneration[5][~ind & mskCut6] = 1;
    vvGeneration[3][ind] = 1;
    vvGeneration[3][~ind & mskCut6] = 1;
  }

  // 2 4
  for (int i = 0; i < 6; ++i)
    for (int j = i+1; j < 6; ++j)
    {
      ind = (1<<i) | (1<<j);
      vvGeneration[2][ind] = 1;
      vvGeneration[4][~ind & mskCut6] = 1;
      vvGeneration[3][ind] = 1;
      vvGeneration[3][~ind & mskCut6] = 1;
    };
  
  // 3
  for (int i = 0; i < 64; ++i)
  {
    vvGeneration[3][i] = (~(vvGeneration[3][i])) & 1;
  }


}
void TabPrepare::setPanelGroup(GroupGraphNode* node, QWidget* parent)
{

  if (node->flgPainted == 0)
  {
    PanelGroupAct* pPanelGroup = new PanelGroupAct(node->mask, node->n, parent);
    pPanelGroup->node = node;
    vPanelGroup.push_back(pPanelGroup);
    node->flgPainted = true;
  }

  for(int i = 0; i < node->vChild.size(); ++i)
  {
    setPanelGroup(node->vChild.at(i), parent);
  }
}
//-------------------------------------------------------------------------
//         TAB 0 SLOTS
//-------------------------------------------------------------------------
void TabPrepare::clearNode(GroupGraphNode* node)
{
  if (node == NULL)
    return;
  for(int i = 0; i < node->vChild.size(); ++i)
  {
    clearNode(node->vChild.at(i));
  }
  delete node;
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
void TabPrepare::makeGragh()
{
//  plActivGroups->setText("blabla");
//
//  FamilyButton* pfb =  new FamilyButton(3, "vanna", "(13,14,35)", "(154,0,36)",pfrmGroups);
//  pfb->move(200,200);
//  pfb->show();
//  PanelGroupAct* ppg = new PanelGroupAct(3, 10, pfrmGroups);
//ppg->move(200,300);
//  ppg->show();
//  pfrmGroups->update();
//  pfrmGroups->repaint();


  QVector<int>* viIsPushed;
  viIsPushed = pPanelFamily->isPushed();

  clearNode(root);
  root = NULL;
  root = new GroupGraphNode(~((~0)<<12));

  int idFam;
  int idProt;
  int mask12;
  
  QVector<QString>* vProtNode;
  for (int i = 0;i < vProtId.size(); ++i)
  {
    vProtNode = vProtId.at(i);
    vProtNode->clear();
  }

  //makeProt6From12
  for (int i = 0; i < viIsPushed->size(); ++i)
  {
    idFam = viIsPushed->at(i);
    for (int j = 0; j < vnProt->at(idFam); ++j)
    {
      idProt = j;
      mask12 = vFamInfo.at(idFam)->vProtActMask.at(idProt);
      vProtNode = vProtId.at(makeProt6From12(mask12));
      vProtNode->push_back(QString::number(idFam) + makeProtID(idProt));
    }
  }

  
  QList<GroupGraphNode*> lstCurr;
  QList<GroupGraphNode*> lstNext;
  int mskCurr;
  int mskNext;
  //make New Nodes o-level
  lstCurr.push_back( new GroupGraphNode(makeProt12From6(0), vProtId.at(0)));
  lstCurr.last()->nGeneration = 0;

  for(int i = 1; i <= 5; ++i)     // cycle by all generations
  {
    for (int j = 0; j < 64; ++j) // cycle by one generation
    {
      if (vvGeneration[i][j] == 1)
      {
        if (vProtId.at(j)->size() != 0)
        {
          mskNext = j;
          lstNext.push_back(new GroupGraphNode(makeProt12From6(mskNext), vProtId.at(j)));
          lstNext.last()->nGeneration = i;
          // find child:
          for (int k = 0; k < lstCurr.size(); ++k)//one parent - many children
          {
            mskCurr = lstCurr.at(k)->mask;
            if ((mskNext & mskCurr) == mskCurr)
            {
              lstCurr.at(k)->vParent.push_back(lstNext.last());
              lstNext.last()->vChild.push_back(lstCurr.at(k));
            }
          }
        }
      }
    }
    //before go to next generation -> lstCurr+lstNext
    for (int k = lstCurr.size()-1; k >=0; --k)
      if (lstCurr.at(k)->vParent.size() != 0)
        lstCurr.removeAt(k);
    lstCurr << lstNext;
    lstNext.clear();
  }
  for (int i = 0; i < lstCurr.size(); ++i)
  {
    lstCurr.at(i)->vParent.push_back(root);
    root->vChild.push_back(lstCurr.at(i));
  }
  root->nGeneration = 6;
  lstCurr.clear();


  for (int i = 0; i < vPanelGroup.size(); ++i)
  {
    delete vPanelGroup.at(i);
  }
  vPanelGroup.clear();
  setPanelGroup(root, pfrmGroups);

  int step[8];
  setMoveCords(step);
  int count[7];
  for(int i = 0; i < 7; ++i)
    count[i] = 1;

  PanelGroupAct* pPanelGroup;
  int nGener, x, y;
  for (int i = 0;i < vPanelGroup.size(); ++i)
  {
    pPanelGroup = vPanelGroup.at(i);
    nGener = pPanelGroup->node->nGeneration;
    x = count[nGener]*step[nGener];
    y = step[7] * (7 - nGener);
    count[nGener]++;
    pPanelGroup->node->x = x;
    pPanelGroup->node->y = y;
    pPanelGroup->move(x, y);
    pPanelGroup->show();
  }

  pfrmGroups->update();
  pfrmGroups->repaint();
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
void TabPrepare::setMoveCords(int step[8])
{
  int count[7];
  for(int i = 0; i < 7; ++i)
    count[i] = 0;

  for(int i = 0; i < vPanelGroup.size(); ++i)
  {
    count[vPanelGroup.at(i)->node->nGeneration] ++;
  }

  const QRect* rct = &(pfrmGroups->geometry());
  int x = rct->width();
  int y = rct->height();
  for (int i = 0; i < 7; ++i)
  {
    step[i] = x / (count[i] + 1);
  }
  step[7] = y / 8;

}
void TabPrepare::paintGraph()
{
    QPainter p;
    QPen pen;
    pen.setColor(QColor(Qt::green));
    p.begin(this);
    p.setPen(pen);
    p.drawLine(10,20,60,60);
    p.end();
  //int x1, x2, y1, y2;
  //PanelGroupAct* pPanelGroup;
  //for (int i = 0; i < vPanelGroup.size(); ++i)
  //{
  //  pPanelGroup = vPanelGroup.at(i);
  //  x1 = pPanelGroup->node->x;
  //  y1 = pPanelGroup->node->y;
  //  for (int j = 0; j < pPanelGroup->node->vChild.size(); ++j)
  //  {
  //    x2 = pPanelGroup->node->vChild.at(j)->x;
  //    y2 = pPanelGroup->node->vChild.at(j)->y;
  //    QPainter p;
  //    QPen pen;
  //    pen.setColor(QColor(Qt::red));
  //    p.begin(pfrmGroups);
  //    p.setPen(pen);
  //    p.drawLine(x1, y1, x2, y2);
  //    p.end();
  //  }
  //}
};
void TabPrepare::paintEvent ( QPaintEvent * )
{
  paintGraph();
}
//*************************************************************************
//          TAB1 ALGORITHM1
//*************************************************************************
TabAlg1::TabAlg1(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew, QWidget *parent) 
   :QWidget(parent)
{
  // INIT
  QPushButton* pbtn = new QPushButton("anna", this);

  // CONNECT
    connect(pbtn, SIGNAL(clicked()),
          this,        SLOT(setButton()) );


  pbtn->move(60, 60);
  pbtn->resize(60,60);


  flag = 0;

};
void TabAlg1::setButton()
{
  flag = ~(int)flag & 1;
  QPushButton* pbtn = new QPushButton("anna", this);

  pbtn->move(60, 200);
  pbtn->resize(60,60);
  pbtn->show();
  this->update();
  this->repaint();

};
void TabAlg1::func()
{
    QPainter p;
    QPen pen;
    if(flag == true)
      pen.setColor(QColor(Qt::red));
    else
      pen.setColor(QColor(Qt::green));
    p.begin(this);
    p.setPen(pen);
    p.drawLine(10,20,60,60);
    p.end();
}
  void TabAlg1::paintEvent(QPaintEvent *)
  {
    //QPainter p;
    //QPen pen;
    //if(flag == true)
    //  pen.setColor(QColor(Qt::red));
    //else
    //  pen.setColor(QColor(Qt::green));
    //p.begin(this);
    //p.setPen(pen);
    //p.drawLine(10,20,60,60);
    //p.end();
    func();
  }
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