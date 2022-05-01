#include "stdafx.h"
#include "CustomEffectRemake.h"
#include "MemScript.h"
#include "InfoLog.h"

cCustomRemake gCustomRemake;

cCustomRemake::cCustomRemake() // OK
{
	this->Init();
}

cCustomRemake::~cCustomRemake() // OK
{

}

void cCustomRemake::Init() // OK
{
	for(int n=0;n < MAX_REMAKE_EFFECT;n++)
	{
		this->m_CustomRemake[n].Index = -1;
	}
}

void cCustomRemake::Load(char* path) // OK
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

			REMAKE_EFFECT info;

			memset(&info,0,sizeof(info));

			static int CustomItemIndexCount = 0;

			info.Index = CustomItemIndexCount++;

			info.ItemType = lpMemScript->GetNumber();

			info.ItemIndex = lpMemScript->GetAsNumber();

			info.RemakeEffect = lpMemScript->GetAsNumber();

			this->SetInfo(info);
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void cCustomRemake::SetInfo(REMAKE_EFFECT info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_REMAKE_EFFECT)
	{
		return;
	}

	this->m_CustomRemake[info.Index] = info;
}