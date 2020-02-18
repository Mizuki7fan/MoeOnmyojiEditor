#pragma once
#include<QString>
#include<vector>

struct data_SkillDesc
{
	int Level;
	QString Cd, Cost;
	int KindID;//0-passive,1-positive,2-onlydesc
	QString Desc;
};

struct data_SkillDerive
{
	QString Icon, Name;
	std::vector<data_SkillDesc> Content;
};

struct data_SingleSkillInfo
{
	//技能的图标、名字、台词
	QString Icon, Name, Dialogue;
	//这个技能不同等级的内容
	std::vector<data_SkillDesc> Content;
	//这个技能的所有衍生技能
	std::vector<data_SkillDerive> Derive;
	//这个技能的衍生词条
	std::vector<std::pair<QString, QString>> Remark;

};

struct data_SkillInfo
{
	std::vector<data_SingleSkillInfo> skill_group;
};