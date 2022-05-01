#pragma once

#define MAX_WORLD_SETTINGS 1
#define MAX_WORLD_SELECT_CHAR 5


struct ButtonRenderChar
{
	DWORD ID;
	float x;
	float y;
	float w;
	float h;
	bool Event;
};

struct Coord
{
	float CoordX;
	float CoordY;
	float Rotate;
};

struct Personaje
{
	int Index;
	Coord Coordenada1;
	Coord Coordenada2;
	ButtonRenderChar BT;
};

struct SelectChar
{
	int Index;
	int MapChar;
	float ModelScale;
	float flt_87933D0;
	float flt_87933D4;
	float flt_87933D8;
	float flt_87933DC;
	float flt_87933E0;
	float flt_87933E4;
	Personaje PJ[MAX_WORLD_SELECT_CHAR];
};

class MultiSelect
{
public:
	//MultiSelect();
	//virtual ~MultiSelect();
	void Load(char* path);
	void SetInfo(SelectChar info);
public:
	SelectChar RenderSelect[MAX_WORLD_SETTINGS];
};
extern MultiSelect gSelectCharRamdon;