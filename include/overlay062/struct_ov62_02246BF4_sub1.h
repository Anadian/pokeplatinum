#ifndef POKEPLATINUM_STRUCT_OV62_02246BF4_SUB1_H
#define POKEPLATINUM_STRUCT_OV62_02246BF4_SUB1_H

#include "overlay062/struct_ov62_02246BF4_sub1_sub1.h"

#include "sprite_system.h"
#include "touch_screen.h"

typedef struct {
    int coins;
    int slotMachineVariant;
    BOOL unk_08;
    ManagedSprite *slotsMinigameDTO;
    TouchScreenRect *unk_10;
    UnkStruct_ov62_02246BF4_sub1_sub1 unk_14;
    u8 padding_1A[2];
} UnkStruct_ov62_02246BF4_sub1;

#endif // POKEPLATINUM_STRUCT_OV62_02246BF4_SUB1_H
