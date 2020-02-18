#pragma once 
#include <QString>
#include "BasicInfo.h"
#include "SkillInfo.h"
#include "VoiceInfo.h"
#include "StoryInfo.h"


class DataForm
{
public:
	DataForm();
	~DataForm();

	//���������Ϣ
	void Clear();
public:
	//ʽ��Ļ�����Ϣ
	data_BasicInfo basic_info;
	data_SkillInfo skill_info;
	data_Voice voice_info;
	data_Story story_info;

};