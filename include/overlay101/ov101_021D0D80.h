#ifndef POKEPLATINUM_OV101_021D0D80_H
#define POKEPLATINUM_OV101_021D0D80_H

#include "overlay101/struct_ov101_021D13C8_decl.h"

#include "enums.h"
#include "overlay_manager.h"

int SlotsMinigame_Init(ApplicationManager *appMan, int *param1);
int SlotsMinigame_Main(ApplicationManager *appMan, int *param1);
int SlotsMinigame_Exit(ApplicationManager *appMan, int *param1);
void SlotsMinigame_LoadWindow(UnkStruct_ov101_021D13C8 *param0);
void SlotsMinigame_DrawMessageBox(UnkStruct_ov101_021D13C8 *param0, u32 param1);
void SlotsMinigame_FreeMessageBox(UnkStruct_ov101_021D13C8 *param0);
void ov101_021D1894(UnkStruct_ov101_021D13C8 *param0, UnkEnum_ov101_021D1894 param1);
void *SlotsMinigame_AllocateMemory(u32 param0);
void *SlotsMinigame_CopyArchive(UnkStruct_ov101_021D13C8 *param0, u32 param1, int param2);

#endif // POKEPLATINUM_OV101_021D0D80_H
