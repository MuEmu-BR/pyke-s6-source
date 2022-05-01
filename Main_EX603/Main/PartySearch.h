#pragma once

#include "Protocol.h"
#include "defines.h"

#define MAX_PARTYLIST 100

struct PARTYLIST
{
	int Index;
	char Name[11];
	int Map;
	int X;
	int Y;
	int Level;
	bool DarkWizard;
	bool DarkKnight;
	bool Elf;
	bool MagicGladiator;
	bool DarkLord;
	bool Summoner;
	bool RageFighter;
	bool OnlyGuild;
	bool OnlyAlliance;
	bool IsSameGuild;
	bool IsSameAlliance;
	bool RequirePassword;
	int Count;
	bool ButtonActive;
};

struct PMSG_PARTY_REQ_SEND
{
	PSBMSG_HEAD header;
	char Name[11];
	bool needPassword;
	char Password[20];
};

class cPartySearch
{
public:
	cPartySearch();
	~cPartySearch();
	void draw_party_search();
	static void party_search_switch_state();
	void event_party_search_window(DWORD Event);
	void draw_party_password();
	static void party_search_password_switch_state();
	void event_party_search_password_window(DWORD Event);
	void ClearPartyList();
	void InsertPartyList(PMSG_PARTYSEARCH_PARTYLIST* lpInfo);
	PARTYLIST* GetPartyList(int index);
	void SendPartyRequest(int index);
	void SendPartyRequest(int index, char* password);
	//void SendPasswordCheck();
	// ----
	PARTYLIST gPartyList[MAX_PARTYLIST];
	int ListsCount;
	int Page;
	int CountPages;
	// ----
	int currentIndex;
	// ----
	int CanOpenSettings[MAX_ACCOUNT_LEVEL];
	int CanOpenMain[MAX_ACCOUNT_LEVEL];
	// ----
}; extern cPartySearch gPartySearch;