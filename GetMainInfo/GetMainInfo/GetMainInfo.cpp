#include "stdafx.h"
#include "..\..\Util\CCRC32.H"
#include "CustomBuyVip.h"
#include "CustomCommandInfo.h"
#include "CustomEventTimeText.h"
#include "CustomItem.h"
#include "CustomJewel.h"
#include "CustomMessage.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "CustomWing.h"
#include "SmokeEffect.h"
#include "ThemidaSDK.h"
#include "CustomGloves.h"
#include "CustomCrossBow.h"
#include "CustomPet.h"
#include "CustomCloak.h"
#include "Fog.h"
#include "CustomItemPosition.h"
#include "CustomEffectRemake.h"
#include "ItemManager.h"
#include "ItemValue.h"
#include "ModelEffect.h"
#include "EventTimerText.h"
#include "Monster.h"
#include "EarthQuake.h"


struct MAIN_FILE_INFO
{
	BYTE LauncherType; 
	char LauncherName[32];
	char CustomerName[32];
	char IpAddress[32];
	WORD IpAddressPort;
	char ClientVersion[8];
	char ClientSerial[17];
	char WindowName[32];
	char ScreenShotPath[50];
	char ClientName[32];
	char HackName[32];
	char PluginName5[32];
	char PluginName1[32];
	char PluginName2[32];
	char PluginName3[32];
	char PluginName4[32];
	char CameraName[32];
	char ServerName1[32];
	char ServerName2[32];
	char ServerName3[32];
	char ServerName4[32];
	DWORD ClientCRC32;
	DWORD HackCRC32;
	DWORD Plugin5CRC32;
	DWORD Plugin1CRC32;
	DWORD Plugin2CRC32;
	DWORD Plugin3CRC32;
	DWORD Plugin4CRC32;
	DWORD CameraCRC32;
	DWORD HelperActiveAlert;
	DWORD HelperActiveLevel;
	DWORD DWMaxAttackSpeed;
	DWORD DKMaxAttackSpeed;
	DWORD FEMaxAttackSpeed;
	DWORD MGMaxAttackSpeed;
	DWORD DLMaxAttackSpeed;
	DWORD SUMaxAttackSpeed;
	DWORD RFMaxAttackSpeed;
	DWORD ReconnectTime;
	DWORD ReduceMemory;
	DWORD RemoveClass;
	DWORD RankUserType;
	DWORD DisableTree; 
	DWORD CsSkill; 
	DWORD DisableReflectEffect;
	DWORD EnableVipShop;
	DWORD VipTypes;
	DWORD PrintLogo;
	DWORD CustomMenuSwitch;
	DWORD CustomMenuType;
	DWORD EnableEventTimeButton;
	DWORD EnableVipShopButton;
	DWORD EnableJewelBankButton;
	DWORD EnableAchievementsButton;
	DWORD EnableSettingsButton;
	DWORD EnablePartySettingsButton;
	DWORD EnableChangeClassButton;
	DWORD EnableFruitSystemButton;
	DWORD EnableRankingButton;
	DWORD EnableCommandButton;
	DWORD EnableCoinStatus;
	DWORD EnableShopValueSystem;
	DWORD CustomStoreEnableJoB;
	DWORD CustomStoreEnableJoS;
	DWORD CustomStoreEnableJoC;
	DWORD CustomStoreEnableCoin1;
	DWORD CustomStoreEnableCoin2;
	DWORD CustomStoreEnableCoin3;
	DWORD CustomOffStoreEnable;
	DWORD CustomMonsterEnable;
	DWORD DisablePartyHpBar;
	DWORD RankUserShowOverHead;
	DWORD RankUserOnlyOnSafeZone;
	DWORD RankUserShowReset;
	DWORD RankUserShowMasterReset;
	DWORD RankUserNeedAltKey;
	//---
	DWORD CustomInterfaceType;
	DWORD CustomRemoveCoord;
	DWORD TIME_GMT;
	DWORD MonitorFPS;
	DWORD MonitorMS;
	DWORD LimitFPS;
	DWORD EffectPlus15;
	DWORD DisableGens;
	DWORD DisableTabMap;
	DWORD DisableHelper;
	DWORD DisableAdvance;
	DWORD DisableEffectRemake;
	DWORD DisableCustomClaws;
	DWORD DisableCustomBow;
	DWORD DisableCustomCloack;
	DWORD DisableCustomPosition;
	DWORD DisableCustomPet;
	DWORD DisableSocketInvetori;
	DWORD DisableRepeirInInventory;
	DWORD DisableButtonOpenStore;
	DWORD DisableButtonInventoryExt;
	DWORD DisableButtonQuestInStats;
	DWORD DisableButtonPetsInStats;
	DWORD DisableButtonSkillMaster;
	DWORD SelectCharAnimate;
	DWORD SelectCharS13;
	DWORD InventoryUPGRADE;
	DWORD CameraZoom;
	WORD MaxClassTypes;
	DWORD DisableBattleZoneWindow;
	DWORD CameraRange;
	DWORD DisableBCDSCCMaster;
	DWORD Disable380MixChaosMachine;
	DWORD DisableWCoinCCashShop;
	DWORD DisableWCoinPCashShop;
	DWORD DisableWCoinGCashShop;
	DWORD Unicode;
	DWORD MiniMapHover;
	DWORD ChangeMGLevel;
	DWORD CustomSelectServerX700;
	DWORD CustomEffectEarthQuake;
	DWORD WeatherFix;
	//--
	CUSTOM_MESSAGE_INFO EngCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_MESSAGE_INFO PorCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_MESSAGE_INFO SpnCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_JEWEL_INFO CustomJewelInfo[MAX_CUSTOM_JEWEL];
	CUSTOM_WING_INFO CustomWingInfo[MAX_CUSTOM_WING];
	CUSTOM_ITEM_INFO CustomItemInfo[MAX_CUSTOM_ITEM];
	CUSTOM_BUYVIP_INFO CustomBuyVipInfo[MAX_CUSTOM_BUYVIP];
	CUSTOM_COMMAND_INFO CustomCommandInfo[MAX_CUSTOM_COMMAND];
	CUSTOM_EVENT_INFO CustomEventInfo[MAX_EVENTTIME];
	CUSTOM_SMOKEEFFECT CustomSmokeEffect[MAX_SMOKE_ITEMS];
	CUSTOM_FOG CustomFog[MAX_FOG];
	CUSTOMMONSTER_DATA CustomMonsters[MAX_CUSTOMMONSTER];
	NPCNAME_DATA CustomNPCName[MAX_CUSTOM_NPCNAME];
	//--
	CUSTOM_BOW_INFO CustomBowInfo[MAX_CUSTOM_BOW];
	CUSTOM_RF_GLOVES CustomGloves[MAX_CUSTOM_GLOVES];
	CUSTOM_PET_INFO CustomPetInfo[MAX_PET_ITEM];
	CUSTOMCLOAK_DATA m_CustomCloak[MAX_CUSTOMCLOAK];
	CUSTOM_POSITION_INFO CustomPosition[MAX_POSITION_ITEM];
	REMAKE_EFFECT CustomRemake[MAX_REMAKE_EFFECT];
	//--
	ITEM_INFO m_ItemInfoEx[MAX_ITEM];
	//--
	CUSTOM_MODEL_EFFECT_INFO m_CustomModelInfo[MAX_MODEL_EFFECT];
	EVENT_TEXT_INFO CustomEventTime[MAX_TIMER_TEXT];
	CUSTOM_HPBAR CustomHpBar[MAX_CUSTOM_HPBAR];
	HORSE_EARTH_QUAKE m_EarthQuake[MAX_EARTH_QUAKE];
};

int _tmain(int argc,_TCHAR* argv[]) // OK
{
	CLEAR_START

	ENCODE_START

	MAIN_FILE_INFO info;

	memset(&info,0,sizeof(info));
	
	GetPrivateProfileString("MainInfo","CustomerName","",info.CustomerName,sizeof(info.CustomerName),".\\MainInfo.ini");

	info.LauncherType = GetPrivateProfileInt("MainInfo","LauncherType",0,".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","LauncherName","XTLauncherExecutable",info.LauncherName,sizeof(info.LauncherName),".\\MainInfo.ini");
	
	GetPrivateProfileString("MainInfo","IpAddress","",info.IpAddress,sizeof(info.IpAddress),".\\MainInfo.ini");

	info.IpAddressPort = GetPrivateProfileInt("MainInfo","IpAddressPort",44405,".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","ClientVersion","",info.ClientVersion,sizeof(info.ClientVersion),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","ClientSerial","",info.ClientSerial,sizeof(info.ClientSerial),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","WindowName","[MU]",info.WindowName,sizeof(info.WindowName),".\\MainInfo.ini");
	
	GetPrivateProfileString("MainInfo","ScreenShotPath","",info.ScreenShotPath,sizeof(info.ScreenShotPath),".\\MainInfo.ini");
	
	GetPrivateProfileString("MainInfo","ClientName","",info.ClientName,sizeof(info.ClientName),".\\MainInfo.ini");
	
	//-------------------

	GetPrivateProfileString("MainInfo","AntiHackName","",info.HackName,sizeof(info.HackName),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","PluginName1","",info.PluginName1,sizeof(info.PluginName1),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","PluginName2","",info.PluginName2,sizeof(info.PluginName2),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","PluginName3","",info.PluginName3,sizeof(info.PluginName3),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","PluginName4","",info.PluginName4,sizeof(info.PluginName4),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","PluginName5","",info.PluginName5,sizeof(info.PluginName5),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","CameraName","",info.CameraName,sizeof(info.CameraName),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","ServerName1","",info.ServerName1,sizeof(info.ServerName1),".\\MainInfo.ini");
	
	GetPrivateProfileString("MainInfo","ServerName2","",info.ServerName2,sizeof(info.ServerName2),".\\MainInfo.ini");
	
	GetPrivateProfileString("MainInfo","ServerName3","",info.ServerName3,sizeof(info.ServerName3),".\\MainInfo.ini");
	
	GetPrivateProfileString("MainInfo","ServerName4","",info.ServerName4,sizeof(info.ServerName4),".\\MainInfo.ini");

	//--

	info.HelperActiveAlert = GetPrivateProfileInt("HelperInfo","HelperActiveAlert",0,".\\MainInfo.ini");

	info.HelperActiveLevel = GetPrivateProfileInt("HelperInfo","HelperActiveLevel",80,".\\MainInfo.ini");

	info.DWMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","DWMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.DKMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","DKMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.FEMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","FEMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.MGMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","MGMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.DLMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","DLMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.SUMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","SUMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.RFMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","RFMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.ReconnectTime = GetPrivateProfileInt("ReconnectInfo","ReconnectTime",0,".\\MainInfo.ini");

	info.ReduceMemory = GetPrivateProfileInt("Custom","DelectCharacter",300,".\\MainInfo.ini");

	info.RemoveClass = GetPrivateProfileInt("Custom","RemoveClass",0,".\\MainInfo.ini");

	info.MaxClassTypes = GetPrivateProfileInt("Custom", "MaxClassTypes", 0, ".\\MainInfo.ini");

	info.RankUserType = GetPrivateProfileInt("Custom","RankUserType",0,".\\MainInfo.ini");

	info.DisableTree = GetPrivateProfileInt("Custom","DisableMasterSkillTree",0,".\\MainInfo.ini");

	info.CsSkill = GetPrivateProfileInt("Custom","EnableCsSkillsAllMaps",0,".\\MainInfo.ini");

	info.DisableReflectEffect = GetPrivateProfileInt("Custom","DisableReflectEffect",0,".\\MainInfo.ini");

	info.RankUserShowOverHead = GetPrivateProfileInt("Custom","RankUserShowOverHead",0,".\\MainInfo.ini");

	info.RankUserOnlyOnSafeZone = GetPrivateProfileInt("Custom","RankUserOnlyOnSafeZone",1,".\\MainInfo.ini");

	info.RankUserShowReset = GetPrivateProfileInt("Custom","RankUserShowReset",1,".\\MainInfo.ini");

	info.RankUserShowMasterReset = GetPrivateProfileInt("Custom","RankUserShowMasterReset",1,".\\MainInfo.ini");

	info.RankUserNeedAltKey = GetPrivateProfileInt("Custom","RankUserNeedAltKey",0,".\\MainInfo.ini");

	info.EnableVipShop = GetPrivateProfileInt("Custom","EnableVipShop",0,".\\MainInfo.ini");

	info.VipTypes = GetPrivateProfileInt("Custom","VipTypes",3,".\\MainInfo.ini");

	info.PrintLogo = GetPrivateProfileInt("Custom","PrintLogo",0,".\\MainInfo.ini");

	info.Unicode = GetPrivateProfileInt("Custom", "Unicode", 0, ".\\MainInfo.ini");

	info.MiniMapHover = GetPrivateProfileInt("Custom", "MiniMapHover", 0, ".\\MainInfo.ini");

	info.ChangeMGLevel = GetPrivateProfileInt("Custom", "ChangeMGLevel", 0, ".\\MainInfo.ini");

	info.CustomMenuSwitch = GetPrivateProfileInt("Custom","CustomMenuSwitch",0,".\\MainInfo.ini");

	info.CustomMenuType = GetPrivateProfileInt("Custom","CustomMenuType",0,".\\MainInfo.ini");

	info.EnableEventTimeButton = GetPrivateProfileInt("Custom", "EnableEventTimeButton", 0, ".\\MainInfo.ini");

	info.EnableVipShopButton = GetPrivateProfileInt("Custom", "EnableVipShopButton", 0, ".\\MainInfo.ini");

	info.EnableJewelBankButton = GetPrivateProfileInt("Custom", "EnableJewelBankButton", 0, ".\\MainInfo.ini");

	info.EnableAchievementsButton = GetPrivateProfileInt("Custom", "EnableAchievementsButton", 0, ".\\MainInfo.ini");

	info.EnableSettingsButton = GetPrivateProfileInt("Custom", "EnableSettingsButton", 0, ".\\MainInfo.ini");
	
	info.EnablePartySettingsButton = GetPrivateProfileInt("Custom", "EnablePartySettingsButton", 0, ".\\MainInfo.ini");
	
	info.EnableChangeClassButton = GetPrivateProfileInt("Custom", "EnableChangeClassButton", 0, ".\\MainInfo.ini");
	
	info.EnableFruitSystemButton = GetPrivateProfileInt("Custom", "EnableFruitSystemButton", 0, ".\\MainInfo.ini");

	info.EnableRankingButton = GetPrivateProfileInt("Custom", "EnableRankingButton", 0, ".\\MainInfo.ini");

	info.EnableCommandButton = GetPrivateProfileInt("Custom", "EnableCommandButton", 0, ".\\MainInfo.ini");

	info.EnableCoinStatus = GetPrivateProfileInt("Custom","EnableCoinStatus",0,".\\MainInfo.ini");

	info.EnableShopValueSystem  = GetPrivateProfileInt("Custom","EnableShopValueSystem",0,".\\MainInfo.ini");

	info.CustomStoreEnableJoB  = GetPrivateProfileInt("Custom","EnableStoreBlessButtom",0,".\\MainInfo.ini");

	info.CustomStoreEnableJoS  = GetPrivateProfileInt("Custom","EnableStoreSoulButtom",0,".\\MainInfo.ini");

	info.CustomStoreEnableJoC  = GetPrivateProfileInt("Custom","EnableStoreChaosButtom",0,".\\MainInfo.ini");

	info.CustomStoreEnableCoin1  = GetPrivateProfileInt("Custom","EnableStoreCoin1Buttom",0,".\\MainInfo.ini");

	info.CustomStoreEnableCoin2  = GetPrivateProfileInt("Custom","EnableStoreCoin2Buttom",0,".\\MainInfo.ini");

	info.CustomStoreEnableCoin3  = GetPrivateProfileInt("Custom","EnableStoreCoin3Buttom",0,".\\MainInfo.ini");

	info.CustomOffStoreEnable  = GetPrivateProfileInt("Custom","EnableOffStoreButtom",0,".\\MainInfo.ini");

	info.CustomMonsterEnable  = GetPrivateProfileInt("Custom","CustomMonsterEnable",0,".\\MainInfo.ini");
	
	info.CustomInterfaceType  = GetPrivateProfileInt("Custom","CustomInterfaceType",0,".\\MainInfo.ini");

	info.CustomRemoveCoord = GetPrivateProfileInt("Custom","CustomRemoveCoord",0,".\\MainInfo.ini");

	info.DisableBattleZoneWindow = GetPrivateProfileInt("Custom", "DisableBattleZoneWindow", 0, ".\\MainInfo.ini");

	info.CameraRange = GetPrivateProfileInt("Custom", "CameraRange", 1000.000, ".\\MainInfo.ini");
	//----------------------------------------------------------------------------------------
	info.TIME_GMT  = GetPrivateProfileInt("TimeZone","TIME_GMT",0,".\\MainInfo.ini");
	
	info.MonitorFPS  = GetPrivateProfileInt("Custom","MonitorFPS",0,".\\MainInfo.ini");

	info.MonitorMS  = GetPrivateProfileInt("Custom","MonitorMS",0,".\\MainInfo.ini");

	info.LimitFPS  = GetPrivateProfileInt("Custom","LimitFPS ",0,".\\MainInfo.ini");
	
	info.EffectPlus15  = GetPrivateProfileInt("Effect","EffectPlus15",0,".\\MainInfo.ini");

	info.DisablePartyHpBar  = GetPrivateProfileInt("Disable","DisablePartyHpBar",0,".\\MainInfo.ini");
	
	info.DisableGens  = GetPrivateProfileInt("Disable","DisableGens ",0,".\\MainInfo.ini");

	info.DisableTabMap  = GetPrivateProfileInt("Disable","DisableTabMap ",0,".\\MainInfo.ini");

	info.DisableHelper  = GetPrivateProfileInt("Disable","DisableHelper ",0,".\\MainInfo.ini");

	info.DisableAdvance  = GetPrivateProfileInt("Disable","DisableAdvance",0,".\\MainInfo.ini");
	
	info.DisableCustomClaws  = GetPrivateProfileInt("Disable","DisableCustomClaws ",0,".\\MainInfo.ini");

	info.DisableCustomBow  = GetPrivateProfileInt("Disable","DisableCustomBow ",0,".\\MainInfo.ini");

	info.DisableCustomCloack  = GetPrivateProfileInt("Disable","DisableCustomCloack ",0,".\\MainInfo.ini");

	info.DisableCustomPosition  = GetPrivateProfileInt("Disable","DisableCustomPosition ",0,".\\MainInfo.ini");

	info.DisableCustomPet  = GetPrivateProfileInt("Disable","DisableCustomPet ",0,".\\MainInfo.ini");

	info.DisableEffectRemake  = GetPrivateProfileInt("Disable","DisableEffectRemake ",0,".\\MainInfo.ini");

	info.DisableSocketInvetori  = GetPrivateProfileInt("Disable","DisableSocketInvetori ",0,".\\MainInfo.ini");

	info.DisableRepeirInInventory  = GetPrivateProfileInt("Disable","DisableRepeirInInventory ",0,".\\MainInfo.ini");

	info.DisableButtonOpenStore  = GetPrivateProfileInt("Disable","DisableButtonOpenStore ",0,".\\MainInfo.ini");

	info.DisableButtonInventoryExt  = GetPrivateProfileInt("Disable","DisableButtonInventoryExt ",0,".\\MainInfo.ini");

	info.DisableButtonQuestInStats  = GetPrivateProfileInt("Disable","DisableButtonQuestInStats ",0,".\\MainInfo.ini");

	info.DisableButtonPetsInStats  = GetPrivateProfileInt("Disable","DisableButtonPetsInStats ",0,".\\MainInfo.ini");

	info.DisableButtonSkillMaster  = GetPrivateProfileInt("Disable","DisableButtonSkillMaster ",0,".\\MainInfo.ini");

	info.DisableBCDSCCMaster = GetPrivateProfileInt("Disable", "DisableBCDSCCMaster ", 0, ".\\MainInfo.ini");

	info.Disable380MixChaosMachine = GetPrivateProfileInt("Disable", "Disable380MixChaosMachine ", 0, ".\\MainInfo.ini");

	info.DisableWCoinCCashShop = GetPrivateProfileInt("Disable", "DisableWCoinCCashShop ", 0, ".\\MainInfo.ini");

	info.DisableWCoinPCashShop = GetPrivateProfileInt("Disable", "DisableWCoinPCashShop ", 0, ".\\MainInfo.ini");

	info.DisableWCoinGCashShop = GetPrivateProfileInt("Disable", "DisableWCoinGCashShop ", 0, ".\\MainInfo.ini");

	info.SelectCharAnimate  = GetPrivateProfileInt("UPGRADE","SelectCharAnimate ",0,".\\MainInfo.ini");

	info.SelectCharS13  = GetPrivateProfileInt("UPGRADE","SelectCharS13 ",0,".\\MainInfo.ini");

	info.CustomSelectServerX700 = GetPrivateProfileInt("UPGRADE", "CustomSelectServerX700 ", 0, ".\\MainInfo.ini");

	info.CustomEffectEarthQuake = GetPrivateProfileInt("UPGRADE", "CustomEffectEarthQuake ", 0, ".\\MainInfo.ini");

	info.InventoryUPGRADE  = GetPrivateProfileInt("UPGRADE","InventoryUPGRADE ",0,".\\MainInfo.ini");

	info.CameraZoom  = GetPrivateProfileInt("UPGRADE","CameraZoom ",0,".\\MainInfo.ini");

	info.WeatherFix = GetPrivateProfileInt("UPGRADE", "WeatherFix ", 0, ".\\MainInfo.ini");

	gCustomMessage.Load("Custom\\CustomMessage.txt");

	gCustomJewel.Load("Custom\\CustomJewel.txt");

	gCustomWing.Load("Custom\\CustomWing.txt");

	gCustomItem.Load("Custom\\CustomItem.txt");

	gCustomBuyVip.Load("Custom\\CustomBuyVip.txt");

	gCustomCommandInfo.Load("Custom\\CustomCommandInfo.txt");

	//gCustomEventTimeText.Load("CustomEventTimeText.txt");

	gSmokeEffect.Load("Custom\\CustomSmokeEffect.txt");

	gFog.Load("Custom\\CustomFog.txt");

	gMonsters.Load("Custom\\CustomMonster.txt");

	gNPCName.Load("Custom\\CustomNPCName.txt");
	//--
	gCustomGloves.Load("Custom\\CustomGloves.txt");

	gCustomCrossBow.Load("Custom\\CustomCrossbow.txt");

	gCustomPet2.Load("Custom\\CustomPet.txt");

	gCloak.Load("Custom\\CustomCloak.txt");

	gCustomPosition.Load("Custom\\CustomItemPosition.txt");

	gCustomRemake.Load("Custom\\CustomEffectRemake.txt");

	gItemManager.Load("Custom\\Item.txt");

	gCustomModelEffect.Load("Custom\\CustomModelEffect.txt");

	gEventText.Load("Custom\\CustomEventTimerText.txt");

	gMonster.Load("Custom\\CustomMonsterHealthBar.txt");

	gCustomEarthQuake.Load("Custom\\CustomEarthQuake.txt");

	memcpy(info.EngCustomMessageInfo,gCustomMessage.m_EngCustomMessageInfo,sizeof(info.EngCustomMessageInfo));

	memcpy(info.PorCustomMessageInfo,gCustomMessage.m_PorCustomMessageInfo,sizeof(info.PorCustomMessageInfo));

	memcpy(info.SpnCustomMessageInfo,gCustomMessage.m_SpnCustomMessageInfo,sizeof(info.SpnCustomMessageInfo));

	memcpy(info.CustomJewelInfo,gCustomJewel.m_CustomJewelInfo,sizeof(info.CustomJewelInfo));

	memcpy(info.CustomWingInfo,gCustomWing.m_CustomWingInfo,sizeof(info.CustomWingInfo));

	memcpy(info.CustomItemInfo,gCustomItem.m_CustomItemInfo,sizeof(info.CustomItemInfo));

	memcpy(info.CustomBuyVipInfo,gCustomBuyVip.m_CustomBuyVipInfo,sizeof(info.CustomBuyVipInfo));

	memcpy(info.CustomCommandInfo,gCustomCommandInfo.m_CustomCommandInfo,sizeof(info.CustomCommandInfo));

	memcpy(info.CustomEventInfo,gCustomEventTimeText.m_CustomEventInfo,sizeof(info.CustomEventInfo));

	memcpy(info.CustomSmokeEffect, gSmokeEffect.m_CustomSmokeEffect, sizeof(info.CustomSmokeEffect));

	memcpy(info.CustomFog, gFog.m_CustomFog, sizeof(info.CustomFog));

	memcpy(info.CustomMonsters, gMonsters.m_Monsters, sizeof(info.CustomMonsters));

	memcpy(info.CustomNPCName, gNPCName.m_CustomNpcName, sizeof(info.CustomNPCName));
//-----
	memcpy(info.CustomGloves, gCustomGloves.m_CustomGlovesInfo, sizeof(info.CustomGloves));

	memcpy(info.CustomBowInfo, gCustomCrossBow.m_CustomBowInfo, sizeof(info.CustomBowInfo));

	memcpy(info.CustomPetInfo, gCustomPet2.m_CustomPetInfo, sizeof(info.CustomPetInfo));

	memcpy(info.m_CustomCloak, gCloak.m_Cloak, sizeof(info.m_CustomCloak));

	memcpy(info.CustomPosition, gCustomPosition.m_CustomPositionInfo, sizeof(info.CustomPosition));

	memcpy(info.CustomRemake, gCustomRemake.m_CustomRemake, sizeof(info.CustomRemake));

	memcpy(info.m_ItemInfoEx, gItemManager.m_ItemInfo, sizeof(info.m_ItemInfoEx));

	memcpy(info.m_CustomModelInfo, gCustomModelEffect.m_CustomModelEffectInfo, sizeof(info.m_CustomModelInfo));

	memcpy(info.CustomEventTime, gEventText.m_EventTextInfo, sizeof(info.CustomEventTime));

	memcpy(info.CustomHpBar, gMonster.m_CustomHpBar, sizeof(info.CustomHpBar));

	memcpy(info.m_EarthQuake, gCustomEarthQuake.m_EarthQuake, sizeof(info.m_EarthQuake));

	CCRC32 CRC32;

	if (CRC32.FileCRC("Client/Main.exe", &info.ClientCRC32, 1024) == 0)
	{
		info.ClientCRC32 = 0;
	}

	if(CRC32.FileCRC("Client/Antihack.dll",&info.HackCRC32,1024) == 0)
	{
		info.HackCRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName1,&info.Plugin1CRC32,1024) == 0)
	{
		info.Plugin1CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName2,&info.Plugin2CRC32,1024) == 0)
	{
		info.Plugin2CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName3,&info.Plugin3CRC32,1024) == 0)
	{
		info.Plugin3CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName4,&info.Plugin4CRC32,1024) == 0)
	{
		info.Plugin4CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName5,&info.Plugin5CRC32,1024) == 0)
	{
		info.Plugin5CRC32 = 0;
	}

	if(CRC32.FileCRC(info.CameraName,&info.CameraCRC32,1024) == 0)
	{
		info.CameraCRC32 = 0;
	}

	DWORD MainDllCRC;
	DWORD PlayerBMDCRC;
	DWORD VerifyDllCRC;

	if (CRC32.FileCRC("Client/Main.dll", &MainDllCRC, 1024) == 0)
	{
		MainDllCRC = 0;
	}

	if (CRC32.FileCRC("Client/Data/Player/Player.BMD", &PlayerBMDCRC, 1024) == 0)
	{
		PlayerBMDCRC = 0;
	}

	if (CRC32.FileCRC("Client/Verify.dll", &VerifyDllCRC, 1024) == 0)
	{
		VerifyDllCRC = 0;
	}

	std::ofstream fout(".\\CRCInfo.txt", std::ios_base::out | std::ios_base::trunc);

	fout << "MainExeCRC = 0x" << std::hex << (DWORD)info.ClientCRC32 << std::endl;
	fout << "MainDllCRC = 0x" << std::hex << (DWORD)MainDllCRC << std::endl;
	fout << "AntihackDllCRC = 0x" << std::hex << (DWORD)info.HackCRC32 << std::endl;
	fout << "PlayerBMDCRC = 0x" << std::hex << (DWORD)PlayerBMDCRC << std::endl;
	fout << "VerifyDllCRC = 0x" << std::hex << (DWORD)VerifyDllCRC << std::endl;

	fout.close();

	for(int n=0;n < sizeof(MAIN_FILE_INFO);n++)
	{
		((BYTE*)&info)[n] ^= (BYTE)(0xDA^LOBYTE(n));
		((BYTE*)&info)[n] -= (BYTE)(0x95^HIBYTE(n));
	}

#if(PREMIUN==1)
	HANDLE file = CreateFile("Client/Data/Local/ServerInfo.bmd",GENERIC_WRITE,FILE_SHARE_READ,0,CREATE_ALWAYS,FILE_ATTRIBUTE_ARCHIVE,0);
#else
	HANDLE file = CreateFile("Free/Licencia",GENERIC_WRITE,FILE_SHARE_READ,0,CREATE_ALWAYS,FILE_ATTRIBUTE_ARCHIVE,0);
#endif

	if(file == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	DWORD OutSize = 0;

	if(WriteFile(file,&info,sizeof(MAIN_FILE_INFO),&OutSize,0) == 0)
	{
		CloseHandle(file);
		return 0;
	}

	CloseHandle(file);

	ENCODE_END

	CLEAR_END

	return 0;
}
