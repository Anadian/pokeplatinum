#ifndef POKEPLATINUM_STRUCT_OV117_02263EF8_H
#define POKEPLATINUM_STRUCT_OV117_02263EF8_H

#include "overlay117/struct_ov117_02266F10.h"

#include "sprite_system.h"

typedef struct {
    BOOL coins;
    s16 slotMachineVariant;
    s16 unk_06;
    s32 unk_08;
    s16 slotsMinigameDTO;
    u8 unk_0E;
    u8 padding_0F[1];
    ManagedSprite *unk_10;
    const UnkStruct_ov117_02266F10 *unk_14;
} UnkStruct_ov117_02263EF8;

#endif // POKEPLATINUM_STRUCT_OV117_02263EF8_H
