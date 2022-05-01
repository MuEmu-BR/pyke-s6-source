#include "stdafx.h"
#include "Common.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Interface.h"
#include "Import.h"
#include "Reconnect.h"
#include "TMemory.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protect.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "User.h"
#include "Util.h"
#include "array.h"
#include "Offset.h"
#include "StatsAdvance.h"
#include "CustomCloak.h"
#include "ChatExpanded.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "Controller.h"
#include "postInterface.h"
#include "Ruud.h"
#include "Inter3.h"
#include "InterEx.h"
#include "Central.h"
#include "JewelryBank.h"
#include "NPCRuud.h"
#include "PartySearchSettings.h"
#include "PartySearch.h"
#include "JewelsBank.h"
#include "ExQuestWinSystem.h"
#include "Achievements.h"
#include "EventTimer.h"
#include "Font.h"
#include "Ranking.h"
#include "ShopSearch.h"
#include "ChangeClass.h"
#include "NewParty.h"
#include "ResetSystem.h"
#include "ServerInfo.h"

Interface gInterface;

Interface::Interface()
{
}

Interface::~Interface()
{
}

void Interface::RenderObjectSystem()
{
	if(gProtect.m_MainInfo.MonitorMS == 1){
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}
	if(gProtect.m_MainInfo.MonitorFPS == 1){
		gInterface.iniciador = 1;
	}
	//51522
	//--
	
	//Menu
	this->BindObject(eMenu_MAIN, 0x7A5A, 222, 372, -1, -1);
	this->BindObject(eMenu_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eMenu_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eMenu_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eMenu_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eMenu_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eMenu_OPT1, 0x7A5E, 107.1f, 29, -1, -1);
	this->BindObject(eMenu_OPT2, 0x7A5E, 107.1f, 29, -1, -1);
	this->BindObject(eMenu_OPT3, 0x7A5E, 107.1f, 29, -1, -1);
	this->BindObject(eMenu_OPT4, 0x7A5E, 107.1f, 29, -1, -1);
	this->BindObject(eMenu_OPT5, 0x7A5E, 107.1f, 29, -1, -1);
	this->BindObject(eMenu_OPT6, 0x7A5E, 107.1f, 29, -1, -1);
	this->BindObject(eMenu_OPT7, 0x7A5E, 107.1f, 29, -1, -1);
	this->BindObject(eMenu_OPT8, 0x7A5E, 107.1f, 29, -1, -1);
	this->BindObject(eMenu_OPT20, 0x7A5E, 107.1f, 29, -1, -1);
	this->BindObject(eMenu_OPT30, 0x7A5E, 107.1f, 29, -1, -1);
	//--
	this->BindObject(eTIME, 0x787F, 131, 70, -10, 359);
	this->BindObject(eFlag01, 0x7880, 78, 78, -1, -1);
	this->BindObject(eFlag02, 0x7881, 78, 78, -1, -1);
	this->BindObject(eFlag03, 0x7882, 78, 78, -1, -1);
	this->BindObject(eFlag04, 0x7883, 78, 78, -1, -1);
	this->BindObject(eFlag05, 0x7884, 78, 78, -1, -1);
	this->BindObject(eFlag06, 0x7885, 78, 78, -1, -1);
	this->BindObject(eFlag07, 0x7886, 78, 78, -1, -1);
	this->BindObject(eFlag08, 0x7887, 78, 78, -1, -1);
	this->BindObject(eFlag09, 0x7888, 78, 78, -1, -1);
	this->BindObject(eFlag10, 0x7889, 78, 78, -1, -1);
	this->BindObject(eFlag11, 0x7890, 78, 78, -1, -1);
	this->BindObject(eFlag12, 0x7891, 78, 78, -1, -1);
	this->BindObject(eFlag13, 0x7892, 78, 78, -1, -1);
	this->BindObject(eFlag14, 0x7893, 78, 78, -1, -1);
	this->BindObject(eFlag15, 0x7894, 78, 78, -1, -1);
	this->BindObject(eFlag16, 0x7895, 78, 78, -1, -1);
	this->BindObject(eFlag17, 0x7896, 78, 78, -1, -1);
	this->BindObject(eFlag18, 0x7897, 78, 78, -1, -1);
	this->BindObject(eFlag19, 0x7898, 78, 78, -1, -1);
	this->BindObject(eFlag20, 0x7899, 78, 78, -1, -1);
	this->BindObject(eFlag21, 0x7900, 78, 78, -1, -1);
	this->BindObject(eFlag22, 0x7901, 78, 78, -1, -1);
	//--
	this->BindObject(eRanking, 0x7902, 179, 27, -1, -1);
	this->BindObject(eSAMPLEBUTTON, 0x7903, 25, 40, -1, -1);
	this->BindObject(eSAMPLEBUTTON2, 0x7904, 25, 40, -1, -1);
	//--
	this->BindObject(eVip_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eVip_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eVip_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eVip_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eVip_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eVip_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eVip_BRONZE, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_SILVER, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_GOLD, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_PLATINUM, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_STATUS, 0x7A5E, 108, 29, -1, -1);
	
	//--
	this->BindObject(eCommand_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eCommand_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCommand_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCommand_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCommand_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCommand_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eRanking_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eRanking_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eEventTime_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eEventTime_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eCONFIRM_MAIN, 0x7A5A, 222, 120, 205, -1);
	this->BindObject(eCONFIRM_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCONFIRM_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCONFIRM_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCONFIRM_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCONFIRM_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_BTN_CANCEL, 0x7A5C, 54, 30, -1, -1);
	this->BindObject(eLogo, 0x7905, 150, 114, -1, -1);
	//Custom Store
	if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		this->BindObject(eOFFTRADE_JoB, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 51522, 108, 30, -1, -1);
	}
	else
	{
		this->BindObject(eOFFTRADE_JoB, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 0x7BFD, 108, 30, -1, -1);
	}
	//-- custom
	this->BindObject(eSTORE_CLOSE, 0x7BFD, 108, 30, -1, -1);
	//Minimap
	this->BindObject(ePLAYER_POINT, 31460, 3, 3, -1, -1);
	this->BindObject(eNULL_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eLORENCIA_MAP, 31462, 128, 128, -1, -1);
	this->BindObject(eDUNGEON_MAP, 31463, 128, 128, -1, -1);
	this->BindObject(eDEVIAS_MAP, 31464, 128, 128, -1, -1);
	this->BindObject(eNORIA_MAP, 31465, 128, 128, -1, -1);
	this->BindObject(eLOSTTOWER_MAP, 31466, 128, 128, -1, -1);
	this->BindObject(eSTADIUM_MAP, 61465, 128, 128, -1, -1);
	this->BindObject(eATLANS_MAP, 31467, 128, 128, -1, -1);
	this->BindObject(eTarkan_MAP, 31468, 128, 128, -1, -1);
	this->BindObject(eElbeland_MAP, 31469, 128, 128, -1, -1);
	this->BindObject(eICARUS_MAP, 31470, 128, 128, -1, -1);
	this->BindObject(eLANDOFTRIALS_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eAIDA_MAP, 31472, 128, 128, -1, -1);
	this->BindObject(eCRYWOLF_MAP, 31473, 128, 128, -1, -1);
	this->BindObject(eKANTRU_MAP, 31474, 128, 128, -1, -1);
	this->BindObject(eKANTRU3_MAP, 31475, 128, 128, -1, -1);
	this->BindObject(eBARRACKS_MAP, 31476, 128, 128, -1, -1);
	this->BindObject(eCALMNESS_MAP, 31477, 128, 128, -1, -1);
	this->BindObject(eRAKLION_MAP, 31478, 128, 128, -1, -1);
	this->BindObject(eVULCANUS_MAP, 31479, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN_MAP, 31480, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN2_MAP, 31481, 128, 128, -1, -1);
	this->BindObject(eNextCommand, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevCommand, 31658, 17, 18, -1, -1);
	this->BindObject(eNextEvent, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevEvent, 31658, 17, 18, -1, -1);
	this->BindObject(eCamera3DInit, 31659, 17, 18, -1, -1);
	this->BindObject(eCamera3DSwitch, 31659, 17, 18, -1, -1);
	//this->Data[eTIME].OnShow = false;
	if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		this->BindObject(ButtonSettings, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStart, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStop, 51522, 19, 19, -1, -1);
	}
	else
	{
		this->BindObject(ButtonSettings, 31761, 18, 13.3, -1, -1);
		this->BindObject(ButtonStart, 31762, 18, 13.3, -1, -1);
		this->BindObject(ButtonStop, 31763, 18, 13.3, -1, -1);
	}
	this->BindObject(ButtonStartAttack, 31593, 15, 15, -15, -15);
	//--
	this->BindObject(eJewelOfBank, 51522, 230.0, 270.0, -1, -1);
	this->BindObject(eJewelOfBankPush, 71521, 59, 28, -1, -1);
	this->BindObject(eJewelOfBankRemove, 71521, 59, 28, -1, -1);
	this->BindObject(eJewelOfBankClose, 71521, 59, 28, -1, -1);

	switch(gProtect.m_MainInfo.CustomInterfaceType)
	{
	case 1:
	case 2:
		//--
		if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{
			this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
			this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
		}
		//--
		this->BindObject(MINIMAP_FRAME, 31608, 154, 162, -10, 359);
		this->BindObject(MINIMAP_TIME_FRAME, 31609, 134.0, 37.0, -10, 359);
		this->BindObject(MINIMAP_BUTTOM, 31617, 38.0f, 24.0f, -10, 569);
		//---
		this->BindObject(eDragonLeft, 2337, 108.0, 45.0, 0.0, 385);
		this->BindObject(eDragonRight, 2336, 108.0, 45.0, 532.0, 385);
		this->BindObject(eParty, iNewParty, 25, 25, 348, 449);
		this->BindObject(eCharacter, iNewCharacter, 25, 25, 379, 449);
		this->BindObject(eInventory, iNewInventory, 25, 25, 409, 449);
		this->BindObject(eFriend, iNewWinpush, 52, 18, 581, 432);

		if(gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			this->BindObject(eFastMenu, iNewFastMenu, 53, 19, 5, 432);
		}
		this->BindObject(eGuild, iNewGuild, 52, 18, 581, 454);
		break;
	case 3:
	case 4:
		this->BindObject(eButton1, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton2, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton3, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton4, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton5, 61525, 43.0f, 17.0f, -43.0f, -17.0f);

		if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{
			this->BindObject(eMenu, 51522, 19, 19, -1, -1);
			this->BindObject(eMenuBG, 51522, 36, 18, 174, 0);
		}
		//Ex700
		this->BindObject(chatbackground, 51545, 300.0f, 128.0f, -10, 569);
		this->BindObject(eShop, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCharacter, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eInventory, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eQuest, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCommunity, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eSystem, 51522, 19.5f, 19.5f, -1, -1);
		break;
	default:
		if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{
			this->BindObject(eCAMERA_MAIN, 0x787A, 72, 18, 195, 0);
			this->BindObject(eCAMERA_BUTTON1, 0x787B, 16, 12, -1, -1);
			this->BindObject(eCAMERA_BUTTON2, 0x787C, 16, 12, -1, -1);
			this->BindObject(eCAMERA_BUTTON3, 0x7906, 16, 12, -1, -1);
		}
		break;
	}
	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		this->BindObject(eMoney1, 0x7909, 75, 13, -1, -1);
		this->BindObject(eMoney2, 0x7910, 75, 13, -1, -1);
	}
	if(gProtect.m_MainInfo.DisableAdvance == 0)
	{
		gInterface.BindObject(eADVANCE_STAT_INFO, ex_INFO_2, 35, 30, -1, -1);
	}

	this->BindObject(OBJECT_PARTYSETTINGS_MAIN, 0x7A5A, 222, 345 + 30, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_SYSTEM_ACTIVE, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_ONLY_GUILD, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_ONLY_ALLIANCE, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_ONE_CLASS, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_DARK_WIZARD, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_DARK_KNIGHT, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_ELF, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_MAGIC_GLADIATOR, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_DARK_LORD, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_SUMMONER, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_RAGE_FIGHTER, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_LEVEL_MINUS, 0x7C0D, 16, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_LEVEL_PLUS, 0x7AA4, 16, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_PASSWORD, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(OBJECT_PARTYSETTINGS_OK, 0x7A5B, 54, 30, -1, -1);

	this->BindObject(OBJECT_PARTYSEARCH_MAIN, 0x7A5A, 222, 345, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_LEFT, 0x7E56, 20, 23, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_RIGHT, 0x7E57, 20, 23, -1, -1);

	this->BindObject(OBJECT_PARTYPASSWORD_MAIN, 0x7A5A, 222, 122, -1, -1);
	this->BindObject(OBJECT_PARTYPASSWORD_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(OBJECT_PARTYPASSWORD_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(OBJECT_PARTYPASSWORD_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(OBJECT_PARTYPASSWORD_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(OBJECT_PARTYPASSWORD_TEXTBOX, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(OBJECT_PARTYPASSWORD_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_IMAGE1, 0x7898, -1, -1, -1, -1);
	this->BindObject(OBJECT_PARTYSEARCH_IMAGE2, 0x7899, -1, -1, -1, -1);

	memset(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue, 0, sizeof(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue));

	this->BindObject(eSTATSADD_MAIN, 0x7A5A, 222, 226, -1, -1);
	this->BindObject(eSTATSADD_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eSTATSADD_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eSTATSADD_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eSTATSADD_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eSTATSADD_TEXTBOX01, 0x9307, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX01, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX02, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX03, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX04, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX05, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	//
	this->BindObject(eRESETSTATS_MAIN, 0x7A5A, 222, 140, -1, -1);
	this->BindObject(eRESETSTATS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eRESETSTATS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eRESETSTATS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eRESETSTATS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eRESETSTATS_POINT, 0x7B68, 10, 10, -1, -1);
	this->BindObject(eRESETSTATS_CHECK_WC, 0x7BAE, 15, 15, 390, 132);
	this->BindObject(eRESETSTATS_CHECK_STAT, 0x7BAE, 15, 15, 390, 152);
	this->BindObject(eRESETMASTER_CHECK_WC, 0x7BAE, 15, 15, 390, 172);
	this->BindObject(eRESETMASTER_CHECK_STAT, 0x7BAE, 15, 15, 390, 192);
	this->BindObject(eRESETSTATS_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	//
	this->BindObject(eCHARINFO_BTN_STAT, 0x7AA4, 16, 15, 475, 73);
	this->BindObject(eCHARINFO_BTN_RESSTAT, 0x7AA4, 16, 15, 475, 94);

	this->BindObject(eARROW_LEFT2, 0x7E59, 20, 22, -1, -1);
	this->BindObject(eARROW_RIGHT2, 0x7E5A, 20, 22, -1, -1);
	this->BindObject(eEVENTTABLE_MAIN, 0x7A5A, 190, 428, -1, -1);
	this->BindObject(eEVENTTABLE_TITLE, 0x7A79, 190, 64, -1, -1);
	this->BindObject(eEVENTTABLE_LEFT, 0x7A7B, 21, 320, -1, -1);
	this->BindObject(eEVENTTABLE_RIGHT, 0x7A7C, 21, 320, -1, -1);
	this->BindObject(eEVENTTABLE_FOOTER, 0x7A7D, 190, 45, -1, -1);
	this->BindObject(eEVENTTABLE_DIV, 0x7A62, 183, 21, -1, -1);
	this->BindObject(eEVENTTABLE_CLOSE, 0x7EC5, 36, 29, -1, -1);

	this->BindObject(eFruitClose, 0x7EC5, 36, 29, -1, -1);

	this->BindObject(eCHANGINGCLASS_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eCHANGINGCLASS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCHANGINGCLASS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCHANGINGCLASS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCHANGINGCLASS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCHANGINGCLASS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_INFOBG, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eCHANGINGCLASS_MONEYBG, 0x7A89, 170, 26, -1, -1);
	this->BindObject(eCHANGINGCLASS_DW, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_DK, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_ELF, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_MG, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_DL, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_SUM, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_RF, 0x7A5E, 106, 29, -1, -1);

	this->BindObject(ePARTYLEADER, 0x789A, 9, 10, 614, 41);
	this->BindObject(ePARTYLEADER2, 0x789A, 9, 10, 614, 65);
	this->BindObject(ePARTYLEADER3, 0x789A, 9, 10, 614, 89);
	this->BindObject(ePARTYLEADER4, 0x789A, 9, 10, 614, 113);
	//
	this->BindObject(ePARTYTRACE, 0x789B, 9, 10, 600, 17);
	this->BindObject(ePARTYTRACE2, 0x789B, 9, 10, 600, 41);
	this->BindObject(ePARTYTRACE3, 0x789B, 9, 10, 600, 65);
	this->BindObject(ePARTYTRACE4, 0x789B, 9, 10, 600, 89);
	this->BindObject(ePARTYTRACE5, 0x789B, 9, 10, 600, 113);

	this->BindObject(eRESET_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eRESET_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eRESET_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eRESET_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eRESET_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eRESET_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eRESET_INFOBG, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eRESET_MONEYBG, 0x7A89, 170, 26, -1, -1);
	this->BindObject(eRESET_FINISH, 0x7A5E, 106, 29, -1, -1);

	this->BindObject(eWAREHOUSE_MAIN, 0x7A5A, 222, 211, -1, -1);
	this->BindObject(eWAREHOUSE_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eWAREHOUSE_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eWAREHOUSE_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eWAREHOUSE_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eWAREHOUSE_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM1, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM2, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM3, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM4, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM5, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM6, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM7, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM8, 0x7A5E, 106, 29, -1, -1);

	this->BindObject(eSETTINGS_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eSETTINGS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eSETTINGS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eSETTINGS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eSETTINGS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eSETTINGS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eSETTINGS_OPTION, 0x7B68, 10, 10, -1, -1);
	this->BindObject(eSETTINGS_LINE, 0x7B67, 154, 2, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX1, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX2, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX3, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX4, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX5, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX6, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX7, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX8, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX9, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX10, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX11, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSETTINGS_CHECKBOX12, 0x7BAE, 15, 15, -1, -1);

	SetRange((LPVOID)0x00842086, 5, ASM::NOP);
	SetRange((LPVOID)0x0084234F, 5, ASM::NOP);
	SetRange((LPVOID)0x008423C3, 5, ASM::NOP);
	SetOp((LPVOID)oLoadSomeForm_Call, this->LoadImages, ASM::CALL);
	SetOp((LPVOID)oDrawInterface_Call, this->Work, ASM::CALL);

	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		SetRange((LPVOID)0x00835116, 5, ASM::NOP);
		SetOp((LPVOID)0x00835116, this->DrawZenAndRud, ASM::CALL);
	}

	gJewelsBank.JewelsBankLoad();
	g_PersonalShopEx.BindImages();
	gAchievements.BindImages();
	g_ExWinQuestSystem.BindImages();
}

void Interface::DrawZenAndRud(int a1, int a2, int a3, int a4)
{
	int v10;
	int v11;
	DWORD v23;
	v10 = *(DWORD*)(a1 + 40);
	v11 = *(DWORD*)(a1 + 36);
	v23 = *(DWORD*)(*(DWORD*)0x8128AC4 + 5956);
	*(float*)(0x00D24E88); //Width

	char MoneyBuff1[50], MoneyBuff2[50], MoneyBuff3[50], MoneyBuff4[50], test[50];
	ZeroMemory(MoneyBuff1, sizeof(MoneyBuff1));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	ZeroMemory(MoneyBuff3, sizeof(MoneyBuff3));
	ZeroMemory(MoneyBuff4, sizeof(MoneyBuff4));

	pGetMoneyFormat(v23, MoneyBuff1, 0);
	pGetMoneyFormat(Coin3, MoneyBuff2, 0);
	pGetMoneyFormat(Coin1, MoneyBuff3, 0);
	pGetMoneyFormat(Coin2, MoneyBuff4, 0);

	gInterface.DrawFormat(eWhite, v11, v10 + 12, 190, 3, pGetTextLine(pTextLineThis, 223));
	//--
	gInterface.DrawGUI(eMoney1, v11 + 18, v10 + 365);
	gInterface.DrawFormat(eBlack, v11 + 18, v10 + 367, 20, 1, "Zen");
	gInterface.DrawFormat(eRed, v11 + 40, v10 + 367, 50, 3, "%s", MoneyBuff1);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 365);
	gInterface.DrawFormat(eBlack, v11 + 102, v10 + 367, 20, 1, "GP");
	gInterface.DrawFormat(eWhite, v11 + 128, v10 + 367, 45, 4, "%s", MoneyBuff2);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 18, v10 + 378);
	gInterface.DrawFormat(eBlack, v11 + 17, v10 + 380, 20, 1, "WC");
	gInterface.DrawFormat(eGold, v11 + 38, v10 + 381, 50, 4, "%s", MoneyBuff3);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 378);
	gInterface.DrawFormat(eBlack, v11 + 98, v10 + 380, 20, 1, "WCP");
	gInterface.DrawFormat(eBlue, v11 + 128, v10 + 381, 45, 4, "%s", MoneyBuff4);
}

void Interface::LoadModels()
{
	pLoadModel(406, "Data\\Custom\\Bmd\\VIP1\\", "musign", -1);
	pLoadTexture(406, "Custom\\Bmd\\VIP1\\", 0x2901, 0x2600, 1);
	pLoadModel(407, "Data\\Custom\\Bmd\\VIP2\\", "musign", -1);
	pLoadTexture(407, "Custom\\Bmd\\VIP2\\", 0x2901, 0x2600, 1);
	pLoadModel(408, "Data\\Custom\\Bmd\\VIP3\\", "musign", -1);
	pLoadTexture(408, "Custom\\Bmd\\VIP3\\", 0x2901, 0x2600, 1);
	// ----
	pInitModelData2();
}

void Interface::LoadImages()
{
	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		pLoadImage("Custom\\Interface\\Money\\item_money.tga", 0x7909, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Money\\item_money2.tga", 0x7910, 0x2601, 0x2901, 1, 0);
	}
	//
	pLoadImage("Custom\\Interface\\Rank01.tga", 0x7880, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank02.tga", 0x7881, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank03.tga", 0x7882, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank04.tga", 0x7883, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank05.tga", 0x7884, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank06.tga", 0x7885, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank07.tga", 0x7886, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank08.tga", 0x7887, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank09.tga", 0x7888, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank10.tga", 0x7889, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank11.tga", 0x7890, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank12.tga", 0x7891, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank13.tga", 0x7892, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank14.tga", 0x7893, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank15.tga", 0x7894, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank16.tga", 0x7895, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank17.tga", 0x7896, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank18.tga", 0x7897, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank19.tga", 0x7898, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank20.tga", 0x7899, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank21.tga", 0x7900, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank22.tga", 0x7901, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Ranking.tga", 0x7902, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Next.tga", 0x7903, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Previous.tga", 0x7904, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\MU-logo.tga", 0x7905, 0x2601, 0x2901, 1, 0);

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		pLoadImage("Custom\\Interface\\Menu1.tga", 0x7906, 0x2601, 0x2901, 1, 0);
	}
	else
	{
		pLoadImage("Custom\\Interface\\Menu2.tga", 0x7906, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Menu_BG.tga", 0x7907, 0x2601, 0x2901, 1, 0);
	}
	pLoadImage("Custom\\Interface\\Button.tga", 0x7908, 0x2601, 0x2900,1,0);
	//MiniMap
	pLoadImage("Custom\\Maps\\PlayerPoint.jpg", 31460, 0x2600, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\none.tga", 31461, 0x2601, 0x2900, 1, 0);
	//--
	pLoadImage("Custom\\Maps\\edBtUcx.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\edBtUcx_1.tga", 31464, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\YYB6BUk.tga", 31465, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_blacksmith.tga", 31466, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Potion.tga", 31467, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_baul.tga", 31468, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Que.tga", 31469, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_monsterred.tga", 31471, 0x2601, 0x2900, 1, 0); //-- Dungeon Red
	pLoadImage("Custom\\Maps\\mini_map_ui_monsterblue.tga", 31472, 0x2601, 0x2900, 1, 0); //-- Dungeon Blue

	pLoadImage("Interface\\mini_map_ui_party.tga", 61520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha

	if(gProtect.m_MakeViewTRSData.TooltipS15 == 1)
	{
		//-- itemtooltip
		pLoadImage("Interface\\GFx\\tooltip_bg01.tga", 61511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
		pLoadImage("Interface\\GFx\\tooltip_bg02.tga", 61512, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg03.tga", 61513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
		pLoadImage("Interface\\GFx\\tooltip_bg04.tga", 61514, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg06.tga", 61515, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg07.tga", 61516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
		pLoadImage("Interface\\GFx\\tooltip_bg08.tga", 61517, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg09.tga", 61518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	}
	//-- itemtooltip
	pLoadImage("Interface\\GFx\\popupbg01.tga", 71511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
	pLoadImage("Interface\\GFx\\popupbg02.tga", 71512, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg03.tga", 71513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
	pLoadImage("Interface\\GFx\\popupbg04.tga", 71514, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg06.tga", 71515, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg07.tga", 71516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
	pLoadImage("Interface\\GFx\\popupbg08.tga", 71517, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg09.tga", 71518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\popup_line_m.tga", 71519, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\popup_line_s.tga", 71520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\Render_buttom_1.tga", 71521, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\Render_buttom_2.tga", 71522, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\Render_buttom_3.tga", 71524, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\RenderBits_Sound.tga", 71523, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\newui_option_volume01.tga", 31596, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\newui_option_volume02.tga", 31597, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Custom\\Party\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);
	//--
	LoadBitmapA("Interface\\newui_number1.tga", 31337, 9729, 10496, 1, 0);

	LoadBitmapA("Interface\\newui_SW_Minimap_Frame.tga", 31608, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\newui_SW_Time_Frame.tga", 31609, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\newui_SW_MiniMap_Bt_clearness.jpg", 31617, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\InventoryFrame_RuudShop.tga", 61560, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Menu_RuudShopFrame.tga", 61561, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Menu_Button03.tga", 61562, GL_LINEAR, GL_CLAMP, 1, 0);
	//
	switch(gProtect.m_MainInfo.CustomInterfaceType) 
	{
	case 1:
	case 2:
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Item_Back01.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\DragonRight.tga", 2336, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\DragonLeft.tga", 2337, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		if(gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left97.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\Interface\\none.tga", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		}else
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\InterfaceS2\\Menu_SD.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		}
		
		LoadBitmapA("Custom\\InterfaceS2\\Menu_right.jpg", 31294, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_middle.jpg", 31293, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Red.jpg", 0x7A42, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Green.jpg", 0x7A41, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Blue.jpg", 0x7A40, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_AG.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_fastmenu.jpg", iNewFastMenu, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Inventory.jpg", iNewInventory, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Character.jpg", iNewCharacter, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Party.jpg", iNewParty, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_friend.jpg", iNewWinpush, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_guild.jpg", iNewGuild, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\skillboxR.jpg", 0x700003, 0x2601, 0x2901, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill.jpg", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill2.jpg", 31309, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill3.jpg", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_command.jpg", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill.jpg", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill2.jpg", 31315, GL_LINEAR, GL_CLAMP, 1, 0); 
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill3.jpg", 31317, GL_LINEAR, GL_CLAMP, 1, 0); 
		//--
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox.jpg", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox2.jpg", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		//Interface Character
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats.jpg", 31352, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\StatsDL.jpg", 51291, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats2.jpg", 51292, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_box.jpg", 35353, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_button.jpg", 51290, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- chat
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_vframe.jpg", 51551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe.tga", 51552, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_up.jpg", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_m.jpg", 51554, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_down.jpg", 51555, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_hframe.jpg", 31275, 9729, 10496, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue1.tga", 51530, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2.tga", 51531, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2_1.jpg", 51532, GL_LINEAR, GL_CLAMP, 1, 0);
		break;
	case 3:
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I1.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I2.tga", 61523, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I3.tga", 61524, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3.tga", 61526, GL_LINEAR, GL_CLAMP, 1, 0); //-- All Window
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I4.tga", 61527, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Draw_money.tga", 61528, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\button_close.tga", 61529, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I1.tga", 61532, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_chainfo_btn_level.tga", 61533, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ButtonCharacterInfo.tga", 61535, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I2.tga", 61538, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I1.tga", 61539, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I2.tga", 61540, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I1.tga", 61541, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I2.tga", 61543, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\StoreFrame_I1.tga", 61544, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE_Exp.tga", 59000, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I1.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);
		goto LOAD_GFX;
	case 4:
		LoadBitmapA("Interface\\GFx\\Legends\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I3.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\Legends\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);
LOAD_GFX:
		LoadBitmapA("Interface\\GFx\\Buttom_empty_small.tga", 61525, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_number1.tga", 6829, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg01.tga", 61550, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg02.tga", 61551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg03.tga", 61534, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Chat_I5.tga", 61548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_chat_back.tga", 61549, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Main_IE_Buttons.tga", 0x901, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\skill_render.tga", 61546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\item_pbtnbg.tga", 61547, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- Folder MacroUI
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Main.tga", 51550, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BSetup.tga", 51546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BStart.tga", 51547, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Stop.tga", 51548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Bar.jpg", 51549, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Menu.tga", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- Botones del Main
		LoadBitmapA("Custom\\Interface\\none.tga", 31303, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31304, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31305, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31306, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31307, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\Interface\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
		break;
	}
	LoadBitmapA("Custom\\Interface\\TimeBar.tga", 0x787F, 0x2601, 0x2901, 1, 0);

	if( gProtect.m_MainInfo.DisableEffectRemake == 0 )
	{
		pLoadImage("Effect\\flare01.jpg", 52002, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareRed.jpg", 52230, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\JointLaser01.jpg", 52224, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\hikorora.jpg", 52379, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareBlue.jpg", 52229, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\bostar3_R.jpg", 32614, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\line_of_big_R.jpg", 32772, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flare01.jpg", 42134, GL_LINEAR, GL_REPEAT, 1, 0);
	}

	pLoadImage("Custom\\Interface\\PartySearch_Title.tga", 0x7898, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Custom\\Interface\\Info_Block.tga", 0x7899, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Custom\\Interface\\Title.tga", 0x9306, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Custom\\Interface\\newui_cha_textbox01.tga", 0x9307, GL_LINEAR, GL_REPEAT, 1, 0);

	pLoadImage("Custom\\Interface\\ui-dialog1_hr.tga", iNewuiDialogHr, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Custom\\Interface\\ui_dialog_e.tga", iGfxDialoge, GL_LINEAR, GL_REPEAT, 1, 0);

	pLoadImage("Custom\\Interface\\pm_flag.tga", 0x789A, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Custom\\Interface\\Portal.tga", 0x789B, GL_LINEAR, GL_REPEAT, 1, 0);

	pLoadImage("Custom\\Interface\\CameraUI_BG.tga", 0x787A, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\CameraUI_Switch.tga", 0x787B, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\CameraUI_Reset.tga", 0x787C, 0x2601, 0x2900, 1, 0);

	pLoadImage("Logo\\Mu-logo_g.jpg", 531019, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Logo\\Mu-logo.tga", 531018, GL_LINEAR, GL_REPEAT, 1, 0);
	//--
	if(gProtect.m_MainInfo.DisableCustomCloack == 0)
	{
		gCloak.LoadTexture();
	}

	gJewelsBank.JewelsBankImageLoad();

	gAchievements.LoadImages();
	g_ExWinQuestSystem.ImageLoad();
	gRanking.ImageLoad();

	//--
	pLoadSomeForm();
}

void Interface::BindObject(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y)
{
	this->Data[MonsterID].EventTick	= 0;
	this->Data[MonsterID].OnClick	= false;
	this->Data[MonsterID].OnShow	= false;
	this->Data[MonsterID].ModelID	= ModelID;
	this->Data[MonsterID].Width		= Width;
	this->Data[MonsterID].Height	= Height;
	this->Data[MonsterID].X			= X;
	this->Data[MonsterID].Y			= Y;
	this->Data[MonsterID].MaxX		= X + Width;
	this->Data[MonsterID].MaxY		= Y + Height;
	this->Data[MonsterID].Attribute	= 0;
}

void Interface::DrawGUI(short ObjectID, float PosX, float PosY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI2(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}

void Interface::DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}

void Interface::ResetDrawIMG(short ObjectID)
{
	if( this->Data[ObjectID].X != -1 || this->Data[ObjectID].Y != -1 )
	{
		this->Data[ObjectID].X		= -1;
		this->Data[ObjectID].Y		= -1;
		this->Data[ObjectID].MaxX	= -1;
		this->Data[ObjectID].MaxY	= -1;
	}
}



void Interface::Work()
{
	gObjUser.Refresh();

	jCRenderRuud.CheckOpen();
	
	if(gObjUser.lpViewPlayer->WeaponFirstSlot >= ITEM2(4,0) && gObjUser.lpViewPlayer->WeaponFirstSlot <= ITEM2(4,255)
		||gObjUser.lpViewPlayer->WeaponSecondSlot >= ITEM2(4,0) && gObjUser.lpViewPlayer->WeaponSecondSlot <= ITEM2(4,255))
	{
		gInterface.PetY = 38.0f;
		
	}
	else
	{
		gInterface.PetY = 26.0f;
	}

	if(gObjUser.lpViewPlayer->PetSlot!= -1)
	{
		gInterface.PetX = 61.0f;
	}else
	{
		gInterface.PetX = 0;
	}

	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{	gInterface.DrawInterfaceDragonLS3();
		gInterface.DrawInterfaceDragonRS3();
	}

	gInterface.DrawMiniMap();

	gInterface.DrawTimeUI();

	gCustomRanking.DrawRankPanelWindow();

	gCustomEventTime.DrawEventTimePanelWindow();
	
	ReconnectMainProc();

	gInterface.DrawVipWindow();

	gInterface.DrawMenu();

	gInterface.DrawMenuOpen();

	gCustomCommandInfo.DrawCommandWindow();

	gInterface.DrawConfirmOpen();

	gPartySearchSettings.draw_party_settings_window();

	gPartySearch.draw_party_search();

	gPartySearch.draw_party_password();

	gInterface.DrawStatsAddWindow();
	gInterface.DrawResetStatsWindow();

	gJewelsBank.Draw();


	gAchievements.Draw();
	g_ExWinQuestSystem.Draw();
	g_ExWinQuestSystem.DrawMiniInfo();

	gInterface.DrawEventTableWindow();

	gRanking.Draw();

	gInterface.DrawFruit();

	g_PersonalShopEx.Draw();

	gInterface.DrawChangingClassWindow();

	gInterface.PartyInterface();

	gInterface.DrawResetWindow();

	gInterface.DrawWarehouseWindow();

	gInterface.DrawSettingsUI();

	gInterface.WindowsKG();

//	gInterface.DrawCameraUI();

	gCamera.Init();

	if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		gInterface.DrawInterfaceCustom();
	}

	pDrawInterface();


	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{

		if (gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			gInterface.DrawInterface97Menu();
		}
		if (gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			gInterface.DrawInterfaceS2Menu();
		}
	}

	//gCRuudShop.RuudShop();

	gInterface.DrawLogo(0);
}

void Interface::WindowsKG(){
		char interaltas[500];
		if (gInterface.validar == 0)
		{
			if (gInterface.ultimo_Ping > 0){
				sprintf_s(interaltas, sizeof(interaltas), " %s || Player: %s", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name);
			}
			else{
				sprintf_s(interaltas, sizeof(interaltas), " %s || Player: %s", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name);
			}
			SetWindowText(pGameWindow, interaltas);
		}
}

void Interface::SwitchMiniMap()
{
	if((GetTickCount() - gInterface.Data[eNULL_MAP].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[eNULL_MAP].EventTick = GetTickCount();

	if (MiniMap != 0)
	{
		gInterface.DrawMessage(1, "MiniMap Window [OFF]");
		MiniMap = 0;
		WritePrivateProfileStringA("Graphics","MiniMap","0","./Settings.ini");
	}
	else 
	{
		gInterface.DrawMessage(1, "MiniMap Window [ON]");
		MiniMap = 1;
		WritePrivateProfileStringA("Graphics","MiniMap","1","./Settings.ini");
	}
}

void Interface::DrawTimeUI()
{
	if (!TimerBar)
	{
		return;
	}

	if (this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::FullMap) || this->CheckWindow(ObjWindow::ChatWindow) || this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::MoveList))
	{
		return;
	}
	// -----
	time_t TimeServer, TimeLocal;
	struct tm * ServerT, *LocalT;
	time(&TimeServer);
	time(&TimeLocal);
	// ----
	ServerT = gmtime(&TimeServer);
	char ServerTimeName[25] = "Server:";
	char ServerTime[30];
	sprintf(ServerTime, "%2d:%02d:%02d", (ServerT->tm_hour + GMT) % 24, ServerT->tm_min, ServerT->tm_sec);

	LocalT = localtime(&TimeLocal);
	char LocalTimeName[25] = "Local:";
	char LocalTime[30];
	sprintf(LocalTime, "%2d:%02d:%02d", LocalT->tm_hour, LocalT->tm_min, LocalT->tm_sec);

	this->DrawGUI(eTIME, this->Data[eTIME].X, this->Data[eTIME].Y);
	this->DrawFormat(eGold, 5, 390, 0, 1, ServerTimeName);
	this->DrawFormat(eWhite, 45, 390, 50, 1, ServerTime);
	this->DrawGUI(eTIME, this->Data[eTIME].X, 380);
	this->DrawFormat(eGold, 5, 412, 0, 1, LocalTimeName);
	this->DrawFormat(eWhite, 45, 412, 50, 1, LocalTime);
}

int Interface::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	int LineCount = 0;
	
	char * Line = strtok(Buff, "\n");
	
	while( Line != NULL )
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
	
	return PosY;
}

bool Interface::IsWorkZone2(float X, float Y, float MaxX, float MaxY)
{
	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX)
		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY))
	{
		return false;
	}
	// ----
	return true;
}

bool Interface::IsWorkZone(short ObjectID)
{
	if( (pCursorX < this->Data[ObjectID].X || pCursorX > this->Data[ObjectID].MaxX) || (pCursorY < this->Data[ObjectID].Y || pCursorY > this->Data[ObjectID].MaxY) )
		return false;

	return true;
}

float Interface::GetResizeX(short ObjectID)
{
	if( pWinWidth == 800 )
	{
		return this->Data[ObjectID].X + 16.0;
	}
	else if( pWinWidth != 1024 )
	{
		return this->Data[ObjectID].X - 16.0;
	}
	
	return this->Data[ObjectID].X;
}

int Interface::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	return pDrawToolTip(X, Y, Buff);
}

int Interface::DrawMessage(int Mode, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	return pDrawMessage(Buff, Mode);
}

void Interface::DrawVipWindow()
{

	if (!this->Data[eVip_MAIN].OnShow)
	{
		return;
	}

	if (gProtect.m_MainInfo.EnableVipShop != 1)
	{
		this->CloseVipWindow();
		return;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)))
	{
		CloseVipWindow();
		return;
	}

	// ----
	float MainWidth = 230.0;
	float MainHeight = 180.0;
	float StartBody = 50.0;
	float StartY = 50.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	// ----
	this->DrawGUI(eVip_MAIN, StartX, StartY + (float)2.0);
	this->DrawGUI(eVip_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eVip_FRAME, StartX, StartY + (float)15.0, 16);
	this->DrawGUI(eVip_FOOTER, StartX, StartY);
	this->DrawGUI(eVip_CLOSE, StartX + MainWidth - this->Data[eVip_CLOSE].Width, StartBody);
	// ----
	if (this->IsWorkZone(eVip_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eVip_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eVip_CLOSE, this->Data[eVip_CLOSE].X, StartBody, Color);
		this->DrawToolTip((int)this->Data[eVip_CLOSE].X + 5, StartBody + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(5));
	int LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 35, 210, 1, gCustomMessage.GetMessage(6), gObjUser.lpPlayer->Name);
	LineY = this->DrawFormat(eGold, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(14));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(7));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(8));
	// ----
	this->DrawGUI(eVip_DIV, StartX, StartBody + 70);
	this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 95 - 2, 210, 1, "Plan");
	this->DrawFormat(eGold, (int)StartX + 80, (int)StartBody + 95 - 2, 210, 1, "Exp");
	this->DrawFormat(eGold, (int)StartX + 130, (int)StartBody + 95 - 2, 210, 1, "Drop");
	this->DrawFormat(eGold, (int)StartX + 170, (int)StartBody + 95 - 2, 210, 1, "Time");
	// ----

	if (gProtect.m_MainInfo.VipTypes < 1 || gProtect.m_MainInfo.VipTypes > 3)
	{
		gProtect.m_MainInfo.VipTypes = 3;
	}

	for (int i = 0; i < (int)gProtect.m_MainInfo.VipTypes; i++)
	{
		this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 110 + (12 * i) - 5, 210, 1, gCustomBuyVip.m_CustomBuyVipInfo[i].VipName);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 80, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Exp);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 130, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Drop);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 170, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "%d day(s)", gCustomBuyVip.m_CustomBuyVipInfo[i].Days);

		pDrawGUI(0x7B5E, StartX + 30, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
		pDrawGUI(0x7B5E, StartX + 30 + 82, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
	}

	if (gProtect.m_MainInfo.VipTypes > 0)
	{
		// ---- bronze start 
		if (IsWorkZone(eVip_BRONZE))
		{
			if (this->Data[eVip_BRONZE].OnClick)
				this->DrawButton(eVip_BRONZE, StartX + 64, 220, 0, 58);
			else
				this->DrawButton(eVip_BRONZE, StartX + 64, 220, 0, 29);
			// ----
			this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
			this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin1);
			this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin2);
			this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin3);
		}
		else
			this->DrawButton(eVip_BRONZE, StartX + 64, 220, 0, 0);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 90, 220 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[0].VipName);
		// ---- bronze end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 1)
	{
		// ---- Silver start ------------------------------------
		if (IsWorkZone(eVip_SILVER))
		{
			if (this->Data[eVip_SILVER].OnClick)
				this->DrawButton(eVip_SILVER, StartX + 64, 250, 0, 58);
			else
				this->DrawButton(eVip_SILVER, StartX + 64, 250, 0, 29);
			// ----
			this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
			this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin1);
			this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin2);
			this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin3);
		}
		else
			this->DrawButton(eVip_SILVER, StartX + 64, 250, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 90, 250 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[1].VipName);
		// ---- silver end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 2)
	{
		// ---- gold start ------------------------------------
		if (IsWorkZone(eVip_GOLD))
		{
			if (this->Data[eVip_GOLD].OnClick)
				this->DrawButton(eVip_GOLD, StartX + 64, 280, 0, 58);
			else
				this->DrawButton(eVip_GOLD, StartX + 64, 280, 0, 29);
			// ----
			this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
			this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin1);
			this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin2);
			this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin3);
		}
		else
			this->DrawButton(eVip_GOLD, StartX + 64, 280, 0, 0);

		this->DrawFormat(eWhite, (int)StartX + 90, 280 + 9, 160, 1, gCustomMessage.GetMessage(9), gCustomBuyVip.m_CustomBuyVipInfo[2].VipName);
		// ---- gold end ------------------------------------
	}
}


bool Interface::EventVipWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_CLOSE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_CLOSE].EventTick = GetTickCount();
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Bronze(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_BRONZE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_BRONZE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_BRONZE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_BRONZE].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_BRONZE].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(1);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Silver(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_SILVER].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_SILVER))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 2)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_SILVER].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_SILVER].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_SILVER].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(2);
	this->CloseVipWindow();
	// ----
	return false;
}

// ----------------------------------------------------------------------------------------------
bool Interface::EventVipWindow_Gold(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_GOLD].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_GOLD))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 3)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_GOLD].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_GOLD].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_GOLD].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(3);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Main(DWORD Event)
{
	this->EventVipWindow_Close(Event);
	this->EventVipWindow_Bronze(Event);
	this->EventVipWindow_Silver(Event);
	this->EventVipWindow_Gold(Event);
	// ----
	return true;
}

float Interface::DrawRepeatGUI(short MonsterID, float X, float Y, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		pDrawGUI(this->Data[MonsterID].ModelID, X, StartY,
			this->Data[MonsterID].Width, this->Data[MonsterID].Height);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

float Interface::DrawRepeatGUIScale(short MonsterID, float X, float Y,float ScaleX, float ScaleY, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		this->DrawIMG(this->Data[MonsterID].ModelID, X, StartY,ScaleX,ScaleY);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

void Interface::DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= X;
		this->Data[ObjectID].Y		= Y;
		this->Data[ObjectID].MaxX	= X + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= Y + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y, 
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawLogo(bool active)
{
	if (gProtect.m_MainInfo.PrintLogo != 0)
	{

		if (active == 1)
		{
			this->Data[eLogo].EventTick = GetTickCount()+1500;
		}

		if (gInterface.Data[eLogo].EventTick > GetTickCount())
		{
			if (gProtect.m_MainInfo.PrintLogo == 1)
			{
				this->DrawGUI(eLogo, 10, 10);
			}

			if (gProtect.m_MainInfo.PrintLogo == 2)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, 10);

			}

			if (gProtect.m_MainInfo.PrintLogo == 3)
			{
				this->DrawGUI(eLogo, 10, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 4)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 5)
			{
				this->DrawGUI(eLogo, (MAX_WIN_WIDTH/2)-(150/2), (MAX_WIN_HEIGHT/2)-(114/2));
			}
		}
	}
}

void Interface::DrawMenu()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eMenu].OnShow)
	{
		this->Data[eMenu].OnShow = false;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store))
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Character))
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		CloseMenuWindow();
		return;
	}
	
	this->Data[eMenu].OnShow = true;
}

bool Interface::EventDrawMenu_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu].EventTick);
	// ----
	if (!this->Data[eMenu].OnShow || !IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
		this->Data[eMenu].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	
	// ----
	this->Data[eMenu].EventTick = GetTickCount();
	
	if (CheckMenuWindow())
	{
		CloseMenuWindow();
	}
	else
	{
		CloseCustomWindow();
		OpenMenuWindow();
	}
	// ----
	return false;
}

void Interface::DrawMenuOpen(){
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1){
		return;
	}
	if (!this->Data[eMenu_MAIN].OnShow){
		return;
	}
	float MainWidth, MainHeight;
	MainWidth = 230.0;
	MainHeight = 363.0;
	float StartBody = 30.0;
	float StartY = 30.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);

	this->DrawGUI(eMenu_MAIN, StartX, StartY + (float)2.0);
	this->DrawGUI(eMenu_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eMenu_FRAME, StartX, StartY + (float)150.0, 12);
	this->DrawGUI(eMenu_FOOTER, StartX, StartY);
	this->DrawGUI(eMenu_CLOSE, StartX + MainWidth - this->Data[eVip_CLOSE].Width, StartBody);
	if (this->IsWorkZone(eMenu_CLOSE)){
		DWORD Color = eGray100;
		if (this->Data[eMenu_CLOSE].OnClick){
			Color = eGray150;
		}
		this->DrawColoredGUI(eVip_CLOSE, this->Data[eMenu_CLOSE].X, StartBody, Color);
		this->DrawToolTip((int)this->Data[eMenu_CLOSE].X + 5, StartBody + 25, "Close");
	}
	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 195, 3, "System Menu");
	float startText1X, startText2X, startText3X, startCoin1X, startCoin2X, startCoin3X, startText1Y;
	startText1X = (int)StartX + 25;
	startText2X = (int)StartX + 90;
	startText3X = (int)StartX + 153;
	startCoin1X = (int)StartX + 50;
	startCoin2X = (int)StartX + 115;
	startCoin3X = (int)StartX + 176;
	startText1Y = (int)StartBody + 50;
	if (gProtect.m_MainInfo.EnableCoinStatus == 1){
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 35, 210, 3, gCustomMessage.GetMessage(50));
		this->DrawFormat(eWhite, startText1X, startText1Y, 40, 1, gCustomMessage.GetMessage(51));
		this->DrawFormat(eGold, startCoin1X, startText1Y, 40, 1, "%d", Coin1);
		this->DrawFormat(eWhite, startText2X, startText1Y, 40, 1, gCustomMessage.GetMessage(52));
		this->DrawFormat(eGold, startCoin2X, startText1Y, 40, 1, "%d", Coin2);
		this->DrawFormat(eWhite, startText3X, startText1Y, 40, 1, gCustomMessage.GetMessage(53));
		this->DrawFormat(eGold, startCoin3X, startText1Y, 40, 1, "%d", Coin3);
	}
	else{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 45, 210, 3, gCustomMessage.GetMessage(54));
	}
	int kg;
	kg = 75.0f;
	this->DrawGUI(eVip_DIV, StartX, StartBody + 60);
	int BtCount = 0;
	int BtStart = StartBody + kg;
	int BtDistance = 28;

	if (gProtect.m_MainInfo.EnableEventTimeButton == 1){
		BtCount++;
	}
	else{
		BtStart -= 27;
	}
	if (gProtect.m_MainInfo.EnableVipShopButton == 1){
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnableJewelBankButton == 1){
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnableAchievementsButton == 1){
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnableSettingsButton == 1){
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnablePartySettingsButton == 1){
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnableChangeClassButton == 1){
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnableFruitSystemButton == 1){
		BtCount++;
	}

	if (gProtect.m_MainInfo.EnableRankingButton == 1){
		BtCount++;
	}

	if (gProtect.m_MainInfo.EnableCommandButton == 1){
		BtCount++;
	}

	if (BtCount == 9){
		BtStart += -60;
	}

	if (BtCount == 8){
		BtStart += -45;
	}

	if (BtCount == 7){
		BtStart += -30;
	}
	if (BtCount == 6){
		BtStart += -15;
	}
	if (BtCount == 5){
		BtStart += 0;
	}
	if (BtCount == 4){
		BtStart += 15;
	}
	if (BtCount == 3){
		BtStart += 30;
	}
	if (BtCount == 2){
		BtStart += 45;
	}
	if (BtCount == 1){
		BtStart += 60;
	}

	//Horario eventos
	float eButtonOPX;
	eButtonOPX = StartX + 64;

	if (gProtect.m_MainInfo.EnableEventTimeButton == 1){
		if (IsWorkZone(eMenu_OPT1))
		{
			if (this->Data[eMenu_OPT1].OnClick)
				this->DrawButton(eMenu_OPT1, eButtonOPX, BtStart, 0, 58);
			else
				this->DrawButton(eMenu_OPT1, eButtonOPX, BtStart, 0, 29);
			// ----
		}
		else
			this->DrawButton(eMenu_OPT1, eButtonOPX, BtStart, 0, 0);

		this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, "Event Timer");
	}

	//Comprar vip
	if (gProtect.m_MainInfo.EnableVipShopButton == 1)
	{

		BtStart += BtDistance;

		if (IsWorkZone(eMenu_OPT2))
		{
			if (this->Data[eMenu_OPT2].OnClick)
				this->DrawButton(eMenu_OPT2, eButtonOPX, BtStart, 0, 58);
			else
				this->DrawButton(eMenu_OPT2, eButtonOPX, BtStart, 0, 29);
			// ----
		}
		else
			this->DrawButton(eMenu_OPT2, eButtonOPX, BtStart, 0, 0);

		this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, "Buy Vip");
	}

	//Ranking
	if (gProtect.m_MainInfo.EnableJewelBankButton == 1)
	{
		BtStart += BtDistance;

		if (IsWorkZone(eMenu_OPT3))
		{
			if (this->Data[eMenu_OPT3].OnClick)
				this->DrawButton(eMenu_OPT3, eButtonOPX, BtStart, 0, 58);
			else
				this->DrawButton(eMenu_OPT3, eButtonOPX, BtStart, 0, 29);
			// ----
		}
		else
			this->DrawButton(eMenu_OPT3, eButtonOPX, BtStart, 0, 0);

		this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, "Jewel Bank");
	}

	if (gProtect.m_MainInfo.EnableAchievementsButton == 1)
	{
		//Commandos
		BtStart += BtDistance;

		if (IsWorkZone(eMenu_OPT4))
		{
			if (this->Data[eMenu_OPT4].OnClick)
				this->DrawButton(eMenu_OPT4, eButtonOPX, BtStart, 0, 58);
			else
				this->DrawButton(eMenu_OPT4, eButtonOPX, BtStart, 0, 29);
			// ----
		}
		else
			this->DrawButton(eMenu_OPT4, eButtonOPX, BtStart, 0, 0);

		this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, "Achievements");
	}

	if (gProtect.m_MainInfo.EnableSettingsButton == 1)
	{
		//Smith Item
		BtStart += BtDistance;

		if (IsWorkZone(eMenu_OPT5))
		{
			if (this->Data[eMenu_OPT5].OnClick)
				this->DrawButton(eMenu_OPT5, eButtonOPX, BtStart, 0, 58);
			else
				this->DrawButton(eMenu_OPT5, eButtonOPX, BtStart, 0, 29);
			// ----
		}
		else
			this->DrawButton(eMenu_OPT5, eButtonOPX, BtStart, 0, 0);

			this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, "Settings");

	}

	if (gProtect.m_MainInfo.EnablePartySettingsButton == 1)
	{
		//LuckyWheel
		BtStart += BtDistance;

		if (IsWorkZone(eMenu_OPT6))
		{
			if (this->Data[eMenu_OPT6].OnClick)
				this->DrawButton(eMenu_OPT6, eButtonOPX, BtStart, 0, 58);
			else
				this->DrawButton(eMenu_OPT6, eButtonOPX, BtStart, 0, 29);
			// ----
		}
		else
			this->DrawButton(eMenu_OPT6, eButtonOPX, BtStart, 0, 0);

		this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, "Party Settings");
	}

	if (gProtect.m_MainInfo.EnableChangeClassButton == 1)
	{
		//Opçőes
		BtStart += BtDistance;

		if (IsWorkZone(eMenu_OPT20))
		{
			if (this->Data[eMenu_OPT20].OnClick)
				this->DrawButton(eMenu_OPT20, eButtonOPX, BtStart, 0, 58);
			else
				this->DrawButton(eMenu_OPT20, eButtonOPX, BtStart, 0, 29);
			// ----
		}
		else
			this->DrawButton(eMenu_OPT20, eButtonOPX, BtStart, 0, 0);

		this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, "Change Class");
	}
	if (gProtect.m_MainInfo.EnableFruitSystemButton == 1){
		BtStart += BtDistance;

		if (IsWorkZone(eMenu_OPT30))
		{
			if (this->Data[eMenu_OPT30].OnClick)
				this->DrawButton(eMenu_OPT30, eButtonOPX, BtStart, 0, 58);
			else
				this->DrawButton(eMenu_OPT30, eButtonOPX, BtStart, 0, 29);
			// ----
		}
		else
			this->DrawButton(eMenu_OPT30, eButtonOPX, BtStart, 0, 0);

		this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, "Fruit System");
	}

	if (gProtect.m_MainInfo.EnableRankingButton == 1){
		BtStart += BtDistance;

		if (IsWorkZone(eMenu_OPT7))
		{
			if (this->Data[eMenu_OPT7].OnClick)
				this->DrawButton(eMenu_OPT7, eButtonOPX, BtStart, 0, 58);
			else
				this->DrawButton(eMenu_OPT7, eButtonOPX, BtStart, 0, 29);
			// ----
		}
		else
			this->DrawButton(eMenu_OPT7, eButtonOPX, BtStart, 0, 0);

		this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, "Ranking");
	}

	if (gProtect.m_MainInfo.EnableCommandButton == 1){
		BtStart += BtDistance;

		if (IsWorkZone(eMenu_OPT8))
		{
			if (this->Data[eMenu_OPT8].OnClick)
				this->DrawButton(eMenu_OPT8, eButtonOPX, BtStart, 0, 58);
			else
				this->DrawButton(eMenu_OPT8, eButtonOPX, BtStart, 0, 29);
			// ----
		}
		else
			this->DrawButton(eMenu_OPT8, eButtonOPX, BtStart, 0, 0);

		this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, "Commands");
	}
}

bool Interface::EventDrawMenu_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_CLOSE].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_CLOSE].EventTick = GetTickCount();
	this->CloseMenuWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventDrawMenu_Op1(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT1].EventTick);
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT1)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		this->Data[eMenu_OPT1].OnClick = true;
		return true;
	}
	this->Data[eMenu_OPT1].OnClick = false;;
	if (Delay < 500){
		return false;
	}
	this->Data[eMenu_OPT1].EventTick = GetTickCount();
	this->CloseMenuWindow();
	gEventTimer.EventTimerSwitch();
	return false;
}

bool Interface::EventDrawMenu_Op2(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT2].EventTick);
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT2)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		this->Data[eMenu_OPT2].OnClick = true;
		return true;
	}
	this->Data[eMenu_OPT2].OnClick = false;;
	if (Delay < 500){
		return false;
	}
	this->Data[eMenu_OPT2].EventTick = GetTickCount();
	this->CloseCustomWindow();
	gInterface.OpenVipWindow();
	return false;
}

bool Interface::EventDrawMenu_Op3(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT3].EventTick);
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT3)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		this->Data[eMenu_OPT3].OnClick = true;
		return true;
	}
	this->Data[eMenu_OPT3].OnClick = false;;
	if (Delay < 500){
		return false;
	}
	this->Data[eMenu_OPT3].EventTick = GetTickCount();
	this->CloseMenuWindow();
	if (gJewelsBank.Active)
	{
		gJewelsBank.Active = false;
	}
	else
	{
		gJewelsBank.Active = true;
	}
	return false;
}

bool Interface::EventDrawMenu_Op4(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT4].EventTick);
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT4)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		this->Data[eMenu_OPT4].OnClick = true;
		return true;
	}
	this->Data[eMenu_OPT4].OnClick = false;;
	if (Delay < 500){
		return false;
	}
	this->Data[eMenu_OPT4].EventTick = GetTickCount();
	this->CloseMenuWindow();
	gAchievements.CGWindowOpen();
	return false;
}

bool Interface::EventDrawMenu_Op5(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT5].EventTick);
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT5)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		this->Data[eMenu_OPT5].OnClick = true;
		return true;
	}
	this->Data[eMenu_OPT5].OnClick = false;;
	if (Delay < 500){
		return false;
	}
	this->Data[eMenu_OPT5].EventTick = GetTickCount();
	this->CloseMenuWindow();
	gInterface.SwitchSettingsWindowState();
	return false;
}

bool Interface::EventDrawMenu_Op6(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT6].EventTick);
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT6)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		this->Data[eMenu_OPT6].OnClick = true;
		return true;
	}
	this->Data[eMenu_OPT6].OnClick = false;;
	if (Delay < 500){
		return false;
	}
	this->Data[eMenu_OPT6].EventTick = GetTickCount();
	this->CloseMenuWindow();
	gPartySearchSettings.party_search_settings_switch_state();
	return false;
}

bool Interface::EventDrawMenu_Op20(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT20].EventTick);
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT20)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		this->Data[eMenu_OPT20].OnClick = true;
		return true;
	}
	this->Data[eMenu_OPT20].OnClick = false;;
	if (Delay < 500){
		return false;
	}
	this->Data[eMenu_OPT20].EventTick = GetTickCount();
	this->CloseMenuWindow();
	gInterface.ChangingClassWindowState();
	return false;
}

bool Interface::EventDrawMenu_Op30(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT30].EventTick);
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT30)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		this->Data[eMenu_OPT30].OnClick = true;
		return true;
	}
	this->Data[eMenu_OPT30].OnClick = false;;
	if (Delay < 500){
		return false;
	}
	this->Data[eMenu_OPT30].EventTick = GetTickCount();
	this->CloseMenuWindow();
	gInterface.Fruit_State();
	return false;
}

bool Interface::EventDrawMenu_Op7(DWORD Event){
	USERBUTTON_REQ pRequest;
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT7].EventTick);
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT7)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		this->Data[eMenu_OPT7].OnClick = true;
		return true;
	}
	this->Data[eMenu_OPT7].OnClick = false;;
	if (Delay < 500){
		return false;
	}
	this->Data[eMenu_OPT7].EventTick = GetTickCount();
	this->CloseMenuWindow();
	pRequest.Head.set(0xFF, 0x21, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.Head.size);
	gRanking.Show = true;
	return false;
}

bool Interface::EventDrawMenu_Op8(DWORD Event){

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT8].EventTick);
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT8)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		this->Data[eMenu_OPT8].OnClick = true;
		return true;
	}
	this->Data[eMenu_OPT8].OnClick = false;;
	if (Delay < 500){
		return false;
	}
	this->Data[eMenu_OPT8].EventTick = GetTickCount();
	this->CloseMenuWindow();
	
	gCustomCommandInfo.OpenCommandWindow();
	return false;
}

bool Interface::MiniMapCheck()
{
	bool visual = false;

	if ( gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
    || gInterface.CheckWindow(8)
    || gInterface.CheckWindow(12)
    || gInterface.CheckWindow(9)
    || gInterface.CheckWindow(7)
    || gInterface.CheckWindow(14)
    || gInterface.CheckWindow(15)
    || gInterface.CheckWindow(60)
    || gInterface.CheckWindow(76) )
	{
		visual = true;
	}
	else
	{
		if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
		{
			visual = true;
		}
		else
		{
			if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
			{
				visual = true;
			}
			else
			{
				if ( gInterface.CheckWindow(27) )
				{
					visual = true;
				}
				else
				{
					if ( gInterface.CheckWindow(13)
					|| gInterface.CheckWindow(16)
					|| gInterface.CheckWindow(3)
					|| gInterface.CheckWindow(21)
					|| gInterface.CheckWindow(6)
					|| gInterface.CheckWindow(22)
					|| gInterface.CheckWindow(23)
					|| gInterface.CheckWindow(24)
					|| gInterface.CheckWindow(4)
					|| gInterface.CheckWindow(18)
					|| gInterface.CheckWindow(10)
					|| gInterface.CheckWindow(5)
					|| gInterface.CheckWindow(25)
					|| gInterface.CheckWindow(26)
					|| gInterface.CheckWindow(19)
					|| gInterface.CheckWindow(20)
					|| gInterface.CheckWindow(58)
					|| gInterface.CheckWindow(59)
					|| gInterface.CheckWindow(62)
					|| gInterface.CheckWindow(73)
					|| gInterface.CheckWindow(68)
					|| gInterface.CheckWindow(69)
					|| gInterface.CheckWindow(70)
					|| gInterface.CheckWindow(66)
					|| gInterface.CheckWindow(75)
					|| gInterface.CheckWindow(74) )
					{
						visual = true;
					}
					else
					{
						if ( gInterface.CheckWindow(79) )
						{
							if ( gInterface.CheckWindow(80) )
							{
								visual = true;
							}
							else
							{
								visual = true;
							}	
						}
					}
				}
			}
		}
	}
  
	if ( gInterface.CheckWindow(77) )
	{
		if ( gInterface.CheckWindow(Warehouse) ||
			gInterface.CheckWindow(ChaosBox) ||
			gInterface.CheckWindow(Store) ||
			gInterface.CheckWindow(OtherStore) ||
			gInterface.CheckWindow(Character))
		{
			visual = true;
		}
		else
		{
			visual = true;
		}
	}
	else if ( gInterface.CheckWindow(78) )
	{
			visual = true;
	}
	return visual;
}

bool Interface::CombinedChecks()
{
	if ((this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Character)
		&& this->CheckWindow(Store)))
		return true;
	return false;
}

bool Interface::CheckMap()
{
	switch(gObjUser.m_MapNumber)
	{
		case eMapNumber::Lorencia:
			return false;
			break;
		case eMapNumber::Dungeon:
			return false;
			break;
		case eMapNumber::Devias:
			return false;
			break;
		case eMapNumber::Noria:
			return false;
			break;
		case eMapNumber::LostTower:
			return false;
			break;
		case eMapNumber::Stadium:
			return false;
		case eMapNumber::Atlans:
			return false;
			break;
		case eMapNumber::Tarkan:
			return false;
			break;
		case eMapNumber::Elbeland:
			return false;
			break;
		case eMapNumber::Icarus:
			return false;
			break;
		case eMapNumber::Trials:
			return false;
			break;
		case eMapNumber::Aida:
			return false;
			break;
		case eMapNumber::Crywolf:
			return false;
			break;
		case eMapNumber::Kanturu1:
			return false;
			break;
		case eMapNumber::Kanturu3:
			return false;
			break;
		case eMapNumber::Barracks:
			return false;
			break;
		case eMapNumber::Calmness:
			return false;
			break;
		case eMapNumber::Raklion:
			return false;
			break;
		case eMapNumber::Vulcanus:
			return false;
			break;
		case eMapNumber::Karutan1:
			return false;
			break;
		case eMapNumber::Karutan2:
			return false;
			break;
		default:
			return true;
			break;
	}
}

void Interface::CloseCustomWindow()
{
	this->CloseMenuWindow();
	this->CloseVipWindow();
	this->Data[eRankPANEL_MAIN].OnShow		= false;
	this->Data[eEventTimePANEL_MAIN].OnShow = false;
	this->Data[eCommand_MAIN].OnShow		= false;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
}

void Interface::DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		return;
	}

	pSetBlend(true);
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	if (ItemID == 406)
	{
		sub_6358A0_Addr(0.4, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else if (ItemID == 407)
	{
		sub_6358A0_Addr(0.5, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else
	{
		sub_6358A0_Addr(0.7, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0); 
	sub_635DE0_Addr();
	sub_635E40_Addr();

	glClear(0x100);

	VAngle v45;

	unsigned __int8 v44 = 1; //0 = parado / 1 = girando

	sub_6359B0_Addr(PosX, PosY, (int)&v45, 0); //posiçăo do bmd
	sub_5CA0D0_Addr(ItemID, Level, Excl, Anc, (int)&v45, v44, 0); //funăo que mostra o BMD
	
	sub_636720_Addr();

	glMatrixMode(0x1700);
	glPopMatrix();
	glMatrixMode(0x1701);
	glPopMatrix();

	sub_637770_Addr();

	glColor3f(1,1,1);
	pSetBlend(false);
}

void Interface::DrawConfirmOpen()
{
	if(!this->CheckWindow(Shop) && this->Data[eCONFIRM_MAIN].OnShow == true)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_OK].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_CANCEL].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if( !this->Data[eCONFIRM_MAIN].OnShow )
	{
		return;
	}

	float StartX;
	if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		StartX = 205.0f;
	}
	else
	{
		StartX = 25.0f;
	}

	float MainWidth			= 230.0;
	float MainHeight		= 130.0;
	float StartBody			= 90.0;
	float StartY			= 90.0;
	
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(66));

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, gCustomMessage.GetMessage(67));

	this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, 0);

	if( this->IsWorkZone(eCONFIRM_BTN_OK) )
	{
		int ScaleY = 30;
		// ----
		if( this->Data[eCONFIRM_BTN_OK].OnClick )
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, ScaleY);
	}

	this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, 0);

	if( this->IsWorkZone(eCONFIRM_BTN_CANCEL) )
	{
		int ScaleY = 30;
		// ----
		if( this->Data[eCONFIRM_BTN_CANCEL].OnClick )
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, ScaleY);
	}

}


bool Interface::EventConfirm_OK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_OK].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_OK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_OK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].EventTick = GetTickCount();

	PMSG_ITEM_BUY_RECV pMsg;

	pMsg.header.set(0xF3, 0xED,sizeof(pMsg));

	pMsg.slot = this->ConfirmSlot;

	DataSend((BYTE*)&pMsg,pMsg.header.size);

	this->Data[eCONFIRM_MAIN].OnShow = false;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

bool Interface::EventConfirm_CANCEL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_CANCEL].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_CANCEL))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_CANCEL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].EventTick = GetTickCount();

	this->Data[eCONFIRM_MAIN].OnShow = false;

	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

//-- advance
void Interface::DrawBarForm(float PosX, float PosY, float Width, float Height, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(PosX, PosY, Width, Height, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}

void Interface::UPDATE_FPS(){
	gInterface.frameCount++;
	if (GetTickCount() - gInterface.lastReport >= 1000)
	{
		gInterface.frameRate = gInterface.frameCount / ((GetTickCount() - gInterface.lastReport) / 1000);
		sprintf(gInterface.FPS_REAL, "FPS: %d", gInterface.frameRate);
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop) )
	{
		return;
	}

	this->DrawFormat(eGold, 600, 5, 80, 1, gInterface.FPS_REAL);
}

void Interface::guiMonitore(){
	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(460.0, 0.0, 180.0, 20.0, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}

void Interface::DrawPing()
{
	gInterface.msPing = GetTickCount() - gInterface.lastSend;
	gInterface.iniciador = 3;
}

struct PMSG_PING
{
	PBMSG_HEAD h;
};

void Interface::SendPingRecv()
{
	if(gInterface.iniciador == 1)
	{
		PMSG_PING pMsgPing;
		pMsgPing.h.set(0x77,sizeof(pMsgPing));
		gInterface.lastSend = GetTickCount();
		DataSend((BYTE*)&pMsgPing,sizeof(pMsgPing));
		gInterface.iniciador=2;
	}
	else if(gInterface.iniciador == 3)
	{
		if (GetTickCount() >= gInterface.lastSend + 1000){
			PMSG_PING pMsgPing;
			pMsgPing.h.set(0x77,sizeof(pMsgPing));
			gInterface.lastSend = GetTickCount();
			DataSend((BYTE*)&pMsgPing,sizeof(pMsgPing));
			gInterface.iniciador=2;
		}
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	sprintf(gInterface.ServerRTT, "RTT: %d ms", gInterface.msPing);
	sprintf(gInterface.ServerPing, "PING: %d ms", (gInterface.msPing/2));
	// ----
	gInterface.validar=0;

	if(gInterface.msPing > 0){
		//----
		this->DrawFormat(eGold, 470, 5, 120, 1, gInterface.ServerRTT);
		this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ServerPing);
		//--
		sprintf(gInterface.ultimoRTT, gInterface.ServerRTT);
		sprintf(gInterface.ultimoPing, gInterface.ServerPing);
		//--
		gInterface.ultimo_RTT = gInterface.msPing;
		gInterface.validar=1;
	}

	if(gInterface.validar==0)
	{
		if(gInterface.ultimo_RTT > 0)
		{
			this->DrawFormat(eGold, 470, 5, 80, 1, gInterface.ultimoRTT);
			this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ultimoPing);
		}
		else
		{
			this->DrawFormat(eGold, 470, 5, 120, 1, gInterface.ServerRTT);
			this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ServerPing);
		}
	}
}

void Interface::SwitchChatExpand()
{

	if((GetTickCount() - gInterface.Data[chatbackground].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[chatbackground].EventTick = GetTickCount();

	if (SeparateChat != 0)
	{
		gInterface.DrawMessage(1, "Chat Window Separate [OFF]");
		SeparateChat = 0;
		WritePrivateProfileStringA("Setting","SeparateChat","0","./Settings.ini");
	}
	else 
	{
		gInterface.DrawMessage(1, "Chat Window Separate [ON]");
		SeparateChat = 1;
		WritePrivateProfileStringA("Setting","SeparateChat","1","./Settings.ini");
	}
	gChatExpanded.Switch();
}

void Interface::OpenConfig(int type)
{
	if(type == 0)
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 
			|| this->CheckWindow(ChatWindow) 
			|| this->CheckWindow(MuHelper) 
			|| this->CheckWindow(Inventory) 
			|| this->CheckWindow(Store) 
			|| this->CheckWindow(Character) 
			|| this->CheckWindow(CreateGuild) )
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (pCheckWindow(pWindowThis(), 35))
		{
			pCloseWindow(pWindowThis(), 35);
		}
		else 
		{
			pOpenWindow(pWindowThis(), 35);
		}
	}
	else if(type = 1 )
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 || OpenSwicthSkill == 0)
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (SkillPage == 1)
		{
			SkillPage = 2;
		}
		else
		{
			SkillPage = 1;
		}
	}

	PlayBuffer(25, 0, 0);
}
//-- SwitchCamera
void Interface::SwitchCamera()
{
	if( (GetTickCount() - gInterface.Data[eCamera3DSwitch].EventTick) < 1000 )
	{
		return;
	}

	if( pMapNumber == 62 )
	{
		gInterface.DrawMessage(1, "Camera3D not available for this map");
		gCamera.Reset();
	}

	gInterface.Data[eCamera3DSwitch].EventTick = GetTickCount();

	gCamera.Switch();

	if (gCamera.IsActive)
	{
		gInterface.DrawMessage(1, "Camera3D [ON]");
	}
	else
	{
		gInterface.DrawMessage(1, "Camera3D [OFF]");
	}
}
//-- CameraInit
void Interface::CameraInit(){

	if((GetTickCount() - gInterface.Data[eCamera3DInit].EventTick) < 1000 )
	{
		return;
	}

	gInterface.Data[eCamera3DInit].EventTick = GetTickCount();

	if (gCamera.IsActive)
	{
		gInterface.DrawMessage(1, "Camera Restore [DEFAULT]");
		gCamera.Reset();
	}
}

bool Interface::Button(DWORD Event, int WinID, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN  && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void Interface::DrawInterfaceS2Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
	if (IsWorkZone(eFastMenu))
	{
		this->DrawToolTip(13, 420, "System");
	}
	if (this->CheckWindow(FastMenu))
	{
		gInterface.DrawButton(eFastMenu, 6, 433, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::DrawInterface97Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::EventNewInterface_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eFastMenu))
	{
		DWORD Delay = (CurrentTick - this->Data[eFastMenu].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFastMenu].OnClick = true;
			return;
		}
		this->Data[eFastMenu].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFastMenu].EventTick = GetTickCount();
		if (this->CheckWindow(FastMenu)) {
				this->CloseWindow(FastMenu);
		}
		else {
			this->OpenWindow(FastMenu);
		}
	}
	else if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory)) {
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList)) {
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild)) {
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}
void Interface::EventNewInterface97_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory))
		{
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList))
		{
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild))
		{
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}

void Interface::DrawInterfaceDragonLS3()
{
	if(this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::FullMap)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::MoveList)
		)
	{
		return;
	}
	this->DrawGUI(eDragonLeft, this->Data[eDragonLeft].X, this->Data[eDragonLeft].Y);
}

void Interface::DrawInterfaceDragonRS3()
{	
	if (this->MiniMapCheck()||(this->CheckWindow(SkillTree)|| this->CheckWindow(CashShop) || this->CheckWindow(FullMap)
		||this->CheckWindow(FastMenu)||this->CheckWindow(FriendList))
		|| pMapNumber == 39 //Kanturu
		|| pMapNumber == 58 //Selupam
		|| pMapNumber == 64 //Duel Arena
		|| pMapNumber == 65 //Doppelganger
		|| pMapNumber == 66 //Doppelganger
		|| pMapNumber == 67 //Doppelganger
		|| pMapNumber == 68 //Doppelganger
		|| pMapNumber == 69 //Imperial Guardian
		|| pMapNumber == 70 //Imperial Guardian
		|| pMapNumber == 71 //Imperial Guardian
		|| pMapNumber == 72 //Imperial Guardian
		|| pMapNumber == 11	//Blood Castle
		|| pMapNumber == 12	//Blood Castle
		|| pMapNumber == 13	//Blood Castle
		|| pMapNumber == 14	//Blood Castle
		|| pMapNumber == 15	//Blood Castle
		|| pMapNumber == 16	//Blood Castle
		|| pMapNumber == 17	//Blood Castle
		|| pMapNumber == 52	//Blood Castle
		|| pMapNumber == 9	//Devil Square
		|| pMapNumber == 32	//Devil Square
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 45	//Illusion Temple
		|| pMapNumber == 46	//Illusion Temple
		|| pMapNumber == 47	//Illusion Temple
		|| pMapNumber == 48	//Illusion Temple
		|| pMapNumber == 49	//Illusion Temple
		|| pMapNumber == 50	//Illusion Temple
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 34 //Crywolf
		|| pMapNumber == 30 //Valley/CastleSiege
		|| pMapNumber == 65 /*DuelArena*/)
	{
		return;
	}
	this->DrawGUI(eDragonRight, this->Data[eDragonRight].X, this->Data[eDragonRight].Y);
}

void Interface::DrawCoord()
{
	gObjUser.Refresh();

	if (*(DWORD*)MAIN_SCREEN_STATE == 5)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		pDrawInterfaceNumBer(22, 461, gObjUser.lpViewPlayer->MapPosX, 1);
		pDrawInterfaceNumBer(46, 461, gObjUser.lpViewPlayer->MapPosY, 1);

	}
}

void Interface::DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...) // OK
{
	char Buff[2048];
	const int BuffLen = sizeof(Buff) - 1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	char * Line = strtok(Buff, "\n");

	while (Line != nullptr)
	{
		DrawInterfaceText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
}

void Interface::DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY, Color);
}

int Interface::DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	char Buff2[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----

	int LineCount = 0;

	strcpy(Buff2, Buff);

	char* Line = strtok(Buff2, "\n");
	// ----
	while (Line != NULL)
	{
		LineCount++;
		Line = strtok(NULL, "\n");
	}

	pSetBlend(1);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	pDrawBarForm(PosX, PosY, Width, LineCount * 10, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);

	this->DrawText(eWhite, PosX, PosY, Width, Align, Buff);
	return 0;
}


void Interface::DrawStatsAddWindow()
{
	if (!this->Data[eSTATSADD_MAIN].OnShow)
	{
		return;
	}

	int ObjectCount = 4;
	if ((gObjUser.lpPlayer->Class & 7) == 4)
	{
		ObjectCount = 5;
	}
	char szCharNames[5][32];
	memcpy(szCharNames[0], gCustomMessage.GetMessage(142), sizeof(szCharNames[0]));
	memcpy(szCharNames[1], gCustomMessage.GetMessage(143), sizeof(szCharNames[1]));
	memcpy(szCharNames[2], gCustomMessage.GetMessage(144), sizeof(szCharNames[2]));
	memcpy(szCharNames[3], gCustomMessage.GetMessage(145), sizeof(szCharNames[3]));
	memcpy(szCharNames[4], gCustomMessage.GetMessage(146), sizeof(szCharNames[4]));
	/*
	char szCharNames[5][32] =
	{
	"Strength:",
	"Agility:",
	"Vitality:",
	"Energy:",
	"Command:",
	};
	*/
	int ObjectIDs[5] =
	{
		eSTATSADD_STATBOX01,
		eSTATSADD_STATBOX02,
		eSTATSADD_STATBOX03,
		eSTATSADD_STATBOX04,
		eSTATSADD_STATBOX05,
	};

	if (this->Data[eSTATSADD_MAIN].ByClose == false)
	{
		if (this->Data[eSTATSADD_MAIN].OpenedValue < 0)
		{
			this->Data[eSTATSADD_MAIN].OpenedValue += this->Data[eSTATSADD_MAIN].Speed;

			if (this->Data[eSTATSADD_MAIN].OpenedValue >= -150)
			{
				this->Data[eSTATSADD_MAIN].Speed = 15;
			}

			if (this->Data[eSTATSADD_MAIN].OpenedValue > 0)
			{
				this->Data[eSTATSADD_MAIN].OpenedValue = 0;
			}
		}
	}
	else
	{
		if (this->Data[eSTATSADD_MAIN].OpenedValue > -226)
		{
			this->Data[eSTATSADD_MAIN].OpenedValue -= this->Data[eSTATSADD_MAIN].Speed;

			if (this->Data[eSTATSADD_MAIN].OpenedValue <= -150)
			{
				this->Data[eSTATSADD_MAIN].Speed = 20;
			}

			if (this->Data[eSTATSADD_MAIN].OpenedValue <= -226)
			{
				//this->Data[eSTATSADD_MAIN].OpenedValue = 100;
				this->Data[eSTATSADD_MAIN].Close();
				/*
				this->Data[eSTATSADD_STEP10].Attribute = 0;
				this->Data[eSTATSADD_STEP100].Attribute = 0;
				this->Data[eSTATSADD_STEP1000].Attribute = 0;
				*/
				for (int i = 0; i<ObjectCount; i++)
				{
					this->Data[ObjectIDs[i]].Attribute = false;
				}
			}
		}
	}

	float MainWidth = 230.0;
	float StartY = 198;
	float StartX = this->Data[eSTATSADD_MAIN].OpenedValue;
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);

	pSetCursorFocus = true;
	// ----
	this->DrawAnimatedGUI(eSTATSADD_MAIN, StartX, StartY + 2);
	this->DrawAnimatedGUI(eSTATSADD_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eSTATSADD_FRAME, StartX, StartY + 67.0, 8);
	this->DrawAnimatedGUI(eSTATSADD_FOOTER, StartX, StartY);
	this->DrawAnimatedGUI(eSTATSADD_CLOSE, StartX + MainWidth - this->Data[eSTATSADD_CLOSE].Width, this->Data[eSTATSADD_MAIN].Y - 2);
	// ----

	// ----
	if (this->IsWorkZone(eSTATSADD_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eSTATSADD_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eSTATSADD_CLOSE, this->Data[eSTATSADD_CLOSE].X, this->Data[eSTATSADD_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eSTATSADD_CLOSE].X + 5, this->Data[eSTATSADD_CLOSE].Y + 25, gCustomMessage.GetMessage(14));
	}
	// ----
	DWORD StatPoints = ViewPoint;

	for (int i = 0; i<ObjectCount; i++)
	{
		StatPoints -= atoi(this->Data[ObjectIDs[i]].StatValue);
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, this->Data[eSTATSADD_MAIN].Y + 8, 210, 3, gCustomMessage.GetMessage(127));

	this->DrawAnimatedGUI(eSTATSADD_TEXTBOX01, ButtonX - 35, this->Data[eSTATSADD_MAIN].Y + 28);
	this->DrawFormat(eWhite, StartX - 40, this->Data[eSTATSADD_MAIN].Y + 34, 210, 3, gCustomMessage.GetMessage(128));

	char Value[50];
	ZeroMemory(Value, sizeof(Value));
	pGetMoneyFormat((double)StatPoints, Value, 0);
	GetFormat(Value, ',', ' ');

	////console.Log("", "Point %d Value %s",StatPoints,Value);

	this->DrawFormat(eWhite, StartX + 45, this->Data[eSTATSADD_MAIN].Y + 34, 210, 3, "%s", Value);

	this->DrawFormat(eWhite, StartX + 10, this->Data[eSTATSADD_MAIN].Y + 55, 210, 3, gCustomMessage.GetMessage(129));
	/*
	this->DrawFormat(eWhite, StartX + 30, this->Data[eSTATSADD_MAIN].Y + 69, 30, 3, "Step value:");

	this->DrawFormat(eWhite, StartX + 80, this->Data[eSTATSADD_MAIN].Y + 70, 10, 3, "10");
	this->DrawFormat(eWhite, StartX + 120, this->Data[eSTATSADD_MAIN].Y + 70, 15, 3, "100");
	this->DrawFormat(eWhite, StartX + 162, this->Data[eSTATSADD_MAIN].Y + 70, 20, 3, "1000");

	if (this->Data[eSTATSADD_STEP10].Attribute == true)
	{
	this->DrawAnimatedButton(eSTATSADD_STEP10, StartX + 90, this->Data[eSTATSADD_MAIN].Y + 66, 0, 15);
	}
	else
	{
	this->DrawAnimatedButton(eSTATSADD_STEP10, StartX + 90, this->Data[eSTATSADD_MAIN].Y + 66, 0, 0);
	}

	if (this->Data[eSTATSADD_STEP100].Attribute == true)
	{
	this->DrawAnimatedButton(eSTATSADD_STEP100, StartX + 135, this->Data[eSTATSADD_MAIN].Y + 66, 0, 15);
	}
	else
	{
	this->DrawAnimatedButton(eSTATSADD_STEP100, StartX + 135, this->Data[eSTATSADD_MAIN].Y + 66, 0, 0);
	}

	if (this->Data[eSTATSADD_STEP1000].Attribute == true)
	{
	this->DrawAnimatedButton(eSTATSADD_STEP1000, StartX + 180, this->Data[eSTATSADD_MAIN].Y + 66, 0, 15);
	}
	else
	{
	this->DrawAnimatedButton(eSTATSADD_STEP1000, StartX + 180, this->Data[eSTATSADD_MAIN].Y + 66, 0, 0);
	}*/

	if (this->Data[eSTATSADD_MAIN].FirstLoad == true)
	{
		this->Data[eSTATSADD_STATBOX01].Attribute = 1;
	}

	for (int i = 0; i<ObjectCount; i++)
	{
		if (this->Data[eSTATSADD_MAIN].FirstLoad == true)
		{
			sprintf(this->Data[ObjectIDs[i]].StatValue, "0");
		}
		this->DrawAnimatedGUI(ObjectIDs[i], ButtonX - 35, this->Data[eSTATSADD_MAIN].Y + 63 + ((i + 1) * 21));
		this->DrawFormat(eWhite, StartX - 38, this->Data[eSTATSADD_MAIN].Y + 69 + ((i + 1) * 21), 210, 3, szCharNames[i]);
		this->DrawFormat(eWhite, StartX + 45, this->Data[eSTATSADD_MAIN].Y + 69 + ((i + 1) * 21), 210, 3, this->Data[ObjectIDs[i]].StatValue);
	}

	for (int i = 0; i<ObjectCount; i++)
	{
		if (this->Data[ObjectIDs[i]].Attribute == 1)
		{
			DWORD Color = eGray100;
			this->DrawColoredAnimatedGUI(ObjectIDs[i], ButtonX - 35, this->Data[eSTATSADD_MAIN].Y + 63 + ((i + 1) * 21), Color);
		}
	}

	this->DrawAnimatedButton(eSTATSADD_BTN_OK, StartX + 85, this->Data[eSTATSADD_MAIN].Y + 194, 0, 0);

	if (this->IsWorkZone(eSTATSADD_BTN_OK))
	{
		int ScaleY = 30;
		// ----
		if (this->Data[eSTATSADD_BTN_OK].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		this->DrawAnimatedButton(eSTATSADD_BTN_OK, StartX + 85, this->Data[eSTATSADD_MAIN].Y + 194, 0, ScaleY);
	}

	//login_me
	//newui_button_cancel
	//newui_button_ok
	if (this->Data[eSTATSADD_MAIN].FirstLoad == true)
	{
		this->Data[eSTATSADD_MAIN].FirstLoad = false;
	}
}
// ----------------------------------------------------------------------------------------------

void Interface::EventStatsAddWindow(DWORD Event)
{
	this->EventStatsAddWindow_Close(Event);
}

void Interface::EventStatsAddWindow_Close(DWORD Event)
{
	if (!this->Data[eSTATSADD_MAIN].OnShow)
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();

	int ObjectIDs[5] =
	{
		eSTATSADD_STATBOX01,
		eSTATSADD_STATBOX02,
		eSTATSADD_STATBOX03,
		eSTATSADD_STATBOX04,
		eSTATSADD_STATBOX05,
	};

	int ObjectCount = 4;
	if ((gObjUser.lpPlayer->Class & 7) == 4)
	{
		ObjectCount = 5;
	}

	for (int i = 0; i<ObjectCount; i++)
	{
		if (IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();

			for (int j = 0; j<ObjectCount; j++)
			{
				this->Data[ObjectIDs[j]].Attribute = 0;
			}

			this->Data[ObjectIDs[i]].Attribute = 1;
		}
	}

	for (int i = 5; i<5; i++)
	{
		if (IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();

			for (int j = 5; j<8; j++)
			{
				this->Data[ObjectIDs[j]].Attribute = 0;
			}

			this->Data[ObjectIDs[i]].Attribute = 1;
		}
	}


	if (IsWorkZone(eSTATSADD_BTN_OK))
	{
		DWORD Delay = (CurrentTick - this->Data[eSTATSADD_BTN_OK].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSTATSADD_BTN_OK].OnClick = true;
			return;
		}
		// ----
		this->Data[eSTATSADD_BTN_OK].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eSTATSADD_BTN_OK].EventTick = GetTickCount();
		Data[eSTATSADD_MAIN].CloseAnimated(15);
		PMSG_UPDATE_STATS_SEND pMsg;
		pMsg.Str = atoi(this->Data[eSTATSADD_STATBOX01].StatValue);
		pMsg.Agi = atoi(this->Data[eSTATSADD_STATBOX02].StatValue);
		pMsg.Vit = atoi(this->Data[eSTATSADD_STATBOX03].StatValue);
		pMsg.Ene = atoi(this->Data[eSTATSADD_STATBOX04].StatValue);
		pMsg.Com = 0;
		if (ObjectCount == 5)
		{
			pMsg.Com = atoi(this->Data[eSTATSADD_STATBOX05].StatValue);
		}
		CGSendStatsAdd(pMsg);
	}

	if (IsWorkZone(eSTATSADD_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eSTATSADD_CLOSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSTATSADD_CLOSE].OnClick = true;
			return;
		}
		// ----
		this->Data[eSTATSADD_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eSTATSADD_CLOSE].EventTick = GetTickCount();
		Data[eSTATSADD_MAIN].CloseAnimated(15);
	}

	// ----
	return;
}

// ----------------------------------------------------------------------------------------------
void Interface::EventCharacterWindow(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	//DWORD Delay			= (CurrentTick - this->Data[eCHARINFO_BTN_STAT].EventTick);
	// ----
	if (!this->CheckWindow(Character))
	{
		return;
	}
	// ----
	if (IsWorkZone(eCHARINFO_BTN_STAT))
	{
		//if (gConfig.GetCustomState(CUSTOM_STATSADD) == 0)
		//{
		//	return;
		//}
		DWORD Delay = (CurrentTick - this->Data[eCHARINFO_BTN_STAT].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHARINFO_BTN_STAT].OnClick = true;
			return;
		}
		// ----
		this->Data[eCHARINFO_BTN_STAT].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHARINFO_BTN_STAT].EventTick = GetTickCount();
		this->SwitchStatsWindowState();
		////console.Log("", "AddStat switchstate");
	}

	if (IsWorkZone(eCHARINFO_BTN_RESSTAT))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHARINFO_BTN_RESSTAT].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHARINFO_BTN_RESSTAT].OnClick = true;
			return;
		}
		// ----
		this->Data[eCHARINFO_BTN_RESSTAT].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHARINFO_BTN_RESSTAT].EventTick = GetTickCount();
		this->SwitchResetStatsWindowState();
	}
	//if( !this->CheckWindow(Character) || !IsWorkZone(eCHARINFO_BTN_STAT) )
	//{
	//	return;
	//}
	//// ----
	//if( Event == WM_LBUTTONDOWN )
	//{
	//	this->Data[eCHARINFO_BTN_STAT].OnClick = true;
	//	return;
	//}
	//// ----
	//this->Data[eCHARINFO_BTN_STAT].OnClick = false;
	//// ----
	//if( Delay < 500 )
	//{
	//	return;
	//}
	//// ----
	//this->Data[eCHARINFO_BTN_STAT].EventTick = GetTickCount();
	//this->SwitchStatsWindowState();
}

void Interface::DrawResetStatsWindow()
{
	if (!this->Data[eRESETSTATS_MAIN].OnShow)
	{
		return;
	}
	// ----
	float MainWidth = 230.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);

	pSetCursorFocus = true;
	// ----

	this->DrawGUI(eRESETSTATS_MAIN, StartX, StartY + 2);
	this->DrawGUI(eRESETSTATS_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eRESETSTATS_FRAME, StartX, StartY + 67.0, 2);
	this->DrawGUI(eRESETSTATS_FOOTER, StartX, StartY);
	this->DrawGUI(eRESETSTATS_CLOSE, StartX + MainWidth - this->Data[eRESETSTATS_CLOSE].Width, this->Data[eRESETSTATS_TITLE].Height + this->Data[eRESETSTATS_CLOSE].Height + 2);

	// ----
	if (this->IsWorkZone(eRESETSTATS_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eRESETSTATS_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eRESETSTATS_CLOSE, this->Data[eRESETSTATS_CLOSE].X, this->Data[eRESETSTATS_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eRESETSTATS_CLOSE].X + 5, this->Data[eRESETSTATS_CLOSE].Y + 25, gCustomMessage.GetMessage(14));
	}
	// ----

	int x = GetPrivateProfileIntA("Custom", "X", -35, "./Settings.ini");
	int y = GetPrivateProfileIntA("Custom", "Y", 60, "./Settings.ini");

	int StatPoints = ViewStrength + ViewDexterity + ViewVitality + ViewEnergy + ViewLeadership;

	StatPoints -= (gObjUser.d_Strength + gObjUser.d_Dexterity + gObjUser.d_Vitality + gObjUser.d_Energy + gObjUser.d_Leadership);

	/*
	if (this->Data[eRESETSTATS_CHECK_STAT].Attribute == true)
	{
	StatPoints -= gObjUser.m_CustomResetPointPriceZen(ViewAccountLevel);
	if (StatPoints < 0)
	{
	StatPoints = 0;
	}
	}
	*/

	this->DrawFormat(eGold, StartX + 10, 110, 210, 3, gCustomMessage.GetMessage(122));
	//Reset Point
	if (this->m_ResetPointCheckBox == 1)
	{
		this->DrawGUI(eRESETSTATS_POINT, StartX + 25, this->Data[eRESETSTATS_MAIN].Y + 33); // Point
		this->DrawFormat(eWhite, StartX + 40, this->Data[eRESETSTATS_MAIN].Y + 34, 100, 1, gCustomMessage.GetMessage(123), gObjUser.GetResetPointPriceWC(ViewAccountLevel)); // Text
		pDrawGUI(0x7B5E, StartX + 30, this->Data[eRESETSTATS_MAIN].Y + 45, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
		pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eRESETSTATS_MAIN].Y + 45, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2
	}
	if (this->m_ResetPointCheckBox1 == 1)
	{
		this->DrawGUI(eRESETSTATS_POINT, StartX + 25, this->Data[eRESETSTATS_MAIN].Y + 53); // Point
		this->DrawFormat(eWhite, StartX + 40, this->Data[eRESETSTATS_MAIN].Y + 54, 100, 1, gCustomMessage.GetMessage(124), gObjUser.GetResetPointPriceZen(ViewAccountLevel)); // Text
		pDrawGUI(0x7B5E, StartX + 30, this->Data[eRESETSTATS_MAIN].Y + 65, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
		pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eRESETSTATS_MAIN].Y + 65, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2
	}
	if (this->m_ResetMasterSkillCheckBox == 1)
	{
		//Master Point Reset
		this->DrawGUI(eRESETSTATS_POINT, StartX + 25, this->Data[eRESETSTATS_MAIN].Y + 73); // Point
		this->DrawFormat(eWhite, StartX + 40, this->Data[eRESETSTATS_MAIN].Y + 74, 115, 1, gCustomMessage.GetMessage(125), gObjUser.GetResetMasterSkillPriceWC(ViewAccountLevel)); // Text
		pDrawGUI(0x7B5E, StartX + 30, this->Data[eRESETSTATS_MAIN].Y + 85, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
		pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eRESETSTATS_MAIN].Y + 85, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2
	}
	if (this->m_ResetMasterSkillCheckBox1 == 1)
	{
		this->DrawGUI(eRESETSTATS_POINT, StartX + 25, this->Data[eRESETSTATS_MAIN].Y + 93); // Point
		this->DrawFormat(eWhite, StartX + 40, this->Data[eRESETSTATS_MAIN].Y + 94, 115, 1, gCustomMessage.GetMessage(126), gObjUser.GetResetMasterSkillPriceZen(ViewAccountLevel)); // Text
		pDrawGUI(0x7B5E, StartX + 30, this->Data[eRESETSTATS_MAIN].Y + 105, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
		pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eRESETSTATS_MAIN].Y + 105, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2
	}
	if (this->m_ResetPointCheckBox == 1)
	{
		//Reset Point
		if (this->Data[eRESETSTATS_CHECK_WC].Attribute == true)
		{
			this->DrawButton(eRESETSTATS_CHECK_WC, 385, 132, 0, 15);
		}
		else
		{
			this->DrawButton(eRESETSTATS_CHECK_WC, 385, 132, 0, 0);
		}
	}
	if (this->m_ResetPointCheckBox1 == 1)
	{
		if (this->Data[eRESETSTATS_CHECK_STAT].Attribute == true)
		{
			this->DrawButton(eRESETSTATS_CHECK_STAT, 385, 152, 0, 15);
		}
		else
		{
			this->DrawButton(eRESETSTATS_CHECK_STAT, 385, 152, 0, 0);
		}
	}

	//this->DrawFormat(eYellow, StartX + 50, this->Data[eRESETSTATS_MAIN].Y + 75, 45, 3, "Reward Points:");
	//pDrawGUI(0x7895, StartX + 120, this->Data[eRESETSTATS_MAIN].Y + 71.5, 50, 16);
	//this->DrawFormat(eWhite, StartX + 110, this->Data[eRESETSTATS_MAIN].Y + 75, 50, 3, "%d", StatPoints);
	if (this->m_ResetMasterSkillCheckBox == 1)
	{
		//Master Point Reset
		if (this->Data[eRESETMASTER_CHECK_WC].Attribute == true)
		{
			this->DrawButton(eRESETMASTER_CHECK_WC, 385, 172, 0, 15);
		}
		else
		{
			this->DrawButton(eRESETMASTER_CHECK_WC, 385, 172, 0, 0);
		}
	}
	if (this->m_ResetMasterSkillCheckBox1 == 1)
	{
		if (this->Data[eRESETMASTER_CHECK_STAT].Attribute == true)
		{
			this->DrawButton(eRESETMASTER_CHECK_STAT, 385, 192, 0, 15);
		}
		else
		{
			this->DrawButton(eRESETMASTER_CHECK_STAT, 385, 192, 0, 0);
		}
	}
	this->Data[eRESETSTATS_BTN_OK].Attribute = false;

	if (this->Data[eRESETSTATS_CHECK_WC].Attribute || this->Data[eRESETSTATS_CHECK_STAT].Attribute || this->Data[eRESETMASTER_CHECK_WC].Attribute || this->Data[eRESETMASTER_CHECK_STAT].Attribute)
	{
		this->DrawButton(eRESETSTATS_BTN_OK, StartX + 85, this->Data[eRESETSTATS_MAIN].Y + 108, 0, 0);

		if (this->IsWorkZone(eRESETSTATS_BTN_OK))
		{
			int ScaleY = 30;
			// ----
			if (this->Data[eRESETSTATS_BTN_OK].OnClick)
			{
				ScaleY = 60;
			}
			// ----
			this->DrawButton(eRESETSTATS_BTN_OK, StartX + 85, this->Data[eRESETSTATS_MAIN].Y + 108, 0, ScaleY);
		}
		this->Data[eRESETSTATS_BTN_OK].Attribute = true;
	}
}

void Interface::EventResetStatsWindow(DWORD Event)
{
	if (!this->Data[eRESETSTATS_MAIN].OnShow)
	{
		return;
	}

	this->EventResetStatsWindow_Close(Event);

	int eObjectIDs[4] =
	{
		eRESETSTATS_CHECK_WC,
		eRESETSTATS_CHECK_STAT,
		eRESETMASTER_CHECK_WC,
		eRESETMASTER_CHECK_STAT,
	};

	DWORD CurrentTick = GetTickCount();

	for (int i = 0; i<4; i++)
	{
		DWORD Delay = (CurrentTick - this->Data[eObjectIDs[i]].EventTick);
		// ----
		if (!IsWorkZone(eObjectIDs[i]))
		{
			continue;
		}
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eObjectIDs[i]].OnClick = true;
			break;;
		}
		// ----
		this->Data[eObjectIDs[i]].OnClick = false;
		// ----
		if (Delay < 500)
		{
			break;
		}
		// ----
		this->Data[eObjectIDs[i]].EventTick = GetTickCount();
		if (this->m_ResetPointCheckBox == 1)
		{
			if (eObjectIDs[i] == eRESETSTATS_CHECK_WC)
			{
				this->Data[eRESETSTATS_CHECK_WC].Attribute = 1;
				this->Data[eRESETSTATS_CHECK_STAT].Attribute = 0;
				this->Data[eRESETMASTER_CHECK_WC].Attribute = 0;
				this->Data[eRESETMASTER_CHECK_STAT].Attribute = 0;
			}
		}
		if (this->m_ResetPointCheckBox1 == 1)
		{
			if (eObjectIDs[i] == eRESETSTATS_CHECK_STAT)
			{
				this->Data[eRESETSTATS_CHECK_STAT].Attribute = 1;
				this->Data[eRESETSTATS_CHECK_WC].Attribute = 0;
				this->Data[eRESETMASTER_CHECK_WC].Attribute = 0;
				this->Data[eRESETMASTER_CHECK_STAT].Attribute = 0;
			}
		}
		if (this->m_ResetMasterSkillCheckBox == 1)
		{
			//Reset Master Point
			if (eObjectIDs[i] == eRESETMASTER_CHECK_WC)
			{
				this->Data[eRESETMASTER_CHECK_WC].Attribute = 1;
				this->Data[eRESETMASTER_CHECK_STAT].Attribute = 0;
				this->Data[eRESETSTATS_CHECK_WC].Attribute = 0;
				this->Data[eRESETSTATS_CHECK_STAT].Attribute = 0;
			}
		}
		if (this->m_ResetMasterSkillCheckBox1 == 1)
		{
			if (eObjectIDs[i] == eRESETMASTER_CHECK_STAT)
			{
				this->Data[eRESETMASTER_CHECK_STAT].Attribute = 1;
				this->Data[eRESETMASTER_CHECK_WC].Attribute = 0;
				this->Data[eRESETSTATS_CHECK_WC].Attribute = 0;
				this->Data[eRESETSTATS_CHECK_STAT].Attribute = 0;
			}
		}
	}

	DWORD Delay = (CurrentTick - this->Data[eRESETSTATS_BTN_OK].EventTick);
	// ----
	if (!IsWorkZone(eRESETSTATS_BTN_OK) || !this->Data[eRESETSTATS_BTN_OK].Attribute)
	{
		return;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eRESETSTATS_BTN_OK].OnClick = true;
		return;
	}
	// ----
	this->Data[eRESETSTATS_BTN_OK].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return;
	}
	// ----
	this->Data[eRESETSTATS_BTN_OK].EventTick = GetTickCount();
	if (this->m_ResetPointCheckBox == 1)
	{
		//Reset Point
		if (this->Data[eRESETSTATS_CHECK_WC].Attribute == true)
		{
			CGSendResetStats(0);
		}
	}
	if (this->m_ResetPointCheckBox1 == 1)
	{
		if (this->Data[eRESETSTATS_CHECK_STAT].Attribute == true)
		{
			CGSendResetStats(1);
		}
	}
	if (this->m_ResetMasterSkillCheckBox == 1)
	{
		//Reset Master Skill
		if (this->Data[eRESETMASTER_CHECK_WC].Attribute == true)
		{
			CGSendResetStats(2);
		}
	}
	if (this->m_ResetMasterSkillCheckBox1 == 1)
	{
		if (this->Data[eRESETMASTER_CHECK_STAT].Attribute == true)
		{
			CGSendResetStats(3);
		}
	}
	this->SwitchResetStatsWindowState();
}

void Interface::EventResetStatsWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eRESETSTATS_CLOSE].EventTick);
	// ----
	if (!this->Data[eRESETSTATS_MAIN].OnShow || !IsWorkZone(eRESETSTATS_CLOSE))
	{
		return;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eRESETSTATS_CLOSE].OnClick = true;
		return;
	}
	// ----
	this->Data[eRESETSTATS_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return;
	}
	// ----
	this->Data[eRESETSTATS_CLOSE].EventTick = GetTickCount();
	this->SwitchResetStatsWindowState();

}

void Interface::DrawAnimatedGUI(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawColoredAnimatedGUI(short ObjectID, float X, float Y, DWORD Color)
{
	//if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	//{
	this->Data[ObjectID].X = X;
	this->Data[ObjectID].Y = Y;
	this->Data[ObjectID].MaxX = X + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = Y + this->Data[ObjectID].Height;
	//}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawAnimatedButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	//if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	//{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	//}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text)
{
	float StartY = Y;
	float StartX = X;

	gInterface.DrawGUI(ObjMain, StartX, StartY + 2);
	gInterface.DrawGUI(ObjTitle, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(ObjFrame, StartX, StartY + 67.0, Repeat);
	gInterface.DrawGUI(ObjFooter, StartX, StartY);

	gInterface.DrawFormat(eGold, StartX + 10, Y + 10, 210, 3, Text);
}

bool Interface::ButtonEx(DWORD Event, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
		//return false;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void Interface::DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
	sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();

	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();

	glColor3f(1, 1, 1);
	pSetBlend(false);
}

void Interface::TextDraw(int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align, HGDIOBJ Font, LPCTSTR Format, ...)
{
	char TextBuff[1024] = { 0 };
	va_list va;
	va_start(va, Format);
	vsprintf_s(TextBuff, Format, va);
	va_end(va);

	int v13; // ST1C_4@1
	int v15; // ST20_4@1
	pSetFont(pTextThis(), (int)Font);
	v13 = sub_41FFE0_Addr(pTextThis());
	v15 = sub_420010_Addr(pTextThis());
	SetTextColorByHDC(pTextThis(), Color);
	sub_4200F0_Addr(pTextThis(), Arg7);
	pSetBkColor(pTextThis(), 255, 255, 255, 0);
	pDrawText(pTextThis(), PosX, PosY, TextBuff, Width, Arg5, (int*)Align, 0);
	SetTextColorByHDC(pTextThis(), v13);
	sub_4200F0_Addr(pTextThis(), v15);
}

int  getNumberOfDays(int month, int year)
{
	//leap year condition, if month is 2
	if (month == 2)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	//months which has 31 days
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12)
	{
		return 31;
	}

	return 30;
}

void Interface::DrawEventTableWindow()
{

	if (!this->Data[eEVENTTABLE_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	float MainWidth = 190.0;
	float MainHeight = this->Data[eEVENTTABLE_MAIN].Height;
	float StartY = 0;
	float StartX = MAX_WIN_WIDTH - this->Data[eEVENTTABLE_MAIN].Width;
	float MainCenter = StartX + (MainWidth / 3);
	//int x = GetPrivateProfileIntA("Graphics", "X", 0, "./Settings.ini");
	//int y = GetPrivateProfileIntA("Graphics", "Y", 60, "./Settings.ini");

	this->DrawGUI(eEVENTTABLE_MAIN, StartX, StartY);
	this->DrawGUI(eEVENTTABLE_LEFT, StartX, StartY + this->Data[eEVENTTABLE_TITLE].Height);
	this->DrawGUI(eEVENTTABLE_RIGHT, MAX_WIN_WIDTH - this->Data[eEVENTTABLE_LEFT].Width, StartY + this->Data[eEVENTTABLE_TITLE].Height);
	this->DrawGUI(eEVENTTABLE_TITLE, StartX, StartY);
	this->DrawGUI(eEVENTTABLE_FOOTER, StartX, 384);
	this->DrawGUI(eEVENTTABLE_CLOSE, StartX + MainWidth - this->Data[eEVENTTABLE_CLOSE].Width + 3, -1);
	// ----
	//gNewInterface.TextDraw(StartX + MainWidth/2,MainHeight-50,0,1,eGold,0,eCenter,gFont[ARIAL_BLACK_16]->m_Font,"%d / %d",gEventTimer.m_CurrentPage+1,gEventTimer.m_PageCount+1);

	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 87, MainHeight - 50, Fcolor->White, Fcolor->Trans, 15, (LPINT)5, "%d / %d", gEventTimer.m_CurrentPage + 1, gEventTimer.m_PageCount + 1);

	gInterface.DrawGUI(eARROW_LEFT2, StartX + 60, MainHeight - 57);

	gInterface.DrawGUI(eARROW_RIGHT2, StartX + 110, MainHeight - 57);
	// ----
	//gNewInterface.TextDraw(StartX+MainWidth/2,StartY+12,0,1,eWhite,0,8,pFontBold,"[Event Table]"); // Window Name
	gFont[TAHOMA_BOLD_14]->DrawText(StartX + 70, StartY + 12, Fcolor->Red, Fcolor->Trans, 15, (LPINT)5, "Event Timer");
	// ----
	int max_per_page = 20;
	int count = 0;

	//g_Console.AddMessage(5,"MaxGroup = %d",gEventTimer.m_MaxGroup);
	CTime local_time(time(0) - this->m_TimeDiff);

	/*
	int font = ARIAL_BLACK_16;

	if (*(DWORD*)MAIN_RESOLUTION == 1)
	{
	font = ARIAL_BLACK_12;
	}
	else if (*(DWORD*)MAIN_RESOLUTION == 2)
	{
	font = ARIAL_BLACK_13;
	}
	else if (*(DWORD*)MAIN_RESOLUTION == 3)
	{
	font = ARIAL_BLACK_14;
	}
	else if (*(DWORD*)MAIN_RESOLUTION == 15)
	{
	font = ARIAL_BLACK_12;
	}
	else if (*(DWORD*)MAIN_RESOLUTION == 17)
	{
	font = ARIAL_BLACK_14;
	}
	*/
	int group = -1;
	for (group = gEventTimer.m_CurrentPage*max_per_page; group<gEventTimer.m_MaxGroup + 1; group++) // switch for all grouos
	{
		if (count >= max_per_page)
		{
			break;
		}
		CTime min_time = (local_time.GetTime() + 86400);
		int min_index = -1;
		std::vector<EVENTTIMER_INFO> mTimer = gEventTimer.getEventTimerByGroup(group); // get all events for this group

		for (int i = 0; i<mTimer.size(); i++) //switch for all events in this group
		{
			if (mTimer.at(i).DayOfWeek == -1)
			{
				CTime eventtime(local_time.GetYear(), local_time.GetMonth(), local_time.GetDay(), mTimer.at(i).Hour, mTimer.at(i).Minute, 0, -1); //get time for this event

				if (eventtime < local_time)
				{
					eventtime += 86400; // åñëè åâåíò óæå áûë ñåãîäíÿ, òî ïðèáàâëÿåì ñóòêè, ñëåäîâàòåëüíî åâåíò äîëæåí áûòü çàâòðà
				}

				if (eventtime < min_time)
				{
					min_time = eventtime;
					min_index = i;
				}

			}
			else
			{
				for (int j = 0; j<8; j++)
				{
					int year = local_time.GetYear();
					int month = local_time.GetMonth();
					int day = local_time.GetDay();

					if (local_time.GetDay() + j > getNumberOfDays(month, year))
					{
						day = local_time.GetDay() + j - getNumberOfDays(month, year);
						if (month + 1>12)
						{
							year++;
							month = 1;
						}
						else
						{
							month++;
						}

					}

					//CTime eventTime(local_time.GetYear(),local_time.GetMonth(),local_time.GetDay()+j,gEventTimer.m_EventTimerInfo[i].Hour,gEventTimer.m_EventTimerInfo[i].Minute,0,-1);
					CTime eventTime(year, month, day, gEventTimer.m_EventTimerInfo[i].Hour, gEventTimer.m_EventTimerInfo[i].Minute, 0, -1);
					if (eventTime.GetDayOfWeek() == mTimer.at(i).DayOfWeek)
					{
						if (eventTime.GetDay() == local_time.GetDay() && eventTime.GetHour() <= local_time.GetHour() && eventTime.GetMinute() < local_time.GetMinute())
						{
							continue;
						}

						min_time = eventTime;
						min_index = i;
					}
				}
			}
		}

		if (min_index != -1)
		{
			CTimeSpan lol = min_time - local_time;

			//gNewInterface.TextDraw(StartX+15,StartY+55+(count*15),0,1,eGold,0,eLeftToRight,gFont[font]->m_Font,"%d. %s:",group+1,mTimer[min_index].Name);
			//gNewInterface.TextDraw(StartX+15,StartY+55+(count*15),0,1,eGold,0,eLeftToRight,gFont[font]->m_Font,"%d. %s:",group+1,gEventTimer.GetText(mTimer.at(min_index).TextIndex));
			//gNewInterface.TextDraw(StartX+MainWidth-15,StartY+55+(count*15),0,1,eBlue,0,eRightToLeft,gFont[font]->m_Font,"%dd %dh %dm %ds",(int)lol.GetDays(),lol.GetHours(),lol.GetMinutes(),lol.GetSeconds());
			gFont[TAHOMA_BOLD_13]->DrawText(StartX + 15, StartY + 55 + (count * 15), Fcolor->White, Fcolor->Trans, 15, (LPINT)5, "%d. %s:", group + 1, gEventTimer.GetText(mTimer.at(min_index).TextIndex));
			gFont[TAHOMA_BOLD_13]->DrawText(StartX + 120, StartY + 55 + (count * 15), Fcolor->Orange, Fcolor->Trans, 15, (LPINT)5, "%dd %dh %dm %ds", (int)lol.GetDays(), lol.GetHours(), lol.GetMinutes(), lol.GetSeconds());

			pDrawGUI(0x7B5E, StartX + 13, StartY + 55 + (count * 15) + 10, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
			pDrawGUI(0x7B5E, StartX + 13 + 82, StartY + 55 + (count * 15) + 10, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2

			count++;
		}
	}
	// ----
	if (this->IsWorkZone(eEVENTTABLE_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eEVENTTABLE_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eEVENTTABLE_CLOSE, StartX + MainWidth - this->Data[eEVENTTABLE_CLOSE].Width + 3, -1, Color);
		this->DrawToolTip(this->Data[eEVENTTABLE_CLOSE].X + 5, this->Data[eEVENTTABLE_CLOSE].Y + 24, "Close");
	}

	if (this->IsWorkZone(eARROW_LEFT2))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eARROW_LEFT2].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eARROW_LEFT2, StartX + 60, MainHeight - 57, Color);
	}

	if (this->IsWorkZone(eARROW_RIGHT2))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eARROW_RIGHT2].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eARROW_RIGHT2, StartX + 110, MainHeight - 57, Color);
	}
}

void Interface::EventEventTableWindow(DWORD Event)
{
	if (!this->Data[eEVENTTABLE_MAIN].OnShow)
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();

	if (this->IsWorkZone(eEVENTTABLE_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_CLOSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eEVENTTABLE_CLOSE].OnClick = true;
			return;
		}
		// ----
		this->Data[eEVENTTABLE_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eEVENTTABLE_CLOSE].EventTick = GetTickCount();
		gEventTimer.EventTimerSwitch();
	}
	else if (this->IsWorkZone(eARROW_LEFT2))
	{
		DWORD Delay = (CurrentTick - this->Data[eARROW_LEFT2].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eARROW_LEFT2].OnClick = true;
			return;
		}
		// ----
		this->Data[eARROW_LEFT2].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eARROW_LEFT2].EventTick = GetTickCount();
		//
		if (gEventTimer.m_CurrentPage > 0)
			gEventTimer.m_CurrentPage--;
	}
	else if (this->IsWorkZone(eARROW_RIGHT2))
	{
		DWORD Delay = (CurrentTick - this->Data[eARROW_RIGHT2].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eARROW_RIGHT2].OnClick = true;
			return;
		}
		// ----
		this->Data[eARROW_RIGHT2].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eARROW_RIGHT2].EventTick = GetTickCount();
		//
		if (gEventTimer.m_CurrentPage<gEventTimer.m_PageCount)
		{
			gEventTimer.m_CurrentPage++;
		}
	}
	// ----
}

bool Interface::CursorZoneButton(float X, float Y, float MaxX, float MaxY)
{
	if ((pCursorX < X || pCursorX > MaxX) || (pCursorY < Y || pCursorY > MaxY))
	{
		return false;
	}
	// ----
	return true;
}

void Interface::DrawFruit()
{
	if (this->CheckWindow(CashShop) ||
		this->CheckWindow(ChaosBox) ||
		this->CheckWindow(FullMap) ||
		this->CheckWindow(MoveList) ||
		this->CheckWindow(SkillTree))
		return;

	if (!this->Data[eFruitMain].OnShow)
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 80.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);

	pDrawImage(iGfxDialoge, StartX + 50, StartY + 50, 150, 200, 1, 1, 1.0, 1.0, 1, 1, 0); //223 280
	pDrawImage(iNewuiDialogHr, StartX + 50, StartY + 115, 145, 5, 1, 1, 1.0, 1.0, 1, 1, 0); //235 210

	this->DrawFormat(eGold, StartX + 15, StartY + 63, 223, 3, gCustomMessage.GetMessage(150));
	int TotalPoint;
	TotalPoint = gObjUser.FStrength + gObjUser.FDexterity + gObjUser.FVitality + gObjUser.FEnergy + gObjUser.FLeadership;
	glColor4f(0.0, 0.0, 0.0, 0.7);
	float BarWidth = 130.1f * (TotalPoint / (TotalPoint + gObjUser.FMaxPoint * 1.0f));
	pDrawBarForm((float)StartX + 60, (float)StartY + 85, 130, 10.0, 0, 0);
	pDrawBarForm((float)StartX + 160, (float)StartY + 134, 30, 13.0, 0, 0);
	pDrawBarForm((float)StartX + 160, (float)StartY + 154, 30, 13.0, 0, 0);
	pDrawBarForm((float)StartX + 160, (float)StartY + 174, 30, 13.0, 0, 0);
	pDrawBarForm((float)StartX + 160, (float)StartY + 194, 30, 13.0, 0, 0);
	pDrawBarForm((float)StartX + 160, (float)StartY + 214, 30, 13.0, 0, 0);
	glColor3f(2.0, 2.0, 0.0);
	pDrawBarForm((float)StartX + 62, (float)StartY + 87, BarWidth, 6, 0, 0);
	this->DrawItem2(StartX + 40, StartY + 100, 50, 50, ITEM(13, 15), SET_ITEMOPT_LEVEL(3), 0, 0, 0); //Str
	this->DrawItem2(StartX + 40, StartY + 120, 50, 50, ITEM(13, 15), SET_ITEMOPT_LEVEL(2), 0, 0, 0); //Agi
	this->DrawItem2(StartX + 40, StartY + 140, 50, 50, ITEM(13, 15), SET_ITEMOPT_LEVEL(1), 0, 0, 0); //Vit
	this->DrawItem2(StartX + 40, StartY + 160, 50, 50, ITEM(13, 15), SET_ITEMOPT_LEVEL(0), 0, 0, 0); //Ene
	this->DrawItem2(StartX + 40, StartY + 180, 50, 50, ITEM(13, 15), SET_ITEMOPT_LEVEL(4), 0, 0, 0); //Cmd
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 100, StartY + 100, Fcolor->Gold, Fcolor->Trans, 30, (LPINT)5, gCustomMessage.GetMessage(151), TotalPoint, gObjUser.FMaxPoint);
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 85, StartY + 135, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, gCustomMessage.GetMessage(152));
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 85, StartY + 155, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, gCustomMessage.GetMessage(153));
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 85, StartY + 175, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, gCustomMessage.GetMessage(154));
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 85, StartY + 195, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, gCustomMessage.GetMessage(155));
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 85, StartY + 215, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, gCustomMessage.GetMessage(156));

	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 165, StartY + 135, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, "%d", gObjUser.FStrength);
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 165, StartY + 155, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, "%d", gObjUser.FDexterity);
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 165, StartY + 175, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, "%d", gObjUser.FVitality);
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 165, StartY + 195, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, "%d", gObjUser.FEnergy);
	gFont[TAHOMA_BOLD_13]->DrawText(StartX + 165, StartY + 215, Fcolor->White, Fcolor->Trans, 30, (LPINT)5, "%d", gObjUser.FLeadership);

	this->DrawGUI(eFruitClose, StartX + 165, StartY + 55);
	if (this->IsWorkZone(eFruitClose))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eFruitClose].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eFruitClose, this->Data[eFruitClose].X, this->Data[eFruitClose].Y, Color);
	}
}

void Interface::EventFruitWindow_Main(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (!gInterface.Data[eFruitMain].OnShow)
	{
		return;
	}

	if (this->IsWorkZone(eFruitClose))
	{
		DWORD Delay = (CurrentTick - this->Data[eFruitClose].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eFruitClose].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eFruitClose].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eFruitClose].EventTick = GetTickCount();
		//Func
		this->Fruit_State();
	}
}

bool Interface::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(), WindowID);
}

bool Interface::CheckWindowEx(int WindowID)
{
	return this->Data[WindowID].OnShow;
}

int Interface::CloseWindow(int WindowID)
{
	return pCloseWindow(pWindowThis(), WindowID);
}

int Interface::OpenWindow(int WindowID)
{
	return pOpenWindow(pWindowThis(), WindowID);
}

void Interface::OpenWindowEx(int WindowID)
{
	Data[WindowID].Open();
}

void Interface::CloseWindowEx(int WindowID)
{
	Data[WindowID].Close();
}

void Interface::DrawChangingClassWindow()
{
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow)
	{
		return;
	}
	// ----
	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);

	pSetCursorFocus = true;
	// ----
	this->DrawGUI(eCHANGINGCLASS_MAIN, StartX, StartY + 2);
	this->DrawGUI(eCHANGINGCLASS_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eCHANGINGCLASS_FRAME, StartX, StartY + 67.0, 13);
	this->DrawGUI(eCHANGINGCLASS_FOOTER, StartX, StartY);
	this->DrawGUI(eCHANGINGCLASS_CLOSE, StartX + MainWidth - this->Data[eCHANGINGCLASS_CLOSE].Width, this->Data[eCHANGINGCLASS_TITLE].Height + this->Data[eCHANGINGCLASS_CLOSE].Height + 2);
	// ----
	if (this->IsWorkZone(eCHANGINGCLASS_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_CLOSE, this->Data[eCHANGINGCLASS_CLOSE].X, this->Data[eCHANGINGCLASS_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eCHANGINGCLASS_CLOSE].X + 5, this->Data[eCHANGINGCLASS_CLOSE].Y + 25, gCustomMessage.GetMessage(70));
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, 110, 210, 3, gCustomMessage.GetMessage(158));
	// ----
	if (gChangeClass.m_PriceType == 0)
	{
		this->DrawFormat(eGold, StartX + 30, 355, 210, 1, gCustomMessage.GetMessage(159));
	}
	else if (gChangeClass.m_PriceType == 1)
	{
		this->DrawFormat(eGold, StartX + 30, 355, 210, 1, gCustomMessage.GetMessage(160));
	}
	else if (gChangeClass.m_PriceType == 2)
	{
		this->DrawFormat(eGold, StartX + 30, 355, 210, 1, gCustomMessage.GetMessage(161));
	}
	else if (gChangeClass.m_PriceType == 3)
	{
		this->DrawFormat(eGold, StartX + 30, 355, 210, 1, gCustomMessage.GetMessage(162));
	}
	this->DrawGUI(eCHANGINGCLASS_MONEYBG, StartX + 30, 365);
	// ----
	char MoneyBuff[50], MoneyBuff2[50];
	ZeroMemory(MoneyBuff, sizeof(MoneyBuff));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	// ----
	//if( gObjUser.m_CreditsCount
	//	< gChangeClass.m_Price )
	//{
	//	pGetMoneyFormat((double)gChangeClass.m_Price, 
	//		MoneyBuff, 0);
	//	pGetMoneyFormat((double)gChangeClass.m_Price - gObjUser.m_CreditsCount, 
	//		MoneyBuff2, 0);
	//	this->DrawFormat(eRed, StartX + 70, 369, 170, 1, "%s\n(Need still %s)", 
	//		MoneyBuff, MoneyBuff2);
	//}
	//else
	//{
	pGetMoneyFormat((double)gChangeClass.m_Price,
		MoneyBuff, 0);
	this->DrawFormat(eGold, StartX + 70, 372, 70, 1, "%s",
		MoneyBuff);
	//}
	// ----
	/*this->DrawFormat(eRed, StartX + 10, 330, 210, 3, "Warning!", MoneyBuff, MoneyBuff2);
	this->DrawFormat(eBlue, StartX + 10, 338, 210, 3, "Before make changing class need remove all items from inventory", MoneyBuff, MoneyBuff2);*/
	// ----
	this->DrawGUI(eCHANGINGCLASS_DW, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 30);
	//this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 40, 210, 3, "Dark Wizard class");
	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 40, 210, 3, gCustomMessage.GetMessage(163), pGetTextLine(pTextLineThis, 20));
	//pGetTextLine
	// ----
	this->DrawGUI(eCHANGINGCLASS_DK, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 30);
	this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 40, 210, 3, gCustomMessage.GetMessage(163), pGetTextLine(pTextLineThis, 21));
	// ----
	this->DrawGUI(eCHANGINGCLASS_ELF, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 60);
	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 70, 210, 3, gCustomMessage.GetMessage(163), pGetTextLine(pTextLineThis, 22));
	// ----
	this->DrawGUI(eCHANGINGCLASS_MG, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 60);
	this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 70, 210, 3, gCustomMessage.GetMessage(163), pGetTextLine(pTextLineThis, 23));
	// ----
	this->DrawGUI(eCHANGINGCLASS_DL, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 90);
	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 100, 210, 3, gCustomMessage.GetMessage(163), pGetTextLine(pTextLineThis, 24));
	// ----
	if (gProtect.m_MainInfo.MaxClassTypes >= 6)
	{
		this->DrawGUI(eCHANGINGCLASS_SUM, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 90);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 100, 210, 3, gCustomMessage.GetMessage(163), pGetTextLine(pTextLineThis, 1687));
	}
	// ----
	if (gProtect.m_MainInfo.MaxClassTypes >= 7)
	{
		this->DrawGUI(eCHANGINGCLASS_RF, ButtonX, this->Data[eCHANGINGCLASS_MAIN].Y + 120);
		this->DrawFormat(eWhite, StartX + 8, this->Data[eCHANGINGCLASS_MAIN].Y + 130, 210, 3, gCustomMessage.GetMessage(163), pGetTextLine(pTextLineThis, 3150));
	}
	// ----
	this->DrawGUI(eCHANGINGCLASS_DIV, StartX, this->Data[eCHANGINGCLASS_MAIN].Y + 212);
	// ----
	this->Data[eCHANGINGCLASS_DW].Attribute = true;
	this->Data[eCHANGINGCLASS_DK].Attribute = true;
	this->Data[eCHANGINGCLASS_ELF].Attribute = true;
	this->Data[eCHANGINGCLASS_MG].Attribute = true;
	this->Data[eCHANGINGCLASS_DL].Attribute = true;
	this->Data[eCHANGINGCLASS_SUM].Attribute = true;
	this->Data[eCHANGINGCLASS_RF].Attribute = true;
	// ----
	if (IsWorkZone(eCHANGINGCLASS_DW))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DW].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DW, this->Data[eCHANGINGCLASS_DW].X, this->Data[eCHANGINGCLASS_DW].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_DK))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DK].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DK, this->Data[eCHANGINGCLASS_DK].X, this->Data[eCHANGINGCLASS_DK].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_ELF))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_ELF].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_ELF, this->Data[eCHANGINGCLASS_ELF].X, this->Data[eCHANGINGCLASS_ELF].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_MG))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_MG].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_MG, this->Data[eCHANGINGCLASS_MG].X, this->Data[eCHANGINGCLASS_MG].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_DL))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DL].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DL, this->Data[eCHANGINGCLASS_DL].X, this->Data[eCHANGINGCLASS_DL].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_SUM))
	{
		if (gProtect.m_MainInfo.MaxClassTypes >= 6)
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eCHANGINGCLASS_SUM].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eCHANGINGCLASS_SUM, this->Data[eCHANGINGCLASS_SUM].X, this->Data[eCHANGINGCLASS_SUM].Y, Color);
		}
	}
	if (IsWorkZone(eCHANGINGCLASS_RF))
	{
		if (gProtect.m_MainInfo.MaxClassTypes >= 7)
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eCHANGINGCLASS_RF].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eCHANGINGCLASS_RF, this->Data[eCHANGINGCLASS_RF].X, this->Data[eCHANGINGCLASS_RF].Y, Color);
		}
	}

}
// ----------------------------------------------------------------------------------------------

void Interface::EventChangingClassWindow_Main(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow)
	{
		return;
	}

	if (this->IsWorkZone(eCHANGINGCLASS_DW))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DW].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_DW].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_DW].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_DW].EventTick = GetTickCount();
		//Func
		gChangeClass.SendChangeClass(0);
	}

	if (this->IsWorkZone(eCHANGINGCLASS_DK))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DK].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_DK].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_DK].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_DK].EventTick = GetTickCount();
		//Func
		gChangeClass.SendChangeClass(16);
	}

	if (this->IsWorkZone(eCHANGINGCLASS_ELF))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_ELF].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_ELF].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_ELF].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_ELF].EventTick = GetTickCount();
		//Func
		gChangeClass.SendChangeClass(32);
	}

	if (this->IsWorkZone(eCHANGINGCLASS_MG))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_MG].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_MG].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_MG].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_MG].EventTick = GetTickCount();
		//Func
		gChangeClass.SendChangeClass(48);
	}

	if (this->IsWorkZone(eCHANGINGCLASS_DL))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DL].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_DL].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_DL].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_DL].EventTick = GetTickCount();
		//Func
		gChangeClass.SendChangeClass(64);
	}

	if (this->IsWorkZone(eCHANGINGCLASS_SUM))
	{
		if (gProtect.m_MainInfo.MaxClassTypes<6)
		{
			return;
		}
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_SUM].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_SUM].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_SUM].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_SUM].EventTick = GetTickCount();
		//Func
		gChangeClass.SendChangeClass(80);
	}

	if (this->IsWorkZone(eCHANGINGCLASS_RF))
	{
		if (gProtect.m_MainInfo.MaxClassTypes<7)
		{
			return;
		}
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_RF].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_RF].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_RF].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_RF].EventTick = GetTickCount();
		//Func
		gChangeClass.SendChangeClass(96);
	}

	if (this->IsWorkZone(eCHANGINGCLASS_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_CLOSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGINGCLASS_CLOSE].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_CLOSE].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHANGINGCLASS_CLOSE].EventTick = GetTickCount();
		//Func
		this->Data[eCHANGINGCLASS_MAIN].Close();
	}
}

void Interface::PartyInterface()
{
	if (this->MiniMapCheck() || this->CombinedChecks())
	{
		return;
	}
	if (gInterface.m_PartyTrace == 1)
	{
		if (pPartyMemberCount == 2)
		{
			pDrawGUI(0x789B, 600, 17, 9.0, 10.0);
			pDrawGUI(0x789B, 600, 62, 9.0, 10.0);
		}
		else if (pPartyMemberCount == 3)
		{
			pDrawGUI(0x789B, 600, 17, 9.0, 10.0);
			pDrawGUI(0x789B, 600, 62, 9.0, 10.0);
			pDrawGUI(0x789B, 600, 105, 9.0, 10.0);
		}
		else if (pPartyMemberCount == 4)
		{
			pDrawGUI(0x789B, 600, 17, 9.0, 10.0);
			pDrawGUI(0x789B, 600, 62, 9.0, 10.0);
			pDrawGUI(0x789B, 600, 105, 9.0, 10.0);
			pDrawGUI(0x789B, 600, 149, 9.0, 10.0);
		}
		else if (pPartyMemberCount == 5)
		{
			pDrawGUI(0x789B, 600, 17, 9.0, 10.0);
			pDrawGUI(0x789B, 600, 62, 9.0, 10.0);
			pDrawGUI(0x789B, 600, 105, 9.0, 10.0);
			pDrawGUI(0x789B, 600, 149, 9.0, 10.0);
			pDrawGUI(0x789B, 600, 193, 9.0, 10.0);
		}
	}
	if (gInterface.m_PartyLeader == 1)
	{
		if (pPartyMemberCount == 2)
		{
			pDrawGUI(0x789A, 614, 62, 9.0, 10.0);
		}
		else if (pPartyMemberCount == 3)
		{
			pDrawGUI(0x789A, 614, 62, 9.0, 10.0);
			pDrawGUI(0x789A, 614, 105, 9.0, 10.0);
		}
		else if (pPartyMemberCount == 4)
		{
			pDrawGUI(0x789A, 614, 62, 9.0, 10.0);
			pDrawGUI(0x789A, 614, 105, 9.0, 10.0);
			pDrawGUI(0x789A, 614, 149, 9.0, 10.0);
		}
		else if (pPartyMemberCount == 5)
		{
			pDrawGUI(0x789A, 614, 62, 9.0, 10.0);
			pDrawGUI(0x789A, 614, 105, 9.0, 10.0);
			pDrawGUI(0x789A, 614, 149, 9.0, 10.0);
			pDrawGUI(0x789A, 614, 193, 9.0, 10.0);
		}
	}
}

void Interface::EventPartyInterface(DWORD Event)
{

	if (this->MiniMapCheck() || this->CombinedChecks())
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();
	// ----
	if (gInterface.m_PartyLeader == 1)
	{
		if (IsWorkZone(ePARTYLEADER))
		{
			DWORD Delay = (CurrentTick - this->Data[ePARTYLEADER].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ePARTYLEADER].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			this->Data[ePARTYLEADER].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			// ----
			this->Data[ePARTYLEADER].EventTick = GetTickCount();
			// ----
			GC_PARTYNEWLEADER pRequest;

			pRequest.h.set(0xFF, 0x15, sizeof(pRequest));
			pRequest.id = (BYTE)1;
			DataSend((BYTE*)&pRequest, pRequest.h.size);
		}
		else if (IsWorkZone(ePARTYLEADER2))
		{
			DWORD Delay = (CurrentTick - this->Data[ePARTYLEADER2].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ePARTYLEADER2].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			this->Data[ePARTYLEADER2].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			// ----
			this->Data[ePARTYLEADER2].EventTick = GetTickCount();
			// ----
			GC_PARTYNEWLEADER pRequest;

			pRequest.h.set(0xFF, 0x15, sizeof(pRequest));
			pRequest.id = (BYTE)2;
			DataSend((BYTE*)&pRequest, pRequest.h.size);
		}
		else if (IsWorkZone(ePARTYLEADER3))
		{
			DWORD Delay = (CurrentTick - this->Data[ePARTYLEADER3].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ePARTYLEADER3].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			this->Data[ePARTYLEADER3].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			// ----
			this->Data[ePARTYLEADER3].EventTick = GetTickCount();
			// ----
			GC_PARTYNEWLEADER pRequest;

			pRequest.h.set(0xFF, 0x15, sizeof(pRequest));
			pRequest.id = (BYTE)3;
			DataSend((BYTE*)&pRequest, pRequest.h.size);
		}
		else if (IsWorkZone(ePARTYLEADER4))
		{
			DWORD Delay = (CurrentTick - this->Data[ePARTYLEADER4].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ePARTYLEADER4].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			this->Data[ePARTYLEADER4].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			// ----
			this->Data[ePARTYLEADER4].EventTick = GetTickCount();
			// ----
			GC_PARTYNEWLEADER pRequest;

			pRequest.h.set(0xFF, 0x15, sizeof(pRequest));
			pRequest.id = (BYTE)4;
			DataSend((BYTE*)&pRequest, pRequest.h.size);
		}
	}
	if (gInterface.m_PartyTrace == 1)
	{
		if (IsWorkZone(ePARTYTRACE))
		{
			DWORD Delay = (CurrentTick - this->Data[ePARTYTRACE].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ePARTYTRACE].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			this->Data[ePARTYTRACE].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			// ----
			this->Data[ePARTYTRACE].EventTick = GetTickCount();
			// ----
			GC_PARTYNEWLEADER pRequest;

			pRequest.h.set(0xFF, 0x26, sizeof(pRequest));
			pRequest.id = (BYTE)0;
			DataSend((BYTE*)&pRequest, pRequest.h.size);
		}
		else if (IsWorkZone(ePARTYTRACE2))
		{
			DWORD Delay = (CurrentTick - this->Data[ePARTYTRACE2].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ePARTYTRACE2].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			this->Data[ePARTYTRACE2].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			// ----
			this->Data[ePARTYTRACE2].EventTick = GetTickCount();
			// ----
			GC_PARTYNEWLEADER pRequest;

			pRequest.h.set(0xFF, 0x26, sizeof(pRequest));
			pRequest.id = (BYTE)1;
			DataSend((BYTE*)&pRequest, pRequest.h.size);
		}
		else if (IsWorkZone(ePARTYTRACE3))
		{
			DWORD Delay = (CurrentTick - this->Data[ePARTYTRACE3].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ePARTYTRACE3].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			this->Data[ePARTYTRACE3].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			// ----
			this->Data[ePARTYTRACE3].EventTick = GetTickCount();
			// ----
			GC_PARTYNEWLEADER pRequest;

			pRequest.h.set(0xFF, 0x26, sizeof(pRequest));
			pRequest.id = (BYTE)2;
			DataSend((BYTE*)&pRequest, pRequest.h.size);
		}
		else if (IsWorkZone(ePARTYTRACE4))
		{
			DWORD Delay = (CurrentTick - this->Data[ePARTYTRACE4].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ePARTYTRACE4].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			this->Data[ePARTYTRACE4].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			// ----
			this->Data[ePARTYTRACE4].EventTick = GetTickCount();
			// ----
			GC_PARTYNEWLEADER pRequest;

			pRequest.h.set(0xFF, 0x26, sizeof(pRequest));
			pRequest.id = (BYTE)3;
			DataSend((BYTE*)&pRequest, pRequest.h.size);
		}
		else if (IsWorkZone(ePARTYTRACE5))
		{
			DWORD Delay = (CurrentTick - this->Data[ePARTYTRACE5].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ePARTYTRACE5].OnClick = true;
				pSetCursorFocus = true;
				return;
			}
			// ----
			this->Data[ePARTYTRACE5].OnClick = false;
			pSetCursorFocus = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			// ----
			this->Data[ePARTYTRACE5].EventTick = GetTickCount();
			// ----
			GC_PARTYNEWLEADER pRequest;

			pRequest.h.set(0xFF, 0x26, sizeof(pRequest));
			pRequest.id = (BYTE)4;
			DataSend((BYTE*)&pRequest, pRequest.h.size);
		}
	}
}

void Interface::DrawResetWindow()
{


	if (!this->Data[eRESET_MAIN].OnShow)
	{
		return;
	}

	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);

	pSetCursorFocus = true;
	// ----
	this->DrawGUI(eRESET_MAIN, StartX, StartY + 2);
	this->DrawGUI(eRESET_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eRESET_FRAME, StartX, StartY + 67.0, 13);
	this->DrawGUI(eRESET_FOOTER, StartX, StartY);
	this->DrawGUI(eRESET_CLOSE, StartX + MainWidth - this->Data[eRESET_CLOSE].Width, this->Data[eRESET_TITLE].Height + this->Data[eRESET_CLOSE].Height + 2);
	// ----
	if (this->IsWorkZone(eRESET_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eRESET_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eRESET_CLOSE, this->Data[eRESET_CLOSE].X, this->Data[eRESET_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eRESET_CLOSE].X + 5, this->Data[eRESET_CLOSE].Y + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, 110, 210, 3, "Reset Master");
	// ----
	this->DrawGUI(eRESET_INFOBG, StartX + 30, 140);
	this->DrawFormat(eGold, StartX + 35, 145, 70, 3, "Next Reset:");
	this->DrawFormat(eWhite, StartX + 135, 145, 70, 1, "%d", ViewReset + 1);
	this->DrawGUI(eRESET_INFOBG, StartX + 30, 160);
	this->DrawFormat(eGold, StartX + 35, 165, 70, 3, "Reward Points:");
	this->DrawFormat(eWhite, StartX + 135, 165, 70, 1, "%d", gResetSystem.GetRewardPoints());
	// ----
	this->DrawGUI(eRESET_DIV, StartX, 185);
	// ----
	this->DrawFormat(eGold, StartX + 30, 215, 210, 1, "Required Level:");
	// ----
	if (gObjUser.lpPlayer->Level < gResetSystem.m_ResetData.ReqLevel)//gResetSystem.m_GroupData[gResetSystem.GetResetGroup()].ReqLevel[ViewAccountLevel] )
	{
		this->DrawFormat(eRed, StartX + 30, 225, 210, 1, "- %d (Your: %d)",
			gResetSystem.m_ResetData.ReqLevel, gObjUser.lpPlayer->Level);
		//gResetSystem.m_GroupData[gResetSystem.GetResetGroup()].ReqLevel[ViewAccountLevel], gObjUser.lpPlayer->Level);
	}
	else
	{
		this->DrawFormat(eWhite, StartX + 30, 225, 210, 1, "- %d",
			gResetSystem.m_ResetData.ReqLevel);
		//gResetSystem.m_GroupData[gResetSystem.GetResetGroup()].ReqLevel[ViewAccountLevel]);
	}
	// ----
	this->DrawFormat(eGold, StartX + 30, 240, 210, 1, "Required Items:");
	// ----
	for (int i = 0; i < gResetSystem.m_ResetData.ItemCount/*gResetSystem.m_GroupData[gResetSystem.GetResetGroup()].ItemCount*/; i++)
	{
		char ItemNameBuff[150], LevelBuff[25], OptionBuff[25];
		// ----
		ZeroMemory(ItemNameBuff, sizeof(ItemNameBuff));
		// ----
		//if (gResetSystem.m_GroupData[gResetSystem.GetResetGroup()].ItemData[i].Count > 1)
		if (gResetSystem.m_ResetData.ItemData[i].Count > 0)
		{
			char buff[25];
			sprintf(buff, " %dx ", gResetSystem.m_ResetData.ItemData[i].Count/*gResetSystem.m_GroupData[gResetSystem.GetResetGroup()].ItemData[i].Count*/);
			strcat(ItemNameBuff, buff);
		}
		// ----
		if (gResetSystem.m_ResetData.ItemData[i].IsExcellent)
		{
			strcat(ItemNameBuff, "Excellent ");
			ItemNameColor = eExcellent;
		}
		// ----
		if (gResetSystem.m_ResetData.ItemData[i].IsAncient)
		{
			strcat(ItemNameBuff, "Ancient ");
			ItemNameColor = eAncient;
		}
		// ----
		if (gResetSystem.m_ResetData.ItemData[i].IsSocket)
		{
			strcat(ItemNameBuff, "Socket ");
			ItemNameColor = eSocket;
		}
		// ----
		strcat(ItemNameBuff, (char*)(*(DWORD*)0x8128AC0 + 84 *
			gResetSystem.m_ResetData.ItemData[i].ID));
		// ----
		if (gResetSystem.m_ResetData.ItemData[i].MinLevel
			== gResetSystem.m_ResetData.ItemData[i].MaxLevel)
		{
			ZeroMemory(LevelBuff, sizeof(LevelBuff));
			sprintf(LevelBuff, " [+%d, ", gResetSystem.m_ResetData.ItemData[i].MinLevel);
			strcat(ItemNameBuff, LevelBuff);
		}
		else
		{
			ZeroMemory(LevelBuff, sizeof(LevelBuff));
			sprintf(LevelBuff, " [+%d~%d, ",
				gResetSystem.m_ResetData.ItemData[i].MinLevel,
				gResetSystem.m_ResetData.ItemData[i].MaxLevel);
			strcat(ItemNameBuff, LevelBuff);
		}
		// ----
		if (gResetSystem.m_ResetData.ItemData[i].MinOption
			== gResetSystem.m_ResetData.ItemData[i].MaxOption)
		{
			ZeroMemory(OptionBuff, sizeof(OptionBuff));
			sprintf(OptionBuff, "+%d] ", gResetSystem.m_ResetData.ItemData[i].MinOption * 4);
			strcat(ItemNameBuff, OptionBuff);
		}
		else
		{
			ZeroMemory(OptionBuff, sizeof(OptionBuff));
			sprintf(OptionBuff, "+%d~%d] ",
				gResetSystem.m_ResetData.ItemData[i].MinOption * 4,
				gResetSystem.m_ResetData.ItemData[i].MaxOption * 4);
			strcat(ItemNameBuff, OptionBuff);
		}
		// ----
		if (gResetSystem.m_ResetData.ItemData[i].IsLuck == 0)
		{
			strcat(ItemNameBuff, "+ Without Luck ");
		}
		else if (gResetSystem.m_ResetData.ItemData[i].IsLuck == 1)
		{
			strcat(ItemNameBuff, "+ Luck ");
		}
		// ----
		if (gResetSystem.m_ResetData.ItemData[i].IsSkill == 0)
		{
			strcat(ItemNameBuff, "+ Without Skill");
		}
		else if (gResetSystem.m_ResetData.ItemData[i].IsSkill == 1)
		{
			strcat(ItemNameBuff, "+ Skill");
		}
		// ----
		if (!gObjUser.m_ResetItemCheck[i])
		{
			pDrawGUI(0x7BC4, StartX + 22.0, 251 + (i * 8), 7.0, 7.0);
		}
		else
		{
			pDrawGUI(0x7BC1, StartX + 22.0, 251 + (i * 8), 7.0, 7.0);
		}
		// ----
		this->DrawFormat(ItemNameColor, StartX + 30, 250 + (i * 8), 210, 1, ItemNameBuff);

	}
	// ----
	if (gResetSystem.m_ResetData.ItemCount <= 0)
	{
		this->DrawFormat(eWhite, StartX + 30, 250, 210, 1, "- None");
	}
	// ----
	this->DrawFormat(eGold, StartX + 30, 295, 210, 1, "Required Zen:");
	this->DrawGUI(eRESET_MONEYBG, StartX + 30, 305);
	// ----
	char MoneyBuff[50], MoneyBuff2[50];
	ZeroMemory(MoneyBuff, sizeof(MoneyBuff));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	// ----
	if (gObjUser.lpPlayer->MoneyInventory
		< gResetSystem.GetResetMoney())
	{
		pGetMoneyFormat((double)gResetSystem.GetResetMoney(),
			MoneyBuff, 0);
		pGetMoneyFormat((double)gResetSystem.GetResetMoney() - gObjUser.lpPlayer->MoneyInventory,
			MoneyBuff2, 0);
		this->DrawFormat(eRed, StartX + 70, 309, 170, 1, "%s\n(Need still %s)",
			MoneyBuff, MoneyBuff2);
	}
	else
	{
		pGetMoneyFormat((double)gResetSystem.GetResetMoney(),
			MoneyBuff, 0);
		this->DrawFormat(eGold, StartX + 70, 312, 70, 1, "%s",
			MoneyBuff);
	}
	// ----
	/*this->DrawFormat(eRed, StartX + 10, 340, 210, 3, "Warning!", MoneyBuff, MoneyBuff2);
	this->DrawFormat(eBlue, StartX + 10, 348, 210, 3, "Before make reset you need remove all items from inventory", MoneyBuff, MoneyBuff2);*/
	// ----
	this->DrawGUI(eRESET_FINISH, ButtonX, this->Data[eRESET_FOOTER].Y + 10);
	this->DrawFormat(eWhite, StartX + 8, this->Data[eRESET_FOOTER].Y + 20, 210, 3, "Make Reset");
	this->DrawGUI(eRESET_DIV, StartX, this->Data[eRESET_FOOTER].Y - 10);
	// ----
	if (!gResetSystem.CheckAllReq())
	{
		this->Data[eRESET_FINISH].Attribute = false;
		this->DrawColoredGUI(eRESET_FINISH, this->Data[eRESET_FINISH].X, this->Data[eRESET_FINISH].Y, eGray150);
		return;
	}
	// ----
	this->Data[eRESET_FINISH].Attribute = true;
	// ----
	if (IsWorkZone(eRESET_FINISH))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eRESET_FINISH].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eRESET_FINISH, this->Data[eRESET_FINISH].X, this->Data[eRESET_FINISH].Y, Color);
	}
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventResetWindow_Main(DWORD Event)
{
	this->EventResetWindow_Close(Event);
	this->EventResetWindow_Finish(Event);
	return true;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventResetWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eRESET_CLOSE].EventTick);
	// ----
	if (!this->Data[eRESET_MAIN].OnShow || !IsWorkZone(eRESET_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eRESET_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eRESET_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eRESET_CLOSE].EventTick = GetTickCount();
	this->Data[eRESET_MAIN].Close();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventResetWindow_Finish(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eRESET_FINISH].EventTick);
	// ----
	if (!this->Data[eRESET_MAIN].OnShow || !IsWorkZone(eRESET_FINISH)
		|| !this->Data[eRESET_FINISH].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eRESET_FINISH].OnClick = true;
		return true;
	}
	// ----
	this->Data[eRESET_FINISH].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eRESET_FINISH].EventTick = GetTickCount();
	gResetSystem.ReqResetFinish();
	// ----
	return false;
}

void Interface::DrawWarehouseWindow()
{

	if (!this->Data[eWAREHOUSE_MAIN].OnShow)
	{
		return;
	}

	/*if (gServerInfo.AnimatedWarehouse == 1)
	{
		if (this->Data[eWAREHOUSE_MAIN].OpenedValue > 100)
		{
			this->Data[eWAREHOUSE_MAIN].OpenedValue -= this->Data[eWAREHOUSE_MAIN].Speed;

			if (this->Data[eWAREHOUSE_MAIN].OpenedValue <= 250)
			{
				this->Data[eWAREHOUSE_MAIN].Speed = 15;
			}

			if (this->Data[eWAREHOUSE_MAIN].OpenedValue < 100)
			{
				this->Data[eWAREHOUSE_MAIN].OpenedValue = 100;
			}
		}
	}*/

	// ----
	float MainWidth = 230.0;

	float StartY = 100;

	/*if (gServerInfo.AnimatedWarehouse == 1)
	{
		StartY = this->Data[eWAREHOUSE_MAIN].OpenedValue;//100.0;
	}*/

	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawAnimatedGUI(eWAREHOUSE_MAIN, StartX, StartY + 2);
	this->DrawAnimatedGUI(eWAREHOUSE_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eWAREHOUSE_FRAME, StartX, StartY + 67.0, 7);
	this->DrawAnimatedGUI(eWAREHOUSE_FOOTER, StartX, StartY);
	this->DrawAnimatedGUI(eWAREHOUSE_CLOSE, StartX + MainWidth - this->Data[eWAREHOUSE_CLOSE].Width, this->Data[eWAREHOUSE_MAIN].Y - 2/* + this->Data[eWAREHOUSE_CLOSE].Height + 2*/);
	// ----
	if (this->IsWorkZone(eWAREHOUSE_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eWAREHOUSE_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eWAREHOUSE_CLOSE, this->Data[eWAREHOUSE_CLOSE].X, this->Data[eWAREHOUSE_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eWAREHOUSE_CLOSE].X + 5, this->Data[eWAREHOUSE_CLOSE].Y + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, this->Data[eWAREHOUSE_MAIN].Y + 8, 210, 3, "WAREHOUSE");

	this->DrawFormat(eBlue, StartX + 10, this->Data[eWAREHOUSE_MAIN].Y + 30, 210, 3, "Dear %s, please select warehouse...", gObjUser.lpPlayer->Name);
	this->DrawAnimatedGUI(eWAREHOUSE_DIV, StartX, this->Data[eWAREHOUSE_MAIN].Y + 33);
	// ----
	this->DrawAnimatedGUI(eWAREHOUSE_NUM1, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 60);
	this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 70, 210, 3, "Warehouse 1");
	// ----
	if (gObjUser.m_MaxWarehouse >= 2)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM2, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 90);
		this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 100, 210, 3, "Warehouse 2");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 3)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM3, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 120);
		this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 130, 210, 3, "Warehouse 3");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 4)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM4, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 150);
		this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 160, 210, 3, "Warehouse 4");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 5)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM5, ButtonX + 52, this->Data[eWAREHOUSE_MAIN].Y + 60);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eWAREHOUSE_MAIN].Y + 70, 210, 3, "Warehouse 5");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 6)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM6, ButtonX + 52, this->Data[eWAREHOUSE_MAIN].Y + 90);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eWAREHOUSE_MAIN].Y + 100, 210, 3, "Warehouse 6");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 7)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM7, ButtonX + 52, this->Data[eWAREHOUSE_MAIN].Y + 120);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eWAREHOUSE_MAIN].Y + 130, 210, 3, "Warehouse 7");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 8)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM8, ButtonX + 52, this->Data[eWAREHOUSE_MAIN].Y + 150);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eWAREHOUSE_MAIN].Y + 160, 210, 3, "Warehouse 8");
	}
	// ----
	if (IsWorkZone(eWAREHOUSE_NUM1))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eWAREHOUSE_NUM1].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eWAREHOUSE_NUM1, this->Data[eWAREHOUSE_NUM1].X, this->Data[eWAREHOUSE_NUM1].Y, Color);
	}
	if (gObjUser.m_MaxWarehouse >= 2)
	{
		if (IsWorkZone(eWAREHOUSE_NUM2))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM2].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM2, this->Data[eWAREHOUSE_NUM2].X, this->Data[eWAREHOUSE_NUM2].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 3)
	{
		if (IsWorkZone(eWAREHOUSE_NUM3))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM3].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM3, this->Data[eWAREHOUSE_NUM3].X, this->Data[eWAREHOUSE_NUM3].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 4)
	{
		if (IsWorkZone(eWAREHOUSE_NUM4))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM4].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM4, this->Data[eWAREHOUSE_NUM4].X, this->Data[eWAREHOUSE_NUM4].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 5)
	{
		if (IsWorkZone(eWAREHOUSE_NUM5))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM5].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM5, this->Data[eWAREHOUSE_NUM5].X, this->Data[eWAREHOUSE_NUM5].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 6)
	{
		if (IsWorkZone(eWAREHOUSE_NUM6))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM6].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM6, this->Data[eWAREHOUSE_NUM6].X, this->Data[eWAREHOUSE_NUM6].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 7)
	{
		if (IsWorkZone(eWAREHOUSE_NUM7))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM7].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM7, this->Data[eWAREHOUSE_NUM7].X, this->Data[eWAREHOUSE_NUM7].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 8)
	{
		if (IsWorkZone(eWAREHOUSE_NUM8))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM8].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM8, this->Data[eWAREHOUSE_NUM8].X, this->Data[eWAREHOUSE_NUM8].Y, Color);
		}
	}
}

void Interface::EventWarehouseWindow_Main(DWORD Event)
{
	this->EventWarehouseWindow_Close(Event);
	// 4136

	DWORD CurrentTick = GetTickCount();

	if ((CurrentTick - this->Data[eWAREHOUSE_MAIN].EventTick) < 500)
	{
		return;
	}

	//DWORD Delay			= (CurrentTick - this->Data[eCHANGINGCLASS_MG].EventTick);
	// ----
	if (!this->Data[eWAREHOUSE_MAIN].OnShow)
	{
		return;
	}

	// || !IsWorkZone(eCHANGINGCLASS_MG) || !this->Data[eCHANGINGCLASS_MG].Attribute )

	int ObjectIDs[8] =
	{
		eWAREHOUSE_NUM1,
		eWAREHOUSE_NUM2,
		eWAREHOUSE_NUM3,
		eWAREHOUSE_NUM4,
		eWAREHOUSE_NUM5,
		eWAREHOUSE_NUM6,
		eWAREHOUSE_NUM7,
		eWAREHOUSE_NUM8
	};

	for (int i = 0; i < 8; i++)
	{
		if (this->IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);

			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;;
			// ----
			if (Delay < 500)
			{
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();
			////console.Log("", "Button %d", i);
			CGSendWarehouseOpen(i);
			this->Data[eWAREHOUSE_MAIN].Close(MAX_WIN_HEIGHT, 20);
			//this->Data[eWAREHOUSE_MAIN].Attribute = MAX_WIN_HEIGHT;
			//this->Data[eWAREHOUSE_MAIN].Speed = 20;
		}
	}
}

void Interface::EventWarehouseWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eWAREHOUSE_CLOSE].EventTick);
	// ----
	if (!this->Data[eWAREHOUSE_MAIN].OnShow || !IsWorkZone(eWAREHOUSE_CLOSE))
	{
		return;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eWAREHOUSE_CLOSE].OnClick = true;
		return;
	}
	// ----
	this->Data[eWAREHOUSE_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return;
	}
	// ----
	this->Data[eWAREHOUSE_CLOSE].EventTick = GetTickCount();
	this->Data[eWAREHOUSE_MAIN].Close(MAX_WIN_HEIGHT, 20);
	// ----
	return;
}

// ----------------------------------------------------------------------------------------------

/*void Interface::DrawCameraUI()
{
	float PosX = 146 + 37;
	// ----
	if (this->CheckWindow(CashShop)
		|| this->CheckWindow(SkillTree)
		|| this->CheckWindow(FullMap)
		|| this->CheckWindow(MoveList)
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}
	if (gProtect.m_MainInfo.CustomMenuSwitch != 0)
	{
		// ----
		this->DrawGUI(eCAMERA_MAIN, PosX, 0);
		this->DrawGUI(eCAMERA_BUTTON1, PosX + 0.2, 1);
		this->DrawGUI(eCAMERA_BUTTON2, PosX + 18.2, 1);
		this->DrawGUI(eCAMERA_BUTTON3, PosX + 36.2, 1);

		// ----
		if (gCamera.IsActive)
		{
			this->DrawColoredGUI(eCAMERA_BUTTON1, PosX + 0.2, 1, eShinyGreen);
		}
		// ----
		if (IsWorkZone(eCAMERA_BUTTON1))
		{
			if (gCamera.IsActive)
			{
				this->DrawToolTip(PosX + 0.2 - 5, 25, "Zoom: %02.f%%", gCamera.ZoomPercent);
			}
			else
			{
				this->DrawToolTip(PosX + 0.2 - 5, 25, "3D Camera [On|Off]");
			}
			// ----
			if (this->Data[eCAMERA_BUTTON1].OnClick)
			{
				pSetCursorFocus = true;
				this->DrawColoredGUI(eCAMERA_BUTTON1, PosX + 0.2, 1, pMakeColor(40, 20, 3, 130));
				return;
			}
			// ----
			this->DrawColoredGUI(eCAMERA_BUTTON1, PosX + 0.2, 1, pMakeColor(255, 204, 20, 200));
		}
		else if (IsWorkZone(eCAMERA_BUTTON2))
		{
			this->DrawToolTip(PosX + 18.2 - 5, 25, "3D Camera [Reset]");
			// ----
			if (this->Data[eCAMERA_BUTTON2].OnClick)
			{
				pSetCursorFocus = true;
				this->DrawColoredGUI(eCAMERA_BUTTON2, PosX + 18.2, 1, pMakeColor(40, 20, 3, 130));
				return;
			}
			// ----
			this->DrawColoredGUI(eCAMERA_BUTTON2, PosX + 18.2, 1, pMakeColor(255, 204, 20, 200));
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
}*/

void Interface::EventCameraUI(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	// ----
	if (this->CheckWindow(CashShop)
		|| this->CheckWindow(SkillTree)
		|| this->CheckWindow(FullMap)
		|| this->CheckWindow(MoveList)
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}
	// ----
	if (IsWorkZone(eCAMERA_BUTTON1))
	{
		DWORD Delay = (CurrentTick - this->Data[eCAMERA_BUTTON1].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCAMERA_BUTTON1].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCAMERA_BUTTON1].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCAMERA_BUTTON1].EventTick = GetTickCount();
		// ----
		gCamera.Switch();
	}
	else if (IsWorkZone(eCAMERA_BUTTON2))
	{
		DWORD Delay = (CurrentTick - this->Data[eCAMERA_BUTTON2].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCAMERA_BUTTON2].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCAMERA_BUTTON2].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCAMERA_BUTTON2].EventTick = GetTickCount();
		// ----
		gCamera.Reset();
	}
	else if (IsWorkZone(eCAMERA_BUTTON3))
	{
		DWORD Delay = (CurrentTick - this->Data[eCAMERA_BUTTON3].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCAMERA_BUTTON3].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eCAMERA_BUTTON3].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCAMERA_BUTTON3].EventTick = GetTickCount();
		// ----
		if (CheckMenuWindow())
		{
			CloseMenuWindow();
		}
		else
		{
			CloseCustomWindow();
			OpenMenuWindow();
		}
	}
}

void Interface::DrawSettingsUI()
{
	if (!this->Data[eSETTINGS_MAIN].OnShow)
	{
		return;
	}
	// ----
	float MainWidth = 230.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);

	pSetCursorFocus = true;

	this->DrawGUI(eSETTINGS_MAIN, StartX, StartY + 2);
	this->DrawGUI(eSETTINGS_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eSETTINGS_FRAME, StartX, StartY + 67.0, 13);
	this->DrawGUI(eSETTINGS_FOOTER, StartX, StartY);

	int x = GetPrivateProfileIntA("Graphics", "X", 0, "./Settings.ini");
	int y = GetPrivateProfileIntA("Graphics", "Y", 0, "./Settings.ini");

	this->DrawGUI(eSETTINGS_CLOSE, StartX + MainWidth - this->Data[eSETTINGS_CLOSE].Width, this->Data[eSETTINGS_CLOSE].Height + this->Data[eSETTINGS_CLOSE].Height + 40);
	// ----

	if (this->IsWorkZone(eSETTINGS_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eSETTINGS_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eSETTINGS_CLOSE, this->Data[eSETTINGS_CLOSE].X, this->Data[eSETTINGS_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eSETTINGS_CLOSE].X + 5, this->Data[eSETTINGS_CLOSE].Y + 25, "Close");
	}
	// ----

	int ObjectIDs[7] =
	{
		eSETTINGS_CHECKBOX1,
		eSETTINGS_CHECKBOX2,
		eSETTINGS_CHECKBOX3,
		eSETTINGS_CHECKBOX4,
		eSETTINGS_CHECKBOX5,
		eSETTINGS_CHECKBOX6,
		eSETTINGS_CHECKBOX7,
	};

	char szCharNames[7][32] =
	{
		"Separate Chat",
		"Fog",
		"Health Bar Monsters",
		"Time Bar",
		"Mini Map",
		"Disable Glow",
		"Disable Shadows"
	};

	for (int i = 0; i<7; i++)
	{
		this->DrawGUI(eSETTINGS_LINE, StartX + 30, this->Data[eSETTINGS_MAIN].Y + 55 + (20 * i));

		this->DrawGUI(eSETTINGS_OPTION, StartX + 35, this->Data[eSETTINGS_MAIN].Y + 38 + (20 * i));

		this->DrawFormat(eWhite, StartX + 50, this->Data[eSETTINGS_MAIN].Y + 40 + (20 * i), 125, 1, szCharNames[i]);

		this->DrawButton(ObjectIDs[i], ButtonX + 100, this->Data[eSETTINGS_MAIN].Y + 37 + (20 * i), 0, 15 * gServerInfo.GetSettingsInfo(i));
	}
	// ----
}

void Interface::EventSettingsUI(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (this->IsWorkZone(eSETTINGS_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eSETTINGS_CLOSE].EventTick);
		// ----
		if (!this->Data[eSETTINGS_MAIN].OnShow)
		{
			return;
		}
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSETTINGS_CLOSE].OnClick = true;
			return;
		}
		// ----
		this->Data[eSETTINGS_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eSETTINGS_CLOSE].EventTick = GetTickCount();
		this->SwitchSettingsWindowState();
		// ----
	}

	int ObjectIDs[7] =
	{
		eSETTINGS_CHECKBOX1,
		eSETTINGS_CHECKBOX2,
		eSETTINGS_CHECKBOX3,
		eSETTINGS_CHECKBOX4,
		eSETTINGS_CHECKBOX5,
		eSETTINGS_CHECKBOX6,
		eSETTINGS_CHECKBOX7,
	};

	for (int i = 0; i<7; i++)
	{
		if (this->IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);
			// ----
			if (!this->Data[eSETTINGS_MAIN].OnShow)
			{
				return;
			}
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 200)
			{
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();
			//this->SwitchSettingsWindowState();
			gServerInfo.SetSettingsInfo(i);
			////console.Log("", "Index = %d",i);
			// ----
		}
	}
}