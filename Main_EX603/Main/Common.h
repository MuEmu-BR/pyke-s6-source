#pragma once

void InitCommon();
char FixHelperMouseClick(int a1); //Dupe ChaosMachine
BOOL CheckIsLuckyItem(int ItemID);
BOOL CheckGensBattleMap(int map);
BOOL CheckGensMoveIndex(int idx);
void LoginTab();
void CheckMasterLevel();
void CompareGensMoveIndex();
void DrawEffectsPic(int &EffectID, float StartX, float StartY, float StartWidth, float StartHeight );
void Copyright();

extern BYTE GensBattleMapCount;
extern BYTE GensMoveIndexCount;
extern BYTE GensBattleMap[120];
extern BYTE GensMoveIndex[120];

extern int DisableStaticEffect;
extern int DisableDynamicEffect;
extern int DisableSkillEffect;
extern int DisableGlowEffect;
extern int DisableObject;
extern int DisableShadow;
extern int Anisotropy;
extern int MaxAnisotropy;
extern int Linear;
extern int Fog;
extern int Tron;
extern int MiniMap;
extern int SeparateChat;
extern int TimerBar;
extern int HpMonsterBar;
extern int HpBar;
extern int SellPostColor;
extern int offhelper;
extern int OpenSwicthSkill;
extern int SkillPage;