#ifndef _NIR_FILTER_
#define _NIR_FILTER_

#include <QtGui>
#include <QString>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QVector>

//*************************************************************************
//          RADIO GROUP
//*************************************************************************
class GroupRadioButton : public QWidget
{
  Q_OBJECT
public:
  GroupRadioButton(QString sName, int id, QWidget *parent = 0);
  int checkedNmb();

//private:

  QGroupBox*      groupBox;

  QRadioButton*   radio1;
  QRadioButton*   radio2;
  QRadioButton*   radio3;

signals:


public slots:

};


//*************************************************************************
//          FILTER WIDGET
//*************************************************************************
class FilterWidget : public QWidget
{
  Q_OBJECT
public:
  FilterWidget(QWidget *parent = 0);
//C X S M A L

  void initFilter();
  QString getFilter();
private:

  QVector<GroupRadioButton*> vGroupRadio;
  QPushButton*               pbFilter;

signals:
  void sendFinter(int);


public slots:
  void makeFilter();

};

#endif // _NIR_FILTER_






//     QGroupBox *groupBox = new QGroupBox(tr("Exclusive Radio Buttons"));

