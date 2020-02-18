#pragma once

#include <QWidget>
#include <QtGui>
#include <QtWidgets>

class SkinForm :public QWidget
{
	Q_OBJECT
public:
	SkinForm(QWidget* _parent = 0);
	~SkinForm();

	QString getLeName();
	QString getSkin();

private:
	QLineEdit* LeName;
	QLineEdit* LeSkin;
};

