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
	LeIcon->setPlaceholderText(QStringLiteral("����ͼ�꣬�磺����"));
	LeIcon->setAlignment(Qt::AlignCenter);
	LeIcon->setObjectName(QStringLiteral("Icon"));
	layout->addWidget(LeIcon, 0, 0, 1, 2);

	LeName = new QLineEdit();
	LeName->setPlaceholderText(QStringLiteral("�������ƣ��磺����"));
	LeName->setAlignment(Qt::AlignCenter);
	LeName->setObjectName(QStringLiteral("Name"));
	layout->addWidget(LeName, 0, 2, 1, 6);

	LeDialogue = new QLineEdit();
	LeDialogue->setPlaceholderText(QStringLiteral("����̨�ʣ��磺Ҫ�ǵû���Ŷ"));
	LeDialogue->setAlignment(Qt::AlignCenter);
	LeDialogue->setObjectName(QStringLiteral("Dialogue"));
	layout->addWidget(LeDialogue, 1, 2, 1, 6);
	
	pbAddLevel = new QPushButton(QStringLiteral("��ӵȼ�"));
	pbDelLevel = new QPushButton(QStringLiteral("ɾ���ȼ�"));
	layout->addWidget(pbAddLevel, 2, 0, 1, 1);
	layout->addWidget(pbDelLevel, 2, 1, 1, 1);
	connect(pbAddLevel, SIGNAL(clicked()), SLOT(AddLevel()));
	connect(pbDelLevel, SIGNAL(clicked()), SLOT(DelLevel()));
	//���ܵȼ�������˵��
	twDesc = new QTabWidget();
	twDesc->setObjectName("twDesc");
	layout->addWidget(twDesc, 3, 0, 4,4);

	//�������ܿ��ܲ�ֹһ����Ҳ�����ж���ȼ�
	pbAddDerive = new QPushButton(QStringLiteral("�����������"));
	layout->addWidget(pbAddDerive, 2, 4, 1, 1);
	pbDelDerive = new QPushButton(QStringLiteral("ɾ����������"));
	layout->addWidget(pbDelDerive, 2, 5, 1, 1);
	twDerive = new QTabWidget();
	twDerive->setObjectName("twDerive");
	layout->addWidget(twDerive, 3, 4, 4, 4);
	connect(pbAddDerive, SIGNAL(clicked()), SLOT(AddDerive()));
	connect(pbDelDerive, SIGNAL(clicked()), SLOT(DelDerive()));

	pbAddRemark = new QPushButton(QStringLiteral("���˵������"));
	layout->addWidget(pbAddRemark, 7, 0, 1, 2);
	pbDelRemark = new QPushButton(QStringLiteral("ɾ��˵������"));
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
		//ɾ������tab
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
	//�½���������
	RemarkDialog* dlg= new RemarkDialog();
	//���ڴ��ڼ��ֹ��������
	QObject::connect(dlg, SIGNAL(SendDataSignal(QString, QString)), this, SLOT(getData(QString,QString)));
	dlg->setWindowTitle(QStringLiteral("��Ӵ���˵��"));
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

