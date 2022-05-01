#include "stdafx.h"
#include "Util.h"
#include "WeatherFix.h"

CWeatherFix gWeatherFix;

__declspec(naked) void WeatherFix()
{
	static DWORD JmpBack = 0x0062F6CA;

	_asm
	{
		Cmp Dword Ptr Ds : [0x00E61E18], 0;
		Je EXIT;
		Cmp Dword Ptr Ds : [0x00E61E18], 3;
		Je EXIT;
		Push Dword Ptr[0x00D3D5E4];
		Jmp JmpBack;
	EXIT:
		Push Dword Ptr[0x00D3D5D4];
		Jmp JmpBack;
	}
}

// ----------------------------------------------------------------------------------------------

void CWeatherFix::Load()
{
	SetCompleteHook(0xE9, 0x0062F6C5, &WeatherFix);
}