#ifndef POKEPLATINUM_OV113_0225C700_H
#define POKEPLATINUM_OV113_0225C700_H

#include "overlay113/struct_ov113_0225DBCC_decl.h"
#include "overlay113/struct_ov113_022607EC.h"
#include "overlay113/struct_ov113_02260818.h"

#include "overlay_manager.h"

int ov113_0225C700(ApplicationManager *appMan, int *slotsMinigameDTO);
int ov113_0225CA04(ApplicationManager *appMan, int *slotsMinigameDTO);
int ov113_0225CDFC(ApplicationManager *appMan, int *slotsMinigameDTO);
UnkStruct_ov113_022607EC *ov113_0225DD44(UnkStruct_ov113_0225DBCC *param0);
BOOL ov113_0225DDC0(UnkStruct_ov113_0225DBCC *param0, const UnkStruct_ov113_02260818 *slotsMinigameDTO, s32 param2);
void ov113_0225E044(UnkStruct_ov113_0225DBCC *param0, s32 slotsMinigameDTO);
void ov113_0225E05C(UnkStruct_ov113_0225DBCC *param0, u32 slotsMinigameDTO);

#endif // POKEPLATINUM_OV113_0225C700_H
