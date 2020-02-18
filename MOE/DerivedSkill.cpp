#include "DerivedSkill.h"
#include "SkillDesc.h"


DerivedSkill::DerivedSkill(QWidget* parent)
	:QWidget(parent)
{
	QGridLayout* layout = new QGridLayout();
	SkillIcon = new QLineEdit();
	SkillIcon->setPlaceholderText(QStringLiteral("技能图标"));
	SkillIcon->setAlignment(Qt::AlignCenter);
	SkillIcon->setObjectName(QStringLiteral("Icon"));
	layout->addWidget(SkillIcon, 0, 0, 1, 1);

	SkillName = new QLineEdit();
	SkillName->setPlaceholderText(QStringLiteral("技能名称"));
	SkillName->setAlignment(Qt::AlignCenter);
	SkillName->setObjectName(QStringLiteral("Name"));
	layout->addWidget(SkillName, 0, 1, 1, 1);

	pbAddLevel = new QPushButton(QStringLiteral("添加等级"));
	layout->addWidget(pbAddLevel, 1, 0, 1, 1);
	pbDelLevel = new QPushButton(QStringLiteral("删除等级"));
	layout->addWidget(pbDelLevel, 1, 1, 1, 1);
	connect(pbAddLevel, SIGNAL(clicked()), SLOT(AddLevel()));
	connect(pbDelLevel, SIGNAL(clicked()), SLOT(DelLevel()));

	twLevel = new QTabWidget();
	twLevel->setObjectName("twLevel");
	layout->addWidget(twLevel, 2, 0, 1, 2);
	this->setLayout(layout);
}

void DerivedSkill::AddLevel()
{
	SkillDesc* tmp = new SkillDesc();
	//QString s = "Desc" + QString::number(twLevel->count());
	tmp->setObjectName("Desc"+QString::number(twLevel->count()));
	int c = twLevel->count();
	twLevel->addTab(tmp,QString::number(c));
}

void DerivedSkill::DelLevel()
{
	if (twLevel->count() == 0)
		return;
	else
	{
		QWidget* p = twLevel->widget(twLevel->count() - 1);
		if (0 != p)
		{
			delete p;
			p = NULL;
		}
	}

}

DerivedSkill::~DerivedSkill()
{
}