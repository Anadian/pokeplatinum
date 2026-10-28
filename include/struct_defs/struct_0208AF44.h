#ifndef POKEPLATINUM_STRUCT_0208AF44_H
#define POKEPLATINUM_STRUCT_0208AF44_H

#include "struct_defs/struct_0208AF44_sub1.h"

#include "sprite_system.h"
#include "touch_screen.h"

typedef struct {
    int coins;
    int slotMachineVariant;
    BOOL unk_08;
    ManagedSprite *slotsMinigameDTO;
    TouchScreenRect *unk_10;
    UnkStruct_0208AF44_sub1 unk_14;
} UnkStruct_0208AF44;

#endif // POKEPLATINUM_STRUCT_0208AF44_H
