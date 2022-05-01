// CustomArcher.h: interface for the CCustomArcher class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "User.h"

struct GOLDER_ARCHER_ITEM_INFO
{
	int Index;
	int Durability;
	int Option0;
	int Option1;
	int Option2;
	int Option3;
	int Option4;
	int Option5;
	int Option6;
	int Duration;
	int Rate;
};

class CCustomArcher
{
public:
	CCustomArcher();
	virtual ~CCustomArcher();
	void Load(char* path);
	void NpcGoldenArcher(LPOBJ lpNpc,LPOBJ lpObj);
private:
	int m_ItemIndex;
	int m_ItemLevel;
	int m_ItemCount;
	int m_ItemDropCount;
	int m_SendFirework;
	std::vector<GOLDER_ARCHER_ITEM_INFO> m_GoldenArcherItemInfo;
};

extern CCustomArcher gCustomArcher;