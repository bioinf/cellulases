#include "nirMyWnd.h"
#include <QtGui>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyWnd w;
  w.setWindowState(Qt::WindowMaximized);
	w.show();
	w.setWindowTitle("Analysis of cellulases");
	return a.exec();
}




