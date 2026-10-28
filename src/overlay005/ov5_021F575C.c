#include "overlay005/ov5_021F575C.h"

#include <nitro.h>
#include <string.h>

#include "field/field_system.h"
#include "overlay005/field_effect_manager.h"

#include "overworld_anim_manager.h"
#include "simple3d.h"

#include "res/graphics/field_effects/field_effects.naix"

typedef struct {
    int coins;
    FieldEffectManager *slotMachineVariant;
    Simple3DModel unk_08;
    Simple3DAnimation unk_1C;
} UnkStruct_021F5788;

typedef struct {
    FieldEffectManager *coins;
    UnkStruct_021F5788 *slotMachineVariant;
} UnkStruct_ov5_021F57C8;

typedef struct {
    Simple3DAnimation coins;
    Simple3DRenderObj unk_24;
    UnkStruct_ov5_021F57C8 unk_78;
} UnkStruct_ov5_021F580C;

static void ov5_021F5788(UnkStruct_021F5788 *param0);
static void ov5_021F57B4(UnkStruct_021F5788 *param0);

static const OverworldAnimManagerFuncs Unk_ov5_02200B54;

void *ov5_021F575C(FieldEffectManager *param0)
{
    UnkStruct_021F5788 *v0 = FieldEffectManager_HeapAllocInit(param0, (sizeof(UnkStruct_021F5788)), 0, 0);
    v0->slotMachineVariant = param0;

    ov5_021F5788(v0);
    return v0;
}

void ov5_021F5778(void *param0)
{
    UnkStruct_021F5788 *v0 = param0;

    ov5_021F57B4(v0);
    FieldEffectManager_HeapFree(v0);
}

static void ov5_021F5788(UnkStruct_021F5788 *param0)
{
    FieldEffectManager_LoadModel(param0->slotMachineVariant, &param0->unk_08, 0, gflash_nsbmd, 0);
    FieldEffectManager_LoadAnimation(param0->slotMachineVariant, &param0->unk_1C, 0, gflash_nsbtp, 0);
}

static void ov5_021F57B4(UnkStruct_021F5788 *param0)
{
    Simple3D_FreeModel(&param0->unk_08);
    Simple3D_FreeAnimation(&param0->unk_1C);
}

void ov5_DisplayBuriedSphereSparkle(FieldSystem *fieldSystem, int x, int z)
{
    UnkStruct_ov5_021F57C8 v2;
    VecFx32 v3;

    v2.coins = fieldSystem->fieldEffMan;
    v2.slotMachineVariant = FieldEffectManager_GetRendererContext(v2.coins, 9);

    v3.x = ((x << 4) * FX32_ONE) + ((16 * FX32_ONE) >> 1);
    v3.y = 0;
    v3.z = ((z << 4) * FX32_ONE) + ((16 * FX32_ONE) >> 1);

    FieldEffectManager_InitAnimManager(v2.coins, &Unk_ov5_02200B54, &v3, 0, &v2, 0xff);
}

static int ov5_021F580C(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F580C *v0 = slotsMinigameDTO;
    const UnkStruct_ov5_021F57C8 *v1 = OverworldAnimManager_GetUserData(param0);

    v0->unk_78 = *v1;

    FieldEffectManager_ApplyAnimCopyToModel(v0->unk_78.coins, &v0->coins, &v0->unk_78.slotMachineVariant->unk_08, &v0->unk_78.slotMachineVariant->unk_1C, 0);
    Simple3D_CreateRenderObjectWithAnim(&v0->unk_24, &v0->unk_78.slotMachineVariant->unk_08, &v0->coins);

    return 1;
}

static void ov5_021F5844(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F580C *v0 = slotsMinigameDTO;
    Simple3D_FreeAnimation(&v0->coins);
}

static void ov5_021F5850(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F580C *v0 = slotsMinigameDTO;

    if (Simple3D_HasAnimationReachedEnd(&v0->coins) == 1) {
        FieldEffectManager_FinishAnimManager(param0);
        return;
    }

    Simple3D_UpdateAnim(&v0->coins, FX32_ONE, 0);
}

static void ov5_021F5878(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    VecFx32 v0;
    UnkStruct_ov5_021F580C *v1 = slotsMinigameDTO;

    OverworldAnimManager_GetPosition(param0, &v0);
    Simple3D_DrawRenderObjWithPos(&v1->unk_24, &v0);
}

static const OverworldAnimManagerFuncs Unk_ov5_02200B54 = {
    (sizeof(UnkStruct_ov5_021F580C)),
    ov5_021F580C,
    ov5_021F5844,
    ov5_021F5850,
    ov5_021F5878
};
