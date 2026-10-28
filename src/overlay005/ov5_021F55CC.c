#include "overlay005/ov5_021F55CC.h"

#include <nitro.h>
#include <string.h>

#include "field/field_system.h"
#include "overlay005/field_effect_manager.h"

#include "fx_util.h"
#include "overworld_anim_manager.h"
#include "simple3d.h"
#include "sound_playback.h"

#include "res/graphics/field_effects/field_effects.naix"

typedef struct {
    FieldEffectManager *coins;
    Simple3DModel slotMachineVariant;
    Simple3DAnimation unk_18;
} UnkStruct_ov5_021F55F8;

typedef struct {
    FieldEffectManager *coins;
    UnkStruct_ov5_021F55F8 *slotMachineVariant;
} UnkStruct_ov5_021F5634;

typedef struct {
    Simple3DAnimation coins;
    Simple3DRenderObj unk_24;
    UnkStruct_ov5_021F5634 unk_78;
} UnkStruct_ov5_021F5684;

static void ov5_021F55F8(UnkStruct_ov5_021F55F8 *param0);
static void ov5_021F5620(UnkStruct_ov5_021F55F8 *param0);

static const OverworldAnimManagerFuncs Unk_ov5_02200B1C;

void *ov5_021F55CC(FieldEffectManager *param0)
{
    UnkStruct_ov5_021F55F8 *v0 = FieldEffectManager_HeapAllocInit(param0, (sizeof(UnkStruct_ov5_021F55F8)), 0, 0);
    v0->coins = param0;

    ov5_021F55F8(v0);
    return v0;
}

void ov5_021F55E8(void *param0)
{
    UnkStruct_ov5_021F55F8 *v0 = param0;

    ov5_021F5620(v0);
    FieldEffectManager_HeapFree(v0);
}

static void ov5_021F55F8(UnkStruct_ov5_021F55F8 *param0)
{
    FieldEffectManager_LoadModel(param0->coins, &param0->slotMachineVariant, 0, ug_effect_smoke_nsbmd, 0);
    FieldEffectManager_LoadAnimation(param0->coins, &param0->unk_18, 0, ug_effect_smoke_nsbtp, 0);
}

static void ov5_021F5620(UnkStruct_ov5_021F55F8 *param0)
{
    Simple3D_FreeModel(&param0->slotMachineVariant);
    Simple3D_FreeAnimation(&param0->unk_18);
}

void ov5_021F5634(FieldSystem *fieldSystem, int x, int unused, int z)
{
    UnkStruct_ov5_021F5634 v2;
    VecFx32 v3;

    v2.coins = fieldSystem->fieldEffMan;
    v2.slotMachineVariant = FieldEffectManager_GetRendererContext(v2.coins, 8);

    v3.x = ((x << 4) * FX32_ONE) + (FX32_ONE * 8);
    v3.y = (FX32_ONE * 10);
    v3.z = ((z << 4) * FX32_ONE);

    FieldEffectManager_InitAnimManager(v2.coins, &Unk_ov5_02200B1C, &v3, 0, &v2, 0xff);
    Sound_PlayEffect(SEQ_SE_DP_WIN_OPEN2_sseq);
}

static int ov5_021F5684(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F5684 *v0 = slotsMinigameDTO;
    const UnkStruct_ov5_021F5634 *v1 = OverworldAnimManager_GetUserData(param0);

    v0->unk_78 = *v1;

    FieldEffectManager_ApplyAnimCopyToModel(v0->unk_78.coins, &v0->coins, &v0->unk_78.slotMachineVariant->slotMachineVariant, &v0->unk_78.slotMachineVariant->unk_18, 0);
    Simple3D_CreateRenderObjectWithAnim(&v0->unk_24, &v0->unk_78.slotMachineVariant->slotMachineVariant, &v0->coins);

    return 1;
}

static void ov5_021F56BC(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F5684 *v0 = slotsMinigameDTO;
    Simple3D_FreeAnimation(&v0->coins);
}

static void ov5_021F56C8(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F5684 *v0 = slotsMinigameDTO;

    if (Simple3D_HasAnimationReachedEnd(&v0->coins) == 1) {
        FieldEffectManager_FinishAnimManager(param0);
        return;
    }

    Simple3D_UpdateAnim(&v0->coins, FX32_ONE, 0);
}

static void ov5_021F56F0(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F5684 *v0 = slotsMinigameDTO;

    {
        VecFx32 v1, v2 = { FX32_ONE, FX32_ONE, FX32_ONE };
        MtxFx33 v3 = { FX32_ONE, 0, 0, 0, FX32_ONE, 0, 0, 0, FX32_ONE };
        const MtxFx43 *v4 = NNS_G3dGlbGetInvCameraMtx();
        MtxFx33 v5;

        MTX_Rot33Angles(&v3, 90, 0, 0);

        MTX_Copy43To33(v4, &v5);
        MTX_Concat33(&v3, &v5, &v3);

        OverworldAnimManager_GetPosition(param0, &v1);
        Simple3D_DrawRenderObj(&v0->unk_24, &v1, &v2, &v3);
    }
}

static const OverworldAnimManagerFuncs Unk_ov5_02200B1C = {
    sizeof(UnkStruct_ov5_021F5684),
    ov5_021F5684,
    ov5_021F56BC,
    ov5_021F56C8,
    ov5_021F56F0
};
