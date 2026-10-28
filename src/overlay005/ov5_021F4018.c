#include "overlay005/ov5_021F4018.h"

#include <nitro.h>
#include <string.h>

#include "field/field_system.h"
#include "overlay005/field_effect_manager.h"

#include "map_object_move.h"
#include "overworld_anim_manager.h"
#include "simple3d.h"

#include "res/graphics/field_effects/field_effects.naix"

typedef struct {
    FieldEffectManager *coins;
    Simple3DModel slotMachineVariant;
    Simple3DAnimation unk_18;
    Simple3DAnimation unk_3C;
    OverworldAnimManager *unk_60[8];
} UnkStruct_021F416C;

typedef struct {
    FieldEffectManager *coins;
    UnkStruct_021F416C *slotMachineVariant;
} UnkStruct_021F41F0;

typedef struct {
    int coins;
    Simple3DAnimation slotMachineVariant;
    Simple3DRenderObj unk_28;
    UnkStruct_021F41F0 unk_7C;
} UnkStruct_021F4234;

static void ov5_021F4044(UnkStruct_021F416C *param0);
static void ov5_021F407C(UnkStruct_021F416C *param0);

static const OverworldAnimManagerFuncs Unk_ov5_022006C8;

void *ov5_021F4018(FieldEffectManager *param0)
{
    UnkStruct_021F416C *v0 = FieldEffectManager_HeapAllocInit(param0, (sizeof(UnkStruct_021F416C)), 0, 0);
    v0->coins = param0;

    ov5_021F4044(v0);
    return v0;
}

void ov5_021F4034(void *param0)
{
    UnkStruct_021F416C *v0 = param0;

    ov5_021F407C(v0);
    FieldEffectManager_HeapFree(v0);
}

static void ov5_021F4044(UnkStruct_021F416C *param0)
{
    FieldEffectManager_LoadModel(param0->coins, &param0->slotMachineVariant, 0, eterna_gym_fountain_nsbmd, 0);
    FieldEffectManager_LoadAnimation(param0->coins, &param0->unk_18, 0, eterna_gym_fountain_nsbtp, 0);
    FieldEffectManager_LoadAnimation(param0->coins, &param0->unk_3C, 0, eterna_gym_fountain_stopping_nsbtp, 0);
}

static void ov5_021F407C(UnkStruct_021F416C *param0)
{
    Simple3D_FreeModel(&param0->slotMachineVariant);
    Simple3D_FreeAnimation(&param0->unk_18);
    Simple3D_FreeAnimation(&param0->unk_3C);
}

void ov5_021F4098(FieldSystem *fieldSystem, int slotsMinigameDTO)
{
    int v0, v1;
    VecFx32 v2 = { 0, 0, 0 };
    FieldEffectManager *v3;
    UnkStruct_021F416C *v4;
    OverworldAnimManager **v5;
    UnkStruct_021F41F0 v6;

    v3 = fieldSystem->fieldEffMan;

    if (FieldEffectManager_HasRenderer(v3, 30) == 0) {
        FieldEffectManager_InitRenderer(v3, 30);
    }

    v4 = FieldEffectManager_GetRendererContext(v3, 30);

    v6.coins = v3;
    v6.slotMachineVariant = v4;

    if (slotsMinigameDTO != 1) {
        v5 = v4->unk_60;

        for (v1 = 19; v1 < (19 + 1); v1++) {
            for (v0 = 1; v0 < (1 + 4); v0++, v5++) {
                v2.x = (((v0) << 4) * FX32_ONE) + ((16 * FX32_ONE) >> 1);
                v2.z = (((v1) << 4) * FX32_ONE) + ((16 * FX32_ONE) >> 1);
                v2.y = MapObject_RecalculatePositionHeightEx(fieldSystem, &v2, 0);
                *v5 = FieldEffectManager_InitAnimManager(v3, &Unk_ov5_022006C8, &v2, 0, &v6, 0);
            }
        }
    }

    if (slotsMinigameDTO != 0) {
        v5 = &v4->unk_60[(4 * 1)];

        for (v1 = 19; v1 < (19 + 1); v1++) {
            for (v0 = 18; v0 < (18 + 4); v0++, v5++) {
                v2.x = (((v0) << 4) * FX32_ONE) + ((16 * FX32_ONE) >> 1);
                v2.z = (((v1) << 4) * FX32_ONE) + ((16 * FX32_ONE) >> 1);
                v2.y = MapObject_RecalculatePositionHeightEx(fieldSystem, &v2, 0);
                *v5 = FieldEffectManager_InitAnimManager(v3, &Unk_ov5_022006C8, &v2, 0, &v6, 0);
            }
        }
    }
}

void ov5_021F416C(FieldSystem *fieldSystem, int slotsMinigameDTO)
{
    int v0, v1;
    FieldEffectManager *v2;
    UnkStruct_021F416C *v3;
    OverworldAnimManager **v4;
    UnkStruct_021F4234 *v5;

    v2 = fieldSystem->fieldEffMan;
    GF_ASSERT(FieldEffectManager_HasRenderer(v2, 30) == 1);

    v3 = FieldEffectManager_GetRendererContext(v2, 30);

    if (slotsMinigameDTO == 0) {
        v4 = v3->unk_60;
        v1 = (4 * 1);
    } else {
        v4 = &v3->unk_60[(4 * 1)];
        v1 = (4 * 1);
    }

    for (v0 = 0; v0 < v1; v0++, v4++) {
        v5 = OverworldAnimManager_GetFuncsContext(*v4);
        v5->coins = 1;

        Simple3D_FreeAnimObject(&v5->slotMachineVariant);
        Simple3D_ZeroOutAnimation(&v5->slotMachineVariant);
        FieldEffectManager_ApplyAnimCopyToModel(v2, &v5->slotMachineVariant, &v5->unk_7C.slotMachineVariant->slotMachineVariant, &v5->unk_7C.slotMachineVariant->unk_3C, 0);
        Simple3D_CreateRenderObjectWithAnim(&v5->unk_28, &v5->unk_7C.slotMachineVariant->slotMachineVariant, &v5->slotMachineVariant);
    }
}

static int ov5_021F41F0(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_021F4234 *v0 = slotsMinigameDTO;
    const UnkStruct_021F41F0 *v1 = OverworldAnimManager_GetUserData(param0);

    v0->unk_7C = *v1;

    FieldEffectManager_ApplyAnimCopyToModel(v0->unk_7C.coins, &v0->slotMachineVariant, &v0->unk_7C.slotMachineVariant->slotMachineVariant, &v0->unk_7C.slotMachineVariant->unk_18, 0);
    Simple3D_CreateRenderObjectWithAnim(&v0->unk_28, &v0->unk_7C.slotMachineVariant->slotMachineVariant, &v0->slotMachineVariant);

    return 1;
}

static void ov5_021F4234(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_021F4234 *v0 = slotsMinigameDTO;
    Simple3D_FreeAnimation(&v0->slotMachineVariant);
}

static void ov5_021F4240(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    int v0 = 1;
    UnkStruct_021F4234 *v1 = slotsMinigameDTO;

    if (v1->coins == 1) {
        if (Simple3D_HasAnimationReachedEnd(&v1->slotMachineVariant) == 1) {
            FieldEffectManager_FinishAnimManager(param0);
            return;
        }

        v0 = 0;
    }

    Simple3D_UpdateAnim(&v1->slotMachineVariant, FX32_ONE, v0);
}

static void ov5_021F4270(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    VecFx32 v0;
    UnkStruct_021F4234 *v1 = slotsMinigameDTO;

    OverworldAnimManager_GetPosition(param0, &v0);
    Simple3D_DrawRenderObjWithPos(&v1->unk_28, &v0);
}

static const OverworldAnimManagerFuncs Unk_ov5_022006C8 = {
    (sizeof(UnkStruct_021F4234)),
    ov5_021F41F0,
    ov5_021F4234,
    ov5_021F4240,
    ov5_021F4270
};
