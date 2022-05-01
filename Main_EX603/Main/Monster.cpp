#include "stdafx.h"
#include "Monster.h"
#include "MonsterBar.h"


Monster gMonster;

Monster::Monster()
{
	this->Init();
}

Monster::~Monster()
{
	
}

void Monster::Init()
{
	for (int n = 0; n < MAX_CUSTOM_HPBAR; n++)
	{
		this->m_CustomHpBar[n].Index = -1;
	}
}

void Monster::Load(CUSTOM_HPBAR* info) // OK
{
	for(int n=0;n < MAX_CUSTOM_HPBAR;n++)
	{
		this->SetInfo(info[n]);
	}
}

void Monster::SetInfo(CUSTOM_HPBAR info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_HPBAR)
	{
		return;
	}
	//console.Log("HpBar", "[Load] %d %s", info.Index, info.Name);
	this->m_CustomHpBar[info.Index] = info;

	MONSTERBAR_DATA data;
	data.MonsterID = info.MonsterID;
	strcpy_s(data.Text,info.Name);
	data.Red = info.Red;
	data.Green = info.Green;
	data.Blue = info.Blue;
	data.Opacity = info.Opacity;
	gMonsterBar.AddMonsterBar(data);
}

CUSTOM_HPBAR* Monster::GetHpBar(int MosnterID) // OK
{
	for(int n=0;n < MAX_CUSTOM_HPBAR;n++)
	{
		CUSTOM_HPBAR* lpInfo = this->GetHpBarByIndex(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(lpInfo->MonsterID == MosnterID)
		{
			return lpInfo;
		}
	}

	return 0;
}


CUSTOM_HPBAR* Monster::GetHpBarByIndex(int index) // OK
{
	if(index < 0 || index >= MAX_CUSTOM_HPBAR)
	{
		return 0;
	}

	if(this->m_CustomHpBar[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomHpBar[index];
}