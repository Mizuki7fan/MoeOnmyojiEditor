#include "StoryForm.h"

StoryForm::StoryForm(QWidget* parent)
	:QWidget(parent)
{
	QGridLayout* layout = new QGridLayout();
	pbAdd = new QPushButton(QStringLiteral("添加"));
	pbDel = new QPushButton(QStringLiteral("删除"));
	layout->addWidget(pbAdd, 0, 0, 1, 1);
	layout->addWidget(pbDel, 0, 1, 1, 1);

	twTab = new QTabWidget();
	layout->addWidget(twTab,1,0,1,2);

	connect(pbAdd, SIGNAL(clicked()), SLOT(AddOne()));
	connect(pbDel, SIGNAL(clicked()), SLOT(DelOne()));
	
	this->setLayout(layout);
}

StoryForm::~StoryForm()
{

}

void StoryForm::fill(data_Story data)
{
	for (int u = 0; u < data.Group.size(); u++)
	{
		QGridLayout* tableRow1Layout = new QGridLayout();
		QLabel* LName = new QLabel();
		LName->setText(data.Group[u].Name);
		LName->setObjectName("LName" + QString::number(twTab->count()));
		tableRow1Layout->addWidget(LName, 0, 0, 2, 1);

		QLineEdit* LeCondition = new QLineEdit();
		LeCondition->setPlaceholderText(QStringLiteral("解锁传记的条件"));
		LeCondition->setAlignment(Qt::AlignCenter);
		LeCondition->setObjectName("LeCondition" + QString::number(twTab->count()));
		LeCondition->setText(data.Group[u].Condition);
		tableRow1Layout->addWidget(LeCondition, 0, 1, 1, 1);

		QLineEdit* LeAward = new QLineEdit();
		LeAward->setPlaceholderText(QStringLiteral("解锁传记的奖励"));
		LeAward->setAlignment(Qt::AlignCenter);
		LeAward->setObjectName("LeAward" + QString::number(twTab->count()));
		LeAward->setText(data.Group[u].Award);
		tableRow1Layout->addWidget(LeAward, 1, 1, 1, 1);

		QLineEdit* LePlay = new QLineEdit();
		LePlay->setPlaceholderText(QStringLiteral("播放按钮"));
		LePlay->setAlignment(Qt::AlignCenter);
		LePlay->setObjectName("LePlay" + QString::number(twTab->count()));
		LePlay->setText(data.Group[u].PlayButton);
		tableRow1Layout->addWidget(LePlay, 0, 2, 2, 1);

		tableRow1Layout->setColumnStretch(0, 1);
		tableRow1Layout->setColumnStretch(1, 6);
		tableRow1Layout->setColumnStretch(2, 1);

		QWidget* tableRow1 = new QWidget();
		tableRow1->setLayout(tableRow1Layout);

		QTextEdit* TeContent = new QTextEdit();
		TeContent->setObjectName("TeContent" + QString::number(twTab->count()));
		TeContent->setText(data.Group[u].Content);
		QVBoxLayout* tableLayout = new QVBoxLayout();
		tableLayout->addWidget(tableRow1);
		tableLayout->addWidget(TeContent);
		tableLayout->addStretch();

		QWidget* table = new QWidget();
		table->setLayout(tableLayout);
		table->setObjectName("table" + QString::number(twTab->count()));

		twTab->addTab(table, data.Group[u].Name);
	}
}

data_Story StoryForm::getData()
{
	data_Story result;
	int cnt = twTab->count();
	result.Group.resize(cnt);
	for (int i = 0; i < cnt; i++)
	{
		QWidget* table = twTab->widget(i);
		result.Group[i].Name = table->findChild<QLabel*>("LName" + QString::number(i))->text();
		result.Group[i].Condition= table->findChild<QLineEdit*>("LeCondition" + QString::number(i))->text();
		result.Group[i].Award= table->findChild<QLineEdit*>("LeAward" + QString::number(i))->text();
		result.Group[i].PlayButton= table->findChild<QLineEdit*>("LePlay" + QString::number(i))->text();
		result.Group[i].Content= table->findChild<QTextEdit*>("TeContent" + QString::number(i))->toPlainText();
	}
	return result;
}

void StoryForm::AddOne()
{
	//添加一个
	bool isOK;
	QString text = QInputDialog::getText(NULL, "",
		QStringLiteral("请输入这篇传记的名字"),
		QLineEdit::Normal,
		QStringLiteral("传记1"),
		&isOK);
	if (!isOK)
		return;
	QGridLayout* tableRow1Layout = new QGridLayout();
	QLabel* LName = new QLabel();
	LName->setText(text);
	LName->setObjectName("LName"+QString::number(twTab->count()));
	tableRow1Layout->addWidget(LName, 0, 0, 2, 1);

	QLineEdit* LeCondition = new QLineEdit();
	LeCondition->setPlaceholderText(QStringLiteral("解锁传记的条件"));
	LeCondition->setAlignment(Qt::AlignCenter);
	LeCondition->setObjectName("LeCondition" + QString::number(twTab->count()));
	tableRow1Layout->addWidget(LeCondition,0,1, 1, 1);

	QLineEdit* LeAward = new QLineEdit();
	LeAward->setPlaceholderText(QStringLiteral("解锁传记的奖励"));
	LeAward->setAlignment(Qt::AlignCenter);
	LeAward->setObjectName("LeAward" + QString::number(twTab->count()));
	tableRow1Layout->addWidget(LeAward, 1, 1, 1, 1);

	QLineEdit* LePlay = new QLineEdit();
	LePlay->setPlaceholderText(QStringLiteral("播放按钮"));
	LePlay->setAlignment(Qt::AlignCenter);
	LePlay->setObjectName("LePlay" + QString::number(twTab->count()));
	tableRow1Layout->addWidget(LePlay, 0, 2, 2, 1);

	tableRow1Layout->setColumnStretch(0, 1);
	tableRow1Layout->setColumnStretch(1, 6);
	tableRow1Layout->setColumnStretch(2,1);

	QWidget* tableRow1 = new QWidget();
	tableRow1->setLayout(tableRow1Layout);

	QTextEdit* TeContent = new QTextEdit();
	TeContent->setObjectName("TeContent" + QString::number(twTab->count()));
	
	QVBoxLayout* tableLayout = new QVBoxLayout();
	tableLayout->addWidget(tableRow1);
	tableLayout->addWidget(TeContent);
	tableLayout->addStretch();

	QWidget* table = new QWidget();
	table->setLayout(tableLayout);
	table->setObjectName("table"+QString::number(twTab->count()));

	twTab->addTab(table, text);
}
void StoryForm::DelOne()
{
	if (twTab->count() == 0)
		return;
	else
	{
		QMessageBox msgBox;
		msgBox.setText(QStringLiteral("提示"));
		msgBox.setInformativeText(QStringLiteral("确实要删除最新的传记吗?"));
		msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
		msgBox.setDefaultButton(QMessageBox::Ok);
		int ret = msgBox.exec();
		if (ret == QMessageBox::Ok) {
			QWidget* p = twTab->widget(twTab->count() - 1);
			if (0 != p)
			{
				delete p;
				p = NULL;
			}
		}
	}

}