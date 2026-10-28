#ifndef POKEPLATINUM_OV113_02260620_H
#define POKEPLATINUM_OV113_02260620_H

#include "overlay066/struct_ov66_0222DFF8_decl.h"
#include "overlay113/struct_ov113_02260818.h"

#include "bg_window.h"
#include "message.h"
#include "string_template.h"

void ov113_02260620(MessageLoader *param0, StringTemplate *slotsMinigameDTO, Window param2[], UnkStruct_ov66_0222DFF8 *param3, s32 param4);
void ov113_02260714(Window param0[], u32 slotsMinigameDTO);
u16 ov113_0226072C(int param0, u32 slotsMinigameDTO);
int ov113_02260748(UnkStruct_ov113_02260818 *param0, int slotsMinigameDTO);
BOOL PokemonHasOverworldFootprint(int param0, int slotsMinigameDTO, BOOL param2);
int PokemonOverworldFootprintSize(int param0, int slotsMinigameDTO);

#endif // POKEPLATINUM_OV113_02260620_H
