#pragma once
#include <QWidget>
#include <QtGui>
#include <QtWidgets>
#include <vector>

class SkillDesc;
class DerivedSkill :public QWidget
{
	Q_OBJECT
public:
	DerivedSkill(QWidget* _parent = 0);
	~DerivedSkill();
	//如果稀有度是SP则将一些内容进行隐藏
public slots:
	void AddLevel();
	void DelLevel();


private:
	//技能图标
	QLineEdit* SkillIcon, * SkillName;
	QPushButton* pbAddLevel, * pbDelLevel;
	QTabWidget* twLevel;
	//技能描述
	SkillDesc* Desc;

};

