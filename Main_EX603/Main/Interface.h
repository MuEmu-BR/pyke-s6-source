#pragma once

#include "stdafx.h"
#include "import.h"
#include "Protect.h"

#define MAX_OBJECT 	500
#define MAX_WIN_WIDTH 640
#define MAX_WIN_HEIGHT 480

#define pDrawInterfaceNumBer   ((double(__stdcall*)(float X, float Y, int num, float size)) 0x854FE0)

#define GMT (24 + (gProtect.m_MainInfo.TIME_GMT))

enum ObjectID
{
	eFlag01=1,
	eFlag02,
	eFlag03,
	eFlag04,
	eFlag05,
	eFlag06,
	eFlag07,
	eFlag08,
	eFlag09,
	eFlag10,
	eFlag11,
	eFlag12,
	eFlag13,
	eFlag14,
	eFlag15,
	eFlag16,
	eFlag17,
	eFlag18,
	eFlag19,
	eFlag20,
	eFlag21,
	eFlag22,
	eTIME,
	eRankPANEL_MAIN,
	eRanking,
	eSAMPLEBUTTON,
	eSAMPLEBUTTON2,
	eVip_MAIN,
	eVip_TITLE,
	eVip_FRAME,
	eVip_FOOTER,
	eVip_DIV,
	eVip_CLOSE,
	eVip_BRONZE,
	eVip_SILVER,
	eVip_GOLD,
	eVip_PLATINUM,
	eVip_STATUS,
	eRanking_MAIN,
	eRanking_CLOSE,
	eRanking_TITLE,
	eRanking_FRAME,
	eRanking_FOOTER,
	eLogo,
	eEventTimePANEL_MAIN,
	eEventTime_MAIN,
	eEventTime_TITLE,
	eEventTime_CLOSE,
	eEventTime_FRAME,
	eEventTime_FOOTER,
	eMenu,
	eMenuBG,
	eMenu_MAIN,
	eMenu_TITLE,
	eMenu_FRAME,
	eMenu_FOOTER,
	eMenu_DIV,
	eMenu_CLOSE,
	eMenu_OPT1,
	eMenu_OPT2,
	eMenu_OPT3,
	eMenu_OPT4,
	eMenu_OPT5,
	eMenu_OPT6,
	eMenu_OPT7,
	eMenu_OPT8,
	eMenu_OPT20,
	eMenu_OPT30,
	eCommand_MAIN,
	eCommand_TITLE,
	eCommand_FRAME,
	eCommand_FOOTER,
	eCommand_DIV,
	eCommand_CLOSE,
	eOFFTRADE_JoB,
	eOFFTRADE_JoS,
	eOFFTRADE_JoC,
	eOFFTRADE_WCC,
	eOFFTRADE_WCP,
	eOFFTRADE_WCG,
	eOFFTRADE_OPEN,
	//Minimap
	ePLAYER_POINT,
	eNULL_MAP,
	eLORENCIA_MAP,
	eDUNGEON_MAP,
	eDEVIAS_MAP,
	eNORIA_MAP,
	eLOSTTOWER_MAP,
	eSTADIUM_MAP,
	eATLANS_MAP,
	eTarkan_MAP,
	eElbeland_MAP,
	eICARUS_MAP,
	eLANDOFTRIALS_MAP,
	eAIDA_MAP,
	eCRYWOLF_MAP,
	eKANTRU_MAP,
	eKANTRU3_MAP,
	eBARRACKS_MAP,
	eCALMNESS_MAP,
	eRAKLION_MAP,
	eVULCANUS_MAP,
	eKALRUTAN_MAP,
	eKALRUTAN2_MAP,
	eCONFIRM_MAIN,
	eCONFIRM_BTN_OK,
	eCONFIRM_BTN_CANCEL,
	eCONFIRM_TITLE,
	eCONFIRM_FRAME,
	eCONFIRM_FOOTER,
	eCONFIRM_DIV,
	eNextCommand,
	ePrevCommand,
	eNextEvent,
	ePrevEvent,
//Ex700
	eMainEx700,
	eQuest,
	eCommunity,
	eSystem,
	//--custom
	eSTORE_CLOSE,
	ex_INFO_2,
	eADVANCE_STAT_INFO,
	//--s2
	eMainS2right,
	eMainS2middle,
	eMainS2left,
	eSkillBox,
	eDragonLeft,
	eDragonRight,
	eCharacter,
	eInventory,
	eParty,
	eFriend,
	eFastMenu,
	eShop,
	eGuild,
	//--custom money
	eMoney1,
	eMoney2,
	CharacterSelect,
	CharacterSelect_Button1,
	CharacterSelect_Button2,
	CharacterSelect_Button3,
	CharacterSelect_Button4,
	CharacterSelect_Button5,
	CharacterCreate_Button1,
	CharacterCreate_Button2,
	CharacterCreate_Button3,
	CharacterCreate_Button4,
	CharacterCreate_Button5,
	CharacterCreate_Button6,
	CharacterCreate_Button7,
	CharacterCreate_SEND,
	CharacterCreate_CANCEL,
	//chat
	chatbackground,
	MINIMAP_FRAME,
	MINIMAP_TIME_FRAME,
	MINIMAP_BUTTOM,
	ButtonSettings,
	ButtonStart,
	ButtonStop,
	ButtonStartAttack,
	eCamera3DInit,
	eCamera3DSwitch,
	strucMoveInv,
	eMainEx700Exp,
	RuudShopListIzq,
	RuudShopListDer,
	RuudShopWindow,
	RuudShopExit,
	eButton1,
	eButton2,
	eButton3,
	eButton4,
	eButton5,
	eJewelOfBank,
	eJewelOfBankPush,
	eJewelOfBankRemove,
	eJewelOfBankClose,

	OBJECT_PARTYSETTINGS_MAIN,
	OBJECT_PARTYSETTINGS_TITLE,
	OBJECT_PARTYSETTINGS_FRAME,
	OBJECT_PARTYSETTINGS_FOOTER,
	OBJECT_PARTYSETTINGS_DIV,
	OBJECT_PARTYSETTINGS_CLOSE,
	OBJECT_PARTYSETTINGS_SYSTEM_ACTIVE,
	OBJECT_PARTYSETTINGS_ONLY_GUILD,
	OBJECT_PARTYSETTINGS_ONLY_ALLIANCE,
	OBJECT_PARTYSETTINGS_ONE_CLASS,
	OBJECT_PARTYSETTINGS_DARK_WIZARD,
	OBJECT_PARTYSETTINGS_DARK_KNIGHT,
	OBJECT_PARTYSETTINGS_ELF,
	OBJECT_PARTYSETTINGS_MAGIC_GLADIATOR,
	OBJECT_PARTYSETTINGS_DARK_LORD,
	OBJECT_PARTYSETTINGS_SUMMONER,
	OBJECT_PARTYSETTINGS_RAGE_FIGHTER,
	OBJECT_PARTYSETTINGS_LEVEL_MINUS,
	OBJECT_PARTYSETTINGS_LEVEL_PLUS,
	OBJECT_PARTYSETTINGS_PASSWORD,
	OBJECT_PARTYSETTINGS_OK,
	OBJECT_PARTYSEARCH_LEFT,
	OBJECT_PARTYSEARCH_RIGHT,
	OBJECT_PARTYSEARCH_IMAGE1,
	OBJECT_PARTYSEARCH_IMAGE2,

	OBJECT_PARTYSEARCH_MAIN,
	OBJECT_PARTYSEARCH_TITLE,
	OBJECT_PARTYSEARCH_FRAME,
	OBJECT_PARTYSEARCH_FOOTER,
	OBJECT_PARTYSEARCH_DIV,
	OBJECT_PARTYSEARCH_CLOSE,

	OBJECT_PARTYPASSWORD_MAIN,
	OBJECT_PARTYPASSWORD_TITLE,
	OBJECT_PARTYPASSWORD_FRAME,
	OBJECT_PARTYPASSWORD_FOOTER,
	OBJECT_PARTYPASSWORD_CLOSE,
	OBJECT_PARTYPASSWORD_TEXTBOX,
	OBJECT_PARTYPASSWORD_OK,

	eSTATSADD_MAIN,
	eSTATSADD_TITLE,
	eSTATSADD_FRAME,
	eSTATSADD_FOOTER,
	eSTATSADD_CLOSE,
	eSTATSADD_TEXTBOX01,
	eSTATSADD_STATBOX01,
	eSTATSADD_STATBOX02,
	eSTATSADD_STATBOX03,
	eSTATSADD_STATBOX04,
	eSTATSADD_STATBOX05,
	eSTATSADD_BTN_OK,
	eRESETSTATS_MAIN,
	eRESETSTATS_TITLE,
	eRESETSTATS_FRAME,
	eRESETSTATS_FOOTER,
	eRESETSTATS_CLOSE,
	eRESETSTATS_POINT,
	eRESETSTATS_CHECK_WC,
	eRESETSTATS_CHECK_STAT,
	eRESETMASTER_CHECK_WC,
	eRESETMASTER_CHECK_STAT,
	eRESETSTATS_BTN_OK,
	eCHARINFO_BTN_STAT,
	eCHARINFO_BTN_RESSTAT,

	eJewelsBank,
	eJEWELBANK_MAIN,
	eJEWELBANK_TITLE,
	eJEWELBANK_FRAME,
	eJEWELBANK_FOOTER,
	eJEWELBANK_POINT,
	eJEWELBANK_LINE,
	eJEWELBANK_DIV,
	eJEWELBANK_CLOSE,
	eJEWELBANK_PAGEUP1,
	eJEWELBANK_PAGEUP2,
	eJEWELBANK_PAGEUP3,
	eJEWELBANK_PAGEUP4,
	eJEWELBANK_PAGEUP5,
	eJEWELBANK_PAGEUP6,
	eJEWELBANK_PAGEUP7,
	eJEWELBANK_PAGEUP8,
	eJEWELBANK_PAGEUP9,
	eJEWELBANK_PAGEUP10,
	eJEWELBANK_PAGEUP11,
	eJEWELBANK_PAGEDN1,
	eJEWELBANK_PAGEDN2,
	eJEWELBANK_PAGEDN3,
	eJEWELBANK_PAGEDN4,
	eJEWELBANK_PAGEDN5,
	eJEWELBANK_PAGEDN6,
	eJEWELBANK_PAGEDN7,
	eJEWELBANK_PAGEDN8,
	eJEWELBANK_PAGEDN9,
	eJEWELBANK_PAGEDN10,
	eJEWELBANK_PAGEDN11,

	OBJECT_ACHIEVEMENTS_MAIN,
	OBJECT_ACHIEVEMENTS_PROGRESS_BG,
	OBJECT_ACHIEVEMENTS_PANEL,
	OBJECT_ACHIEVEMENTS_CLOSE,
	OBJECT_ACHIEVEMENTS_MISSIONS,
	OBJECT_ACHIEVEMENTS_DAMAGE,
	OBJECT_ACHIEVEMENTS_DEFENSE,
	OBJECT_ACHIEVEMENTS_LIFE,
	OBJECT_ACHIEVEMENTS_EXCELLENT,
	OBJECT_ACHIEVEMENTS_CRITICAL,

	OBJECT_WIN_QUEST_MAIN,
	OBJECT_WIN_QUEST_TITLE,
	OBJECT_WIN_QUEST_FRAME,
	OBJECT_WIN_QUEST_FOOTER,
	OBJECT_WIN_QUEST_DIV,
	OBJECT_WIN_QUEST_CLOSE,
	OBJECT_WIN_QUEST_TAB,
	OBJECT_WIN_QUEST_TAB1,
	OBJECT_WIN_QUEST_TAB2,
	OBJECT_WIN_QUEST_TAB3,
	OBJECT_WIN_QUEST_FINISH,
	OBJECT_WIN_QUEST_COUNT1,
	OBJECT_WIN_QUEST_COUNT2,
	OBJECT_WIN_QUEST_COUNT3,
	OBJECT_WIN_QUEST_INFOBG,
	OBJECT_WIN_QUEST_INFOBG2,
	OBJECT_WIN_QUEST_LINE1,
	OBJECT_WIN_QUEST_POINT1,
	OBJECT_WIN_QUEST_INFO,
	OBJECT_WIN_QUEST_INFOBG3,

	eARROW_RIGHT2,
	eARROW_LEFT2,
	eEVENTTABLE_MAIN,
	eEVENTTABLE_TITLE,
	eEVENTTABLE_LEFT,
	eEVENTTABLE_RIGHT,
	eEVENTTABLE_FOOTER,
	eEVENTTABLE_DIV,
	eEVENTTABLE_CLOSE,

	eFruitMain,
	eFruitClose,

	ePT_PERSONAL_SEARCH_MAIN,
	ePT_PERSONAL_SEARCH_TITLE,
	ePT_PERSONAL_SEARCH_FRAME,
	ePT_PERSONAL_SEARCH_FOOTER,
	ePT_PERSONAL_SEARCH_DIV,
	ePT_PERSONAL_SEARCH_CLOSE,
	ePT_PERSONAL_SEARCH_L,
	ePT_PERSONAL_SEARCH_R,
	ePT_PERSONAL_SEARCH_PAGEUP1,
	ePT_PERSONAL_SEARCH_PAGEUP2,
	ePT_PERSONAL_SEARCH_PAGEUP3,
	ePT_PERSONAL_SEARCH_PAGEUP4,
	ePT_PERSONAL_SEARCH_PAGEUP5,
	ePT_PERSONAL_SEARCH_PAGEUP6,
	ePT_PERSONAL_SEARCH_PAGEUP7,
	ePT_PERSONAL_SEARCH_PAGEUP8,
	ePT_PERSONAL_SEARCH_PAGEUP9,
	ePT_PERSONAL_SEARCH_PAGEUP10,

	eCHANGINGCLASS_MAIN,
	eCHANGINGCLASS_TITLE,
	eCHANGINGCLASS_FRAME,
	eCHANGINGCLASS_FOOTER,
	eCHANGINGCLASS_DIV,
	eCHANGINGCLASS_INFOBG,
	eCHANGINGCLASS_MONEYBG,
	eCHANGINGCLASS_CLOSE,
	eCHANGINGCLASS_DW,
	eCHANGINGCLASS_DK,
	eCHANGINGCLASS_ELF,
	eCHANGINGCLASS_MG,
	eCHANGINGCLASS_DL,
	eCHANGINGCLASS_SUM,
	eCHANGINGCLASS_RF,

	//
	ePARTYLEADER,
	ePARTYLEADER2,
	ePARTYLEADER3,
	ePARTYLEADER4,
	ePARTYTRACE,
	ePARTYTRACE2,
	ePARTYTRACE3,
	ePARTYTRACE4,
	ePARTYTRACE5,

	eRESET_MAIN,
	eRESET_TITLE,
	eRESET_FRAME,
	eRESET_FOOTER,
	eRESET_DIV,
	eRESET_INFOBG,
	eRESET_MONEYBG,
	eRESET_CLOSE,
	eRESET_FINISH,

	eWAREHOUSE_MAIN,
	eWAREHOUSE_TITLE,
	eWAREHOUSE_FRAME,
	eWAREHOUSE_FOOTER,
	eWAREHOUSE_DIV,
	eWAREHOUSE_CLOSE,
	eWAREHOUSE_NUM1,
	eWAREHOUSE_NUM2,
	eWAREHOUSE_NUM3,
	eWAREHOUSE_NUM4,
	eWAREHOUSE_NUM5,
	eWAREHOUSE_NUM6,
	eWAREHOUSE_NUM7,
	eWAREHOUSE_NUM8,

	// ----
	eSETTINGS_MAIN,
	eSETTINGS_TITLE,
	eSETTINGS_FRAME,
	eSETTINGS_FOOTER,
	eSETTINGS_DIV,
	eSETTINGS_CLOSE,
	eSETTINGS_OPTION,
	eSETTINGS_LINE,
	eSETTINGS_CHECKBOX1,
	eSETTINGS_CHECKBOX2,
	eSETTINGS_CHECKBOX3,
	eSETTINGS_CHECKBOX4,
	eSETTINGS_CHECKBOX5,
	eSETTINGS_CHECKBOX6,
	eSETTINGS_CHECKBOX7,
	eSETTINGS_CHECKBOX8,
	eSETTINGS_CHECKBOX9,
	eSETTINGS_CHECKBOX10,
	eSETTINGS_CHECKBOX11,
	eSETTINGS_CHECKBOX12,

	eCAMERA_MAIN,
	eCAMERA_BUTTON1,
	eCAMERA_BUTTON2,
	eCAMERA_BUTTON3,

	iNewuiDialogHr = 0x9308,
	iGfxDialoge = 0x9309,
};

struct InterfaceElement
{
	DWORD	ModelID;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	BYTE	Attribute;
	char	StatValue[20];
	bool	FirstLoad;
	bool	ByClose;
	BYTE	Speed;
	long	OpenedValue;

	void Open()
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->ByClose = false;
	};

	void Open(int Value, int Speed)
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
		this->FirstLoad = true;
	};

	void Close()
	{
		this->OnShow = false;
		pSetCursorFocus = false;
		this->ByClose = false;
	};

	void Close(int Value, int Speed)
	{
		this->OnShow = false; pSetCursorFocus = false;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
	}

	void CloseAnimated(int Speed)
	{
		pSetCursorFocus = false;
		//this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = true;
	}
};

class Interface
{
public:
	int ConfirmSlot;
	float PetY;
	float PetX;
	int lastReport;
	int frameCount;
	int frameRate;
	char FPS_REAL[30];
	void UPDATE_FPS();
	void guiMonitore();
	int iniciador;
	int msPing;
	int lastSend;
	int validar;
	char ServerPing[50];
	char ultimoPing[50];
	int ultimo_Ping;
	char ServerRTT[50];
	char ultimoRTT[50];
	int ultimo_RTT;
	InterfaceElement Data[MAX_OBJECT];
public:
	Interface();
	virtual ~Interface();
	void RenderObjectSystem();
	static void LoadImages();
	static void LoadModels();
	static void Work();
	void        WindowsKG();
//-- System Windows
	void OpenVipWindow(){ this->Data[eVip_MAIN].OnShow = true; };
	void CloseVipWindow() { this->Data[eVip_MAIN].OnShow = false; }
	bool CheckVipWindow() { return this->Data[eVip_MAIN].OnShow; };
	void DrawVipWindow();
	bool EventVipWindow_Main(DWORD Event);
	bool EventVipWindow_Close(DWORD Event);
	bool EventVipWindow_Bronze(DWORD Event);
	bool EventVipWindow_Silver(DWORD Event);
	bool EventVipWindow_Gold(DWORD Event);
	bool EventVipWindow_Platinum(DWORD Event);
	bool EventVipWindow_StatusVip(DWORD Event);
	//--
	//Menu
	void		DrawMenu();
	bool		EventDrawMenu_Open(DWORD Event);
	void		OpenMenuWindow() { this->Data[eMenu_MAIN].OnShow = true; };// pSetCursorFocus = true; };
	void		CloseMenuWindow() { this->Data[eMenu_MAIN].OnShow = false; };// pSetCursorFocus = false; };
	bool		CheckMenuWindow() { return this->Data[eMenu_MAIN].OnShow; };
	void		DrawMenuOpen();
	bool		EventDrawMenu_Close(DWORD Event);
	bool		EventDrawMenu_Op1(DWORD Event);
	bool		EventDrawMenu_Op2(DWORD Event);
	bool		EventDrawMenu_Op3(DWORD Event);
	bool		EventDrawMenu_Op4(DWORD Event);
	bool		EventDrawMenu_Op5(DWORD Event);
	bool		EventDrawMenu_Op6(DWORD Event);
	bool		EventDrawMenu_Op7(DWORD Event);
	bool		EventDrawMenu_Op8(DWORD Event);
	bool		EventDrawMenu_Op20(DWORD Event);
	bool		EventDrawMenu_Op30(DWORD Event);
	//--
	void DrawConfirmOpen();
	bool EventConfirm_OK(DWORD Event);
	bool EventConfirm_CANCEL(DWORD Event);
//-- Funtions
	void BindObject(short ObjectID, DWORD ModelID, float Width, float Height, float X, float Y);
	void DrawGUI(short ObjectID, float PosX, float PosY);
	void DrawGUI2(short ObjectID, float PosX, float PosY);
	void DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawTimeUI();
	int DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	void DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void ResetDrawIMG(short ObjectID);
	int DrawMessage(int Mode, LPCSTR Text, ...);
	void DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	bool IsWorkZone2(float X, float Y, float MaxX, float MaxY);
	bool IsWorkZone(short ObjectID);
	float GetResizeX(short ObjectID);
	int DrawToolTip(int X, int Y, LPCSTR Text, ...);
	float DrawRepeatGUI(short MonsterID, float X, float Y, int Count);
	float DrawRepeatGUIScale(short MonsterID, float X, float Y,float ScaleX, float ScaleY, int Count);
	void DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color);
	void DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawLogo(bool active);
	void CloseCustomWindow();
	//Mini Map
	void DrawMiniMap();
	bool MiniMapCheck();
	bool CombinedChecks();
	bool CheckMap();
	void SwitchMiniMap();
	// ex700
	void DrawInterfaceCustom();
	// s2
	void DrawInterfaceS2Menu();
	void DrawInterface97Menu();
	void EventNewInterface_All(DWORD Event);
	void EventNewInterface97_All(DWORD Event);
	void DrawCoord();
	void DrawInterfaceDragonLS3();
	void DrawInterfaceDragonRS3();
	// Advanced Stats
	void DrawBarForm(float PosX,float PosY,float Width,float Height,GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	//--
	void OpenConfig(int type);
	void SwitchCamera();
	void SwitchChatExpand();
	void CameraInit();
	bool Button(DWORD Event, int WinID, int ButtonID, bool Type);
	void DrawPing();
	void SendPingRecv();

	static void DrawZenAndRud(int a1, int a2, int a3, int a4);

	void DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	void DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color);
	int DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...);

	void		DrawStatsAddWindow();
	void		EventStatsAddWindow(DWORD Event);
	void		EventStatsAddWindow_Close(DWORD Event);
	void		SwitchStatsWindowState() { (Data[eSTATSADD_MAIN].OnShow == true) ? Data[eSTATSADD_MAIN].CloseAnimated(15) : Data[eSTATSADD_MAIN].Open(-226, 20); };
	void		CloseStatsAddWindow() { this->Data[eSTATSADD_MAIN].OnShow = false; };
	//
	void		DrawResetStatsWindow();
	void		EventResetStatsWindow(DWORD Event);
	void		EventResetStatsWindow_Close(DWORD Event);
	void		SwitchResetStatsWindowState() { (Data[eRESETSTATS_MAIN].OnShow == true) ? Data[eRESETSTATS_MAIN].Close() : Data[eRESETSTATS_MAIN].Open(); };
	void		CloseResetStatsWindow() { this->Data[eRESETSTATS_MAIN].OnShow = false; };
	void		EventCharacterWindow(DWORD Event);
	void	DrawAnimatedGUI(short ObjectID, float PosX, float PosY);
	void	DrawColoredAnimatedGUI(short ObjectID, float X, float Y, DWORD Color);
	void	DrawAnimatedButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void		DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text);
	bool		ButtonEx(DWORD Event, int ButtonID, bool Type);
	void		DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	void	TextDraw(int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align, HGDIOBJ Font, LPCTSTR Format, ...);

	void		DrawEventTableWindow();
	void		EventEventTableWindow(DWORD Event);
	void		CloseEventTableWindow() { this->Data[eEVENTTABLE_MAIN].OnShow = false; };
	
	bool		CursorZoneButton(float X, float Y, float MaxX, float MaxY);

	void		DrawFruit();
	void		EventFruitWindow_Main(DWORD Event);
	void		Fruit_State(){ (Data[eFruitMain].OnShow == true) ? Data[eFruitMain].Close() : Data[eFruitMain].Open(); };
	void		CloseFruitWindow() { this->Data[eFruitMain].OnShow = false; };

	bool		CheckWindow(int WindowID);
	int			CloseWindow(int WindowID);
	int			OpenWindow(int WindowID);
	bool		CheckWindowEx(int WindowID);
	void		OpenWindowEx(int WindowID);
	void		CloseWindowEx(int WindowID);
	//
	void		DrawChangingClassWindow();
	void		ChangingClassWindowState(){ (Data[eCHANGINGCLASS_MAIN].OnShow == true) ? Data[eCHANGINGCLASS_MAIN].Close() : Data[eCHANGINGCLASS_MAIN].Open(); };
	void		EventChangingClassWindow_Main(DWORD Event);
	void		CloseChangingClassWindow() { this->Data[eCHANGINGCLASS_MAIN].OnShow = false; };
	//
	void PartyInterface();
	void EventPartyInterface(DWORD Event);
	//--
	// ----
	void		DrawResetWindow();
	bool		EventResetWindow_Main(DWORD Event);
	bool		EventResetWindow_Close(DWORD Event);
	bool		EventResetWindow_Finish(DWORD Event);
	// ----
	// ----
	void		DrawWarehouseWindow();
	void		EventWarehouseWindow_Main(DWORD Event);
	void		EventWarehouseWindow_Close(DWORD Event);
	// ----
	void		EventCameraUI(DWORD Event);
	//void		DrawCameraUI();
	// ----
	void		DrawSettingsUI();
	void		EventSettingsUI(DWORD Event);
	void		SwitchSettingsWindowState() { (Data[eSETTINGS_MAIN].OnShow == true) ? Data[eSETTINGS_MAIN].Close() : Data[eSETTINGS_MAIN].Open(); };
	// ----
	BYTE m_SettingButton;
	BYTE m_RolltheDiceButton;
	BYTE m_HeadsTailsButton;
	BYTE m_LuckyNumberButton;
	BYTE m_SmithItemButton;
	BYTE m_TitleManagerButton;
	BYTE m_PartySearchSettingButton;
	BYTE m_OffAttackButton;
	BYTE m_BuyVipButton;
	BYTE m_ChangeClassButton;
	BYTE m_ResetPointCheckBox;
	BYTE m_ResetPointCheckBox1;
	BYTE m_ResetMasterSkillCheckBox;
	BYTE m_ResetMasterSkillCheckBox1;
	BYTE m_AccountSecurityButton;
	BYTE m_JewelsBankButton;
	BYTE m_RenameButton;
	BYTE m_TopPlayer;
	BYTE m_PShopCurrency;
	BYTE m_PShopOffStore;
	BYTE m_RPSMode;
	BYTE m_NewsBoard;
	BYTE m_FruitMain;
	BYTE m_LuckySpinMain;
	BYTE m_GiftCode;
	BYTE m_PSBless;
	BYTE m_PSSoul;
	BYTE m_PSChaos;
	BYTE m_PSWcoinC;
	BYTE m_PSWcoinP;
	BYTE m_PSWcoinG;
	BYTE m_QuickAdd;
	BYTE m_ResetStats;
	BYTE m_EventTimer;
	BYTE m_CustomWare;
	BYTE m_PartyLeader;
	BYTE m_PartyTrace;

	long long m_TimeDiff;
	//--
private:
	
};
extern Interface gInterface;
