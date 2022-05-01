#include "StdAfx.h"
#include "ChatExpanded.h"
#include "Import.h"
#include "TMemory.h"
#include <atlstr.h>
#include "ToolKit.h"
#include "Defines.h"
#include "Object.h"
#include "Common.h"
#include "LuaExport.h"
// ----------------------------------------------------------------------------------------------

ChatExpanded	gChatExpanded;
// ----------------------------------------------------------------------------------------------

Naked(FixSysMsg1)
{
	__asm
	{
		cmp dword ptr ss:[ebp+0x10], 3
		je _true
		call NewCall
		jmp FixSysMsg1_FALSE
		_true:
		pop eax
		jmp FixSysMsg1_TRUE
	}
}
// ----------------------------------------------------------------------------------------------

Naked(FixSysMsg2)
{
	__asm 
	{
		cmp dword ptr ss:[ebp+0x10], 3
		je _true
		call NewCall
		jmp FixSysMsg2_FALSE
		_true:
		pop eax
		jmp FixSysMsg2_TRUE
	}
}
// ----------------------------------------

Naked(FixSysMsg3)
{
	__asm 
	{
		cmp dword ptr ss:[ebp+0x10], 3
		je _true
		call NewCall
		jmp FixSysMsg3_FALSE
		_true:
		pop eax
		jmp FixSysMsg3_TRUE
	}
}
// -----------------------------------------
std::string s;
std::string _TextT;
size_t pos;

__declspec(naked) void ChangeSystemColor()
{
	static DWORD ret = 0x007890F2;
	static DWORD addr0 = 0x0078C030;
	static DWORD addr1 = 0x00402880;

	static DWORD text;
	static DWORD X;
	static DWORD Y;

	__asm
	{
		MOV ECX, DWORD PTR SS : [EBP - 0x2C]
			CALL addr0
			MOV ECX, EAX
			CALL addr1
			MOV text, EAX
			MOV ECX, DWORD PTR SS : [EBP - 0x34]
			MOV Y, ECX
			MOV EDX, DWORD PTR SS : [EBP - 0x38]
			MOV X, EDX
	}

	pDrawText(pTextThis(), (int)X, (int)Y, /*s.c_str()*/(char*)text, 0, 0, (LPINT)1, 0);
	s.clear();
	__asm
	{
		jmp ret
	}
}

__declspec(naked) void SetChatTextType()
{
	static DWORD ret = 0x00788F29;
	static int textType;

	__asm
	{
		mov textType, EAX
	}

	gChatExpanded.m_Lua.Generic_Call("MakeText", "i", textType);

	__asm
	{
		JMP ret;
	}
}

#define sub_7865E0_Addr		((int(__thiscall*)(int This)) 0x7865E0)

char sub_7865E0(int This, LPVOID EDX)
{
	//, LPVOID EDX
	return sub_7865E0_Addr(This);
}

bool __fastcall ChatDrawTextHook(void* This, /*void *_EDX,*/ int PosX, int PosY, LPCTSTR Text, int nCount, int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin, DWORD* ChatData);

bool __fastcall ChatDrawTextHook(void* This, /*void *_EDX,*/ int PosX, int PosY, LPCTSTR Text, int nCount, int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin, DWORD* ChatData)
{
	std::string post = "[POST]";
	std::string s = Text;
	pos = s.find(post);
	if (pos != std::string::npos || ChatData[14] == 10)
	{
		gChatExpanded.m_Lua.Generic_Call("MakeText", "i", 10);
		pDrawText(This, PosX, PosY, Text, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin);
		return 1;
	}

	int len = strlen(Text);

	if (Text[len - 27] == '_' &&
		Text[len - 26] == '[' &&
		Text[len - 1] == ']')
	{
		gChatExpanded.m_Lua.Generic_Call("MakeText", "i", 12);
		char newText[256] = { '\0' };
		memcpy(newText, Text, len - 27);
		pDrawText(This, PosX, PosY, newText, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin);
	}
	else
	{
		pDrawText(This, PosX, PosY, Text, nCount, nTabPositions, lpnTabStopPositions, nTabOrigin);
	}
	return 0;
}

__declspec(naked) void LoadFont()
{
	static int cHeight = *(DWORD*)MAIN_FONT_SIZE - 1;
	pFontNormal = (HGDIOBJ)CreateFontA(cHeight, 0, 0, 0, 400, 0, 0, 0, 0x01, 0, 0, 3, 0, "Comic Sans MS");
	pFontBold = (HGDIOBJ)CreateFontA(cHeight, 0, 0, 0, 400, 0, 0, 0, 0x01, 0, 0, 3, 0, "Comic Sans MS");
	pFontBigBold = (HGDIOBJ)CreateFontA(cHeight, 0, 0, 0, 400, 0, 0, 0, 0x01, 0, 0, 3, 0, "Comic Sans MS");
	pFontNormal2 = (HGDIOBJ)CreateFontA(cHeight, 0, 0, 0, 400, 0, 0, 0, 0x01, 0, 0, 3, 0, "Comic Sans MS");
	DWORD buff1, buff2, buff3, buff4;
	gChatExpanded.m_Lua.Generic_Call("MakeSetFont", "ii>i", 1, cHeight, &buff1);
	pFontNormal = (HGDIOBJ)buff1;
	gChatExpanded.m_Lua.Generic_Call("MakeSetFont", "ii>i", 2, cHeight, &buff2);
	pFontBold = (HGDIOBJ)buff2;
	gChatExpanded.m_Lua.Generic_Call("MakeSetFont", "ii>i", 3, cHeight, &buff3);
	pFontBigBold = (HGDIOBJ)buff3;
	gChatExpanded.m_Lua.Generic_Call("MakeSetFont", "ii>i", 4, cHeight, &buff4);
	pFontNormal2 = (HGDIOBJ)buff4;
	static DWORD ret = 0x004D29C7;
	__asm
	{
		jmp ret
	}
}

void ChatExpanded::Load()
{
	this->isFirstLoad = true;
	this->m_Lua.DoFile("Data\\Custom\\Scripts\\ChatWindow.lua");
	this->m_Lua.DoFile("Data\\Custom\\Scripts\\Fonts.lua");

	//LOAD FONTS
	SetRange(0x004D285A, 0x2E, ASM::NOP);
	SetRange(0x004D28C4, 0x2D, ASM::NOP);
	SetRange(0x004D292D, 0x30, ASM::NOP);
	SetRange(0x004D2999, 0x2E, ASM::NOP);
	SetCompleteHook(0xE9, 0x004D2999, &LoadFont);

	MemorySet(0x007890C6, 0x90, 0x2C);
	SetCompleteHook(0xE9, 0x007890C6, &ChangeSystemColor);

	MemorySet(0x00788C66, 0x90, 0x33);
	SetCompleteHook(0xE9, 0x00788C66, &SetChatTextType);

	MemorySet(0x00788CAC, 0x90, 0x33);
	SetCompleteHook(0xE9, 0x00788CAC, &SetChatTextType);

	MemorySet(0x00788CF2, 0x90, 0x30);
	SetCompleteHook(0xE9, 0x00788CF2, &SetChatTextType);

	MemorySet(0x00788D35, 0x90, 0x36);
	SetCompleteHook(0xE9, 0x00788D35, &SetChatTextType);

	MemorySet(0x00788D7E, 0x90, 0x33);
	SetCompleteHook(0xE9, 0x00788D7E, &SetChatTextType);

	MemorySet(0x00788DC4, 0x90, 0x33);
	SetCompleteHook(0xE9, 0x00788DC4, &SetChatTextType);

	MemorySet(0x00788E0A, 0x90, 0x33);
	SetCompleteHook(0xE9, 0x00788E0A, &SetChatTextType);

	MemorySet(0x00788E50, 0x90, 0x33);
	SetCompleteHook(0xE9, 0x00788E50, &SetChatTextType);

	MemorySet(0x00788E96, 0x90, 0x46);
	SetCompleteHook(0xE9, 0x00788E96, &SetChatTextType);

	MemorySet(0x00788EEC, 0x90, 0x36);
	SetCompleteHook(0xE9, 0x00788EEC, &SetChatTextType);

	SetOp((LPVOID)oShowChatMessage_Call, (LPVOID)this->ShowChatMessage, ASM::CALL);
	SetOp((LPVOID)FixSysMsg1_Hook, FixSysMsg1, ASM::JMP);
	SetOp((LPVOID)FixSysMsg2_Hook, FixSysMsg2, ASM::JMP);
	SetOp((LPVOID)FixSysMsg3_Hook, FixSysMsg3, ASM::JMP);
}
// -----------------------------------------

void ChatExpanded::SetInstance(LPVOID Instance)
{
	this->Instance			= Instance;
	this->PosYBuff			= this->GetPosY();
	this->HeightBuff		= this->GetHeight();
	this->MessageCountBuff	= this->GetMessageCount();
	this->MessageTypeBuff	= this->GetMessageType();
	this->ScrollPosBuff		= this->GetScrollPos();
}
// ------------------------------------------

void ChatExpanded::Restore()
{
	this->SetPosY(this->PosYBuff);
	this->SetHeight(this->HeightBuff);
	this->SetMessageCount(this->MessageCountBuff);
	this->SetMessageType(this->MessageTypeBuff);
	this->SetScrollPos(this->ScrollPosBuff);
}
// -----------------------------------------

void ChatExpanded::Switch()
{
	if( gChatExpanded.m_separate == 0 )
	{
		SetOp((LPVOID)oShowChatMessage_Call, (LPVOID)this->ShowChatMessage, ASM::CALL);
		SetOp((LPVOID)FixSysMsg1_Hook, FixSysMsg1, ASM::JMP);
		SetOp((LPVOID)FixSysMsg2_Hook, FixSysMsg2, ASM::JMP);
		SetOp((LPVOID)FixSysMsg3_Hook, FixSysMsg3, ASM::JMP);
		gChatExpanded.m_separate = 1;
	}
	else
	{
		SetOp((LPVOID)FixSysMsg1_Hook, (LPVOID)oNewCall, ASM::CALL);
		SetOp((LPVOID)FixSysMsg2_Hook, (LPVOID)oNewCall, ASM::CALL);
		SetOp((LPVOID)FixSysMsg3_Hook, (LPVOID)oNewCall, ASM::CALL);
		gChatExpanded.m_separate = 0;
	}
}
// ----------------------------------------

bool ChatExpanded::ShowChatMessage(LPVOID This, LPVOID EDX)
{
	if(gChatExpanded.m_separate == 0)
	{
		return pShowChatMessage(This);
	}
	// ----
	gChatExpanded.SetInstance(This);
	gChatExpanded.SetPosY(172);
	gChatExpanded.SetHeight(100);
	gChatExpanded.SetMessageCount(4);
	pSetChatMessageType(This, 3);
	pShowChatMessage(This);
	gChatExpanded.Restore();
	return pShowChatMessage(This);
}
// ----------------------------------------