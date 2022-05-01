#include "stdafx.h"
#if(HAPPY_HOUR)
#include "HappyHour.h"
#include "ScheduleManager.h"
#include "ServerInfo.h"
#include "Util.h"
#include "MemScript.h"
#include "Notice.h"
#include "Message.h"
#include "HappyHoursMaster.h"

HappyHours ObjHappy;

void HappyHours::Load(char* path)
{

	pugi::xml_document file;
	pugi::xml_parse_result res = file.load_file(path);
	if(res.status != pugi::status_ok){
		ErrorMessageBox("File %s load fail. Error: %s", path, res.description());
		return;
	}
	this->m_HappyHoursTime.clear();
	ObjMasterH.m_MasterHappyStartTime.clear();
    pugi::xml_node HappyHour = file.child("HappyHours");
	pugi::xml_node Normal = HappyHour.child("Normal");
    pugi::xml_node ExpDates = Normal.child("System");
	ObjHappy.NormalEnable  = ExpDates.attribute("Enable").as_int();
	ObjHappy.NormalMinutes = ExpDates.attribute("Minutes").as_int();
	ObjHappy.ExtraExp      = ExpDates.attribute("ExtraExp").as_int();
	ObjHappy.ExtraDrop     = ExpDates.attribute("ExtraDrop").as_int();
	pugi::xml_node Hours = Normal.child("Time");
	for (pugi::xml_node AddDates = Hours.child("Date"); AddDates; AddDates = AddDates.next_sibling()){
		HAPPY_HOURS_START_TIME info;
	    info.Year = AddDates.attribute("Year").as_int();
	    info.Month = AddDates.attribute("Month").as_int();
	    info.Day = AddDates.attribute("Day").as_int();
	    info.DayOfWeek = AddDates.attribute("DayOfWeek").as_int();
        info.Hour = AddDates.attribute("Hour").as_int();
	    info.Minute = AddDates.attribute("Minute").as_int();
        info.Second = AddDates.attribute("Second").as_int();
        this->m_HappyHoursTime.push_back(info);
	}
	pugi::xml_node Master = HappyHour.child("Master");
    pugi::xml_node ExpDat = Master.child("System");
	ObjMasterH.MasterEndable  = ExpDat.attribute("Enable").as_int();
	ObjMasterH.ExtraMasterExp = ExpDat.attribute("ExtraExpMaster").as_int();
	ObjMasterH.MasterMinutes      = ExpDat.attribute("Minutes").as_int();
	pugi::xml_node Hour = Master.child("Time");
	for (pugi::xml_node AddDat = Hour.child("Date"); AddDat; AddDat = AddDat.next_sibling()){
		MASTER_HOURS_START_TIME info;
	    info.Year = AddDat.attribute("Year").as_int();
		info.Month = AddDat.attribute("Month").as_int();
		info.Day = AddDat.attribute("Day").as_int();
		info.DayOfWeek = AddDat.attribute("DayOfWeek").as_int();
	    info.Hour = AddDat.attribute("Hour").as_int();
    	info.Minute = AddDat.attribute("Minute").as_int();
		info.Second = AddDat.attribute("Second").as_int();
		ObjMasterH.m_MasterHappyStartTime.push_back(info);
	}
}

void HappyHours::CheckSync() // OK
{
	if(this->m_HappyHoursTime.empty() != 0)
	{
		return;
	}

	CTime ScheduleTime;

	CScheduleManager ScheduleManager;
	
	for(std::vector<HAPPY_HOURS_START_TIME>::iterator it=this->m_HappyHoursTime.begin();it != this->m_HappyHoursTime.end();it++)
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
		this->SetProcState(STATE_NORMAL_START);
	}

}

void HappyHours::MainProc()
{
	switch(this->m_iState)
	{

	case STATE_NORMAL_SYNC:
		this->CheckSync();
		break;

	case STATE_NORMAL_START:
		StartNormalHappyHours();
		break;
	}

}

void HappyHours::StartNormalHappyHours()
{
	if((this->Start == 0) && (this->NormalEnable == 1))
	{
		_beginthread( cHappyHour__InsideTrigger, 0, NULL  );
		LogAdd(LOG_EVENT,"[HappyHours] Evento Iniciado!");
	}
}

void cHappyHour__InsideTrigger(void * lpParam)

{
	ObjHappy.Start = 1;
	
	int *TotalNormalExp = gServerInfo.m_AddExperienceRate;
	int *ItemDrop		= gServerInfo.m_ItemDropRate;

	*ItemDrop		+= ObjHappy.ExtraDrop;
	*TotalNormalExp += ObjHappy.ExtraExp;
	
	//Start Normal Event 
//	gNotice.GCNoticeSendToAll(0,0,0,0,0,0,gMessage.GetMessage(511),*TotalNormalExp,*ItemDrop);
	gNotice.GCNoticeSendToAll(0,0,0,0,0,0,"[HappyHours] TotalNormalExp: [%d],TotalItemDrop: [%d]",*TotalNormalExp,*ItemDrop);

	//StartEvent In Minutes
//	gNotice.GCNoticeSendToAll(0,0,0,0,0,0,gMessage.GetMessage(512),(ObjHappy.NormalMinutes));
	gNotice.GCNoticeSendToAll(0,0,0,0,0,0,"[HappyHours] duration %d Minute(s)",(ObjHappy.NormalMinutes));

	//Logs GameServer
	LogAdd(LOG_EVENT,"[HappyHours] Extra Drop:%d,Extra Exp:%d",ObjHappy.ExtraDrop,ObjHappy.ExtraExp);
	LogAdd(LOG_EVENT,"[HappyHours] Total Drop:%d,Total Exp:%d",*ItemDrop,*TotalNormalExp);
	
	//Minutes 
	Sleep(ObjHappy.NormalMinutes * 60000);

	//End Event
//	gNotice.GCNoticeSendToAll(0,0,0,0,0,0,gMessage.GetMessage(513));
	gNotice.GCNoticeSendToAll(0,0,0,0,0,0,"[HappyHours] End");

	*ItemDrop		-= ObjHappy.ExtraDrop;
	*TotalNormalExp -= ObjHappy.ExtraExp;

	LogAdd(LOG_EVENT,"[HappyHours] End!");

	ObjHappy.Start = 0;

	ObjHappy.SetProcState(STATE_NORMAL_SYNC);

		_endthread();
}

#endif
