#include "stdafx.h"
#include "Monster.h"
#include "MemScript.h"

Monster gMonster;

Monster::Monster()
{
	this->Init();
}

Monster::~Monster()
{
	
}

void Monster::Init()
{
	for (int n = 0; n < MAX_CUSTOM_HPBAR; n++)
	{
		this->m_CustomHpBar[n].Index = -1;
	}
}

void Monster::Load(char* path)
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

			if(strcmp("end",lpMemScript->GetString()) == 0)
			{
				break;
			}

			CUSTOM_HPBAR info;

			memset(&info,0,sizeof(info));

			static int CustomItemIndexCount = 0;

			info.Index = CustomItemIndexCount++;

			info.MonsterID = lpMemScript->GetAsNumber();

			strcpy_s(info.Name,lpMemScript->GetAsString());

			info.Red = lpMemScript->GetAsNumber();

			info.Green = lpMemScript->GetAsNumber();

			info.Blue = lpMemScript->GetAsNumber();

			info.Opacity = lpMemScript->GetAsFloatNumber();

			this->SetInfo(info);
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void Monster::SetInfo(CUSTOM_HPBAR info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_HPBAR)
	{
		return;
	}
	this->m_CustomHpBar[info.Index] = info;
}
