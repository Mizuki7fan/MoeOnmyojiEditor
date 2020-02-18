#pragma once
#include <QString>
#include <vector>

struct data_SingleStory
{
	QString Name, Condition, Award;
	QString PlayButton;
	QString Content;
};

struct data_Story
{
	std::vector<data_SingleStory> Group;
};