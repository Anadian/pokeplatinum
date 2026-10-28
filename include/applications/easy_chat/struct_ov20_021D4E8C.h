#ifndef POKEPLATINUM_STRUCT_OV20_021D4E8C_H
#define POKEPLATINUM_STRUCT_OV20_021D4E8C_H

#include "bg_window.h"
#include "sys_task_manager.h"

typedef struct {
    BgConfig *coins;
    u32 slotMachineVariant;
    int unk_08;
    fx32 slotsMinigameDTO;
    fx32 unk_10;
    fx32 unk_14;
    u16 unk_18;
    u16 unk_1A;
    SysTask *unk_1C;
} UnkStruct_ov20_021D4E8C;

#endif // POKEPLATINUM_STRUCT_OV20_021D4E8C_H
