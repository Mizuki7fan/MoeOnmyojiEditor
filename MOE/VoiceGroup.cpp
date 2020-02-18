#include "VoiceGroup.h"

VoiceGroup::VoiceGroup(QWidget* parent)
	:QWidget(parent)
{
	QHBoxLayout* row1layout = new QHBoxLayout();
	pbAdd = new QPushButton(QStringLiteral("添加"));
	pbDel = new QPushButton(QStringLiteral("删除"));
	row1layout->addWidget(pbAdd);
	row1layout->addWidget(pbDel);
	QWidget* row1 = new QWidget();
//row1->setFixedHeight(this->height() / 8);
	row1->setLayout(row1layout);

	std::vector<QWidget*> row2;
	row2.resize(30);
	//预设大小
	Action.resize(30);
	ContentCN.resize(30);
	ContentJP.resize(30);
	PlayButton.resize(30);
	for (int i = 0; i < 30; i++)
	{
	QGridLayout* row2l = new QGridLayout();
	row2l->setColumnStretch(0, 1);
	row2l->setColumnStretch(1, 6);
	row2l->setColumnStretch(2, 1);
	Action[i] = new QTextEdit();
	Action[i]->setAlignment(Qt::AlignCenter);
	Action[i]->setVisible(false);
	Action[i]->setPlaceholderText(QStringLiteral("动作名称"));
	Action[i]->setObjectName("Action" + QString::number(i));
	ContentCN[i] = new QTextEdit();
	ContentCN[i]->setVisible(false);
	ContentCN[i]->setPlaceholderText(QStringLiteral("中文翻译"));
	ContentCN[i]->setObjectName("ContentCN" + QString::number(i));
	ContentJP[i] = new QTextEdit();
	ContentJP[i]->setVisible(false);
	ContentJP[i]->setPlaceholderText(QStringLiteral("日语原话"));
	ContentJP[i]->setObjectName("ContentJP" + QString::number(i));
	PlayButton[i] = new QTextEdit();
	PlayButton[i]->setVisible(false);
	PlayButton[i]->setAlignment(Qt::AlignCenter);
	PlayButton[i]->setPlaceholderText(QStringLiteral("播放文件"));
	PlayButton[i]->setObjectName("PlayButton" + QString::number(i));
	row2l->addWidget(Action[i], 0, 0, 2, 1);
	row2l->addWidget(ContentJP[i],0,1,1,1);
	row2l->addWidget(ContentCN[i],1,1, 1, 1);
	row2l->addWidget(PlayButton[i],0,2, 2, 1);
	row2[i] = new QWidget();
	row2[i]->setFixedHeight(this->height() / 5);
	row2[i]->setLayout(row2l);
	}
	QVBoxLayout *vlayout = new QVBoxLayout();
	vlayout->setAlignment(Qt::AlignTop);
	vlayout->addWidget(row1);
	for (int i = 0; i < 30; i++)
	{
		vlayout->addWidget(row2[i]);
	}
	vlayout->addStretch();

	wWnd = new QWidget();
	wWnd->setLayout(vlayout);
	wWnd->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	saWnd = new QScrollArea();
	saWnd->setFocusPolicy(Qt::NoFocus);
	saWnd->setFrameStyle(QFrame::NoFrame);
	saWnd->setWidgetResizable(true);
	saWnd->setWidget(wWnd);
	QGridLayout* layout = new QGridLayout();
	layout->addWidget(saWnd, 0, 0);
	this->setLayout(layout);

	connect(pbAdd, SIGNAL(clicked()), SLOT(AddOne()));
	connect(pbDel, SIGNAL(clicked()), SLOT(DelOne()));

}

VoiceGroup::~VoiceGroup()
{
}

int VoiceGroup::getCount()
{
	return cnt;
}

void VoiceGroup::setCount(int n)
{
	cnt = n;
}

void VoiceGroup::AddOne()
{
	if (cnt == 30)
		return;
	Action[cnt]->setVisible(true);
	ContentCN[cnt]->setVisible(true);
	ContentJP[cnt]->setVisible(true);
	PlayButton[cnt]->setVisible(true);
	cnt++;
}

void VoiceGroup::DelOne()
{
	if (cnt == 0)
		return;
	cnt--;
	Action[cnt]->setVisible(false);
	ContentCN[cnt]->setVisible(false);
	ContentJP[cnt]->setVisible(false);
	PlayButton[cnt]->setVisible(false);
}
