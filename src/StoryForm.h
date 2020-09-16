#pragma once

#include <QWidget>
#include <QtGui>
#include <QtWidgets>
#include <vector>
#include "StoryInfo.h"

class StoryForm :public QWidget
{
	Q_OBJECT
public:
	StoryForm(QWidget* _parent = 0);
	~StoryForm();

	void fill(data_Story);
	data_Story getData();

public slots:
	void AddOne();
	void DelOne();
private:

	std::vector<QLabel*> vLName;
	std::vector<QLineEdit*> LeCondition;
	std::vector<QLineEdit*> LeAward;
	std::vector<QLineEdit*> LePlay;
	std::vector<QTextEdit*> TeContent;

	QPushButton* pbAdd, * pbDel;
	QTabWidget* twTab;

};
