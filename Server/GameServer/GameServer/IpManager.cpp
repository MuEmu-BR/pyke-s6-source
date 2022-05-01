// IpManager.cpp: implementation of the CIpManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IpManager.h"
#include "ServerInfo.h"
#include "Log.h"
#include "Util.h"

CIpManager gIpManager;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIpManager::CIpManager() // OK
{

}

CIpManager::~CIpManager() // OK
{

}
//antiflood - replace entire ipmanager.cpp and ipmanager.h
bool CIpManager::CheckIpAddress(char* IpAddress) // OK
{
	std::map<std::string,IP_ADDRESS_INFO>::iterator it = this->m_IpAddressInfo.find(std::string(IpAddress));
	
	if(it == this->m_IpAddressInfo.end())
	{
		return ((gServerInfo.m_MaxIpConnection==0)?0:1);
	}	

	if(it->second.IpBlocked > 0)
	{
		if(it->second.IpRealUser == 1 || GetTickCount()-it->second.IpBlockedTime > gServerInfo.m_IpConnectionBlockedTime)
		{
			//check banned time or real user and unban the ip.
			gLog.Output(LOG_HACK,"IP IS UNBAN: %s", IpAddress);
			LogAdd(LOG_RED,"IP IS UNBAN: %s", IpAddress);
			it->second.IpBlocked = 0;
			it->second.IpBlockedTime = 0;
		}
		else
		{
			return 0;
		}
	}

	if(it->second.IpRealUser == 0 && it->second.IpTick != 0 && GetTickCount()-it->second.IpTick < 1000)
	{
		it->second.IpBlocked = 1;
		it->second.IpBlockedTime = GetTickCount();
		gLog.Output(LOG_HACK,"FLOOD ATTEMPT DETECTED - BAN IP: %s", IpAddress);
		LogAdd(LOG_RED,"FLOOD ATTEMPT DETECTED - BAN IP: %s", IpAddress);
		return 0;
	}

	it->second.IpTick = GetTickCount();

	if(it->second.IpAddressCount>=gServerInfo.m_MaxIpConnection)
	{
		if(it->second.IpRealUser == 0)
		{
			it->second.IpBlocked = 1;
			it->second.IpBlockedTime = GetTickCount();
			gLog.Output(LOG_HACK,"FLOOD ATTEMPT DETECTED - BAN IP: %s", IpAddress);
			LogAdd(LOG_RED,"FLOOD ATTEMPT DETECTED - BAN IP: %s", IpAddress);
		}
		return 0;
	}
	return 1;
}

void CIpManager::InsertIpAddress(char* IpAddress) // OK
{
	IP_ADDRESS_INFO info;

	strcpy_s(info.IpAddress,IpAddress);

	info.IpAddressCount = 1;
	info.IpTick = GetTickCount();
	info.IpBlocked = 0;
	info.IpBlockedTime = 0;
	info.IpRealUser = 0;

	std::map<std::string,IP_ADDRESS_INFO>::iterator it = this->m_IpAddressInfo.find(std::string(IpAddress));

	if(it == this->m_IpAddressInfo.end())
	{
		this->m_IpAddressInfo.insert(std::pair<std::string,IP_ADDRESS_INFO>(std::string(IpAddress),info));
	}
	else
	{
		it->second.IpAddressCount++;
	}
}

void CIpManager::RemoveIpAddress(char* IpAddress) // OK
{
	std::map<std::string,IP_ADDRESS_INFO>::iterator it = this->m_IpAddressInfo.find(std::string(IpAddress));

	if(it != this->m_IpAddressInfo.end())
	{
		if(it->second.IpBlocked == 0 && (--it->second.IpAddressCount) == 0)
		{
			this->m_IpAddressInfo.erase(it);
		}
	}
}

void CIpManager::InsertRealUser(char* IpAddress) // OK
{
	std::map<std::string,IP_ADDRESS_INFO>::iterator it = this->m_IpAddressInfo.find(std::string(IpAddress));

	if(it != this->m_IpAddressInfo.end())
	{
		if(it->second.IpRealUser == 0)
		{
			it->second.IpRealUser = 1;
		}
	}
}
