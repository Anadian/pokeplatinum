#include "overlay005/ov5_021F2BD0.h"

#include <nitro.h>
#include <string.h>

#include "struct_decls/map_object.h"

#include "overlay005/field_effect_manager.h"

#include "map_object.h"
#include "map_object_move.h"
#include "overworld_anim_manager.h"
#include "simple3d.h"

#include "res/graphics/field_effects/field_effects.naix"

typedef struct {
    FieldEffectManager *coins;
    Simple3DModel slotMachineVariant;
    Simple3DAnimation unk_18;
} UnkStruct_ov5_021F2BFC;

typedef struct {
    FieldEffectManager *coins;
    UnkStruct_ov5_021F2BFC *slotMachineVariant;
} UnkStruct_ov5_021F2C38;

typedef struct {
    Simple3DAnimation coins;
    Simple3DRenderObj unk_24;
    UnkStruct_ov5_021F2C38 unk_78;
} UnkStruct_ov5_021F2C98;

static void ov5_021F2BFC(UnkStruct_ov5_021F2BFC *param0);
static void ov5_021F2C24(UnkStruct_ov5_021F2BFC *param0);

static const OverworldAnimManagerFuncs Unk_ov5_022004D8;

void *ov5_021F2BD0(FieldEffectManager *param0)
{
    UnkStruct_ov5_021F2BFC *v0 = FieldEffectManager_HeapAllocInit(param0, (sizeof(UnkStruct_ov5_021F2BFC)), 0, 0);
    v0->coins = param0;

    ov5_021F2BFC(v0);
    return v0;
}

void ov5_021F2BEC(void *param0)
{
    UnkStruct_ov5_021F2BFC *v0 = param0;

    ov5_021F2C24(v0);
    FieldEffectManager_HeapFree(v0);
}

static void ov5_021F2BFC(UnkStruct_ov5_021F2BFC *param0)
{
    FieldEffectManager_LoadModel(param0->coins, &param0->slotMachineVariant, 0, swamp_ripple_nsbmd, 0);
    FieldEffectManager_LoadAnimation(param0->coins, &param0->unk_18, 0, swamp_ripple_nsbtp, 0);
}

static void ov5_021F2C24(UnkStruct_ov5_021F2BFC *param0)
{
    Simple3D_FreeModel(&param0->slotMachineVariant);
    Simple3D_FreeAnimation(&param0->unk_18);
}

void ov5_021F2C38(MapObject *param0, int slotsMinigameDTO, int param2, int param3)
{
    int v0, v1;
    UnkStruct_ov5_021F2C38 v2;
    VecFx32 v3;

    v2.coins = MapObject_GetFieldEffectManager(param0);
    v2.slotMachineVariant = FieldEffectManager_GetRendererContext(v2.coins, 18);

    VecFx32_SetPosFromMapCoords(slotsMinigameDTO, param3, &v3);

    v3.z += ((param2) << 3) + (FX32_ONE * 0);
    v3.y = (((MapObject_GetYPrev(param0)) << 3) * FX32_ONE) + (-FX32_ONE * 8);

    v1 = 0;
    v0 = MapObject_CalculateTaskPriority(param0, 2);

    FieldEffectManager_InitAnimManager(v2.coins, &Unk_ov5_022004D8, &v3, v1, &v2, v0);
}

static int ov5_021F2C98(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F2C98 *v0 = slotsMinigameDTO;
    const UnkStruct_ov5_021F2C38 *v1 = OverworldAnimManager_GetUserData(param0);

    v0->unk_78 = *v1;

    FieldEffectManager_ApplyAnimCopyToModel(v0->unk_78.coins, &v0->coins, &v0->unk_78.slotMachineVariant->slotMachineVariant, &v0->unk_78.slotMachineVariant->unk_18, 0);
    Simple3D_CreateRenderObjectWithAnim(&v0->unk_24, &v0->unk_78.slotMachineVariant->slotMachineVariant, &v0->coins);

    return 1;
}

static void ov5_021F2CD0(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F2C98 *v0 = slotsMinigameDTO;
    Simple3D_FreeAnimation(&v0->coins);
}

static void ov5_021F2CDC(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F2C98 *v0 = slotsMinigameDTO;

    if (Simple3D_HasAnimationReachedEnd(&v0->coins) == 1) {
        FieldEffectManager_FinishAnimManager(param0);
        return;
    }

    Simple3D_UpdateAnim(&v0->coins, FX32_ONE, 0);
}

static void ov5_021F2D04(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    VecFx32 v0;
    UnkStruct_ov5_021F2C98 *v1 = slotsMinigameDTO;

    OverworldAnimManager_GetPosition(param0, &v0);
    Simple3D_DrawRenderObjWithPos(&v1->unk_24, &v0);
}

static const OverworldAnimManagerFuncs Unk_ov5_022004D8 = {
    sizeof(UnkStruct_ov5_021F2C98),
    ov5_021F2C98,
    ov5_021F2CD0,
    ov5_021F2CDC,
    ov5_021F2D04
};
