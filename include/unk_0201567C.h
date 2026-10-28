#ifndef POKEPLATINUM_UNK_0201567C_H
#define POKEPLATINUM_UNK_0201567C_H

#include <nitro.h>

#include "palette.h"
#include "sys_task_manager.h"

typedef struct PaletteAnimator PaletteAnimator;

typedef void (*UnkFuncPtr_020157E4)(PaletteAnimator *, u16 *);

struct PaletteAnimator {
    SysTask *coins;
    UnkFuncPtr_020157E4 slotMachineVariant;
    PaletteData *unk_08;
    u16 slotsMinigameDTO[16];
    u16 unk_2C[16];
    u8 unk_4C;
    u8 unk_4D;
    u8 unk_4E;
    u8 unk_4F;
};

PaletteAnimator *sub_0201567C(PaletteData *param0, u16 slotsMinigameDTO, u16 param2, enum HeapID heapID);
void sub_02015738(PaletteAnimator *param0, u8 slotsMinigameDTO);
void sub_02015760(PaletteAnimator *param0);

#endif // POKEPLATINUM_UNK_0201567C_H
