#pragma once

namespace CNSL_E
{
	enum T
	{
		CONSOLE_RED = 1,

		CONSOLE_GREEN = 2,

		CONSOLE_BLUE = 3,

		CONSOLE_CYAN = 4,

		CONSOLE_YELLOW = 5,
	};
}

class CConsole
{
public:

	CConsole();

	~CConsole();

	void Load();

	int WriteMessage(char* szBuffer);

	bool CommandsStatus(char* szBuffer, char* szCmdName, int Size);

	bool WriteInFile(LPCTSTR szBuffer);

	void SetCommands(char* szBuffer);

	void AddMessage(int Color, const char* Format, ...);

	static void STDAPICALLTYPE SetSettings(PVOID lpVOID);

	DWORD PiD;

	HANDLE g_Handle(BOOL bImput);

}; extern CConsole gConsole;
