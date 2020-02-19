#include "SkinForm.h"

SkinForm::SkinForm(QWidget* parent)
	: QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout();
	QLabel *LName = new QLabel(QStringLiteral("皮肤名称"));
	LName->setAlignment(Qt::AlignCenter);
	layout->addWidget(LName);

	LeName = new QLineEdit();
	LeName->setPlaceholderText(QStringLiteral("如：闲池荷香"));
	LeName->setAlignment(Qt::AlignCenter);
	LeName->setObjectName("LeName");//设置该物件的objectName，用于findchild的查找以获取其值
	layout->addWidget(LeName);

	QLabel* LSkin = new QLabel(QStringLiteral("皮肤资源名称"));
	LSkin->setAlignment(Qt::AlignCenter);
	layout->addWidget(LSkin);

	LeSkin = new QLineEdit();
	LeSkin->setPlaceholderText(QStringLiteral("如：[[File:花鸟卷_闲池荷香.png|400px]]"));
	LeSkin->setAlignment(Qt::AlignCenter);
	LeSkin->setObjectName("LeSkin");//设置该物件的objectName，用于findchild的查找以获取其值
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
