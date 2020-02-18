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
	//如果稀有度是SP则将一些内容进行隐藏
public slots:
	void doHide(int);
	void addSkin();
	void delSkin();

private:
	QLineEdit* LeName;//式神名字
	QLineEdit* LeNameHiragara;//日文名字
	QLineEdit* LeNameJP;//日文汉字
	QLineEdit* LeCv;//声优
	QLineEdit* LeGetway;
	QLineEdit* LeRegion;
	QComboBox* LeRarity;//稀有度
	std::vector<QComboBox*> N_A_Rank;//未觉醒的五项数值
	std::vector<QLineEdit*> N_A_Value;
	std::vector<QComboBox*> A_Rank;
	std::vector<QLineEdit*> A_Value;
	QLineEdit* LeAEffectKind;
	QLineEdit* LeAEffect;
	QLineEdit* LeAlias;
	QLineEdit* LeRelevant;
	QTextEdit* TeIntro;
	QTextEdit* TeSkin;

	//添加皮肤，删除皮肤
	QPushButton* pbAddSkin, * pbDelSkin;
	//皮肤区域的tabWidget
	QTabWidget* twSkin;
	//皮肤区域tabWidget的数值

	std::vector<SkinForm*> sfSkin;

};

