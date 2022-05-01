#include "stdafx.h"
#include "HappyHoursMaster.h"
#include "ScheduleManager.h"
#include "ServerInfo.h"
#include "Util.h"
#include "MemScript.h"
#include "Notice.h"
#include "Message.h"

#if(HAPPY_HOUR == 1)

MasterHours ObjMasterH;


void MasterHours::CheckSync() // OK
{
	if(this->m_MasterHappyStartTime.empty() != 0)
	{
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;
	
	for(std::vector<MASTER_HOURS_START_TIME>::iterator it=this->m_MasterHappyStartTime.begin();it != this->m_MasterHappyStartTime.end();it++)
	{
		ScheduleManager.AddSchedule(it->Year,it->Month,it->Day,it->Hour,it->Minute,it->Second,it->DayOfWeek);
	}

	if(ScheduleManager.GetSchedule(&ScheduleTime) == 0)
	{
		return;
	}

	this->m_RemainTime = (int)difftime(ScheduleTime.GetTime(),time(0));

	this->m_TargetTime = (int)ScheduleTime.GetTime();

	if(this->m_RemainTime <= 0)
	{
		this->SetProcState(STATE_MASTER_START);
	}

}

void MasterHours::MainProc()
{
	switch(this->m_iState)
	{

	case STATE_MASTER_SYNC:
		this->CheckSync();
		break;

	case STATE_MASTER_START:
		StartMasterHours();
		break;
	}

}

void MasterHours::StartMasterHours()
{
	if((this->Start == 0) && (this->MasterEndable == 1)) 
	{
		_beginthread( cMasterHour__InsideTrigger, 0, NULL  );
		LogAdd(LOG_EVENT,"[MasterHour] Evento Iniciado!");
	}
}

void cMasterHour__InsideTrigger(void * lpParam)
{
	ObjMasterH.Start = 1;

	int *TotalMasterExp  = gServerInfo.m_AddMasterExperienceRate;
	int *TotalMasterItemDrop		= gServerInfo.m_ItemDropRate;

	*TotalMasterExp	+= ObjMasterH.ExtraMasterExp;
	*TotalMasterItemDrop		+= ObjMasterH.ExtraMasterDrop;

	//Start Master Event 
//	gNotice.GCNoticeSendToAll(0,0,0,0,0,0,gMessage.GetMessage(514),*TotalMasterExp);
//	gNotice.GCNoticeSendToAll(0,0,0,0,0,0,"[MasterHours] TotalMasterExp",*TotalMasterExp);
	gNotice.GCNoticeSendToAll(0,0,0,0,0,0,"[MasterHours] TotalMasterExp",*TotalMasterExp,*TotalMasterItemDrop);

	//StartEvent In Minutes
//	gNotice.GCNoticeSendToAll(0,0,0,0,0,0,gMessage.GetMessage(515),(ObjMasterH.MasterMinutes));
	gNotice.GCNoticeSendToAll(0,0,0,0,0,0,"[MasterHours] duration %d Minute(s)",(ObjMasterH.MasterMinutes));

	//Logs GameServer
//	LogAdd(LOG_EVENT,"[MasterHours] Extra Exp:%d,Total Exp:%d",ObjMasterH.ExtraMasterExp,*TotalMasterExp);
	LogAdd(LOG_EVENT,"[MasterHours] Extra Drop:%d,Extra Exp:%d",ObjMasterH.ExtraMasterDrop,ObjMasterH.ExtraMasterExp);
	LogAdd(LOG_EVENT,"[MasterHours] Total Drop:%d,Total Exp:%d",*TotalMasterItemDrop,*TotalMasterExp); // nuevo
	
	//Master Minutes 
	Sleep(ObjMasterH.MasterMinutes * 60000);

	//End Event
//	gNotice.GCNoticeSendToAll(0,0,0,0,0,0,gMessage.GetMessage(516));
	gNotice.GCNoticeSendToAll(0,0,0,0,0,0,"[MasterHours] End");

	*TotalMasterExp -= ObjMasterH.ExtraMasterExp;
	*TotalMasterItemDrop	-= ObjMasterH.ExtraMasterDrop;	// nuevo

	LogAdd(LOG_EVENT,"[MasterHours] End!");

	ObjMasterH.Start = 0;

	ObjMasterH.SetProcState(STATE_MASTER_SYNC);

		_endthread();
}

#endif