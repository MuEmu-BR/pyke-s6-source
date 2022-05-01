#pragma once

class CFont
{
public:
	CFont(TCHAR* Name, int Size, int Weight, BOOL bItalic, BOOL bUnderline);
	~CFont();
	int SetFont();
	HGDIOBJ m_Font;
	int DrawText(int x, int y, BYTE *Color, BYTE * BgColor, int width, LPINT align, LPCSTR Text, ...);
	HFONT MAKE;
};

extern CFont* gFont[100];

class cColor
{
public:
	cColor();
	virtual ~cColor();
	void LoadResource();
	BYTE ShinyGreen[4];
	BYTE Gold[4];
	BYTE White[4];
	BYTE Orange[4];
	BYTE Red[4];
	BYTE Red50[4];
	BYTE Blue[4];
	BYTE Green[4];
	BYTE Trans[4];
	BYTE Trans25[4];
	BYTE Black[4];
}; extern cColor *Fcolor;


void InitFonts();

enum FONT_TYPE {
	ARIAL_8,
	ARIAL_10,
	ARIAL_12,
	ARIAL_14,
	ARIAL_15,
	ARIAL_16,
	ARIAL_20,
	ARIAL_22,
	ARIAL_24,

	ARIAL_BLACK_10,
	ARIAL_BLACK_11,
	ARIAL_BLACK_12,
	ARIAL_BLACK_13,
	ARIAL_BLACK_14,
	ARIAL_BLACK_15,
	ARIAL_BLACK_16,
	ARIAL_BLACK_24,

	ARIAL_UNDERLINE_10,
	ARIAL_UNDERLINE_12,
	ARIAL_UNDERLINE_14,
	ARIAL_UNDERLINE_15,
	ARIAL_UNDERLINE_16,

	ARIAL_ITALIC_10,
	ARIAL_ITALIC_12,
	ARIAL_ITALIC_14,
	ARIAL_ITALIC_15,
	ARIAL_ITALIC_16,

	TAHOMA_12,
	TAHOMA_13,
	TAHOMA_14,
	TAHOMA_15,
	TAHOMA_16,

	TAHOMA_BOLD_12,
	TAHOMA_BOLD_13,
	TAHOMA_BOLD_14,
	TAHOMA_BOLD_15,
	TAHOMA_BOLD_16,
	TAHOMA_BOLD_17,
};