#include "nirTabFamily.h"
#include "nirStrNameProt.h"


//*************************************************************************
//          TAB1 NEW PROTEIN
//*************************************************************************
TabNewProtein::TabNewProtein(QWidget *parent)
  :QWidget(parent)
{
  // INIT
  pPanelFamily = new PanelFamily(QBoxLayout::LeftToRight, 0);
  ptEditProt   = new QTextEdit();
  ptEditNote   = new QTextEdit();
  pbtnSave     = new QPushButton("Save");

  ptEditProt->setFont(QFont("Courier"));
  ptEditNote->setFont(QFont("Courier"));

  idFam = 0;
  nProt = 0;

  plProt = new QLabel("Protein. id = " + makeProtID(nProt));
  plNote = new QLabel("Note. Name " + QString::number(idFam)+ makeProtID(nProt));

  //  CONNECTORS
  connect(pbtnSave, SIGNAL(clicked()),
          this,     SLOT(saveProt()) );
  connect(pPanelFamily, SIGNAL(setFamily(int, int)),
          this,     SLOT(changeFam(int,int)) );

  //ACTIONS

  // LAYOUT
  QVBoxLayout *layout = new QVBoxLayout;

  QHBoxLayout *layoutEdit = new QHBoxLayout;
  QVBoxLayout *layoutProt = new QVBoxLayout;
  QVBoxLayout *layoutNote = new QVBoxLayout;

  layoutProt->addWidget(plProt);
  layoutProt->addWidget(ptEditProt);
  layoutNote->addWidget(plNote);
  layoutNote->addWidget(ptEditNote);
  layoutEdit->addLayout(layoutProt);
  layoutEdit->addLayout(layoutNote);

  layout->addWidget(pPanelFamily);
  layout->addLayout(layoutEdit);
  layout->addWidget(pbtnSave);
  
  setLayout(layout);
}
//*************************************************************************
//          TAB1 NEW SLOTS
//*************************************************************************
void TabNewProtein::changeById(int idFamNew, int nProtNew)
{
  idFam = idFamNew;
  nProt = nProtNew;
  plProt->setText("Protein. id = " + makeProtID(nProt));
  plNote->setText("Note. Name " + QString::number(idFam)+ makeProtID(nProt));
  pPanelFamily->changeFamilyId(idFamNew);
}
//*************************************************************************
//*************************************************************************
void TabNewProtein::saveProt()
{
  // Save new protein
  QFile fileProt("Data_Protein/p_" + QString::number(idFam)+ makeProtID(nProt)+".txt");
  fileProt.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream streamProt(&fileProt);
  streamProt << ptEditProt->toPlainText();
  fileProt.close();

  // Save note for protein
  QFile fileNote("Data_Note/n_" + QString::number(idFam)+ makeProtID(nProt)+".txt");
  fileNote.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream streamNote(&fileNote);
  streamNote << ptEditNote->toPlainText();
  fileNote.close();

  // Cleaning
  ptEditProt->clear();
  ptEditNote->clear();
  
  // Увеличить количество протеинов в семействе и перепесать файл
  nProt ++;
  plProt->setText("Protein. id = " + makeProtID(nProt));
  plNote->setText("Note. Name " + QString::number(idFam)+ makeProtID(nProt));
  emit saveFam();


}
//*************************************************************************
//          TAB2 EDIT PROTEIN
//*************************************************************************
TabEditProtein::TabEditProtein(QWidget *parent)
  :QWidget(parent)
{
  // INIT
  pPanelFamily = new PanelFamily(QBoxLayout::LeftToRight, 0);
  ptEditProt   = new QTextEdit();
  ptEditNote   = new QTextEdit();
  pbtnSave     = new QPushButton("Save");

  cbProtein    = new QComboBox();

  idFam = 0;
  nProt = 0;
  plProt = new QLabel("Protein.");
  plNote = new QLabel("Note.");


  //  CONNECTORS
  connect(pbtnSave,  SIGNAL(clicked()),
          this,      SLOT(saveProt()) );
  connect(cbProtein, SIGNAL(activated (const QString &)),
          this,      SLOT(openProt(const QString &)) );
  connect(pPanelFamily, SIGNAL(setFamily(int, int)),
          this,     SLOT(changeFam(int,int)) );


  //ACTIONS
  ptEditProt->setFont(QFont("Courier"));
  ptEditNote->setFont(QFont("Courier"));

  // LAYOUT
  QVBoxLayout *layout = new QVBoxLayout;
  QHBoxLayout *layoutEdit = new QHBoxLayout;
  QVBoxLayout *layoutProt = new QVBoxLayout;
  QVBoxLayout *layoutNote = new QVBoxLayout;
  QHBoxLayout *layoutMenu = new QHBoxLayout;
  QVBoxLayout *layoutSubMenu = new QVBoxLayout;

  layoutProt->addWidget(plProt);
  layoutProt->addWidget(ptEditProt);
  layoutNote->addWidget(plNote);
  layoutNote->addWidget(ptEditNote);
  layoutEdit->addLayout(layoutProt);
  layoutEdit->addLayout(layoutNote);

  layoutSubMenu->addWidget(new QLabel("Choose protein ID"));
  layoutSubMenu->addWidget(cbProtein);
  layoutMenu->addLayout(layoutSubMenu);
  layoutMenu->addWidget(pbtnSave);
  layoutMenu->setAlignment(Qt::AlignBottom);

  layout->addWidget(pPanelFamily);
  layout->addLayout(layoutMenu);
  layout->addLayout(layoutEdit);

  

  setLayout(layout);
}
//*************************************************************************
//          TAB2 EDIT PROTEIN SLOTS
//*************************************************************************
void TabEditProtein::changeById(int idFamNew, int nProtNew)
{
  idFam = idFamNew;
  nProt = nProtNew;
  plProt->setText("Protein.");
  plNote->setText("Note.");

  ptEditProt->clear();
  ptEditNote->clear();

  cbProtein->clear();
  cbProtein->addItem("");
  for (int i = 0; i < nProt; i++)
    cbProtein->addItem(makeProtID(i));

  pPanelFamily->changeFamilyId(idFamNew);
}
//*************************************************************************

void TabEditProtein::changeNumbProt()
  {cbProtein->addItem(makeProtID(nProt));  nProt++; };
//*************************************************************************

void TabEditProtein::openProt(const QString & nameProt)
{
  sNameProt = nameProt;
  plProt->setText("Protein. id = " + sNameProt);
  plNote->setText("Note. Name " + QString::number(idFam)+ sNameProt);
  ptEditProt->clear();
  ptEditNote->clear();

  QFile fileProt("Data_Protein/p_" + QString::number(idFam)+ sNameProt+".txt");
  fileProt.open(QIODevice::ReadOnly | QIODevice::Text);
  QTextStream streamProt(&fileProt);
  ptEditProt->setPlainText(streamProt.readAll());
  fileProt.close();

  // Save note for protein
  QFile fileNote("Data_Note/n_" + QString::number(idFam)+ sNameProt+".txt");
  fileNote.open(QIODevice::ReadOnly | QIODevice::Text);
  QTextStream streamNote(&fileNote);
  ptEditNote->setPlainText(streamNote.readAll());
  fileNote.close();

};
//*************************************************************************
void TabEditProtein::saveProt()
{
  // Save new protein
  QFile fileProt("Data_Protein/p_" + QString::number(idFam)+ sNameProt+".txt");
  fileProt.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream streamProt(&fileProt);
  streamProt << ptEditProt->toPlainText();
  fileProt.close();

  // Save note for protein
  QFile fileNote("Data_Note/n_" + QString::number(idFam)+ sNameProt+".txt");
  fileNote.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream streamNote(&fileNote);
  streamNote << ptEditNote->toPlainText();
  fileNote.close();

}
//*************************************************************************
//          TAB3 EDIT FAMILY
//*************************************************************************
TabEditFamily::TabEditFamily(QWidget *parent)
  :QWidget(parent)
{
  // INIT
  pPanelFamily = new PanelFamily(QBoxLayout::LeftToRight, 0);
  ptEditFam    = new QTextEdit();
  plFam        = new QLabel("Information about Family");
  pbtnSave     = new QPushButton("Save");

  idFam = 0;
  nProt = 0;

  // CONNECTORS
  connect(pbtnSave, SIGNAL(clicked()),
          this,     SLOT(saveProt()) );
  connect(pPanelFamily, SIGNAL(setFamily(int, int)),
          this,     SLOT(changeFam(int,int)) );

  // ACTIONS
  ptEditFam->setFont(QFont("Courier"));

  // LAYOUT
  QVBoxLayout *layout = new QVBoxLayout;
  QHBoxLayout *layoutTitle = new QHBoxLayout;


  layoutTitle->addWidget(plFam);
  layoutTitle->addWidget(pbtnSave);

  layout->addWidget(pPanelFamily);
  layout->addLayout(layoutTitle);
  layout->addWidget(ptEditFam);

  setLayout(layout);
}
//*************************************************************************
//          TAB3 EDIT FAMILY FUNCTIONS
//*************************************************************************
void TabEditFamily::changeById(int idFamNew, int nProt)
{
  idFam=idFamNew;
  plFam->setText("Information about Family " + QString::number(idFam));
  ptEditFam->clear();

  QFile fileProt("Data_Family/f_" + QString::number(idFam) + ".txt");
  fileProt.open(QIODevice::ReadOnly | QIODevice::Text);
  QTextStream streamProt(&fileProt);
  ptEditFam->setPlainText(streamProt.readAll());
  fileProt.close();

  pPanelFamily->changeFamilyId(idFamNew);
}
//*************************************************************************
//          TAB3 EDIT FAMILY SLOTS
//*************************************************************************
void TabEditFamily::saveProt()
{
  // Save note for family
  QFile fileProt("Data_Family/f_" + QString::number(idFam) + ".txt");
  fileProt.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream streamProt(&fileProt);
  streamProt << ptEditFam->toPlainText();
  fileProt.close();

}


//*************************************************************************
//          BASIC TAB FAMILY WIDGET
//*************************************************************************


MyTabWidgetFamily::MyTabWidgetFamily(QWidget* parent)
    :QTabWidget(parent)
{
  // INIT

  PanelFamily* pPanelFamily = new PanelFamily(QBoxLayout::LeftToRight, 0);

  vbFamilyNew = &(pPanelFamily->vbFamily);
  vnProtNew   = &(pPanelFamily->vnProt);

  ptwidget = this;
  ptab1 = new TabNewProtein(pPanelFamily);
  ptab2 = new TabEditProtein(pPanelFamily);
  ptab3 = new TabEditFamily(pPanelFamily);

  //  CONNECTORS
  connect(ptab1,  SIGNAL(changeFamId(int, int)),
          this, SLOT(changeFam(int, int))     );
  connect(ptab2,  SIGNAL(changeFamId(int, int)),
          this, SLOT(changeFam(int, int))     );
  connect(ptab3,  SIGNAL(changeFamId(int, int)),
          this, SLOT(changeFam(int, int))     );

  
  connect(this,  SIGNAL(changeFamId(int, int)),
          ptab2, SLOT(changeById(int, int))     );
  connect(this,  SIGNAL(changeFamId(int, int)),
          ptab1, SLOT(changeById(int, int))     );
  connect(this,  SIGNAL(changeFamId(int, int)),
          ptab3, SLOT(changeById(int, int))     );

  connect(ptab1, SIGNAL(saveFam()),
          this,  SLOT(saveFamToMain()) );
  connect(ptab1, SIGNAL(saveFam()),
          ptab2, SLOT(changeNumbProt()) );


  connect(pPanelFamily, SIGNAL(setFamily(int, int)),
          this,         SLOT(changeTab1(int, int))  );
  connect(this,         SIGNAL(saveFam()),
          pPanelFamily, SLOT(saveInitProt()) );

  //ACTIONS

  // LAYOUT
  ptwidget->addTab(ptab1, "New Protein");
  ptwidget->addTab(ptab2, "Edit Protein");
  ptwidget->addTab(ptab3, "Family Information");
  //ptwidget->setStyleSheet(
  //  "QTabBar::tab { padding: 15px 100px 10px 10px;"
  //                 "margin-top: 10px;"
  //                 "color: #303070;"
  //                 "border-width: 1px;"
  //                 "border-top-left-radius: 4px;"
  //                 "border-top-right-radius: 4px;}"
  //  "QTabBar::tab:selected { background: white"
  //  /*                          "border: 1px solid #808090;"
  //                            "border-bottom: solid 0px;} " */
  //  "QTabBar::tab:!selected { border-bottom: 0px solid ;}"
  //  "QTabWidget::tab-bar { left: 30px; }");

  ptwidget->setStyleSheet(
      "QTabBar::tab { background: lightgray; color: #303070; padding: 8px;"
                     "border-top-left-radius: 4px;"
                     "border-top-right-radius: 4px;"
                     "min-width: 7em;"
                     "max-width: 7em;} "
      "QTabBar::tab:selected { background: white; border: 1px solid #808090; border-bottom: solid 0px} "
      "QTabBar::tab:!selected { background: lightgray; border: 1px solid #808090;} "
      "QTabWidget::tab-bar { left: 7em; }");


  
  
  //QVBoxLayout *layout = new QVBoxLayout;
  ////layout->addWidget(pPanelFamily);
  //layout->addWidget(ptwidget);
  //setLayout(layout);

}
