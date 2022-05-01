// SkillDamage.h: interface for the CSkillDamage class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

struct SKILL_DAMAGE_INFO
{
	int Index;
	int DamageRate;
};

class CSkillDamage
{
public:
	CSkillDamage();
	virtual ~CSkillDamage();
	void Load(char* path);
	int GetDamage(int SkillNumber);
private:
	std::map<int, SKILL_DAMAGE_INFO> m_SkillDamageInfo;
};

extern CSkillDamage gSkillDamage;