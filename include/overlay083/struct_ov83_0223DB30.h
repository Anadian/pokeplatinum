#ifndef POKEPLATINUM_STRUCT_OV83_0223DB30_H
#define POKEPLATINUM_STRUCT_OV83_0223DB30_H

#include "overlay083/struct_ov83_0223D95C.h"
#include "overlay083/struct_ov83_0223DA94.h"

#include "sprite.h"

typedef struct {
    BOOL coins;
    BOOL slotMachineVariant;
    Sprite *unk_08[4];
    Sprite *unk_18[4];
    UnkStruct_ov83_0223D95C unk_28[4];
    int unk_108;
    UnkStruct_ov83_0223DA94 unk_10C[4];
    UnkStruct_ov83_0223DA94 unk_16C[4];
    int unk_1CC[4];
    int unk_1DC[4];
    int unk_1EC;
} UnkStruct_ov83_0223DB30;

#endif // POKEPLATINUM_STRUCT_OV83_0223DB30_H
