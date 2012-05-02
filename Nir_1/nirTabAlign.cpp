#include "nirTabAlign.h"
#include "nirStrNameProt.h"

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
    arguments << "-align" << "-infile=align_in.fasta" << "-type=protein" << "-outfile=align_out.aln" << ">>" << "align_log.txt";   
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

/*    arguments << "-infile=align_in.fasta" <<
                 "-outfile=align_out.aln" <<
                 "-align" <<
                 "-type=protein" <<
                 "-ktuple=1" <<
                 "-window=5" <<
                 "-score=percent" <<
                 "-topdiags=5" <<
                 "-pairgap=3" <<
                 "-pwmatrix=gonnet" <<
                 "-pwdnamatrix=iub" <<
                 "-pwgapopen=10" <<
                 "-pwgapext=0.1" <<
                 "-matrix=gonnet" <<
                 "-dnamatrix=iub" <<
                 "-gapopen=10" <<
                 "-gapext=0.2" <<
                 "-gapdist=5" <<
                 "-iteration=none" <<
                 "-numiter=1" <<
                 "-clustering=NJ" <<
                 "-seqnos=on" <<
                 "-outorder=aligned" <<
                 ">>" <<
                 "align_log.txt"; */  
    arguments << "-align" << "-infile=align_in.fasta" << "-type=protein" << "-outfile=align_out.aln" ;//<< ">>" << "align_log.txt"; 
    QProcess *myProcess = new QProcess();
    myProcess->start(program, arguments);
    myProcess->waitForStarted();
    myProcess->waitForFinished();
    myProcess->waitForReadyRead();    

    QFile fLog("align_log.txt");
    fLog.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream streamLog(&fLog);
    streamLog << myProcess->readAll();
    fLog.close();
    //bool flWait = myProcess->waitForFinished(-1);


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


MyTabWidgetAlign::MyTabWidgetAlign(QVector<FamilyButton*>* vbFamilyNew, QVector<int>* vnProtNew,QWidget* parent)
    :QTabWidget(parent)
{
  // INIT
  ptab4 = new TabAlignment(vbFamilyNew, vnProtNew);
  ptab5 = new TabImport();


  //  CONNECTORS
  connect(ptab4, SIGNAL(sendImport(QString& , QString& )),
          ptab5, SLOT(setImport(QString& , QString& )) );
  connect(ptab4, SIGNAL(sendImport(QString& , QString& )),
          this,  SLOT(setView(QString& , QString& )) );
  connect(ptab5, SIGNAL(setSave(QString& , QString& )),
          ptab4, SLOT(loadFromViewTab(QString& , QString& )) );

  //ACTIONS

  // LAYOUT
  this->addTab(ptab4, "Alignment");
  this->addTab(ptab5, "View");


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