#ifndef POKEPLATINUM_STRUCT_OV101_021D1894_H
#define POKEPLATINUM_STRUCT_OV101_021D1894_H

#include "enums.h"
#include "sys_task_manager.h"

typedef struct {
    u32 command; // 0 No Change, 1, Stop/Pause, 2 Play
    int isSoundSequenceChangeActive;
    SlotsMinigame_SoundSequenceID formerSequenceID;
    SlotsMinigame_SoundSequenceID currentSequenceID;
    SysTask *task;
} SlotsMinigame_SoundSequenceController;

#endif // POKEPLATINUM_STRUCT_OV101_021D1894_H
