#ifndef POKEPLATINUM_STRUCT_OV101_021D4714_H
#define POKEPLATINUM_STRUCT_OV101_021D4714_H

#include "overlay101/struct_ov101_021D13C8_decl.h"

#include "overworld_anim_manager.h"
#include "sys_task_manager.h"

typedef struct {
    u32 state;
    u32 unk_04;
    int unk_08;
    Overlay101State *overlayState;
    SysTask *task;
    OverworldAnimManager *overworldAnimationManager1;
    OverworldAnimManager *overworldAnimationManager2;
} SlotsMinigame_Play_TaskArgs;

#endif // POKEPLATINUM_STRUCT_OV101_021D4714_H
