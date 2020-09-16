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
	//���ܵ�ͼ�ꡢ���֡�̨��
	QString Icon, Name, Dialogue;
	//������ܲ�ͬ�ȼ�������
	std::vector<data_SkillDesc> Content;
	//������ܵ�������������
	std::vector<data_SkillDerive> Derive;
	//������ܵ���������
	std::vector<std::pair<QString, QString>> Remark;

};

struct data_SkillInfo
{
	std::vector<data_SingleSkillInfo> skill_group;
};