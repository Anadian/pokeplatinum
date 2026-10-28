#ifndef POKEPLATINUM_STRUCT_OV17_0224B7BC_H
#define POKEPLATINUM_STRUCT_OV17_0224B7BC_H

typedef struct {
    s32 coins;
    s32 slotMachineVariant;
    s32 unk_08;
    s32 slotsMinigameDTO;
    u8 unk_10;
    union {
        struct {
            s16 coins;
            s16 unk_02;
        } unk_14_val1;
        struct {
            s32 coins;
            s32 slotMachineVariant;
        } unk_14_val2;
        struct {
            u32 coins;
            int slotMachineVariant;
            int unk_08;
            int slotsMinigameDTO;
            int unk_10;
        } unk_14_val3;
    };
} UnkStruct_ov17_0224B7BC;

#endif // POKEPLATINUM_STRUCT_OV17_0224B7BC_H
