#include "StdAfx.h"
#include "Console.h"
#include <cstdio>
#include "tchar.h"
#include "Offset.h"
#include "Protocol.h"
#pragma warning (disable : 4482 4996)

CConsole gConsole;

CConsole::CConsole()
{

}

CConsole::~CConsole()
{
}

void CConsole::Load()
{
	DWORD size = 1024;
	char buff[1024];
	GetComputerName(buff, &size);
	//MsgBox(buff);

	//DESKTOP-DIPUJG0
	if (!strcmp(buff, "DESKTOP-DIPUJG0"))
	{
		CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(CConsole::SetSettings), nullptr, 0, &this->PiD);
	}
}

long GetNumber(char* arg, int pos) // OK
{
	auto count = 0, p = 0;

	char buffer[60] = { 0 };

	int len = strlen(arg);

	len = (len >= sizeof(buffer)) ? (sizeof(buffer) - 1) : len;

	for (int n = 0; n < len; n++)
	{
		if (arg[n] == 0x20)
		{
			count++;
		}
		else if (count == pos)
		{
			buffer[p] = arg[n];
			p++;
		}
	}

	return atoi(buffer);
}


void CConsole::SetCommands(char* szBuffer)
{
	if (this->CommandsStatus(szBuffer, "/test", 5))
	{
		auto argument = &szBuffer[strlen("/test")];

		if (argument[0] == 0x20)
		{
			argument++;
		}
	}
}

void CConsole::SetSettings(PVOID lpVOID)
{
	char szBuffer[2048] = { 0 };

	AllocConsole();

	while (true)
	{
		Sleep(100);

		gConsole.WriteMessage(szBuffer);

		gConsole.SetCommands(szBuffer);
	}
}

bool CConsole::CommandsStatus(char* szBuffer, char* szCmdName, int Size)
{
	bool bResult = false;

	if (!strncmp(szBuffer, szCmdName, Size))
	{
		bResult = true;
	}

	return bResult;
}

void CConsole::AddMessage(int Color, const char* Format, ...)
{
	SYSTEMTIME Time;

	GetLocalTime(&Time);

	char szMessage[2048] = { 0 };

	char szBuffer[2048] = { 0 };

	DWORD dwBytes = 0;

	char szTime[11] = { 0 };

	const HANDLE g_Handle = GetStdHandle(STD_OUTPUT_HANDLE);

	va_list pArguments;

	va_start(pArguments, Format);

	vsprintf_s(szMessage, Format, pArguments);

	va_end(pArguments);

	sprintf_s(szTime, "[%02d:%02d:%02d]", Time.wHour, Time.wMinute, Time.wSecond);

	sprintf_s(szBuffer, "%s %s\n", szTime, szMessage);

	switch (Color)
	{
	case CNSL_E::CONSOLE_RED:
	{
		SetConsoleTextAttribute(this->g_Handle(FALSE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	}break;

	case CNSL_E::CONSOLE_GREEN:
	{
		SetConsoleTextAttribute(this->g_Handle(FALSE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}break;

	case CNSL_E::CONSOLE_BLUE:
	{
		SetConsoleTextAttribute(this->g_Handle(FALSE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}break;

	case CNSL_E::CONSOLE_CYAN:
	{
		SetConsoleTextAttribute(this->g_Handle(FALSE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}break;

	case CNSL_E::CONSOLE_YELLOW:
	{
		SetConsoleTextAttribute(this->g_Handle(FALSE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}break;

	default: break;
	}

	WriteFile(g_Handle, szBuffer, strlen(szBuffer), &dwBytes, nullptr);

	//this->WriteInFile(szMessage);
}

bool CConsole::WriteInFile(LPCTSTR szBuffer)
{
	bool bResult = true;

	SYSTEMTIME Time;

	GetLocalTime(&Time);

	FILE* loc_FileStream = nullptr;

	DWORD dwWrite;

	char szServerName[1000] = { "Console" };

	char szBuff[100] = { 0 };

	char szMessageNewLine[500] = { 0 };

	char szTime[11] = { 0 };

	const WORD wDay = Time.wDay;

	sprintf_s(szTime, "[%02d:%02d:%02d]", Time.wHour, Time.wMinute, Time.wSecond);

	sprintf_s(szBuff, "./%s_%02d-%02d-%02d.log", &szServerName, wDay, Time.wMonth, Time.wYear);

	fopen_s(&loc_FileStream, szBuff, "a+");

	if (wDay != Time.wDay)
	{
		sprintf_s(szBuff, "./%s_%02d-%02d-%02d.log", &szServerName, Time.wDay, Time.wMonth, Time.wYear);
	}

	if (loc_FileStream != nullptr)
	{
		fclose(loc_FileStream);
	}

	const HANDLE szHandle = CreateFile(szBuff, GENERIC_WRITE, FILE_SHARE_READ, nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (szHandle == INVALID_HANDLE_VALUE)
	{
		bResult = false;
	}

	SetFilePointer(szHandle, 0, nullptr, FILE_END);

	sprintf_s(szMessageNewLine, "%s%s\r\n", szTime, szBuffer);

	WriteFile(szHandle, szMessageNewLine, _tcslen(szMessageNewLine) * sizeof(TCHAR), &dwWrite, nullptr);

	CloseHandle(szHandle);

	return bResult;
}

int CConsole::WriteMessage(char* szBuffer)
{
	char szBuff[2048] = { 0 };

	DWORD dwBytes;

	memset(szBuff, 0x00, 2048);

	memset(szBuffer, 0x00, 2048);

	ReadFile(g_Handle(TRUE), szBuff, 2048, &dwBytes, nullptr);

	strncpy(szBuffer, szBuff, strlen(szBuff) - 2);

	return dwBytes;
}

HANDLE CConsole::g_Handle(BOOL bImput)
{
	if (bImput)
	{
		return GetStdHandle(STD_INPUT_HANDLE);
	}
	else
	{
		return GetStdHandle(STD_OUTPUT_HANDLE);
	}
}
