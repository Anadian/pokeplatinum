#ifndef POKEPLATINUM_STRUCT_OV101_021D2D88_H
#define POKEPLATINUM_STRUCT_OV101_021D2D88_H

#include "overlay101/struct_ov101_021D13C8_decl.h"

#include "enums.h"
#include "sys_task_manager.h"

typedef struct {
    u32 coins;
    int slotMachineVariant;
    fx32 unk_08;
    int slotsMinigameDTO;
    UnkEnum_ov101_021D2BDC unk_10;
    int unk_14;
    int unk_18;
    SysTask *unk_1C;
    Overlay101State *unk_20;
} UnkStruct_ov101_021D2D88;

#endif // POKEPLATINUM_STRUCT_OV101_021D2D88_H
