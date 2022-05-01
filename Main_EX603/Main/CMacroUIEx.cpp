#include "stdafx.h"
#include "CMacroUIEx.h"
#include "Util.h"
#include "Offset.h"
#include "Import.h"
#include "User.h"
#include "Interface.h"
#include "Defines.h"
#include "MuHelper.h"
#include "Protocol.h"
#include "Common.h"
#include "MiniMap.h"
#include "InfoLog.h"
#include "Camera.h"
// ---------------------------------------------------------------------------------------------
CMacroUIEx gCMacroUIEx;
// ---------------------------------------------------------------------------------------------

void CMacroUIEx::RenderFrame(int *This)
{
	float CY;
	char Cord[256];
	float X = (double)*((DWORD *)This + 5);
	float Y = (double)*((signed int *)This + 6);

	float renderMenu = 15.0f;

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	renderMenu = 10.0f;
	RenderBitmap(51550, X + 85.0 + renderMenu, Y, 124.0, 24.0, 0.0, 0.285, 0.725, 0.28, 1, 1, 0.0);
	RenderBitmap(51550, X, Y, 124.0, 24.0, 0.0, 0.0, 0.725, 0.28, 1, 1, 0.0);

	pSetFont(pTextThis(), (int)pFontNormal);
	//Mapa y Coordenadas
	if (World >= 82 && World <= 100)
	{
		wsprintf(Cord, "%s  %d,%d", pGetTextLine(pTextLineThis, (3810 + World - 82)), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	}
	else
	{
		wsprintf(Cord, "%s  %d,%d", pGetMapName(World), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	}
	
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 240, 240, 240, 255);
	pDrawText(pTextThis(), X - 35, Y + 4, Cord, 190, 0, (LPINT)3, 0);
	//Extra
	DWORD Color = Color4f(255, 189, 25, 255);
	gInterface.DrawFormat(Color, X + 154 + renderMenu, Y + 2, 27.5, 3, "0");
	
//Botones
	renderMenu = 15.0f;
	gInterface.DrawButtonRender(ButtonSettings, 119 + renderMenu, 7.0, 0, 0);
	//-- Config
	if (gInterface.IsWorkZone(ButtonSettings))
	{
		gInterface.DrawToolTip(X + 119 + renderMenu, Y + 50, "Config Helper");

		if (gInterface.Data[ButtonSettings].OnClick)
		{
			RenderBitmap(51546, X + 119 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);
			//gInterface.DrawButtonRender(ButtonSettings, 119.5f, 7.0, 0, 40.0f);
		}
		else
		{
			RenderBitmap(51546, X + 119 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.2255f, 0.878, 0.225, 1, 1, 0.0);
		}
		//gInterface.DrawButtonRender(ButtonSettings, 119.5f, 7.0, 0, 20.0f);
	}
	else
	{
		RenderBitmap(51546, X + 119 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.0, 0.878, 0.225, 1, 1, 0.0);
	}
	if (!*(BYTE*)(*(DWORD*)(MUHELPER_STRUC)+0x08))
	{
		gInterface.DrawButtonRender(ButtonStart, 138 + renderMenu, 7.0 , 0, 0.0f);
		//-- Play
		if (gInterface.IsWorkZone(ButtonStart))
		{
			gInterface.DrawToolTip(X + 138 + renderMenu, Y + 50,"Play Helper");

			if (gInterface.Data[ButtonStart].OnClick)
			{
				RenderBitmap(51547, X + 138 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);
			}
			else
			{
				RenderBitmap(51547, X + 138 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.2255f, 0.878, 0.225, 1, 1, 0.0);
			}
		}
		else
		{
			RenderBitmap(51547, X + 138 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.0, 0.878, 0.225, 1, 1, 0.0);
		}
	}
	else
	{
		gInterface.DrawButtonRender(ButtonStop, 138 + renderMenu, 7.0 , 0, 0.0f);

		if(offhelper == 1)
		{
			gMuHelper.RunningOffHelper();
		}
		//-- Pause
		if (gInterface.IsWorkZone(ButtonStop))
		{
			gInterface.DrawToolTip(X + 138 + renderMenu, Y + 50,"Pause Helper");

			if (gInterface.Data[ButtonStop].OnClick)
			{
				RenderBitmap(51548, X + 138 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);
				
				//gMuHelper.ClearOffHelper();
			}
			else
			{
				RenderBitmap(51548, X + 138 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.2255f, 0.878, 0.225, 1, 1, 0.0);
			}
			//gInterface.DrawButtonRender(ButtonStart, 138.5, 7.0 , 0, 20.0f);
		}
		else
		{
			RenderBitmap(51548, X + 138 + renderMenu, Y + 7.0, 19, 19, 0.0, 0.0, 0.878, 0.225, 1, 1, 0.0);
		}
	}
	gInterface.DrawButtonRender(eMenu, X + 100.0f + renderMenu, Y + 7.0 , 0, 0.0f);

	if (gInterface.IsWorkZone(eMenu))
	{
		gInterface.DrawToolTip(X + 100.0f + renderMenu, 50, "Especial Menu");
		// ----
		if (gInterface.Data[eMenu].OnClick)
		{
			RenderBitmap(51553, X + 100.0f + renderMenu, Y + 7.0, 19, 19, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);
		}
		else
		{
			RenderBitmap(51553, X + 100.0f + renderMenu, Y + 7.0, 19, 19, 0.0, 0.2255f, 0.878, 0.225, 1, 1, 0.0);
		}
	}
	else
	{
		RenderBitmap(51553, X + 100.0f + renderMenu, Y + 7.0, 19, 19, 0.0, 0.0, 0.878, 0.225, 1, 1, 0.0);
	}
	pGLSwitch();
	EnableAlphaTest(0);
}


void CMacroUIEx::Button(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();

	if( gInterface.IsWorkZone(ButtonSettings) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[ButtonSettings].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[ButtonSettings].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[ButtonSettings].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[ButtonSettings].EventTick = GetTickCount();
		// ----
	}
	else if( gInterface.IsWorkZone(ButtonStart) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[ButtonStart].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[ButtonStart].OnClick = true;

			return;
		}
		// ----
		gInterface.Data[ButtonStart].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[ButtonStart].EventTick = GetTickCount();
		// ----
		}
	else if( gInterface.IsWorkZone(ButtonStop) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[ButtonStop].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[ButtonStop].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[ButtonStop].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[ButtonStop].EventTick = GetTickCount();
		// ----
	}
}

char BarTime(int This)
{
	float v1; // ST10_4@2
	float v2; // ST0C_4@2
	float v3; // ST30_4@3
	float v4; // ST08_4@3
	float v5; // ST04_4@3
	int v13; // [sp+30h] [bp-4h]@1

	 v13 = This;

	if ( *(BYTE *)(v13 + 72) == 1 )
	{
		v1 = (double)*(signed int *)(This + 20);
		v2 = (double)*(signed int *)(This + 16);
		RenderImage2(51522, v5, v4);
		if ( *(DWORD *)(v13 + 88) == 1 )
		{
			v3 = *(float *)(v13 + 92) * 50.0;
			v4 = (double)(*(DWORD *)(v13 + 20) + 2);
			v5 = (double)(*(DWORD *)(v13 + 16) + 2);
			RenderImage(51549, v5 + 108.0, v4 - 16.0, v3, 3.0);
		}
		else if ( *(DWORD *)(v13 + 88) > 1 )
		{
			RenderImage2(51522, v5, v4);
			v3 = *(float *)(v13 + 92) * 50.0;
			v4 = (double)(*(DWORD *)(v13 + 20) + 2);
			v5 = (double)(*(DWORD *)(v13 + 16) + 2);
			RenderImage(51549, v5 + 108.0, v4 - 16.0, v3, 3.0);
		}
		/*if ( *(BYTE *)(v13 + 128) == 1 )
		{
			v14 = (const CHAR *)sub_402880((void *)(v16 + 100));
			sub_597220(*(_DWORD *)(v16 + 132), *(_DWORD *)(v16 + 136), v14);
		}*/
	}
  return 1;
}

//-- (007D25C0)
__declspec(naked) void MuHelperRemake_01()  //<- ConfigHelper
{
	static DWORD Remake_Buffer = 0x007D26DA;
	static DWORD W = 19;
	static DWORD H = 19;
	static DWORD X = 119 + 15.0f;
	static DWORD Y = 7;
 
	_asm
	{
		PUSH H                                  ; |Arg6 = 0000000D
		PUSH W                                  ; |Arg5 = 00000012
		MOV EDX,DWORD PTR SS:[EBP-0xB8]         ; |
		MOV EAX,DWORD PTR DS:[EDX+0x18]            ; |
		PUSH Y                                 ; |Arg4
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0x14]            ; |
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0xC]             ; |
		LEA EDX,DWORD PTR DS:[EDX+ECX+0x29]        ; |
		PUSH X                                 ; |Arg3
		JMP [Remake_Buffer]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake_02()  //<- PlayHelper
{
	static DWORD Remake_Buffer = 0x007D2776;
	static DWORD W = 19;
	static DWORD H = 19;
	static DWORD X = 138 + 15.0f;
	static DWORD Y = 7;
 
	_asm
	{
		PUSH H                                     ; |Arg6 = 0000000D
		PUSH W                                     ; |Arg5 = 00000012
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0x18]            ; |
		PUSH Y                                     ; |Arg4
		MOV EDX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EAX,DWORD PTR DS:[EDX+0x14]            ; |
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0xC]             ; |
		LEA EAX,DWORD PTR DS:[EAX+EDX+0x3B]        ; |
		PUSH X                                     ; |Arg3
		JMP [Remake_Buffer]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake_03()  //<- PauseHelper
{
	static DWORD Remake_Buffer = 0x007D2821;
	static DWORD W = 19;
	static DWORD H = 19;
	static DWORD X = 138 + 15.0f;
	static DWORD Y = 7;
 
	_asm
	{
		PUSH H                                     ; |Arg6 = 0000000D
		PUSH W                                     ; |Arg5 = 00000012
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0x18]            ; |
		PUSH Y                                     ; |Arg4
		MOV EDX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EAX,DWORD PTR DS:[EDX+0x14]            ; |
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0xC]             ; |
		LEA EAX,DWORD PTR DS:[EAX+EDX+0x3B]        ; |
		PUSH X                                     ; |Arg3
		JMP [Remake_Buffer]
	}
}

//==========================================================================================

void CMacroUIEx::RenderHelperFrame(int *This)
{
	char Cord[256];
	float X = (double)*((DWORD *)This + 5);
	float Y = (double)*((signed int *)This + 6);
	float RenderX;

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	RenderImage(31602, X, Y, 22.0, 25.0);

	for (int i = 0; i < 5; i++)
	{
		RenderX = (double)X + 22.0 + (i * 26.0);
		RenderImage(31603, RenderX, Y, 26.0, 25.0);
	}

	RenderImage(31604, RenderX, Y, 73.0, 20.0);

	//Mapa y Coordenadas
	if (World >= 82 && World <= 100)
	{
		wsprintf(Cord, "%s  (%d , %d)", pGetTextLine(pTextLineThis, (3810 + World - 82)), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	}
	else
	{
		wsprintf(Cord, "%s  (%d , %d)", pGetMapName(World), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	}
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 240, 240, 240, 255);
	pDrawText(pTextThis(), X - 30, Y + 4, Cord, 190, 0, (LPINT)3, 0);
	pGLSwitch();
	EnableAlphaTest(0);
	//-- Config
	gInterface.DrawButtonRender(ButtonSettings, 146, 1, 0, 0);

	if (gInterface.IsWorkZone(ButtonSettings))
	{
		gInterface.DrawToolTip(146, Y + 25, "Config Helper");

		if (gInterface.Data[ButtonSettings].OnClick)
		{
			pDrawButton(31761, 146, 1.6, 18.0f, 13.3, 0, 26.9);
		}
		else
		{
			pDrawButton(31761, 146, 1.6, 18.0f, 13.3, 0, 13.6);
		}
	}
	else
	{
		pDrawButton(31761, 146, 1.0, 18.0f, 13.3, 0, 0);
	}

	if (!*(BYTE*)(*(DWORD*)(MUHELPER_STRUC)+0x08))
	{
		gInterface.DrawButtonRender(ButtonStart, 146 + 18, 1, 0, 0);
		//-- Play
		if (gInterface.IsWorkZone(ButtonStart))
		{
			gInterface.DrawToolTip(146 + 18, Y + 25, "Play Helper");

			if (gInterface.Data[ButtonStart].OnClick)
			{
				pDrawButton(31762, 146 + 18, 1.6, 18.0f, 13.3, 0, 26.9);
			}
			else
			{
				pDrawButton(31762, 146 + 18, 1.6, 18.0f, 13.3, 0, 13.6);
			}
		}
		else
		{
			pDrawButton(31762, 146 + 18, 1.0, 18.0f, 13.3, 0, 0);
		}
	}
	else
	{
		gInterface.DrawButtonRender(ButtonStop, 146 + 18, 1, 0, 0);

		if (offhelper == 1)
		{
			gMuHelper.RunningOffHelper();
		}
		//-- Pause
		if (gInterface.IsWorkZone(ButtonStop))
		{
			gInterface.DrawToolTip(146 + 18, Y + 25, "Pause Helper");

			if (gInterface.Data[ButtonStop].OnClick)
			{
				pDrawButton(31763, 146 + 18, 1.6, 18.0f, 13.3, 0, 26.9);
			}
			else
			{
				pDrawButton(31763, 146 + 18, 1.6, 18.0f, 13.3, 0, 13.6);
			}
		}
		else
		{
			pDrawButton(31763, 146 + 18, 1.0, 18.0f, 13.3, 0, 0);
		}
	}


	if (gProtect.m_MainInfo.CustomMenuSwitch != 0)
	{
		float PosX = 146 + 37;
		gInterface.DrawGUI(eCAMERA_MAIN, PosX, 0);
		gInterface.DrawGUI(eCAMERA_BUTTON1, PosX + 0.2, 1);
		gInterface.DrawGUI(eCAMERA_BUTTON2, PosX + 18.2, 1);
		gInterface.DrawGUI(eCAMERA_BUTTON3, PosX + 36.2, 1);

		if (gCamera.IsActive)
		{
			gInterface.DrawColoredGUI(eCAMERA_BUTTON1, PosX + 0.2, 1, eShinyGreen);
		}
		// ----
		if (gInterface.IsWorkZone(eCAMERA_BUTTON1))
		{
			if (gCamera.IsActive)
			{
				gInterface.DrawToolTip(PosX + 0.2 - 5, 25, "Zoom: %02.f%%", gCamera.ZoomPercent);
			}
			else
			{
				gInterface.DrawToolTip(PosX + 0.2 - 5, 25, "3D Camera [On|Off]");
			}
			// ----
			if (gInterface.Data[eCAMERA_BUTTON1].OnClick)
			{
				pSetCursorFocus = true;
				gInterface.DrawColoredGUI(eCAMERA_BUTTON1, PosX + 0.2, 1, pMakeColor(40, 20, 3, 130));
				return;
			}
			// ----
			gInterface.DrawColoredGUI(eCAMERA_BUTTON1, PosX + 0.2, 1, pMakeColor(255, 204, 20, 200));
		}
		else if (gInterface.IsWorkZone(eCAMERA_BUTTON2))
		{
			gInterface.DrawToolTip(PosX + 18.2 - 5, 25, "3D Camera [Reset]");
			// ----
			if (gInterface.Data[eCAMERA_BUTTON2].OnClick)
			{
				pSetCursorFocus = true;
				gInterface.DrawColoredGUI(eCAMERA_BUTTON2, PosX + 18.2, 1, pMakeColor(40, 20, 3, 130));
				return;
			}
			// ----
			gInterface.DrawColoredGUI(eCAMERA_BUTTON2, PosX + 18.2, 1, pMakeColor(255, 204, 20, 200));
		}
		else if (gInterface.IsWorkZone(eCAMERA_BUTTON3))
		{
			gInterface.DrawToolTip(PosX + 36.2 - 5, 25, "Menu");
			// ----
			if (gInterface.Data[eCAMERA_BUTTON3].OnClick)
			{
				pSetCursorFocus = true;
				gInterface.DrawColoredGUI(eCAMERA_BUTTON3, PosX + 36.2, 1, pMakeColor(40, 20, 3, 130));

			}
			// ----
			gInterface.DrawColoredGUI(eCAMERA_BUTTON3, PosX + 36.2, 1, pMakeColor(255, 204, 20, 200));
		}
	}
//=======================================================
	/*DWORD Color;
	if (gProtect.m_MainInfo.CustomMenuSwitch != 0)
	{
		pDrawButton(30983, 146 + 37.2, 0.0, 36, 18, 0, 0);

		gInterface.DrawButtonRender(eMenu, 146 + 37.2, Y + 1.0 , 0, 0.0f);

		if (gInterface.IsWorkZone(eMenu))
		{
			gInterface.DrawToolTip(146 + 37.2, 50, "Especial Menu");
			// ----
			if (gInterface.Data[eMenu].OnClick)
			{
				Color = eGray150;

				gInterface.DrawColoredGUI(eMenu, 146 + 37.2, Y + 1.0, Color);
			}
			else
			{
				gInterface.DrawButtonRender(eMenu, 146 + 37.2, Y + 1.0 , 0, 0.0f);
			}
		}
		else
		{
			gInterface.DrawButtonRender(eMenu, 146 + 37.2, Y + 1.0 , 0, 0.0f);
		}
	}*/
}

__declspec(naked) void MuHelperRemake2_01()  //<- ConfigHelper
{
	static DWORD Addr_JMP = 0x007D26DA;
	static DWORD W = 18;
	static DWORD H = 13.3;
	static DWORD X = 146.0f;
	static DWORD Y = 1;
 
	_asm
	{
		PUSH H                                  ; |Arg6 = 0000000D
		PUSH W                                  ; |Arg5 = 00000012
		MOV EDX,DWORD PTR SS:[EBP-0xB8]         ; |
		MOV EAX,DWORD PTR DS:[EDX+0x18]            ; |
		PUSH Y                                 ; |Arg4
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0x14]            ; |
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0xC]             ; |
		LEA EDX,DWORD PTR DS:[EDX+ECX+0x29]        ; |
		PUSH X                                 ; |Arg3
		JMP [Addr_JMP]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake2_02()  //<- PlayHelper
{
	static DWORD Addr_JMP = 0x007D2776;
	static DWORD W = 18;
	static DWORD H = 13.3;
	static DWORD X = 146.0f + 18.0f;
	static DWORD Y = 1;
 
	_asm
	{
		PUSH H                                     ; |Arg6 = 0000000D
		PUSH W                                     ; |Arg5 = 00000012
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0x18]            ; |
		PUSH Y                                     ; |Arg4
		MOV EDX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EAX,DWORD PTR DS:[EDX+0x14]            ; |
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0xC]             ; |
		LEA EAX,DWORD PTR DS:[EAX+EDX+0x3B]        ; |
		PUSH X                                     ; |Arg3
		JMP [Addr_JMP]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake2_03()  //<- PauseHelper
{
	static DWORD Addr_JMP = 0x007D2821;
	static DWORD W = 18;
	static DWORD H = 13.3;
	static DWORD X = 146.0f + 18.0f;
	static DWORD Y = 1;
 
	_asm
	{
		PUSH H                                     ; |Arg6 = 0000000D
		PUSH W                                     ; |Arg5 = 00000012
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0x18]            ; |
		PUSH Y                                     ; |Arg4
		MOV EDX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EAX,DWORD PTR DS:[EDX+0x14]            ; |
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0xC]             ; |
		LEA EAX,DWORD PTR DS:[EAX+EDX+0x3B]        ; |
		PUSH X                                     ; |Arg3
		JMP [Addr_JMP]
	}
}

void OffHelper(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(id, x, y, w, h);

	if( gInterface.IsWorkZone(ButtonStartAttack) )
	{
		if( gInterface.Data[ButtonStartAttack].OnClick )
		{
			if(offhelper == 0)
			{
				offhelper = 1;
			}
			else
			{
				offhelper = 0;
			}
			gInterface.Data[ButtonStartAttack].OnClick = false;
		}
	}
	if(offhelper == 1)
	{
		gInterface.DrawButtonRender(ButtonStartAttack, x + 50, y + 8, 0, 0);
	}
	else
	{
		gInterface.DrawButtonRender(ButtonStartAttack, x + 50, y + 8, 0, 15);
	}
	gInterface.DrawFormat(eGold, x + 50 + 16, y + 12, 60, 1, "Offline Mode");
}

void CMacroUIEx::Load()
{
	SetCompleteHook(0xE8,0x007D2B0C,&FixHelperMouseClick);

	SetCompleteHook(0xE8, 0x007F76CD, &OffHelper);

	if( gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4 )
	{
		SetCompleteHook(0xE9, 0x007D2BC0, this->RenderFrame);
		SetCompleteHook(0xE9, 0x0080B8E0, &BarTime);
		SetCompleteHook(0xE9, 0x007D26B5, &MuHelperRemake_01);
		SetCompleteHook(0xE9, 0x007D2751, &MuHelperRemake_02);
		SetCompleteHook(0xE9, 0x007D27FC, &MuHelperRemake_03);
	}
	else
	{
		SetCompleteHook(0xE9, 0x007D26B5, &MuHelperRemake2_01);
		SetCompleteHook(0xE9, 0x007D2751, &MuHelperRemake2_02);
		SetCompleteHook(0xE9, 0x007D27FC, &MuHelperRemake2_03);
		SetCompleteHook(0xE9, 0x007D2BC0, this->RenderHelperFrame);
	}
}
