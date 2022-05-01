#include "stdafx.h"
#include "WhiteBootsFix.h" 
#include "Util.h"
#include "Object.h"

CWhiteBootsFix gWhiteBootsFix;


int PreviewCharSetChangeUp(lpViewObj lpObj)
{
	int result = (int)lpObj;

	if (lpObj->m_Model.SkinID == 1163)
	{
		int Stop = 1;

		if (lpObj->m_Model.AnimationID >= 233 && lpObj->m_Model.AnimationID <= 240)
			Stop = 0;

		if (lpObj->m_Model.AnimationID >= 38 && lpObj->m_Model.AnimationID <= 155)
			Stop = 0;

		if (Stop)
			pSetPlayerStop(lpObj);

		int ClassModel = pGetClassModel(lpObj->ClassCode);

		if (lpObj->HelmSlot >= 9389)
		{
			lpObj->HelmSlot = ClassModel + 9389;
			lpObj->HelmLevel = 0;
			lpObj->HelmExcellent = 0;
			lpObj->HelmAncient = 0;

		}
		if (lpObj->ArmorSlot >= 9413)
		{
			lpObj->ArmorSlot = ClassModel + 9413;
			lpObj->ArmorLevel = 0;
			lpObj->ArmorExcellent = 0;
			lpObj->ArmorAncient = 0;
		}
		if (lpObj->PantsSlot >= 9437)
		{
			lpObj->PantsSlot = ClassModel + 9437;
			lpObj->PantsLevel = 0;
			lpObj->PantsExcellent = 0;
			lpObj->PantsAncient = 0;
		}
		if (lpObj->GlovesSlot >= 9461)
		{
			lpObj->GlovesSlot = ClassModel + 9461;
			lpObj->GlovesLevel = 0;
			lpObj->GlovesExcellent = 0;
			lpObj->GlovesAncient = 0;
		}
		if (lpObj->BootsSlot >= 9485)
		{
			lpObj->BootsSlot = ClassModel + 9485;
			lpObj->BootsLevel = 0;
			lpObj->BootsExcellent = 0;
			lpObj->BootsAncient = 0;
		}
		result = SetCharacterScale((int)lpObj);
	}
	return result;
}

// ----------------------------------------------------------------------------------------------

void CWhiteBootsFix::Load()
{
	SetCompleteHook(0xE9, 0x57F920, &PreviewCharSetChangeUp);
}