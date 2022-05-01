#include "stdafx.h"
#include "JCMeshItemGlow.h"
#include "MemScript.h"

JCRenderMesh JCRender;

JCRenderMesh::JCRenderMesh()
{
	for ( int k = 0 ; k < MAX_JCRENDER_MESH ; ++k )
	{
		this->m_JCRenderMesh[k].ItemIndex = -1;
	}
}

JCRenderMesh::~JCRenderMesh()
{
}

void JCRenderMesh::Load( char* Path )
{
	CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == 0)
	{
		printf(MEM_SCRIPT_ALLOC_ERROR, Path);
		return;
	}

	if(lpMemScript->SetBuffer( Path ) == 0)
	{
		printf(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	static int CustomItemIndexCount = 0;

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

			ITEM_RENDER_MESH info;

			memset(&info, 0, sizeof( info ));

			info.ItemIndex = lpMemScript->GetNumber();
			
			info.ColorR = lpMemScript->GetAsFloatNumber();

			info.ColorG = lpMemScript->GetAsFloatNumber();

			info.ColorB = lpMemScript->GetAsFloatNumber();

			if( CustomItemIndexCount < MAX_JCRENDER_MESH )
			{
				this->m_JCRenderMesh[CustomItemIndexCount] = info;
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