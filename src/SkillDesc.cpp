#include "SkillDesc.h"

SkillDesc::SkillDesc(QWidget* parent)
	: QWidget(parent)
{
	QGridLayout *layout = new QGridLayout();
	layout->setColumnStretch(0, 1);
	layout->setColumnStretch(1, 1);
	layout->setColumnStretch(2, 1);
	layout->setColumnStretch(3, 1);
	RbNotPassive = new QRadioButton();
	RbNotPassive->setText(QStringLiteral("主动技能"));
	RbNotPassive->setObjectName(QStringLiteral("RbNotPassive"));
	RbIsPassive = new QRadioButton();
	RbIsPassive->setText(QStringLiteral("被动技能"));
	RbIsPassive->setObjectName(QStringLiteral("RbIsPassive"));
	RbOnlyDesc = new QRadioButton();
	RbOnlyDesc->setText(QStringLiteral("仅有描述"));
	RbOnlyDesc->setObjectName(QStringLiteral("RbOnlyDesc"));

	BgPassive = new QButtonGroup();
	BgPassive->addButton(RbNotPassive, 0);
	BgPassive->addButton(RbIsPassive, 1);
	BgPassive->addButton(RbOnlyDesc, 2);
	RbNotPassive->setChecked(true);
	layout->addWidget(RbNotPassive, 0, 0, 1, 1);
	layout->addWidget(RbIsPassive, 0, 1, 1, 1);
	layout->addWidget(RbOnlyDesc, 0, 2, 1, 1);

	LCd = new QLabel(QStringLiteral("冷却："));
	LCd->setAlignment(Qt::AlignCenter);
	layout->addWidget(LCd, 1, 0, 1, 1);

	LeCd = new QLineEdit();
	LeCd->setAlignment(Qt::AlignCenter);
	LeCd->setObjectName("Cd");
	layout->addWidget(LeCd, 1, 1, 1, 1);
	
	LCost = new QLabel(QStringLiteral("鬼火："));
	LCost->setAlignment(Qt::AlignCenter);
	layout->addWidget(LCost, 1, 2, 1, 1);

	LeCost = new QLineEdit();
	LeCost->setAlignment(Qt::AlignCenter);
	LeCost->setObjectName("Cost");
	layout->addWidget(LeCost, 1, 3, 1, 1);

	LPassive = new QLabel(QStringLiteral("被动技能"));
	LPassive->setAlignment(Qt::AlignCenter);
	LPassive->setVisible(false);
	layout->addWidget(LPassive, 1, 0, 1, 4);

	this->setLayout(layout);

	connect(BgPassive, SIGNAL(buttonClicked(int)), this, SLOT(ChangeState(int)));

	TeDesc = new QTextEdit();
	TeDesc->setPlaceholderText(QStringLiteral("技能描述，加粗、分段和颜色需要手动指定"));
	TeDesc->setAlignment(Qt::AlignLeft);
	TeDesc->setObjectName("Desc");
	layout->addWidget(TeDesc, 2, 0,1,4);
	ChangeState(0);
}

SkillDesc::~SkillDesc()
{

}

void SkillDesc::ChangeState(int i)
{
	if (i == 0)
	{//主动技能
	//	RbIsPassive->setChecked(false);
		LPassive->setVisible(false);
		LCd->setVisible(true);
		LeCd->setVisible(true);
		LCost->setVisible(true);
		LeCost->setVisible(true);
	}
	else if (i == 1)
	{
		LPassive->setText(QStringLiteral("被动技能"));
		LPassive->setVisible(true);
		LCd->setVisible(false);
		LeCd->setVisible(false);
		LCost->setVisible(false);
		LeCost->setVisible(false);
	}
	else if (i==2)
	{
		LPassive->setText(QStringLiteral(""));
		LPassive->setVisible(true);
		LCd->setVisible(false);
		LeCd->setVisible(false);
		LCost->setVisible(false);
		LeCost->setVisible(false);

	}

}
