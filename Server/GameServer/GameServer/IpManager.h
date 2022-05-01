// IpManager.h: interface for the CIpManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

struct IP_ADDRESS_INFO
{
	char IpAddress[16];
	WORD IpAddressCount;
	//antiflood
	WORD IpFloodAttemps;
	WORD IpBlocked;
	DWORD IpBlockedTime;
	DWORD IpTick;
	DWORD IpFloodLastTime;
	WORD IpRealUser;
};

struct IP_ADDRESS_BLOCK
{
	char IpAddress[16];
};

class CIpManager
{
public:
	CIpManager();
	virtual ~CIpManager();
	bool CheckIpAddress(char* IpAddress);
	void InsertIpAddress(char* IpAddress);
	void RemoveIpAddress(char* IpAddress);
	//antiflood
	void InsertRealUser(char* IpAddress);
	std::map<std::string,IP_ADDRESS_INFO> m_IpAddressInfo;
private:
};

extern CIpManager gIpManager;
