// CustomArcher.cpp: implementation of the CCustomArcher class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CustomArcher.h"
#include "DSProtocol.h"
#include "ItemManager.h"
#include "ItemOptionRate.h"
#include "Log.h"
#include "Map.h"
#include "Message.h"
#include "Notice.h"
#include "RandomManager.h"
#include "ServerInfo.h"
#include "Util.h"

CCustomArcher gCustomArcher;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomArcher::CCustomArcher() //OK
{
	this->m_GoldenArcherItemInfo.clear();
}

CCustomArcher::~CCustomArcher() //OK
{

}

void CCustomArcher::Load(char* path) // OK
{
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);

	if(res.status != pugi::status_ok)
	{
		ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
		return;
	}

	this->m_GoldenArcherItemInfo.clear();

	pugi::xml_node Requirement = file.child("Requirement");

	this->m_ItemIndex = SafeGetItem(GET_ITEM(Requirement.attribute("ItemCat").as_int(),Requirement.attribute("ItemIndex").as_int()));
	this->m_ItemLevel = Requirement.attribute("ItemLevel").as_int();
	this->m_ItemCount = Requirement.attribute("ItemCount").as_int();
	this->m_SendFirework = Requirement.attribute("Fireworks").as_int();

	pugi::xml_node ItemList = file.child("ItemList");

	this->m_ItemDropCount = ItemList.attribute("ItemDropCount").as_int();

	for (pugi::xml_node Item = ItemList.child("Item"); Item; Item = Item.next_sibling())
	{
		GOLDER_ARCHER_ITEM_INFO info;

		info.Index = SafeGetItem(GET_ITEM(Item.attribute("Cat").as_int(), Item.attribute("Index").as_int()));
		info.Durability = Item.attribute("Durability").as_int();
		info.Option0 = Item.attribute("LevelOption").as_int();
		info.Option1 = Item.attribute("SkillOption").as_int();
		info.Option2 = Item.attribute("LuckOption").as_int();
		info.Option3 = Item.attribute("JoLOption").as_int();
		info.Option4 = Item.attribute("ExcOption").as_int();
		info.Option5 = Item.attribute("SetOption").as_int();
		info.Option6 = Item.attribute("SocketOption").as_int();
		info.Duration = Item.attribute("Duration").as_int();
		info.Rate = Item.attribute("Rate").as_int();

		this->m_GoldenArcherItemInfo.push_back(info);
	}
}

void CCustomArcher::NpcGoldenArcher(LPOBJ lpNpc,LPOBJ lpObj) // OK
{
	if(gServerInfo.m_CustomArcherSwitch == 0)
	{
		return;
	}

	if(gServerInfo.m_CustomArcherEnable[lpObj->AccountLevel] == 0)
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0, gMessage.GetMessage(862));
		return;
	}

	if(lpObj->Interface.use != 0)
	{
		return;
	}
	
	if(gItemManager.GetInventoryItemCount(lpObj,this->m_ItemIndex,this->m_ItemLevel) < this->m_ItemCount)
	{
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0, gMessage.GetMessage(863),this->m_ItemCount,gItemManager.GetItemName(this->m_ItemIndex));
		return;
	}

	gItemManager.DeleteInventoryItemCount(lpObj,this->m_ItemIndex,this->m_ItemLevel,this->m_ItemCount);

	CRandomManager RandomManager;

	for(std::vector<GOLDER_ARCHER_ITEM_INFO>::iterator it=this->m_GoldenArcherItemInfo.begin();it != this->m_GoldenArcherItemInfo.end();it++)
	{
		RandomManager.AddElement((int)(&(*it)),it->Rate);
	}

	for(int n=0;n < this->m_ItemDropCount;n++)
	{
		int px = lpNpc->X;
		int py = lpNpc->Y;

		GOLDER_ARCHER_ITEM_INFO* lpGoldenArcherInfo = 0;

		if(RandomManager.GetRandomElement((int*)&lpGoldenArcherInfo) == 0)
		{
			return;
		}

		if(this->m_ItemDropCount > 1 || (gMap[lpNpc->Map].CheckAttr(px,py,4) != 0 || gMap[lpNpc->Map].CheckAttr(px,py,8) != 0))
		{
			if(gObjGetRandomFreeLocation(lpNpc->Map,&px,&py,2,2,10) == 0)
			{
				px = lpNpc->X;
				py = lpNpc->Y;
			}
		}

		WORD ItemIndex = lpGoldenArcherInfo->Index;
		BYTE ItemLevel = 0;
		BYTE ItemDur = lpGoldenArcherInfo->Durability;
		BYTE ItemOption1 = 0;
		BYTE ItemOption2 = 0;
		BYTE ItemOption3 = 0;
		BYTE ItemNewOption = 0;
		BYTE ItemSetOption = 0;
		BYTE ItemSocketOption[MAX_SOCKET_OPTION] = {0xFF,0xFF,0xFF,0xFF,0xFF};

		gItemOptionRate.GetItemOption0(lpGoldenArcherInfo->Option0,&ItemLevel);
		gItemOptionRate.GetItemOption1(lpGoldenArcherInfo->Option1,&ItemOption1);
		gItemOptionRate.GetItemOption2(lpGoldenArcherInfo->Option2,&ItemOption2);
		gItemOptionRate.GetItemOption3(lpGoldenArcherInfo->Option3,&ItemOption3);
		gItemOptionRate.GetItemOption4(lpGoldenArcherInfo->Option4,&ItemNewOption);
		gItemOptionRate.GetItemOption5(lpGoldenArcherInfo->Option5,&ItemSetOption);
		gItemOptionRate.GetItemOption6(lpGoldenArcherInfo->Option6,&ItemSocketOption[0]);
		gItemOptionRate.MakeNewOption(ItemIndex,ItemNewOption,&ItemNewOption);
		gItemOptionRate.MakeSetOption(ItemIndex,ItemSetOption,&ItemSetOption);
		gItemOptionRate.MakeSocketOption(ItemIndex,ItemSocketOption[0],&ItemSocketOption[0]);

		GDCreateItemSend(lpObj->Index,lpNpc->Map,px,py,ItemIndex,ItemLevel,ItemDur,ItemOption1,ItemOption2,ItemOption3,lpObj->Index,ItemNewOption,ItemSetOption,0,0,ItemSocketOption,0xFF, ((lpGoldenArcherInfo->Duration>0) ? ((DWORD)time(0) + lpGoldenArcherInfo->Duration) : 0));
	}

	if(this->m_SendFirework != 0)
	{
		GCServerCommandSend(lpObj->Index, 0, lpObj->X, lpObj->Y);
	}

	gLog.Output(LOG_GENERAL,"[CustomArcher][Success][%s][%s]",lpObj->Account,lpObj->Name);
}