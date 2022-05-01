#pragma once

#define pSetPlayerStop						((int(__cdecl*)(lpViewObj lpObj)) 0x0054EA80)
#define SetCharacterScale		((int(__cdecl*)(int index)) 0x0057F020)
#define pGetClassModel			((char(__cdecl*)(BYTE))0x00587500)

class CWhiteBootsFix
{
public:
	// ----
	void	Load();
	// ----
}; extern CWhiteBootsFix gWhiteBootsFix;