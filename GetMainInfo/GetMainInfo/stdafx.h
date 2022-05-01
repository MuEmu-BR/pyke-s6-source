#pragma once

// System Include
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <stdlib.h>
#include <map>
#include <fstream>

#define PREMIUN	1

#if(PREMIUN == 1)
	#define MAX_CUSTOM_GLOVES	50
	#define MAX_CUSTOM_BOW		50
	#define MAX_PET_ITEM		300
	#define MAX_CUSTOMCLOAK		20
	#define MAX_CUSTOPETEFFECT	1000
#else
	#define MAX_CUSTOM_GLOVES	20
	#define MAX_CUSTOM_BOW		20
	#define MAX_PET_ITEM		150
	#define MAX_CUSTOMCLOAK		10
	#define MAX_CUSTOPETEFFECT		500
#endif

#define MAX_CUSTOM_WING			100
#define MAX_REMAKE_EFFECT		100
#define MAX_CUSTOM_ITEM_INFO	1000
#define MAX_POSITION_ITEM		1000
#define MAX_DYNAMIC_WING_EFFECT	3000
#define MAX_CUSTOM_WING_EFFECT	3000

#define GET_ITEM(x, y)	((x * 512) + y)