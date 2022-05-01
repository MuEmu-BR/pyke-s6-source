#pragma once

struct ZEN_DROP
{
	BYTE MapNumber;
	DWORD MinMoney;
	DWORD MaxMoney;
};

class CZenDrop
{
public:
	CZenDrop();
	virtual ~CZenDrop();
	void Load(char* path);
	bool IsZenDropActive(BYTE Map);
	DWORD GetZenAmount(BYTE MapNumber, WORD MonsterLevel);
	// ----
	bool m_ZenDropEnable;
	bool m_MultiplyZenDropByMonLevel;
	DWORD m_MultiplyZenChanceRate;
	std::map<int, ZEN_DROP> m_ZenDrop;
}; extern CZenDrop gZenDrop;