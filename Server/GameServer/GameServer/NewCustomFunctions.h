#include "User.h"
#include "Protocol.h"

#define BASIC_INV_HEIGHT			8
#define EXTENDED_INV_HEIGHT			4

enum
{
	Type_Player = 0,
	Type_Pet =  1,
	Type_Alchemist =  2,
	Type_Buffer = 3,
	Type_Store = 4,
	Type_Trader = 5,
	Type_Reset = 6,
	Type_PK = 7,
	Type_Warper = 10,
	Type_Racer = 11,
	Type_Reward = 12,
	Type_Hiden = 13,
};

//YolaxD Custom!
#define MAX_TYPE_PLAYER_BOTS 7
#define PSHOP_SIZE 32
#define MAIN_INVENTORY_NORMAL_SIZE	(INVENTORY_SIZE - PSHOP_SIZE)
#define BASIC_INVENTORY_SIZE		(INVENTORY_SIZE - PSHOP_SIZE - INVENTORY_WEAR_SIZE)


struct PMSG_PKLEVEL
{
	PBMSG_HEAD h;	// C1:F3:08
	BYTE subcode;	// 3
	BYTE NumberH;	// 4
	BYTE NumberL;	// 5
	BYTE PkLevel;	// 6
};

class YolaCustom
{
public:

	 YolaCustom();
	~YolaCustom();

	//Packets
	void PHeadSetB(LPBYTE lpBuf, BYTE head, int size);
	void PHeadSubSetB(LPBYTE lpBuf, BYTE head, BYTE sub, int size);
	void PHeadSetBE( LPBYTE lpBuf, BYTE head,int size);
	void PHeadSetW(LPBYTE lpBuf, BYTE head,  int size);

	//Inventory
	BYTE gObjInventoryInsertItem(int aIndex, CItem item);
	void gObjInventoryItemSet(int aIndex, int itempos, BYTE set_byte);
	void gObjTempInventoryItemBoxSet(BYTE * TempMap, int itempos, int xl, int yl, BYTE set_byte);
	unsigned char gObjInventoryInsertItemPos(int aIndex, class CItem item, int pos, int RequestCheck);
	unsigned char gObjTempInventoryInsertItem(LPOBJ lpObj, class CItem item, unsigned char* TempMap);
	unsigned char gObjTempInventoryInsertItem(LPOBJ lpObj, int itemType, BYTE * TempMap);
	BOOL ExtentCheck(int x, int y, int w, int h);
	BYTE gObjInventoryRectCheck(int aIndex, int sx, int sy, int width, int height);
	BOOL IS_EXTENDED_INV(int aIndex, BYTE INVNUM);
	void gObjInventoryItemBoxSet(int aIndex, int itempos, int xl, int yl, BYTE set_byte);
	BYTE gObjTempInventoryRectCheck(BYTE * TempMap, int sx, int sy, int width, int height);
	BYTE gObjInventoryInsertItemBot(LPOBJ lpObj, int type, int index, int level, int iSerial, int iDur, int ItemSlot1, int ItemSlot2, int ItemSlot3, int ItemSlot4, int ItemSlot5);
	void GCInventoryItemOneSend(int aIndex, int pos);
	unsigned char gObjShopBuyInventoryInsertItem(int aIndex, class CItem item);
	BYTE gObjOnlyInventoryRectCheck(int aIndex, int sx, int sy, int width, int height);
	BYTE GETHEIGHT(int aIndex);
	//Trade
	void gObjTradeCancel(int aIndex);
	void gObjCharTradeClear(LPOBJ lpObj);
	//

	//Items
	BOOL DeleteItemByLevel( int iIndex, DWORD itemId, BYTE ItemLevel);
	int  ItemGetNumberMake(int type, int index);
	int  ItemGetDurability(int index, int itemLevel, int ExcellentItem, int SetItem);
	int getNumberOfExcOptions(int checksum);
	int gObjCheckSerial0ItemList(class CItem* lpItem);
	BYTE BoxExcOptions(int maxOptions);

	//SkyEvent
	BOOL SetPosMonsterSkyEvent(int aIndex, int PosTableNum);
	int  gObjMonsterAdd(WORD Type, BYTE Map, BYTE X, BYTE Y);
	BOOL gObjIsNewClass(LPOBJ lpObj);

	//User
	int  gObjGetIndex(char* szId);

	//BotWarper
	BOOL CheckMainToMove(LPOBJ lpObj);
	BOOL CheckEquipmentToMove(LPOBJ lpObj, int iTargetMapNumber);
	BOOL CheckInterfaceToMove(LPOBJ lpObj);

	//Map
	BOOL gObjCheckTeleportAreaByMap(BYTE mapnumber, BYTE x, BYTE y);
	BOOL gObjItsInSafeZone(int PlayerID); //afk-system , botpet
	BOOL gObjMoveHackCheck(int aIndex);
	BOOL gObjGetRandomFreeArea(int iMapNumber, BYTE &cX, BYTE &cY, int iSX, int iSY, int iDX, int iDY, int iLoopCount);
	void GCPkLevelSend(int aIndex, BYTE pklevel);
	//Vars
	int g_RenaCount;	// GOLDEN ARCHER :D

};

extern YolaCustom ObjYola;