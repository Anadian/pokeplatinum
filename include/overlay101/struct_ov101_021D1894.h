#ifndef POKEPLATINUM_STRUCT_OV101_021D1894_H
#define POKEPLATINUM_STRUCT_OV101_021D1894_H

#include "enums.h"
#include "sys_task_manager.h"

typedef struct {
    u32 coins; //Command: 0 No change, 1 Stop/Pause, 2 Play
    int slotMachineVariant; //isSoundSequenceChangeActive; Substate: needs to be zero to quit the SlotsMinigame
    SlotsMinigame_SoundSequenceID unk_08; //from SQEUENCE_ID
    SlotsMinigame_SoundSequenceID slotsMinigameDTO; //to SEQUENCE_STATE
    SysTask *unk_10;
} SlotsMinigame_SoundSequenceController; //SlotsMinigame_SoundSequenceController

#endif // POKEPLATINUM_STRUCT_OV101_021D1894_H
