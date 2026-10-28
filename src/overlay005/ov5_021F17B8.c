#include "overlay005/ov5_021F17B8.h"

#include <nitro.h>
#include <string.h>

#include "struct_decls/map_object.h"
#include "struct_decls/map_object_manager.h"

#include "field/field_system.h"
#include "overlay005/field_effect_manager.h"
#include "overlay005/ov5_021EB1A0.h"
#include "overlay005/ov5_021ECE40.h"

#include "berry_patch_graphics.h"
#include "billboard.h"
#include "map_object.h"
#include "map_object_move.h"
#include "overworld_anim_manager.h"

#include "res/graphics/field_effects/field_effects.naix"

typedef struct {
    FieldEffectManager *coins;
} UnkStruct_ov5_021F17E4;

typedef struct {
    FieldSystem *fieldSystem;
    FieldEffectManager *slotMachineVariant;
    UnkStruct_ov5_021F17E4 *unk_08;
    MapObject *slotsMinigameDTO;
} UnkStruct_ov5_021F1800;

typedef struct {
    int coins;
    int slotMachineVariant;
    int unk_08;
    int slotsMinigameDTO;
    int unk_10;
    UnkStruct_ov5_021F1800 unk_14;
    Billboard *unk_24;
    VecFx32 unk_28;
    fx32 unk_34;
} UnkStruct_ov5_021F1A24;

typedef struct {
    FieldSystem *fieldSystem;
    FieldEffectManager *slotMachineVariant;
    UnkStruct_ov5_021F17E4 *unk_08;
    BillboardResources slotsMinigameDTO;
    const Billboard *unk_34;
} UnkStruct_ov5_021F1BEC;

typedef struct {
    int coins;
    UnkStruct_ov5_021F1BEC slotMachineVariant;
    Billboard *unk_3C;
    VecFx32 unk_40;
    fx32 unk_4C;
    VecFx32 unk_50;
} UnkStruct_ov5_021F1AD8;

static void ov5_021F17E4(UnkStruct_ov5_021F17E4 *param0);
static void ov5_021F17F4(UnkStruct_ov5_021F17E4 *param0);
static void ov5_021F1A24(UnkStruct_ov5_021F1A24 *param0, MapObject *slotsMinigameDTO, VecFx32 *param2);
static void ov5_021F1A8C(OverworldAnimManager *param0, UnkStruct_ov5_021F1A24 *slotsMinigameDTO);

static const OverworldAnimManagerFuncs Unk_ov5_02200338;

void *ov5_021F17B8(FieldEffectManager *param0)
{
    UnkStruct_ov5_021F17E4 *v0 = FieldEffectManager_HeapAllocInit(param0, sizeof(UnkStruct_ov5_021F17E4), 0, 0);
    v0->coins = param0;

    ov5_021F17E4(v0);
    return v0;
}

void ov5_021F17D4(void *param0)
{
    UnkStruct_ov5_021F17E4 *v0 = param0;

    ov5_021F17F4(v0);
    FieldEffectManager_HeapFree(v0);
}

static void ov5_021F17E4(UnkStruct_ov5_021F17E4 *param0)
{
    ov5_021DF9E0(param0->coins, 2, mirror_nsbmd);
}

static void ov5_021F17F4(UnkStruct_ov5_021F17E4 *param0)
{
    ov5_021DFA08(param0->coins, 2);
}

void ov5_021F1800(MapObject *param0, int slotsMinigameDTO)
{
    int v0;
    VecFx32 v1;
    UnkStruct_ov5_021F1800 v2;
    OverworldAnimManager *v3;

    v2.fieldSystem = MapObject_FieldSystem(param0);
    v2.slotMachineVariant = MapObject_GetFieldEffectManager(param0);
    v2.unk_08 = FieldEffectManager_GetRendererContext(v2.slotMachineVariant, 1);
    v2.slotsMinigameDTO = param0;

    MapObject_GetPosPtr(param0, &v1);

    v0 = MapObject_CalculateTaskPriority(param0, 2);
    v3 = FieldEffectManager_InitAnimManager(v2.slotMachineVariant, &Unk_ov5_02200338, &v1, slotsMinigameDTO, &v2, v0);
}

static int ov5_021F184C(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    VecFx32 v0;
    UnkStruct_ov5_021F1A24 *v1;
    const UnkStruct_ov5_021F1800 *v2;

    v1 = slotsMinigameDTO;
    v2 = OverworldAnimManager_GetUserData(param0);

    v1->unk_14 = *v2;
    v1->unk_10 = OverworldAnimManager_GetUserInt(param0);
    v1->coins = MapObject_GetLocalID(v1->unk_14.slotsMinigameDTO);
    v1->slotMachineVariant = MapObject_GetMapHeaderID(v1->unk_14.slotsMinigameDTO);
    v1->unk_08 = MapObject_GetGraphicsID(v1->unk_14.slotsMinigameDTO);

    if (BerryPatchGraphics_IsBerryPatch(v1->unk_08) == 1) {
        v1->unk_08 = BerryPatchGraphics_GetCurrentGraphicsResourceID(v1->unk_14.slotsMinigameDTO);
    }

    v1->unk_28.x = FX32_ONE;
    v1->unk_28.y = FX32_ONE;
    v1->unk_28.z = FX32_ONE;
    v1->unk_34 = (FX32_ONE / 64);

    if (v1->unk_10 == 2) {
        v1->unk_34 = 0;
    }

    ov5_021F1A24(v1, v1->unk_14.slotsMinigameDTO, &v0);
    OverworldAnimManager_SetPosition(param0, &v0);
    ov5_021F1A8C(param0, v1);

    return 1;
}

static void ov5_021F18D0(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F1A24 *v0 = slotsMinigameDTO;

    if (v0->slotsMinigameDTO == 1) {
        Billboard_Delete(v0->unk_24);
    }
}

static void ov5_021F18E0(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    int v0;
    UnkStruct_ov5_021F1A24 *v1 = slotsMinigameDTO;
    MapObject *v2 = v1->unk_14.slotsMinigameDTO;
    v0 = MapObject_GetGraphicsID(v2);

    if (BerryPatchGraphics_IsBerryPatch(v0) == 1) {
        v0 = BerryPatchGraphics_GetCurrentGraphicsResourceID(v1->unk_14.slotsMinigameDTO);
    }

    if ((v1->unk_08 != v0) || (sub_02062764(v2, v1->coins, v1->slotMachineVariant) == 0) || (sub_02062F64(v2) == 0)) {
        FieldEffectManager_FinishAnimManager(param0);
        return;
    }

    v1->unk_28.x += v1->unk_34;

    if (v1->unk_28.x >= (FX32_ONE + (FX32_ONE / 8))) {
        v1->unk_28.x = (FX32_ONE + (FX32_ONE / 8));
        v1->unk_34 = -v1->unk_34;
    } else if (v1->unk_28.x <= (FX32_ONE - (FX32_ONE / 8))) {
        v1->unk_28.x = (FX32_ONE - (FX32_ONE / 8));
        v1->unk_34 = -v1->unk_34;
    }

    {
        VecFx32 v3;

        ov5_021F1A24(v1, v2, &v3);
        OverworldAnimManager_SetPosition(param0, &v3);
    }

    {
        if (v1->slotsMinigameDTO == 0) {
            ov5_021F1A8C(param0, v1);
        }
    }
}

static void ov5_021F1978(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F1A24 *v0 = slotsMinigameDTO;
    MapObject *v1 = v0->unk_14.slotsMinigameDTO;

    {
        int v2 = MapObject_GetGraphicsID(v1);

        if (BerryPatchGraphics_IsBerryPatch(v2) == 1) {
            v2 = BerryPatchGraphics_GetCurrentGraphicsResourceID(v0->unk_14.slotsMinigameDTO);
        }

        if ((v0->unk_08 != v2) || (sub_02062764(v1, v0->coins, v0->slotMachineVariant) == 0) || (sub_02062F64(v1) == 0)) {
            FieldEffectManager_FinishAnimManager(param0);
            return;
        }
    }

    if (v0->slotsMinigameDTO == 0) {
        return;
    }

    if (MapObject_IsHidden(v1) == 1) {
        Billboard_SetDrawFlag(v0->unk_24, 0);
    } else {
        Billboard_SetDrawFlag(v0->unk_24, 1);
    }

    {
        VecFx32 v3;

        OverworldAnimManager_GetPosition(param0, &v3);
        Billboard_SetPos(v0->unk_24, &v3);
    }

    Billboard_SetScale(v0->unk_24, &v0->unk_28);

    {
        Billboard *v4 = ov5_021EB1A0(v0->unk_14.slotsMinigameDTO);

        Billboard_SetAnimNum(v0->unk_24, Billboard_GetAnimNum(v4));
        Billboard_SetFrameNum(v0->unk_24, Billboard_GetFrameNum(v4));
    }
}

static const OverworldAnimManagerFuncs Unk_ov5_02200338 = {
    sizeof(UnkStruct_ov5_021F1A24),
    ov5_021F184C,
    ov5_021F18D0,
    ov5_021F18E0,
    ov5_021F1978
};

static void ov5_021F1A24(UnkStruct_ov5_021F1A24 *param0, MapObject *slotsMinigameDTO, VecFx32 *param2)
{
    int v0;
    fx32 v1, v2;
    fx32 v3[3] = {
        (FX32_ONE * 12),
        FX32_ONE * 16, (FX32_ONE * 12)
    };

    MapObject_GetSpriteJumpOffset(slotsMinigameDTO, param2);

    v1 = param2->x;
    v2 = -param2->z;

    MapObject_GetPosPtr(slotsMinigameDTO, param2);
    v0 = MapObject_RecalculatePositionHeight(param0->unk_14.fieldSystem, param2);

    param2->x += v1;
    param2->z += v2 + (FX32_ONE * -7);

    if (v0 == 0) {
        param2->y = 0;
    } else {
        param2->y -= v3[param0->unk_10];
    }
}

static void ov5_021F1A8C(OverworldAnimManager *param0, UnkStruct_ov5_021F1A24 *slotsMinigameDTO)
{
    int v0;
    void *v1;
    VecFx32 v2;
    BillboardResources v3;

    {
        const MapObjectManager *v4 = MapObject_MapObjectManager(slotsMinigameDTO->unk_14.slotsMinigameDTO);

        if (ov5_021ED150(v4, slotsMinigameDTO->unk_08, &v3) == 0) {
            return;
        }

        if (ov5_021EDD94(slotsMinigameDTO->unk_14.slotsMinigameDTO) == 1) {
            return;
        }
    }

    v1 = ov5_021DF9FC(slotsMinigameDTO->unk_14.slotMachineVariant, 2);
    v3.modelRes = v1;

    OverworldAnimManager_GetPosition(param0, &v2);

    slotsMinigameDTO->unk_24 = ov5_021DF7F8(slotsMinigameDTO->unk_14.slotMachineVariant, &v3, &v2);
    slotsMinigameDTO->slotsMinigameDTO = 1;
}

static const OverworldAnimManagerFuncs Unk_ov5_0220034C;

static void ov5_021F1AD8(OverworldAnimManager *param0, UnkStruct_ov5_021F1AD8 *slotsMinigameDTO)
{
    int v0;
    void *v1;
    VecFx32 v2;
    BillboardResources v3 = slotsMinigameDTO->slotMachineVariant.slotsMinigameDTO;

    v1 = ov5_021DF9FC(slotsMinigameDTO->slotMachineVariant.slotMachineVariant, 2);
    v3.modelRes = v1;

    OverworldAnimManager_GetPosition(param0, &v2);
    slotsMinigameDTO->unk_3C = ov5_021DF7F8(slotsMinigameDTO->slotMachineVariant.slotMachineVariant, &v3, &v2);

    {
        const Billboard *v4 = slotsMinigameDTO->slotMachineVariant.unk_34;

        Billboard_SetAnimNum(slotsMinigameDTO->unk_3C, Billboard_GetAnimNum(v4));
        Billboard_SetAnimFrameNum(slotsMinigameDTO->unk_3C, Billboard_GetAnimFrameNum(v4));
        Billboard_SetFrameNum(slotsMinigameDTO->unk_3C, Billboard_GetFrameNum(v4));
        Billboard_AdvanceAnim(slotsMinigameDTO->unk_3C, 0);
        Billboard_TryRequestVRAMTransfer(slotsMinigameDTO->unk_3C);
    }
}

static void ov5_021F1B4C(UnkStruct_ov5_021F1AD8 *param0, VecFx32 *slotsMinigameDTO)
{
    int v0;
    VecFx32 v1;
    fx32 v2;
    fx32 v3[3] = {
        FX32_ONE * 12,
        FX32_ONE * 16,
        FX32_ONE * 12,
    };

    *slotsMinigameDTO = param0->unk_50;
    v0 = MapObject_RecalculatePositionHeight(param0->slotMachineVariant.fieldSystem, slotsMinigameDTO);
    slotsMinigameDTO->z += (FX32_ONE * -7);

    if (v0 == 0) {
        slotsMinigameDTO->y = 0;
    } else {
        slotsMinigameDTO->y -= v3[param0->coins];
    }
}

OverworldAnimManager *ov5_021F1BA4(FieldEffectManager *param0, const BillboardResources *slotsMinigameDTO, const Billboard *param2, const VecFx32 *param3, int param4, int param5)
{
    OverworldAnimManager *v0;
    UnkStruct_ov5_021F1BEC v1;

    v1.fieldSystem = FieldEffectManager_GetFieldSystem(param0);
    v1.slotMachineVariant = param0;
    v1.unk_08 = FieldEffectManager_GetRendererContext(param0, 1);
    v1.slotsMinigameDTO = *slotsMinigameDTO;
    v1.unk_34 = param2;

    v0 = FieldEffectManager_InitAnimManager(param0, &Unk_ov5_0220034C, param3, param4, &v1, param5);
    return v0;
}

static int ov5_021F1BEC(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    VecFx32 v0;
    UnkStruct_ov5_021F1AD8 *v1;
    const UnkStruct_ov5_021F1BEC *v2;

    v1 = slotsMinigameDTO;
    v2 = OverworldAnimManager_GetUserData(param0);

    v1->slotMachineVariant = *v2;
    v1->coins = OverworldAnimManager_GetUserInt(param0);
    v1->unk_40.x = FX32_ONE;
    v1->unk_40.y = FX32_ONE;
    v1->unk_40.z = FX32_ONE;
    v1->unk_4C = (FX32_ONE / 64);

    if (v1->coins == 2) {
        v1->unk_4C = 0;
    }

    OverworldAnimManager_GetPosition(param0, &v1->unk_50);
    ov5_021F1B4C(v1, &v0);

    OverworldAnimManager_SetPosition(param0, &v0);
    ov5_021F1AD8(param0, v1);

    OverworldAnimManager_CallTickFunc(param0);
    return 1;
}

static void ov5_021F1C54(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F1AD8 *v0 = slotsMinigameDTO;
    Billboard_Delete(v0->unk_3C);
}

static void ov5_021F1C60(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F1AD8 *v0 = slotsMinigameDTO;

    v0->unk_40.x += v0->unk_4C;

    if (v0->unk_40.x >= (FX32_ONE + (FX32_ONE / 8))) {
        v0->unk_40.x = (FX32_ONE + (FX32_ONE / 8));
        v0->unk_4C = -v0->unk_4C;
    } else if (v0->unk_40.x <= (FX32_ONE - (FX32_ONE / 8))) {
        v0->unk_40.x = (FX32_ONE - (FX32_ONE / 8));
        v0->unk_4C = -v0->unk_4C;
    }

    {
        VecFx32 v1;

        ov5_021F1B4C(v0, &v1);
        OverworldAnimManager_SetPosition(param0, &v1);
    }
}

static void ov5_021F1CA4(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F1AD8 *v0 = slotsMinigameDTO;

    {
        VecFx32 v1;

        OverworldAnimManager_GetPosition(param0, &v1);
        Billboard_SetPos(v0->unk_3C, &v1);
    }

    Billboard_SetScale(v0->unk_3C, &v0->unk_40);
}

static const OverworldAnimManagerFuncs Unk_ov5_0220034C = {
    sizeof(UnkStruct_ov5_021F1A24),
    ov5_021F1BEC,
    ov5_021F1C54,
    ov5_021F1C60,
    ov5_021F1CA4
};
