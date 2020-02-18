#pragma once

#include <QWidget>
#include <QtGui>
#include <QtWidgets>

class SkillDesc;
class SingleSkillForm :public QWidget
{
	Q_OBJECT
public:
	SingleSkillForm(QWidget* _parent = 0);
	~SingleSkillForm();

private slots:
	void AddLevel();
	void DelLevel();
	void AddRemark();
	void DelRemark();
	void AddDerive();
	void DelDerive();
	void getData(QString, QString);

private:

	QLineEdit* LeIcon;//技能的图标
	QLineEdit* LeName;//技能的名称
	QLineEdit* LeDialogue;//技能的台词

	//增加/删除一个技能等级
	QPushButton* pbAddLevel, * pbDelLevel;
	//使用/禁止衍生技能
	QPushButton* pbAddDerive;
	QPushButton* pbDelDerive;
	//使用/禁止备注
	QPushButton* pbAddRemark;
	QPushButton* pbDelRemark;


	QTabWidget* twDesc;//技能的描述
	QTabWidget* twDerive;
	QTabWidget* twRemark;
	std::vector<SkillDesc*> sdDesc;
	QString Color;
};

