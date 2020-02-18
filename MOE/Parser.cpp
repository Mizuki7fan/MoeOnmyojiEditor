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
	QString value = str.mid(k + 1, str.length() - k);//ȡ�Ⱥ��Ҳ��ֵ
	if (state.top() == 0)
	{//��0״̬�£�����==��������==��������������stateΪ1
		if (str.indexOf(QStringLiteral("== �������� ==")) != -1)
		{
			state.push(1);
			return;
		}
		else if (str.indexOf(QStringLiteral("== ���� ==")) != -1)
		{
			state.push(-1);//��ֹ
			return;
		}
	}
	else if (state.top() == 1)
	{
		if (str.indexOf(QStringLiteral("{{����ʦ����:������Ϣ��")) != -1)
		{
			state.push(2);
			return;
		}

	}
	else if (state.top() == 2)
	{
		if (str.indexOf(QStringLiteral("|ʽ������")) != -1)
			Data->basic_info.NameCN = value;
		else if (str.indexOf(QStringLiteral("|ʽ����������")) != -1)
		{
			QStringList Q = str.split("|");//����|�ָ��ַ���
			Data->basic_info.NameJP = Q.at(2);
			Data->basic_info.NameHiragara = Q.at(3);
		}
		else if (str.indexOf(QStringLiteral("|����")) != -1)
			Data->basic_info.CV = value;
		else if (str.indexOf(QStringLiteral("|ϡ�ж�")) != -1)
			Data->basic_info.Rarity = value;
		else if (str.indexOf(QStringLiteral("|��÷�ʽ")) != -1)
			Data->basic_info.Getway = value;
		else if (str.indexOf(QStringLiteral("|�����ռ�")) != -1)
			Data->basic_info.Region = value;
		else if (str.indexOf(QStringLiteral("|δ���ѹ����ȼ�")) != -1)
			Data->basic_info.NAAtkRank = value;
		else if (str.indexOf(QStringLiteral("|δ���������ȼ�")) != -1)
			Data->basic_info.NAHpRank = value;
		else if (str.indexOf(QStringLiteral("|δ���ѷ����ȼ�")) != -1)
			Data->basic_info.NADefRank = value;
		else if (str.indexOf(QStringLiteral("|δ�����ٶȵȼ�")) != -1)
			Data->basic_info.NASpdRank = value;
		else if (str.indexOf(QStringLiteral("|δ���ѱ����ȼ�")) != -1)
			Data->basic_info.NACrtRank = value;
		else if (str.indexOf(QStringLiteral("|���ѹ����ȼ�")) != -1)
			Data->basic_info.AAtkRank = value;
		else if (str.indexOf(QStringLiteral("|���������ȼ�")) != -1)
			Data->basic_info.AHpRank = value;
		else if (str.indexOf(QStringLiteral("|���ѷ����ȼ�")) != -1)
			Data->basic_info.ADefRank = value;
		else if (str.indexOf(QStringLiteral("|�����ٶȵȼ�")) != -1)
			Data->basic_info.ASpdRank = value;
		else if (str.indexOf(QStringLiteral("|���ѱ����ȼ�")) != -1)
			Data->basic_info.ACrtRank = value;
		else if (str.indexOf(QStringLiteral("|1������")) != -1)
			Data->basic_info.NAAtk = value;
		else if (str.indexOf(QStringLiteral("|1������")) != -1)
			Data->basic_info.NAHp = value;
		else if (str.indexOf(QStringLiteral("|1������")) != -1)
			Data->basic_info.NADef = value;
		else if (str.indexOf(QStringLiteral("|1���ٶ�")) != -1)
			Data->basic_info.NASpd = value;
		else if (str.indexOf(QStringLiteral("|1������")) != -1)
			Data->basic_info.NACrt = value;
		else if (str.indexOf(QStringLiteral("|40������")) != -1)
			Data->basic_info.AAtk = value;
		else if (str.indexOf(QStringLiteral("|40������")) != -1)
			Data->basic_info.AHp = value;
		else if (str.indexOf(QStringLiteral("|40������")) != -1)
			Data->basic_info.ADef = value;
		else if (str.indexOf(QStringLiteral("|40���ٶ�")) != -1)
			Data->basic_info.ASpd = value;
		else if (str.indexOf(QStringLiteral("|40������")) != -1)
			Data->basic_info.ACrt = value;
		else if (str.indexOf(QStringLiteral("|δ���ѱ���")) != -1)
			Data->basic_info.NACtd = value;
		else if (str.indexOf(QStringLiteral("|δ��������")) != -1)
			Data->basic_info.NAHr = value;
		else if (str.indexOf(QStringLiteral("|δ���ѵֿ�")) != -1)
			Data->basic_info.NAResist = value;
		else if (str.indexOf(QStringLiteral("|���ѱ���")) != -1)
			Data->basic_info.ACtd = value;
		else if (str.indexOf(QStringLiteral("|��������")) != -1)
			Data->basic_info.AHr = value;
		else if (str.indexOf(QStringLiteral("|���ѵֿ�")) != -1)
			Data->basic_info.AResist = value;
		else if (str.indexOf(QStringLiteral("|����Ч������")) != -1)
			Data->basic_info.AEffectKind = value;
		else if (str.indexOf(QStringLiteral("|����Ч��")) != -1)
			Data->basic_info.AEffect = value;
		else if (str.indexOf(QStringLiteral("|���")) != -1)
			Data->basic_info.Alias = value;
		else if (str.indexOf(QStringLiteral("|��ؽ�ɫ")) != -1)
			Data->basic_info.Relevant = value;
		else if (str.indexOf(QStringLiteral("|ʽ����")) != -1)
		{//�����ʽ�����״̬
			state.push(3);
		}
		else if (str.indexOf(QStringLiteral("|ʽ������")) != -1)
		{
			state.push(4);
		}
		else if (str.indexOf("}}") == 0)//��2״̬����}}
		{
			state.pop();
			state.pop();
		}
	}
	else if (state.top() == 3)
	{//����ʽ����
		if (str.indexOf("|") == 0)
		{
			state.pop();
			goto start;
		}
		else
			Data->basic_info.Intro.append(value);
	}
	else if (state.top() == 4)
	{//����������״̬
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
	QString value = str.mid(k + 1, str.length() - k);//ȡ�Ⱥ��Ҳ��ֵ
	if (state.top() == 0)
	{//��0״̬�£�����==��������==��������������stateΪ1
		if (str.indexOf(QStringLiteral("== ���� ==")) != -1)
			state.push(1);
		return;
	}
	else if (state.top() == 1)
	{
		if (str.indexOf(QStringLiteral("{{����ʦ����:ͨ�ü���")) != -1)
		{
			state.push(2);
			data_SingleSkillInfo tmp;
			Data->skill_info.skill_group.push_back(tmp);
			skill_no++;
			return;
		}
		else if (str.indexOf(QStringLiteral("== ���� ==")) != -1)
		{
			state.push(-1);
			return;
		}
	}
	else if (state.top() == 2)
	{
		if (str.indexOf(QStringLiteral("|����ͼ��")) != -1)
			Data->skill_info.skill_group[skill_no].Icon = value;
		else if (str.indexOf(QStringLiteral("|��������")) != -1)
			Data->skill_info.skill_group[skill_no].Name = value;
		else if (str.indexOf(QStringLiteral("|����̨��")) != -1)
			Data->skill_info.skill_group[skill_no].Dialogue = value;
		else if (str.indexOf(QStringLiteral("|��������")) != -1)
		{
			state.push(3);
		}
		else if (str.indexOf(QStringLiteral("|��������")) != -1)
		{
			state.push(5);
		}
		else if (str.indexOf(QStringLiteral("|���ܴ���")) != -1)
		{
			skill_remark_no = -1;
			state.push(8);
		}
		else if (str.indexOf("}}"))
		{//����ΪֹӦ���ǵ�������˵�����
			state.pop();
		}
	}
	else if (state.top() == 3)
	{//
		if (str.indexOf(QStringLiteral("|lv")) != -1)
		{
			if (str.indexOf(QStringLiteral("��ȴ")) != -1)
			{
				Data->skill_info.skill_group[skill_no].Content[skill_lv_no].Cd = value;
			}
			else if (str.indexOf(QStringLiteral("���")) != -1)
			{
				Data->skill_info.skill_group[skill_no].Content[skill_lv_no].Cost = value;
			}
			else if (str.indexOf(QStringLiteral("����")) != -1)
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
	{//�����Ǽ�������������
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
	{//��ʼ�������ܵĶ�ȡ
		if (str.indexOf(QStringLiteral("|��")) != -1)
		{
			if (str.indexOf(QStringLiteral("ͼ��")) != -1)
			{
				data_SkillDerive tmp;
				skill_derive_no++;
				Data->skill_info.skill_group[skill_no].Derive.push_back(tmp);
				Data->skill_info.skill_group[skill_no].Derive[skill_derive_no].Icon = value;
			}
			else if (str.indexOf(QStringLiteral("��")) != -1)
				Data->skill_info.skill_group[skill_no].Derive[skill_derive_no].Name = value;
			else if (str.indexOf(QStringLiteral("˵��")) != -1)
			{//�����������ܵ�˵��
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
			if (str.indexOf(QStringLiteral("��ȴ")) != -1)
			{
				Data->skill_info.skill_group[skill_no].Derive[skill_derive_no].Content[skill_lv_no].Cd = value;
			}
			else if (str.indexOf(QStringLiteral("���")) != -1)
			{
				Data->skill_info.skill_group[skill_no].Derive[skill_derive_no].Content[skill_lv_no].Cost = value;
			}
			else if (str.indexOf(QStringLiteral("����")) != -1)
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
		{//��ʾ��������˵������

			skill_lv_no = -1;
			state.pop();
			return;
		}
	}
	else if (state.top() == 7)
	{//�������ܵ�����
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
	{//�����Ǽ�������������
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
	QString value = str.mid(k + 1, str.length() - k);//ȡ�Ⱥ��Ҳ��ֵ
	if (state.top() == 0)
	{//��0״̬�£�����==��������==��������������stateΪ1
		if (str.indexOf(QStringLiteral("== ���� ==")) != -1)
			state.push(1);
		return;
	}
	else if (state.top() == 1)
	{//��ȡ��������������
		if (str.indexOf(QStringLiteral("=== ")) != -1)
		{
			QStringList Q = str.split("===");
			//��ȡ�÷��������
			QString q = Q.at(1).trimmed();
			data_VoiceGroup tmp;
			Data->voice_info.Group.push_back(tmp);
			voice_no++;
			//�÷��������
			Data->voice_info.Group[voice_no].GroupName = q;
			state.push(2);
		}
		else if (str.indexOf(QStringLiteral("== ���� ==")))
		{
			state.push(-1);
			return;
		}
	}
	else if (state.top() == 2)
	{
		if (str.indexOf(QStringLiteral("|������")) != -1)
		{
			data_SingleVoice tmp;
			tmp.Action = value;
			Data->voice_info.Group[voice_no].Text.push_back(tmp);
			voicegroup_no++;
		}
		else if (str.indexOf(QStringLiteral("|��")) != -1)
		{
			Data->voice_info.Group[voice_no].Text[voicegroup_no].TextJP = value;
		}
		else if (str.indexOf(QStringLiteral("|��")) != -1)
		{
			Data->voice_info.Group[voice_no].Text[voicegroup_no].TextCN = value;
		}
		else if (str.indexOf(QStringLiteral("|��")) != -1)
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
	QString value = str.mid(k + 1, str.length() - k);//ȡ�Ⱥ��Ҳ��ֵ
	if (state.top() == 0)
	{//��0״̬�£�����==��������==��������������stateΪ1
		if (str.indexOf(QStringLiteral("== ���� ==")) != -1)
			state.push(1);
		return;
	}
	else if (state.top() == 1)
	{
		if (str.indexOf(QStringLiteral("|��")) != -1)
		{
			data_SingleStory tmp;
			tmp.Name = value;
			Data->story_info.Group.push_back(tmp);
			story_no++;
		}
		else if (str.indexOf(QStringLiteral("|����")) != -1)
		{
			Data->story_info.Group[story_no].Condition = value;
		}
		else if (str.indexOf(QStringLiteral("|����")) != -1)
		{
			Data->story_info.Group[story_no].Award= value;
		}
		else if (str.indexOf(QStringLiteral("|��")) != -1)
		{
			Data->story_info.Group[story_no].PlayButton = value;
		}
		else if (str.indexOf(QStringLiteral("|ֵ")) != -1)
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
	BasicInfo_txt.append(QStringLiteral("== �������� ==\n"));
	BasicInfo_txt.append(QStringLiteral("{{����ʦ����:������Ϣ��\n"));
	BasicInfo_txt.append(QStringLiteral("|ʽ������=") + data.NameCN + "\n");
	BasicInfo_txt.append(QStringLiteral("|ʽ����������={{ruby|") + data.NameJP + "|" + data.NameHiragara + "|ja}}\n");
	BasicInfo_txt.append(QStringLiteral("|����=") + data.CV + "\n");
	BasicInfo_txt.append(QStringLiteral("|ϡ�ж�=") + data.Rarity + "\n");
	BasicInfo_txt.append(QStringLiteral("|��÷�ʽ=") + data.Getway + "\n");
	BasicInfo_txt.append(QStringLiteral("|�����ռ�=") + data.Region + "\n");
	BasicInfo_txt.append(QStringLiteral("|δ���ѹ����ȼ�=") + data.NAAtkRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|δ���������ȼ�=") + data.NAHpRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|δ���ѷ����ȼ�=") + data.NADefRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|δ�����ٶȵȼ�=") + data.NASpdRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|δ���ѱ����ȼ�=") + data.NACrtRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|1������=") + data.NAAtk + "\n");
	BasicInfo_txt.append(QStringLiteral("|1������=") + data.NAHp + "\n");
	BasicInfo_txt.append(QStringLiteral("|1������=") + data.NADef + "\n");
	BasicInfo_txt.append(QStringLiteral("|1���ٶ�=") + data.NASpd + "\n");
	BasicInfo_txt.append(QStringLiteral("|1������=") + data.NACrt + "\n");
	BasicInfo_txt.append(QStringLiteral("|���ѹ����ȼ�=") + data.AAtkRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|���������ȼ�=") + data.AHpRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|���ѷ����ȼ�=") + data.ADefRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|�����ٶȵȼ�=") + data.ASpdRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|���ѱ����ȼ�=") + data.ACrtRank + "\n");
	BasicInfo_txt.append(QStringLiteral("|40������=") + data.AAtk + "\n");
	BasicInfo_txt.append(QStringLiteral("|40������=") + data.AHp + "\n");
	BasicInfo_txt.append(QStringLiteral("|40������=") + data.ADef + "\n");
	BasicInfo_txt.append(QStringLiteral("|40���ٶ�=") + data.ASpd + "\n");
	BasicInfo_txt.append(QStringLiteral("|40������=") + data.ACrt + "\n");
	BasicInfo_txt.append(QStringLiteral("|δ���ѱ���=") + data.ACtd + "\n");
	BasicInfo_txt.append(QStringLiteral("|δ��������=") + data.AHr + "\n");
	BasicInfo_txt.append(QStringLiteral("|δ���ѵֿ�=") + data.AResist + "\n");
	BasicInfo_txt.append(QStringLiteral("|���ѱ���=") + data.ACtd + "\n");
	BasicInfo_txt.append(QStringLiteral("|��������=") + data.AHr + "\n");
	BasicInfo_txt.append(QStringLiteral("|���ѵֿ�=") + data.AResist + "\n");
	BasicInfo_txt.append(QStringLiteral("|����Ч������=") + data.AEffectKind + "\n");
	BasicInfo_txt.append(QStringLiteral("|����Ч��=") + data.AEffect + "\n");
	BasicInfo_txt.append(QStringLiteral("|���=") + data.Alias + "\n");
	BasicInfo_txt.append(QStringLiteral("|��ؽ�ɫ=") + data.Relevant + "\n");
	BasicInfo_txt.append(QStringLiteral("|ʽ����=\n"));
	QStringList Q = data.Intro.split("\n");
	for (int i = 0; i < Q.size() - 1; i++)
	{
		BasicInfo_txt.append(Q.at(i) + "<br>\n");
	}
	BasicInfo_txt.append(QStringLiteral("|ʽ������={{tabs\n"));
	for (int i = 0; i < data.SkinName.size(); i++)
	{
		BasicInfo_txt.append("|bt" + QString::number(i + 1) + "=" + data.SkinName[i] + "\n");
		BasicInfo_txt.append("|tab" + QString::number(i + 1) + "=" + data.SkinPng[i] + "\n");
	}
	BasicInfo_txt.append("|DefaultTab=1\n|AutoWidth=yes\n}}\n}}\n\n");
}

void Parser::Form2Txt_Skill()
{
	std::vector<QString> trans = { QStringLiteral("����һ"),QStringLiteral("���ܶ�"),QStringLiteral("������"), QStringLiteral("������"), QStringLiteral("������"), QStringLiteral("������"), QStringLiteral("������"), QStringLiteral("���ܰ�") };
	data_SkillInfo data = Data->skill_info;
	Skill_txt.append(QStringLiteral("== ���� ==\n"));
	int n_skill = data.skill_group.size();
	for (int u = 0; u < n_skill; u++)
	{
		Skill_txt.append("=== " + trans[u] + " ===\n");
		Skill_txt.append(QStringLiteral("{{����ʦ����:ͨ�ü���\n"));
		Skill_txt.append(QStringLiteral("|����ͼ��=") + data.skill_group[u].Icon + "\n");
		Skill_txt.append(QStringLiteral("|��������=") + data.skill_group[u].Name + "\n");
		Skill_txt.append(QStringLiteral("|����̨��=") + data.skill_group[u].Dialogue + "\n");
		Skill_txt.append(QStringLiteral("|��������={{����ʦ����:��ͨ����") + "\n");
		for (int i = 0; i < data.skill_group[u].Content.size(); i++)
		{
			Skill_txt.append("|lv" + QString::number(i + 1) + "=Lv." + QString::number(i + 1) + "\n");
			Skill_txt.append("|lv" + QString::number(i + 1) + QStringLiteral("��ȴ=") + data.skill_group[u].Content[i].Cd + "\n");
			Skill_txt.append("|lv" + QString::number(i + 1) + QStringLiteral("���=") + data.skill_group[u].Content[i].Cost + "\n");
			Skill_txt.append("|lv" + QString::number(i + 1) + QStringLiteral("����=") + "\n");
			QStringList Q = data.skill_group[u].Content[i].Desc.split("\n");//����|�ָ��ַ���
			for (int m = 0; m < Q.size() - 1; m++)
			{
				Skill_txt.append("<p>" + Q.at(m) + "</p>\n");
			}
			//ȥ����ĩ�Ŀո�
			Skill_txt.append("<p>" + Q.at(Q.size() - 1).left(Q.at(Q.size() - 1).length() - 1) + "</p>\n");
		}
		Skill_txt.append("}}\n");
		if (data.skill_group[u].Derive.size() != 0)
		{
			Skill_txt.append(QStringLiteral("|��������={{����ʦ����:��������") + "\n");
			for (int i = 0; i < data.skill_group[u].Derive.size(); i++)
			{
				Skill_txt.append(QStringLiteral("|��") + QString::number(i + 1) + QStringLiteral("ͼ��=") + data.skill_group[u].Derive[i].Icon + "\n");
				Skill_txt.append(QStringLiteral("|��") + QString::number(i + 1) + QStringLiteral("��=") + data.skill_group[u].Derive[i].Name + "\n");
				Skill_txt.append(QStringLiteral("|��") + QString::number(i + 1) + QStringLiteral("˵��={{����ʦ����:��ͨ����\n"));
				for (int j = 0; j < data.skill_group[u].Derive[i].Content.size(); j++)
				{
					Skill_txt.append(QStringLiteral("|lv") + QString::number(j + 1) + "=Lv." + QString::number(j + 1) + "\n");
					Skill_txt.append("|lv" + QString::number(j + 1) + QStringLiteral("��ȴ=") + data.skill_group[u].Derive[i].Content[j].Cd + "\n");
					Skill_txt.append("|lv" + QString::number(j + 1) + QStringLiteral("���=") + data.skill_group[u].Derive[i].Content[j].Cost + "\n");
					Skill_txt.append("|lv" + QString::number(j + 1) + QStringLiteral("����=") + "\n");
					QStringList Q = data.skill_group[u].Derive[i].Content[j].Desc.split("\n");//����|�ָ��ַ���
					for (int m = 0; m < Q.size() - 1; m++)
					{
						Skill_txt.append("<p>" + Q.at(m) + "</p>\n");
					}
					//ȥ����ĩ�Ŀո�
					Skill_txt.append("<p>" + Q.at(Q.size() - 1).left(Q.at(Q.size() - 1).length() - 1) + "</p>\n");
				}
				Skill_txt.append("}}\n");
			}
			Skill_txt.append("}}\n");
		}
		if (data.skill_group[u].Remark.size() != 0)
		{
			Skill_txt.append(QStringLiteral("|���ܴ���={{����ʦ����:���ܴ���˵��") + "\n");
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
					QStringList Q = a.second.split("\n");//����|�ָ��ַ���
					for (int m = 0; m < Q.size() - 1; m++)
					{
						Skill_txt.append("<p>" + Q.at(m) + "</p>\n");
					}
					//ȥ����ĩ�Ŀո�,�ո����Ӧ�ú�QString�йذ�
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
	Voice_txt.append(QStringLiteral("== ���� ==\n"));
	for (int u = 0; u < data.Group.size(); u++)
	{
		Voice_txt.append("=== "+Data->voice_info.Group[u].GroupName+" ===\n");
		Voice_txt.append(QStringLiteral("{{����ʦ����:����\n"));
		for (int i = 0; i < data.Group[u].Text.size(); i++)
		{
			Voice_txt.append(QStringLiteral("|������") + QString::number(i + 1) + "=" + data.Group[u].Text[i].Action+"\n");
			Voice_txt.append(QStringLiteral("|��") + QString::number(i + 1) + "=" + data.Group[u].Text[i].TextJP+"\n");
			Voice_txt.append(QStringLiteral("|��") + QString::number(i + 1) + "=" + data.Group[u].Text[i].TextCN+"\n");
			Voice_txt.append(QStringLiteral("|��") + QString::number(i + 1) + "=" + data.Group[u].Text[i].PlayButton+"\n");
		}
		Voice_txt.append("}}\n");
	}
}

void Parser::Form2Txt_Story()
{
	data_Story data = Data->story_info;
	Story_txt.append(QStringLiteral("== ���� ==\n"));
	Story_txt.append(QStringLiteral("{{����ʦ����:����1\n"));
	for (int u = 0; u < data.Group.size(); u++)
	{
		Story_txt.append(QStringLiteral("|��")+QString::number(u+1)+"="+data.Group[u].Name+"\n");
		Story_txt.append(QStringLiteral("|����") + QString::number(u + 1) + "=" + data.Group[u].Condition + "\n");
		Story_txt.append(QStringLiteral("|����") + QString::number(u + 1) + "=" + data.Group[u].Award + "\n");
		Story_txt.append(QStringLiteral("|��") + QString::number(u + 1) + "=" + data.Group[u].PlayButton + "\n");
		Story_txt.append(QStringLiteral("|ֵ") + QString::number(u + 1) + "=\n");
		QStringList Q = data.Group[u].Content.split("\n");//����|�ָ��ַ���
		for (int m = 0; m < Q.size() - 1; m++)
		{
			Story_txt.append("<p>" + Q.at(m) + "</p>\n");
		}
		//ȥ����ĩ�Ŀո�
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
	state.push(0);//��ʼ����state=0����state=-1��ʱ���ʾɨ�����
	while (!file.atEnd())
	{//����һ��
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
	//��ʼ״̬Ϊ0
	QFile file(txt_path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QTextStream in(&file);
	while (!file.atEnd())
	{//����һ��
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
	//��ʼ״̬Ϊ0
	QFile file(txt_path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QTextStream in(&file);
	while (!file.atEnd())
	{//����һ��
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
	//��ʼ״̬Ϊ0
	QFile file(txt_path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QTextStream in(&file);
	while (!file.atEnd())
	{//����һ��
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