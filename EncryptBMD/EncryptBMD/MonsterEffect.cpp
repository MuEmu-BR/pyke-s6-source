#include "stdafx.h"
#include "MonsterEffect.h"
#include "MemScript.h"

jCEffectMonster JCEffectMonster;

jCEffectMonster::jCEffectMonster()
{
	for ( int k = 0 ; k < MAX_EFFECT_MONSTER ; ++k )
	{
		this->m_MonsterEffect[k].IndexMonster = -1;
	}
}

jCEffectMonster::~jCEffectMonster()
{

}

void jCEffectMonster::Load( char* path )
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

			xMonsterEffect info;

			memset(&info,0,sizeof(info));

			static int CustomItemIndexCount = 0;

			info.IndexMonster = lpMemScript->GetNumber();

			info.TypeEffect = lpMemScript->GetAsNumber();
			
			info.IDEffect = lpMemScript->GetAsNumber();

			info.EfectValue = lpMemScript->GetAsNumber();

			info.Join[0] = lpMemScript->GetAsFloatNumber();

			info.Join[1] = lpMemScript->GetAsFloatNumber();

			info.Join[2] = lpMemScript->GetAsFloatNumber();

			info.Color[0] = lpMemScript->GetAsFloatNumber();
			
			info.Color[1] = lpMemScript->GetAsFloatNumber();
			
			info.Color[2] = lpMemScript->GetAsFloatNumber();

			info.Scale = lpMemScript->GetAsFloatNumber();
			
			if( CustomItemIndexCount < MAX_EFFECT_MONSTER )
			{
				this->m_MonsterEffect[CustomItemIndexCount] = info;
			}
			CustomItemIndexCount++;
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}