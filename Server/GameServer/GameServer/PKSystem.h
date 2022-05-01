// PKSystem.h: interface for the CPKSystem class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "User.h"

struct PK_SYSTEM_INFO
{
	int Index;
	int ItemLoseRateOnMonsterKill;
	int ItemLoseRateOnPlayerKill;
	int ItemMinLevel;
	int ItemMaxLevel;
	int DropExc;
	int DropSet;
	int DropSocket;
	int DropHarmony;
};

struct PK_SYSTEM_SAFE_ZONE_INFO
{
	int Map;
	int X;
	int Y;
	int TX;
	int TY;
	int MinLevel;
	int MaxLevel;
	int MinReset;
	int MaxReset;
	int AccountLevel;
};

class CPKSystem
{
public:
	CPKSystem();
	virtual ~CPKSystem();
	void Load(char* path);
	void UserDieProc(LPOBJ lpObj, LPOBJ lpTarget);
	bool CheckSafeZone(LPOBJ lpObj);
private:
	std::map<int, PK_SYSTEM_INFO> m_PKSystemInfo;
	std::vector<PK_SYSTEM_SAFE_ZONE_INFO> m_PKSystemSafeZoneInfo;
};

extern CPKSystem gPKSystem;
