#ifndef POKEPLATINUM_STRUCT_OV17_0224DFF8_H
#define POKEPLATINUM_STRUCT_OV17_0224DFF8_H

#include "overlay017/struct_ov17_02243C80.h"
#include "overlay017/struct_ov17_0224DF54.h"
#include "overlay017/struct_ov17_0224DF54_sub2.h"
#include "overlay017/struct_ov17_0224E1F4.h"
#include "overlay017/struct_ov17_0224F30C.h"

typedef struct {
    UnkStruct_ov17_0224DF54 *coins;
    UnkStruct_ov17_02243C80 slotMachineVariant;
    UnkStruct_ov17_0224F30C *slotsMinigameDTO;
    u8 unk_10;
    u8 unk_11[4];
    UnkStruct_ov17_0224E1F4 unk_18[4];
    UnkStruct_ov17_0224DF54_sub2 unk_C8;
} UnkStruct_ov17_0224DFF8;

#endif // POKEPLATINUM_STRUCT_OV17_0224DFF8_H
