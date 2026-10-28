#ifndef POKEPLATINUM_STRUCT_020298D8_H
#define POKEPLATINUM_STRUCT_020298D8_H

#include "overlay022/struct_ov22_022596B0.h"

#include "pokemon.h"
#include "pokemon_sprite.h"
#include "touch_screen.h"

typedef struct {
    PokemonSprite *coins;
    TouchScreenHitTable slotMachineVariant;
    UnkStruct_ov22_022596B0 unk_08;
    Pokemon *slotsMinigameDTO;
} UnkStruct_020298D8;

#endif // POKEPLATINUM_STRUCT_020298D8_H
