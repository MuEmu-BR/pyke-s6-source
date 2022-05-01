#pragma once

struct REMAKE_EFFECT
{
	int Index;
	int ItemType;
	int ItemIndex;
	int RemakeEffect;
};

class cCustomRemake
{
public:
	cCustomRemake();
	virtual ~cCustomRemake();
	void Init();
	void Load(char* path);
	void SetInfo(REMAKE_EFFECT info);
public:
	REMAKE_EFFECT m_CustomRemake[MAX_REMAKE_EFFECT];
}; extern cCustomRemake gCustomRemake;