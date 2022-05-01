#pragma once

#include "Protocol.h"
#include "Object.h"

#define MAX_MAIN_VIEWPORT 400
#define RGBTOGLFLOAT(x) ((float)x/255.0f)
#define FLOATTORGB(x)	((float)x*255)
#define ABS(x) (((x) < 0) ? (-(x)) : (x))
#define pGetRand				((int(*)()) 0x9CFB8D)

struct NEW_HEALTH_BAR
{
	WORD index;
	BYTE type;
	BYTE rate;
	WORD monsterid;
	float Life;
	float MaxLife;
	short Level;
	int Reset;
	int Shield;
	int MaxShield;
	BYTE SDrate;
	bool isSameGuild;
	bool HaveGuild;
	char GuildName[11];
	BYTE Mark[64];
	//BYTE Rank;
};

class CHPBar
{
public:
	CHPBar();
	virtual ~CHPBar();
	void ClearNewHealthBar();
	void InsertNewHealthBar(PMSG_NEW_HEALTH_RECV* lpInfo);
	NEW_HEALTH_BAR* GetNewHealthBar(WORD index,BYTE type);
	void DrawHealthBar();
	void DrawTestHealthBar();
	void DrawCharacterBar(lpViewObj lpObj);
	static void DrawAllHPBars();
	bool IsPartyMember(int ViewportID);
	//int GetCountOfNumbers(int n);
	char* del_char(char* s, char c);
	//char* GetHPValue(int HP);
	char* ParseReducedValue(DWORD Num);
	//void ChangeState();
	//
}; extern CHPBar gHPBar;