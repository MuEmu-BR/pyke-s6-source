#pragma once
// -------------------------------------------------------------------------------

//#include "..\include\prodef.h"
#include "Protocol.h"
#include "DefaultClassInfo.h"
// -------------------------------------------------------------------------------

#define	MAX_RESET_GROUP		500
#define MAX_RESET_ITEM		5
// -------------------------------------------------------------------------

struct RESET_REQ_USERDATA
{
	PSBMSG_HEAD h;
};
// -------------------------------------------------------------------------------

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
	RESET_REWARD_DATA	RewardData[MAX_CLASS];
};

struct RESET_CURRENT_DATA
{
	int MinReset;
	int MaxReset;
	int ReqLevel;
	int ItemCount;
	RESET_ITEM_DATA		ItemData[MAX_RESET_ITEM];
	RESET_REWARD_DATA RewardData;
};

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
// -------------------------------------------------------------------------

namespace ResetProtocol
{
	enum T
	{
		UserData	= 0x00,
		ResetFinish	= 0x0A,
		Case		= 0xFB,
	};
};
// -------------------------------------------------------------------------------