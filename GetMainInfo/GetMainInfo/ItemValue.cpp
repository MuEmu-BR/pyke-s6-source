#include "stdafx.h"
#include "ItemValue.h"
#include "MemScript.h"

CItemValue gItemValue;

CItemValue::CItemValue()
{
	this->Init();
}

CItemValue::~CItemValue()
{
	
}

void CItemValue::Init()
{
	for (int n = 0; n < MAX_ITEM_VALUE; n++)
	{
		this->m_ItemValueInfo[n].Index = -1;
	}
}

void CItemValue::Load(char * path)
{
	CMemScript* lpMemScript = new CMemScript;

	int Index = 0;

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

			if(strcmp("end",lpMemScript->GetString()) == 0)
			{
				break;
			}

			
			ITEM_VALUE_INFO info;

			info.Index = Index++;

			info.ItemIndex = lpMemScript->GetNumber();

			info.Level = lpMemScript->GetAsNumber();

			info.OpcExc = lpMemScript->GetAsNumber();

			info.Zen = lpMemScript->GetAsNumber();

			info.Coin1 = lpMemScript->GetAsNumber();

			info.Coin2 = lpMemScript->GetAsNumber();

			info.Coin3 = lpMemScript->GetAsNumber();

			info.Sell  = lpMemScript->GetAsNumber();

			this->SetInfo(info);
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void CItemValue::SetInfo(ITEM_VALUE_INFO info)
{
	if(info.Index < 0 || info.Index >= MAX_ITEM_VALUE)
	{
		return;
	}

	this->m_ItemValueInfo[info.Index] = info;
}