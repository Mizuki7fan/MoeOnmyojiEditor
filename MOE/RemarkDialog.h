#pragma once
#include <QDialog>
#include <QtGui>
#include <QtWidgets>

class RemarkDialog :public QDialog
{
	Q_OBJECT

signals:
	void SendDataSignal( QString, QString);

public:
	RemarkDialog(QDialog* _parent = 0);
	~RemarkDialog();
	void setComm();

	void loadFixedItem();


private slots:
	void ChangeState(int i);
	void ChangeDesc(int i);
	void SendData();


private:
	QRadioButton* RbCom, * RbSpec;
	QButtonGroup* bg;
	QComboBox* CbCache;
	QLineEdit* LeName;
	QTextEdit* LeDesc;
	QTextEdit* TeComDesc;

	QPushButton* Ok, * Close;
	QStringList CommName;
	QStringList CommDesc;

	//返回的名字和描述
	bool isComm = true;

};

