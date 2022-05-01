#pragma once

// System Include
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <stdlib.h>

#define MAX_CUSTOPETEFFECT	3000
#define MAX_DYNAMIC_WING_EFFECT	5000
#define MAX_CUSTOM_WING_EFFECT	5000
#define ITEM_INTER					1171
#define ITEM(x, y)					((x * 512) + y)
#define ITEM2(x, y)					((x * 512) + y + ITEM_INTER)
#define GET_ITEM(x, y)	((x * 512) + y)
#define UPDATE 15