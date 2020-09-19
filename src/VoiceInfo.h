#pragma once
#include<QString>
#include<vector>

struct data_SingleVoice
{
	bool IsIncluded;
	QString Action;
	QString TextJP, TextCN;
	QString PlayButton;
};

struct data_VoiceGroup
{
	QString GroupName;
	std::vector<data_SingleVoice> Text;
};

struct data_Voice
{
	std::vector<data_VoiceGroup> Group;
};