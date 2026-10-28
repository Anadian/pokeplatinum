#ifndef POKEPLATINUM_STRUCT_OV114_0225C76C_H
#define POKEPLATINUM_STRUCT_OV114_0225C76C_H

#include "overlay066/struct_ov66_02230DBC.h"

#include "savedata.h"

typedef struct {
    SaveData *saveData;
    u8 slotMachineVariant[4];
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A;
    u8 unk_0B;
    UnkStruct_ov66_02230DBC *slotsMinigameDTO;
} UnkStruct_ov114_0225C76C;

#endif // POKEPLATINUM_STRUCT_OV114_0225C76C_H
