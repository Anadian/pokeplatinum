#ifndef POKEPLATINUM_STRUCT_OV101_021D4714_H
#define POKEPLATINUM_STRUCT_OV101_021D4714_H

#include "overlay101/struct_ov101_021D13C8_decl.h"

#include "overworld_anim_manager.h"
#include "sys_task_manager.h"

typedef struct {
    u32 coins;
    u32 slotMachineVariant;
    int unk_08;
    Overlay101State *slotsMinigameDTO;
    SysTask *unk_10;
    OverworldAnimManager *unk_14;
    OverworldAnimManager *unk_18;
} UnkStruct_ov101_021D4714;

#endif // POKEPLATINUM_STRUCT_OV101_021D4714_H
