#include "stdafx.h"
#include "ItemManager.h"
#include "MemScript.h"

CItemManager gItemManager;

CItemManager::CItemManager() // OK
{
	this->Init();
}

CItemManager::~CItemManager() // OK
{

}


void CItemManager::Init() // OK
{
	for(int n=0;n < MAX_ITEM;n++)
	{
		this->m_ItemInfo[n].Index = -1;
	}
}

void CItemManager::Load(char* path)
{
	CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == 0)
	{
		printf(MEM_SCRIPT_ALLOC_ERROR,path);
		return;
	}

	if(lpMemScript->SetBuffer(path) == 0)
	{
		printf(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->Init();

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}
		
			int section = lpMemScript->GetNumber();

			while(true)
			{
				if(strcmp("end",lpMemScript->GetAsString()) == 0)
				{
					break;
				}

				ITEM_INFO info;

				memset(&info,0,sizeof(info));

				static int CustomItemIndexCount = 0;

				info.Index = CustomItemIndexCount++;

				info.ItemIndex = GET_ITEM(section,lpMemScript->GetNumber());

				info.Slot = lpMemScript->GetAsNumber();

				info.Skill = lpMemScript->GetAsNumber();

				info.Width = lpMemScript->GetAsNumber();

				info.Height = lpMemScript->GetAsNumber();

				info.HaveSerial = lpMemScript->GetAsNumber();

				info.HaveOption = lpMemScript->GetAsNumber();

				info.DropItem = lpMemScript->GetAsNumber();

				strcpy_s(info.Name,lpMemScript->GetAsString());

				if(section >= 0 && section <= 5)
				{
					info.Level = lpMemScript->GetAsNumber();

					info.DamageMin = lpMemScript->GetAsNumber();

					info.DamageMax = lpMemScript->GetAsNumber();

					info.AttackSpeed = lpMemScript->GetAsNumber();

					info.Durability = lpMemScript->GetAsNumber();

					info.MagicDurability = lpMemScript->GetAsNumber();

					info.MagicDamageRate = lpMemScript->GetAsNumber();

					info.RequireLevel = lpMemScript->GetAsNumber();

					info.RequireStrength = lpMemScript->GetAsNumber();

					info.RequireDexterity = lpMemScript->GetAsNumber();

					info.RequireEnergy = lpMemScript->GetAsNumber();

					info.RequireVitality = lpMemScript->GetAsNumber();

					info.RequireLeadership = lpMemScript->GetAsNumber();

					info.TwoHand = ((info.Width>=2)?1:0);

					info.Durability += info.MagicDurability;
				}
				else if(section >= 6 && section <= 11)
				{
						info.Level = lpMemScript->GetAsNumber();

					if(section == 6)
					{
						info.Defense = lpMemScript->GetAsNumber();

						info.DefenseSuccessRate = lpMemScript->GetAsNumber();
					}
					else if(section >= 7 && section <= 9)
					{
						info.Defense = lpMemScript->GetAsNumber();

						info.MagicDefense = lpMemScript->GetAsNumber();
					}
					else if(section == 10)
					{
						info.Defense = lpMemScript->GetAsNumber();

						info.AttackSpeed = lpMemScript->GetAsNumber();
					}
					else if(section == 11)
					{
						info.Defense = lpMemScript->GetAsNumber();

						info.WalkSpeed = lpMemScript->GetAsNumber();
					}

					info.Durability = lpMemScript->GetAsNumber();

					info.RequireLevel = lpMemScript->GetAsNumber();

					info.RequireStrength = lpMemScript->GetAsNumber();

					info.RequireDexterity = lpMemScript->GetAsNumber();

					info.RequireEnergy = lpMemScript->GetAsNumber();

					info.RequireVitality = lpMemScript->GetAsNumber();

					info.RequireLeadership = lpMemScript->GetAsNumber();
				}
				else if(section == 12)
				{
					info.RequireLevel = lpMemScript->GetAsNumber();

					info.Defense = lpMemScript->GetAsNumber();

					info.Durability = lpMemScript->GetAsNumber();

					info.DamageMin = lpMemScript->GetAsNumber();

					info.DamageMax = lpMemScript->GetAsNumber();

					info.RequireStrength = lpMemScript->GetAsNumber();

					info.RequireDexterity = lpMemScript->GetAsNumber();

					info.RequireLeadership = lpMemScript->GetAsNumber();

					info.BuyMoney = lpMemScript->GetAsNumber();
				}
				else if(section == 13)
				{
					info.Level = lpMemScript->GetAsNumber();

					info.Durability = lpMemScript->GetAsNumber();

					for(int n=0;n < 7;n++){info.Resistance[n] = lpMemScript->GetAsNumber();}

					info.RequireLevel = info.Level;
				}
				else if(section == 14)
				{
					info.Value = lpMemScript->GetAsNumber();

					info.Level = lpMemScript->GetAsNumber();

					info.Durability = 1;
				}
				else if(section == 15)
				{
					info.Level = lpMemScript->GetAsNumber();

					info.RequireLevel = lpMemScript->GetAsNumber();

					info.RequireEnergy = lpMemScript->GetAsNumber();

					info.BuyMoney = lpMemScript->GetAsNumber();

					info.DamageMin = info.Level;

					info.DamageMax = info.Level+(info.Level/2);
				}

				if(section <= 11 || section == 13)
				{
					lpMemScript->GetToken();
				}

				if(section != 14)
				{
					for(int n=0;n < 7;n++)
					{
						info.RequireClass[n] = lpMemScript->GetAsNumber();
					}
				}

				

				this->SetInfo(info);
			}
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}


void CItemManager::SetInfo(ITEM_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_ITEM)
	{
		return;
	}
	this->m_ItemInfo[info.Index] = info;
}
