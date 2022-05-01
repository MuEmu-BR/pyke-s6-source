#include "stdafx.h"
#include "Font.h"
#include "zzzmathlib.h"
#include "import.h"
#include "Pet.h"

CFont* gFont[100];
cColor *Fcolor = new cColor;

CFont::CFont(TCHAR* Name, int Size, int Weight, BOOL bItalic, BOOL bUnderline)
{
	this->m_Font = CreateFontA(Size, 0, 0, 0, Weight, bItalic, bUnderline, FALSE,
		0xFDE9, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS,
		NONANTIALIASED_QUALITY, FF_DONTCARE | DEFAULT_PITCH,
		Name);
}

cColor::cColor()
{
	Vector4(0xAC, 0xFF, 0x38, 0xFF, this->ShinyGreen);
	Vector4(0xFF, 0xBD, 0x19, 0xFF, this->Gold);
	Vector4(0xFF, 0xFF, 0xFF, 0xFF, this->White);
	Vector4(0xFF, 0x69, 0x19, 0xFF, this->Orange);
	Vector4(0xFF, 0, 0, 0x80, this->Red50);
	Vector4(0, 0, 0, 0, this->Trans);
	Vector4(0, 0, 0, 0x32, this->Trans25);
	Vector4(0xFF, 0, 0, 0xFF, this->Red);
	Vector4(0, 0xFF, 0, 0xFF, this->Green);
	Vector4(0, 0, 0xFF, 0xFF, this->Blue);
	Vector4(50, 50, 50, 150, this->Black);
}

cColor::~cColor()
{
	return;
}

CFont::~CFont()
{
	DeleteObject(this->m_Font);
}

int CFont::SetFont()
{
	return pSetTextSize(pTextThis(), this->MAKE);
}

void InitFonts()
{
	char FontName[] = "Arial";
	const int BaseFontSize = 0;
	gFont[ARIAL_8] = new CFont(FontName, BaseFontSize + 8, FW_NORMAL, FALSE, FALSE);
	gFont[ARIAL_12] = new CFont(FontName, BaseFontSize + 12, FW_NORMAL, FALSE, FALSE);
	gFont[ARIAL_14] = new CFont(FontName, BaseFontSize + 14, FW_NORMAL, FALSE, FALSE);
	gFont[ARIAL_15] = new CFont(FontName, BaseFontSize + 15, FW_NORMAL, FALSE, FALSE);
	gFont[ARIAL_16] = new CFont(FontName, BaseFontSize + 16, FW_NORMAL, FALSE, FALSE);
	gFont[ARIAL_20] = new CFont(FontName, BaseFontSize + 20, FW_NORMAL, FALSE, FALSE);
	gFont[ARIAL_22] = new CFont(FontName, BaseFontSize + 22, FW_NORMAL, FALSE, FALSE);
	gFont[ARIAL_24] = new CFont(FontName, BaseFontSize + 24, FW_NORMAL, FALSE, FALSE);

	gFont[ARIAL_BLACK_10] = new CFont(FontName, BaseFontSize + 10, FW_BOLD, FALSE, FALSE);
	gFont[ARIAL_BLACK_11] = new CFont(FontName, BaseFontSize + 11, FW_BOLD, FALSE, FALSE);
	gFont[ARIAL_BLACK_12] = new CFont(FontName, BaseFontSize + 12, FW_BOLD, FALSE, FALSE);
	gFont[ARIAL_BLACK_13] = new CFont(FontName, BaseFontSize + 13, FW_BOLD, FALSE, FALSE);
	gFont[ARIAL_BLACK_14] = new CFont(FontName, BaseFontSize + 14, FW_BOLD, FALSE, FALSE);
	gFont[ARIAL_BLACK_15] = new CFont(FontName, BaseFontSize + 15, FW_BOLD, FALSE, FALSE);
	gFont[ARIAL_BLACK_16] = new CFont(FontName, BaseFontSize + 16, FW_BOLD, FALSE, FALSE);
	gFont[ARIAL_BLACK_24] = new CFont(FontName, BaseFontSize + 24, FW_BOLD, FALSE, FALSE);

	gFont[ARIAL_UNDERLINE_10] = new CFont(FontName, BaseFontSize + 10, FW_NORMAL, FALSE, TRUE);
	gFont[ARIAL_UNDERLINE_12] = new CFont(FontName, BaseFontSize + 12, FW_NORMAL, FALSE, TRUE);
	gFont[ARIAL_UNDERLINE_14] = new CFont(FontName, BaseFontSize + 14, FW_NORMAL, FALSE, TRUE);
	gFont[ARIAL_UNDERLINE_15] = new CFont(FontName, BaseFontSize + 15, FW_NORMAL, FALSE, TRUE);
	gFont[ARIAL_UNDERLINE_16] = new CFont(FontName, BaseFontSize + 16, FW_NORMAL, FALSE, TRUE);

	gFont[ARIAL_ITALIC_10] = new CFont(FontName, BaseFontSize + 8, FW_NORMAL, TRUE, FALSE);
	gFont[ARIAL_ITALIC_12] = new CFont(FontName, BaseFontSize + 12, FW_NORMAL, TRUE, FALSE);
	gFont[ARIAL_ITALIC_14] = new CFont(FontName, BaseFontSize + 14, FW_NORMAL, TRUE, FALSE);
	gFont[ARIAL_ITALIC_15] = new CFont(FontName, BaseFontSize + 15, FW_NORMAL, TRUE, FALSE);
	gFont[ARIAL_ITALIC_16] = new CFont(FontName, BaseFontSize + 16, FW_NORMAL, TRUE, FALSE);

	gFont[TAHOMA_12] = new CFont(FontName, BaseFontSize + 12, FW_NORMAL, FALSE, FALSE);
	gFont[TAHOMA_13] = new CFont(FontName, BaseFontSize + 13, FW_NORMAL, FALSE, FALSE);
	gFont[TAHOMA_14] = new CFont(FontName, BaseFontSize + 14, FW_NORMAL, FALSE, FALSE);
	gFont[TAHOMA_15] = new CFont(FontName, BaseFontSize + 15, FW_NORMAL, FALSE, FALSE);
	gFont[TAHOMA_16] = new CFont(FontName, BaseFontSize + 16, FW_NORMAL, FALSE, FALSE);

	gFont[TAHOMA_BOLD_12] = new CFont(FontName, BaseFontSize + 12, FW_BOLD, FALSE, FALSE);
	gFont[TAHOMA_BOLD_13] = new CFont(FontName, BaseFontSize + 13, FW_BOLD, FALSE, FALSE);
	gFont[TAHOMA_BOLD_14] = new CFont(FontName, BaseFontSize + 14, FW_BOLD, FALSE, FALSE);
	gFont[TAHOMA_BOLD_15] = new CFont(FontName, BaseFontSize + 15, FW_BOLD, FALSE, FALSE);
	gFont[TAHOMA_BOLD_16] = new CFont(FontName, BaseFontSize + 16, FW_BOLD, FALSE, FALSE);
	gFont[TAHOMA_BOLD_17] = new CFont(FontName, BaseFontSize + 20, FW_BOLD, FALSE, FALSE);
}

int CFont::DrawText(int x, int y, BYTE *Color, BYTE * BgColor, int width, LPINT align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff) - 1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	this->SetFont();
	pSetTextColor(pTextThis(), Color[0], Color[1], Color[2], Color[3]);
	pSetTextBGColor(pTextThis(), BgColor[0], BgColor[1], BgColor[2], BgColor[3]);
	return pDrawText(pTextThis(), x, y, Buff, width, 0, (LPINT)align, 0);
}