#include "stdafx.h"
#include "MultiSelect.h"
#include "MemScript.h"

MultiSelect gSelectCharRamdon;

void MultiSelect::Load(char* path) // OK
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
	
	SelectChar info;

	memset(&info, 0, sizeof(info));

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			int Secction = lpMemScript->GetNumber();

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

				if(Secction == 0)
				{
					static int CustomItemIndexCount = 0;

					info.Index = CustomItemIndexCount++;

					info.MapChar = lpMemScript->GetNumber();

					info.ModelScale = lpMemScript->GetAsFloatNumber();
			
					info.flt_87933D0 = lpMemScript->GetAsFloatNumber();
			
					info.flt_87933D4 = lpMemScript->GetAsFloatNumber();

					info.flt_87933D8 = lpMemScript->GetAsFloatNumber();

					info.flt_87933DC = lpMemScript->GetAsFloatNumber();

					info.flt_87933E0 = lpMemScript->GetAsFloatNumber();

					info.flt_87933E4 = lpMemScript->GetAsFloatNumber();
				}

				if(Secction == 1)
				{
					static int CustomIndexCount = 0;

					if(CustomIndexCount >= MAX_WORLD_SELECT_CHAR)
					{
						break;
					}

					info.PJ[CustomIndexCount].Index = lpMemScript->GetNumber();

					info.PJ[CustomIndexCount].Coordenada1.CoordX =  lpMemScript->GetAsFloatNumber();

					info.PJ[CustomIndexCount].Coordenada1.CoordY =  lpMemScript->GetAsFloatNumber();

					info.PJ[CustomIndexCount++].Coordenada1.Rotate =  lpMemScript->GetAsFloatNumber();
				}

				if(Secction == 2)
				{
					static int IndexCount = 0;

					if(IndexCount >= MAX_WORLD_SELECT_CHAR)
					{
						break;
					}
					info.PJ[IndexCount].Index = lpMemScript->GetNumber();

					info.PJ[IndexCount].Coordenada2.CoordX =  lpMemScript->GetAsFloatNumber();

					info.PJ[IndexCount].Coordenada2.CoordY =  lpMemScript->GetAsFloatNumber();

					info.PJ[IndexCount++].Coordenada2.Rotate =  lpMemScript->GetAsFloatNumber();

				}
			}
		}
		this->SetInfo(info);
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void MultiSelect::SetInfo(SelectChar info)
{
	if(info.Index < 0 || info.Index >= MAX_WORLD_SETTINGS)
	{
		return;
	}

	this->RenderSelect[info.Index] = info;
}