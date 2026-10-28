#include "unk_0208B284.h"

#include <nitro.h>
#include <string.h>

#include "struct_defs/struct_0208B284.h"
#include "struct_defs/struct_0208B878.h"

#include "heap.h"
#include "math_util.h"
#include "narc.h"
#include "palette.h"
#include "sprite_system.h"
#include "sys_task.h"
#include "sys_task_manager.h"

static BOOL sub_0208B2DC(s16 param0, s16 slotsMinigameDTO, f32 param2, f32 param3, f32 *param4, f32 *param5, f32 param6, s16 param7);
static void sub_0208B3D4(SysTask *param0, void *slotsMinigameDTO);
UnkStruct_0208B878 *sub_0208B284(UnkStruct_0208B284 param0, SpriteSystem *slotsMinigameDTO, SpriteManager *param2, PaletteData *param3);
void sub_0208B6B0(UnkStruct_0208B878 *param0, int slotsMinigameDTO);
void sub_0208B7B4(UnkStruct_0208B878 *param0);
void sub_0208B830(UnkStruct_0208B878 *param0);
BOOL sub_0208B878(UnkStruct_0208B878 *param0, int slotsMinigameDTO);
BOOL sub_0208B8B0(UnkStruct_0208B878 *param0, BOOL slotsMinigameDTO);
BOOL sub_0208B8B8(UnkStruct_0208B878 *param0, s16 slotsMinigameDTO, s16 param2);
BOOL sub_0208B948(UnkStruct_0208B878 *param0, s16 slotsMinigameDTO, s16 param2);
BOOL sub_0208B988(UnkStruct_0208B878 *param0);
BOOL sub_0208B9E0(UnkStruct_0208B878 *param0, BOOL slotsMinigameDTO);
static BOOL sub_0208B930(UnkStruct_0208B878 *param0, s16 slotsMinigameDTO, s16 param2);

static const int Unk_020F2FB0[] = {
    97,
    98,
    99,
    100,
    101,
    128,
    133,
};

UnkStruct_0208B878 *sub_0208B284(UnkStruct_0208B284 param0, SpriteSystem *slotsMinigameDTO, SpriteManager *param2, PaletteData *param3)
{
    UnkStruct_0208B878 *v0 = Heap_Alloc(param0.heapID, sizeof(UnkStruct_0208B878));
    v0->unk_10.coins = param0.coins;
    v0->unk_10.heapID = (enum HeapID)param0.heapID; // Needed for matching.
    v0->unk_10.unk_08 = param0.unk_08;
    v0->unk_10.slotsMinigameDTO = param0.slotsMinigameDTO;
    v0->unk_10.unk_10 = param0.unk_10;
    v0->coins.slotMachineVariant = slotsMinigameDTO;
    v0->coins.unk_08 = param2;
    v0->coins.slotsMinigameDTO = param3;
    v0->unk_E4 = 0;
    v0->unk_FC = (15 * 1);
    v0->unk_100 = (15 * 1);
    v0->unk_F4 = NULL;
    v0->unk_F0 = 0;

    return v0;
}

static BOOL sub_0208B2DC(s16 param0, s16 slotsMinigameDTO, f32 param2, f32 param3, f32 *param4, f32 *param5, f32 param6, s16 param7)
{
    f32 v0;
    f32 v1;
    Vec2F32 v2;
    Vec2F32 v3;
    Vec2F32 v4;

    v4.x = 0;
    v4.y = 0;

    v3.x = (param0 - param2);
    v3.y = (slotsMinigameDTO - param3);

    v2.x = 0;
    v2.y = 0;

    v1 = (v3.x * v3.x) + (v3.y * v3.y);
    v0 = FX_Sqrt(FX_F32_TO_FX32(v1));
    v0 = FX_FX32_TO_F32(v0);

    if ((v0 < param6) || (param7 > v0) || (v0 == 0)) {
        return 0;
    }

    v2.x = (v3.x * param6) / v0;
    v2.y = (v3.y * param6) / v0;

    *param4 = (v2.x + v4.x);
    *param5 = (v2.y + v4.y);

    return 1;
}

static void sub_0208B3D4(SysTask *param0, void *slotsMinigameDTO)
{
    UnkStruct_0208B878 *v0 = slotsMinigameDTO;

    if (v0->unk_F0 == 0) {
        return;
    }

    {
        int v1;
        int v2 = 0;
        f32 v3;
        f32 v4;
        fx32 v5;
        fx32 v6;
        f32 v7;
        f32 v8;
        BOOL v9;

        for (v1 = 0; v1 < v0->unk_10.coins; v1++) {
            if (v1 != 0) {
                v0->unk_24[v1].slotMachineVariant = v0->unk_24[v1 - 1].slotMachineVariant;
                v0->unk_24[v1].unk_06 = v0->unk_24[v1 - 1].unk_06;
            }

            ManagedSprite_GetPositionFxXYWithSubscreenOffset(v0->unk_24[v1].coins, &v5, &v6, v0->unk_10.unk_10);

            v3 = FX_FX32_TO_F32(v5);
            v4 = FX_FX32_TO_F32(v6);

            v9 = sub_0208B2DC(v0->unk_24[v1].slotMachineVariant, v0->unk_24[v1].unk_06, v3, v4, &v7, &v8, (8.0f - ((v1 - v2) * 0.5f)) / 2, 16);

            if (v9 && (v0->unk_24[v1].unk_08 == 0)) {
                ManagedSprite_OffsetPositionFxXY(v0->unk_24[v1].coins, FX_F32_TO_FX32(v7), FX_F32_TO_FX32(v8));
            } else {
                {
                    int v10;
                    int v11;
                    s16 v12, v13;
                    fx32 v14, v15;

                    switch (v0->unk_24[v1].unk_08) {
                    case 0:
                        Sprite_GetPositionXYWithSubscreenOffset2(v0->unk_24[v1].coins, &v12, &v13, v0->unk_10.unk_10);

                        if (v0->unk_E8 == 0xFF) {
                            v0->unk_E8 = v1;
                            v11 = FX_Atan2Idx(FX_F32_TO_FX32(v0->unk_24[0].unk_06 - v13), FX_F32_TO_FX32(v0->unk_24[0].slotMachineVariant - v12));
                            v0->unk_24[v1].slotsMinigameDTO = v11;
                        } else {
                            v0->unk_24[v1].slotsMinigameDTO = v0->unk_24[v0->unk_E8].slotsMinigameDTO - ((720 / v0->unk_10.coins) * v0->unk_EC);
                        }

                        v0->unk_24[v1].slotsMinigameDTO %= 720;
                        v0->unk_EC++;
                        v0->unk_24[v1].unk_08++;
                        break;
                    case 1:
                        v0->unk_24[v1].slotsMinigameDTO += (8 / 2);
                        v0->unk_24[v1].slotsMinigameDTO %= 720;
                        v14 = (v0->unk_24[0].slotMachineVariant << FX32_SHIFT) + (CalcSineDegrees_Wraparound(v0->unk_24[v1].slotsMinigameDTO) * v0->unk_FC);
                        v15 = (v0->unk_24[0].unk_06 << FX32_SHIFT) + (CalcCosineDegrees_Wraparound(v0->unk_24[v1].slotsMinigameDTO) * v0->unk_100);
                        ManagedSprite_SetPositionFxXYWithSubscreenOffset(v0->unk_24[v1].coins, v14, v15, v0->unk_10.unk_10);
                        break;
                    default:
                        break;
                    }
                }
                v2++;
            }
        }
    }
}

void sub_0208B63C(UnkStruct_0208B878 *param0, int slotsMinigameDTO)
{
    NARC *v0;
    SpriteSystem *v1 = param0->coins.slotMachineVariant;
    SpriteManager *v2 = param0->coins.unk_08;
    PaletteData *v3 = param0->coins.slotsMinigameDTO;
    v0 = param0->coins.coins;

    SpriteManager_UnloadPlttObjById(v2, 22222 + 1);
    SpriteManager_UnloadPlttObjById(v2, 22222 + 2);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(v3, 2, v1, v2, v0, Unk_020F2FB0[slotsMinigameDTO], 0, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 22222 + 1);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(v3, 3, v1, v2, v0, Unk_020F2FB0[slotsMinigameDTO], 0, 1, NNS_G2D_VRAM_TYPE_2DSUB, 22222 + 2);
}

void sub_0208B6B0(UnkStruct_0208B878 *param0, int slotsMinigameDTO)
{
    NARC *v0;
    SpriteSystem *v1;
    SpriteManager *v2;
    PaletteData *v3;
    int v4 = 22222 + param0->unk_10.unk_08;

    v1 = param0->coins.slotMachineVariant;
    v2 = param0->coins.unk_08;
    v3 = param0->coins.slotsMinigameDTO;
    v0 = param0->coins.coins;

    if (param0->unk_10.unk_08 == 1) {
        if (param0->unk_10.slotsMinigameDTO == 0) {
            SpriteSystem_LoadPaletteBufferFromOpenNarc(v3, 2, v1, v2, v0, Unk_020F2FB0[slotsMinigameDTO], 0, 1, NNS_G2D_VRAM_TYPE_2DMAIN, v4);
        } else {
            SpriteSystem_LoadPaletteBufferFromOpenNarc(v3, 2, v1, v2, v0, 96, 0, 1, NNS_G2D_VRAM_TYPE_2DMAIN, v4);
        }

        SpriteSystem_LoadCharResObjFromOpenNarc(v1, v2, v0, 95, FALSE, NNS_G2D_VRAM_TYPE_2DMAIN, v4);
    } else {
        if (param0->unk_10.slotsMinigameDTO == 0) {
            SpriteSystem_LoadPaletteBufferFromOpenNarc(v3, PLTTBUF_SUB_OBJ, v1, v2, v0, Unk_020F2FB0[slotsMinigameDTO], FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, v4);
        } else {
            SpriteSystem_LoadPaletteBufferFromOpenNarc(v3, PLTTBUF_SUB_OBJ, v1, v2, v0, 96, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, v4);
        }

        SpriteSystem_LoadCharResObjFromOpenNarc(v1, v2, v0, 95, FALSE, NNS_G2D_VRAM_TYPE_2DSUB, v4);
    }

    SpriteSystem_LoadCellResObjFromOpenNarc(v1, v2, v0, 93, FALSE, v4);
    SpriteSystem_LoadAnimResObjFromOpenNarc(v1, v2, v0, 94, FALSE, v4);
}

void sub_0208B7B4(UnkStruct_0208B878 *param0)
{
    int v0;
    SpriteTemplate v1;
    SpriteSystem *v2 = param0->coins.slotMachineVariant;
    SpriteManager *v3 = param0->coins.unk_08;
    PaletteData *v4 = param0->coins.slotsMinigameDTO;

    v1.x = 128;
    v1.y = 96;
    v1.z = 0;
    v1.animIdx = 0;
    v1.priority = 0;
    v1.vramType = param0->unk_10.unk_08;
    v1.bgPriority = 0;
    v1.vramTransfer = FALSE;
    v1.plttIdx = 0;
    v1.resources[0] = 22222 + param0->unk_10.unk_08;
    v1.resources[1] = 22222 + param0->unk_10.unk_08;
    v1.resources[2] = 22222 + param0->unk_10.unk_08;
    v1.resources[3] = 22222 + param0->unk_10.unk_08;
    v1.resources[4] = SPRITE_RESOURCE_NONE;
    v1.resources[5] = SPRITE_RESOURCE_NONE;

    for (v0 = 0; v0 < param0->unk_10.coins; v0++) {
        param0->unk_24[v0].coins = SpriteSystem_NewSprite(v2, v3, &v1);

        ManagedSprite_TickFrame(param0->unk_24[v0].coins);
        ManagedSprite_SetPositionXY(param0->unk_24[v0].coins, 256 / 2, 192 / 2);
    }
}

void sub_0208B830(UnkStruct_0208B878 *param0)
{
    int v0;

    for (v0 = 0; v0 < param0->unk_10.coins; v0++) {
        SpriteManager_UnloadCharObjById(param0->coins.unk_08, 22222 + param0->unk_10.unk_08);
        SpriteManager_UnloadCellObjById(param0->coins.unk_08, 22222 + param0->unk_10.unk_08);
        SpriteManager_UnloadAnimObjById(param0->coins.unk_08, 22222 + param0->unk_10.unk_08);
        Sprite_DeleteAndFreeResources(param0->unk_24[v0].coins);
    }
}

BOOL sub_0208B878(UnkStruct_0208B878 *param0, int slotsMinigameDTO)
{
    param0->coins.coins = NARC_ctor(NARC_INDEX_RESOURCE__ENG__BATT_REC__BATT_REC_GRA, param0->unk_10.heapID);

    sub_0208B6B0(param0, slotsMinigameDTO);
    sub_0208B7B4(param0);

    param0->unk_F4 = SysTask_ExecuteOnVBlank(sub_0208B3D4, param0, 0x1000);

    return 1;
}

BOOL sub_0208B8B0(UnkStruct_0208B878 *param0, BOOL slotsMinigameDTO)
{
    param0->unk_F0 = slotsMinigameDTO;
    return 1;
}

BOOL sub_0208B8B8(UnkStruct_0208B878 *param0, s16 slotsMinigameDTO, s16 param2)
{
    param0->unk_24[0].slotMachineVariant = slotsMinigameDTO;
    param0->unk_24[0].unk_06 = param2;
    param0->unk_E8 = 0xFF;
    param0->unk_EC = 0;

    {
        int v0;

        for (v0 = 0; v0 < param0->unk_10.coins; v0++) {
            param0->unk_24[v0].unk_08 = 0;
        }
    }

    return 1;
}

BOOL sub_0208B8EC(UnkStruct_0208B878 *param0, s16 slotsMinigameDTO, s16 param2)
{
    if (sub_0208B930(param0, slotsMinigameDTO, param2) == 0) {
        return 0;
    }

    param0->unk_24[0].slotMachineVariant = slotsMinigameDTO;
    param0->unk_24[0].unk_06 = param2;
    param0->unk_E8 = 0xFF;
    param0->unk_EC = 0;

    {
        int v0;

        for (v0 = 0; v0 < param0->unk_10.coins; v0++) {
            param0->unk_24[v0].unk_08 = 0;
        }
    }

    return 1;
}

static BOOL sub_0208B930(UnkStruct_0208B878 *param0, s16 slotsMinigameDTO, s16 param2)
{
    if ((param0->unk_24[0].slotMachineVariant == slotsMinigameDTO) && (param0->unk_24[0].unk_06 == param2)) {
        return 0;
    }

    return 1;
}

BOOL sub_0208B948(UnkStruct_0208B878 *param0, s16 slotsMinigameDTO, s16 param2)
{
    {
        int v0;

        param0->unk_E8 = 0xFF;
        param0->unk_EC = 0;

        for (v0 = 0; v0 < param0->unk_10.coins; v0++) {
            param0->unk_24[v0].slotMachineVariant = slotsMinigameDTO;
            param0->unk_24[v0].unk_06 = param2;
            ManagedSprite_SetPositionXYWithSubscreenOffset(param0->unk_24[v0].coins, slotsMinigameDTO, param2, param0->unk_10.unk_10);
        }
    }

    return 1;
}

BOOL sub_0208B988(UnkStruct_0208B878 *param0)
{
    switch (param0->unk_E4) {
    case 0:
        sub_0208B8B0(param0, 0);
        param0->unk_E4++;
        break;
    case 1:
        SysTask_Done(param0->unk_F4);
        param0->unk_E4++;
        break;
    default:
        sub_0208B830(param0);
        NARC_dtor(param0->coins.coins);
        Heap_Free(param0);

        return 0;
    }

    return 1;
}

BOOL sub_0208B9E0(UnkStruct_0208B878 *param0, BOOL slotsMinigameDTO)
{
    {
        int v0;

        for (v0 = 0; v0 < param0->unk_10.coins; v0++) {
            ManagedSprite_SetDrawFlag(param0->unk_24[v0].coins, slotsMinigameDTO);
        }
    }

    return 1;
}

void sub_0208BA08(UnkStruct_0208B878 *param0, int slotsMinigameDTO, int param2)
{
    if ((slotsMinigameDTO != 0) && (param2 != 0)) {
        param0->unk_FC = slotsMinigameDTO;
        param0->unk_100 = param2;
    } else {
        param0->unk_FC = (15 * 1);
        param0->unk_100 = (15 * 1);
    }
}

void sub_0208BA30(UnkStruct_0208B878 *param0)
{
    int v0;

    for (v0 = 0; v0 < param0->unk_10.coins; v0++) {
        ManagedSprite_SetAnim(param0->unk_24[v0].coins, 1);
    }
}

void sub_0208BA54(UnkStruct_0208B878 *param0)
{
    int v0;

    for (v0 = 0; v0 < param0->unk_10.coins; v0++) {
        ManagedSprite_SetAnim(param0->unk_24[v0].coins, 0);
    }
}
