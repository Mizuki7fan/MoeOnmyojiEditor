#pragma once
#include <QWidget>
#include <QtGui>
#include <QtWidgets>
#include <vector>
#include <QStackedWidget>
#include "SkillInfo.h"

class SingleSkillForm;
class SkillForm :public QWidget
{
	Q_OBJECT;
public:
	SkillForm(QWidget* _parent = 0);
	~SkillForm();

	void fill(data_SkillInfo);
	data_SkillInfo getData();

public slots:
	void addSkill();
	void delSkill();

private:
	//添加技能
	QPushButton *pbAdd;
	//删除技能
	QPushButton *pbDel;
	//播放技能的tab
	QTabWidget *twSkill;
	
	std::vector<SingleSkillForm*> sfSkillForm;


};