#pragma once
#include <QString>
#include <vector>

struct data_BasicInfo
{
	QString NameCN, NameJP, NameHiragara;
	QString CV;
	QString Rarity;
	QString Getway;
	QString Region;
	//未觉醒的5个等级
	QString NAAtkRank, NAHpRank, NADefRank, NASpdRank, NACrtRank;
	//觉醒的5个等级
	QString AAtkRank, AHpRank, ADefRank, ASpdRank, ACrtRank;
	//Lv1的8个数值
	QString NAAtk, NAHp, NADef, NASpd, NACrt,NACtd, NAHr, NAResist;
	//Lv40的8个数值
	QString AAtk, AHp, ADef, ASpd, ACrt, ACtd,AHr, AResist;
	QString AEffect, AEffectKind;
	QString Alias, Relevant;
	QString Intro;
	std::vector<QString> SkinName;
	std::vector<QString> SkinPng;
};