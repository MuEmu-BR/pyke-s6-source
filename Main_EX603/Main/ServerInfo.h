#pragma once


class ServerInfo
{
public:
	~ServerInfo();
	void Load();
	void SetSettingsInfo(int index);
	int GetSettingsInfo(int index);
private:
	HANDLE hThread;
}; extern ServerInfo gServerInfo;