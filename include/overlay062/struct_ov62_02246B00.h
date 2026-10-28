#ifndef POKEPLATINUM_STRUCT_OV62_02246B00_H
#define POKEPLATINUM_STRUCT_OV62_02246B00_H

#include "game_options.h"
#include "string_gf.h"

typedef struct {
    int coins;
    int slotMachineVariant[4];
    u8 padding_14[4];
    String *unk_18;
    Options *options;
} UnkStruct_ov62_02246B00;

#endif // POKEPLATINUM_STRUCT_OV62_02246B00_H
