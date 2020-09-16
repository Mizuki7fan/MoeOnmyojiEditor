#pragma once
#include <QWidget>
#include <QtGui>
#include <QtWidgets>
#include <vector>
//添加一个语音组
class VoiceGroup :public QWidget
{
	Q_OBJECT
public:
	VoiceGroup(QWidget* _parent = 0);
	~VoiceGroup();

	int getCount();
	void setCount(int);

	//如果稀有度是SP则将一些内容进行隐藏
public slots:
	void AddOne();
	void DelOne();


private:
	QScrollArea* saWnd;
	QWidget* wWnd;
	QPushButton* pbAdd, * pbDel;
	std::vector<QTextEdit*> Action;
	std::vector<QTextEdit*> ContentCN;
	std::vector<QTextEdit*> ContentJP;
	std::vector<QTextEdit*> PlayButton;

	int cnt = 0;
};

