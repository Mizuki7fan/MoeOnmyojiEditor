#include "BasicInfoForm.h"
#include "SkinForm.h"

#include <iostream>

BasicInfoForm::BasicInfoForm(QWidget* parent)
	:QWidget(parent)
{
	//������һ��ֻ֧��2�У����Բ����ã�ʹ�����񲼾�
	QGridLayout* layout = new QGridLayout();
	QFont fontBold("Microsoft YaHei", -1, 75);
	QStringList RarityList;
	RarityList << "SSR" << "SP" << "SR" << "R" << "N";
	QStringList RankList;
	RankList << "SS" << "S" << "A" << "B" << "C" << "D";

	//ʽ��������
	LeName = new QLineEdit();
	LeName->setPlaceholderText(QStringLiteral("���������磺�����"));
	LeName->setAlignment(Qt::AlignCenter);
	LeName->setFont(fontBold);
	// ��������ʼ���С��кţ�����������
	layout->addWidget(LeName, 0, 0, 1, 6);
	LeNameHiragara = new QLineEdit();
	LeNameHiragara->setPlaceholderText(QStringLiteral("ƽ�������磺�����礦�դ�����"));
	LeNameHiragara->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeNameHiragara, 1, 0, 1, 6);
	QLabel* LCv = new QLabel(QStringLiteral("����"));
	LCv->setAlignment(Qt::AlignCenter);
	LCv->setFont(fontBold);
	layout->addWidget(LCv, 1, 6, 1, 2);
	LeCv = new QLineEdit();
	LeCv->setPlaceholderText(QStringLiteral("�磺���ɳ֯"));
	LeCv->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeCv, 2, 6, 1, 2);


	QLabel* LRarity = new QLabel(QStringLiteral("ϡ�ж�"));
	LRarity->setAlignment(Qt::AlignCenter);
	LRarity->setFont(fontBold);
	layout->addWidget(LRarity, 1, 8, 1, 2);

	LeRarity = new QComboBox();
	LeRarity->addItems(RarityList);
	connect(LeRarity, SIGNAL(currentIndexChanged(int)), this, SLOT(doHide(int)));
	layout->addWidget(LeRarity, 2, 8, 1, 2);

	LeNameJP = new QLineEdit();
	LeNameJP->setPlaceholderText(QStringLiteral("���ﺺ�֣��磺���B�L��"));
	LeNameJP->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeNameJP, 2, 0, 1, 6);

	QLabel* LAtk = new  QLabel(QStringLiteral("����"));
	LAtk->setAlignment(Qt::AlignCenter);
	LAtk->setFont(fontBold);
	layout->addWidget(LAtk, 3, 1, 1, 1);

	QLabel* LHp = new  QLabel(QStringLiteral("����"));
	LHp->setAlignment(Qt::AlignCenter);
	LHp->setFont(fontBold);
	layout->addWidget(LHp, 3, 2, 1, 1);

	QLabel* LDef = new  QLabel(QStringLiteral("����"));
	LDef->setAlignment(Qt::AlignCenter);
	LDef->setFont(fontBold);
	layout->addWidget(LDef, 3, 3, 1, 1);

	QLabel* LSpd = new  QLabel(QStringLiteral("�ٶ�"));
	LSpd->setAlignment(Qt::AlignCenter);
	LSpd->setFont(fontBold);
	layout->addWidget(LSpd, 3, 4, 1, 1);

	QLabel* LCrt = new  QLabel(QStringLiteral("����"));
	LCrt->setAlignment(Qt::AlignCenter);
	LCrt->setFont(fontBold);
	layout->addWidget(LCrt, 3, 5, 1, 1);

	QLabel* LGetway = new  QLabel(QStringLiteral("��÷�ʽ"));
	LGetway->setAlignment(Qt::AlignCenter);
	LGetway->setFont(fontBold);
	layout->addWidget(LGetway, 3, 6, 1, 2);

	LeGetway = new QLineEdit();
	LeGetway->setPlaceholderText(QStringLiteral("�磺�鿨"));
	LeGetway->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeGetway, 4, 6, 1, 2);

	QLabel* LRegion = new QLabel(QStringLiteral("�����ռ�"));
	LRegion->setAlignment(Qt::AlignCenter);
	LRegion->setFont(fontBold);
	layout->addWidget(LRegion, 3, 8, 1, 2);

	LeRegion = new QLineEdit();
	LeRegion->setPlaceholderText(QStringLiteral("�磺�Ĺ�����֮��"));
	LeRegion->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeRegion, 4, 8, 1, 2);

	QLabel* LNotAwakened = new QLabel(QStringLiteral("δ����"));
	LNotAwakened->setAlignment(Qt::AlignCenter);
	LNotAwakened->setFont(fontBold);
	layout->addWidget(LNotAwakened, 4, 0, 1, 1);

	QLabel* LLv1 = new QLabel(QStringLiteral("1��"));
	LLv1->setAlignment(Qt::AlignCenter);
	LLv1->setFont(fontBold);
	layout->addWidget(LLv1, 5, 0, 1, 1);

	QLabel* LAwakened = new QLabel(QStringLiteral("����"));
	LAwakened->setAlignment(Qt::AlignCenter);
	LAwakened->setFont(fontBold);
	layout->addWidget(LAwakened, 6, 0, 1, 1);

	QLabel* LLv40 = new QLabel(QStringLiteral("40��"));
	LLv40->setAlignment(Qt::AlignCenter);
	LLv40->setFont(fontBold);
	layout->addWidget(LLv40, 7, 0, 1, 1);

	//�������壬��ҪԤ�����ú������С
	N_A_Rank.resize(5);
	N_A_Value.resize(8);
	A_Rank.resize(5);
	A_Value.resize(8);
	for (int i = 0; i < 5; i++)
	{
		N_A_Rank[i] = new QComboBox();
		N_A_Rank[i]->addItems(RankList);
		layout->addWidget(N_A_Rank[i], 4, i + 1, 1, 1);
		A_Rank[i] = new QComboBox();
		A_Rank[i]->addItems(RankList);
		layout->addWidget(A_Rank[i], 6, i + 1, 1, 1);
		N_A_Value[i] = new QLineEdit();
		N_A_Value[i]->setAlignment(Qt::AlignCenter);
		layout->addWidget(N_A_Value[i], 5, i + 1, 1, 1);
		A_Value[i] = new QLineEdit();
		A_Value[i]->setAlignment(Qt::AlignCenter);
		layout->addWidget(A_Value[i], 7, i + 1, 1, 1);
	}
	QLabel* LCdt = new QLabel(QStringLiteral("�����˺�"));
	LCdt->setAlignment(Qt::AlignCenter);
	LCdt->setFont(fontBold);
	layout->addWidget(LCdt, 8, 1, 1, 1);

	QLabel* LHr = new QLabel(QStringLiteral("Ч������"));
	LHr->setAlignment(Qt::AlignCenter);
	LHr->setFont(fontBold);
	layout->addWidget(LHr, 8, 2, 1, 1);

	QLabel* LResist = new QLabel(QStringLiteral("Ч���ֿ�"));
	LResist->setAlignment(Qt::AlignCenter);
	LResist->setFont(fontBold);
	layout->addWidget(LResist, 8, 3, 1, 1);

	QLabel* LNA = new QLabel(QStringLiteral("δ����"));
	LNA->setAlignment(Qt::AlignCenter);
	LNA->setFont(fontBold);
	layout->addWidget(LNA, 9, 0, 1, 1);

	QLabel* LA = new QLabel(QStringLiteral("����"));
	LA->setAlignment(Qt::AlignCenter);
	LA->setFont(fontBold);
	layout->addWidget(LA, 10, 0, 1, 1);

	for (int i = 5; i < 8; i++)
	{
		N_A_Value[i] = new QLineEdit();
		N_A_Value[i]->setAlignment(Qt::AlignCenter);
		layout->addWidget(N_A_Value[i], 9, i - 4, 1, 1);
		A_Value[i] = new QLineEdit();
		A_Value[i]->setAlignment(Qt::AlignCenter);
		layout->addWidget(A_Value[i], 10, i - 4, 1, 1);
	}
	QLabel* LAEffect = new QLabel(QStringLiteral("����Ч��"));
	LAEffect->setAlignment(Qt::AlignCenter);
	LAEffect->setFont(fontBold);
	layout->addWidget(LAEffect, 11, 0, 1, 1);

	LeAEffectKind = new QLineEdit();
	LeAEffectKind->setPlaceholderText(QStringLiteral("�磺��Ӽ���"));
	LeAEffectKind->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeAEffectKind, 11, 1, 1, 1);

	LeAEffect = new QLineEdit();
	LeAEffect->setPlaceholderText(QStringLiteral("�磺��Ӱ"));
	LeAEffect->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeAEffect, 11, 2, 1, 4);

	QLabel* LAlias = new QLabel(QStringLiteral("���"));
	LAlias->setAlignment(Qt::AlignCenter);
	LAlias->setFont(fontBold);
	layout->addWidget(LAlias, 12, 0, 1, 1);

	LeAlias = new QLineEdit();
	LeAlias->setPlaceholderText(QStringLiteral("�磺���Ӿ�"));
	LeAlias->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeAlias, 12, 1, 1, 5);

	QLabel* LRevelant = new QLabel(QStringLiteral("��ؽ�ɫ"));
	LRevelant->setAlignment(Qt::AlignCenter);
	LRevelant->setFont(fontBold);
	layout->addWidget(LRevelant, 13, 0, 1, 1);

	LeRelevant = new QLineEdit();
	LeRelevant->setPlaceholderText(QStringLiteral("�磺��ï����"));
	LeRelevant->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeRelevant, 13, 1, 1, 5);

	TeIntro = new QTextEdit();
	TeIntro->setPlaceholderText(QStringLiteral("ʽ����"));
	TeIntro->setAlignment(Qt::AlignCenter);
	layout->addWidget(TeIntro, 14, 0, 8, 6);

	twSkin = new QTabWidget();
	layout->addWidget(twSkin, 6, 6, 16, 4);

	pbAddSkin = new QPushButton(QStringLiteral("�������"));
	layout->addWidget(pbAddSkin, 5, 6, 1, 2);
	connect(pbAddSkin, SIGNAL(clicked()), this, SLOT(addSkin()));


	pbDelSkin = new QPushButton(QStringLiteral("ɾ������"));
	layout->addWidget(pbDelSkin, 5, 8, 1, 2);
	connect(pbDelSkin, SIGNAL(clicked()), this, SLOT(delSkin()));

	this->setLayout(layout);
}

BasicInfoForm::~BasicInfoForm()
{

}

void BasicInfoForm::addSkin()
{
	SkinForm* tmp = new SkinForm();
	sfSkin.push_back(tmp);
	twSkin->addTab(tmp, QString::number(sfSkin.size()));
}

void BasicInfoForm::delSkin()
{
	if (sfSkin.size() == 0)
		return;
	else
	{
		sfSkin.pop_back();
		//ɾ������tab
		int c = twSkin->count();
		QWidget* p = twSkin->widget(c - 1);
		if (0 != p)
		{
			delete p;
			p = NULL;
		}
	}
}

void BasicInfoForm::fill(data_BasicInfo data)
{
	this->LeName->setText(data.NameCN);
	this->LeNameJP->setText(data.NameJP);
	this->LeNameHiragara->setText(data.NameHiragara);
	this->LeCv->setText(data.CV);
	this->LeRarity->setCurrentText(data.Rarity);
	this->LeGetway->setText(data.Getway);
	this->LeRegion->setText(data.Region);
	this->N_A_Rank[0]->setCurrentText(data.NAAtkRank);//δ���ѵ���ά��ֵ
	this->N_A_Rank[1]->setCurrentText(data.NAHpRank);
	this->N_A_Rank[2]->setCurrentText(data.NADefRank);
	this->N_A_Rank[3]->setCurrentText(data.NASpdRank);
	this->N_A_Rank[4]->setCurrentText(data.NACrtRank);
	this->A_Rank[0]->setCurrentText(data.AAtkRank);//���ѵ���ά��ֵ
	this->A_Rank[1]->setCurrentText(data.AHpRank);
	this->A_Rank[2]->setCurrentText(data.ADefRank);
	this->A_Rank[3]->setCurrentText(data.ASpdRank);
	this->A_Rank[4]->setCurrentText(data.ACrtRank);

	this->N_A_Value[0]->setText(data.NAAtk);//1������ֵ
	this->N_A_Value[1]->setText(data.NAHp);
	this->N_A_Value[2]->setText(data.NADef);
	this->N_A_Value[3]->setText(data.NASpd);
	this->N_A_Value[4]->setText(data.NACrt);
	this->N_A_Value[5]->setText(data.NACtd);
	this->N_A_Value[6]->setText(data.NAHr);
	this->N_A_Value[7]->setText(data.NAResist);

	this->A_Value[0]->setText(data.AAtk);//40������ֵ
	this->A_Value[1]->setText(data.AHp);
	this->A_Value[2]->setText(data.ADef);
	this->A_Value[3]->setText(data.ASpd);
	this->A_Value[4]->setText(data.ACrt);
	this->A_Value[5]->setText(data.ACtd);
	this->A_Value[6]->setText(data.AHr);
	this->A_Value[7]->setText(data.AResist);

	this->LeAEffect->setText(data.AEffect);
	this->LeAEffectKind->setText(data.AEffectKind);
	this->LeAlias->setText(data.Alias);
	this->LeRelevant->setText(data.Relevant);
	this->TeIntro->setText(data.Intro);

	int k = data.SkinName.size();
	for (int i = 0; i < k; i++)
	{
		SkinForm* tmp = new SkinForm();
		tmp->findChild<QLineEdit*>("LeName")->setText(data.SkinName[i]);
		tmp->findChild<QLineEdit*>("LeSkin")->setText(data.SkinPng[i]);
		twSkin->addTab(tmp, data.SkinName[i]);
	}
}

data_BasicInfo BasicInfoForm::getData()
{
	data_BasicInfo result;
	result.NameCN = this->LeName->text();
	result.NameJP = this->LeNameJP->text();
	result.NameHiragara = this->LeNameHiragara->text();
	result.CV = this->LeCv->text();
	result.Rarity = this->LeRarity->currentText();//���Ǹ�combobox
	result.Getway = this->LeGetway->text();
	result.Region = this->LeRegion->text();
	result.NAAtkRank = this->N_A_Rank[0]->currentText();//δ���ѵ���ά��ֵ
	result.NAHpRank = this->N_A_Rank[1]->currentText();
	result.NADefRank = this->N_A_Rank[2]->currentText();
	result.NASpdRank = this->N_A_Rank[3]->currentText();
	result.NACrtRank = this->N_A_Rank[4]->currentText();
	result.AAtkRank = this->A_Rank[0]->currentText();//���ѵ���ά��ֵ
	result.AHpRank = this->A_Rank[1]->currentText();
	result.ADefRank = this->A_Rank[2]->currentText();
	result.ASpdRank = this->A_Rank[3]->currentText();
	result.ACrtRank = this->A_Rank[4]->currentText();

	result.NAAtk = this->N_A_Value[0]->text();//1������ֵ
	result.NAHp = this->N_A_Value[1]->text();
	result.NADef = this->N_A_Value[2]->text();
	result.NASpd = this->N_A_Value[3]->text();
	result.NACrt = this->N_A_Value[4]->text();
	result.NACtd = this->N_A_Value[5]->text();
	result.NAHr = this->N_A_Value[6]->text();
	result.NAResist = this->N_A_Value[7]->text();

	result.AAtk = this->A_Value[0]->text();//40������ֵ
	result.AHp = this->A_Value[1]->text();
	result.ADef = this->A_Value[2]->text();
	result.ASpd = this->A_Value[3]->text();
	result.ACrt = this->A_Value[4]->text();
	result.ACtd = this->A_Value[5]->text();
	result.AHr = this->A_Value[6]->text();
	result.AResist = this->A_Value[7]->text();

	result.AEffect = this->LeAEffect->text();
	result.AEffectKind = this->LeAEffectKind->text();
	result.Alias = this->LeAlias->text();
	result.Relevant = this->LeRelevant->text();

	result.Intro = this->TeIntro->toPlainText();

	int k = this->twSkin->count();
	for (int i = 0; i < k; i++)
	{
		result.SkinName.push_back(twSkin->widget(i)->findChild<QLineEdit*>("LeName")->text());
		result.SkinPng.push_back(twSkin->widget(i)->findChild<QLineEdit*>("LeSkin")->text());
	}
	return result;
}

void BasicInfoForm::doHide(int k)
{
	//���ڿ���ģ������أ�����LeRarity��ֵΪk����k=1��ʱ���ʾʽ��ϡ�ж���SP��һЩ��ĿӦ���޸�
	if (k == 1 || k==4)
	{
		for (int i = 0; i < 5; i++)
			A_Rank[i]->setEnabled(false);
		for (int i = 5; i < 8; i++)
			A_Value[i]->setEnabled(false);
		LeAEffect->setEnabled(false);
		LeAEffectKind->setEnabled(false);
	}
	else
	{
		for (int i = 0; i < 5; i++)
			A_Rank[i]->setEnabled(true);
		for (int i = 0; i < 8; i++)
			A_Value[i]->setEnabled(true);
		LeAEffect->setEnabled(true);
		LeAEffectKind->setEnabled(true);
	}
}
