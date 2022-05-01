#pragma once

#define max_ceffect 3000

struct PET_EFFECT_CUSTOM
{
	int Index;
	int ItemIndex;
	int Join;
	int TypeEffect;
	int EffectCode;
	float EffectSize;
	int LargeRand;
	float ColorR;
	float ColorG;
	float ColorB;
};

class cCEffectPet
{
public:
	cCEffectPet();
	virtual ~cCEffectPet();
	void Init();
	void Load(char* path);
	void SetInfo(PET_EFFECT_CUSTOM info);

public:
	PET_EFFECT_CUSTOM m_PetCEffect [max_ceffect];

}; extern cCEffectPet gCustomCEffectPet;