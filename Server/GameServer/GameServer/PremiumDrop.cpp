#include "stdafx.h"
#include "PremiumDrop.h"
#include "Util.h"
#include "JSProtocol.h"
#include "Notice.h"

CPremiumDrop gPremiumDrop;

CPremiumDrop::CPremiumDrop()
{
	this->m_PremiumDropInfo.clear();
	this->m_PremiumDropEnable = false;
}

CPremiumDrop::~CPremiumDrop()
{
	
}

void CPremiumDrop::Load(char* path)
{
	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);

	if (res.status != pugi::status_ok)
	{
		ErrorMessageBox("Failed to load %s file (%s)", path, res.description());
		return;
	}

	this->m_PremiumDropInfo.clear();

	pugi::xml_node main = file.child("PremiumDrop");

	this->m_PremiumDropEnable = main.attribute("Enable").as_bool();

	for (pugi::xml_node group = main.child("Group"); group; group = group.next_sibling())
	{
		PREMIUM_DROP_INFO info;

		info.MapNumber = group.attribute("MapNumber").as_int();

		info.MonsterClass = group.attribute("MonsterClass").as_int();

		info.MonsterLevelMin = group.attribute("MonsterLevelMin").as_int();

		info.MonsterLevelMax = group.attribute("MonsterLevelMax").as_int();

		info.PremiumLevel = group.attribute("PremiumLevel").as_int();

		info.TimeValue = group.attribute("TimeValue").as_int();

		info.TimeForBiggerAL = group.attribute("TimeForBiggerAL").as_int();

		info.DropRate = group.attribute("DropRate").as_int();

		this->m_PremiumDropInfo.push_back(info);
	}
}

bool CPremiumDrop::DropPremium(LPOBJ lpObj, LPOBJ lpTarget)
{
	if (this->m_PremiumDropEnable == 0)
	{
		return 0;
	}

	for(std::vector<PREMIUM_DROP_INFO>::iterator it=this->m_PremiumDropInfo.begin();it != this->m_PremiumDropInfo.end();it++)
	{
		int DropRate;

		if(it->MapNumber != -1 && it->MapNumber != lpObj->Map)
		{
			continue;
		}

		if(it->MonsterClass != -1 && it->MonsterClass != lpObj->Class)
		{
			continue;
		}

		if(it->MonsterLevelMin != -1 && it->MonsterLevelMin > lpObj->Level)
		{
			continue;
		}

		if(it->MonsterLevelMax != -1 && it->MonsterLevelMax < lpObj->Level)
		{
			continue;
		}

		if ((GetLargeRand()%1000000) <= it->DropRate)
		{
			char szStatus[50];
			switch (it->PremiumLevel)
			{
				case 1: sprintf_s(szStatus, "Silver"); break;
				case 2: sprintf_s(szStatus, "Gold"); break;
				case 3: sprintf_s(szStatus, "Platinum"); break;
				default: sprintf_s(szStatus, "None"); break;
			}

			if (lpTarget->AccountLevel > it->PremiumLevel)
			{
				GJAccountLevelSaveSend(lpTarget->Index,lpTarget->AccountLevel,it->TimeForBiggerAL);
				GJAccountLevelSend(lpTarget->Index);
				gNotice.GCNoticeSend(lpTarget->Index, 1, 0, 0, 0, 0, 0, "You won the premium extension for %d minutes!", it->TimeForBiggerAL/24);
			}
			else
			{
				GJAccountLevelSaveSend(lpTarget->Index,it->PremiumLevel,it->TimeValue);
				GJAccountLevelSend(lpTarget->Index);
				gNotice.GCNoticeSend(lpTarget->Index, 1, 0, 0, 0, 0, 0, "You won %s VIP type for %d minutes!", szStatus, it->TimeValue/24);
			}

			return 1;
		}
	}

	return 0;
}
