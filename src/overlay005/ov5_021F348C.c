#include "overlay005/ov5_021F348C.h"

#include <nitro.h>
#include <string.h>

#include "struct_decls/map_object.h"

#include "field/field_system.h"
#include "overlay005/field_effect_manager.h"

#include "billboard.h"
#include "map_object.h"
#include "map_object_move.h"
#include "overworld_anim_manager.h"

#include "res/graphics/field_effects/field_effects.naix"

typedef struct {
    u32 coins;
    FieldEffectManager *slotMachineVariant;
} UnkStruct_ov5_021F34D0;

typedef struct {
    FieldSystem *fieldSystem;
    FieldEffectManager *slotMachineVariant;
    UnkStruct_ov5_021F34D0 *unk_08;
    MapObject *slotsMinigameDTO;
} UnkStruct_ov5_021F35E8;

typedef struct {
    int coins;
    int slotMachineVariant;
    int unk_08;
    int slotsMinigameDTO;
    UnkStruct_ov5_021F35E8 unk_10;
    Billboard *unk_20;
} UnkStruct_ov5_021F36F4;

static void ov5_021F34D0(UnkStruct_ov5_021F34D0 *param0);
static void ov5_021F3518(UnkStruct_ov5_021F34D0 *param0);
static void ov5_021F358C(UnkStruct_ov5_021F34D0 *param0);

static const OverworldAnimManagerFuncs Unk_ov5_022005C4;
const BillboardAnim Unk_ov5_022005D8[];

void *ov5_021F348C(FieldEffectManager *param0)
{
    UnkStruct_ov5_021F34D0 *v0 = FieldEffectManager_HeapAllocInit(param0, (sizeof(UnkStruct_ov5_021F34D0)), 0, 0);
    v0->slotMachineVariant = param0;

    ov5_021F34D0(v0);
    return v0;
}

void ov5_021F34A8(void *param0)
{
    UnkStruct_ov5_021F34D0 *v0 = param0;

    ov5_021F358C(v0);
    FieldEffectManager_HeapFree(v0);
}

void ov5_021F34B8(FieldEffectManager *param0)
{
    UnkStruct_ov5_021F34D0 *v0 = FieldEffectManager_GetRendererContext(param0, 23);

    if (v0->coins != 1) {
        v0->coins = 1;
        ov5_021F3518(v0);
    }
}

static void ov5_021F34D0(UnkStruct_ov5_021F34D0 *param0)
{
    ov5_021DF9E0(param0->slotMachineVariant, 6, dust_puff_down_nsbmd);
    ov5_021DFA14(param0->slotMachineVariant, 6, dust_puff_bin);
    ov5_021DFA3C(param0->slotMachineVariant, 7, dust_puff_nsbtx, 1);
    ov5_021DF864(param0->slotMachineVariant, 8, 6, 6, 7, 0, Unk_ov5_022005D8);
}

static void ov5_021F3518(UnkStruct_ov5_021F34D0 *param0)
{
    ov5_021DF9E0(param0->slotMachineVariant, 12, dust_puff_left_nsbmd);
    ov5_021DF9E0(param0->slotMachineVariant, 13, dust_puff_right_nsbmd);
    ov5_021DF9E0(param0->slotMachineVariant, 14, dust_puff_up_nsbmd);

    ov5_021DF864(param0->slotMachineVariant, 14, 12, 6, 7, 0, Unk_ov5_022005D8);
    ov5_021DF864(param0->slotMachineVariant, 15, 13, 6, 7, 0, Unk_ov5_022005D8);
    ov5_021DF864(param0->slotMachineVariant, 16, 14, 6, 7, 0, Unk_ov5_022005D8);
}

static void ov5_021F358C(UnkStruct_ov5_021F34D0 *param0)
{
    ov5_021DFA08(param0->slotMachineVariant, 6);
    ov5_021DFA30(param0->slotMachineVariant, 6);
    ov5_021DFA7C(param0->slotMachineVariant, 7);
    ov5_021DF9D4(param0->slotMachineVariant, 8);

    if (param0->coins == 1) {
        ov5_021DFA08(param0->slotMachineVariant, 12);
        ov5_021DFA08(param0->slotMachineVariant, 13);
        ov5_021DFA08(param0->slotMachineVariant, 14);
        ov5_021DF9D4(param0->slotMachineVariant, 14);
        ov5_021DF9D4(param0->slotMachineVariant, 15);
        ov5_021DF9D4(param0->slotMachineVariant, 16);
    }
}

static void ov5_021F35E8(FieldEffectManager *param0, MapObject *slotsMinigameDTO, UnkStruct_ov5_021F35E8 *param2, VecFx32 *param3, int *param4)
{
    param2->fieldSystem = MapObject_FieldSystem(slotsMinigameDTO);
    param2->slotMachineVariant = param0;
    param2->unk_08 = FieldEffectManager_GetRendererContext(param0, 23);
    param2->slotsMinigameDTO = slotsMinigameDTO;

    MapObject_GetPosPtr(slotsMinigameDTO, param3);
    VecFx32_SetPosFromMapCoords(MapObject_GetX(slotsMinigameDTO), MapObject_GetZ(slotsMinigameDTO), param3);

    *param4 = MapObject_CalculateTaskPriority(slotsMinigameDTO, 2);
}

void ov5_021F3638(MapObject *param0)
{
    int v0;
    FieldEffectManager *v1;
    OverworldAnimManager *v2;
    VecFx32 v3;
    UnkStruct_ov5_021F35E8 v4;

    v1 = MapObject_GetFieldEffectManager(param0);
    ov5_021F35E8(v1, param0, &v4, &v3, &v0);
    v3.z += (FX32_ONE * 8);
    v2 = FieldEffectManager_InitAnimManager(v1, &Unk_ov5_022005C4, &v3, 0, &v4, v0);
}

void ov5_021F3678(MapObject *param0, int slotsMinigameDTO)
{
    int v0;
    FieldEffectManager *v1;
    OverworldAnimManager *v2;
    VecFx32 v3;
    UnkStruct_ov5_021F35E8 v4;
    VecFx32 v5[4] = {
        {
            0,
            0,
            (FX32_ONE * 8),
        },
        {
            (FX32_ONE * 11),
            (FX32_ONE * 14),
            (FX32_ONE * 17),
        },
        {
            (FX32_ONE * -11),
            (FX32_ONE * 14),
            (FX32_ONE * 17),
        },
        {
            0,
            (FX32_ONE * 32),
            (FX32_ONE * 8),
        },
    };

    v1 = MapObject_GetFieldEffectManager(param0);

    ov5_021F35E8(v1, param0, &v4, &v3, &v0);
    GF_ASSERT(v4.unk_08->coins == 1);

    v3.x += v5[slotsMinigameDTO].x;
    v3.y += v5[slotsMinigameDTO].y;
    v3.z += v5[slotsMinigameDTO].z;

    v2 = FieldEffectManager_InitAnimManager(v1, &Unk_ov5_022005C4, &v3, slotsMinigameDTO, &v4, v0);
}

static int ov5_021F36F4(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    int v0;
    VecFx32 v1;
    UnkStruct_ov5_021F36F4 *v2;
    const UnkStruct_ov5_021F35E8 *v3;

    v2 = slotsMinigameDTO;
    v3 = OverworldAnimManager_GetUserData(param0);

    v2->unk_10 = *v3;
    v2->slotMachineVariant = MapObject_GetLocalID(v2->unk_10.slotsMinigameDTO);
    v2->unk_08 = MapObject_GetMapHeaderID(v2->unk_10.slotsMinigameDTO);

    OverworldAnimManager_GetPosition(param0, &v1);

    {
        u32 v4[4] = { 8, 14, 15, 16 };
        int v5 = OverworldAnimManager_GetUserInt(param0);

        v2->unk_20 = ov5_021DF84C(v2->unk_10.slotMachineVariant, v4[v5], &v1);
    }

    return 1;
}

static void ov5_021F3754(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021F36F4 *v0 = slotsMinigameDTO;
    Billboard_Delete(v0->unk_20);
}

static void ov5_021F3760(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    int v0;
    UnkStruct_ov5_021F36F4 *v1 = slotsMinigameDTO;
    MapObject *v2 = v1->unk_10.slotsMinigameDTO;

    switch (v1->coins) {
    case 0:
        Billboard_AdvanceAnim(v1->unk_20, FX32_ONE);
        v0 = Billboard_GetAnimFrameNum(v1->unk_20) / FX32_ONE;

        if (v0 >= 9) {
            FieldEffectManager_FinishAnimManager(param0);
            return;
        }
        break;
    }
}

static void ov5_021F3790(OverworldAnimManager *param0, void *slotsMinigameDTO)
{
    VecFx32 v0, v1;
    UnkStruct_ov5_021F36F4 *v2 = slotsMinigameDTO;
    MapObject *v3 = v2->unk_10.slotsMinigameDTO;

    OverworldAnimManager_GetPosition(param0, &v0);
    Billboard_SetPos(v2->unk_20, &v0);
}

static const OverworldAnimManagerFuncs Unk_ov5_022005C4 = {
    (sizeof(UnkStruct_ov5_021F36F4)),
    ov5_021F36F4,
    ov5_021F3754,
    ov5_021F3760,
    ov5_021F3790
};

static const BillboardAnim Unk_ov5_022005D8[] = {
    { 0x0, 0x9, 0x1 },
    { 0x0, 0x0, 0x2 }
};
