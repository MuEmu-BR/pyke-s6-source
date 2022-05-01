#include "stdafx.h"
#include "PartySearchSettings.h"
#include "Interface.h"
#include "Console.h"
#include "Offset.h"
#include "Protect.h"
#include "Defines.h"
//#include "Protocol.h"

cPartySearchSettings gPartySearchSettings;

cPartySearchSettings::cPartySearchSettings()
{
	this->m_SystemActive = false;
	this->m_OnlyGuild = false;
	this->m_OnlyAlliance = false;
	this->m_OneClass = false;
	this->m_DarkWizard = false;
	this->m_DarkKnight = false;
	this->m_Elf = false;
	this->m_MagicGladiator = false;
	this->m_DarkLord = false;
	this->m_Summoner = false;
	this->m_RageFighter = false;
	this->m_Level = 400;
	//
}

cPartySearchSettings::~cPartySearchSettings()
{

}

void cPartySearchSettings::draw_party_settings_window()
{
	if (!gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].OnShow)
	{
		return;
	}
	// ----
	float MainWidth = 230.0;
	float StartY = 23.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);

	pSetCursorFocus = true;
	// ----
	gInterface.DrawGUI(OBJECT_PARTYSETTINGS_MAIN, StartX, StartY + 2);
	gInterface.DrawGUI(OBJECT_PARTYSETTINGS_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(OBJECT_PARTYSETTINGS_FRAME, StartX, StartY + 67.0, 18);
	gInterface.DrawGUI(OBJECT_PARTYSETTINGS_FOOTER, StartX, StartY);
	gInterface.DrawGUI(OBJECT_PARTYSETTINGS_CLOSE, StartX + MainWidth - gInterface.Data[OBJECT_PARTYSETTINGS_CLOSE].Width + 2, 22);
	// ----
	if (gInterface.IsWorkZone(OBJECT_PARTYSETTINGS_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[OBJECT_PARTYSETTINGS_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(OBJECT_PARTYSETTINGS_CLOSE, gInterface.Data[OBJECT_PARTYSETTINGS_CLOSE].X, gInterface.Data[OBJECT_PARTYSETTINGS_CLOSE].Y, Color);
		gInterface.DrawToolTip(gInterface.Data[OBJECT_PARTYSETTINGS_CLOSE].X + 5, gInterface.Data[OBJECT_PARTYSETTINGS_CLOSE].Y + 25, "Close");
	}
	// ----
	gInterface.DrawText(eGold, StartX + 10, 33, 210, 3, "Party Search Settings");
	///////////////////////////////////////////ACTIVE SYSTEM///////////////////////////////////////////
	gInterface.DrawText(eWhite, StartX + 40, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 33, 200, 1, "Active System");

	if (gPartySearchSettings.m_SystemActive == false)
	{
		gInterface.DrawButton(OBJECT_PARTYSETTINGS_SYSTEM_ACTIVE, ButtonX + 110, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 30, 0, 0);
	}
	else
	{
		gInterface.DrawButton(OBJECT_PARTYSETTINGS_SYSTEM_ACTIVE, ButtonX + 110, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 30, 0, 15);
	}
	gInterface.DrawGUI(OBJECT_PARTYSETTINGS_DIV, StartX, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 40); // Делитель большой
/////////////////////////////////////////ACTIVE SYSTEM END/////////////////////////////////////////

/////////////////////////////////////////////MAX LEVEL/////////////////////////////////////////////
	gInterface.DrawText(eWhite, StartX + 40, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 60, 200, 1, "Max Level");
	//gInterface.DrawGUI(OBJECT_PARTYSETTINGS_DIV, StartX , gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 67); // Делитель большой
	pDrawGUI(0x7B5E, StartX + 30, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 73, 82.0, 2.0); // Делитель мелкий 1
	pDrawGUI(0x7B5E, StartX + 30 + 82, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 73, 82.0, 2.0); // Делитель мелкий 2

	gInterface.DrawToolTip(StartX + 174, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 62, "%d", gPartySearchSettings.m_Level);

	if (gPartySearchSettings.m_SystemActive == 0)
	{
		gInterface.DrawColoredButton(OBJECT_PARTYSETTINGS_LEVEL_MINUS, StartX + 150, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 57, 0, 0, eGray150); // 
	}
	else
	{
		gInterface.DrawButton(OBJECT_PARTYSETTINGS_LEVEL_MINUS, StartX + 150, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 57, 0, 0); // 

		if (gInterface.IsWorkZone(OBJECT_PARTYSETTINGS_LEVEL_MINUS))
		{
			if (gInterface.Data[OBJECT_PARTYSETTINGS_LEVEL_MINUS].OnClick)
			{
				gInterface.DrawButton(OBJECT_PARTYSETTINGS_LEVEL_MINUS, StartX + 150, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 57, 0, 16);
			}
		}
	}

	if (gPartySearchSettings.m_SystemActive == 0)
	{
		gInterface.DrawColoredButton(OBJECT_PARTYSETTINGS_LEVEL_PLUS, StartX + 193, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 57, 0, 0, eGray150); //
	}
	else
	{
		gInterface.DrawButton(OBJECT_PARTYSETTINGS_LEVEL_PLUS, StartX + 193, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 57, 0, 0); //

		if (gInterface.IsWorkZone(OBJECT_PARTYSETTINGS_LEVEL_PLUS))
		{
			if (gInterface.Data[OBJECT_PARTYSETTINGS_LEVEL_PLUS].OnClick)
			{
				gInterface.DrawButton(OBJECT_PARTYSETTINGS_LEVEL_PLUS, StartX + 193, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 57, 0, 16);
			}
		}
	}

	///////////////////////////////////////////MAX LEVEL END///////////////////////////////////////////

	/////////////////////////////////////////////PASSWORD//////////////////////////////////////////////

	if (gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].FirstLoad == true)
	{
		if (strlen(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue) == 0)
			sprintf(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue, "NONE");
	}

	gInterface.DrawGUI(OBJECT_PARTYSETTINGS_PASSWORD, StartX + 28, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 76);
	if (gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].Attribute == 1)
	{
		gInterface.DrawColoredGUI(OBJECT_PARTYSETTINGS_PASSWORD, StartX + 28, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 76, eGray100);
	}

	gInterface.DrawText(eWhite, StartX + 40, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 82, 200, 1, "Password");

	gInterface.DrawText(eWhite, StartX + 50, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 82, 200, 3, gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue);

	pDrawGUI(0x7B5E, StartX + 30, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 95, 82.0, 2.0); // Делитель мелкий 1
	pDrawGUI(0x7B5E, StartX + 30 + 82, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 95, 82.0, 2.0); // Делитель мелкий 2

///////////////////////////////////////////PASSWORD END////////////////////////////////////////////

///////////////////////////////////////////////GUILD///////////////////////////////////////////////

	gInterface.DrawText(eWhite, StartX + 40, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + /*87*/104, 200, 1, "Only Guild");

	if (gPartySearchSettings.m_SystemActive)
	{
		if (gPartySearchSettings.m_OnlyGuild == false)
		{
			gInterface.DrawButton(OBJECT_PARTYSETTINGS_ONLY_GUILD, ButtonX + 110, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 100, 0, 0);
		}
		else
		{
			gInterface.DrawButton(OBJECT_PARTYSETTINGS_ONLY_GUILD, ButtonX + 110, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 100, 0, 15);
		}
	}
	else
	{
		gInterface.DrawButton(OBJECT_PARTYSETTINGS_ONLY_GUILD, ButtonX + 110, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + /*83*/100, 0, 30);
	}

	pDrawGUI(0x7B5E, StartX + 30, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + /*100*/117, 82.0, 2.0); // Делитель мелкий 1
	pDrawGUI(0x7B5E, StartX + 30 + 82, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 117, 82.0, 2.0); // Делитель мелкий 2

	gInterface.DrawText(eWhite, StartX + 40, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 126, 200, 1, "Only Alliance");

	if (gPartySearchSettings.m_SystemActive)
	{
		if (gPartySearchSettings.m_OnlyAlliance == false)
		{
			gInterface.DrawButton(OBJECT_PARTYSETTINGS_ONLY_ALLIANCE, ButtonX + 110, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 122, 0, 0);
		}
		else
		{
			gInterface.DrawButton(OBJECT_PARTYSETTINGS_ONLY_ALLIANCE, ButtonX + 110, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 122, 0, 15);
		}
	}
	else
	{
		gInterface.DrawButton(OBJECT_PARTYSETTINGS_ONLY_ALLIANCE, ButtonX + 110, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 122, 0, 30);
	}

	pDrawGUI(0x7B5E, StartX + 30, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 139, 82.0, 2.0); // Делитель мелкий 1
	pDrawGUI(0x7B5E, StartX + 30 + 82, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 139, 82.0, 2.0); // Делитель мелкий 2

	gInterface.DrawText(eWhite, StartX + 40, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 148, 200, 1, "Only One Class");

	if (gPartySearchSettings.m_SystemActive)
	{
		if (gPartySearchSettings.m_OneClass == false)
		{
			gInterface.DrawButton(OBJECT_PARTYSETTINGS_ONE_CLASS, ButtonX + 110, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 144, 0, 0);
		}
		else
		{
			gInterface.DrawButton(OBJECT_PARTYSETTINGS_ONE_CLASS, ButtonX + 110, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 144, 0, 15);
		}
	}
	else
	{
		gInterface.DrawButton(OBJECT_PARTYSETTINGS_ONE_CLASS, ButtonX + 110, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 144, 0, 30);
	}

	gInterface.DrawGUI(OBJECT_PARTYSETTINGS_DIV, StartX, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 154);// 94 // Делитель большой
/////////////////////////////////////////////GUILD END/////////////////////////////////////////////
	char szCharNames[7][32] =
	{
		"Dark Wizard",
		"Dark Knight",
		"Elf",
		"Magic Gladiator",
		"Dark Lord",
		"Summoner",
		"Rage Fighter"
	};

	int ObjectIDs[7] =
	{
		OBJECT_PARTYSETTINGS_DARK_WIZARD,
		OBJECT_PARTYSETTINGS_DARK_KNIGHT,
		OBJECT_PARTYSETTINGS_ELF,
		OBJECT_PARTYSETTINGS_MAGIC_GLADIATOR,
		OBJECT_PARTYSETTINGS_DARK_LORD,
		OBJECT_PARTYSETTINGS_SUMMONER,
		OBJECT_PARTYSETTINGS_RAGE_FIGHTER
	};

	for (int i = 0; i < gProtect.m_MainInfo.MaxClassTypes; i++)
	{
		gInterface.DrawText(eWhite, StartX + 40, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 135 + 22 + 17 + (i * 22), 200, 1, szCharNames[i]);

		bool ClassValue = 0;
		switch (i)
		{
		case 0:
			ClassValue = gPartySearchSettings.m_DarkWizard;
			break;
		case 1:
			ClassValue = gPartySearchSettings.m_DarkKnight;
			break;
		case 2:
			ClassValue = gPartySearchSettings.m_Elf;
			break;
		case 3:
			ClassValue = gPartySearchSettings.m_MagicGladiator;
			break;
		case 4:
			ClassValue = gPartySearchSettings.m_DarkLord;
			break;
		case 5:
			ClassValue = gPartySearchSettings.m_Summoner;
			break;
		case 6:
			ClassValue = gPartySearchSettings.m_RageFighter;
			break;
		}

		if (gPartySearchSettings.m_SystemActive)
		{
			if (ClassValue == false)
			{
				gInterface.DrawButton(ObjectIDs[i], ButtonX + 110, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 131 + 22 + 17 + (i * 22), 0, 0);
			}
			else
			{
				gInterface.DrawButton(ObjectIDs[i], ButtonX + 110, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 131 + 22 + 17 + (i * 22), 0, 15);
			}
		}
		else
		{
			gInterface.DrawButton(ObjectIDs[i], ButtonX + 110, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 131 + 22 + 17 + (i * 22), 0, 30);
		}

		if (i != 0)
		{
			pDrawGUI(0x7B5E, StartX + 30, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 148 + 17 + (i * 22), 82.0, 2.0); // Делитель мелкий 1
			pDrawGUI(0x7B5E, StartX + 30 + 82, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 148 + 17 + (i * 22), 82.0, 2.0); // Делитель мелкий 2
		}
	}

	gInterface.DrawGUI(OBJECT_PARTYSETTINGS_DIV, StartX, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 295 + 17); // Делитель большой
	gInterface.DrawButton(OBJECT_PARTYSETTINGS_OK, StartX + gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Width / 2 - gInterface.Data[OBJECT_PARTYSETTINGS_OK].Width / 2, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 310 + 17, 0, 0);

	if (gInterface.IsWorkZone(OBJECT_PARTYSETTINGS_OK))
	{
		int ScaleY = 30;
		// ----
		if (gInterface.Data[OBJECT_PARTYSETTINGS_OK].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		gInterface.DrawButton(OBJECT_PARTYSETTINGS_OK, StartX + gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Width / 2 - gInterface.Data[OBJECT_PARTYSETTINGS_OK].Width / 2, gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Y + 310 + 17, 0, ScaleY);
	}
	if (gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].FirstLoad == true)
	{
		gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].FirstLoad = false;
	}
}

void cPartySearchSettings::party_search_settings_switch_state()
{
	gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].OnShow == true ? gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Close() : gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].Open();
}

void cPartySearchSettings::event_party_search_settings_window(DWORD Event)
{
	if (!gInterface.Data[OBJECT_PARTYSETTINGS_MAIN].OnShow)
	{
		return;
	}

	const DWORD CurrentTick = GetTickCount();

	if (gInterface.IsWorkZone(OBJECT_PARTYSETTINGS_PASSWORD))
	{
		gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].Attribute = 1;
	}
	else
	{
		gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].Attribute = 0;
	}
	
	if (gInterface.IsWorkZone(OBJECT_PARTYSETTINGS_CLOSE))
	{
		const DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYSETTINGS_CLOSE].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_PARTYSETTINGS_CLOSE].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_CLOSE].EventTick = GetTickCount();
		this->party_search_settings_switch_state();
	}

	if (gInterface.IsWorkZone(OBJECT_PARTYSETTINGS_SYSTEM_ACTIVE))
	{
		const DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYSETTINGS_SYSTEM_ACTIVE].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_PARTYSETTINGS_SYSTEM_ACTIVE].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_SYSTEM_ACTIVE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_SYSTEM_ACTIVE].EventTick = GetTickCount();
		gPartySearchSettings.m_SystemActive ^= 1;

		for (int i = 0; i < gProtect.m_MainInfo.MaxClassTypes; i++)
		{
			gPartySearchSettings.m_SystemActive == true ? gPartySearchSettings.set_class_value(i, true) : gPartySearchSettings.set_class_value(i, false);
		}
	}

	if (gInterface.IsWorkZone(OBJECT_PARTYSETTINGS_LEVEL_MINUS))
	{
		if (gPartySearchSettings.m_SystemActive == 0)
		{
			return;
		}

		const DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYSETTINGS_LEVEL_MINUS].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_PARTYSETTINGS_LEVEL_MINUS].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_LEVEL_MINUS].OnClick = false;
		// ----
		if (Delay < 200)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_LEVEL_MINUS].EventTick = GetTickCount();

		gPartySearchSettings.m_Level -= 10;
		if (gPartySearchSettings.m_Level <= 0)
		{
			gPartySearchSettings.m_Level = 0;
		}
	}

	if (gInterface.IsWorkZone(OBJECT_PARTYSETTINGS_LEVEL_PLUS))
	{
		if (gPartySearchSettings.m_SystemActive == 0)
		{
			return;
		}

		DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYSETTINGS_LEVEL_PLUS].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_PARTYSETTINGS_LEVEL_PLUS].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_LEVEL_PLUS].OnClick = false;
		// ----
		if (Delay < 200)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_LEVEL_PLUS].EventTick = GetTickCount();

		gPartySearchSettings.m_Level += 10;
		if (gPartySearchSettings.m_Level >= 400)
		{
			gPartySearchSettings.m_Level = 400;
		}
	}

	if (gInterface.IsWorkZone(OBJECT_PARTYSETTINGS_ONLY_GUILD))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYSETTINGS_ONLY_GUILD].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_PARTYSETTINGS_ONLY_GUILD].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_ONLY_GUILD].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_ONLY_GUILD].EventTick = GetTickCount();
		gPartySearchSettings.m_OnlyGuild ^= 1;
	}

	if (gInterface.IsWorkZone(OBJECT_PARTYSETTINGS_ONLY_ALLIANCE))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYSETTINGS_ONLY_ALLIANCE].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_PARTYSETTINGS_ONLY_ALLIANCE].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_ONLY_ALLIANCE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_ONLY_ALLIANCE].EventTick = GetTickCount();
		gPartySearchSettings.m_OnlyAlliance ^= 1;
	}

	if (gInterface.IsWorkZone(OBJECT_PARTYSETTINGS_ONE_CLASS))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYSETTINGS_ONE_CLASS].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_PARTYSETTINGS_ONE_CLASS].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_ONE_CLASS].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_ONE_CLASS].EventTick = GetTickCount();
		gPartySearchSettings.m_OneClass ^= 1;

		for (int i = 0; i < gProtect.m_MainInfo.MaxClassTypes; i++)
		{
			gPartySearchSettings.m_OneClass == false ? gPartySearchSettings.set_class_value(i, true) : gPartySearchSettings.set_class_value(i, false);
		}
	}

	if (gInterface.IsWorkZone(OBJECT_PARTYSETTINGS_OK))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYSETTINGS_OK].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_PARTYSETTINGS_OK].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_OK].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSETTINGS_OK].EventTick = GetTickCount();
		gPartySearchSettings.CGSendPartySearchAdd();
		this->party_search_settings_switch_state();
	}

	int ObjectIDs[7] =
	{
		OBJECT_PARTYSETTINGS_DARK_WIZARD,
		OBJECT_PARTYSETTINGS_DARK_KNIGHT,
		OBJECT_PARTYSETTINGS_ELF,
		OBJECT_PARTYSETTINGS_MAGIC_GLADIATOR,
		OBJECT_PARTYSETTINGS_DARK_LORD,
		OBJECT_PARTYSETTINGS_SUMMONER,
		OBJECT_PARTYSETTINGS_RAGE_FIGHTER
	};

	for (int i = 0; i < gProtect.m_MainInfo.MaxClassTypes; i++)
	{
		if (gInterface.IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - gInterface.Data[ObjectIDs[i]].EventTick);

			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			// ----
			gInterface.Data[ObjectIDs[i]].EventTick = GetTickCount();
			gPartySearchSettings.change_class_value(i);

			if (gPartySearchSettings.m_OneClass == true)
			{
				gPartySearchSettings.m_OneClass = false;
			}
		}
	}
}

void cPartySearchSettings::change_class_value(int ClassType)
{
	switch (ClassType)
	{
	case 0:
		this->m_DarkWizard ^= 1;
		break;
	case 1:
		this->m_DarkKnight ^= 1;
		break;
	case 2:
		this->m_Elf ^= 1;
		break;
	case 3:
		this->m_MagicGladiator ^= 1;
		break;
	case 4:
		this->m_DarkLord ^= 1;
		break;
	case 5:
		this->m_Summoner ^= 1;
		break;
	case 6:
		this->m_RageFighter ^= 1;
		break;
	}
}

void cPartySearchSettings::set_class_value(int Class, int Value)
{
	switch (Class)
	{
	case 0:
		this->m_DarkWizard = Value;
		break;
	case 1:
		this->m_DarkKnight = Value;
		break;
	case 2:
		this->m_Elf = Value;
		break;
	case 3:
		this->m_MagicGladiator = Value;
		break;
	case 4:
		this->m_DarkLord = Value;
		break;
	case 5:
		this->m_Summoner = Value;
		break;
	case 6:
		this->m_RageFighter = Value;
		break;
	}
}


void cPartySearchSettings::CGSendPartySearchAdd()
{
	PMSG_SEND_PARTYSEARCH_ADD pMsg;
	pMsg.header.set(0xFF, 0x04, sizeof(pMsg));

	pMsg.SystemActive = this->m_SystemActive;
	pMsg.OnlyGuild = this->m_OnlyGuild;
	pMsg.OnlyAlliance = this->m_OnlyAlliance;
	pMsg.OneClass = this->m_OneClass;
	pMsg.DarkWizard = this->m_DarkWizard;
	pMsg.DarkKnight = this->m_DarkKnight;
	pMsg.Elf = this->m_Elf;
	pMsg.MagicGladiator = this->m_MagicGladiator;
	pMsg.DarkLord = this->m_DarkLord;
	pMsg.Summoner = this->m_Summoner;
	pMsg.RageFighter = this->m_RageFighter;
	pMsg.Level = this->m_Level;

	if (!strcmp(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue, "NONE"))
	{
		pMsg.RequirePassword = false;
	}
	else
	{
		pMsg.RequirePassword = true;
		memcpy(pMsg.Password, gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue, sizeof(pMsg.Password));
	}

	DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void cPartySearchSettings::GCPartySettingsRecv(PMSG_PARTYSETTINGS_RECV* lpMsg)
{
	this->m_SystemActive = lpMsg->SystemActive;

	this->m_OnlyGuild = lpMsg->OnlyGuild;

	this->m_OnlyAlliance = lpMsg->OnlyAlliance;

	this->m_OneClass = lpMsg->OneClass;

	this->m_Level = lpMsg->Level;

	this->m_DarkWizard = lpMsg->DarkWizard;

	this->m_DarkKnight = lpMsg->DarkKnight;

	this->m_Elf = lpMsg->Elf;

	this->m_MagicGladiator = lpMsg->MagicGladiator;

	this->m_DarkLord = lpMsg->DarkLord;

	this->m_Summoner = lpMsg->Summoner;

	this->m_RageFighter = lpMsg->RageFighter;

	gConsole.AddMessage(5, "req = %d, pass = %s", lpMsg->RequiredPassword, lpMsg->Password);

	if (lpMsg->RequiredPassword)
	{
		memcpy(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue, lpMsg->Password, sizeof(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue));
		gConsole.AddMessage(5, "Pass = %s", gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue);
	}
	else
	{
		strcpy_s(gInterface.Data[OBJECT_PARTYSETTINGS_PASSWORD].StatValue, "NONE");
	}
}
