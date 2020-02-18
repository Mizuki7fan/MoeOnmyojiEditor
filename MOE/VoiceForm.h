#pragma once
#include <QWidget>
#include <QtGui>
#include <QtWidgets>
#include <vector>
#include "VoiceInfo.h"
//���һ��������
class VoiceGroup;
class VoiceForm :public QWidget
{
	Q_OBJECT
public:
	VoiceForm(QWidget* _parent = 0);
	~VoiceForm();
	//�������
	void fill(data_Voice);
	//��ȡ����
	data_Voice getData();

	//���ϡ�ж���SP��һЩ���ݽ�������
public slots:
	void AddOne();
	void DelOne();

private:
	QPushButton* pbAdd, * pbDel;
	QTabWidget* tbVoice;

};

