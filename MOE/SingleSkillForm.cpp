#include "SingleSkillForm.h"
#include "SkillDesc.h"
#include "RemarkDialog.h"
#include "DerivedSkill.h"
#include <iostream>

SingleSkillForm::SingleSkillForm(QWidget* parent)
	: QWidget(parent)
{
	QGridLayout *layout = new QGridLayout();
	LeIcon = new QLineEdit();
	LeIcon->setPlaceholderText(QStringLiteral("技能图标，如：归鸟"));
	LeIcon->setAlignment(Qt::AlignCenter);
	LeIcon->setObjectName(QStringLiteral("Icon"));
	layout->addWidget(LeIcon, 0, 0, 1, 2);

	LeName = new QLineEdit();
	LeName->setPlaceholderText(QStringLiteral("技能名称，如：归鸟"));
	LeName->setAlignment(Qt::AlignCenter);
	LeName->setObjectName(QStringLiteral("Name"));
	layout->addWidget(LeName, 0, 2, 1, 6);

	LeDialogue = new QLineEdit();
	LeDialogue->setPlaceholderText(QStringLiteral("技能台词，如：要记得回来哦"));
	LeDialogue->setAlignment(Qt::AlignCenter);
	LeDialogue->setObjectName(QStringLiteral("Dialogue"));
	layout->addWidget(LeDialogue, 1, 2, 1, 6);
	
	pbAddLevel = new QPushButton(QStringLiteral("添加等级"));
	pbDelLevel = new QPushButton(QStringLiteral("删除等级"));
	layout->addWidget(pbAddLevel, 2, 0, 1, 1);
	layout->addWidget(pbDelLevel, 2, 1, 1, 1);
	connect(pbAddLevel, SIGNAL(clicked()), SLOT(AddLevel()));
	connect(pbDelLevel, SIGNAL(clicked()), SLOT(DelLevel()));
	//技能等级的提升说明
	twDesc = new QTabWidget();
	twDesc->setObjectName("twDesc");
	layout->addWidget(twDesc, 3, 0, 4,4);

	//衍生技能可能不止一个，也可能有多个等级
	pbAddDerive = new QPushButton(QStringLiteral("添加衍生技能"));
	layout->addWidget(pbAddDerive, 2, 4, 1, 1);
	pbDelDerive = new QPushButton(QStringLiteral("删除衍生技能"));
	layout->addWidget(pbDelDerive, 2, 5, 1, 1);
	twDerive = new QTabWidget();
	twDerive->setObjectName("twDerive");
	layout->addWidget(twDerive, 3, 4, 4, 4);
	connect(pbAddDerive, SIGNAL(clicked()), SLOT(AddDerive()));
	connect(pbDelDerive, SIGNAL(clicked()), SLOT(DelDerive()));

	pbAddRemark = new QPushButton(QStringLiteral("添加说明词条"));
	layout->addWidget(pbAddRemark, 7, 0, 1, 2);
	pbDelRemark = new QPushButton(QStringLiteral("删除说明词条"));
	layout->addWidget(pbDelRemark, 7, 2, 1, 2);
	twRemark = new QTabWidget();
	twRemark->setObjectName("twRemark");
	layout->addWidget(twRemark, 8, 0, 3, 8);

	connect(pbAddRemark, SIGNAL(clicked()), SLOT(AddRemark()));
	connect(pbDelRemark, SIGNAL(clicked()), SLOT(DelRemark()));
	layout->rowStretch(1);
	this->setLayout(layout);
}
SingleSkillForm::~SingleSkillForm()
{

}

void SingleSkillForm::AddLevel()
{
	SkillDesc* tmp = new SkillDesc();
	sdDesc.push_back(tmp);
	tmp->setObjectName("Desc" + QString::number(twDesc->count()));
	twDesc->addTab(tmp, QStringLiteral("Lv.") + QString::number(sdDesc.size()));
}

void SingleSkillForm::DelLevel()
{
	if (sdDesc.size() <=1)
		return;
	else
	{
		sdDesc.pop_back();
		//删除立绘tab
		int c = twDesc->count();
		QWidget* p = twDesc->widget(c - 1);
		if (0 != p)
		{
			delete p;
			p = NULL;
		}
	}
}

void SingleSkillForm::AddRemark()
{
	//新建弹窗窗口
	RemarkDialog* dlg= new RemarkDialog();
	//窗口打开期间禁止其他交互
	QObject::connect(dlg, SIGNAL(SendDataSignal(QString, QString)), this, SLOT(getData(QString,QString)));
	dlg->setWindowTitle(QStringLiteral("添加词条说明"));
	dlg->setModal(true);
	dlg->show();
}

void SingleSkillForm::DelRemark()
{
	if (twRemark->count()==0)
		return;
	else
	{
		int c = twRemark->count();
		QWidget* p = twRemark->widget(c - 1);
		if (0 != p)
		{
			delete p;
			p = NULL;
		}
	}
}

void SingleSkillForm::AddDerive()
{
	DerivedSkill* tmp = new DerivedSkill();
//	tmp->setObjectName("Desc" + QString::number(twDesc->count()));
	tmp->setObjectName("Derive" + QString::number(twDerive->count()));
	int c = twDerive->count();
	twDerive->addTab(tmp,QString::number(c));

}

void SingleSkillForm::DelDerive()
{
	if (twDerive->count()==0)
		return;
	else
	{
		int c = twDerive->count();
		QWidget* p = twDerive->widget(c - 1);
		if (0 != p)
		{
			delete p;
			p = NULL;
		}
	}
}

void SingleSkillForm::getData(QString Name, QString Desc)
{
	QTextEdit* te = new QTextEdit();
	te->setText(Desc);
	te->setObjectName("Remark" + QString::number(twRemark->count()));
	twRemark->addTab(te, Name);
}

