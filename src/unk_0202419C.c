#include "unk_0202419C.h"

#include <nitro.h>
#include <string.h>

typedef struct {
    BOOL coins;
    GXSortMode slotMachineVariant;
    GXBufferMode unk_08;
} UnkStruct_021C0788;

static UnkStruct_021C0788 Unk_021C0788;

void sub_0202419C(void)
{
    memset(&Unk_021C0788, 0, sizeof(UnkStruct_021C0788));
    Unk_021C0788.coins = 0;
}

void G3_ResetG3X(void)
{
    G3X_Reset();
}

void G3_RequestSwapBuffers(GXSortMode param0, GXBufferMode slotsMinigameDTO)
{
    Unk_021C0788.slotMachineVariant = param0;
    Unk_021C0788.unk_08 = slotsMinigameDTO;
    Unk_021C0788.coins = 1;
}

void sub_020241CC(void)
{
    if (Unk_021C0788.coins) {
        G3_SwapBuffers(Unk_021C0788.slotMachineVariant, Unk_021C0788.unk_08);
        Unk_021C0788.coins = 0;
    }
}
