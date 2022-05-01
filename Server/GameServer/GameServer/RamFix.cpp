#include "stdafx.h"
#include "Protect.h"
#include "RamFix.h"

void RamFix()
{
	HANDLE v1;
	HANDLE v2;
	while ( 1 )
	{
		Sleep(5000);
		v1 = GetCurrentProcess();
		SetProcessWorkingSetSize(v1, 0xFFFFFFFF, 0xFFFFFFFF);
		v2 = GetCurrentProcess();
		SetThreadPriority(v2, -2);
	}
}