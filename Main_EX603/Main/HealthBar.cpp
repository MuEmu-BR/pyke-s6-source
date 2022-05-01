#include "stdafx.h"
#include "HealthBar.h"
#include "Util.h"
#include "Offset.h"
#include "Camera.h"
#include "Interface.h"

#include "User.h"
#include "MonsterBar.h"
#include "NewParty.h"
#include "Font.h"
#include "CustomRankUser.h"
#include "Common.h"

CHPBar gHPBar;

NEW_HEALTH_BAR gNewHealthBar[MAX_MAIN_VIEWPORT];

CHPBar::CHPBar()
{

}

CHPBar::~CHPBar()
{

}

void CHPBar::ClearNewHealthBar() // OK
{
	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		gNewHealthBar[n].index = 0xFFFF;
		gNewHealthBar[n].type = 0;
		gNewHealthBar[n].rate = 0;
		gNewHealthBar[n].monsterid = 0;
		gNewHealthBar[n].Life = 0;
		gNewHealthBar[n].Reset = 0;
		gNewHealthBar[n].MaxLife = 0;
		gNewHealthBar[n].Level = 0;
		gNewHealthBar[n].Shield = 0;
		gNewHealthBar[n].MaxShield = 0;
		gNewHealthBar[n].SDrate = 0;
		gNewHealthBar[n].isSameGuild = false;
		gNewHealthBar[n].HaveGuild = false;
		//gNewHealthBar[n].Rank = 0;

		for	(int i=0;i<64;i++)
		{
			gNewHealthBar[n].Mark[i] = 0;
		}
	}
}

void CHPBar::InsertNewHealthBar(PMSG_NEW_HEALTH_RECV* lpInfo) // OK
{
	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		if(gNewHealthBar[n].index == 0xFFFF)
		{
			gNewHealthBar[n].index = lpInfo->index;
			gNewHealthBar[n].type = lpInfo->type;
			gNewHealthBar[n].rate = lpInfo->rate;
			gNewHealthBar[n].monsterid = lpInfo->monsterid;
			gNewHealthBar[n].Life = lpInfo->Life;
			gNewHealthBar[n].MaxLife = lpInfo->MaxLife;
			gNewHealthBar[n].Level = lpInfo->Level;
			gNewHealthBar[n].Reset = lpInfo->Reset;
			gNewHealthBar[n].Shield = lpInfo->Shield;
			gNewHealthBar[n].MaxShield = lpInfo->MaxShield;
			gNewHealthBar[n].SDrate = lpInfo->SDrate;
			gNewHealthBar[n].isSameGuild = lpInfo->isSameGuild;
			gNewHealthBar[n].HaveGuild = lpInfo->HaveGuild;
			//gNewHealthBar[n].Rank = lpInfo->Rank;

			if (lpInfo->type == emPlayer && lpInfo->HaveGuild)
			{
				memcpy(gNewHealthBar[n].GuildName,lpInfo->GuildName,sizeof(gNewHealthBar[n].GuildName));
				char kek[65];

				for	(int i=0;i<32;i++)
				{
					sprintf(&kek[i * 2], "%02x", lpInfo->Mark[i]);
				}
				kek[64] = '\0';

				for	(int i=0;i<64;i++)
				{
					if (kek[i]>=97)
					{
						gNewHealthBar[n].Mark[i] = (int)kek[i] - 87;
					}
					else
					{
						gNewHealthBar[n].Mark[i] = (int)kek[i] - 48;
					}
					//atoi(kek[i]);
					//g_Console.AddMessage(5,"%d",(int)kek[i]);
				}

				//g_Console.AddMessage(5,"Logo setted!");
			}
			return;
		}
	}
}

NEW_HEALTH_BAR* CHPBar::GetNewHealthBar(WORD index,BYTE type) // OK
{
	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		if(gNewHealthBar[n].index != 0xFFFF)
		{
			if(gNewHealthBar[n].index == index && gNewHealthBar[n].type == type)
			{
				return &gNewHealthBar[n];
			}
		}
	}

	return 0;
}

#define sub_56F210_Addr			((void(__cdecl*)(ObjectPreview *a4, ObjectModel *a5, int a6)) 0x0056F210)
#define sub_4CD7F0_Addr			((int(__thiscall*)(ObjectModel *a5, signed int a2)) 0x004CD7F0)
#define sub_545030_Addr			((int(__thiscall*)(void *This, int a2, int a3, DWORD *a4, char a5)) 0x00545030)
//sub_9CFB8D

void ItemEquip()
{
	//D28AB8
	//g_Console.AddMessage(5,"Index = %d",*(int*)0xD28AA8);
	//size = 656
	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		lpViewObj lpObj		= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), n);
		if (lpObj->aIndex == gObjUser.lpViewPlayer->aIndex)
		{
		
			if (pGetRand()%4 != 0)
			{
				continue;
			}
			//g_Console.AddMessage(5,"type = %d|%d [%s - %s]",a4->m_Model.ObjectType,a5->ObjectType,a4->Name,gObjUser.lpViewPlayer->Name);
			lpObj->m_Model.Unknown156 = 1.0;
			lpObj->m_Model.Unknown160 = 1.0;
			lpObj->m_Model.Unknown164 = 1.0;
			//a5->VecPos.X+=5;

			int v8 = sub_4CDA10_Addr();
			int v554 = sub_969C50_Addr(v8, lpObj->m_Model.Unknown48);

			int v276 = sub_4CD7F0_Addr(&lpObj->m_Model,0);

			VAngle test;
			test.X = 0.0;
			test.Y = -18.0;
			test.Z = 50;

			DWORD v556;

			//a5->Angle.X+=10;

			float R = lpObj->m_Model.Unknown156;
			float G = lpObj->m_Model.Unknown160;
			float B = lpObj->m_Model.Unknown164;

			int Effect = 32288;

			//pCustomEffGet2(v554,v276)
			int EffectType = 3;
			sub_545030_Addr((LPVOID)v554,v276,(int)&test,&v556,1);
			pPlayDynamicEffect(Effect,&v556,(int)&lpObj->m_Model.Angle, &lpObj->m_Model.Unknown156, EffectType, 1.0, 0);
			test.X = 0.0;
			test.Y = 0.0;
			test.Z = 70.0;
			sub_545030_Addr((LPVOID)v554,v276,(int)&test,&v556,1);
			pPlayDynamicEffect(Effect,&v556,(int)&lpObj->m_Model.Angle, &lpObj->m_Model.Unknown156, EffectType, 1.0, 0);
			test.X = 0.0;
			test.Y = 18.0;
			test.Z = 50.0;
			sub_545030_Addr((LPVOID)v554,v276,(int)&test,&v556,1);
			pPlayDynamicEffect(Effect,&v556,(int)&lpObj->m_Model.Angle, &lpObj->m_Model.Unknown156, EffectType, 1.0, 0);

			lpObj->m_Model.Unknown156 = R;
			lpObj->m_Model.Unknown160 = G;
			lpObj->m_Model.Unknown164 = B;
		}
	}
}

void getColor(int type,int &red,int &green,int &blue, int &alpha)
{
	/*
	0 transparent    
	1 black      000000
	2 Gray     808080
	3 White     ffffff
	4 Red      ff0000
	5 Orange     ff8000
	6 Yellow     ffff00
	7 LightGreen    80ff00
	8 Green     00ff00
	9 BlueGreen    00ff80
	a Turcus     00ffff
	b LightBlue    0080ff
	c Blue     0000ff  
	d Purple     8000ff
	e Pink     ff00ff
	f DarkPink    ff0080
	 */
	switch(type)
	{
		case 0x0:
			alpha = 0;
		break;
		case 0x1:
			red = 0;
			green = 0;
			blue = 0;
			alpha = 0xFF;
		break;
		case 0x2:
			red = 0x80;
			green = 0x80;
			blue = 0x80;
			alpha = 0xFF;
		break;
		case 0x3:
			red = 0xFF;
			green = 0xFF;
			blue = 0xFF;
			alpha = 0xFF;
		break;
		case 0x4:
			red = 0xFF;
			green = 0;
			blue = 0;
			alpha = 0xFF;
		break;
		case 0x5:
			red = 0xFF;
			green = 0x80;
			blue = 0;
			alpha = 0xFF;
		break;
		case 0x6:
			red = 0xFF;
			green = 0xFF;
			blue = 0;
			alpha = 0xFF;
		break;
		case 0x7:
			red = 0x80;
			green = 0xFF;
			blue = 0;
			alpha = 0xFF;
		break;
		case 0x8:
			red = 0;
			green = 0xFF;
			blue = 0;
			alpha = 0xFF;
		break;
		case 0x9:
			red = 0;
			green = 0xFF;
			blue = 0x80;
			alpha = 0xFF;
		break;
		case 0xA:
			red = 0;
			green = 0xFF;
			blue = 0xFF;
			alpha = 0xFF;
		break;
		case 0xB:
			red = 0;
			green = 0x80;
			blue = 0xFF;
			alpha = 0xFF;
		break;
		case 0xC:
			red = 0;
			green = 0;
			blue = 0xFF;
			alpha = 0xFF;
		break;
		case 0xD:
			red = 0x80;
			green = 0;
			blue = 0xFF;
			alpha = 0xFF;
		break;
		case 0xE:
			red = 0xFF;
			green = 0;
			blue = 0xFF;
			alpha = 0xFF;
		break;
		case 0xF:
			red = 0xFF;
			green = 0;
			blue = 0x80;
			alpha = 0xFF;
		break;
	}
}

void DrawGuildLogo(BYTE* Mark, float startX, float startY)
{
	glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.7); // Цвет фона для имени
	pDrawBarForm(startX-1,startY,10,10,0.0,0);
	int line = 0;
	for	(int i=0;i<64;i++)
	{
		//g_Console.AddMessage(5,"%d",lpNewHealthBar->Mark[i]);
		if (i%8==0)
		{
			line++;
		}
		int red=0;
		int green=0;
		int blue = 0;
		int alpha = 0;
		getColor(Mark[i],red,green,blue,alpha);
		pSetBlend(true);
		glColor4f(RGBTOGLFLOAT(red), RGBTOGLFLOAT(green), RGBTOGLFLOAT(blue), RGBTOGLFLOAT(alpha));
		pDrawBarForm(startX+((i%8)),startY+line,1,1,0.0f, 0);
		pGLSwitchBlend();
		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);

	}
}

void CHPBar::DrawTestHealthBar()
{
	if (!HpMonsterBar)
	{
		return;
	}

	int PosX, PosY;
	float LifeBarWidth = 66.95;
	char LifeDisplay[20];
	VAngle Angle;

	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		lpViewObj lpObj		= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), n);
		lpViewObj lpTarget	= gObjUser.lpViewTarget;

		//g_Console.AddMessage(5,lpTarget->Name);

		bool istarget = 1;

		if( !lpTarget || (lpTarget->m_Model.ObjectType != emMonster && lpTarget->m_Model.ObjectType != emPlayer) || !lpTarget->m_Model.Unknown4 || lpTarget->aIndex != lpObj->aIndex )
		{
			istarget = 0;
		}

		if(!lpObj)
		{
			continue;
		}

		if(lpObj->m_Model.Unknown4 == 0)
		{
			continue;
		}

		NEW_HEALTH_BAR* lpNewHealthBar = this->GetNewHealthBar(lpObj->aIndex,lpObj->m_Model.ObjectType);

		if(lpNewHealthBar == 0)
		{
			continue;
		}

		//int LifePercent = lpNewHealthBar->rate/10;

		Angle.X = lpObj->m_Model.VecPos.X;
		Angle.Y = lpObj->m_Model.VecPos.Y;
		Angle.Z = lpObj->m_Model.VecPos.Z + lpObj->m_Model.Unknown216.Z + 100.0;

		pGetPosFromAngle(&Angle, &PosX, &PosY);
		float PosX1 = PosX;
		PosX -= (int)floor(LifeBarWidth / (double)2.0);

		pSetBlend(true);

		if (lpNewHealthBar->type == emPlayer)
		{
			float bg_width = 56.95;
			
			if (!istarget)
			{
				if (lpNewHealthBar->HaveGuild)
				{
					DrawGuildLogo(lpNewHealthBar->Mark,PosX-10,PosY-10);
				}

				float BarWidth = (((bg_width - 1) / 100.0f) * lpNewHealthBar->rate) - 1;
				float SDBarWidth = (((bg_width - 1) / 100.0f) * lpNewHealthBar->SDrate) - 1;

				glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.7); // Цвет фона для имени
				pDrawBarForm((float)(PosX - 1), (float)(PosY), bg_width, 7, 0.0, 0); // Фон для имени

				glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT((255.0f/100.0f)*lpNewHealthBar->SDrate), RGBTOGLFLOAT(0), 0.8); // Цвет SD Бара
				
				pDrawBarForm((float)(PosX), (float)(PosY+1), SDBarWidth, 1, 0.0, 0); // SD Бар

				glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT(ABS(((255.0f/100.0f)*lpNewHealthBar->rate)-255.0f)), RGBTOGLFLOAT(0), 0.8); // Цвет ХП Бара
				
				pDrawBarForm((float)(PosX), (float)(PosY+3), BarWidth, 3, 0.0, 0); // ХпБар

				glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.7); // Цвет фона для имени
				pDrawBarForm(PosX+bg_width,PosY-1,12,8,0.0,0);

				pGLSwitch();
				glColor3f(1.0, 1.0, 1.0);
				pDrawGUI(0xF91E,PosX+bg_width+1,PosY,10,6);

				int Color = eGold;

				//g_Console.AddMessage(5,"PKLevel = %d",lpObj->PkLevel);
				switch (lpObj->PkLevel)
				{
				case 1:
				case 2:
					Color = eBlue;
					break;
				case 4:
					Color = eOrange;
					break;
				case 5:
					Color = eRed;
					break;
				default:
					Color = eGold;
					break;
				}

				if (this->IsPartyMember(n))
				{
					Color = ePartyBlue;
				}
				//else if (lpNewHealthBar->isSameGuild == true)
				//{
				//	glColor4f(RGBTOGLFLOAT(18), RGBTOGLFLOAT(226), RGBTOGLFLOAT(131), 0.9); // Цвет фона для имени
				//}

				gInterface.TextDraw(PosX1,PosY+7,0,1,Color,0,8,/*gFont[ARIAL_14]->m_Font*/pFontNormal,lpObj->Name);

				if (lpNewHealthBar->HaveGuild)
				{
					Color = eGold;
					if (lpNewHealthBar->isSameGuild)
					{
						Color = eGuildGreen;
					}
					gInterface.TextDraw(PosX1,PosY-8,0,1,Color,0,8,/*gFont[ARIAL_16]->m_Font*/pFontNormal,lpNewHealthBar->GuildName);
				}

				//pDrawGUI(0xF91E,PosX+bg_width+1,PosY,16,11);
				//pDrawCircle(0xF91E, PosX+bg_width+1,PosY, 10.0, 6.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 1);
				
			}

			//if (this->IsPartyMember(n))
			//{
			//	glColor4f(RGBTOGLFLOAT(63), RGBTOGLFLOAT(124), RGBTOGLFLOAT(204), 0.9); // Цвет фона для имени
			//}
			//else if (lpNewHealthBar->isSameGuild == true)
			//{
			//	glColor4f(RGBTOGLFLOAT(18), RGBTOGLFLOAT(226), RGBTOGLFLOAT(131), 0.9); // Цвет фона для имени
			//}
			//else
			//{
			//	glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для имени
			//}

			//if (!istarget)
			//{
			//	pDrawBarForm((float)(PosX - 1), (float)(PosY - 12), 66.95, 10, 0.0, 0); // Фон для имени
			//}
			//else
			//{
			//	pDrawBarForm((float)(PosX - 1), (float)(PosY + 12), 66.95, 20, 0.0, 0); // Фон для имени
			//}			

			//glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для хпбара
			//pDrawBarForm((float)(PosX - 1), (float)(PosY - 1.5), 66.95, 6, 0.0, 0); // Фон хпбара
			//pDrawBarForm((float)(PosX - 1), (float)(PosY + 5), 66.95, 6, 0.0, 0); // Фон SD
			//
			//glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT(ABS(((255.0f/100.0f)*lpNewHealthBar->rate)-255.0f)), RGBTOGLFLOAT(0), 0.8); // Цвет ХП Бара

			//pDrawBarForm((float)(PosX), (float)(PosY), BarWidth, 3, 0.0, 0); // ХпБар

			//glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT((255.0f/100.0f)*lpNewHealthBar->SDrate), RGBTOGLFLOAT(0), 0.8); // Цвет SD Бара

			//pDrawBarForm((float)(PosX), (float)(PosY+7), SDBarWidth, 2.5, 0.0, 0); // SD Бар

			//if(!istarget)
			//{
			//	if (lpNewHealthBar->isSameGuild)
			//	{
			//		pDrawColorText(lpObj->Name, PosX -1, PosY - 11, 66.95, 1, eBlack, 9, 3); // Драв имени
			//	}
			//	else
			//	{
			//		pDrawColorText(lpObj->Name, PosX -1, PosY - 11, 66.95, 1, eWhite, 9, 3); // Драв имени
			//	}
			//}
			//else
			//{
			//	char Text[100];
			//	//char HP[20];
			//	//char MaxHP[20];
			//	//strcpy(HP, this->GetHPValue((int)lpNewHealthBar->Life));
			//	//strcpy(MaxHP, this->GetHPValue((int)lpNewHealthBar->MaxLife));
			//	sprintf(Text, "Lvl: %d R: %d HP: %s/%s", lpNewHealthBar->Level, lpNewHealthBar->Reset, this->ParseReducedValue((int)lpNewHealthBar->Life), this->ParseReducedValue((int)lpNewHealthBar->MaxLife));

			//	if (lpNewHealthBar->isSameGuild)
			//	{
			//		pDrawColorText(lpObj->Name, PosX -1, PosY + 23, 67, 1, eBlack, 9, 3); // Драв имени
			//		pDrawColorText(Text, PosX -1, PosY + 13, 67, 1, eBlack, 9, 3); // Драв инфы
			//	}
			//	else
			//	{
			//		pDrawColorText(lpObj->Name, PosX -1, PosY + 23, 67, 1, eWhite, 9, 3); // Драв имени
			//		pDrawColorText(Text, PosX -1, PosY + 13, 67, 1, eWhite, 9, 3); // Драв инфы
			//	}
			//}
		}
		
		pGLSwitch();
	}

	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);
}


void CHPBar::DrawHealthBar()
{
	if (!HpMonsterBar)
	{
		return;
	}

	//g_Console.AddMessage(5,"HPBAR");
	//((void(*)())0x005BA770)();

	//ItemEquip();

	int PosX, PosY;
	float LifeBarWidth = 66.95;
	char LifeDisplay[20];
	VAngle Angle;

	/*if (gObjUser.Rank != 0)
	{
		g_Console.AddMessage(5,"SELF RANK [%d]", gObjUser.Rank);
		Angle.X = gObjUser.lpViewPlayer->m_Model.VecPos.X;
		Angle.Y = gObjUser.lpViewPlayer->m_Model.VecPos.Y;
		Angle.Z = gObjUser.lpViewPlayer->m_Model.VecPos.Z + gObjUser.lpViewPlayer->m_Model.Unknown216.Z + 100.0;

		pGetPosFromAngle(&Angle, &PosX, &PosY);
		PosX -= (int)floor(LifeBarWidth / (double)2.0);

		float RankX = PosX + (66.95/2) - gInterface.Data[eRANK1+gObjUser.Rank-1].Width/2;
		gInterface.DrawGUI(eRANK1+gObjUser.Rank-1,RankX, (float)(PosY -30));
	}*/

	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		lpViewObj lpObj		= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), n);
		lpViewObj lpTarget	= gObjUser.lpViewTarget;

		//g_Console.AddMessage(5,lpTarget->Name);

		bool istarget = 1;

		if( !lpTarget || (lpTarget->m_Model.ObjectType != emMonster && lpTarget->m_Model.ObjectType != emPlayer) || !lpTarget->m_Model.Unknown4 || lpTarget->aIndex != lpObj->aIndex )
		{
			istarget = 0;
		}

		if(!lpObj)
		{
			continue;
		}

		if(lpObj->m_Model.Unknown4 == 0)
		{
			continue;
		}

		NEW_HEALTH_BAR* lpNewHealthBar = this->GetNewHealthBar(lpObj->aIndex,lpObj->m_Model.ObjectType);

		if(lpNewHealthBar == 0)
		{
			continue;
		}

		int LifePercent = lpNewHealthBar->rate/10;
		float BarWidth = (((66.95 - 1) / 100.0f) * lpNewHealthBar->rate) - 1;
		float SDBarWidth = (((66.95 - 1) / 100.0f) * lpNewHealthBar->SDrate) - 1;

		Angle.X = lpObj->m_Model.VecPos.X;
		Angle.Y = lpObj->m_Model.VecPos.Y;
		Angle.Z = lpObj->m_Model.VecPos.Z + lpObj->m_Model.Unknown216.Z + 100.0;

		pGetPosFromAngle(&Angle, &PosX, &PosY);
		PosX -= (int)floor(LifeBarWidth / (double)2.0);

		pSetBlend(true);

		if (lpNewHealthBar->type == emPlayer)
		{
			/*if (lpNewHealthBar->Rank != 0)
			{
				float RankX = PosX + (66.95/2) - gInterface.Data[eRANK1+lpNewHealthBar->Rank-1].Width/2;
				gInterface.DrawGUI(eRANK1+lpNewHealthBar->Rank-1,RankX, (float)(PosY -30));
			}*/
			
			//if (lpNewHealthBar->HaveGuild)
			//{
			//	int line = 0;
			//	for	(int i=0;i<64;i++)
			//	{
			//		//g_Console.AddMessage(5,"%d",lpNewHealthBar->Mark[i]);
			//		if (i%8==0)
			//		{
			//			line++;
			//		}
			//		int red=0;
			//		int green=0;
			//		int blue = 0;
			//		int alpha = 0;
			//		getColor(lpNewHealthBar->Mark[i],red,green,blue,alpha);
			//		pSetBlend(true);
			//		glColor4f(RGBTOGLFLOAT(red), RGBTOGLFLOAT(green), RGBTOGLFLOAT(blue), RGBTOGLFLOAT(alpha));
			//		pDrawBarForm(PosX-20+((i%8)),PosY+line,1,1,0.0f, 0);
			//		pGLSwitchBlend();
			//		pGLSwitch();
			//		glColor3f(1.0, 1.0, 1.0);
			//		pSetBlend(false);

			//	}
			//}
			
			if (this->IsPartyMember(n))
			{
				glColor4f(RGBTOGLFLOAT(63), RGBTOGLFLOAT(124), RGBTOGLFLOAT(204), 0.9); // Цвет фона для имени
			}
			else if (lpNewHealthBar->isSameGuild == true)
			{
				glColor4f(RGBTOGLFLOAT(18), RGBTOGLFLOAT(226), RGBTOGLFLOAT(131), 0.9); // Цвет фона для имени
			}
			else
			{
				glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для имени
			}

		
			pDrawBarForm((float)(PosX - 1), (float)(PosY - 12), 66.95, 10, 0.0, 0); // Фон для имени
				

			glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для хпбара
			pDrawBarForm((float)(PosX - 1), (float)(PosY - 1.5), 66.95, 6, 0.0, 0); // Фон хпбара
			pDrawBarForm((float)(PosX - 1), (float)(PosY + 5), 66.95, 6, 0.0, 0); // Фон SD
			
			glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT(ABS(((255.0f/100.0f)*lpNewHealthBar->rate)-255.0f)), RGBTOGLFLOAT(0), 0.8); // Цвет ХП Бара

			pDrawBarForm((float)(PosX), (float)(PosY), BarWidth, 3, 0.0, 0); // ХпБар

			glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT((255.0f/100.0f)*lpNewHealthBar->SDrate), RGBTOGLFLOAT(0), 0.8); // Цвет SD Бара

			pDrawBarForm((float)(PosX), (float)(PosY+7), SDBarWidth, 2.5, 0.0, 0); // SD Бар

			
				if (lpNewHealthBar->isSameGuild)
				{
					pDrawColorText(lpObj->Name, PosX -1, PosY - 11, 66.95, 1, eBlack, 9, 3); // Драв имени
				}
				else
				{
					pDrawColorText(lpObj->Name, PosX -1, PosY - 11, 66.95, 1, eWhite, 9, 3); // Драв имени
				}
		
		}
		else
		{
			MONSTERBAR_DATA* HpBarEx = gMonsterBar.GetHPBar(lpNewHealthBar->monsterid);

			if(HpBarEx == 0)
			{
				glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для имени

			
					pDrawBarForm((float)(PosX - 1), (float)(PosY - 12), 66.95, 10, 0.0, 0); // Фон для имени
				
			

				glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для хпбара
				pDrawBarForm((float)(PosX - 1), (float)(PosY - 1.5), 66.95, 6, 0.0, 0); // Фон хпбара

				glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT(ABS(((255.0f/100.0f)*lpNewHealthBar->rate)-255.0f)), RGBTOGLFLOAT(0), 0.8); // Цвет ХП Бара

				pDrawBarForm((float)(PosX), (float)(PosY), BarWidth, 3, 0.0, 0); // ХпБар

				
					pDrawColorText(lpObj->Name, PosX -1, PosY - 11, 66.95, 1, eWhite, 9, 3); // Драв имени
			
			}
			else
			{
				glColor4f(RGBTOGLFLOAT(HpBarEx->Red), RGBTOGLFLOAT(HpBarEx->Green), RGBTOGLFLOAT(HpBarEx->Blue), HpBarEx->Opacity); // Цвет фона для имени

				
					pDrawBarForm((float)(PosX - 1), (float)(PosY - 22), 66.95, 20, 0.0, 0); // Фон для имени
			

				glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для хпбара
				pDrawBarForm((float)(PosX - 1), (float)(PosY - 1.5), 66.95, 6, 0.0, 0); // Фон хпбара

				glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT(ABS(((255.0f/100.0f)*lpNewHealthBar->rate)-255.0f)), RGBTOGLFLOAT(0), 0.8); // Цвет ХП Бара

				pDrawBarForm((float)(PosX), (float)(PosY), BarWidth, 3, 0.0, 0); // ХпБар

				
					pDrawColorText(lpObj->Name, PosX -1, PosY - 11, 66.95, 1, eWhite, 9, 3); // Драв имени
					pDrawColorText(HpBarEx->Text, PosX -1, PosY - 21, 66.95, 1, eWhite, 9, 3); // Драв имени
			
		
			}
		}



		

		pGLSwitch();
	}

	gCustomRankUser.DrawInfo();
	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);
}

void CHPBar::DrawCharacterBar(lpViewObj lpObj)
{
	if (!HpBar)
	{
		return;
	}

	int PosX, PosY;
	float LifeBarWidth = 66.95;
	char LifeDisplay[20];
	VAngle Angle;

	//for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	//{
		//lpViewObj lpObj		= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), n);
		//lpViewObj lpTarget	= gObjUser.lpViewTarget;

		//g_Console.AddMessage(5,lpTarget->Name);

		/*bool istarget = 1;

		if( !lpTarget || (lpTarget->m_Model.ObjectType != emMonster && lpTarget->m_Model.ObjectType != emPlayer) || !lpTarget->m_Model.Unknown4 || lpTarget->aIndex != lpObj->aIndex )
		{
			istarget = 0;
		}*/

		if(!lpObj)
		{
			return;
		}

		if(lpObj->m_Model.Unknown4 == 0)
		{
			return;
		}

		NEW_HEALTH_BAR* lpNewHealthBar = this->GetNewHealthBar(lpObj->aIndex,lpObj->m_Model.ObjectType);

		if(lpNewHealthBar == 0)
		{
			return;;
		}

		int LifePercent = lpNewHealthBar->rate/10;
		float BarWidth = (((66.95 - 1) / 100.0f) * lpNewHealthBar->rate) - 1;
		float SDBarWidth = (((66.95 - 1) / 100.0f) * lpNewHealthBar->SDrate) - 1;

		Angle.X = lpObj->m_Model.VecPos.X;
		Angle.Y = lpObj->m_Model.VecPos.Y;
		Angle.Z = lpObj->m_Model.VecPos.Z + lpObj->m_Model.Unknown216.Z + 100.0;

		pGetPosFromAngle(&Angle, &PosX, &PosY);
		PosX -= (int)floor(LifeBarWidth / (double)2.0);

		pSetBlend(true);

		bool istarget = true;

		if (lpNewHealthBar->type == emPlayer)
		{
			/*if (lpNewHealthBar->Rank != 0)
			{
				float RankX = PosX + (66.95/2) - gInterface.Data[eRANK1+lpNewHealthBar->Rank-1].Width/2;
				gInterface.DrawGUI(eRANK1+lpNewHealthBar->Rank-1,RankX, (float)(PosY -30));
			}*/
			
			//if (lpNewHealthBar->HaveGuild)
			//{
			//	int line = 0;
			//	for	(int i=0;i<64;i++)
			//	{
			//		//g_Console.AddMessage(5,"%d",lpNewHealthBar->Mark[i]);
			//		if (i%8==0)
			//		{
			//			line++;
			//		}
			//		int red=0;
			//		int green=0;
			//		int blue = 0;
			//		int alpha = 0;
			//		getColor(lpNewHealthBar->Mark[i],red,green,blue,alpha);
			//		pSetBlend(true);
			//		glColor4f(RGBTOGLFLOAT(red), RGBTOGLFLOAT(green), RGBTOGLFLOAT(blue), RGBTOGLFLOAT(alpha));
			//		pDrawBarForm(PosX-20+((i%8)),PosY+line,1,1,0.0f, 0);
			//		pGLSwitchBlend();
			//		pGLSwitch();
			//		glColor3f(1.0, 1.0, 1.0);
			//		pSetBlend(false);

			//	}
			//}
			
			if (this->IsPartyMember(lpObj->ID))
			{
				glColor4f(RGBTOGLFLOAT(63), RGBTOGLFLOAT(124), RGBTOGLFLOAT(204), 0.9); // Цвет фона для имени
			}
			else if (lpNewHealthBar->isSameGuild == true)
			{
				glColor4f(RGBTOGLFLOAT(18), RGBTOGLFLOAT(226), RGBTOGLFLOAT(131), 0.9); // Цвет фона для имени
			}
			else
			{
				glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для имени
			}

			if (!istarget)
			{
				pDrawBarForm((float)(PosX - 1), (float)(PosY - 12), 66.95, 10, 0.0, 0); // Фон для имени
			}
			else
			{
				pDrawBarForm((float)(PosX - 1), (float)(PosY + 12), 66.95, 20, 0.0, 0); // Фон для имени
			}			

			glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для хпбара
			pDrawBarForm((float)(PosX - 1), (float)(PosY - 1.5), 66.95, 6, 0.0, 0); // Фон хпбара
			pDrawBarForm((float)(PosX - 1), (float)(PosY + 5), 66.95, 6, 0.0, 0); // Фон SD
			
			glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT(ABS(((255.0f/100.0f)*lpNewHealthBar->rate)-255.0f)), RGBTOGLFLOAT(0), 0.8); // Цвет ХП Бара

			pDrawBarForm((float)(PosX), (float)(PosY), BarWidth, 3, 0.0, 0); // ХпБар

			glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT((255.0f/100.0f)*lpNewHealthBar->SDrate), RGBTOGLFLOAT(0), 0.8); // Цвет SD Бара

			pDrawBarForm((float)(PosX), (float)(PosY+7), SDBarWidth, 2.5, 0.0, 0); // SD Бар

			if(!istarget)
			{
				if (lpNewHealthBar->isSameGuild)
				{
					pDrawColorText(lpObj->Name, PosX -1, PosY - 11, 66.95, 1, eBlack, 9, 3); // Драв имени
				}
				else
				{
					pDrawColorText(lpObj->Name, PosX -1, PosY - 11, 66.95, 1, eWhite, 9, 3); // Драв имени
				}
			}
			else
			{
				char Text[100];
				//char HP[20];
				//char MaxHP[20];
				//strcpy(HP, this->GetHPValue((int)lpNewHealthBar->Life));
				//strcpy(MaxHP, this->GetHPValue((int)lpNewHealthBar->MaxLife));
				sprintf(Text, "Lvl: %d R: %d HP: %s/%s", lpNewHealthBar->Level, lpNewHealthBar->Reset, this->ParseReducedValue((int)lpNewHealthBar->Life), this->ParseReducedValue((int)lpNewHealthBar->MaxLife));

				if (lpNewHealthBar->isSameGuild)
				{
					pDrawColorText(lpObj->Name, PosX -1, PosY + 23, 67, 1, eBlack, 9, 3); // Драв имени
					pDrawColorText(Text, PosX -1, PosY + 13, 67, 1, eBlack, 9, 3); // Драв инфы
				}
				else
				{
					pDrawColorText(lpObj->Name, PosX -1, PosY + 23, 67, 1, eWhite, 9, 3); // Драв имени
					pDrawColorText(Text, PosX -1, PosY + 13, 67, 1, eWhite, 9, 3); // Драв инфы
				}
			}
		}
		//pGLSwitch();
	//}
	gCustomRankUser.DrawInfo();
	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);
}


bool CHPBar::IsPartyMember(int ViewportID)
{
#if (_NEW_PARTY_SYSTEM_ == TRUE )
	for( int PartySlot = 0; PartySlot < g_Party.PartyMemberCount; PartySlot++ )
#else
	for( int PartySlot = 0; PartySlot < pPartyMemberCount; PartySlot++ )
#endif
	{
		PartyList PartyMember	= *(PartyList*)((char*)&pPartyListStruct + sizeof(PartyList) * PartySlot);
		//lpViewObj lpPartyObj	= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), PartyMember.ViewportID);
		if (ViewportID == PartyMember.ViewportID)
		{
			return true;
		}
	}

	return false;
}

void CHPBar::DrawAllHPBars()
{
	//gHPBar.DrawTestHealthBar();
	gHPBar.DrawHealthBar();
	//gHPBar.DrawOldHPBar();
}
//
char* CHPBar::ParseReducedValue(DWORD Num)
{
	char Text[50];
	if (Num >= 10000000000)
		sprintf(Text, "%ldkkk", Num / 1000000000);
	else if (Num >= 10000000)
		sprintf(Text, "%ldkk", Num / 1000000);
	else if (Num >= 10000)
		sprintf(Text, "%ldk", Num / 1000);
	else
		sprintf(Text, "%ld", Num);

	return strdup(Text);
}

char* CHPBar::del_char(char* s, char c)
{
    char * buf = strchr(s, c);
    while( buf )
    {
        if(buf + 1)
            strcpy(buf, buf + 1);
        else
            buf[0] = '\0';
        buf = strchr(buf, c);
    }
    return s;
}