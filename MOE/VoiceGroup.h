#pragma once
#include <QWidget>
#include <QtGui>
#include <QtWidgets>
#include <vector>
//���һ��������
class VoiceGroup :public QWidget
{
	Q_OBJECT
public:
	VoiceGroup(QWidget* _parent = 0);
	~VoiceGroup();

	int getCount();
	void setCount(int);

	//���ϡ�ж���SP��һЩ���ݽ�������
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

