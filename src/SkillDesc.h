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
	QLineEdit *LeCd;//������ȴ
	QLineEdit *LeCost;//�������
	QRadioButton* RbIsPassive, * RbNotPassive, * RbOnlyDesc;//��������/��������/������
	QButtonGroup* BgPassive;
	QTextEdit* TeDesc;//���ܵ�����

};
