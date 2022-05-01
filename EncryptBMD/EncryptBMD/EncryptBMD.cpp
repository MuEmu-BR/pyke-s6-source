#include "stdafx.h"
#include "..\..\Util\CCRC32.H"
#include "ThemidaSDK.h"
#include "CustomEffectDynamic.h"
#include "CustomWIngEffect.h"
#include "CustomPetEffect.h"
#include "tooltipbuff.h"
#include "cCPetRenderMesh.h"
#include "MultiSelect.h"
#include "CustomMonsterGlow.h"
#include "MonsterEffect.h"
#include "JCRendernoItemGlow.h"
#include "ItemTooltip.h"

struct PETEFFECT_BMD
{
	PET_EFFECT_CUSTOM m_PetCEffectBMD[max_ceffect];
	CUSTOM_WING_EFFECT_INFO CustomWingEffectInfo[MAX_CUSTOM_WING_EFFECT];
	DYNAMIC_WING_EFFECT_INFO DynamicWingEffectInfo[MAX_DYNAMIC_WING_EFFECT];
	RENDER_MESH RenderMeshPet[MAX_RENDER_MESH];
	CUSTOM_MONSTERGLOW_INFO m_CustomMonsterGlow[MAX_CUSTOM_MONSTERGLOW];
	CUSTOM_GLOW_INFO m_CustomMonsterbrightness[MAX_CUSTOM_MONSTERGLOW];
	xMonsterEffect m_CustomMonsterEffect[ MAX_EFFECT_MONSTER ];
	//--
	JCItemnoGlow m_JCWRemoveGlow[ MAX_NOGLOW ];
};

struct TOOLTIP_BMD
{
	RenderTooltipBuff m_TooltipTRSDataEng[256];
	RenderTooltipBuff m_TooltipTRSDataSpn[256];
	RenderTooltipBuff m_TooltipTRSDataPor[256];

	nInformation m_TRSTooltipData[MaxLine];
	nText m_TRSTooltipText[MaxLine];
};

struct RENDER_MAKE_VIEW
{
	#if UPDATE >= 15
	SelectChar m_RenderSelect[MAX_WORLD_SETTINGS];
	DWORD TooltipS15;
	#endif
};

int encryptEffect()
{
	CLEAR_START

	ENCODE_START
	
	int EncryptEffect;

	EncryptEffect = GetPrivateProfileIntA("Encrypt", "EncryptEffect", 0, ".\\Settings.ini");

	if(EncryptEffect == 0)
	{
		return 0;
	}
	
	PETEFFECT_BMD info;

	memset(&info,0,sizeof(info));

	gCustomCEffectPet.Load("Data/CustomPetEffect.txt");

	gCustomWingEffect.Load("Data/CustomEffectStatic.txt");

	gDynamicWingEffect.Load("Data/CustomEffectDynamic.txt");

	cRender.Load("Data/CustomPetGlow.txt");

	gCustomMonsterGlow.Load("Data/CustomMonsterGlow.txt");

	JCEffectMonster.Load("Data/CustomMonsterEffect.txt");

	JCRemoveGlow.Load("Data/RenderItemGlow.txt");

	memcpy(info.m_PetCEffectBMD, gCustomCEffectPet.m_PetCEffect, sizeof(info.m_PetCEffectBMD));

	memcpy(info.CustomWingEffectInfo, gCustomWingEffect.m_CustomWingEffectInfo,sizeof(info.CustomWingEffectInfo));

	memcpy(info.DynamicWingEffectInfo,gDynamicWingEffect.m_DynamicWingEffectInfo,sizeof(info.DynamicWingEffectInfo));

	memcpy(info.RenderMeshPet, cRender.m_RenderMeshPet, sizeof(info.RenderMeshPet));
	
	memcpy(info.m_CustomMonsterGlow, gCustomMonsterGlow.m_CustomGlowInfo, sizeof(info.m_CustomMonsterGlow));

	memcpy(info.m_CustomMonsterbrightness, gCustomMonsterGlow.m_CustombrightnessInfo, sizeof(info.m_CustomMonsterbrightness));

	memcpy(info.m_CustomMonsterEffect, JCEffectMonster.m_MonsterEffect, sizeof(info.m_CustomMonsterEffect));

	memcpy(info.m_JCWRemoveGlow, JCRemoveGlow.m_JCRemoveGlow, sizeof(info.m_JCWRemoveGlow));

	for(int n=0;n < sizeof(PETEFFECT_BMD);n++)
	{
		((BYTE*)&info)[n] ^= (BYTE)(0xFA^LOBYTE(n));
		((BYTE*)&info)[n] -= (BYTE)(0x85^HIBYTE(n));
	}

	HANDLE file = CreateFile("Client/Data/Local/EffectTRSData.bmd", GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0 );

	if(file == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	DWORD OutSize = 0;

	if( WriteFile(file, &info, sizeof(PETEFFECT_BMD), &OutSize, 0) == 0 )
	{
		CloseHandle( file );

		return 0;
	}

	CloseHandle( file );

	ENCODE_END

	CLEAR_END
}

int encryptTooltip()
{
	CLEAR_START

	ENCODE_START

	int EncryptTooltip;

	EncryptTooltip = GetPrivateProfileIntA("Encrypt", "EncryptTooltip", 0, ".\\Settings.ini");

	if(EncryptTooltip == 0)
	{
		return 0;
	}

	TOOLTIP_BMD info;

	memset(&info,0,sizeof(info));

	gCBuffIcon.Load("Data/BuffEffect_eng.txt", 0);

	gCBuffIcon.Load("Data/BuffEffect_spn.txt", 1);
	
	gCBuffIcon.Load("Data/BuffEffect_por.txt", 2);

	GInfo.Load("Data/ItemToolTip.txt", 1);

	GInfo.Load("Data/TextTooltip.txt", 2);

	memcpy(info.m_TooltipTRSDataEng, gCBuffIcon.m_TooltipENG, sizeof(info.m_TooltipTRSDataEng));
	memcpy(info.m_TooltipTRSDataSpn, gCBuffIcon.m_TooltipSPN, sizeof(info.m_TooltipTRSDataSpn));
	memcpy(info.m_TooltipTRSDataPor, gCBuffIcon.m_TooltipPOR, sizeof(info.m_TooltipTRSDataPor));
	memcpy(info.m_TRSTooltipData, GInfo.n_TRSTooltipData, sizeof(info.m_TRSTooltipData));
	memcpy(info.m_TRSTooltipText, GInfo.n_TRSTooltipText, sizeof(info.m_TRSTooltipText));

	for(int n = 0;n < sizeof(TOOLTIP_BMD);n++)
	{
		((BYTE*)&info)[n] ^= (BYTE)(0xFA^LOBYTE(n));
		((BYTE*)&info)[n] -= (BYTE)(0x85^HIBYTE(n));
	}

	HANDLE file = CreateFile("Client/Data/Local/TooltipTRSData.bmd", GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0 );

	if(file == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	DWORD OutSize = 0;

	if( WriteFile(file, &info, sizeof(TOOLTIP_BMD), &OutSize, 0) == 0 )
	{
		CloseHandle( file );

		return 0;
	}

	CloseHandle( file );

	ENCODE_END

	CLEAR_END
}

int encryptSelectChar()
{
	CLEAR_START

	ENCODE_START

	int EncryptMakeWorld;

	EncryptMakeWorld = GetPrivateProfileIntA("Encrypt", "EncryptMakeWorld", 0, ".\\Settings.ini");

	if(EncryptMakeWorld == 0)
	{
		return 0;
	}

	RENDER_MAKE_VIEW info;

	memset(&info,0,sizeof(info));

	info.TooltipS15 = GetPrivateProfileIntA("Season15", "RenderTooltipS15", 0, ".\\Settings.ini");

	gSelectCharRamdon.Load("Data/MakeSelectChar.txt");

	memcpy(info.m_RenderSelect, gSelectCharRamdon.RenderSelect, sizeof(info.m_RenderSelect));

	for(int n = 0;n < sizeof(RENDER_MAKE_VIEW); n++)
	{
		((BYTE*)&info)[n] ^= (BYTE) (0xFA^LOBYTE( n ));
		((BYTE*)&info)[n] -= (BYTE) (0x85^HIBYTE( n ));
	}

	HANDLE file = CreateFile("Client/Data/Local/MakeWorldTRSData.bmd", GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0 );

	if(file == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	DWORD OutSize = 0;

	if( WriteFile(file, &info, sizeof(RENDER_MAKE_VIEW), &OutSize, 0) == 0 )
	{
		CloseHandle( file );

		return 0;
	}

	CloseHandle( file );

	ENCODE_END

	CLEAR_END
}

int _tmain(int argc, _TCHAR* argv[]) // OK
{
	CreateDirectory("Client/Data/Local", 0);

	//gInfoLog.Load();

	encryptEffect();

	encryptTooltip();

	encryptSelectChar();

	return 0;
}
