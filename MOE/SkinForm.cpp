#include "SkinForm.h"

SkinForm::SkinForm(QWidget* parent)
	: QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout();
	QLabel *LName = new QLabel(QStringLiteral("Ƥ������"));
	LName->setAlignment(Qt::AlignCenter);
	layout->addWidget(LName);

	LeName = new QLineEdit();
	LeName->setPlaceholderText(QStringLiteral("�磺�гغ���"));
	LeName->setAlignment(Qt::AlignCenter);
	LeName->setObjectName("LeName");//���ø������objectName������findchild�Ĳ����Ի�ȡ��ֵ
	layout->addWidget(LeName);

	QLabel* LSkin = new QLabel(QStringLiteral("Ƥ����Դ����"));
	LSkin->setAlignment(Qt::AlignCenter);
	layout->addWidget(LSkin);

	LeSkin = new QLineEdit();
	LeSkin->setPlaceholderText(QStringLiteral("�磺[[File:�����_�гغ���.png|400px]]"));
	LeSkin->setAlignment(Qt::AlignCenter);
	LeSkin->setObjectName("LeSkin");//���ø������objectName������findchild�Ĳ����Ի�ȡ��ֵ
	layout->addWidget(LeSkin);

	layout->addStretch();
	this->setLayout(layout);
}


SkinForm::~SkinForm()
{

}

QString SkinForm::getLeName()
{
	return LeName->text();
}

QString SkinForm::getSkin()
{
	return LeSkin->text();
}
