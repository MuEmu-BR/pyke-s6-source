#pragma once
// -------------------------------------------------------------------------------

#define MAX_SHOPPOINTEX_EVENT		7
#define MAX_SHOPPOINTEX_MONSTER		1024
#include "User.h"
// -------------------------------------------------------------------------------

namespace ShopPointExEvent
{
	enum T
	{
		BC	= 0,
		DS	= 1,
		CC	= 2,
		IT	= 3,
		CW	= 4,
		DG	= 5,
		IG	= 6,
	};
};
// -------------------------------------------------------------------------------

struct SHOPPOINTEX_EVENT
{
	int		AddCredits;
	int		AddCoinC;
	int		AddCoinP;
	int		AddCoinG;
};
// -------------------------------------------------------------------------------

struct SHOPPOINTEX_MONSTER
{
	DWORD	MonsterID;
	int		MapNumber;
	int		AddCoinC;
	int		AddCoinP;
	int		AddCoinG;
	int		AddCredits;
	int		AddGuildScore;
	// ----
	SHOPPOINTEX_MONSTER()
	{
		ZeroMemory(this, sizeof(*this));
	}
};
// -------------------------------------------------------------------------------

class ShopPointEx
{
public:
			ShopPointEx();
			~ShopPointEx();
	// ----
	void	Init();
	void	Load(char* path);
	// ----
	int		GetMonsterSlot(int Class, int Map);
	// ----
	void	AddTimeBonus(int UserIndex);
	void	AddEventBonus(int UserIndex, ShopPointExEvent::T Event);
	void	AddMonsterBonus(LPOBJ lpObj, LPOBJ lpTarget);
	// ----
	void	SendNotify(int UserIndex, int CoinC, int CoinP, int CoinG, int Credits, char* Text);
	// ----
public:
	bool	m_IsLoaded;
	bool	m_TimeBonusOn;
	int		m_TimeBonusWCoinC;
	int		m_TimeBonusWCoinP;
	int		m_TimeBonusWCoinG;
	int		m_TimeBonusCredits;
	DWORD	m_TimeBonusInterval;
	int		m_MonsterLoaded;
	// ----
	SHOPPOINTEX_EVENT	m_EventBonus[MAX_SHOPPOINTEX_EVENT];
	//SHOPPOINTEX_MONSTER m_MonsterBonus[MAX_SHOPPOINTEX_MONSTER];
	std::vector<SHOPPOINTEX_MONSTER> m_MobsData;
	// ----
}; extern ShopPointEx gShopPointEx;
// -------------------------------------------------------------------------------