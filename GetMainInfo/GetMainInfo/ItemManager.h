// ItemManager.h: interface for the CItemManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#define MAX_ITEM_SECTION 16
#define MAX_ITEM_TYPE 512
#define MAX_ITEM 8192
#define MAX_ITEM_INFO 12

struct ITEM_INFO
{
	int Index;
	int ItemIndex;
	int Slot;
	int Skill;
	int Width;
	int Height;
	int HaveSerial;
	int HaveOption;
	int DropItem;
	char Name[32];
	int Level;
	int DamageMin;
	int DamageMax;
	int MagicDamageRate;
	int TwoHand;
	int Defense;
	int MagicDefense;
	int DefenseSuccessRate;
	int AttackSpeed;
	int WalkSpeed;
	int Durability;
	int MagicDurability;
	int Value;
	int BuyMoney;
	int Resistance[7];
	int RequireLevel;
	int RequireStrength;
	int RequireDexterity;
	int RequireEnergy;
	int RequireVitality;
	int RequireLeadership;
	int RequireClass[7];
};

class CItemManager
{
public:
	CItemManager();
	virtual ~CItemManager();
	void Init();
	void Load(char* path);
	void SetInfo(ITEM_INFO info);
public:
	ITEM_INFO m_ItemInfo[MAX_ITEM];
};

extern CItemManager gItemManager;