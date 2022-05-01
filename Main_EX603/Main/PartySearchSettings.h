#pragma once

#include "Protocol.h"

struct PMSG_SEND_PARTYSEARCH_ADD
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

struct PMSG_PARTYSETTINGS_RECV
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

class cPartySearchSettings
{
public:
	cPartySearchSettings();
	virtual ~cPartySearchSettings();
	void draw_party_settings_window();
	static void party_search_settings_switch_state();
	void event_party_search_settings_window(DWORD Event);
	void change_class_value(int Class);
	void set_class_value(int Class, int Value);
	void CGSendPartySearchAdd();
	void GCPartySettingsRecv(PMSG_PARTYSETTINGS_RECV* lpMsg);
	// ----
	bool m_SystemActive;
	bool m_OnlyGuild;
	bool m_OnlyAlliance;
	bool m_OneClass;
	bool m_DarkWizard;
	bool m_DarkKnight;
	bool m_Elf;
	bool m_MagicGladiator;
	bool m_DarkLord;
	bool m_Summoner;
	bool m_RageFighter;
	int m_Level;
}; extern cPartySearchSettings gPartySearchSettings;