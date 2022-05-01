#pragma once

#define MAX_CUSTOM_HPBAR	500

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
	void Load(CUSTOM_HPBAR* info);
	void SetInfo(CUSTOM_HPBAR info);
	CUSTOM_HPBAR* GetHpBar(int MonsterID);
	CUSTOM_HPBAR* GetHpBarByIndex(int index);
public:
	CUSTOM_HPBAR m_CustomHpBar[MAX_CUSTOM_HPBAR];
}; extern Monster gMonster;