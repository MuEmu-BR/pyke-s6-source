#include "stdafx.h"
#include "ServerInfo.h"
#include "Common.h"
#include "CustomFog.h"
#include "ChatExpanded.h"
#include "JCEntryproy.h"

ServerInfo gServerInfo;

ServerInfo::~ServerInfo()
{
}


void ServerInfo::Load()
{
	
}

void ServerInfo::SetSettingsInfo(int index)
{
	if (index == 0)
	{
		gChatExpanded.m_separate ^= 1;
	}
	else if (index == 1)
	{
		Fog ^= 1;
	}
	else if (index == 2)
	{
		HpMonsterBar ^= 1;
	}
	else if (index == 3)
	{
		TimerBar ^= 1;
	}
	else if (index == 4)
	{
		MiniMap ^= 1;
	}
	else if (index == 5)
	{
		DisableGlowEffect ^= 1;
	}
	else if (index == 6)
	{
		DisableShadow ^= 1;
	}
}

int ServerInfo::GetSettingsInfo(int index)
{
	if (index == 0)
	{
		return gChatExpanded.m_separate;
	}
	else if (index == 1)
	{
		return Fog;
	}
	else if (index == 2)
	{
		return HpMonsterBar;
	}
	else if (index == 3)
	{
		return TimerBar;
	}
	else if (index == 4)
	{
		return MiniMap;
	}
	else if (index == 5)
	{
		return DisableGlowEffect;
	}
	else if (index == 6)
	{
		return DisableShadow;
	}
}
