#pragma once

#include "Protocol.h"

struct PMSG_RECV_PARTYSEARCH_ADD
{
	PSBMSG_HEAD header;
	bool SystemActive;
	bool OnlyGuild;
	bool OnlyAlliance;
	bool OneClass;
	bool DarkWizard;
	bool DarkKnight;
	bool Elf;
	bool MagicGladiator;
	bool DarkLord;
	bool Summoner;
	bool RageFighter;
	int Level;
	bool RequirePassword;
	char Password[20];
};

struct PMSG_SEND_PARTYLIST
{
	PSWMSG_HEAD header;
	int Count;
};

struct PMSG_PARTYLIST
{
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
};

struct PMSG_PARTYSETTINGS_SEND
{
	PSBMSG_HEAD header;
	bool SystemActive;
	bool OnlyGuild;
	bool OnlyAlliance;
	bool OneClass;
	bool DarkWizard;
	bool DarkKnight;
	bool Elf;
	bool MagicGladiator;
	bool DarkLord;
	bool Summoner;
	bool RageFighter;
	int Level;
	bool RequiredPassword;
	char Password[20];
};

struct PMSG_PARTY_REQ_REQ
{
	PSBMSG_HEAD header;
	char Name[11];
	bool needPassword;
	char Password[20];
};

struct REGISTERED_INFO
{
	char Name[11];
	int aIndex;
	bool OnlyGuild;
	bool OnlyAlliance;
	bool OneClass;
	bool DarkWizard;
	bool DarkKnight;
	bool Elf;
	bool MagicGladiator;
	bool DarkLord;
	bool Summoner;
	bool RageFighter;
	int Level;
	BYTE IsOnline;
	bool RequirePassword;
	char Password[20];
};

class CPartySearch
{
public:
	CPartySearch();
	~CPartySearch();
	void Load(char* section, char* path);
	void PartySearchAddToList(PMSG_RECV_PARTYSEARCH_ADD* lpMsg, int aIndex);
	void PartySearchDelFromList(char* Name);
	void GCPartyListSend(int aIndex);
	bool Dialog(LPOBJ lpObj, LPOBJ lpNpc);
	void RequestParty(PMSG_PARTY_REQ_REQ* lpMsg, int aIndex);
	void SendPartySettings(LPOBJ lpObj);
	// ----
	int NpcID;
	int NpcMap;
	int NpcX;
	int NpcY;
	int DelAfterRelog;
	int CanOpenSettings[MAX_ACCOUNT_LEVEL];
	int CanOpenMain[MAX_ACCOUNT_LEVEL];
	// ----
	std::map<std::string,REGISTERED_INFO> m_Registered;
}; extern CPartySearch gPartySearch;