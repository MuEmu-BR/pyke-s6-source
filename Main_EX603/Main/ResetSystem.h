#pragma once
// -------------------------------------------------------------------------------

#include "Protocol.h"
#include "Defines.h"
// -------------------------------------------------------------------------------

#define	RESET_DEBUG			0
#define	MAX_RESET_GROUP		500
//#define	MAX_RESET_MONEY		1500000000
#define MAX_RESET_ITEM		5
#define CHECK_RESET_INV		1
// -------------------------------------------------------------------------------

struct RESET_REQ_USERDATA
{
	PSBMSG_HEAD h;
};

// -------------------------------------------------------------------------------

struct RESET_ITEM_DATA
{
	WORD	ID;
	BYTE	MinLevel;
	BYTE	MaxLevel;
	BYTE	MinOption;
	BYTE	MaxOption;
	BYTE	IsLuck;
	BYTE	IsSkill;
	bool	IsExcellent;
	bool	IsAncient;
	bool	IsSocket;
	int		Count;
};
// -------------------------------------------------------------------------

struct RESET_REWARD_DATA
{
	int		LevelPoint;
	int		GensPoint;
	int		WCoinC;
	int		WCoinP;
	int		GoblinPoint;
	int		Credits;
};
// -------------------------------------------------------------------------

struct RESET_GROUP_DATA
{
	int		MinReset;
	int		MaxReset;
	int		ReqLevel[MAX_ACCOUNT_LEVEL];
	int		ReqMoney[MAX_ACCOUNT_LEVEL];
	int		ItemCount;
	RESET_ITEM_DATA		ItemData[MAX_RESET_ITEM];
	RESET_REWARD_DATA	RewardData[7];
};
// -------------------------------------------------------------------------

struct RESET_CURRENT_DATA
{
	int MinReset;
	int MaxReset;
	int ReqLevel;
	int ItemCount;
	RESET_ITEM_DATA		ItemData[MAX_RESET_ITEM];
	RESET_REWARD_DATA RewardData;
};
// -------------------------------------------------------------------------------

struct RESET_ANS_USERDATA
{
	PSBMSG_HEAD h;
	bool		ByDialog;
	int			Reset;
	int			GrandReset;
	int			ResetMoney;
	int			CommandPerReset;
	RESET_CURRENT_DATA ResetData;
	bool		ItemCheck[MAX_RESET_ITEM];
};

class ResetSystem
{
public:
			ResetSystem();
	virtual ~ResetSystem();
	// ----
	void	Init();
	void	Load();
	void	ReadGroupData(char * File);
	// ----
	int		GetResetMoney();
	//int		GetResetGroup();
	bool	CheckAllReq();
	// ----
	void	SetData(RESET_ANS_USERDATA * aRecv);
	void	ReqResetFinish();
	void	GetResetResult();
	int		GetRewardPoints();
	// ----
	//int		m_GroupLoadedCount;
	//RESET_GROUP_DATA	m_GroupData[MAX_RESET_GROUP];
	RESET_CURRENT_DATA m_ResetData;
	DWORD ResetMoney;
	int m_BonusCommand;
	// ----
}; extern ResetSystem gResetSystem;
// -------------------------------------------------------------------------------