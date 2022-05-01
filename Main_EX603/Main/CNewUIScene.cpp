#include "stdafx.h"
#include "CNewUIScene.h"
#include "Defines.h"
#include "TMemory.h"
#include "Util.h"
#include "Interface.h"
#include "zzzMathLib.h"
#include "Protect.h"

void LoginScreen(int a1, DWORD *a2){
	if (gProtect.m_MainInfo.CustomSelectServerX700 == 1){
		if ( World == 75) /*Select Server*/{
			SetFloat((PVOID)(0x005DB53F), -2.014084447E38);
			SetFloat((PVOID)(0x005DB55D), -2.70652875E38);
			*(float*)0xE61E3C = 33000.0;
			*(float*)0x87933D0 = -84.0;
			*(float*)0x87933D4 = 0.0;
			*(float*)0x87933D8 = -45.0;
			*(float*)0x87933DC = 24475.79687;
			*(float*)0x87933E0 = 7581.581055;
			*(float*)0x87933E4 = 1834.539917;	
			*(float*)0xE61E40 = 35.0;
		}
	}
}

void RenderSSCObjectVisual(int a1, int a2){
	vec3_t Bone;
	vec3_t Color;
	vec3_t WorldPos;
    /*Select Server*/
	if (gProtect.m_MainInfo.CustomSelectServerX700 == 1){
	    if (World == 75){  
		switch ( *(DWORD *)(a1 + 48) )   {
			case 1:{
				BeginRender(1.0);
				*(DWORD *)(a1 + 60) = -2;
				*(BYTE*)(a2 + 136) = 0;
				float v552 = 4000;
				float v551 = ((int) (v552 - timeGetTime() * 0.75f) % 4001) * 0.0002500000118743628;
				RenderMesh(a2,0,66,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),v551,-1);
				*(BYTE*)(a2 + 136) = -1;
				EndRender();
			}
			break;
			case 5:{
				BeginRender(1.0);
				*(BYTE*)(a2 + 136) = 0;
       	        *(float *)(a2 + 72) = 0.80000001;
       	        *(float *)(a2 + 76) = 0.69999999;
       		    *(float *)(a2 + 80) = 0.30000001;
				RenderMesh(a2,0,68,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),32042);
			    RenderMesh(a2,23,66,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),-1);
		    	RenderMesh(a2,23,68,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),32042);
			    RenderMesh(a2,24,66,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),-1);
		     	RenderMesh(a2,24,68,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),32042);
		    	RenderMesh(a2,25,66,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),-1);
			    RenderMesh(a2,25,68,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),32042);
			    RenderMesh(a2,26,66,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),-1);
 	    		RenderMesh(a2,26,68,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),32042);
		    	RenderMesh(a2,27,66,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),-1);
		        RenderMesh(a2,27,68,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),32042);
			    RenderMesh(a2,28,66,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),-1);
	    		RenderMesh(a2,28,68,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),32042);
			    *(BYTE*)(a2 + 136) = -1;
			    EndRender();
			    float v409 = (double)(rand() % 10) / 20.0 + 1.399999976158142;
			    float v19 = v409 - 0.300000011920929;
			    Vector( 0.0, 0.0, 0.0, WorldPos);
			    TransformPosition(a2, Joint(37), WorldPos, Bone, 0);
			    Vector( 1.0, 0.30000001, 0.0, Color);		
			    CreateSprite(32114, Bone, v409, Color, a1, 0.0, 0);
                CreateSprite(32114, Bone, v19, Color, a1, 0.0, 0);
			    v409 = (double)(rand() % 10) / 20.0 + 1.0;
			    float v20 = v409 + 0.300000011920929;
			    CreateSprite(32002, Bone, v20, Color, a1, 0.0, 0);
			    v409 = (double)(rand() % 8) / 20.0 + 0.4000000059604645;
			    CreateSprite(32114, Bone, v409, Color, a1, 0.0, 0);
			    float v21 = v409 - 0.2000000029802322;
                CreateSprite(32114, Bone, v21, Color, a1, 0.0, 0);
			}
			break;
			case 38:{
			    *(DWORD *)(a1 + 60) = -2;
			    if ( !(rand() % 6) )	{		
		    		Vector( 0.020, 0.020, 0.050, Color);			
			    	CreateParticle(32146, a1 + 252, a1 + 264, Color, 20,*(float *)(a1 + 96), a2);
				}
			}
			break;
			case 54:{
		    	*(DWORD *)(a1 + 60) = -2;
		    	if ( !(rand() % 2) )	{
	    			Vector( 0.22, 0.15000001, 0.15000001, Color);			
		    		CreateParticle(32287, a1 + 252, a1 + 264, Color, 2, *(float *)(a1 + 96), 0);
				}
			}
			break;
			}
		}
	}
	RenderCryingWolf2ndObjectVisual(a1, a2);
}

void LogoMUm(){
	if (SceneFlag == 2){
		glColor3f(1.0f, 1.0f, 1.0f);
		*(float*)0xE8CB18 = *(float*)0xE8CB18 + 0.01999999955296516;
		if (*(float*)0xE8CB18 > 10.0)
			*(float*)0xE8CB18 = 10.0;
		EnableAlphaBlend();
		float v25 = *(float*)0xE8CB18 - 0.300000011920929;
		float v24 = *(float*)0xE8CB18 - 0.300000011920929;
		float v23 = *(float*)0xE8CB18 - 0.300000011920929;
		float v22 = *(float*)0xE8CB18 - 0.300000011920929;
		glColor4f(v22, v23, v24, v25);
		RenderBitmap(531019, 217.60001, 25.0, 204.8, 102.4, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		EnableAlphaTest(1);
		glColor4f(*(float*)0xE8CB18, *(float*)0xE8CB18, *(float*)0xE8CB18, *(float*)0xE8CB18);
		RenderBitmap(531018, 217.60001, 25.0, 204.8, 102.4, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		glEnable(GL_TEXTURE_2D);
	}

}

void RenderInfomation(int a1){
	LogoMUm();
	RenderInfomationR();
}

void CScene(){
	MemorySet(0x005B993A,0x90,0x5);
	SetCompleteHook(0xE8, 0x005EDDA9,&RenderSSCObjectVisual);
	SetCompleteHook(0xE8, 0x004D7EB1, &RenderInfomation); //ok
	/*Select Server*/
	if (gProtect.m_MainInfo.CustomSelectServerX700 == 1){
		SetDword((LPVOID)0x004D75F0, 75);//Select Server
		SetCompleteHook(0xE8, 0x004D76FB, &LoginScreen);//Select Server
	    SetCompleteHook(0xE8, 0x004D79C3, &LoginScreen);//Select Server
		SetDword((PVOID)(0x004D7A0E), 480);//Select Server
	    SetByte((PVOID)(0x004D7A18), 0);//Select Server
	}
}