#include "stdafx.h"
#include "resource.h"
#include "Controller.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protocol.h"
#include "Import.h"
#include "Interface.h"
#include "Protect.h"
#include "TMemory.h"
#include "CSCharacterS13.h"
#include "CMacroUIEx.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "MiniMap.h"
#include "WindowsStruct.h"
#include "Ruud.h"
#include "Central.h"
#include "PartySearch.h"
#include "ControllerTextBox.h"
#include "PartySearchSettings.h"
#include "JewelsBank.h"
#include "ExQuestWinSystem.h"
#include "Achievements.h"
#include "EventTimer.h"
#include "Ranking.h"
#include "ShopSearch.h"
#include "NewParty.h"
// ----------------------------------------------------------------------------------------------

Controller	gController;
// ----------------------------------------------------------------------------------------------
void __declspec(naked) iconHook()
{
	static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON1));
	static DWORD dwJmp = 0x004D0E3C;

	_asm
	{
		MOV EAX, dwIcon
		JMP dwJmp
	}
}

bool Controller::Load()
{
	this->Instance = Instance;
	this->VKF9_State = 0;
	if (!this->MouseHook)
	{
		this->MouseHook = SetWindowsHookEx(WH_MOUSE, this->Mouse, gController.Instance, GetCurrentThreadId());
		// ----
		if (!this->MouseHook)
		{
			return false;
		}
	}
	// ----
	if (!this->KeyboardHook)
	{
		this->KeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, this->Keyboard, gController.Instance, NULL);
		// ----
		if (!this->KeyboardHook)
		{
			return false;
		}
	}
	// ----
	SetOp((LPVOID)0x004D0E2F, iconHook, ASM::CALL);
	return true;
}


LRESULT Controller::Mouse(int Code, WPARAM wParam, LPARAM lParam)
{
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
	}
	// ----
	MOUSEHOOKSTRUCTEX * Mouse	= (MOUSEHOOKSTRUCTEX*)lParam;
	gCamera.Run(Mouse, wParam);
	gController.wMouse = wParam;
	switch(wParam)
	{
	case WM_LBUTTONUP:
	case WM_LBUTTONDOWN:
		{
			gCustomRanking.EventRankingNext(wParam);
			gCustomRanking.EventRankingBack(wParam);
			gInterface.EventVipWindow_Main(wParam);
			gInterface.EventVipWindow_Close(wParam);
			gCustomRanking.EventVipWindow_Close(wParam);
			gCustomCommandInfo.EventCommandWindow_Close(wParam);
			gCustomCommandInfo.CommandNext(wParam);
			gCustomCommandInfo.CommandPrev(wParam);
			gCustomEventTime.EventEventTimeWindow_Close(wParam);
			gCustomEventTime.EventNext(wParam);
			gCustomEventTime.EventPrev(wParam);
			gInterface.EventDrawMenu_Open(wParam);
			gInterface.EventDrawMenu_Close(wParam);
			gInterface.EventDrawMenu_Op1(wParam);
			gInterface.EventDrawMenu_Op2(wParam);
			gInterface.EventDrawMenu_Op3(wParam);
			gInterface.EventDrawMenu_Op4(wParam);
			gInterface.EventDrawMenu_Op5(wParam);
			gInterface.EventDrawMenu_Op6(wParam);
			gInterface.EventDrawMenu_Op7(wParam);
			gInterface.EventDrawMenu_Op8(wParam);
			gInterface.EventDrawMenu_Op20(wParam);
			gInterface.EventDrawMenu_Op30(wParam);
			gInterface.EventConfirm_CANCEL(wParam);
			gInterface.EventConfirm_OK(wParam);
			gCRuudShop.RuudShopEventButton(wParam);
			gCSCharacterS13.SelectCharButton(wParam);
			EventMuOffhelper(wParam);

			gPartySearchSettings.event_party_search_settings_window(wParam);

			gPartySearch.event_party_search_window(wParam);

			gPartySearch.event_party_search_password_window(wParam);

			gInterface.EventCharacterWindow(wParam);
			gInterface.EventStatsAddWindow(wParam);
			gInterface.EventResetStatsWindow(wParam);

			gJewelsBank.Button(wParam);
			gJewelsBank.EventJewelBank_Close(wParam);

			gAchievements.Button(wParam);

			g_ExWinQuestSystem.Button(wParam);

			gInterface.EventEventTableWindow(wParam);

			gInterface.EventFruitWindow_Main(wParam);

			g_PersonalShopEx.Button(wParam);

			gInterface.EventChangingClassWindow_Main(wParam);

			g_Party.MouseController(wParam);
			g_Party.MouseControllerD(wParam);
			g_Party.MouseControllerPage(wParam);

#if(ADD_PARTY_LEADER==1)
			g_Party.MouseControllerLeader(wParam);
#endif
			gInterface.EventPartyInterface(wParam);

			gInterface.EventResetWindow_Main(wParam);

			gInterface.EventWarehouseWindow_Main(wParam);

			gInterface.EventCameraUI(wParam);

			gInterface.EventSettingsUI(wParam);

			if(gCRuudShop.RuudRender.Open)
			{
				if ( pCheckMouseOver(gCRuudShop.RuudRender.x, gCRuudShop.RuudRender.y + 10, gCRuudShop.RuudRender.w, 40.0f) == 1 )
				{
					gCRuudShop.RuudRender.Cursor.x = (double)*(DWORD*)0x879340C - gCRuudShop.RuudRender.x;
					gCRuudShop.RuudRender.Cursor.y = (double)*(DWORD*)0x8793410 - gCRuudShop.RuudRender.y;
					if(wParam == WM_LBUTTONDOWN)
					{
						gCRuudShop.RuudRender.Move = 1;
					}
					else
					{
						gCRuudShop.RuudRender.Move = 0;
					}
				}
				else
				{
					gCRuudShop.RuudRender.Move = 0;
				}
			}
			else if(gProtect.m_MainInfo.CustomInterfaceType == 1)
			{
				gInterface.EventNewInterface97_All(wParam);
			}
			else if(gProtect.m_MainInfo.CustomInterfaceType == 2)
			{
				gInterface.EventNewInterface_All(wParam);
			}
			gCMacroUIEx.Button(wParam);
			gOffTrade.EventOffTradeWindow_Main(wParam);
			gOffTrade.EventCloseTradeWindow_Main(wParam);
		}
		
		break;
		case WM_MOUSEMOVE:

			gCRuudShop.MoveWindows(&gCRuudShop.RuudRender,
				((double)*(DWORD*)0x879340C) - gCRuudShop.RuudRender.Cursor.x,
				((double)*(DWORD*)0x8793410) - gCRuudShop.RuudRender.Cursor.y);

	}
	// ----
	return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------

LRESULT Controller::Keyboard(int Code, WPARAM wParam, LPARAM lParam)
{
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
	}

	if (Code < 0) return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
	
	if( (Code == HC_ACTION) && (wParam == WM_KEYDOWN))
	{
		KBDLLHOOKSTRUCT Hook = *((KBDLLHOOKSTRUCT*)lParam);

		USERBUTTON_REQ pRequest;

		if (GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
		{
			//gConsole.AddMessage(5, "Pressed: %d", Hook.vkCode);
			if (gTextBoxController.ControlTextBox(Hook))
			{
				return 1;
			}
		}

		switch(Hook.vkCode)
		{
			// --
		case VK_F4:
		{
			gInterface.SwitchSettingsWindowState();
		}
		break;
		case VK_F5:
		{
			gInterface.Fruit_State();
		}
		break;
		case VK_F6:
		{
			gInterface.ChangingClassWindowState();
		}
		break;
		case VK_F7:
		{
			pRequest.Head.set(0xFF, 0x21, sizeof(pRequest));
			DataSend((BYTE*)&pRequest, pRequest.Head.size);
			gRanking.Show = true;
		}
		break;
		case VK_F8:
		{
			if (gJewelsBank.Active)
			{
				gJewelsBank.Active = false;
			}
			else
			{
				gJewelsBank.Active = true;
			}
		}
		break;	
		case VK_F9:
		{
			gAchievements.CGWindowOpen();
		}
		break;
		case VK_F10:
		{
			gInterface.SwitchCamera();
		}
		break;
		case VK_F11:
		{
			gInterface.CameraInit();
		}
		break;
		case VK_F12:
		{
			if (gTrayMode.TempWindowProc == NULL)
			{
				gTrayMode.TempWindowProc = SetWindowLong(pGameWindow, GWL_WNDPROC, (long)gController.Window);
			}
			// ----
			gTrayMode.SwitchState();
		}
		break;
		case VK_ESCAPE:
		{
			gInterface.CloseChangingClassWindow();
			gInterface.CloseCustomWindow();
			gInterface.CloseEventTableWindow();
			gInterface.CloseFruitWindow();
			gInterface.CloseMenuWindow();
			gInterface.CloseResetStatsWindow();
			gInterface.CloseStatsAddWindow();
			gInterface.CloseVipWindow();
		}
		break;
		case VK_END:
		{
			if (gInterface.CheckVipWindow())
			{
				gInterface.CloseVipWindow();
			}
			else
			{
				gInterface.CloseCustomWindow();
				gInterface.OpenVipWindow();
			}
		}
		break;
		case VK_SNAPSHOT:
		{
			gInterface.Data[eLogo].EventTick = GetTickCount()+1500;
			return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
		}
		break;

		default:
		break;
		}
	} 
	return (LRESULT) NULL;
	
}
// ----------------------------------------------------------------------------------------------


LRESULT Controller::Window(HWND Window, DWORD Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{

	case TRAYMODE_ICON_MESSAGE:
		{
			switch(lParam)
			{
			case WM_LBUTTONDBLCLK:
				{
					gTrayMode.SwitchState();
				}
				break;
			}
		}
		break;
	}
	// ----
	return CallWindowProc((WNDPROC)gTrayMode.TempWindowProc, Window, Message, wParam, lParam);
}


