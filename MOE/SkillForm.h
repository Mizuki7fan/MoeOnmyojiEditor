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
	//��Ӽ���
	QPushButton *pbAdd;
	//ɾ������
	QPushButton *pbDel;
	//���ż��ܵ�tab
	QTabWidget *twSkill;
	
	std::vector<SingleSkillForm*> sfSkillForm;


};