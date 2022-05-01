// PKSystem.cpp: implementation of the CPKSystem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PKSystem.h"
#include "MapManager.h"
#include "ItemManager.h"
#include "Map.h"
#include "Util.h"

CPKSystem gPKSystem;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPKSystem::CPKSystem() // OK
{
	this->m_PKSystemInfo.clear();
}

CPKSystem::~CPKSystem() // OK
{

}

void CPKSystem::Load(char* path) // OK
{
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);

	if(res.status != pugi::status_ok)
	{
		ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
		return;
	}

	this->m_PKSystemInfo.clear();

	pugi::xml_node PKItemDrop = file.child("PKItemDrop");

	for (pugi::xml_node PK = PKItemDrop.child("PK"); PK; PK = PK.next_sibling())
	{
		PK_SYSTEM_INFO info;

		info.Index = PK.attribute("Level").as_int();
		info.ItemLoseRateOnMonsterKill = PK.attribute("ItemLoseRateOnMonsterKill").as_int();
		info.ItemLoseRateOnPlayerKill = PK.attribute("ItemLoseRateOnPlayerKill").as_int();
		info.ItemMinLevel = PK.attribute("ItemMinLevel").as_int();
		info.ItemMaxLevel = PK.attribute("ItemMaxLevel").as_int();
		info.DropExc = PK.attribute("DropExc").as_int();
		info.DropSet = PK.attribute("DropSet").as_int();
		info.DropSocket = PK.attribute("DropSocket").as_int();
		info.DropHarmony = PK.attribute("DropHarmony").as_int();

		this->m_PKSystemInfo.insert(std::pair<int, PK_SYSTEM_INFO>(info.Index, info));
	}

	pugi::xml_node PKSafeZone = file.child("PKSafeZone");

	for (pugi::xml_node Rule = PKSafeZone.child("Rule"); Rule; Rule = Rule.next_sibling())
	{
		PK_SYSTEM_SAFE_ZONE_INFO info;

		info.Map = Rule.attribute("MapNumber").as_int();

		info.X = Rule.attribute("StartPosX").as_int();

		info.Y = Rule.attribute("StartPosY").as_int();

		info.TX = Rule.attribute("EndPosX").as_int();

		info.TY = Rule.attribute("EndPosY").as_int();

		this->m_PKSystemSafeZoneInfo.push_back(info);
	}
}

void CPKSystem::UserDieProc(LPOBJ lpObj, LPOBJ lpTarget) // OK
{
	if(gMapManager.PKSystemEnable(lpObj->Map) == 0)
	{
		return;
	}

	std::map<int, PK_SYSTEM_INFO>::iterator it = this->m_PKSystemInfo.find(lpObj->PKLevel);

	if (it == this->m_PKSystemInfo.end())
	{
		return;
	}

	int Rate = (lpTarget->Type == OBJECT_USER) ? it->second.ItemLoseRateOnPlayerKill : it->second.ItemLoseRateOnMonsterKill;

	if (rand() % 99 > Rate)
	{
		return;
	}

	int count = (INVENTORY_WEAR_SIZE * 2);

	while (count-- != 0)
	{
		int slot = rand() % INVENTORY_WEAR_SIZE;

		CItem* lpItem = &lpObj->Inventory[slot];

		if (lpItem->IsItem() != 0 && lpItem->m_Level >= it->second.ItemMinLevel && lpItem->m_Level <= it->second.ItemMaxLevel)
		{
			if (lpItem->m_Index == GET_ITEM(13, 20) && (lpItem->m_Level >= 1 && lpItem->m_Level <= 2))
			{
				continue;
			}

			if (lpItem->IsLuckyItem() != 0)
			{
				continue;
			}

			if (it->second.DropExc == 0 && lpItem->IsExcItem() != 0)
			{
				continue;
			}

			if (it->second.DropSet == 0 && lpItem->IsSetItem() != 0)
			{
				continue;
			}

			if (it->second.DropSocket == 0 && lpItem->IsSocketItem() != 0)
			{
				continue;
			}

			if (it->second.DropHarmony == 0 && lpItem->IsJewelOfHarmonyItem() != 0)
			{
				continue;
			}

			PMSG_ITEM_DROP_SEND pMsg;

			pMsg.header.set(0x23, sizeof(pMsg));
			pMsg.result = 0;
			pMsg.slot = slot;

			if (gMap[lpObj->Map].ItemDrop(lpItem->m_Index, lpItem->m_Level, lpItem->m_Durability, lpObj->X, lpObj->Y, lpItem->m_Option1, lpItem->m_Option2, lpItem->m_Option3, lpItem->m_NewOption, lpItem->m_SetOption, lpItem->m_Serial, lpObj->Index, lpItem->m_PetItemLevel, lpItem->m_PetItemExp, lpItem->m_JewelOfHarmonyOption, lpItem->m_ItemOptionEx, lpItem->m_SocketOption, lpItem->m_SocketOptionBonus, lpItem->m_PeriodicItemTime) != 0)
			{
				pMsg.result = 1;
				gItemManager.InventoryDelItem(lpObj->Index, slot);
				gItemManager.UpdateInventoryViewport(lpObj->Index, slot);
			}

			DataSend(lpObj->Index, (BYTE*)&pMsg, pMsg.header.size);

			LogAdd(LOG_BLACK, "[PK System] Item Drop (%s) (%s) dropped %s", lpObj->Account, lpObj->Name, gItemManager.GetItemName(lpItem->m_Index));

			return;
		}
	}
}

bool CPKSystem::CheckSafeZone(LPOBJ lpObj) // OK
{
	for (std::vector<PK_SYSTEM_SAFE_ZONE_INFO>::iterator it = this->m_PKSystemSafeZoneInfo.begin(); it != this->m_PKSystemSafeZoneInfo.end(); it++)
	{
		if (it->Map != lpObj->Map)
		{
			continue;
		}

		if ((lpObj->X < it->X || lpObj->X > it->TX) || (lpObj->Y < it->Y || lpObj->Y > it->TY))
		{
			continue;
		}

		return 1;
	}

	return 0;
}