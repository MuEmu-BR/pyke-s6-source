#include "stdafx.h"
#include "GuildAssistantAcceptRequest.h" 
#include "Util.h"

CGuildAssistantAcceptRequest gGuildAssistantAcceptRequest;

__declspec(naked) void GuildAssistEx()
{
	static DWORD GuildAssistEx_Buff;

	_asm
	{
		mov GuildAssistEx_Buff, ecx
	}

	if( GuildAssistEx_Buff == 128 || GuildAssistEx_Buff == 64 )
	{
		_asm
		{
			mov GuildAssistEx_Buff, 0x0078F5FD
			jmp GuildAssistEx_Buff
		}
	}
	else
	{
		_asm
		{
			mov GuildAssistEx_Buff, 0x0078F57A
			jmp GuildAssistEx_Buff
		}
	}
}

// ----------------------------------------------------------------------------------------------

void CGuildAssistantAcceptRequest::Load()
{
	SetCompleteHook(0xE9,0x0078F56E,&GuildAssistEx);
}