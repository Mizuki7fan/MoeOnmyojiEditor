#include "SkillForm.h"
#include "SingleSkillForm.h"
#include "SkillDesc.h"
#include "RemarkDialog.h"
#include "DerivedSkill.h"
#include <iostream>

SkillForm::SkillForm(QWidget* parent)
	: QWidget(parent)
{
	QGridLayout *layout = new QGridLayout();
	
	pbAdd = new QPushButton(QStringLiteral("添加技能"));
	layout->addWidget(pbAdd, 0, 0, 1, 1);
	connect(pbAdd, SIGNAL(clicked()), this, SLOT(addSkill()));

	pbDel = new QPushButton(QStringLiteral("删除技能"));
	layout->addWidget(pbDel, 0, 1, 1, 1);
	connect(pbDel, SIGNAL(clicked()), this, SLOT(delSkill()));

	twSkill = new QTabWidget();
	layout->addWidget(twSkill, 1, 0, 1, 2);

	this->setLayout(layout);
}


SkillForm::~SkillForm()
{

}

void SkillForm::fill(data_SkillInfo data)
{
	//填充读入的数据
	int s_count = data.skill_group.size();
	for (int u = 0; u < s_count;u++)
	{
		data_SingleSkillInfo SS_info = data.skill_group[u];
		SingleSkillForm* SS = new SingleSkillForm();
		//给控件注册名字
		SS->setObjectName("Skill" + QString::number(u));			
		SS->findChild<QLineEdit*>("Icon")->setText(SS_info.Icon);
		SS->findChild<QLineEdit*>("Name")->setText(SS_info.Name);
		SS->findChild<QLineEdit*>("Dialogue")->setText(SS_info.Dialogue);

		//填写词条本体的升级信息
		QTabWidget* twDesc = SS->findChild<QTabWidget*>("twDesc");
		int n_twDesc = SS_info.Content.size();
		for (int i = 0; i < n_twDesc; i++)
		{
			SkillDesc* skill_desc = new SkillDesc();
			skill_desc->setObjectName("Desc" + QString::number(i));
			skill_desc->findChild<QLineEdit*>("Cd")->setText(SS_info.Content[i].Cd);
			skill_desc->findChild<QLineEdit*>("Cost")->setText(SS_info.Content[i].Cost);
			skill_desc->findChild<QTextEdit*>("Desc")->setText(SS_info.Content[i].Desc);
			if (SS_info.Content[i].KindID == 0)
				skill_desc->findChild<QRadioButton*>("RbNotPassive")->setChecked(true);
			if (SS_info.Content[i].KindID == 1)
			{
				skill_desc->findChild<QRadioButton*>("RbIsPassive")->setChecked(true);
				skill_desc->ChangeState(1);
			}
			if (SS_info.Content[i].KindID == 2)
			{
				skill_desc->findChild<QRadioButton*>("RbOnlyDesc")->setChecked(true);
				skill_desc->ChangeState(2);
			}
			twDesc->addTab(skill_desc, "Lv." + QString::number(i));
		}
		QTabWidget* twDerive = SS->findChild<QTabWidget*>("twDerive");
		int n_twDerive = SS_info.Derive.size();
		for (int i = 0; i < n_twDerive; i++)
		{
			DerivedSkill* derived_skill = new DerivedSkill();
			derived_skill->setObjectName("Derive" + QString::number(i));
			derived_skill->findChild<QLineEdit*>("Icon")->setText(SS_info.Derive[i].Icon);
			derived_skill->findChild<QLineEdit*>("Name")->setText(SS_info.Derive[i].Name);
			QTabWidget* twLevel =derived_skill->findChild<QTabWidget*>("twLevel");	
			//twLevel->setObjectName("twLevel");
			int n_twDesc = SS_info.Derive[i].Content.size();
			for (int j = 0; j < n_twDesc; j++)
			{
				SkillDesc* skill_desc = new SkillDesc();
				skill_desc->setObjectName("Desc" + QString::number(j));
				skill_desc->findChild<QLineEdit*>("Cd")->setText(SS_info.Derive[i].Content[j].Cd);
				skill_desc->findChild<QLineEdit*>("Cost")->setText(SS_info.Derive[i].Content[j].Cost);
				skill_desc->findChild<QTextEdit*>("Desc")->setText(SS_info.Derive[i].Content[j].Desc);
				if (SS_info.Derive[i].Content[j].KindID == 0)
					skill_desc->findChild<QRadioButton*>("RbNotPassive")->setChecked(true);
				else if (SS_info.Derive[i].Content[j].KindID == 1)
				{
					skill_desc->findChild<QRadioButton*>("RbIsPassive")->setChecked(true);
					skill_desc->ChangeState(1);
				}
				else if (SS_info.Derive[i].Content[j].KindID == 2)
				{
					skill_desc->findChild<QRadioButton*>("RbOnlyDesc")->setChecked(true);
					skill_desc->ChangeState(2);
				}

				twLevel->addTab(skill_desc, "Lv." + QString::number(j));
			}
			twDerive->addTab(derived_skill, SS_info.Derive[i].Name);
		}

		QTabWidget* twRemark = SS->findChild<QTabWidget*>("twRemark");
		int n_twRemark = SS_info.Remark.size();
		for (int i = 0; i < n_twRemark; i++)
		{
			QTextEdit* te = new QTextEdit();
			te->setText(SS_info.Remark[i].second);
			te->setObjectName("Remark" + QString::number(i));
			twRemark->addTab(te, SS_info.Remark[i].first);
		}
		twSkill->addTab(SS, SS_info.Name);
	}
}

data_SkillInfo SkillForm::getData()
{
	data_SkillInfo result;
	int s_count = twSkill->count();
	for (int u = 0; u < s_count; u++)
	{//对twSkill中的每个tab进行遍历
		data_SingleSkillInfo SS_info;
		SingleSkillForm* SS;
		//获取单个技能的控件
		SS = twSkill->findChild<SingleSkillForm*>("Skill" + QString::number(u));
		//获取该tab中名为Icon的控件的值
		SS_info.Icon = SS->findChild<QLineEdit*>("Icon")->text();
		SS_info.Name = SS->findChild<QLineEdit*>("Name")->text();
		SS_info.Dialogue = SS->findChild<QLineEdit*>("Dialogue")->text();

		//获取词条本体的升级信息
		QTabWidget* twDesc = SS->findChild<QTabWidget*>("twDesc");
		int n_twDesc = twDesc->count();
		SS_info.Content.resize(n_twDesc);
		for (int i = 0; i < n_twDesc; i++)
		{
			SkillDesc* skill_desc = SS->findChild<SkillDesc*>("Desc" + QString::number(i));
			SS_info.Content[i].Level = i;
			SS_info.Content[i].Cd = skill_desc->findChild<QLineEdit*>("Cd")->text();
			SS_info.Content[i].Cost = skill_desc->findChild<QLineEdit*>("Cost")->text();
			SS_info.Content[i].Desc = skill_desc->findChild<QTextEdit*>("Desc")->toPlainText().trimmed();
			QRadioButton* NotPassive = skill_desc->findChild<QRadioButton*>("RbNotPassive");
			QRadioButton* IsPassive = skill_desc->findChild<QRadioButton*>("RbIsPassive");
			QRadioButton* OnlyDesc = skill_desc->findChild<QRadioButton*>("RbOnlyDesc");
			if (NotPassive->isChecked())//主动技能
				SS_info.Content[i].KindID = 0;
			else if (IsPassive->isChecked())
				SS_info.Content[i].KindID = 1;
			else if (OnlyDesc->isChecked())
				SS_info.Content[i].KindID = 2;
		}

		//处理衍生词条
		QTabWidget* twDerive = SS->findChild<QTabWidget*>("twDerive");
		int n_twDerive = twDerive->count();
		SS_info.Derive.resize(n_twDerive);
		for (int i = 0; i < n_twDerive; i++)
		{
			DerivedSkill* derived_skill = SS->findChild<DerivedSkill*>("Derive" + QString::number(i));
			SS_info.Derive[i].Icon = derived_skill->findChild<QLineEdit*>("Icon")->text();
			SS_info.Derive[i].Name = derived_skill->findChild<QLineEdit*>("Name")->text();
			QTabWidget* twLevel = derived_skill->findChild<QTabWidget*>("twLevel");
			int n_twLevel = twLevel->count();
			SS_info.Derive[i].Content.resize(n_twLevel);
			for (int j = 0; j < n_twLevel; j++)
			{
				SkillDesc* skill_desc = derived_skill->findChild<SkillDesc*>("Desc" + QString::number(j));
				SS_info.Derive[i].Content[j].Level = j;
				SS_info.Derive[i].Content[j].Cd = skill_desc->findChild<QLineEdit*>("Cd")->text();
				SS_info.Derive[i].Content[j].Cost = skill_desc->findChild<QLineEdit*>("Cost")->text();
				SS_info.Derive[i].Content[j].Desc = skill_desc->findChild<QTextEdit*>("Desc")->toPlainText().trimmed();
				QRadioButton* NotPassive = skill_desc->findChild<QRadioButton*>("RbNotPassive");
				QRadioButton* IsPassive = skill_desc->findChild<QRadioButton*>("RbIsPassive");
				QRadioButton* OnlyDesc = skill_desc->findChild<QRadioButton*>("RbOnlyDesc");
				if (NotPassive->isChecked())//主动技能
					SS_info.Derive[i].Content[j].KindID = 0;
				else if (IsPassive->isChecked())
					SS_info.Derive[i].Content[j].KindID = 1;
				else if (OnlyDesc->isChecked())
					SS_info.Derive[i].Content[j].KindID = 2;
			}
		}

		//处理说明词条
		QTabWidget* twRemark = SS->findChild<QTabWidget*>("twRemark");
		int n_twRemark = twRemark->count();
		SS_info.Remark.resize(n_twRemark);
		for (int i = 0; i < n_twRemark; i++)
		{
			SS_info.Remark[i].first = twRemark->tabText(i);
			QTextEdit* te = twRemark->findChild<QTextEdit*>("Remark" + QString::number(i));
			SS_info.Remark[i].second = te->toPlainText().trimmed();
		}
		result.skill_group.push_back(SS_info);
	}
	return result;
}

void SkillForm::delSkill()
{
	if (sfSkillForm.size() == 0)
		return;
	else
	{
		sfSkillForm.pop_back();
		int c = twSkill->count();
		QWidget* p = twSkill->widget(c - 1);
		if (0 != p)
		{
			delete p;
			p = NULL;
		}
	}
}

void SkillForm::addSkill()
{
	bool isOK;
	QString text = QInputDialog::getText(NULL, "",
		QStringLiteral("请输入技能的名字"),
		QLineEdit::Normal,
		QStringLiteral("技能1"),
		&isOK);
	if (!isOK)
		return;
	SingleSkillForm* tmp = new SingleSkillForm();
	QWidget* q = this->parentWidget()->findChild<QWidget*>("BasicInfoForm");
	QString Name = q->findChild<QLineEdit*>("LeName")->text();

	tmp->findChild<QLineEdit*>("Icon")->setText("[[File:"+Name+"_"+text+".png|60px]]");
	tmp->findChild<QLineEdit*>("Name")->setText(text);
	//设置控件的名字以备查找
	QString name = "Skill" + QString::number(twSkill->count());
	tmp->setObjectName(name);
	sfSkillForm.push_back(tmp);
	twSkill->addTab(tmp, text);
}
