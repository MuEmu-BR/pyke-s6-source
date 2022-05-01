#include "stdafx.h"
#include "CustomNpcName.h"
#include "Offset.h"
#include "User.h"
#include "TMemory.h"
#include "Interface.h"
#include "Protocol.h"
#include "Object.h"
#include "Import.h"
#include "Defines.h"
#include "Util.h"
#include "User.h"
#include "PrintPlayer.h"
#include "Camera.h"
#include "ResetSystem.h"

User gObjUser;

DWORD LastTime = 0;

void User::Load()
{
	this->m_TargetUpdateTick	= 0;
	this->m_TargetType			= false;
	this->m_CursorX				= -1;
	this->m_CursorY				= -1;
	this->m_MapNumber			= -1;

	SetCompleteHook(0xFF, 0x0077F822, &this->ChangeCharInfo);

	ZeroMemory(this->m_ResetItemCheck, sizeof(this->m_ResetItemCheck));

	SetCompleteHook(0xFF, 0x00520ECF, &this->GetMapName);
	SetCompleteHook(0xFF, 0x00520F1F, &this->GetMapName);
	SetCompleteHook(0xFF, 0x0063E743, &this->GetMapName);
	SetCompleteHook(0xFF, 0x00640EB2, &this->GetMapName);
	SetCompleteHook(0xFF, 0x007D2DD9, &this->GetMapName);
	SetCompleteHook(0xFF, 0x007E6C0F, &this->GetMapName);
	SetCompleteHook(0xFF, 0x0084AEF7, &this->GetMapName);

	//SetOp((LPVOID)0x00588511, (LPVOID)this->SetEventEffect, ASM::CALL);
}

void User::Refresh()
{
	
	this->lpPlayer			= &*(ObjectCharacter*)oUserObjectStruct;
	this->lpViewPlayer		= &*(ObjectPreview*)oUserPreviewStruct;
	this->GetTarget();

	this->m_CursorX			= pCursorX;
	this->m_CursorY			= pCursorY;
	this->m_MapNumber		= pMapNumber;
	this->m_MasterLevel = pMasterLevel;
	this->m_MasterPoint = pMasterPoint;
	this->m_MasterExp = pMasterExp;
	this->m_MasterNextExp = pMasterNextExp;

	this->CoordenadaX = this->lpViewPlayer->MapPosX;
	this->CoordenadaY = this->lpViewPlayer->MapPosY;
	this->getLevel = gObjUser.lpPlayer->Level;
	this->GetPet = this->lpViewPlayer->PetSlot;
	this->InSafeZone = this->lpViewPlayer->InSafeZone;

	sprintf(this->getName,"%s",gObjUser.lpPlayer->Name);

	if ( gObjUser.GetActiveSkill() == 261 || 
		gObjUser.GetActiveSkill() == 552 || 
		gObjUser.GetActiveSkill() == 555 )
	{
		SetDouble(&pFrameSpeed1, 0.0004000);
		SetDouble(&pFrameSpeed2, 0.0002000);
	}
	else
	{
		SetDouble(&pFrameSpeed1, 0.0040000);
		SetDouble(&pFrameSpeed2, 0.0020000);
	}
}

bool User::GetTarget()
{
	if( pViewNPCTargetID != -1 )
	{
		this->lpViewTarget	= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), pViewNPCTargetID);

		this->m_TargetType	= 1;
		return true;
	}
	else if( pViewAttackTargetID != -1 )
	{
		this->lpViewTarget	= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), pViewAttackTargetID);
		this->m_TargetType	= 2;
		return true;
	}
	
	if( this->lpViewTarget != 0 )
	{
		ZeroMemory(&this->lpViewTarget, sizeof(this->lpViewTarget));
	}
	
	this->m_TargetType = 0;
	return false;
}

int User::GetActiveSkill()
{
 lpCharObj lpPlayer  = &*(ObjectCharacter*)*(int*)(MAIN_CHARACTER_STRUCT);
 lpViewObj lpViewPlayer  = &*(ObjectPreview*)*(int*)(MAIN_VIEWPORT_STRUCT);
 return lpPlayer->pMagicList[lpViewPlayer->ActiveMagic];
}

void User::SetEventEffect(int PreviewStruct)
{

	lpViewObj lpPreview = &*(ObjectPreview*)PreviewStruct;

	if(lpPreview)
	{
		if(*(DWORD*)(MAIN_SCREEN_STATE) == GameProcess)
		{
			if (lpPreview->m_Model.ObjectType == emPlayer)
			{
					VAngle Angle;
					int PosX;
					int PosY;

					Angle.X = *(float*)(PreviewStruct+0x404);

					Angle.Y = *(float*)(PreviewStruct+0x408);

					Angle.Z = *(float*)(PreviewStruct+0x40C) + *(float*)(PreviewStruct+0x3E8) + 100.0f;

					pGetPosFromAngle(&Angle, &PosX, &PosY);
			}
		}
	}

	// ----
	if( lpPreview->CtlCode == 32 )
	{
		if( *(DWORD*)(PreviewStruct + 672) && lpPreview->Unknown23 != 5 )
		{
			pInitEventStatus(PreviewStruct);
		}
		// ----
		lpPreview->Unknown23 = 5;
	}
	// ----
	if( *(DWORD*)(PreviewStruct + 672) != 0 || !lpPreview->Unknown23 )
	{
		return;
	}
	// ----
	switch(lpPreview->Unknown23)
	{
	case 5:	//-> GM
		{
			if( pEventEffectThis(668) )
			{
				DWORD ModelID = 349;
				// ----
				if( !strncmp(lpPreview->Name, "[GM]", 4) )
				{
					ModelID = 406;
				}
				else if( !strncmp(lpPreview->Name, "[EM]", 4) )
				{
					ModelID = 407;
				}
				else if( !strcmp(lpPreview->Name, "Admin") )
				{
					ModelID = 408;
				}

				// ----
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect(pEventEffectThis(668), ModelID, 20, 1, 70.0, -5.0, 0.0, 0.0, 0.0, 45.0);
			}
		}
		break;
		// --
	case 6:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 0, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 7:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 1, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 8:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 2, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 9:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 3, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 10:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 4, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 11:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 5, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 12:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 6, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
		// --
	case 13:
		{
			if( pEventEffectThis(668) )
			{
				*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 7, 20, 120.0, 0.0, 0.0);
			}
		}
		break;
	default:
		{
			lpPreview->Unknown23 = 0;
		}
		break;
	}
}

char* User::GetMapName(int MapNumber)
{
	if (MapNumber >= 82 && MapNumber <= 100)
	{
		return pGetTextLine(pTextLineThis, (3170 + MapNumber - 82));
	}
	return pGetMapName(MapNumber);
}

void User::ChangeCharInfo(LPVOID This)
{
	if (!gInterface.CheckWindow(Character))
	{
		return;
	}

	gInterface.DrawFormat(eShinyGreen, 473, 56, 100, 1, "Level: %d", gObjUser.lpPlayer->Level);
	gInterface.DrawFormat(eShinyGreen, 520, 56, 100, 1, "Reset: %d", ViewReset);
	//gInterface.DrawFormat(eExcellent, 570, 58, 100, 1, "Grand Reset: %d", ViewGReset);
	char Value[50];
	if (gInterface.m_QuickAdd == 1)
	{
		gInterface.DrawButton(eCHARINFO_BTN_STAT, 473, 73, 0, 0);
		gInterface.DrawFormat(eShinyGreen, 492, 76, 100, 1, "Quick add stats");
		pDrawGUI(0x9306, 565, 73, 50, 16);

		ZeroMemory(Value, sizeof(Value));
		pGetMoneyFormat((double)ViewPoint, Value, 0);
		GetFormat(Value, ',', ' ');

		gInterface.DrawFormat(eBlue, 540, 77, 100, 3, "%s", Value);

		if (gInterface.IsWorkZone(eCHARINFO_BTN_STAT))
		{
			if (gInterface.Data[eCHARINFO_BTN_STAT].OnClick)
			{
				gInterface.DrawButton(eCHARINFO_BTN_STAT, 473, 73, 0, 14);
			}
		}
	}

	if (gInterface.m_ResetStats == 1)
	{
		int StatPoints = ViewStrength + ViewDexterity + ViewVitality + ViewEnergy + (ViewLeadership-(gResetSystem.m_BonusCommand*ViewReset));

		//console.Log("", "[%d] %d %d %d %d %d", StatPoints, ViewStrength,ViewDexterity,ViewVitality,ViewEnergy,ViewLeadership);

		//StatPoints -= (gConfig.Strength + gConfig.Dexterity + gConfig.Vitality + gConfig.Energy + gConfig.Leadership);
		StatPoints -= (gObjUser.d_Strength + gObjUser.d_Dexterity + gObjUser.d_Vitality + gObjUser.d_Energy + gObjUser.d_Leadership);

		gInterface.DrawButton(eCHARINFO_BTN_RESSTAT, 473, 94, 0, 0);
		gInterface.DrawFormat(eShinyGreen, 492, 97, 100, 1, "Reset stats");
		pDrawGUI(0x9306, 565, 94, 50, 16);

		char Value2[50];
		ZeroMemory(Value, sizeof(Value2));
		pGetMoneyFormat((double)StatPoints, Value2, 0);
		GetFormat(Value2, ',', ' ');

		gInterface.DrawFormat(eBlue, 540, 98, 100, 3, "%s", Value2);

		if (gInterface.IsWorkZone(eCHARINFO_BTN_RESSTAT))
		{
			if (gInterface.Data[eCHARINFO_BTN_RESSTAT].OnClick)
			{
				gInterface.DrawButton(eCHARINFO_BTN_RESSTAT, 473, 94, 0, 14);
			}
		}
	}
	else
	{
		((BOOL(__thiscall*)(LPVOID This))0x0077FAE0)(This);
	}
}

int User::GetResetPointPriceWC(int AccountLevel)
{
	return this->m_CustomResetPointPriceWC[AccountLevel];
}


int User::GetResetPointPriceZen(int AccountLevel)
{
	return this->m_CustomResetPointPriceZen[AccountLevel];
}

int User::GetResetMasterSkillPriceWC(int AccountLevel)
{
	return this->m_CustomMasterSkillPriceWC[AccountLevel];
}

int User::GetResetMasterSkillPriceZen(int AccountLevel)
{
	return this->m_CustomMasterSkillPriceZen[AccountLevel];
}

int User::GetMaxStatPoint(int AccountLevel)
{
	return this->m_MaxStatPoint[AccountLevel];
}
