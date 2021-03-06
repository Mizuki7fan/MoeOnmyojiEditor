#include "BasicInfoForm.h"
#include "SkinForm.h"

#include <iostream>

BasicInfoForm::BasicInfoForm(QWidget* parent)
	:QWidget(parent)
{
	//燕汽下蕉匯違峪屶隔2双��侭參音癖喘��聞喘利鯉下蕉
	QGridLayout* layout = new QGridLayout();
	QFont fontBold("Microsoft YaHei", -1, 75);
	QStringList RarityList;
	RarityList << "SSR" << "SP" << "SR" << "R" << "N";
	QStringList RankList;
	RankList << "SS" << "S" << "A" << "B" << "C" << "D";

	//塀舞嶄猟兆
	LeName = new QLineEdit();
	LeName->setPlaceholderText(QStringLiteral("嶄猟兆��泌�沙�抵壌"));
	LeName->setAlignment(Qt::AlignCenter);
	LeName->setFont(fontBold);
	LeName->setObjectName("LeName");
	// 歌方�再霾宍槻弌∩从釘�佩方��双方
	layout->addWidget(LeName, 0, 0, 1, 6);
	LeNameHiragara = new QLineEdit();
	LeNameHiragara->setPlaceholderText(QStringLiteral("峠邪兆��泌�困�ちょうふうげつ"));
	LeNameHiragara->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeNameHiragara, 1, 0, 1, 6);
	QLabel* LCv = new QLabel(QStringLiteral("蕗單"));
	LCv->setAlignment(Qt::AlignCenter);
	LCv->setFont(fontBold);
	layout->addWidget(LCv, 1, 6, 1, 2);
	LeCv = new QLineEdit();
	LeCv->setPlaceholderText(QStringLiteral("泌�犀膽�紐岶"));
	LeCv->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeCv, 2, 6, 1, 2);


	QLabel* LRarity = new QLabel(QStringLiteral("蓮嗤業"));
	LRarity->setAlignment(Qt::AlignCenter);
	LRarity->setFont(fontBold);
	layout->addWidget(LRarity, 1, 8, 1, 2);

	LeRarity = new QComboBox();
	LeRarity->addItems(RarityList);
	connect(LeRarity, SIGNAL(currentIndexChanged(int)), this, SLOT(doHide(int)));
	layout->addWidget(LeRarity, 2, 8, 1, 2);

	LeNameJP = new QLineEdit();
	LeNameJP->setPlaceholderText(QStringLiteral("晩囂査忖��泌�沙��B�L埖"));
	LeNameJP->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeNameJP, 2, 0, 1, 6);

	QLabel* LAtk = new  QLabel(QStringLiteral("好似"));
	LAtk->setAlignment(Qt::AlignCenter);
	LAtk->setFont(fontBold);
	layout->addWidget(LAtk, 3, 1, 1, 1);

	QLabel* LHp = new  QLabel(QStringLiteral("伏凋"));
	LHp->setAlignment(Qt::AlignCenter);
	LHp->setFont(fontBold);
	layout->addWidget(LHp, 3, 2, 1, 1);

	QLabel* LDef = new  QLabel(QStringLiteral("契囮"));
	LDef->setAlignment(Qt::AlignCenter);
	LDef->setFont(fontBold);
	layout->addWidget(LDef, 3, 3, 1, 1);

	QLabel* LSpd = new  QLabel(QStringLiteral("堀業"));
	LSpd->setAlignment(Qt::AlignCenter);
	LSpd->setFont(fontBold);
	layout->addWidget(LSpd, 3, 4, 1, 1);

	QLabel* LCrt = new  QLabel(QStringLiteral("羽似"));
	LCrt->setAlignment(Qt::AlignCenter);
	LCrt->setFont(fontBold);
	layout->addWidget(LCrt, 3, 5, 1, 1);

	QLabel* LGetway = new  QLabel(QStringLiteral("資誼圭塀"));
	LGetway->setAlignment(Qt::AlignCenter);
	LGetway->setFont(fontBold);
	layout->addWidget(LGetway, 3, 6, 1, 2);

	LeGetway = new QLineEdit();
	LeGetway->setPlaceholderText(QStringLiteral("泌�些蘓�"));
	LeGetway->setText(QStringLiteral("孰蚕、為麹匚佩"));
	LeGetway->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeGetway, 4, 6, 1, 2);

	QLabel* LRegion = new QLabel(QStringLiteral("仇囃辺鹿"));
	LRegion->setAlignment(Qt::AlignCenter);
	LRegion->setFont(fontBold);
	layout->addWidget(LRegion, 3, 8, 1, 2);

	LeRegion = new QLineEdit();
	LeRegion->setPlaceholderText(QStringLiteral("泌�宰長�，佛岻劑"));
	LeRegion->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeRegion, 4, 8, 1, 2);

	QLabel* LNotAwakened = new QLabel(QStringLiteral("隆状佰"));
	LNotAwakened->setAlignment(Qt::AlignCenter);
	LNotAwakened->setFont(fontBold);
	layout->addWidget(LNotAwakened, 4, 0, 1, 1);

	QLabel* LLv1 = new QLabel(QStringLiteral("1雫"));
	LLv1->setAlignment(Qt::AlignCenter);
	LLv1->setFont(fontBold);
	layout->addWidget(LLv1, 5, 0, 1, 1);

	QLabel* LAwakened = new QLabel(QStringLiteral("状佰"));
	LAwakened->setAlignment(Qt::AlignCenter);
	LAwakened->setFont(fontBold);
	layout->addWidget(LAwakened, 6, 0, 1, 1);

	QLabel* LLv40 = new QLabel(QStringLiteral("40雫"));
	LLv40->setAlignment(Qt::AlignCenter);
	LLv40->setFont(fontBold);
	layout->addWidget(LLv40, 7, 0, 1, 1);

	//答楚協吶��俶勣圓枠譜崔挫方怏寄弌
	N_A_Rank.resize(5);
	N_A_Value.resize(8);
	A_Rank.resize(5);
	A_Value.resize(8);
	for (int i = 0; i < 5; i++)
	{
		N_A_Rank[i] = new QComboBox();
		A_Rank[i] = new QComboBox();
		N_A_Value[i] = new QLineEdit();
		A_Value[i] = new QLineEdit();
		N_A_Rank[i]->addItems(RankList);
		layout->addWidget(N_A_Rank[i], 4, i + 1, 1, 1);
		A_Rank[i]->addItems(RankList);
		layout->addWidget(A_Rank[i], 6, i + 1, 1, 1);
		N_A_Value[i]->setAlignment(Qt::AlignCenter);
		layout->addWidget(N_A_Value[i], 5, i + 1, 1, 1);
		A_Value[i]->setAlignment(Qt::AlignCenter);
		layout->addWidget(A_Value[i], 7, i + 1, 1, 1);
	}
	connect(N_A_Rank[4], SIGNAL(currentIndexChanged(int)), this, SLOT(doSetNCrt(int)));
	connect(A_Rank[4], SIGNAL(currentIndexChanged(int)), this, SLOT(doSetCrt(int)));
	N_A_Rank[4]->setCurrentIndex(1);
	A_Rank[4]->setCurrentIndex(1);
	for (int i = 0; i < 4; i++)
	{
		N_A_Rank[i]->setCurrentIndex(1);
		A_Rank[i]->setCurrentIndex(1);
	}
	QLabel* LCdt = new QLabel(QStringLiteral("羽似彬墾"));
	LCdt->setAlignment(Qt::AlignCenter);
	LCdt->setFont(fontBold);
	layout->addWidget(LCdt, 8, 1, 1, 1);

	QLabel* LHr = new QLabel(QStringLiteral("丼惚凋嶄"));
	LHr->setAlignment(Qt::AlignCenter);
	LHr->setFont(fontBold);
	layout->addWidget(LHr, 8, 2, 1, 1);

	QLabel* LResist = new QLabel(QStringLiteral("丼惚丘森"));
	LResist->setAlignment(Qt::AlignCenter);
	LResist->setFont(fontBold);
	layout->addWidget(LResist, 8, 3, 1, 1);

	QLabel* LNA = new QLabel(QStringLiteral("隆状佰"));
	LNA->setAlignment(Qt::AlignCenter);
	LNA->setFont(fontBold);
	layout->addWidget(LNA, 9, 0, 1, 1);

	QLabel* LA = new QLabel(QStringLiteral("状佰"));
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
	N_A_Value[5]->setText("150%");
	A_Value[5]->setText("150%");
	N_A_Value[6]->setText("0%");
	A_Value[6]->setText("0%");
	N_A_Value[7]->setText("0%");
	A_Value[7]->setText("0%");


	QLabel* LAEffect = new QLabel(QStringLiteral("状佰丼惚"));
	LAEffect->setAlignment(Qt::AlignCenter);
	LAEffect->setFont(fontBold);
	layout->addWidget(LAEffect, 11, 0, 1, 1);

	LeAEffectKind = new QLineEdit();
	LeAEffectKind->setPlaceholderText(QStringLiteral("泌�彩躰喙篠�"));
	LeAEffectKind->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeAEffectKind, 11, 1, 1, 1);

	LeAEffect = new QLineEdit();
	LeAEffect->setPlaceholderText(QStringLiteral("泌�裟誡�"));
	LeAEffect->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeAEffect, 11, 2, 1, 4);

	QLabel* LAlias = new QLabel(QStringLiteral("艶各"));
	LAlias->setAlignment(Qt::AlignCenter);
	LAlias->setFont(fontBold);
	layout->addWidget(LAlias, 12, 0, 1, 1);

	LeAlias = new QLineEdit();
	LeAlias->setPlaceholderText(QStringLiteral("泌�咲掀咯�"));
	LeAlias->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeAlias, 12, 1, 1, 5);

	QLabel* LRevelant = new QLabel(QStringLiteral("�犢惱派�"));
	LRevelant->setAlignment(Qt::AlignCenter);
	LRevelant->setFont(fontBold);
	layout->addWidget(LRevelant, 13, 0, 1, 1);

	LeRelevant = new QLineEdit();
	LeRelevant->setPlaceholderText(QStringLiteral("泌�査愧�吶伉"));
	LeRelevant->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeRelevant, 13, 1, 1, 5);

	TeIntro = new QTextEdit();
	TeIntro->setPlaceholderText(QStringLiteral("塀舞酒初"));
	TeIntro->setAlignment(Qt::AlignCenter);
	layout->addWidget(TeIntro, 14, 0, 8, 6);

	twSkin = new QTabWidget();
	layout->addWidget(twSkin, 6, 6, 16, 4);

	pbAddSkin = new QPushButton(QStringLiteral("耶紗羨紙"));
	layout->addWidget(pbAddSkin, 5, 6, 1, 2);
	connect(pbAddSkin, SIGNAL(clicked()), this, SLOT(addSkin()));


	pbDelSkin = new QPushButton(QStringLiteral("評茅羨紙"));
	layout->addWidget(pbDelSkin, 5, 8, 1, 2);
	connect(pbDelSkin, SIGNAL(clicked()), this, SLOT(delSkin()));

	this->setLayout(layout);
}

BasicInfoForm::~BasicInfoForm()
{

}

void BasicInfoForm::doSetNCrt(int i)
{
	switch (i)
	{
	case 0: 
		N_A_Value[4]->setText("20%");
		break;
	case 1:
		N_A_Value[4]->setText("10%");
		break;
	case 2:
		N_A_Value[4]->setText("8%");
		break;
	case 3:
		N_A_Value[4]->setText("5%");
		break;
	case 4:
		N_A_Value[4]->setText("3%");
		break;
	case 5:
		N_A_Value[4]->setText("0%");
		break;
	default:
		break;
	}
}

void BasicInfoForm::doSetCrt(int i)
{
	switch (i)
	{
	case 0:
		A_Value[4]->setText("20%");
		break;
	case 1:
		A_Value[4]->setText("10%");
		break;
	case 2:
		A_Value[4]->setText("8%");
		break;
	case 3:
		A_Value[4]->setText("5%");
		break;
	case 4:
		A_Value[4]->setText("3%");
		break;
	case 5:
		A_Value[4]->setText("0%");
		break;
	default:
		break;
	}
}

void BasicInfoForm::addSkin()
{
	bool isOK;
	QString text = QInputDialog::getText(NULL, "",
		QStringLiteral("萩補秘討券議兆忖"),
		QLineEdit::Normal,
		QStringLiteral("潮範"),
		&isOK);
	if (!isOK)
		return;
	SkinForm* tmp = new SkinForm();
	tmp->findChild<QLineEdit*>("LeName")->setText(text);
	tmp->findChild<QLineEdit*>("LeSkin")->setText("[[File:"+LeName->text()+"_"+text+".png|400px]]");
	twSkin->addTab(tmp, text);
}

void BasicInfoForm::delSkin()
{
	if (twSkin->count()==0)
		return;
	else
	{
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
	this->N_A_Rank[0]->setCurrentText(data.NAAtkRank);//隆状佰議励略方峙
	this->N_A_Rank[1]->setCurrentText(data.NAHpRank);
	this->N_A_Rank[2]->setCurrentText(data.NADefRank);
	this->N_A_Rank[3]->setCurrentText(data.NASpdRank);
	this->N_A_Rank[4]->setCurrentText(data.NACrtRank);
	this->A_Rank[0]->setCurrentText(data.AAtkRank);//状佰議励略方峙
	this->A_Rank[1]->setCurrentText(data.AHpRank);
	this->A_Rank[2]->setCurrentText(data.ADefRank);
	this->A_Rank[3]->setCurrentText(data.ASpdRank);
	this->A_Rank[4]->setCurrentText(data.ACrtRank);

	this->N_A_Value[0]->setText(data.NAAtk);//1雫議方峙
	this->N_A_Value[1]->setText(data.NAHp);
	this->N_A_Value[2]->setText(data.NADef);
	this->N_A_Value[3]->setText(data.NASpd);
	this->N_A_Value[4]->setText(data.NACrt);
	this->N_A_Value[5]->setText(data.NACtd);
	this->N_A_Value[6]->setText(data.NAHr);
	this->N_A_Value[7]->setText(data.NAResist);

	this->A_Value[0]->setText(data.AAtk);//40雫議方峙
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
	result.Rarity = this->LeRarity->currentText();//宸頁倖combobox
	result.Getway = this->LeGetway->text();
	result.Region = this->LeRegion->text();
	result.NAAtkRank = this->N_A_Rank[0]->currentText();//隆状佰議励略方峙
	result.NAHpRank = this->N_A_Rank[1]->currentText();
	result.NADefRank = this->N_A_Rank[2]->currentText();
	result.NASpdRank = this->N_A_Rank[3]->currentText();
	result.NACrtRank = this->N_A_Rank[4]->currentText();
	result.AAtkRank = this->A_Rank[0]->currentText();//状佰議励略方峙
	result.AHpRank = this->A_Rank[1]->currentText();
	result.ADefRank = this->A_Rank[2]->currentText();
	result.ASpdRank = this->A_Rank[3]->currentText();
	result.ACrtRank = this->A_Rank[4]->currentText();

	result.NAAtk = this->N_A_Value[0]->text();//1雫議方峙
	result.NAHp = this->N_A_Value[1]->text();
	result.NADef = this->N_A_Value[2]->text();
	result.NASpd = this->N_A_Value[3]->text();
	result.NACrt = this->N_A_Value[4]->text();
	result.NACtd = this->N_A_Value[5]->text();
	result.NAHr = this->N_A_Value[6]->text();
	result.NAResist = this->N_A_Value[7]->text();

	result.AAtk = this->A_Value[0]->text();//40雫議方峙
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
	//喘噐陣崙庁翠議咨茄��俊辺LeRarity議峙葎k��輝k=1議扮昨燕幣塀舞蓮嗤業頁SP��匯乂�酊甚Φ頴涕�
	if (k == 1 || k==4)
	{
		for (int i = 0; i < 5; i++)
		{
			A_Rank[i]->setEnabled(false);
			A_Rank[i]->setCurrentText("");
		}
		for (int i = 5; i < 8; i++)
		{
			A_Value[i]->setEnabled(false);
			A_Value[i]->setText("");
		}
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
