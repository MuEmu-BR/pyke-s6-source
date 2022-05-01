#pragma once



struct CUSTOM_PET_INFO
{
	int Index;
	int ItemIndex;
	int IndexInventory;
	int PetType;
	char ModelName[50];
	int FenrrirEffect;
	float Scale_Inve;
	float Scale_Drop;
	float Scale_View;
};

class cCustomPet
{
public:
	cCustomPet();
	virtual ~cCustomPet();
	void Init();
	void Load(char* path);
	void SetInfo(CUSTOM_PET_INFO info);
public:
	CUSTOM_PET_INFO m_CustomPetInfo[MAX_PET_ITEM];
};

extern cCustomPet gCustomPet2;
