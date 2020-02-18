#pragma once
#include <QWidget>
#include <QtGui>
#include <QtWidgets>
#include <vector>
#include "BasicInfo.h"

class SkinForm;

class BasicInfoForm:public QWidget
{
	Q_OBJECT
public:
	BasicInfoForm(QWidget* _parent = 0);
	~BasicInfoForm();

	void fill(data_BasicInfo);
	data_BasicInfo getData();
	//���ϡ�ж���SP��һЩ���ݽ�������
public slots:
	void doHide(int);
	void addSkin();
	void delSkin();

private:
	QLineEdit* LeName;//ʽ������
	QLineEdit* LeNameHiragara;//��������
	QLineEdit* LeNameJP;//���ĺ���
	QLineEdit* LeCv;//����
	QLineEdit* LeGetway;
	QLineEdit* LeRegion;
	QComboBox* LeRarity;//ϡ�ж�
	std::vector<QComboBox*> N_A_Rank;//δ���ѵ�������ֵ
	std::vector<QLineEdit*> N_A_Value;
	std::vector<QComboBox*> A_Rank;
	std::vector<QLineEdit*> A_Value;
	QLineEdit* LeAEffectKind;
	QLineEdit* LeAEffect;
	QLineEdit* LeAlias;
	QLineEdit* LeRelevant;
	QTextEdit* TeIntro;
	QTextEdit* TeSkin;

	//���Ƥ����ɾ��Ƥ��
	QPushButton* pbAddSkin, * pbDelSkin;
	//Ƥ�������tabWidget
	QTabWidget* twSkin;
	//Ƥ������tabWidget����ֵ

	std::vector<SkinForm*> sfSkin;

};

