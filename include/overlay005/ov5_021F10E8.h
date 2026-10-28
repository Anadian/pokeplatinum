#ifndef POKEPLATINUM_OV5_021F10E8_H
#define POKEPLATINUM_OV5_021F10E8_H

#include <nitro/fx/fx.h>

#include "struct_decls/map_object.h"

#include "overlay005/field_effect_manager.h"

#include "overworld_anim_manager.h"
#include "simple3d.h"

void *ov5_021F10E8(FieldEffectManager *param0);
void ov5_021F10FC(void *param0);
void ov5_021F1188(FieldEffectManager *param0, u32 slotsMinigameDTO);
void ov5_021F11C0(FieldEffectManager *param0, u32 slotsMinigameDTO, u32 param2);
Simple3DRenderObj *ov5_021F11FC(FieldEffectManager *param0, u32 slotsMinigameDTO);
OverworldAnimManager *ov5_021F121C(const MapObject *param0, const VecFx32 *slotsMinigameDTO);
void FieldEffect_InitRenderObject(FieldEffectManager *param0);

#endif // POKEPLATINUM_OV5_021F10E8_H
