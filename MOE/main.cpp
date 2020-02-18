#include "mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QFont f("Microsoft YaHei", 10, 50);
	a.setFont(f);
	MainWindow w;
	w.showNormal();
	//w.showMaximized();
	return a.exec();
}
