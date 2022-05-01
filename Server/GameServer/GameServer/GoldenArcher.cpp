// GoldenArcher.cpp: implementation of the CGoldenArcher class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GoldenArcher.h"
#include "Map.h"
#include "Util.h"

CGoldenArcher gGoldenArcher;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGoldenArcher::CGoldenArcher() // OK
{

}

CGoldenArcher::~CGoldenArcher() // OK
{

}

void CGoldenArcher::NpcTalk(LPOBJ lpNpc, LPOBJ lpObj) // OK
{
	if(lpObj->Interface.use != 0)
	{
		return;
	}

	lpObj->Interface.use = 1;
	lpObj->Interface.type = INTERFACE_GOLDEN_ARCHER;
	lpObj->Interface.state = 0;

	if(lpObj->Map == MAP_LORENCIA)
	{
		if(lpObj->Interface.use != 0)
		{
			return;
		}

		PMSG_GOLDEN_ARCHER_TALK_SEND pMsg;

		pMsg.header.setE(0x94,sizeof(pMsg));

		pMsg.RenaCount = 0;
		pMsg.Type = 0;

		pMsg.Other[0] = 0;
		pMsg.Other[1] = 0;
		pMsg.Other[2] = 0;

		DataSend(lpObj->Index,(BYTE*)&pMsg,pMsg.header.size);
	}
	else if(lpObj->Map == MAP_DEVIAS)
	{
		PMSG_GOLDEN_ARCHER_TALK_SEND pMsg;

		pMsg.header.setE(0x94,sizeof(pMsg));

		pMsg.RenaCount = 0;

		pMsg.Type = 2;

		pMsg.Other[0] = 0;
		pMsg.Other[1] = 0;
		pMsg.Other[2] = 0;

		DataSend(lpObj->Index,(BYTE*)&pMsg,pMsg.header.size);
	}
}

void CGoldenArcher::CGRegisterRecv(PMSG_GOLDEN_ARCHER_REGISTER_RECV* lpMsg,int aIndex) // OK
{
	LPOBJ lpObj = &gObj[aIndex];

	if(gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	LogAdd(LOG_RED,"%x %x",lpMsg->Type,lpMsg->Pos);
}

void CGoldenArcher::CGSerialRecv(PMSG_GOLDEN_ARCHER_SERIAL_RECV* lpMsg,int aIndex) // OK
{
	LPOBJ lpObj = &gObj[aIndex];

	if(gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}

	LogAdd(LOG_RED,"%s %s %s",lpMsg->Serial1,lpMsg->Serial2,lpMsg->Serial3);
}