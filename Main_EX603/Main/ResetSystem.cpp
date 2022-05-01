#include "stdafx.h"
#include "ResetSystem.h"
#include "User.h"
#include "Protocol.h"
#include "Interface.h"
#include "PrintPlayer.h"
#include "MemScript.h"
#include "Util.h"
// -------------------------------------------------------------------------------

ResetSystem		gResetSystem;
// -------------------------------------------------------------------------------

ResetSystem::ResetSystem()
{
	this->Init();
}
// -------------------------------------------------------------------------

ResetSystem::~ResetSystem()
{

}
// -------------------------------------------------------------------------

void ResetSystem::Init()
{
	/*ZeroMemory(this->m_GroupData, sizeof(this->m_GroupData));
	this->m_GroupLoadedCount	= 0;*/
}
// -------------------------------------------------------------------------

void ResetSystem::Load()
{
	//this->Init();
	//this->ReadGroupData("Data\\Custom\\ResetGroup.txt");
	//console.Log("","[ResetSystem]\tSuccessfully Loaded");
}
// -------------------------------------------------------------------------

void ResetSystem::ReadGroupData(char * path)
{
	//CMemScript* lpMemScript = new CMemScript;

	//if(lpMemScript == 0)
	//{
	//	ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR,path);
	//	return;
	//}

	//if(lpMemScript->SetBuffer(path) == 0)
	//{
	//	ErrorMessageBox(lpMemScript->GetLastError());
	//	delete lpMemScript;
	//	return;
	//}

	//try
	//{
	//	while(true)
	//	{
	//		if(lpMemScript->GetToken() == TOKEN_END)
	//		{
	//			break;
	//		}

	//		if(strcmp("end",lpMemScript->GetString()) == 0)
	//		{
	//			break;
	//		}

	//		int GroupID = lpMemScript->GetNumber();;
	//		// ----
	//		this->m_GroupData[GroupID].MinReset		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].MaxReset		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqLevel[0]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqLevel[1]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqLevel[2]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqLevel[3]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqMoney[0]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqMoney[1]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqMoney[2]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ReqMoney[3]		= lpMemScript->GetAsNumber();
	//		// ----
	//		this->m_GroupData[GroupID].ItemCount	= lpMemScript->GetAsNumber();
	//		// ----
	//		int RewardPerGroup	= 0;
	//		// ----
	//		while(true)
	//		{
	//			if( RewardPerGroup >= 7 )
	//			{
	//				break;
	//			}
	//			// ----
	//			this->m_GroupData[GroupID].RewardData[RewardPerGroup].LevelPoint = lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].RewardData[RewardPerGroup].GensPoint = lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].RewardData[RewardPerGroup].WCoinC = lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].RewardData[RewardPerGroup].WCoinP = lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].RewardData[RewardPerGroup].GoblinPoint = lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].RewardData[RewardPerGroup].Credits = lpMemScript->GetAsNumber();
	//			// ----
	//			RewardPerGroup++;
	//		}
	//		// ----
	//		int ItemPerGroup = 0;
	//		// ----
	//		while(true)
	//		{
	//			if( ItemPerGroup >= this->m_GroupData[GroupID].ItemCount )
	//			{
	//				break;
	//			}
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].ID			= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].MinLevel		= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].MaxLevel		= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].MinOption		= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].MaxOption		= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].IsLuck		= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].IsSkill		= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].IsExcellent	= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].IsAncient		= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].IsSocket		= lpMemScript->GetAsNumber();
	//			// ----
	//			this->m_GroupData[GroupID].ItemData[ItemPerGroup].Count		= lpMemScript->GetAsNumber();
	//			// ----
	//			ItemPerGroup++;
	//		}
	//		// ----
	//		this->m_GroupLoadedCount++;
	//	}
	//}
	//catch(...)
	//{
	//	ErrorMessageBox(lpMemScript->GetLastError());
	//}

	//delete lpMemScript;
}
// -------------------------------------------------------------------------

int ResetSystem::GetResetMoney()
{
	return this->ResetMoney;
}
// -------------------------------------------------------------------------

//int ResetSystem::GetResetGroup()
//{
//	for( int Group = 0; Group < this->m_GroupLoadedCount; Group++ )
//	{
//		if( ViewReset >= this->m_GroupData[Group].MinReset 
//			&& ViewReset < this->m_GroupData[Group].MaxReset )
//		{
//			return Group;
//		}
//	}
//	// ----
//	return -1;
//}
// -------------------------------------------------------------------------

bool ResetSystem::CheckAllReq()
{
	if( gObjUser.lpPlayer->MoneyInventory 
		< this->ResetMoney )
	{
		return false;
	}
	// ----
	if( gObjUser.lpPlayer->Level < this->m_ResetData.ReqLevel)//this->m_GroupData[this->GetResetGroup()].ReqLevel[ViewAccountLevel] )
	{
		return false;
	}
	// ----
	for( int i = 0; i < this->m_ResetData.ItemCount/*this->m_GroupData[this->GetResetGroup()].ItemCount*/; i++ )
	{
		if( !gObjUser.m_ResetItemCheck[i] )
		{
			return false;
		}
	}
	// ----
	return true;
}
// -------------------------------------------------------------------------

void ResetSystem::SetData(RESET_ANS_USERDATA * aRecv)
{
	//pOpenInfoBox(pTextLineThis,((int(__cdecl*)(LPVOID a,char* This))0x00409A50)(pTextLineThis,"test"),-1);
	ZeroMemory(gObjUser.m_ResetItemCheck, sizeof(gObjUser.m_ResetItemCheck));
	// ----
	ViewReset = aRecv->Reset;

	this->ResetMoney = aRecv->ResetMoney;
	this->m_BonusCommand = aRecv->CommandPerReset;

	this->m_ResetData = aRecv->ResetData;

	for( int i = 0; i < 5; i++ )
	{
		gObjUser.m_ResetItemCheck[i] = aRecv->ItemCheck[i];
	}
	// ----
	if( aRecv->ByDialog )
	{
		gInterface.Data[eRESET_MAIN].Open();
	}
}
// -------------------------------------------------------------------------

void ResetSystem::ReqResetFinish()
{
	RESET_REQ_USERDATA pRequest;
	pRequest.h.set(0xFF,0x07,sizeof(pRequest));
	DataSend((BYTE*)&pRequest,pRequest.h.size);
}
// -------------------------------------------------------------------------

void ResetSystem::GetResetResult()
{
	gInterface.Data[eRESET_MAIN].Close();
}
// -------------------------------------------------------------------------

int ResetSystem::GetRewardPoints()
{
	/*int Group = this->GetResetGroup();

	if (Group == -1)
	{
		return 0;
	}
	return (this->m_GroupData[gResetSystem.GetResetGroup()].RewardData[gObjUser.lpPlayer->Class&7].LevelPoint * (ViewReset + 1));*/
	return this->m_ResetData.RewardData.LevelPoint * (ViewReset + 1);
}
