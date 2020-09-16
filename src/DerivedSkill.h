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
	//���ϡ�ж���SP��һЩ���ݽ�������
public slots:
	void AddLevel();
	void DelLevel();


private:
	//����ͼ��
	QLineEdit* SkillIcon, * SkillName;
	QPushButton* pbAddLevel, * pbDelLevel;
	QTabWidget* twLevel;
	//��������
	SkillDesc* Desc;

};

