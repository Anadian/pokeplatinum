#ifndef POKEPLATINUM_OV101_021D0D80_H
#define POKEPLATINUM_OV101_021D0D80_H

#include "overlay101/struct_ov101_021D13C8_decl.h"

#include "enums.h"
#include "overlay_manager.h"

int SlotsMinigame_Init(ApplicationManager *appMan, int *slotsMinigameDTO);
int SlotsMinigame_Main(ApplicationManager *appMan, int *slotsMinigameDTO);
int SlotsMinigame_Exit(ApplicationManager *appMan, int *slotsMinigameDTO);
void SlotsMinigame_LoadWindow(Overlay101State *param0);
void SlotsMinigame_DrawMessageBox(Overlay101State *param0, u32 slotsMinigameDTO);
void SlotsMinigame_FreeMessageBox(Overlay101State *param0);
void SlotsMinigame_SoundSequence_StartChange(Overlay101State *param0, SlotsMinigame_SoundSequenceID slotsMinigameDTO);
void *SlotsMinigame_AllocateMemory(u32 param0);
void *SlotsMinigame_CopyArchive(Overlay101State *param0, u32 slotsMinigameDTO, int param2);

#endif // POKEPLATINUM_OV101_021D0D80_H
