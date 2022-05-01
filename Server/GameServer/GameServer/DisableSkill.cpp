#include "stdafx.h"
#include "DisableSkill.h"
#include "MemScript.h"
#include "Util.h"

CCustomDisableSkill gCustomDisableSkill;

CCustomDisableSkill::CCustomDisableSkill()
{
	this->m_DisableSkillInfo.clear();
}

CCustomDisableSkill::~CCustomDisableSkill()
{
}

void CCustomDisableSkill::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR, path);
		return;
	}

	if (lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->m_DisableSkillInfo.clear();

	try
	{
		while (true)
		{

			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if (strcmp("end", lpMemScript->GetString()) == 0)
			{
				break;
			}

			CUSTOM_DISABLE_SKILL info;

			info.SkillNumber = lpMemScript->GetNumber();

			info.General = lpMemScript->GetAsNumber();

			info.Guild = lpMemScript->GetAsNumber();

			info.Duel = lpMemScript->GetAsNumber();

			info.Player = lpMemScript->GetAsNumber();

			info.Map = lpMemScript->GetAsNumber();

			this->m_DisableSkillInfo.push_back(info);

		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

bool CCustomDisableSkill::GetSkillDisableGeneral(int Skill)
{
	for (std::vector<CUSTOM_DISABLE_SKILL>::iterator it = this->m_DisableSkillInfo.begin(); it != this->m_DisableSkillInfo.end(); it++)
	{
		if (it->SkillNumber == Skill)
		{
			if(it->General == 1)
			{
				return true;
			}
		}
	}
	return false;
}
bool CCustomDisableSkill::GetSkillDisableGuild(int Skill)
{
	for (std::vector<CUSTOM_DISABLE_SKILL>::iterator it = this->m_DisableSkillInfo.begin(); it != this->m_DisableSkillInfo.end(); it++)
	{
		if (it->SkillNumber == Skill)
		{
			if (it->Guild == 1)
			{
				return true;
			}
		}
	}
	return false;
}
bool CCustomDisableSkill::GetSkillDisableDuel(int Skill)
{
	for (std::vector<CUSTOM_DISABLE_SKILL>::iterator it = this->m_DisableSkillInfo.begin(); it != this->m_DisableSkillInfo.end(); it++)
	{
		if (it->SkillNumber == Skill)
		{
			if (it->Duel == 1)
			{
				return true;
			}
		}
	}
	return false;
}

bool CCustomDisableSkill::GetSkillDisablePlayer(int Skill)
{
	for (std::vector<CUSTOM_DISABLE_SKILL>::iterator it = this->m_DisableSkillInfo.begin(); it != this->m_DisableSkillInfo.end(); it++)
	{
		if (it->SkillNumber == Skill)
		{
			if (it->Player == 1)
			{
				return true;
			}
		}
	}
	return false;
}

bool CCustomDisableSkill::GetSkillDisableMap(LPOBJ lpObj, int Skill)
{
	for (std::vector<CUSTOM_DISABLE_SKILL>::iterator it = this->m_DisableSkillInfo.begin(); it != this->m_DisableSkillInfo.end(); it++)
	{
		if (it->SkillNumber == Skill)
		{
			if (it->Map != lpObj->Map)
			{
				return true;
			}
		}
	}
	return false;
}