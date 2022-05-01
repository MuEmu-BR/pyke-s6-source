#pragma once

#define MAX_CUSTOM_HPBAR	500
//#define MAX_CUSTOM_MONSTERS	100

struct CUSTOM_HPBAR
{
	int Index;
	int MonsterID;
	char Name[25];
	BYTE Red;
	BYTE Green;
	BYTE Blue;
	float Opacity;
};

class Monster
{
public:
	Monster();
	virtual ~Monster();
	void Init();
	void Load(char * path);
	void SetInfo(CUSTOM_HPBAR info);
public:
	CUSTOM_HPBAR m_CustomHpBar[MAX_CUSTOM_HPBAR];
}; extern Monster gMonster;