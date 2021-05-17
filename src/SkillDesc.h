#pragma once

#include <QWidget>
#include <QtGui>
#include <QtWidgets>

class SkillDesc :public QWidget
{
	Q_OBJECT
public:
	SkillDesc(QWidget* _parent = 0);
	~SkillDesc();
	//void CopyInfo(const SkillDesc& copy);
public slots:
	void ChangeState(int i);

private:
	QLabel* LCd, * LCost, * LPassive;
	QLineEdit *LeCd;//技能冷却
	QLineEdit *LeCost;//鬼火消耗
	QRadioButton* RbIsPassive, * RbNotPassive, * RbOnlyDesc;//主动技能/被动技能/无描述
	QButtonGroup* BgPassive;
	QTextEdit* TeDesc;//技能的描述

};
