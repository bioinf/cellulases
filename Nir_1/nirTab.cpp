#include "nirTab.h"

QString makeProtID(int id)
{
  if (id < 10)
    return "0"+QString::number(id);
  else
    return QString::number(id);
}
int     makeMask(QString s)
{
  int j, curr, mask = 0;
  for (int i = 0; i < 6; ++i)
  {
    j = i*2+1;
    if(s.at(j) == '0')
      curr = 1;
    else
      curr = 2;
    mask += curr <<(2*i);
  }
  return mask;
}
QString   makeProtToABC(int id)
{
  if (id < 10)
    return QString::number(id);
  else
    return ('A'+id-10);
}
int   makeProtFromABC(QChar ch)
{
  QChar ch0('0');
  QChar chA('A');
  if (ch <= '9' && ch >= '0')
    return ch.toAscii() - ch0.toAscii();
  else
    return ch.toAscii() - chA.toAscii() + 10;
}
//*************************************************************************
//          TAB1 NEW PROTEIN
//*************************************************************************
TabNewProtein::TabNewProtein(QWidget *parent)
  :QWidget(parent)
{
  // INIT
  ptEditProt = new QTextEdit();
  ptEditNote = new QTextEdit();
  pbtnSave = new QPushButton("Save");

  ptEditProt->setFont(QFont("Courier"));
  ptEditNote->setFont(QFont("Courier"));

  idFam = 0;
  nProt = 0;

  plProt = new QLabel("Protein. id = " + makeProtID(nProt));
  plNote = new QLabel("Note. Name " + QString::number(idFam)+ makeProtID(nProt));

  //  CONNECTORS
  connect(pbtnSave, SIGNAL(clicked()),
          this,     SLOT(saveProt()) );
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
  ptEditProt = new QTextEdit();
  ptEditNote = new QTextEdit();
  pbtnSave = new QPushButton("Save");

  cbProtein = new QComboBox();

  idFam = 0;
  nProt = 0;
  plProt = new QLabel("Protein.");
  plNote = new QLabel("Note.");


  //  CONNECTORS
  connect(pbtnSave,  SIGNAL(clicked()),
          this,      SLOT(saveProt()) );
  connect(cbProtein, SIGNAL(activated (const QString &)),
          this,      SLOT(openProt(const QString &)) );


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
  ptEditFam = new QTextEdit();
  plFam = new QLabel("Information about Family");
  pbtnSave = new QPushButton("Save");

  idFam = 0;
  nProt = 0;

  // CONNECTORS
  connect(pbtnSave, SIGNAL(clicked()),
          this,     SLOT(saveProt()) );

  // ACTIONS
  ptEditFam->setFont(QFont("Courier"));

  // LAYOUT
  QVBoxLayout *layout = new QVBoxLayout;
  QHBoxLayout *layoutTitle = new QHBoxLayout;


  layoutTitle->addWidget(plFam);
  layoutTitle->addWidget(pbtnSave);

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
//          TAB4 ALIGNMENT
//*************************************************************************
TabAlignment::TabAlignment(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew,QWidget *parent)
  :QWidget(parent)
{
  // INIT
  pvbFamily = vbFamilyNew;
  pvnProt   = vnProtNew;

  ptEditFasta = new QTextEdit();
  ptEditAlign = new QTextEdit();
  ptEditNote  = new QTextEdit();
  plFam       = new QLabel();
  pbtnSave    = new QPushButton("Save");
  pbtnImport  = new QPushButton("View");
  pbtnFasta   = new QPushButton("Make Fasta");
  pbtnReFasta = new QPushButton("ReMake Fasta");

  ptEditFasta->setFont(QFont("Courier"));
  ptEditAlign->setFont(QFont("Courier"));
  ptEditNote->setFont(QFont("Courier"));

  pFilter = new FilterWidget();

  sAlignFile = "";
  plAlingCode = new QLabel("AlignCode: "+sAlignFile);

  sFileHystory = "historyAlign.txt";
  cbAlignUsed = new QComboBox();
  cbAlignUsed->addItem("");
  loadHystory();



  // CONNECTORS
  connect(pbtnSave, SIGNAL(clicked()),
          this,     SLOT(saveAlign()) );

  // LAYOUT
  QHBoxLayout *layout = new QHBoxLayout;
  QHBoxLayout *layoutProts = new QHBoxLayout;
  
  QVBoxLayout *layoutTmp;


  // ACTIONS
  QVector<ProtButton*>* pvbProt;
  ProtButton*           pbProt;
  
  for (int i = 0; i< pvbFamily->size(); ++i) // Family
  {
    layoutTmp = new QVBoxLayout;
    vLayoutProts.push_back(layoutTmp);
    layoutTmp->setSpacing(1);
    layoutTmp->setAlignment(Qt::AlignTop);

    pvbProt = new QVector<ProtButton*>;


    pbProt = new ProtButton(i, pvbFamily->at(i)->sName, pvbFamily->at(i)->sColorL, "(163,163,163)", 0);
    vbFamily.push_back(pbProt);
    layoutTmp->addWidget(pbProt);
    connect(pbProt, SIGNAL(selectFam(int, int)),
            this,   SLOT(selectAll(int, int)) );

    for (int j = 0; j < pvnProt->at(i); ++j)   // Protein
    {
      pbProt = new ProtButton(i, makeProtID(j), pvbFamily->at(i)->sColorL, pvbFamily->at(i)->sColorG, 1);
      pvbProt->push_back(pbProt);

      layoutTmp->addWidget(pbProt);
      //layoutTmp->setAlignment(pbProt, Qt::AlignTop);
      // CONNECT
    }
    layoutProts->addLayout(layoutTmp);
    vvbProt.push_back(pvbProt);
  }

  // Set Hydrolytic Activityfrom file - note
  loadHydrolytic();
   
  connect(pFilter,   SIGNAL(sendFinter(int)),
          this,      SLOT(setFilter(int)) );
  connect(pbtnFasta, SIGNAL(clicked()),
          this,      SLOT(setAlign()) );
  connect(pbtnReFasta, SIGNAL(clicked()),
          this,      SLOT(resetAlign()) );
  connect(cbAlignUsed, SIGNAL(activated (const QString &)),
          this,      SLOT(setFromFile(const QString &)));
  connect(pbtnImport, SIGNAL(clicked()),
          this,      SLOT(prepareImport()) );
  

  // LAYOUT
  

  QVBoxLayout *layoutAlign = new QVBoxLayout;
  QHBoxLayout *layoutButt = new QHBoxLayout;
  
  layoutAlign->addWidget(pFilter);
  layoutAlign->addWidget(pbtnFasta);
  layoutAlign->addWidget(new QLabel("Fasta to align"));
  layoutAlign->addWidget(plAlingCode);
  layoutAlign->addWidget(ptEditFasta);

  layoutAlign->addWidget(new QLabel("Choose align"));
  layoutAlign->addWidget(cbAlignUsed);
  layoutAlign->addWidget(pbtnReFasta);
  
  layoutAlign->addWidget(new QLabel("Result"));
  layoutAlign->addWidget(ptEditAlign);
  layoutAlign->addWidget(new QLabel("Notes"));
  layoutAlign->addWidget(ptEditNote);
  layoutButt->addWidget(pbtnSave);
  layoutButt->addWidget(pbtnImport);
  layoutAlign->addLayout(layoutButt);
  
  
  layout->addLayout(layoutProts);
  layout->addLayout(layoutAlign);
  
  

  setLayout(layout);

  // BGColor
  //QPalette* palette = new QPalette();
  //palette->setColor(QPalette::Shadow,Qt::red);
  //this->setPalette(*palette);
  //this->setStyleSheet(/*"QWidget */"{ background: lightgray; } ");
//QPalette* palette = new QPalette();
//	palette->setColor(QPalette::Base,Qt::red);	
//	this->setPalette(*(palette));

}

//*************************************************************************
//          TAB4 ALINGMENT SLOTS
//*************************************************************************
void TabAlignment::loadFromViewTab(QString& sRes, QString& sNote)
{
  ptEditAlign->clear();
  ptEditAlign->setText(sRes);
  ptEditNote->clear();
  ptEditNote->setText(sNote);
  saveAlign();
}
void TabAlignment::prepareImport()
{
  emit sendImport(ptEditAlign->toPlainText(), ptEditNote->toPlainText());
}
void TabAlignment::setFromFile(const QString & sItem)
{
  // Очистить всё
  // TextEdit
  ptEditFasta->clear();
  ptEditAlign->clear();
  ptEditNote->clear();
  // Кнопки
  QVector<ProtButton*>* pvbProt;
  ProtButton*           pbProt;
  
  for (int i = 0; i< pvbFamily->size(); ++i) // Family
  {
    pvbFamily->at(i)->changeStateGrey();
    pvbProt = vvbProt.at(i);
    for (int j = 0; j < pvbProt->size(); ++j)   // Protein
    {
      pvbProt->at(j)->changeStateGrey();
    }
  }
  // Фильтр
  pFilter->initFilter();
  //Открыть файл на чтение
  QString sIt(sItem);
  QTextStream strmItem(&sIt, QIODevice::ReadOnly);
  strmItem >> sAlignFile;
  sAlignFile = "";
  strmItem >> sAlignFile;

  // Установка кнопок как было раньше
  QChar ch;
  int iFam, iProt;
  for(int i = 0; i < sAlignFile.size(); i += 2)
  {
    ch = sAlignFile.at(i);
    iFam = ch.toAscii() - '0';
    ch = sAlignFile.at(i+1);
    iProt = makeProtFromABC(ch);
    vvbProt.at(iFam)->at(iProt)->changeStateLight();
  }


  QFile fileAlign("Data_Align/a_" + sAlignFile +".txt");
  fileAlign.open(QIODevice::ReadOnly | QIODevice::Text);
  QTextStream streamAling(&fileAlign);
  ptEditAlign->setPlainText(streamAling.readAll());
  fileAlign.close();

  QFile fileANote("Data_Align_Note/an_" + sAlignFile + ".txt");
  fileANote.open(QIODevice::ReadOnly | QIODevice::Text);
  QTextStream streamANote(&fileANote);
  ptEditNote->setPlainText(streamANote.readAll());
  fileANote.close();

}
void TabAlignment::selectAll(int idFam, int iState)
{
  if(iState == 1)
    for(int i = 0; i < pvnProt->at(idFam); ++i)
    {
      if(vvbProt.at(idFam)->at(i)->pbtn->isEnabled()== true)
        vvbProt.at(idFam)->at(i)->changeStateLight();
    }
  else
    for(int i = 0; i < pvnProt->at(idFam); ++i)
    {
      if(vvbProt.at(idFam)->at(i)->pbtn->isEnabled() == true)
        vvbProt.at(idFam)->at(i)->changeStateGrey();
    }
}
void TabAlignment::setFilter(int mask)
{
  QVector<ProtButton*>* pvbTmp;
  for (int i = 0; i < vvbProt.size(); ++i)
  {
    pvbTmp = vvbProt.at(i);
    for (int j = 0; j < pvbTmp->size(); ++j)
    {
      if ( (pvbTmp->at(j)->iHydrolytic | mask) == mask )
      {
        if (pvbTmp->at(j)->iState == 0)
          pvbTmp->at(j)->changeStateGrey();
      }
      else
        pvbTmp->at(j)->changeStateBlack();
    }
  }
}
void TabAlignment::resetAlign()
{
    QFile fFastaIn("align_in.fasta");
    fFastaIn.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream streamFastaIn(&fFastaIn);
    streamFastaIn << ptEditFasta->toPlainText();
    fFastaIn.close();

    QString program = "clustalw2";
    QStringList arguments;
    arguments << "-align" << "-infile=align_in.fasta" << "-type=protein" << "-outfile=align_out.aln";   
    QProcess *myProcess = new QProcess();
    myProcess->start(program, arguments);
    bool flWait = myProcess->waitForFinished(-1);
    //if (myProcess->exitStatus() == QProcess::CrashExit)
    //{
    //  int g = 3;
    //  g++;
    //}
    //myProcess->close();

    QFile fFastaOut("align_out.aln");
    fFastaOut.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream streamFastaOut(&fFastaOut);
    ptEditAlign->setPlainText(streamFastaOut.readAll());
    fFastaOut.close();

  //QFile fFastaIn("align_in.fasta");
  //fFastaIn.open(QIODevice::WriteOnly | QIODevice::Text);
  //QTextStream streamFastaIn(&fFastaIn);
  //streamFastaIn << ptEditFasta->toPlainText();
  //QString s = ptEditFasta->toPlainText();
  //fFastaIn.close();

  //QString program = "clustalw2.exe";
  //QStringList arguments;
  //arguments << "-align" << "-infile=align_in.fasta" << "-type=protein" << "-outfile=Data_Align/a_" + sAlignFile +".txt";
  //QProcess *myProcess = new QProcess();
  //myProcess->start(program, arguments);
  //myProcess->close();

  //QFile fFastaOut("align_in.aln");
  //fFastaOut.open(QIODevice::ReadOnly | QIODevice::Text);
  //QTextStream streamFastaOut(&fFastaOut);
  //ptEditAlign->setPlainText(streamFastaOut.readAll());
  //fFastaOut.close();
}
void TabAlignment::setAlign()
{
  sAlignFile = "";
  ptEditFasta->clear();
  QVector<ProtButton*>* pvbTmp;
  for (int i = 0; i < vvbProt.size(); ++i)
  {
    pvbTmp = vvbProt.at(i);
    for (int j = 0; j < pvbTmp->size(); ++j)
    {
      if ((pvbTmp->at(j)->pbtn->isEnabled() == true) && (pvbTmp->at(j)->getState() == 1))
      {
        QFile fileProt("Data_Protein/p_" + QString::number(i) + makeProtID(j) + ".txt");
        fileProt.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream strmProt(&fileProt);
        ptEditFasta->insertPlainText(strmProt.readAll() + "\n");
         
        sAlignFile += QString::number(i) + makeProtToABC(j);
      }
    }
  }
  plAlingCode->setText("AlignCode: " + sAlignFile);
  ptEditAlign->clear();
  ptEditNote->clear();
  ptEditNote->setText(pFilter->getFilter());

  //Если можно открыть предыдущую версию
  QFile fileAlign("Data_Align/a_" + sAlignFile +".txt");
  if(fileAlign.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    QTextStream streamAling(&fileAlign);
    ptEditAlign->setPlainText(streamAling.readAll());
    fileAlign.close();
  }
  else
  {
    QFile fFastaIn("align_in.fasta");
    fFastaIn.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream streamFastaIn(&fFastaIn);
    streamFastaIn << ptEditFasta->toPlainText();
    fFastaIn.close();

    QString program = "clustalw2";
    QStringList arguments;
    arguments << "-align" << "-infile=align_in.fasta" << "-type=protein" << "-outfile=align_out.aln";   
    QProcess *myProcess = new QProcess();
    myProcess->start(program, arguments);
    bool flWait = myProcess->waitForFinished(-1);

    //if (myProcess->exitStatus() == QProcess::CrashExit)
    //{
    //  int g = 3;
    //  g++;
    //}
    //myProcess->close();

    QFile fFastaOut("align_out.aln");
    fFastaOut.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream streamFastaOut(&fFastaOut);
    ptEditAlign->setPlainText(streamFastaOut.readAll());
    fFastaOut.close();
  }

  QFile fileANote("Data_Align_Note/an_" + sAlignFile + ".txt");
  if( fileANote.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    QTextStream streamANote(&fileANote);
    ptEditNote->setPlainText(streamANote.readAll());
    fileANote.close();
  }


  cbAlignUsed->setCurrentIndex(0);
}
void TabAlignment::saveAlign()
{
  if(sAlignFile == "")
    return;

  QFile fileAlign("Data_Align/a_" + sAlignFile +".txt");
  fileAlign.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream streamAling(&fileAlign);
  streamAling << ptEditAlign->toPlainText();
  fileAlign.close();


  QFile fileANote("Data_Align_Note/an_" + sAlignFile + ".txt");
  fileANote.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream streamANote(&fileANote);
  streamANote << ptEditNote->toPlainText();
  fileANote.close();



  bool useFlag = false;
  for (int i = 0; i < vAlignUsed.size(); ++i)
  {
    if (vAlignUsed.at(i) == sAlignFile)
    {
      useFlag = true;
      break;
    }
  }
  if (useFlag == false)
  {
    // Add to combobox
    cbAlignUsed->addItem(QString::number(cbAlignUsed->count()) + "\t" + sAlignFile);
    // Add to vector of history
    vAlignUsed.push_back(sAlignFile);
    // Addto hustory file
    QFile fileHist(sFileHystory);
    fileHist.open(QIODevice::Append | QIODevice::Text);
    QTextStream streamHist(&fileHist);
    streamHist << sAlignFile<<"\n";
    fileHist.close();
  }
}
//*************************************************************************
//          TAB4 ALINGMENT FUNCTIONS
//*************************************************************************
void TabAlignment::loadHystory()
{
  cbAlignUsed->clear();
  cbAlignUsed->addItem("");
  QFile file(sFileHystory);
  file.open(QIODevice::ReadOnly | QIODevice::Text);
  QTextStream strm(&file);
  QString s = strm.readLine(500);
  while (s != "")
  {
    vAlignUsed.push_back(s);
    s = strm.readLine(500);
  }
  for (int i = 0; i < vAlignUsed.size(); ++i)
    cbAlignUsed->addItem(QString::number(i) + "\t" + vAlignUsed.at(i));
}
void TabAlignment::loadHydrolytic()
{
  //QVector<QVector<ProtButton*>*> vvbProt; 
  QVector<ProtButton*>* pvbTmp;
  QString s;
  QChar ch;
  int mask;
  for (int i = 0; i < vvbProt.size(); ++i)
  {
    pvbTmp = vvbProt.at(i);
    for (int j = 0; j < pvbTmp->size(); ++j)
    {
      QFile fileNote("Data_Note/n_" + QString::number(i) + makeProtID(j) + ".txt");
      fileNote.open(QIODevice::ReadOnly | QIODevice::Text);
      QTextStream strmNote(&fileNote);
      s = strmNote.readLine(50); // Hydrolytic Activity
      s = strmNote.readLine(50); // [C X S M A L]
      s = strmNote.readLine(50); // [* * * * * *]
      mask = makeMask(s);

      pvbTmp->at(j)->iHydrolytic = mask;


      fileNote.close();
    }
  }
}
//*************************************************************************
//          TAB5 IMPORT
//*************************************************************************
TabImport::TabImport(QWidget *parent)
  :QWidget(parent)
{
  // INIT
  ptEditRes  = new QTextEdit();
  ptEditNote = new QTextEdit();

  pbtnSave   = new QPushButton("Save");

  ptEditRes->setFont(QFont("Courier"));
  ptEditNote->setFont(QFont("Courier"));

  //CONNECT
  connect(pbtnSave, SIGNAL(clicked()),
          this,     SLOT(pushSave()) );


  // LAYOUT
  QVBoxLayout *layout = new QVBoxLayout;

  QHBoxLayout *layoutText = new QHBoxLayout;

  QVBoxLayout *layoutRes = new QVBoxLayout;
  QVBoxLayout *layoutNote = new QVBoxLayout;
  
  layoutRes->addWidget(new QLabel("Result:"));
  layoutRes->addWidget(ptEditRes);
  layoutNote->addWidget(new QLabel("Note:"));
  layoutNote->addWidget(ptEditNote);

  layoutText->addLayout(layoutRes);
  layoutText->addLayout(layoutNote);

  layout->addWidget(pbtnSave);
  layout->addLayout(layoutText);

  setLayout(layout);
}

//*************************************************************************
//          BASIC TAB WIDGET
//*************************************************************************


MyTabWidget::MyTabWidget(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew,QWidget* parent)
    :QTabWidget(parent)
{
  // INIT
  ptab1 = new TabNewProtein();
  ptab2 = new TabEditProtein();
  ptab3 = new TabEditFamily();
  ptab4 = new TabAlignment(vbFamilyNew, vnProtNew);
  ptab5 = new TabImport();


  //  CONNECTORS
  connect(this,  SIGNAL(changeToTab1(int, int)),
          ptab1, SLOT(changeById(int, int))     );
  connect(this,  SIGNAL(changeToTab1(int, int)),
          ptab2, SLOT(changeById(int, int))     );
  connect(ptab1, SIGNAL(saveFam()),
          this,  SLOT(saveFamToMain()) );
  connect(ptab1, SIGNAL(saveFam()),
          ptab2, SLOT(changeNumbProt()) );
  connect(this,  SIGNAL(changeToTab1(int, int)),
          ptab3, SLOT(changeById(int, int))     );
  connect(ptab4, SIGNAL(sendImport(QString& , QString& )),
          ptab5, SLOT(setImport(QString& , QString& )) );

  connect(ptab4, SIGNAL(sendImport(QString& , QString& )),
          this,  SLOT(setView(QString& , QString& )) );

  connect(ptab5, SIGNAL(setSave(QString& , QString& )),
          ptab4, SLOT(loadFromViewTab(QString& , QString& )) );

  //ACTIONS

  // LAYOUT
  this->addTab(ptab1, "New Protein");
  this->addTab(ptab2, "Edit Protein");
  this->addTab(ptab3, "Family Information");
  this->addTab(ptab4, "Alignment");
  this->addTab(ptab5, "View");


  this->setStyleSheet(
      "QTabBar::tab { background: gray; color: white; padding: 10px; } "
      "QTabBar::tab:selected { background: lightgray; } "
      /*"QTabWidget::pane { border: 0; } "*/
      /*"QWidget { background: lightgray; } "*/);
}
