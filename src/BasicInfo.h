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
	//δ���ѵ�5���ȼ�
	QString NAAtkRank, NAHpRank, NADefRank, NASpdRank, NACrtRank;
	//���ѵ�5���ȼ�
	QString AAtkRank, AHpRank, ADefRank, ASpdRank, ACrtRank;
	//Lv1��8����ֵ
	QString NAAtk, NAHp, NADef, NASpd, NACrt,NACtd, NAHr, NAResist;
	//Lv40��8����ֵ
	QString AAtk, AHp, ADef, ASpd, ACrt, ACtd,AHr, AResist;
	QString AEffect, AEffectKind;
	QString Alias, Relevant;
	QString Intro;
	std::vector<QString> SkinName;
	std::vector<QString> SkinPng;
};