#include "Parser.h"

Parser::Parser(DataForm* data) :Data(data)
{	
	LoadFixItem();
	Form2Txt_BasicInfo();
	Form2Txt_Skill();
	Form2Txt_Voice();
	Form2Txt_Story();
}

Parser::Parser(QString txt_path) :txt_path(txt_path)
{
	Data = new DataForm();

	Txt2Form_BasicInfo();
	Txt2Form_Skill();
	Txt2Form_Voice();
	Txt2Form_Story();
}


Parser::~Parser()
{
}

void Parser::LoadFixItem()
{
	QFile file("FixedItem.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QTextStream in(&file);
	while (!file.atEnd())
	{
		QString str = QString::fromLocal8Bit(file.readLine());
		int nIndex = str.lastIndexOf('\n');
		str = str.left(nIndex);
		QStringList Q = str.split("=");
		FixItem.push_back(Q.at(1));
		QString exp = QString::fromLocal8Bit(file.readLine());
	}
}

void Parser::output(QString of)
{
	QFile f(of);
	if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		std::cout << "OpenFailed" << std::endl;
	}
	QTextStream out(&f);

	out << BasicInfo_txt;
	out << Skill_txt;
	out << Voice_txt;
	out << Story_txt;
	f.close();
	return;
}

DataForm* Parser::input()
{
	return Data;
}

void Parser::matchBasicInfo(QString str)
{
start:

	std::cout << str.toLocal8Bit().data() << std::endl;
	int k = str.indexOf("=");
	QString value = str.mid(k + 1, str.length() - k);//取等号右侧的值
	if (state.top() == 0)
	{//在0状态下，发现==基本资料==的字样，则设置state为1
		if (str.indexOf(QStringLiteral("== 基本资料 ==")) != -1)
		{
			state.push(1);
			return;
		}
		else if (str.indexOf(QStringLiteral("== 技能 ==")) != -1)
		{
			state.push(-1);//终止
			return;
		}
	}
	else if (state.top() == 1)
	{
		if (str.indexOf(QStringLiteral("{{阴阳师手游:基本信息改")) != -1)
		{
			state.push(2);
			return;
		}

	}
	else if (state.top() == 2)
	{
		if (str.indexOf(QStringLiteral("|式神名称")) != -1)
			Data->basic_info.NameCN = value;
		else if (str.indexOf(QStringLiteral("|式神日语名称")) != -1)
		{
			QStringList Q = str.split("|");//按照|分割字符串
			Data->basic_info.NameJP = Q.at(2);
			Data->basic_info.NameHiragara = Q.at(3);
		}
		else if (str.indexOf(QStringLiteral("|声优")) != -1)
			Data->basic_info.CV = value;
		else if (str.indexOf(QStringLiteral("|稀有度")) != -1)
			Data->basic_info.Rarity = value;
		else if (str.indexOf(QStringLiteral("|获得方式")) != -1)
			Data->basic_info.Getway = value;
		else if (str.indexOf(QStringLiteral("|地域收集")) != -1)
			Data->basic_info.Region = value;
		else if (str.indexOf(QStringLiteral("|未觉醒攻击等级")) != -1)
			Data->basic_info.NAAtkRank = value;
		else if (str.indexOf(QStringLiteral("|未觉醒生命等级")) != -1)
			Data->basic_info.NAHpRank = value;
		else if (str.indexOf(QStringLiteral("|未觉醒防御等级")) != -1)
			Data->basic_info.NADefRank = value;
		else if (str.indexOf(QStringLiteral("|未觉醒速度等级")) != -1)
			Data->basic_info.NASpdRank = value;
		else if (str.indexOf(QStringLiteral("|未觉醒暴击等级")) != -1)
			Data->basic_info.NACrtRank = value;
		else if (str.indexOf(QStringLiteral("|觉醒攻击等级")) != -1)
			Data->basic_info.AAtkRank = value;
		else if (str.indexOf(QStringLiteral("|觉醒生命等级")) != -1)
			Data->basic_info.AHpRank = value;
		else if (str.indexOf(QStringLiteral("|觉醒防御等级")) != -1)
			Data->basic_info.ADefRank = value;
		else if (str.indexOf(QStringLiteral("|觉醒速度等级")) != -1)
			Data->basic_info.ASpdRank = value;
		else if (str.indexOf(QStringLiteral("|觉醒暴击等级")) != -1)
			Data->basic_info.ACrtRank = value;
		else if (str.indexOf(QStringLiteral("|1级攻击")) != -1)
			Data->basic_info.NAAtk = value;
		else if (str.indexOf(QStringLiteral("|1级生命")) != -1)
			Data->basic_info.NAHp = value;
		else if (str.indexOf(QStringLiteral("|1级防御")) != -1)
			Data->basic_info.NADef = value;
		else if (str.indexOf(QStringLiteral("|1级速度")) != -1)
			Data->basic_info.NASpd = value;
		else if (str.indexOf(QStringLiteral("|1级暴击")) != -1)
			Data->basic_info.NACrt = value;
		else if (str.indexOf(QStringLiteral("|40级攻击")) != -1)
			Data->basic_info.AAtk = value;
		else if (str.indexOf(QStringLiteral("|40级生命")) != -1)
			Data->basic_info.AHp = value;
		else if (str.indexOf(QStringLiteral("|40级防御")) != -1)
			Data->basic_info.ADef = value;
		else if (str.indexOf(QStringLiteral("|40级速度")) != -1)
			Data->basic_info.ASpd = value;
		else if (str.indexOf(QStringLiteral("|40级暴击")) != -1)
			Data->basic_info.ACrt = value;
		else if (str.indexOf(QStringLiteral("|未觉醒暴伤")) != -1)
			Data->basic_info.NACtd = value;
		else if (str.indexOf(QStringLiteral("|未觉醒命中")) != -1)
			Data->basic_info.NAHr = value;
		else if (str.indexOf(QStringLiteral("|未觉醒抵抗")) != -1)
			Data->basic_info.NAResist = value;
		else if (str.indexOf(QStringLiteral("|觉醒暴伤")) != -1)
			Data->basic_info.ACtd = value;
		else if (str.indexOf(QStringLiteral("|觉醒命中")) != -1)
			Data->basic_info.AHr = value;
		else if (str.indexOf(QStringLiteral("|觉醒抵抗")) != -1)
			Data->basic_info.AResist = value;
		else if (str.indexOf(QStringLiteral("|觉醒效果类型")) != -1)
			Data->basic_info.AEffectKind = value;
		else if (str.indexOf(QStringLiteral("|觉醒效果")) != -1)
			Data->basic_info.AEffect = value;
		else if (str.indexOf(QStringLiteral("|别称")) != -1)
			Data->basic_info.Alias = value;
		else if (str.indexOf(QStringLiteral("|相关角色")) != -1)
			Data->basic_info.Relevant = value;
		else if (str.indexOf(QStringLiteral("|式神简介")) != -1)
		{//进入读式神简介的状态
			state.push(3);
		}
		else if (str.indexOf(QStringLiteral("|式神立绘")) != -1)
		{
			state.push(4);
		}
		else if (str.indexOf("}}") == 0)//在2状态碰见}}
		{
			state.pop();
			state.pop();
		}
	}
	else if (state.top() == 3)
	{//读入式神简介
		if (str.indexOf("|") == 0)
		{
			state.pop();
			goto start;
		}
		else
			Data->basic_info.Intro.append(value);
	}
	else if (state.top() == 4)
	{//进入读立绘的状态
		if (str.indexOf("|bt") != -1)
			Data->basic_info.SkinName.push_back(value);
		else if (str.indexOf("|tab") != -1)
			Data->basic_info.SkinPng.push_back(value);
		else if (str.indexOf("}}") == 0)
			state.pop();
	}
}

void Parser::matchSkill(QString str)
{
start:
	int k = str.indexOf("=");
	QString value = str.mid(k + 1, str.length() - k);//取等号右侧的值
	if (state.top() == 0)
	{//在0状态下，发现==基本资料==的字样，则设置state为1
		if (str.indexOf(QStringLiteral("== 技能 ==")) != -1)
			state.push(1);
		return;
	}
	else if (state.top() == 1)
	{
		if (str.indexOf(QStringLiteral("{{阴阳师手游:通用技能")) != -1)
		{
			state.push(2);
			data_SingleSkillInfo tmp;
			Data->skill_info.skill_group.push_back(tmp);
			skill_no++;
			return;
		}
		else if (str.indexOf(QStringLiteral("== 语音 ==")) != -1)
		{
			state.push(-1);
			return;
		}
	}
	else if (state.top() == 2)
	{
		if (str.indexOf(QStringLiteral("|技能图标")) != -1)
			Data->skill_info.skill_group[skill_no].Icon = value;
		else if (str.indexOf(QStringLiteral("|技能名称")) != -1)
			Data->skill_info.skill_group[skill_no].Name = value;
		else if (str.indexOf(QStringLiteral("|技能台词")) != -1)
			Data->skill_info.skill_group[skill_no].Dialogue = value;
		else if (str.indexOf(QStringLiteral("|技能描述")) != -1)
		{
			state.push(3);
		}
		else if (str.indexOf(QStringLiteral("|衍生技能")) != -1)
		{
			state.push(5);
		}
		else if (str.indexOf(QStringLiteral("|技能词条")) != -1)
		{
			skill_remark_no = -1;
			state.push(8);
		}
		else if (str.indexOf("}}"))
		{//这里为止应该是单条技能说明完毕
			state.pop();
		}
	}
	else if (state.top() == 3)
	{//
		if (str.indexOf(QStringLiteral("|lv")) != -1)
		{
			if (str.indexOf(QStringLiteral("冷却")) != -1)
			{
				Data->skill_info.skill_group[skill_no].Content[skill_lv_no].Cd = value;
			}
			else if (str.indexOf(QStringLiteral("鬼火")) != -1)
			{
				Data->skill_info.skill_group[skill_no].Content[skill_lv_no].Cost = value;
			}
			else if (str.indexOf(QStringLiteral("描述")) != -1)
			{
				state.push(4);
			}
			else
			{
				data_SkillDesc tmp;
				Data->skill_info.skill_group[skill_no].Content.push_back(tmp);
				skill_lv_no++;
			}
		}
		else if (str.indexOf("}}") == 0)
		{
			skill_lv_no = -1;
			state.pop();
			return;
		}

	}
	else if (state.top() == 4)
	{//处理是技能描述的情形
		if (str.indexOf("|") == 0)
		{
			state.pop();
			goto start;
		}
		else if (str.indexOf("}}") == 0)
		{
			state.pop();
			goto start;
		}
		else
		{
			Data->skill_info.skill_group[skill_no].Content[skill_lv_no].Desc.append(value + "\n");
		}
	}
	else if (state.top() == 5)
	{//开始衍生技能的读取
		if (str.indexOf(QStringLiteral("|衍")) != -1)
		{
			if (str.indexOf(QStringLiteral("图标")) != -1)
			{
				data_SkillDerive tmp;
				skill_derive_no++;
				Data->skill_info.skill_group[skill_no].Derive.push_back(tmp);
				Data->skill_info.skill_group[skill_no].Derive[skill_derive_no].Icon = value;
			}
			else if (str.indexOf(QStringLiteral("名")) != -1)
				Data->skill_info.skill_group[skill_no].Derive[skill_derive_no].Name = value;
			else if (str.indexOf(QStringLiteral("说明")) != -1)
			{//进行衍生技能的说明
				state.push(6);
			}
		}
		else if (str.indexOf("}}") == 0)
		{
			state.pop();
			return;
		}
	}
	else if (state.top() == 6)
	{
		if (str.indexOf("|lv") != -1)
		{
			if (str.indexOf(QStringLiteral("冷却")) != -1)
			{
				Data->skill_info.skill_group[skill_no].Derive[skill_derive_no].Content[skill_lv_no].Cd = value;
			}
			else if (str.indexOf(QStringLiteral("鬼火")) != -1)
			{
				Data->skill_info.skill_group[skill_no].Derive[skill_derive_no].Content[skill_lv_no].Cost = value;
			}
			else if (str.indexOf(QStringLiteral("描述")) != -1)
			{
				state.push(7);
			}
			else
			{
				data_SkillDesc tmp;
				Data->skill_info.skill_group[skill_no].Derive[skill_derive_no].Content.push_back(tmp);
				skill_lv_no++;
			}

		}
		else if (str.indexOf("}}") == 0)
		{//表示衍生技能说明结束

			skill_lv_no = -1;
			state.pop();
			return;
		}
	}
	else if (state.top() == 7)
	{//衍生技能的描述
		if (str.indexOf("|") == 0)
		{
			state.pop();
			goto start;
		}
		else if (str.indexOf("}}") == 0)
		{
			skill_derive_no = -1;
			state.pop();
			goto start;
		}
		else
		{
			Data->skill_info.skill_group[skill_no].Derive[skill_derive_no].Content[skill_lv_no].Desc.append(value + "\n");
		}
	}
	else if (state.top() == 8)
	{
		if (str.indexOf("Color") != -1)
		{
			std::pair<QString, QString> tmp;
			skill_remark_no++;
			Data->skill_info.skill_group[skill_no].Remark.push_back(tmp);
		}
		else if (str.indexOf("Name") != -1)
		{
			QStringList Q = value.split("'''");
			Data->skill_info.skill_group[skill_no].Remark[skill_remark_no].first = Q.at(1);

		}
		else if (str.indexOf("Content") != -1)
		{
			state.push(9);
		}
		else if (str.indexOf("}}") != -1)
		{
			state.pop();
		}
	}
	else if (state.top() == 9)
	{//处理是技能描述的情形
		if (str.indexOf("|") == 0)
		{
			state.pop();
			goto start;
		}
		else if (str.indexOf("}}") == 0)
		{
			state.pop();
			goto start;
		}
		else
		{
			Data->skill_info.skill_group[skill_no].Remark[skill_remark_no].second.append(value + "\n");
		}
	}

}
void Parser::matchVoice(QString str)
{
	int k = str.indexOf("=");
	QString value = str.mid(k + 1, str.length() - k);//取等号右侧的值
	if (state.top() == 0)
	{//在0状态下，发现==基本资料==的字样，则设置state为1
		if (str.indexOf(QStringLiteral("== 语音 ==")) != -1)
			state.push(1);
		return;
	}
	else if (state.top() == 1)
	{//读取该组语音的名字
		if (str.indexOf(QStringLiteral("=== ")) != -1)
		{
			QStringList Q = str.split("===");
			//获取该分组的名字
			QString q = Q.at(1).trimmed();
			data_VoiceGroup tmp;
			Data->voice_info.Group.push_back(tmp);
			voice_no++;
			//该分组的名字
			Data->voice_info.Group[voice_no].GroupName = q;
			state.push(2);
		}
		else if (str.indexOf(QStringLiteral("== 传记 ==")))
		{
			state.push(-1);
			return;
		}
	}
	else if (state.top() == 2)
	{
		if (str.indexOf(QStringLiteral("|动作名")) != -1)
		{
			data_SingleVoice tmp;
			tmp.Action = value;
			Data->voice_info.Group[voice_no].Text.push_back(tmp);
			voicegroup_no++;
		}
		else if (str.indexOf(QStringLiteral("|日")) != -1)
		{
			Data->voice_info.Group[voice_no].Text[voicegroup_no].TextJP = value;
		}
		else if (str.indexOf(QStringLiteral("|中")) != -1)
		{
			Data->voice_info.Group[voice_no].Text[voicegroup_no].TextCN = value;
		}
		else if (str.indexOf(QStringLiteral("|播")) != -1)
		{
			Data->voice_info.Group[voice_no].Text[voicegroup_no].PlayButton = value;
		}
		else if (str.indexOf("}}") == 0)
		{
			voicegroup_no = -1;
			state.pop();
		}
	}
}

void Parser::matchStory(QString str)
{
	start:
	int k = str.indexOf("=");
	QString value = str.mid(k + 1, str.length() - k);//取等号右侧的值
	if (state.top() == 0)
	{//在0状态下，发现==基本资料==的字样，则设置state为1
		if (str.indexOf(QStringLiteral("== 传记 ==")) != -1)
			state.push(1);
		return;
	}
	else if (state.top() == 1)
	{
		if (str.indexOf(QStringLiteral("|标")) != -1)
		{
			data_SingleStory tmp;
			tmp.Name = value;
			Data->story_info.Group.push_back(tmp);
			story_no++;
		}
		else if (str.indexOf(QStringLiteral("|条件")) != -1)
		{
			Data->story_info.Group[story_no].Condition = value;
		}
		else if (str.indexOf(QStringLiteral("|奖励")) != -1)
		{
			Data->story_info.Group[story_no].Award= value;
		}
		else if (str.indexOf(QStringLiteral("|播")) != -1)
		{
			Data->story_info.Group[story_no].PlayButton = value;
		}
		else if (str.indexOf(QStringLiteral("|值")) != -1)
		{
			state.push(2);
		}
		else if (str.indexOf("}}") == 0)
		{
			state.push(-1);
			return;
		}
	}
	else if (state.top() == 2)
	{
		if (str.indexOf("|") == 0)
		{
			state.pop();
			goto start;
		}
		else if (str.indexOf("}}") == 0)
		{
			state.pop();
			goto start;
		}
		else
		{
			Data->story_info.Group[story_no].Content.append(value+"\n");
		}
	}
}
void Parser::Form2Txt_BasicInfo()
{
	data_BasicInfo data = Data->basic_info;
	BasicInfo_txt.append(QStringLiteral("__NOTOC__\n\n"));
	BasicInfo_txt.append(QStringLiteral("== 基本资料 ==\n"));
	BasicInfo_txt.append(QStringLiteral("{{阴阳师手游:基本信息改\n"));
	BasicInfo_txt.append(QStringLiteral("|式神名称=") + data.NameCN + "\n");
	BasicInfo_txt.append(QStringLiteral("|式神日语名称={{ruby|") + data.NameJP + "|" + data.NameHiragara + "|ja}}\n");
	BasicInfo_txt.append(QStringLiteral("|声优=") + data.CV + "\n");
	BasicInfo_txt.append(QStringLiteral("|稀有度=") + data.Rarity + "\n");
	BasicInfo_txt.append(QStringLiteral("|获得方式=") + data.Getway + "\n");
	BasicInfo_txt.append(QStringLiteral("|地域收集=") + data.Region + "\n");
	BasicInfo_txt.append(QStringLiteral("|未觉醒攻击等级=") + data.NAAtkRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|未觉醒生命等级=") + data.NAHpRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|未觉醒防御等级=") + data.NADefRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|未觉醒速度等级=") + data.NASpdRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|未觉醒暴击等级=") + data.NACrtRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|1级攻击=") + data.NAAtk + "\n");
	BasicInfo_txt.append(QStringLiteral("|1级生命=") + data.NAHp + "\n");
	BasicInfo_txt.append(QStringLiteral("|1级防御=") + data.NADef + "\n");
	BasicInfo_txt.append(QStringLiteral("|1级速度=") + data.NASpd + "\n");
	BasicInfo_txt.append(QStringLiteral("|1级暴击=") + data.NACrt + "\n");
	BasicInfo_txt.append(QStringLiteral("|觉醒攻击等级=") + data.AAtkRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|觉醒生命等级=") + data.AHpRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|觉醒防御等级=") + data.ADefRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|觉醒速度等级=") + data.ASpdRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|觉醒暴击等级=") + data.ACrtRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|40级攻击=") + data.AAtk + "\n");
	BasicInfo_txt.append(QStringLiteral("|40级生命=") + data.AHp + "\n");
	BasicInfo_txt.append(QStringLiteral("|40级防御=") + data.ADef + "\n");
	BasicInfo_txt.append(QStringLiteral("|40级速度=") + data.ASpd + "\n");
	BasicInfo_txt.append(QStringLiteral("|40级暴击=") + data.ACrt + "\n");
	BasicInfo_txt.append(QStringLiteral("|未觉醒暴伤=") + data.ACtd + "\n");
	BasicInfo_txt.append(QStringLiteral("|未觉醒命中=") + data.AHr + "\n");
	BasicInfo_txt.append(QStringLiteral("|未觉醒抵抗=") + data.AResist + "\n");
	BasicInfo_txt.append(QStringLiteral("|觉醒暴伤=") + data.ACtd + "\n");
	BasicInfo_txt.append(QStringLiteral("|觉醒命中=") + data.AHr + "\n");
	BasicInfo_txt.append(QStringLiteral("|觉醒抵抗=") + data.AResist + "\n");
	BasicInfo_txt.append(QStringLiteral("|觉醒效果类型=") + data.AEffectKind + "\n");
	BasicInfo_txt.append(QStringLiteral("|觉醒效果=") + data.AEffect + "\n");
	BasicInfo_txt.append(QStringLiteral("|别称=") + data.Alias + "\n");
	BasicInfo_txt.append(QStringLiteral("|相关角色=") + data.Relevant + "\n");
	BasicInfo_txt.append(QStringLiteral("|式神简介=\n"));
	QStringList Q = data.Intro.split("\n");
	for (int i = 0; i < Q.size() - 1; i++)
	{
		BasicInfo_txt.append(Q.at(i) + "<br>\n");
	}
	BasicInfo_txt.append(QStringLiteral("|式神立绘={{tabs\n"));
	for (int i = 0; i < data.SkinName.size(); i++)
	{
		BasicInfo_txt.append("|bt" + QString::number(i + 1) + "=" + data.SkinName[i] + "\n");
		BasicInfo_txt.append("|tab" + QString::number(i + 1) + "=" + data.SkinPng[i] + "\n");
	}
	BasicInfo_txt.append("|DefaultTab=1\n|AutoWidth=yes\n}}\n}}\n\n");
}

void Parser::Form2Txt_Skill()
{
	std::vector<QString> trans = { QStringLiteral("技能一"),QStringLiteral("技能二"),QStringLiteral("技能三"), QStringLiteral("技能四"), QStringLiteral("技能五"), QStringLiteral("技能六"), QStringLiteral("技能七"), QStringLiteral("技能八") };
	data_SkillInfo data = Data->skill_info;
	Skill_txt.append(QStringLiteral("== 技能 ==\n"));
	int n_skill = data.skill_group.size();
	for (int u = 0; u < n_skill; u++)
	{
		Skill_txt.append("=== " + trans[u] + " ===\n");
		Skill_txt.append(QStringLiteral("{{阴阳师手游:通用技能\n"));
		Skill_txt.append(QStringLiteral("|技能图标=") + data.skill_group[u].Icon + "\n");
		Skill_txt.append(QStringLiteral("|技能名称=") + data.skill_group[u].Name + "\n");
		Skill_txt.append(QStringLiteral("|技能台词=") + data.skill_group[u].Dialogue + "\n");
		Skill_txt.append(QStringLiteral("|技能描述={{阴阳师手游:普通技能") + "\n");
		for (int i = 0; i < data.skill_group[u].Content.size(); i++)
		{
			Skill_txt.append("|lv" + QString::number(i + 1) + "=Lv." + QString::number(i + 1) + "\n");
			Skill_txt.append("|lv" + QString::number(i + 1) + QStringLiteral("冷却=") + data.skill_group[u].Content[i].Cd + "\n");
			Skill_txt.append("|lv" + QString::number(i + 1) + QStringLiteral("鬼火=") + data.skill_group[u].Content[i].Cost + "\n");
			Skill_txt.append("|lv" + QString::number(i + 1) + QStringLiteral("描述=") + "\n");
			QStringList Q = data.skill_group[u].Content[i].Desc.split("\n");//按照|分割字符串
			for (int m = 0; m < Q.size() - 1; m++)
			{
				Skill_txt.append("<p>" + Q.at(m) + "</p>\n");
			}
			//去掉行末的空格
			Skill_txt.append("<p>" + Q.at(Q.size() - 1).left(Q.at(Q.size() - 1).length() - 1) + "</p>\n");
		}
		Skill_txt.append("}}\n");
		if (data.skill_group[u].Derive.size() != 0)
		{
			Skill_txt.append(QStringLiteral("|衍生技能={{阴阳师手游:衍生技能") + "\n");
			for (int i = 0; i < data.skill_group[u].Derive.size(); i++)
			{
				Skill_txt.append(QStringLiteral("|衍") + QString::number(i + 1) + QStringLiteral("图标=") + data.skill_group[u].Derive[i].Icon + "\n");
				Skill_txt.append(QStringLiteral("|衍") + QString::number(i + 1) + QStringLiteral("名=") + data.skill_group[u].Derive[i].Name + "\n");
				Skill_txt.append(QStringLiteral("|衍") + QString::number(i + 1) + QStringLiteral("说明={{阴阳师手游:普通技能\n"));
				for (int j = 0; j < data.skill_group[u].Derive[i].Content.size(); j++)
				{
					Skill_txt.append(QStringLiteral("|lv") + QString::number(j + 1) + "=Lv." + QString::number(j + 1) + "\n");
					Skill_txt.append("|lv" + QString::number(j + 1) + QStringLiteral("冷却=") + data.skill_group[u].Derive[i].Content[j].Cd + "\n");
					Skill_txt.append("|lv" + QString::number(j + 1) + QStringLiteral("鬼火=") + data.skill_group[u].Derive[i].Content[j].Cost + "\n");
					Skill_txt.append("|lv" + QString::number(j + 1) + QStringLiteral("描述=") + "\n");
					QStringList Q = data.skill_group[u].Derive[i].Content[j].Desc.split("\n");//按照|分割字符串
					for (int m = 0; m < Q.size() - 1; m++)
					{
						Skill_txt.append("<p>" + Q.at(m) + "</p>\n");
					}
					//去掉行末的空格
					Skill_txt.append("<p>" + Q.at(Q.size() - 1).left(Q.at(Q.size() - 1).length() - 1) + "</p>\n");
				}
				Skill_txt.append("}}\n");
			}
			Skill_txt.append("}}\n");
		}
		if (data.skill_group[u].Remark.size() != 0)
		{
			Skill_txt.append(QStringLiteral("|技能词条={{阴阳师手游:技能词条说明") + "\n");
			int id = 0;
			for (auto a : data.skill_group[u].Remark)
			{
				id++;
				if(std::find(FixItem.begin(), FixItem.end(), a.first)!=FixItem.end())
				{
					Skill_txt.append("|Item" + QString::number(id) + "Color=blue\n");
				}
				else
				{
					Skill_txt.append("|Item" + QString::number(id) + "Color=red\n");
				}
				Skill_txt.append("|Item" + QString::number(id) + "Name=" + a.first + "\n");
				Skill_txt.append("|Item" + QString::number(id) + "Content=\n");
				if (!a.second.isEmpty())
				{
					QStringList Q = a.second.split("\n");//按照|分割字符串
					for (int m = 0; m < Q.size() - 1; m++)
					{
						Skill_txt.append("<p>" + Q.at(m) + "</p>\n");
					}
					//去掉行末的空格,空格成因应该和QString有关吧
					Skill_txt.append("<p>" + Q.at(Q.size() - 1).left(Q.at(Q.size() - 1).length() - 1) + "</p>\n");
				}
			}
			Skill_txt.append("}}\n");
		}
		Skill_txt.append("}}\n");
		Skill_txt.append("\n");
	}
}

void Parser::Form2Txt_Voice()
{
	data_Voice data = Data->voice_info;
	Voice_txt.append(QStringLiteral("== 语音 ==\n"));
	for (int u = 0; u < data.Group.size(); u++)
	{
		Voice_txt.append("=== "+Data->voice_info.Group[u].GroupName+" ===\n");
		Voice_txt.append(QStringLiteral("{{阴阳师手游:语音\n"));
		for (int i = 0; i < data.Group[u].Text.size(); i++)
		{
			Voice_txt.append(QStringLiteral("|动作名") + QString::number(i + 1) + "=" + data.Group[u].Text[i].Action+"\n");
			Voice_txt.append(QStringLiteral("|日") + QString::number(i + 1) + "=" + data.Group[u].Text[i].TextJP+"\n");
			Voice_txt.append(QStringLiteral("|中") + QString::number(i + 1) + "=" + data.Group[u].Text[i].TextCN+"\n");
			Voice_txt.append(QStringLiteral("|播") + QString::number(i + 1) + "=" + data.Group[u].Text[i].PlayButton+"\n");
		}
		Voice_txt.append("}}\n");
	}
}

void Parser::Form2Txt_Story()
{
	data_Story data = Data->story_info;
	Story_txt.append(QStringLiteral("== 传记 ==\n"));
	Story_txt.append(QStringLiteral("{{阴阳师手游:传记1\n"));
	for (int u = 0; u < data.Group.size(); u++)
	{
		Story_txt.append(QStringLiteral("|标")+QString::number(u+1)+"="+data.Group[u].Name+"\n");
		Story_txt.append(QStringLiteral("|条件") + QString::number(u + 1) + "=" + data.Group[u].Condition + "\n");
		Story_txt.append(QStringLiteral("|奖励") + QString::number(u + 1) + "=" + data.Group[u].Award + "\n");
		Story_txt.append(QStringLiteral("|播") + QString::number(u + 1) + "=" + data.Group[u].PlayButton + "\n");
		Story_txt.append(QStringLiteral("|值") + QString::number(u + 1) + "=\n");
		QStringList Q = data.Group[u].Content.split("\n");//按照|分割字符串
		for (int m = 0; m < Q.size() - 1; m++)
		{
			Story_txt.append("<p>" + Q.at(m) + "</p>\n");
		}
		//去掉行末的空格
		Story_txt.append("<p>" + Q.at(Q.size() - 1).left(Q.at(Q.size() - 1).length() - 1) + "</p>\n");
	}
	Story_txt.append("}}\n");
	Story_txt.append("<!-- Edited by Moegirl Onmyoji Editor -->\n\n");
}

void Parser::Txt2Form_BasicInfo()
{
	QFile file(txt_path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QTextStream in(&file);
	state.push(0);//初始设置state=0，当state=-1的时候表示扫描结束
	while (!file.atEnd())
	{//读入一行
		QString str=QString::fromLocal8Bit( file.readLine());
		int nIndex = str.lastIndexOf('\n');
		str = str.left(nIndex);
		line_id++;
		matchBasicInfo(str);
		if (state.top() == -1)
			break;
	}
	line_number[1] = line_id;
	line_id = 0;
}

void Parser::Txt2Form_Skill()
{
	while (!state.empty())
		state.pop();
	state.push(0);
	//初始状态为0
	QFile file(txt_path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QTextStream in(&file);
	while (!file.atEnd())
	{//读入一行
		QString str = QString::fromLocal8Bit(file.readLine());
		int nIndex = str.lastIndexOf('\n');
		str = str.left(nIndex);
		line_id++;
		if (line_id < line_number[1])
			continue;
		std::cout << str.toLocal8Bit().data() << std::endl;
		matchSkill(str);
		if (state.top() == -1)
			break;
	}
	line_number[2] = line_id;
	line_id = 0;
}

void Parser::Txt2Form_Voice()
{
	while (!state.empty())
		state.pop();
	state.push(0);
	//初始状态为0
	QFile file(txt_path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QTextStream in(&file);
	while (!file.atEnd())
	{//读入一行
		QString str = QString::fromLocal8Bit(file.readLine());
		int nIndex = str.lastIndexOf('\n');
		str = str.left(nIndex);
		line_id++;
		if (line_id < line_number[2])
			continue;
		std::cout << str.toLocal8Bit().data() << std::endl;
		matchVoice(str);
		if (state.top() == -1)
			break;
	}
	line_number[3] = line_id;
	line_id = 0;
}

void Parser::Txt2Form_Story()
{
	while (!state.empty())
		state.pop();
	state.push(0);
	//初始状态为0
	QFile file(txt_path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QTextStream in(&file);
	while (!file.atEnd())
	{//读入一行
		QString str = QString::fromLocal8Bit(file.readLine());
		int nIndex = str.lastIndexOf('\n');
		str = str.left(nIndex);
		line_id++;
		if (line_id < line_number[3])
			continue;
		std::cout << str.toLocal8Bit().data() << std::endl;
		matchStory(str);
		if (state.top() == -1)
			break;
	}
}