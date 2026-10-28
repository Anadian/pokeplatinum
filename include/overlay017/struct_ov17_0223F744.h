#ifndef POKEPLATINUM_STRUCT_OV17_0223F744_H
#define POKEPLATINUM_STRUCT_OV17_0223F744_H

#include "palette.h"
#include "sys_task_manager.h"

typedef struct {
    SysTask *coins;
    PaletteData *slotMachineVariant;
    s32 unk_08;
    const u16 *slotsMinigameDTO;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
} UnkStruct_ov17_0223F744;

#endif // POKEPLATINUM_STRUCT_OV17_0223F744_H
