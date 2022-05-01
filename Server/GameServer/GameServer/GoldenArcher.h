// GoldenArcher.h: interface for the CGoldenArcher class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "Protocol.h"
#include "User.h"

//**********************************************//
//************ Client -> GameServer ************//
//**********************************************//

struct PMSG_GOLDEN_ARCHER_REGISTER_RECV
{
	PBMSG_HEAD header; // C1:95
	BYTE Type;
	BYTE Pos;
};

struct PMSG_GOLDEN_ARCHER_SERIAL_RECV
{
	PBMSG_HEAD header; // C1:9D
	char Serial1[5];
	char Serial2[5];
	char Serial3[5];
};

//**********************************************//
//************ GameServer -> Client ************//
//**********************************************//

struct PMSG_GOLDEN_ARCHER_TALK_SEND
{
	PBMSG_HEAD header; // C1:94
	BYTE Type;
	WORD RenaCount;
	short Other[3];
};

//**********************************************//
//********** DataServer -> GameServer **********//
//**********************************************//

//**********************************************//
//********** GameServer -> DataServer **********//
//**********************************************//

//**********************************************//
//**********************************************//
//**********************************************//

class CGoldenArcher
{
public:
	CGoldenArcher();
	virtual ~CGoldenArcher();
	void NpcTalk(LPOBJ lpNpc,LPOBJ lpObj);
	void CGRegisterRecv(PMSG_GOLDEN_ARCHER_REGISTER_RECV* lpMsg,int aIndex);
	void CGSerialRecv(PMSG_GOLDEN_ARCHER_SERIAL_RECV* lpMsg,int aIndex);
};

extern CGoldenArcher gGoldenArcher;
