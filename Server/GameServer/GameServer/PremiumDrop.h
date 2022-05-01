#pragma once

#include "User.h"

struct PREMIUM_DROP_INFO
{
	int MapNumber;
	int MonsterClass;
	int MonsterLevelMin;
	int MonsterLevelMax;
	int PremiumLevel;
	int TimeValue;
	int TimeForBiggerAL;
	int DropRate;
};

class CPremiumDrop
{
public:
	CPremiumDrop();
	virtual ~CPremiumDrop();
	void Load(char* path);
	bool DropPremium(LPOBJ lpObj, LPOBJ lpTarget); 
private:
	std::vector<PREMIUM_DROP_INFO> m_PremiumDropInfo;
	bool m_PremiumDropEnable;
}; extern CPremiumDrop gPremiumDrop;