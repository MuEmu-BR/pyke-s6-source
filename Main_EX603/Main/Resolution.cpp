#include "stdafx.h"
#include "Resolution.h"
#include "Offset.h"
#include "Util.h"
#include "Import.h"

double Resolution_ClipX1 = 2000.0f;
double Resolution_ClipX2 = 2000.0f;

#define sub_8324B0_Addr		((int(__thiscall*)(LPVOID This)) 0x8324B0)
#define sub_51AF30_Addr		((int(__thiscall*)(int This)) 0x51AF30)
//int __thiscall sub_51AF30(int this, int a2)

char sub_832940(void *This)
{
	HGDIOBJ alpha; // ST18_4@1
	int v2; // eax@4
	int v3; // ST08_4@13
	int v4; // ST04_4@13
	int v5; // ST00_4@13
	void *v6; // eax@13
	int v7; // ST08_4@14
	int v8; // ST04_4@14
	int v9; // ST00_4@14
	void *v10; // eax@14
	int v11; // ST04_4@14
	int v12; // ST00_4@14
	void *v13; // eax@14
	int v14; // eax@14
	int v15; // ST04_4@14
	int v16; // ST00_4@14
	void *v17; // eax@14
	float green; // ST10_4@15
	float red; // ST0C_4@15
	float v20; // ST08_4@15
	float v21; // ST04_4@15
	int v22; // ST08_4@18
	int v23; // ST04_4@18
	int v24; // ST00_4@18
	void *v25; // eax@18
	int v26; // ST08_4@19
	int v27; // ST04_4@19
	int v28; // ST00_4@19
	void *v29; // eax@19
	int v30; // ST04_4@22
	int v31; // ST00_4@22
	void *v32; // eax@22
	int v33; // eax@22
	int v34; // eax@22
	int v35; // ST04_4@25
	int v36; // ST00_4@25
	void *v37; // eax@25
	int v38; // ST08_4@27
	int v39; // ST04_4@27
	int v40; // ST00_4@27
	void *v41; // eax@27
	void *v43; // [sp+20h] [bp-50h]@1
	char v44; // [sp+24h] [bp-4Ch]@4
	char v45; // [sp+2Ch] [bp-44h]@2
	int v46; // [sp+34h] [bp-3Ch]@1
	int v47; // [sp+38h] [bp-38h]@1
	int v48; // [sp+3Ch] [bp-34h]@1
	int v49; // [sp+40h] [bp-30h]@6
	char v50; // [sp+44h] [bp-2Ch]@1
	char v51; // [sp+4Ch] [bp-24h]@14
	int v52; // [sp+64h] [bp-Ch]@6
	int v53; // [sp+68h] [bp-8h]@6
	int v54; // [sp+6Ch] [bp-4h]@1

	v43 = This;
	pSetBlend(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	alpha = pFontNormal;
	//sub_41FE10();
	//sub_420120(alpha);
	pSetFont(pTextThis(), (int)alpha);
	//sub_41FE10();
	pSetTextColor(pTextThis(), -1, -1, -1, -1);
	//sub_8324B0(v43);
	sub_8324B0_Addr(v43);
	sub_51AF30_Addr((int)v43 + 28);
	/*v54 = *(_WORD *)(dword_8128AC8 + 14);
	v48 = *(_DWORD *)(dword_8128AC4 + 5956);
	v47 = 0;
	v46 = 0;*/


	return 0;
}

void InitResolution() // OK
{
	SetCompleteHook(0xE9,0x004D13C2,&ResolutionSwitch);

	SetCompleteHook(0xE9,0x004D2782,&ResolutionSwitchFont);

	SetCompleteHook(0xE9,0x00830C3A,&ResolutionMoveList);
	//Local calls from 00830BA6, 00832ED8
	//SetCompleteHook(0xFF, 0x00830BA6, &MoveListInit);
	//SetCompleteHook(0xFF, 0x00832ED8, &MoveListInit);
}

__declspec(naked) void ResolutionSwitch() // OK
{
	static DWORD ResolutionSwitchAddress1 = 0x004D1450;

	_asm
	{
		Mov Edx,Dword Ptr Ds:[MAIN_RESOLUTION]
		Mov Dword Ptr Ss:[Ebp-0x340],Edx
		Cmp Dword Ptr Ss:[Ebp-0x340],0x00
		Jnz NEXT1
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],640
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],480
		Jmp EXIT
		NEXT1:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x01
		Jnz NEXT2
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],800
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],600
		Jmp EXIT
		NEXT2:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x02
		Jnz NEXT3
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1024
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],768
		Jmp EXIT
		NEXT3:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x03
		Jnz NEXT4
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1152
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],864
		Jmp EXIT
		NEXT4:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x04
		Jnz NEXT5
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1280
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],768
		Jmp EXIT
		NEXT5:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x05
		Jnz NEXT6
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1280
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],800
		Jmp EXIT
		NEXT6:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x06
		Jnz NEXT7
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1280
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],960
		Jmp EXIT
		NEXT7:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x07
		Jnz NEXT8
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1280
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],1024
		Jmp EXIT
		NEXT8:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x08
		Jnz NEXT9
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1366
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],768
		Jmp EXIT
		NEXT9:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x09
		Jnz NEXT10
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1440
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],900
		Jmp EXIT
		NEXT10:
		Cmp Dword Ptr Ss:[Ebp-0x340],0xA
		Jnz NEXT11
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1600
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],900
		Jmp EXIT
		NEXT11:
		Cmp Dword Ptr Ss:[Ebp-0x340],0xB
		Jnz NEXT12
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1600
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],1200
		Jmp EXIT
		NEXT12:
		Cmp Dword Ptr Ss:[Ebp-0x340],0xC
		Jnz NEXT13
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1680
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],1050
		Jmp EXIT
		NEXT13:
		Cmp Dword Ptr Ss:[Ebp-0x340],0xD
		Jnz NEXT14
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1920
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],1080
		Jmp EXIT
		NEXT14:
		Cmp Dword Ptr Ss:[Ebp-0x340],0xE
		Jnz NEXT15
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1920
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],1200
		Jmp EXIT
		NEXT15:
		Cmp Dword Ptr Ss:[Ebp-0x340],0xF
		Jnz NEXT16
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1024
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],600
		Jmp EXIT
		NEXT16:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x10
		Jnz NEXT17
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1910
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],970
		Jmp EXIT
		NEXT17:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x11
		Jnz EXIT
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1350
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],650
		EXIT:
		Jmp [ResolutionSwitchAddress1]
	}
}

__declspec(naked) void ResolutionSwitchFont() // OK
{
	static DWORD ResolutionSwitchFontAddress1 = 0x004D27FB;

	_asm
	{
		Mov Eax,Dword Ptr Ds:[MAIN_RESOLUTION_X]
		Mov Dword Ptr Ss:[Ebp-0xF20],Eax
		Cmp Dword Ptr Ss:[Ebp-0xF20],640
		Jnz NEXT1
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0C
		Jmp EXIT
		NEXT1:
		Cmp Dword Ptr Ss:[Ebp-0xF20],800
		Jnz NEXT2
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0D
		Jmp EXIT
		NEXT2:
		Cmp Dword Ptr Ss:[Ebp-0xF20],1024
		Jnz NEXT3
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0E
		Jmp EXIT
		NEXT3:
		Cmp Dword Ptr Ss:[Ebp-0xF20],1280
		Jnz NEXT4
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0F
		Jmp EXIT
		NEXT4:
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0F
		Lea Ecx,Resolution_ClipX1
		Mov Edx,Dword Ptr Ds:[Ecx+0x00]
		Mov Eax,Dword Ptr Ds:[Ecx+0x04]
		Push Eax
		Push Edx
		Push 0x00D2C848
		Call [SetDouble]
		Add Esp,0x0C
		Lea Ecx,Resolution_ClipX2
		Mov Edx,Dword Ptr Ds:[Ecx+0x00]
		Mov Eax,Dword Ptr Ds:[Ecx+0x04]
		Push Eax
		Push Edx
		Push 0x00D2C898
		Call [SetDouble]
		Add Esp,0x0C
		EXIT:
		Jmp [ResolutionSwitchFontAddress1]
	}
}

__declspec(naked) void ResolutionMoveList() // OK
{
	static DWORD ResolutionMoveListAddress1 = 0x00830CE2;
	static DWORD ResolutionMoveListAddress2 = 0x00830C43;

	_asm
	{
		Mov Ecx,Dword Ptr Ds:[MAIN_RESOLUTION_X]
		Mov Dword Ptr Ss:[Ebp-0x08],Ecx
		Cmp Dword Ptr Ss:[Ebp-0x08],0x500
		Jbe EXIT
		Jmp [ResolutionMoveListAddress1]
		EXIT:
		Jmp [ResolutionMoveListAddress2]
	}
}

/*static void __fastcall MoveListInit(LPVOID This, LPVOID EDX, int Arg1, int Arg2)
{
	GLsizei TempWidth = pWinWidth;
	pWinWidth = 1280;
	pMoveListInit(This, Arg1, Arg2);
	pWinWidth = TempWidth;
}*/