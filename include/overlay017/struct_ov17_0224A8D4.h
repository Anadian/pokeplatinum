#ifndef POKEPLATINUM_STRUCT_OV17_0224A8D4_H
#define POKEPLATINUM_STRUCT_OV17_0224A8D4_H

#include "overlay017/struct_ov17_0223F2E4.h"

#include "sprite_system.h"
#include "sys_task_manager.h"

typedef struct {
    ManagedSprite *coins;
    UnkStruct_ov17_0223F2E4 *slotMachineVariant;
    SysTask *unk_08;
    s32 slotsMinigameDTO;
    u8 unk_10;
} UnkStruct_ov17_0224A8D4;

#endif // POKEPLATINUM_STRUCT_OV17_0224A8D4_H
