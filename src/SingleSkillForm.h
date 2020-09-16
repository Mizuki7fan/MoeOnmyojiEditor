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

	QLineEdit* LeIcon;//���ܵ�ͼ��
	QLineEdit* LeName;//���ܵ�����
	QLineEdit* LeDialogue;//���ܵ�̨��

	//����/ɾ��һ�����ܵȼ�
	QPushButton* pbAddLevel, * pbDelLevel;
	//ʹ��/��ֹ��������
	QPushButton* pbAddDerive;
	QPushButton* pbDelDerive;
	//ʹ��/��ֹ��ע
	QPushButton* pbAddRemark;
	QPushButton* pbDelRemark;


	QTabWidget* twDesc;//���ܵ�����
	QTabWidget* twDerive;
	QTabWidget* twRemark;
	std::vector<SkillDesc*> sdDesc;
	QString Color;
};

