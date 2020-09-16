#include "RemarkDialog.h"
#include <iostream>

RemarkDialog::RemarkDialog(QDialog* parent)
	: QDialog(parent)
{
	setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
	//setComm();
	loadFixedItem();
	QGridLayout *layout = new QGridLayout();
	layout->setColumnStretch(0, 1);
	layout->setColumnStretch(1, 1);
	RbCom = new QRadioButton();
	RbCom->setText(QStringLiteral("通用"));
	
	RbSpec = new QRadioButton();
	RbSpec->setText(QStringLiteral("特有"));
	bg=new QButtonGroup();
	bg->addButton(RbCom,0);
	bg->addButton(RbSpec,1);

	RbCom->setChecked(true);
	
	layout->addWidget(RbCom, 0, 0, 1, 1);
	layout->addWidget(RbSpec, 0, 1, 1, 1);

	CbCache = new QComboBox();
	CbCache->addItems(CommName);
	connect(CbCache, SIGNAL(currentIndexChanged(int)), this, SLOT(ChangeDesc(int)));

	layout->addWidget(CbCache, 1, 0, 1, 1);


	LeName = new QLineEdit();
	LeName->setAlignment(Qt::AlignCenter);
	layout->addWidget(LeName, 1, 1, 1, 1);

	TeComDesc = new QTextEdit();
	TeComDesc->setAlignment(Qt::AlignLeft);
	TeComDesc->setEnabled(false);
	layout->addWidget(TeComDesc, 2, 0, 4, 1);
	
	LeDesc = new QTextEdit();
	LeDesc->setAlignment(Qt::AlignLeft);
	layout->addWidget(LeDesc, 2, 1, 4, 1);


	Ok = new QPushButton(QStringLiteral("添加"));
	layout->addWidget(Ok, 6, 0, 1, 1);
	connect(Ok, SIGNAL(clicked()), SLOT(SendData()));

	Close = new QPushButton(QStringLiteral("取消"));
	layout->addWidget(Close,6, 1, 1, 1);

	this->setLayout(layout);
	connect(bg, SIGNAL(buttonClicked(int)),this, SLOT(ChangeState(int)));
	ChangeDesc(0);
	ChangeState(0);
}

RemarkDialog::~RemarkDialog()
{
}

void RemarkDialog::setComm()
{
	CommName << "1"
		<< "2"
		<< "3";
	CommDesc << "4"
		<< "5"
		<< "7";
}

void RemarkDialog::loadFixedItem()
{
	QFile file(":/txt/Information/FixedItem.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QTextStream in(&file);
	while (!file.atEnd())
	{
		QString str = QString::fromLocal8Bit(file.readLine());
		int nIndex = str.lastIndexOf('\n');
		str = str.left(nIndex);
		std::cout << str.toLocal8Bit().data() << std::endl;
		QStringList Q = str.split("=");
		CommName << Q.at(1);
		QString exp = QString::fromLocal8Bit(file.readLine());
		nIndex = exp.lastIndexOf('\n');
		exp = exp.left(nIndex);
		std::cout << exp.toLocal8Bit().data() << std::endl;
		QStringList Q2 = exp.split("=");
		CommDesc << Q2.at(1);
	}
}

void RemarkDialog::ChangeDesc(int i)
{
	this->TeComDesc->setText(CommDesc.at(i));
}

void RemarkDialog::SendData()
{

	QString Name, Desc,Color;

	if (isComm)
	{
		Name = CbCache->currentText();
		Desc = TeComDesc->toPlainText();
	}
	else
	{
		Name = LeName->text();
		Desc = LeDesc->toPlainText();
	}
	emit SendDataSignal(Name, Desc);
	this->close();
}

void RemarkDialog::ChangeState(int i)
{
	if (i == 0)//选择了通用的词条
	{
		isComm = true;
		CbCache->setEnabled(true);
		LeName->setEnabled(false);
		LeDesc->setEnabled(false);
	}
	else
	{
		isComm = false;
		CbCache->setEnabled(false);
		LeName->setEnabled(true);
		LeDesc->setEnabled(true);
	}
}