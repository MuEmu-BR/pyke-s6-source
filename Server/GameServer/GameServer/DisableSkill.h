#pragma once

#include "User.h"

struct CUSTOM_DISABLE_SKILL
{
	int SkillNumber;
	int General;
	int Guild;
	int Duel;
	int Player;
	int Map;
};

class CCustomDisableSkill
{
public:
	CCustomDisableSkill();
	virtual~CCustomDisableSkill();
	void Load(char* path);
	bool GetSkillDisableGeneral(int Skill);
	bool GetSkillDisableGuild(int Skill);
	bool GetSkillDisableDuel(int Skill);
	bool GetSkillDisablePlayer(int Skill);
	bool GetSkillDisableMap(LPOBJ lpObj, int Skill);
private:
	std::vector<CUSTOM_DISABLE_SKILL>m_DisableSkillInfo;

};
extern CCustomDisableSkill gCustomDisableSkill;