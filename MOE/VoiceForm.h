#pragma once
#include <QWidget>
#include <QtGui>
#include <QtWidgets>
#include <vector>
#include "VoiceInfo.h"
//添加一个语音组
class VoiceGroup;
class VoiceForm :public QWidget
{
	Q_OBJECT
public:
	VoiceForm(QWidget* _parent = 0);
	~VoiceForm();
	//填充数据
	void fill(data_Voice);
	//读取数据
	data_Voice getData();

	//如果稀有度是SP则将一些内容进行隐藏
public slots:
	void AddOne();
	void DelOne();

private:
	QPushButton* pbAdd, * pbDel;
	QTabWidget* tbVoice;

};

