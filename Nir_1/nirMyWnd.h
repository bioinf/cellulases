#ifndef _NIR_MY_WND_
#define _NIR_MY_WND_

#include <QtGui/QMainWindow>
#include <QtGui>
#include <QVector>
#include <QString>
#include <QFile>
#include <QTextStream>

#include "nirTabMain.h"


//*************************************************************************
//          MAIN WINDOW
//*************************************************************************
class MyWnd : public QWidget
{
  Q_OBJECT

public:
  MyWnd(QWidget *parent = 0, Qt::WFlags flags = 0);
  ~MyWnd();

private:
  MyTabWidgetMain*  ptabwMain;

signals:

public slots:

};



#endif // _NIR_MY_WND_
