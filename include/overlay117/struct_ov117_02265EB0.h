#ifndef POKEPLATINUM_STRUCT_OV117_02265EB0_H
#define POKEPLATINUM_STRUCT_OV117_02265EB0_H

#include "struct_decls/font_oam.h"

#include "char_transfer.h"

typedef struct {
    FontOAM *coins;
    CharTransferAllocation slotMachineVariant;
    u16 unk_10;
    u8 padding_12[2];
} UnkStruct_ov117_02265EB0;

#endif // POKEPLATINUM_STRUCT_OV117_02265EB0_H
