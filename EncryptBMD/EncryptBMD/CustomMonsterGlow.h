#pragma once

#define MAX_CUSTOM_MONSTERGLOW 100

struct CUSTOM_MONSTERGLOW_INFO
{
	int Index;
	int MonsterID;
	int EffectIndex;
	int EffectType;
	float ColorR;
	float ColorG;
	float ColorB;
};

struct CUSTOM_GLOW_INFO
{
	int Index;
	int MonsterID;
	int Golden;
	int brightness;
};

class cCustomGlow
{
public:
	cCustomGlow();
	virtual ~cCustomGlow();
	void Init();
	void Load(char* path);
	void SetInfo1(CUSTOM_GLOW_INFO info);
	void SetInfo2(CUSTOM_MONSTERGLOW_INFO info);
public:
	CUSTOM_MONSTERGLOW_INFO m_CustomGlowInfo[MAX_CUSTOM_MONSTERGLOW];
	CUSTOM_GLOW_INFO m_CustombrightnessInfo[MAX_CUSTOM_MONSTERGLOW];
};

extern cCustomGlow gCustomMonsterGlow;