#include "stdafx.h"
#include "PartySearch.h"
#include "User.h"
#include "Interface.h"

#include "PartySearchSettings.h"
#include "Console.h"
#include "Offset.h"

cPartySearch gPartySearch;

cPartySearch::cPartySearch()
{
	this->ClearPartyList();
}

cPartySearch::~cPartySearch()
{

}

void cPartySearch::draw_party_search()
{
	if (!gInterface.Data[OBJECT_PARTYSEARCH_MAIN].OnShow)
	{
		return;
	}
	// ----
	float MainWidth = 230.0;
	float StartY = 50.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);

	pSetCursorFocus = true;
	// ----
	gInterface.DrawGUI(OBJECT_PARTYSEARCH_MAIN, StartX, StartY + 2);
	gInterface.DrawGUI(OBJECT_PARTYSEARCH_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(OBJECT_PARTYSEARCH_FRAME, StartX, StartY + 67.0, 16);
	gInterface.DrawGUI(OBJECT_PARTYSEARCH_FOOTER, StartX, StartY);
	gInterface.DrawGUI(OBJECT_PARTYSEARCH_CLOSE, StartX + MainWidth - gInterface.Data[OBJECT_PARTYSEARCH_CLOSE].Width + 2, 49);
	// ----
	if (gInterface.IsWorkZone(OBJECT_PARTYSEARCH_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[OBJECT_PARTYSEARCH_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(OBJECT_PARTYSEARCH_CLOSE, gInterface.Data[OBJECT_PARTYSEARCH_CLOSE].X, gInterface.Data[OBJECT_PARTYSEARCH_CLOSE].Y, Color);
		gInterface.DrawToolTip(gInterface.Data[OBJECT_PARTYSEARCH_CLOSE].X + 5, gInterface.Data[OBJECT_PARTYSEARCH_CLOSE].Y + 25, "Close");
	}
	// ----
	gInterface.DrawText(eGold, StartX + 10, 60, 210, 3, "Party Search");
	// ----
	gInterface.DrawText(eWhite, StartX + 20, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 34, 20, 1, "Status:");

	if (gPartySearchSettings.m_SystemActive == false)
	{
		gInterface.DrawText(eRed, StartX + 42, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 34, 20, 1, "OFF");
	}
	else
	{
		gInterface.DrawText(eShinyGreen, StartX + 42, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 34, 20, 1, "ON");
	}

	// ----
	gInterface.DrawGUI(OBJECT_PARTYSETTINGS_DIV, StartX, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 40); // Делитель большой
	// ----
	gInterface.DrawText(eWhite, StartX + 5, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 56, 50, 3, "Player");
	// ----
	gInterface.DrawText(eWhite, StartX + 45, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 56, 50, 3, "Map");
	// ----
	gInterface.DrawText(eWhite, StartX + 95, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 56, 50, 3, "X");
	// ----
	gInterface.DrawText(eWhite, StartX + 115, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 56, 50, 3, "Y");
	// ----
	gInterface.DrawText(eWhite, StartX + 140, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 56, 50, 3, "Count");
	// ----
	gInterface.DrawText(eWhite, StartX + 170, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 56, 50, 3, "Join");
	// ----
	gInterface.DrawGUI(OBJECT_PARTYSETTINGS_DIV, StartX, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 60); // Делитель большой
	// ----
	if (gPartySearch.CountPages > 1)
	{
		gInterface.DrawText(eGold, StartX + 104, 379, 20, 3, "%d/%d", gPartySearch.Page + 1, gPartySearch.CountPages);
	}

	if (gPartySearch.Page + 1 > 1)
	{
		gInterface.DrawButton(OBJECT_PARTYSEARCH_LEFT, StartX + 73, 372, 0, 0);
	}

	if (gPartySearch.Page + 1 < gPartySearch.CountPages)
	{
		gInterface.DrawButton(OBJECT_PARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 0);
	}

	int DrawnItems = 0;

	for (int i = 0; i < gPartySearch.ListsCount; i++)
	{
		if (DrawnItems >= 10)
		{
			break;
		}

		PARTYLIST* info = gPartySearch.GetPartyList(i + (10 * gPartySearch.Page));

		if (info == 0)
		{
			continue;
		}

		pDrawGUI(0x7898, StartX + 10, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 80 + (20 * i), 170, 21);

		gInterface.DrawText(eYellow, StartX + 15, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 1, info->Name);

		gInterface.DrawText(eWhite, StartX + 45, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, gObjUser.GetMapName(info->Map));

		gInterface.DrawText(eWhite, StartX + 95, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d", info->X);

		gInterface.DrawText(eWhite, StartX + 115, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d", info->Y);

		gInterface.DrawText(eWhite, StartX + 140, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d / 5", info->Count);

		pDrawGUI(0x7899, StartX + 178, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 80 + (i * 20), 22, 19);

		if (info->ButtonActive == true)
		{
			pDrawButton(0x7AA4, StartX + 203, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 82 + (i * 20), 16, 15, 0, 0);
		}

		int X = StartX + 203;
		int Y = gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 82 + (i * 20);
		int MaxX = X + 16;
		int MaxY = Y + 15;

		if (info->ButtonActive == true)
		{
			if (gInterface.IsWorkZone2(X, Y, MaxX, MaxY))
			{
				pDrawColorButton(0x7AA4, X, Y, 16, 15, 0, 16, eGray100);
			}
		}

		DrawnItems++;
	}

	DrawnItems = 0;

	for (int i = 0; i < gPartySearch.ListsCount; i++)
	{
		if (DrawnItems >= 10)
		{
			break;
		}

		PARTYLIST* info = gPartySearch.GetPartyList(i + (10 * gPartySearch.Page));

		if (info == 0)
		{
			continue;
		}

		int X = StartX + 178;
		int Y = gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 80 + (i * 20);
		int MaxX = X + 22;
		int MaxY = Y + 19;

		if (gInterface.IsWorkZone2(X, Y, MaxX, MaxY))
		{
			char szText[2048];
			sprintf(szText, "Need to Party:\n_____________________\nLevel:%d", info->Level);

			if (info->RequirePassword)
			{
				strcat(szText, "\nPASSWORD IS REQUIRED");
			}

			if (info->DarkWizard)
			{
				strcat(szText, "\nDark Wizard");
			}
			if (info->DarkKnight)
			{
				strcat(szText, "\nDark Knight");
			}
			if (info->Elf == true)
			{
				strcat(szText, "\nElf");
			}
			if (info->MagicGladiator)
			{
				strcat(szText, "\nMagic Gladiator");
			}
			if (info->DarkLord)
			{
				strcat(szText, "\nDark Lord");
			}
			if (info->Summoner)
			{
				strcat(szText, "\nSummoner");
			}
			if (info->RageFighter)
			{
				strcat(szText, "\nRage Fighter");
			}
			if (info->OnlyGuild)
			{
				strcat(szText, "\nOnly Guild");
			}
			if (info->OnlyAlliance)
			{
				strcat(szText, "\nOnly Alliance");
			}

			strcat(szText, "\n_____________________");

			gInterface.DrawToolTipEx(eWhite, StartX + 230, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 62 + (i * 20), 100, 30, 3, szText);
		}

		DrawnItems++;
	}

	if (gPartySearch.Page + 1 > 1)
	{
		if (gInterface.IsWorkZone(OBJECT_PARTYSEARCH_LEFT))
		{
			if (gInterface.Data[OBJECT_PARTYSEARCH_LEFT].OnClick)
			{
				gInterface.DrawButton(OBJECT_PARTYSEARCH_LEFT, StartX + 73, 372, 0, 46);
				return;
			}
			gInterface.DrawButton(OBJECT_PARTYSEARCH_LEFT, StartX + 73, 372, 0, 23);
		}
	}
	if (gPartySearch.Page + 1 < gPartySearch.CountPages)
	{
		if (gInterface.IsWorkZone(OBJECT_PARTYSEARCH_RIGHT))
		{
			if (gInterface.Data[OBJECT_PARTYSEARCH_RIGHT].OnClick)
			{
				gInterface.DrawButton(OBJECT_PARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 46);
				return;
			}
			gInterface.DrawButton(OBJECT_PARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 23);
		}
	}
}

void cPartySearch::party_search_switch_state()
{
	gInterface.Data[OBJECT_PARTYSEARCH_MAIN].OnShow == true ? gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Close() : gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Open();
}

void cPartySearch::event_party_search_window(DWORD Event)
{
	if (!gInterface.Data[OBJECT_PARTYSEARCH_MAIN].OnShow)
	{
		return;
	}
	
	const float StartX = (MAX_WIN_WIDTH / 2) - (230.0 / 2);
	DWORD CurrentTick = GetTickCount();

	if (gInterface.IsWorkZone(OBJECT_PARTYSEARCH_CLOSE))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYSEARCH_CLOSE].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_PARTYSEARCH_CLOSE].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSEARCH_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSEARCH_CLOSE].EventTick = GetTickCount();
		this->party_search_switch_state();
	}
	if (gInterface.IsWorkZone(OBJECT_PARTYSEARCH_LEFT) && gPartySearch.Page + 1 > 1)
	{
		DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYSEARCH_LEFT].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_PARTYSEARCH_LEFT].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSEARCH_LEFT].OnClick = false;
		// ----
		if (Delay < 100)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSEARCH_LEFT].EventTick = GetTickCount();
		// ----
		gPartySearch.Page--;
	}
	if (gInterface.IsWorkZone(OBJECT_PARTYSEARCH_RIGHT) && gPartySearch.Page + 1 < gPartySearch.CountPages)
	{
		DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYSEARCH_RIGHT].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_PARTYSEARCH_RIGHT].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSEARCH_RIGHT].OnClick = false;
		// ----
		if (Delay < 100)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYSEARCH_RIGHT].EventTick = GetTickCount();
		// ----
		gPartySearch.Page++;
	}

	for (int i = 0; i < gPartySearch.ListsCount; i++)
	{
		if (gInterface.IsWorkZone2(StartX + 203, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 82 + (i * 20), StartX + 203 + 16, gInterface.Data[OBJECT_PARTYSEARCH_MAIN].Y + 82 + (i * 20) + 15))
		{
			DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYSEARCH_RIGHT].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[OBJECT_PARTYSEARCH_RIGHT].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[OBJECT_PARTYSEARCH_RIGHT].OnClick = false;
			// ----
			if (Delay < 100)
			{
				return;
			}
			// ----
			if (gPartySearch.gPartyList[i + (10 * gPartySearch.Page)].ButtonActive == false)
			{
				return;
			}
			// ----
			gInterface.Data[OBJECT_PARTYSEARCH_RIGHT].EventTick = GetTickCount();
			// ----
			if (gPartySearch.gPartyList[i + (10 * gPartySearch.Page)].RequirePassword)
			{
				this->party_search_switch_state();
				gPartySearch.currentIndex = i + (10 * gPartySearch.Page);
				//gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Open();
				this->party_search_password_switch_state();
			}
			else
			{
				gPartySearch.SendPartyRequest(i + (10 * gPartySearch.Page));
			}
		}
	}
}

void cPartySearch::draw_party_password()
{
	if (!gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].OnShow)
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
	gInterface.DrawGUI(OBJECT_PARTYPASSWORD_MAIN, StartX, StartY + 2);
	gInterface.DrawGUI(OBJECT_PARTYPASSWORD_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(OBJECT_PARTYPASSWORD_FRAME, StartX, StartY + 67.0, 1);
	gInterface.DrawGUI(OBJECT_PARTYPASSWORD_FOOTER, StartX, StartY);
	gInterface.DrawGUI(OBJECT_PARTYPASSWORD_CLOSE, StartX + MainWidth - gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].Width + 2, 99);
	// ----
	if (gInterface.IsWorkZone(OBJECT_PARTYPASSWORD_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(OBJECT_PARTYPASSWORD_CLOSE, gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].X, gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].Y, Color);
		gInterface.DrawToolTip(gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].X + 5, gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].Y + 25, "Close");
	}
	// ----
	gInterface.DrawText(eGold, StartX + 10, 110, 210, 3, "Enter a password:");

	if (gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].FirstLoad == true)
	{
		gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].Attribute = 1;
		sprintf(gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue, "");
	}

	gInterface.DrawGUI(OBJECT_PARTYPASSWORD_TEXTBOX, StartX + 28, gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Y + 46);
	if (gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].Attribute == 1)
	{
		gInterface.DrawColoredGUI(OBJECT_PARTYPASSWORD_TEXTBOX, StartX + 28, gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Y + 46, eGray100);
	}

	gInterface.DrawText(eWhite, StartX + 40, gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Y + 52, 200, 1, "Password");

	gInterface.DrawText(eWhite, StartX + 50, gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Y + 52, 200, 3, gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue);


	gInterface.DrawButton(OBJECT_PARTYPASSWORD_OK, StartX + gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Width / 2 - gInterface.Data[OBJECT_PARTYPASSWORD_OK].Width / 2, gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Y + 86, 0, 0);

	if (gInterface.IsWorkZone(OBJECT_PARTYPASSWORD_OK))
	{
		int ScaleY = 30;
		// ----
		if (gInterface.Data[OBJECT_PARTYPASSWORD_OK].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		gInterface.DrawButton(OBJECT_PARTYPASSWORD_OK, StartX + gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Width / 2 - gInterface.Data[OBJECT_PARTYPASSWORD_OK].Width / 2, gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Y + 86, 0, ScaleY);
	}


	if (gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].FirstLoad == true)
	{
		gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].FirstLoad = false;
	}
}

void cPartySearch::party_search_password_switch_state()
{
	gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].OnShow == true ? gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Close() : gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].Open();
}

void cPartySearch::event_party_search_password_window(DWORD Event)
{
	if (!gInterface.Data[OBJECT_PARTYPASSWORD_MAIN].OnShow)
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();

	if (gInterface.IsWorkZone(OBJECT_PARTYPASSWORD_TEXTBOX))
	{
		gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].Attribute = 1;
	}
	else
	{
		gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].Attribute = 0;
	}

	if (gInterface.IsWorkZone(OBJECT_PARTYPASSWORD_OK))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYPASSWORD_OK].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_PARTYPASSWORD_OK].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYPASSWORD_OK].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYPASSWORD_OK].EventTick = GetTickCount();
		gPartySearch.SendPartyRequest(gPartySearch.currentIndex, gInterface.Data[OBJECT_PARTYPASSWORD_TEXTBOX].StatValue);
		this->party_search_password_switch_state();
	}

	if (gInterface.IsWorkZone(OBJECT_PARTYPASSWORD_CLOSE))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		gInterface.Data[OBJECT_PARTYPASSWORD_CLOSE].EventTick = GetTickCount();
		this->party_search_password_switch_state();
	}
}


void cPartySearch::ClearPartyList()
{
	for (int i = 0; i<MAX_PARTYLIST; i++)
	{
		this->gPartyList[i].Index = 0xFFFF;
		memset(&this->gPartyList[i].Name, 0, sizeof(this->gPartyList[i].Name));
		this->gPartyList[i].Map = -1;
		this->gPartyList[i].X = -1;
		this->gPartyList[i].Y = -1;
		this->gPartyList[i].Count = -1;
		this->gPartyList[i].ButtonActive = true;
	}

	this->Page = 0;
	this->CountPages = 0;
	this->ListsCount = 0;
	this->currentIndex = -1;
}


void cPartySearch::InsertPartyList(PMSG_PARTYSEARCH_PARTYLIST* lpInfo)
{
	memcpy(this->gPartyList[this->ListsCount].Name, lpInfo->Name, sizeof(this->gPartyList[this->ListsCount].Name));
	this->gPartyList[this->ListsCount].Map = lpInfo->Map;
	this->gPartyList[this->ListsCount].X = lpInfo->X;
	this->gPartyList[this->ListsCount].Y = lpInfo->Y;
	this->gPartyList[this->ListsCount].Level = lpInfo->Level;
	this->gPartyList[this->ListsCount].DarkWizard = lpInfo->DarkWizard;
	this->gPartyList[this->ListsCount].DarkKnight = lpInfo->DarkKnight;
	this->gPartyList[this->ListsCount].Elf = lpInfo->Elf;
	this->gPartyList[this->ListsCount].MagicGladiator = lpInfo->MagicGladiator;
	this->gPartyList[this->ListsCount].DarkLord = lpInfo->DarkLord;
	this->gPartyList[this->ListsCount].Summoner = lpInfo->Summoner;
	this->gPartyList[this->ListsCount].RageFighter = lpInfo->RageFighter;
	this->gPartyList[this->ListsCount].OnlyGuild = lpInfo->OnlyGuild;
	this->gPartyList[this->ListsCount].IsSameGuild = lpInfo->IsSameGuild;
	this->gPartyList[this->ListsCount].OnlyAlliance = lpInfo->OnlyAliiance;
	this->gPartyList[this->ListsCount].IsSameAlliance = lpInfo->IsSameAlliance;
	this->gPartyList[this->ListsCount].RequirePassword = lpInfo->RequirePassword;
	this->gPartyList[this->ListsCount].Count = lpInfo->Count;
	this->gPartyList[this->ListsCount].Index = this->ListsCount;
	this->ListsCount++;
}

PARTYLIST* cPartySearch::GetPartyList(int index)
{
	if (this->gPartyList[index].Index == 0xFFFF)
	{
		return nullptr;
	}

	this->CountPages = ((this->ListsCount - 1) / 10) + 1;

	if (this->CountPages <= 0)
	{
		this->CountPages = 1;
	}

	for (int i = 0; i < this->ListsCount; i++)
	{
		if (strcmp(this->gPartyList[i].Name, gObjUser.lpPlayer->Name) == 0)
		{
			gPartySearchSettings.m_SystemActive = true;
			break;
		}
	}

	switch (gObjUser.lpPlayer->Class & 7)
	{
	case 0:
	{
		if (this->gPartyList[index].DarkWizard == false)
		{
			this->gPartyList[index].ButtonActive = false;
		}
	}
	break;
	case 1:
	{
		if (this->gPartyList[index].DarkKnight == false)
		{
			this->gPartyList[index].ButtonActive = false;
		}
	}
	break;
	case 2:
	{
		if (this->gPartyList[index].Elf == false)
		{
			this->gPartyList[index].ButtonActive = false;
		}
	}
	break;
	case 3:
	{
		if (this->gPartyList[index].MagicGladiator == false)
		{
			this->gPartyList[index].ButtonActive = false;
		}
	}
	break;
	case 4:
	{
		if (this->gPartyList[index].DarkLord == false)
		{
			this->gPartyList[index].ButtonActive = false;
		}
	}
	break;
	case 5:
	{
		if (this->gPartyList[index].Summoner == false)
		{
			this->gPartyList[index].ButtonActive = false;
		}
	}
	break;
	case 6:
	{
		if (this->gPartyList[index].RageFighter == false)
		{
			this->gPartyList[index].ButtonActive = false;
		}
	}
	break;
	default: this->gPartyList[index].ButtonActive = false;
	}

	if (gPartyList[index].OnlyGuild == true && gPartyList[index].IsSameGuild == false)
	{
		this->gPartyList[index].ButtonActive = false;
	}

	if (gPartyList[index].OnlyAlliance == true && gPartyList[index].IsSameAlliance == false)
	{
		this->gPartyList[index].ButtonActive = false;
	}

	if (gPartyList[index].Count >= 5)
	{
		gPartyList[index].ButtonActive = false;
	}
	
	if (pPartyMemberCount > 0)
	{
		gPartyList[index].ButtonActive = false;
	}

	if (gObjUser.lpPlayer->Level > gPartyList[index].Level)
	{
		gPartyList[index].ButtonActive = false;
	}

	if (gPartySearchSettings.m_SystemActive == true)
	{
		gPartyList[index].ButtonActive = false;
	}

	return &this->gPartyList[index];
}

void cPartySearch::SendPartyRequest(int index)
{
	PARTYLIST* info = gPartySearch.GetPartyList(index);

	if (info == nullptr)
	{
		return;
	}

	this->currentIndex = index;

	PMSG_PARTY_REQ_SEND pMsg;

	pMsg.header.set(0xFF, 0x05, sizeof(pMsg));

	memcpy(pMsg.Name, info->Name, sizeof(pMsg.Name));
	pMsg.needPassword = false;
	memset(pMsg.Password, 0, sizeof(pMsg.Password));

	DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void cPartySearch::SendPartyRequest(int index, char* password)
{
	PARTYLIST* info = gPartySearch.GetPartyList(index);

	if (info == nullptr)
	{
		return;
	}

	this->currentIndex = index;

	PMSG_PARTY_REQ_SEND pMsg;

	pMsg.header.set(0xFF, 0x13, sizeof(pMsg));

	memcpy(pMsg.Name, info->Name, sizeof(pMsg.Name));
	pMsg.needPassword = true;
	memcpy(pMsg.Password, password, sizeof(pMsg.Password));

	DataSend((BYTE*)&pMsg, pMsg.header.size);
}