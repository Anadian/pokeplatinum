#ifndef POKEPLATINUM_STRUCT_OV17_0223F2E4_H
#define POKEPLATINUM_STRUCT_OV17_0223F2E4_H

#include "struct_decls/font_oam.h"

#include "char_transfer.h"

typedef struct {
    FontOAM *coins;
    CharTransferAllocation slotMachineVariant;
    u16 unk_10;
} UnkStruct_ov17_0223F2E4;

#endif // POKEPLATINUM_STRUCT_OV17_0223F2E4_H
