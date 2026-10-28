#ifndef POKEPLATINUM_STRUCT_OV22_0225B388_H
#define POKEPLATINUM_STRUCT_OV22_0225B388_H

#include "overlay022/struct_ov22_02254DE0.h"
#include "overlay022/struct_ov22_02259484.h"

#include "bg_window.h"
#include "software_sprite.h"

typedef struct {
    SoftwareSpriteManager *coins;
    SoftwareSpriteChars **slotMachineVariant;
    SoftwareSpritePalette **unk_08;
    u8 *slotsMinigameDTO;
    PokemonSpriteManager *unk_10;
    BgConfig *unk_14;
    UnkStruct_ov22_02254DE0 *unk_18;
    UnkStruct_ov22_02259484 *unk_1C;
    int unk_20;
} UnkStruct_ov22_0225B388;

#endif // POKEPLATINUM_STRUCT_OV22_0225B388_H
