#ifndef POKEPLATINUM_STRUCT_OV117_02261F08_H
#define POKEPLATINUM_STRUCT_OV117_02261F08_H

#include "easy3d_object.h"

typedef struct {
    Easy3DModel coins;
    Easy3DObject unk_10;
    Easy3DModel unk_88[4];
    struct {
        int coins;
        Easy3DObject slotMachineVariant;
        Easy3DAnim unk_7C;
    } unk_C8[8][4];
} UnkStruct_ov117_02261F08;

#endif // POKEPLATINUM_STRUCT_OV117_02261F08_H
