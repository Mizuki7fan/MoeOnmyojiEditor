#pragma once
#include "DataForm.h"
#include <QFile>
#include <iostream>
#include <QtCore>
#include <stack>

//用于进行输入和输出的转化
class Parser
{
public:
	Parser(DataForm* data);
	Parser(QString txt_path);
	~Parser();

	void LoadFixItem();
	void output(QString of);
	DataForm* input();

	void matchBasicInfo(QString);
	void matchSkill(QString);
	void matchVoice(QString);
	void matchStory(QString);

private:
	//Form2Txt
	void Form2Txt_BasicInfo();
	void Form2Txt_Skill();
	void Form2Txt_Voice();
	void Form2Txt_Story();

	//Txt2Form
	void Txt2Form_BasicInfo();
	void Txt2Form_Skill();
	void Txt2Form_Voice();
	void Txt2Form_Story();

private:
	//txt文件
	QString txt_path;
	QString BasicInfo_txt;
	QString Skill_txt;
	QString Voice_txt;
	QString Story_txt;
	//表单数据
	DataForm* Data;
	//状态机用于解析文本
	std::stack<int> state;
	//int state = 0;
	int skill_no = -1;//表示当前添加的技能的数量
	int skill_lv_no = -1;
	int skill_derive_no = -1;
	int skill_remark_no = -1;

	int voice_no = -1;
	int voicegroup_no = -1;

	int story_no = -1;

	//表示各个模块第一行的行号
	int line_number[4] = { 0,0,0,0 };
	int line_id = 0;

	std::vector<QString> FixItem;

};