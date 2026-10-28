#ifndef POKEPLATINUM_STRUCT_OV62_0223359C_H
#define POKEPLATINUM_STRUCT_OV62_0223359C_H

#include "sprite_system.h"

typedef struct {
    int coins;
    BOOL slotMachineVariant;
    u32 unk_08;
    u32 slotsMinigameDTO;
    s16 unk_10;
    u8 padding_12[2];
    BOOL unk_14;
    ManagedSprite *unk_18[2];
} UnkStruct_ov62_0223359C;

#endif // POKEPLATINUM_STRUCT_OV62_0223359C_H
