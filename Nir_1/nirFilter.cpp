#include "nirFilter.h"


//*************************************************************************
//          RADIO GROUP
//*************************************************************************
GroupRadioButton::GroupRadioButton(QString sName, int id, QWidget *parent)
  :QWidget(parent)
{
  groupBox = new QGroupBox(sName);

  radio1 = new QRadioButton(tr("0"));
  radio2 = new QRadioButton(tr("1"));
  radio3 = new QRadioButton(tr("*"));

  QVBoxLayout *vbox = new QVBoxLayout;
  vbox->setAlignment(Qt::AlignTop);
  vbox->addWidget(radio1);
  vbox->addWidget(radio2);
  vbox->addWidget(radio3);
  //vbox->addStretch(1);

  radio3->setChecked(true);

  groupBox->setLayout(vbox);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(groupBox);
  this->setLayout(layout);
};
int GroupRadioButton::checkedNmb()
{
  if (radio1->isChecked())
    return 1;
  else if (radio2->isChecked())
    return 2;
  else
    return 3;
}

//*************************************************************************
//          FILTER WIDGET
//*************************************************************************


FilterWidget::FilterWidget(QWidget *parent)
  :QWidget(parent)
  {
    pbFilter = new QPushButton("Filter!");

    connect(pbFilter, SIGNAL(clicked()),
            this,     SLOT(makeFilter()) );

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setAlignment(Qt::AlignTop);


    GroupRadioButton* grTmp;
    grTmp = new GroupRadioButton("C", 0);
    vGroupRadio.push_back(grTmp);
    layout->addWidget(grTmp);
    grTmp = new GroupRadioButton("X", 1);
    vGroupRadio.push_back(grTmp);
    layout->addWidget(grTmp);
    grTmp = new GroupRadioButton("S", 2);
    vGroupRadio.push_back(grTmp);
    layout->addWidget(grTmp);
    grTmp = new GroupRadioButton("M", 3);
    vGroupRadio.push_back(grTmp);
    layout->addWidget(grTmp);
    grTmp = new GroupRadioButton("A", 4);
    vGroupRadio.push_back(grTmp);
    layout->addWidget(grTmp);
    grTmp = new GroupRadioButton("L", 5);
    vGroupRadio.push_back(grTmp);
    layout->addWidget(grTmp);
    layout->addWidget(pbFilter);
    this->setLayout(layout);
  };

void FilterWidget::makeFilter()
{
  int mask = 0;
  for (int i = 0; i < vGroupRadio.size(); ++i)
  {
    mask += vGroupRadio.at(i)->checkedNmb()<<(2*i);
  }
  emit sendFinter(mask);
}
void FilterWidget::initFilter()
{
  for (int i = 0; i < vGroupRadio.size(); ++i)
  {
    vGroupRadio.at(i)->radio3->setChecked(true);
  }
}
QString FilterWidget::getFilter()
{
  QString sres("");
  sres += "Hydrolytic Activity\n[C X S M A L]\n[";
  for (int i = 0; i < vGroupRadio.size(); ++i)
  {
    if( vGroupRadio.at(i)->radio1->isChecked() )
      sres += "0 ";
    else if( vGroupRadio.at(i)->radio2->isChecked() )
      sres += "1 ";
    else //if( vGroupRadio.at(i)->radio3->isChecked() )
      sres += "* ";
  }
  sres += "]\n";
  return sres;
}