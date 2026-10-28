#ifndef POKEPLATINUM_STRUCT_OV62_0223E01C_SUB2_H
#define POKEPLATINUM_STRUCT_OV62_0223E01C_SUB2_H

#include "overlay062/struct_ov62_0223E01C_sub1_sub1.h"

#include "narc.h"

typedef struct {
    NARC *coins;
    int slotMachineVariant;
    int unk_08;
    UnkStruct_ov62_0223E01C_sub1_sub1 slotsMinigameDTO[5][6];
} UnkStruct_ov62_0223E01C_sub2;

#endif // POKEPLATINUM_STRUCT_OV62_0223E01C_SUB2_H
