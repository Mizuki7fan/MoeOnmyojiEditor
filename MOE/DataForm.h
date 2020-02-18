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

	//清除所有信息
	void Clear();
public:
	//式神的基本信息
	data_BasicInfo basic_info;
	data_SkillInfo skill_info;
	data_Voice voice_info;
	data_Story story_info;

};