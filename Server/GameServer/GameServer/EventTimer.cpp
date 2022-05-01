#include "stdafx.h"
#include "EventTimer.h"
#include "MemScript.h"
#include "Util.h"

CEventTimer gEventTimer;

CEventTimer::CEventTimer()
{
	
}

CEventTimer::~CEventTimer()
{
	
}

void CEventTimer::Load(char* path)
{

	CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR,path);
		return;
	}

	if(lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->m_EventTimerInfo.clear();

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if(strcmp("end",lpMemScript->GetString()) == 0)
			{
				break;
			}

			EVENTTIMER_INFO info;

			info.Group = lpMemScript->GetNumber();

			info.DayOfWeek = lpMemScript->GetAsNumber();

			info.Hour = lpMemScript->GetAsNumber();

			info.Minute = lpMemScript->GetAsNumber();

			info.TextIndex = lpMemScript->GetAsNumber();

			this->m_EventTimerInfo.push_back(info);
		}
	}
	catch(...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void CEventTimer::CG_RequestEvents(CG_EVENTTIMER_REQ* aRecv, int aIndex)
{
	BYTE send[8192];

	PMSG_SEND_EVENTTIMER pMsg;
	pMsg.header.set(0xFB, 0x0B, sizeof(pMsg));

	int size = sizeof(pMsg);

	pMsg.Count = 0;

	for (int i=0;i<this->m_EventTimerInfo.size();i++)
	{
		memcpy(&send[size],&this->m_EventTimerInfo[i],sizeof(this->m_EventTimerInfo[i]));
		size += sizeof(this->m_EventTimerInfo[i]);

		pMsg.Count ++;
	}

	pMsg.header.size[0] = SET_NUMBERHB(size);

	pMsg.header.size[1] = SET_NUMBERLB(size);

	memcpy(send,&pMsg,sizeof(pMsg));
	DataSend(aIndex,send,size);
}
