#include "VoiceForm.h"
#include "VoiceGroup.h"

VoiceForm::VoiceForm(QWidget* parent)
	:QWidget(parent)
{
	QGridLayout* layout = new QGridLayout();
	pbAdd = new QPushButton(QStringLiteral("添加一组"));
	layout->addWidget(pbAdd, 0, 0, 1, 1);
	pbDel = new QPushButton(QStringLiteral("删除一组"));
	layout->addWidget(pbDel, 0, 1, 1, 1);
	tbVoice=new QTabWidget();
	tbVoice->setObjectName("tbVoice");
	layout->addWidget(tbVoice, 1, 0, 1, 2);

	connect(pbAdd, SIGNAL(clicked()), SLOT(AddOne()));
	connect(pbDel, SIGNAL(clicked()), SLOT(DelOne()));

	this->setLayout(layout);
}

VoiceForm::~VoiceForm()
{
	
}

void VoiceForm::fill(data_Voice data)
{
	for (int u = 0; u < data.Group.size(); u++)
	{
		//VoiceGroup* vg = tbVoice->findChild<VoiceGroup*>("VG" + QString::number(u));
		VoiceGroup* vg = new VoiceGroup();
		vg->setObjectName("VG" + QString::number(u));
		vg->setCount(data.Group[u].Text.size());
		for (int i = 0; i < data.Group[u].Text.size();i++)
		{
			QTextEdit* Action = vg->findChild<QTextEdit*>("Action" + QString::number(i));
			Action->setText(data.Group[u].Text[i].Action);
			Action->setVisible(true);
			
			QTextEdit* ContentCN = vg->findChild<QTextEdit*>("ContentCN" + QString::number(i));
			ContentCN->setText(data.Group[u].Text[i].TextCN);
			ContentCN->setVisible(true);
			
			QTextEdit* ContentJP = vg->findChild<QTextEdit*>("ContentJP" + QString::number(i));
			ContentJP->setText(data.Group[u].Text[i].TextJP);
			ContentJP->setVisible(true);

			QTextEdit* PlayButton = vg->findChild<QTextEdit*>("PlayButton" + QString::number(i));
			PlayButton->setText(data.Group[u].Text[i].PlayButton);
			PlayButton->setVisible(true);
		}
		tbVoice->addTab(vg, data.Group[u].GroupName);
	}
}

data_Voice VoiceForm::getData()
{
	data_Voice result;
	int k = tbVoice->count();
	result.Group.resize(k);
	for (int i = 0; i < k; i++)
	{
		//获取当前的voicegroup
		VoiceGroup* vg = tbVoice->findChild<VoiceGroup*>("VG" + QString::number(i));
		result.Group[i].GroupName = tbVoice->tabText(i);
		int cnt = vg->getCount();
		result.Group[i].Text.resize(cnt);
		for (int j = 0; j < cnt; j++)
		{
			result.Group[i].Text[j].Action = vg->findChild<QTextEdit*>("Action" + QString::number(j))->toPlainText();
			result.Group[i].Text[j].TextCN= vg->findChild<QTextEdit*>("ContentCN" + QString::number(j))->toPlainText();
			result.Group[i].Text[j].TextJP= vg->findChild<QTextEdit*>("ContentJP" + QString::number(j))->toPlainText();
			result.Group[i].Text[j].PlayButton= vg->findChild<QTextEdit*>("PlayButton" + QString::number(j))->toPlainText();
		}
	}
	return result;
}

void VoiceForm::AddOne()
{
	bool isOK;
	QString text = QInputDialog::getText(NULL,"",
		QStringLiteral("请输入语音分组的名字"),
		QLineEdit::Normal,
		"",
		&isOK);
	if (isOK) {
		VoiceGroup* vg = new VoiceGroup();
		vg->setObjectName("VG" + QString::number(tbVoice->count()));
		tbVoice->addTab(vg, text);
	}
}

void VoiceForm::DelOne()
{
	if (tbVoice->count() == 0)
		return;
	else
	{
		QMessageBox msgBox;
		msgBox.setText(QStringLiteral("提示"));
		msgBox.setInformativeText(QStringLiteral("确实要删除最新的分组吗?"));
		msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
		msgBox.setDefaultButton(QMessageBox::Ok);
		int ret = msgBox.exec();
		if (ret == QMessageBox::Ok) {
			QWidget* p = tbVoice->widget(tbVoice->count() - 1);
			if (0 != p)
			{
				delete p;
				p = NULL;
			}
		}
	}
	}