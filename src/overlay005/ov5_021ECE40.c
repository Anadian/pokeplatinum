#include "overlay005/ov5_021ECE40.h"

#include <nitro.h>
#include <string.h>

#include "struct_decls/map_object.h"
#include "struct_decls/map_object_manager.h"

#include "overlay005/area_light.h"
#include "overlay005/field_effect_manager.h"
#include "overlay005/funcptr_ov5_021EE454.h"
#include "overlay005/object_event_gfx_data.h"
#include "overlay005/ov5_021EB1A0.h"
#include "overlay005/ov5_021ECC20.h"
#include "overlay005/ov5_021F17B8.h"
#include "overlay005/resource_heap.h"
#include "overlay005/struct_ov5_021ED01C.h"
#include "overlay005/struct_ov5_021ED0A4.h"
#include "overlay005/struct_ov5_021EDF3C.h"
#include "overlay005/struct_ov5_021EDFBC.h"
#include "overlay005/struct_ov5_021EE134.h"
#include "overlay005/struct_ov5_021EE294.h"

#include "berry_patch_graphics.h"
#include "billboard.h"
#include "enums.h"
#include "heap.h"
#include "map_object.h"
#include "map_object_move.h"
#include "map_tile_behavior.h"
#include "narc.h"
#include "overworld_anim_manager.h"
#include "resource_collection.h"
#include "sys_task.h"
#include "sys_task_manager.h"

typedef enum {
    UnkEnum_ov5_021ED334_00 = 0,
    UnkEnum_ov5_021ED334_01,
    UnkEnum_ov5_021ED334_02,
} UnkEnum_ov5_021ED334;

typedef struct {
    int coins;
    s16 slotMachineVariant;
    void *unk_08;
    void *slotsMinigameDTO;
    void *unk_10;
    BillboardGfxSequence unk_14;
    Billboard *unk_24;
    BillboardResources unk_28;
    MapObject *unk_50;
    OverworldAnimManager *unk_54;
    void *unk_58;
    UnkFuncPtr_ov5_021EE454 unk_5C;
} UnkStruct_ov5_021EE698;

static void ov5_021ED094(const MapObject *param0);
static void ov5_021ED0A4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED0F0(UnkStruct_ov5_021ED0A4 *param0);
static BillboardResources *ov5_021ED110(UnkStruct_ov5_021ED0A4 *param0, u32 slotsMinigameDTO);
static void ov5_021ED184(UnkStruct_ov5_021ED0A4 *param0, u32 slotsMinigameDTO);
static void ov5_021ED1A4(UnkStruct_ov5_021ED0A4 *param0);
static int ov5_021ED1C8(const MapObjectManager *param0, const MapObject *slotsMinigameDTO, int param2);
static void ov5_021ED224(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO, int param2, int param3, int param4, int param5, int param6);
static void ov5_021ED2AC(UnkStruct_ov5_021ED0A4 *param0);
static const ObjectEventGfxFileEntry *ov5_021ED2D0(int param0, int slotsMinigameDTO, const ObjectEventGfxFileEntry *param2);
static int ov5_021ED2E8(UnkStruct_ov5_021ED0A4 *param0, ResourceHeap *slotsMinigameDTO, int param2, int param3, const ObjectEventGfxFileEntry *param4);
static UnkEnum_ov5_021ED334 ov5_021ED334(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO, int param2, const ObjectEventGfxFileEntry *param3);
static UnkEnum_ov5_021ED334 ov5_021ED390(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static UnkEnum_ov5_021ED334 ov5_021ED3A4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED3B8(UnkStruct_ov5_021ED0A4 *param0, const int *slotsMinigameDTO);
static void ov5_021ED3DC(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED40C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED43C(UnkStruct_ov5_021ED0A4 *param0, const int *slotsMinigameDTO);
static void ov5_021ED460(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED490(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED4C0(UnkStruct_ov5_021ED0A4 *param0, const int *slotsMinigameDTO);
static void ov5_021ED4E4(UnkStruct_ov5_021ED0A4 *param0, const int *slotsMinigameDTO, const int *param2, const int *param3);
static void ov5_021ED504(int *param0, int slotsMinigameDTO, int param2);
static int ov5_021ED50C(int *param0, int slotsMinigameDTO, int param2, int param3);
static int ov5_021ED528(int *param0, int slotsMinigameDTO, int param2);
static int ov5_021ED53C(int *param0, int slotsMinigameDTO, int param2, int param3);
static void ov5_021ED558(UnkStruct_ov5_021ED0A4 *param0);
static void ov5_021ED56C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021ED598(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED5B4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021ED5E8(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED610(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED63C(MapObjectManager *param0, UnkStruct_ov5_021ED0A4 *slotsMinigameDTO);
static void ov5_021ED694(UnkStruct_ov5_021ED0A4 *param0);
static void ov5_021ED6A8(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021ED6D4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED6F0(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED74C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED778(MapObjectManager *param0, UnkStruct_ov5_021ED0A4 *slotsMinigameDTO);
static void ov5_021ED7D0(UnkStruct_ov5_021ED0A4 *param0);
static void ov5_021ED7E4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021ED810(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021ED82C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED858(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED88C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED8B8(MapObjectManager *param0, UnkStruct_ov5_021ED0A4 *slotsMinigameDTO);
static int ov5_021ED924(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021ED94C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021ED974(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021ED99C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED9C4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED9DC(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021ED9F4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021EDA0C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021EDA54(const MapObjectManager *param0, int slotsMinigameDTO, const MapObject *param2);
static int ov5_021EDAB4(const MapObjectManager *param0, int slotsMinigameDTO, const MapObject *param2);
static int ov5_021EDB3C(const MapObjectManager *param0, int slotsMinigameDTO, const MapObject *param2);
static int *ov5_021EDCB8(UnkStruct_ov5_021ED0A4 *param0);
static int *ov5_021EDCBC(UnkStruct_ov5_021ED0A4 *param0);
static int *ov5_021EDCC0(UnkStruct_ov5_021ED0A4 *param0);
static void ov5_021EDCC4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021EDCC8(const UnkStruct_ov5_021ED0A4 *param0);
static void ov5_021EDCCC(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021EDCD0(const UnkStruct_ov5_021ED0A4 *param0);
static void ov5_021EDCD4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021EDCD8(const UnkStruct_ov5_021ED0A4 *param0);
static void ov5_021EDCDC(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021EDCE0(const UnkStruct_ov5_021ED0A4 *param0);
static void ov5_021EDCE4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021EDCE8(const UnkStruct_ov5_021ED0A4 *param0);
static void ov5_021EDCEC(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021EDCF0(const UnkStruct_ov5_021ED0A4 *param0);
static void *ov5_021EDCF4(UnkStruct_ov5_021ED0A4 *param0, u32 slotsMinigameDTO, int param2);
static const ObjectEventGfxModelAnimEntry *ov5_021EDD04(int param0);
static int ov5_021EDD2C(int param0);
static int ov5_021EDD38(int param0);
static const BillboardAnim *ov5_021EDD44(int param0);
static u32 ov5_021EDD50(int param0);
static void ov5_021EDDAC(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021EDDD4(BillboardList *param0);
static Billboard *ov5_021EDDDC(BillboardList *param0, const BillboardResources *slotsMinigameDTO, const VecFx32 *param2, u32 param3);
static void ov5_021EDE3C(UnkStruct_ov5_021ED0A4 *param0, u32 slotsMinigameDTO, BillboardResources *param2);
static UnkStruct_ov5_021ED0A4 *ov5_021EDEA8(const MapObject *param0);
static int ov5_021EDF3C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO, u32 param2, int param3);
static void ov5_021EDFBC(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static int ov5_021EDFF0(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021EE030(SysTask *param0, void *slotsMinigameDTO);
static void ov5_021EE0E8(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO, void *param2, int param3);
static void ov5_021EE134(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021EE170(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO);
static void ov5_021EE1AC(SysTask *param0, void *slotsMinigameDTO);
static void ov5_021EE1E8(SysTask *param0, void *slotsMinigameDTO);
static void ov5_021EE228(UnkStruct_ov5_021ED0A4 *param0, MapObject *slotsMinigameDTO, Billboard **param2, int param3);
static void ov5_021EE264(UnkStruct_ov5_021ED0A4 *param0, const MapObject *slotsMinigameDTO);
static void ov5_021EE2C4(SysTask *param0, void *slotsMinigameDTO);
static void ov5_021EE294(UnkStruct_ov5_021ED0A4 *param0);
static void ov5_021EE2D0(UnkStruct_ov5_021ED0A4 *param0, UnkStruct_ov5_021EE294 *slotsMinigameDTO);
static void ov5_021EE320(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO, int param2);
static void ov5_021EE3C4(UnkStruct_ov5_021ED0A4 *param0);
static Billboard *ov5_021EE454(MapObject *param0, int slotsMinigameDTO, UnkFuncPtr_ov5_021EE454 param2, void *param3);
static void ov5_021EE698(SysTask *param0, void *slotsMinigameDTO);

void ov5_021ECE40(UnkStruct_ov5_021ED0A4 *param0, const MapObjectManager *slotsMinigameDTO, int param2, int param3, int param4, int param5, const int *param6, int param7)
{
    param0->unk_104 = slotsMinigameDTO;

    ov5_021EDDAC(param0, param2);
    ov5_021EE320(param0, param2, param7);
    ov5_021ED224(param0, 8, 4, 8, 4, param4, param5);
    ov5_021ED0A4(param0, param2);
    ov5_021ED4E4(param0, param6, gPreloadedBillboardModels, gPreloadedBillboardFrameSeqs);
}

void ov5_021ECE94(UnkStruct_ov5_021ED0A4 *param0)
{
    ov5_021EE3C4(param0);
    ov5_021ED0F0(param0);
    ov5_021EDDD4(ov5_021EDC8C(param0));
    ov5_021ED2AC(param0);
}

int ov5_021ECEB4(MapObject *param0, Billboard **slotsMinigameDTO, int param2)
{
    int v0;
    UnkStruct_ov5_021ED0A4 *v1;

    *slotsMinigameDTO = NULL;

    v1 = ov5_021EDEA8(param0);
    v0 = ov5_021ED82C(v1, param2);

    if (v0 == 0) {
        ov5_021ED060(param0, slotsMinigameDTO, param2);
        return v0;
    }

    if ((v0 == 3) || (v0 == 4)) {
        ov5_021EE228(v1, param0, slotsMinigameDTO, param2);
        return v0;
    }

    *slotsMinigameDTO = ov5_021ECF1C(param0, param2);
    return v0;
}

int ov5_021ECF04(MapObject *param0, Billboard **slotsMinigameDTO)
{
    int v0 = MapObject_GetGraphicsID(param0);
    int v1 = ov5_021ECEB4(param0, slotsMinigameDTO, v0);

    return v1;
}

Billboard *ov5_021ECF1C(MapObject *param0, int slotsMinigameDTO)
{
    VecFx32 v0;
    BillboardList *v1;
    Billboard *v2;
    BillboardResources *v3;
    UnkStruct_ov5_021ED0A4 *v4 = ov5_021EDEA8(param0);
    v1 = ov5_021EDC8C(v4);

    ov5_021EDA0C(v4, slotsMinigameDTO);
    v3 = ov5_021ED110(v4, slotsMinigameDTO);

    GF_ASSERT(v3 != NULL);

    ov5_021ECDA0(param0, &v0);
    v2 = ov5_021EDDDC(v1, v3, &v0, ov5_021EDD50(slotsMinigameDTO));

    GF_ASSERT(v2 != NULL);

    return v2;
}

void ov5_021ECF70(const MapObject *param0, Billboard **slotsMinigameDTO, int param2)
{
    int v0;

    Billboard_Delete(*slotsMinigameDTO);
    *slotsMinigameDTO = NULL;

    v0 = ov5_021ED1C8(MapObject_MapObjectManager(param0), param0, param2);

    if (v0 == 0) {
        ov5_021ED184(ov5_021EDEA8(param0), param2);
    }
}

void ov5_021ECFA4(const MapObject *param0, Billboard **slotsMinigameDTO)
{
    ov5_021ED094(param0);

    if ((*slotsMinigameDTO) != NULL) {
        int v0 = MapObject_GetGraphicsID(param0);

        if (BerryPatchGraphics_IsBerryPatch(v0) == 1) {
            v0 = BerryPatchGraphics_GetCurrentGraphicsResourceID(param0);
        }

        ov5_021ECF70(param0, slotsMinigameDTO, v0);
    }
}

void ov5_021ECFD8(const MapObject *param0, Billboard **slotsMinigameDTO, int param2)
{
    int v0;

    ov5_021ED094(param0);

    if ((*slotsMinigameDTO) != NULL) {
        Billboard_Delete(*slotsMinigameDTO);
        *slotsMinigameDTO = NULL;
    }

    if (param2 != 0xffff) {
        v0 = ov5_021ED1C8(MapObject_MapObjectManager(param0), param0, param2);

        if (v0 == 0) {
            ov5_021ED184(ov5_021EDEA8(param0), param2);
        }
    }
}

void ov5_021ED01C(Billboard *param0, UnkStruct_ov5_021ED01C *slotsMinigameDTO)
{
    slotsMinigameDTO->coins = Billboard_GetDrawFlag(param0);
    slotsMinigameDTO->unk_02 = Billboard_GetAnimNum(param0);
    slotsMinigameDTO->slotMachineVariant = Billboard_GetFrameNum(param0);
}

void ov5_021ED03C(Billboard *param0, UnkStruct_ov5_021ED01C *slotsMinigameDTO)
{
    Billboard_SetDrawFlag(param0, slotsMinigameDTO->coins);
    Billboard_SetAnimNum(param0, slotsMinigameDTO->unk_02);
    Billboard_SetFrameNum(param0, slotsMinigameDTO->slotMachineVariant);
}

void ov5_021ED060(MapObject *param0, Billboard **slotsMinigameDTO, int param2)
{
    UnkStruct_ov5_021ED0A4 *v0 = ov5_021EDEA8(param0);

    if (ov5_021ED3A4(v0, param2) == UnkEnum_ov5_021ED334_00) {
        *slotsMinigameDTO = ov5_021ECF1C(param0, param2);
    } else {
        ov5_021EE228(v0, param0, slotsMinigameDTO, param2);
    }
}

static void ov5_021ED094(const MapObject *param0)
{
    UnkStruct_ov5_021ED0A4 *v0 = ov5_021EDEA8(param0);

    ov5_021EE264(v0, param0);
}

static void ov5_021ED0A4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0, v1;
    BillboardResources *v2;
    UnkStruct_ov5_021ED110 *v3;

    v0 = sizeof(BillboardResources) * slotsMinigameDTO;
    v2 = Heap_Alloc(HEAP_ID_FIELD1, v0);

    param0->unk_E4 = v2;
    GF_ASSERT(v2 != NULL);

    v0 = (sizeof(UnkStruct_ov5_021ED110)) * slotsMinigameDTO;
    v3 = Heap_Alloc(HEAP_ID_FIELD1, v0);

    param0->unk_F4 = v3;
    GF_ASSERT(v3 != NULL);

    v1 = sizeof(BillboardResources);

    do {
        v3->coins = 0xffff;
        v3->slotMachineVariant = v2;
        v3++;
        (u8 *)v2 += v1;
        slotsMinigameDTO--;
    } while (slotsMinigameDTO);
}

static void ov5_021ED0F0(UnkStruct_ov5_021ED0A4 *param0)
{
    ov5_021ED1A4(param0);

    Heap_FreeExplicit(HEAP_ID_FIELD1, param0->unk_E4);
    Heap_FreeExplicit(HEAP_ID_FIELD1, param0->unk_F4);
}

static BillboardResources *ov5_021ED110(UnkStruct_ov5_021ED0A4 *param0, u32 slotsMinigameDTO)
{
    int v0;
    UnkStruct_ov5_021ED110 *v1 = param0->unk_F4;
    v0 = param0->slotMachineVariant;

    do {
        if (v1->coins == slotsMinigameDTO) {
            return v1->slotMachineVariant;
        }

        v1++;
        v0--;
    } while (v0);

    v1 = param0->unk_F4;
    v0 = param0->slotMachineVariant;

    do {
        if (v1->coins == 0xffff) {
            v1->coins = slotsMinigameDTO;
            ov5_021EDE3C(param0, slotsMinigameDTO, v1->slotMachineVariant);
            return v1->slotMachineVariant;
        }

        v1++;
        v0--;
    } while (v0);

    return NULL;
}

int ov5_021ED150(const MapObjectManager *param0, u32 slotsMinigameDTO, BillboardResources *param2)
{
    int v0;
    const UnkStruct_ov5_021ED0A4 *v1 = sub_0206285C(param0);
    UnkStruct_ov5_021ED110 *v2 = v1->unk_F4;
    v0 = v1->slotMachineVariant;

    do {
        if (v2->coins == slotsMinigameDTO) {
            *param2 = *(v2->slotMachineVariant);
            return 1;
        }

        v2++;
        v0--;
    } while (v0);

    return 0;
}

static void ov5_021ED184(UnkStruct_ov5_021ED0A4 *param0, u32 slotsMinigameDTO)
{
    int v0;
    UnkStruct_ov5_021ED110 *v1 = param0->unk_F4;
    v0 = param0->slotMachineVariant;

    do {
        if (v1->coins == slotsMinigameDTO) {
            v1->coins = 0xffff;

            return;
        }

        v1++;
        v0--;
    } while (v0);
}

static void ov5_021ED1A4(UnkStruct_ov5_021ED0A4 *param0)
{
    int v0;
    UnkStruct_ov5_021ED110 *v1 = param0->unk_F4;
    v0 = param0->slotMachineVariant;

    do {
        if (v1->coins != 0xffff) {
            v1->coins = 0xffff;
        }

        v1++;
        v0--;
    } while (v0);
}

static int ov5_021ED1C8(const MapObjectManager *param0, const MapObject *slotsMinigameDTO, int param2)
{
    int v0, v1;
    const MapObject *v2;

    v0 = MapObjectMan_GetMaxObjects(param0);
    v2 = MapObjectMan_GetMapObjectConst(param0);

    do {
        if (v2 != slotsMinigameDTO) {
            if (sub_02062CF8(v2) == 1) {
                v1 = MapObject_GetGraphicsID(v2);

                if (BerryPatchGraphics_IsBerryPatch(v1) == 1) {
                    v1 = BerryPatchGraphics_GetCurrentGraphicsResourceID(v2);
                }

                if ((v1 != 0xffff) && (v1 == param2)) {
                    return 1;
                }
            }
        }

        sub_02062880(&v2);
        v0--;
    } while (v0);

    return 0;
}

static void ov5_021ED224(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO, int param2, int param3, int param4, int param5, int param6)
{
    {
        param0->unk_F8 = ResourceHeap_New(HEAP_ID_FIELD1, HEAP_ID_64, 0x1000 * slotsMinigameDTO, slotsMinigameDTO);
        ov5_021ED558(param0);
        ov5_021EDCC4(param0, param2);
        ov5_021EDCCC(param0, slotsMinigameDTO - param2);
    }

    {
        param0->unk_FC = ResourceHeap_New(HEAP_ID_FIELD1, HEAP_ID_65, 0x80 * param3, param3);
        ov5_021ED694(param0);
        ov5_021EDCD4(param0, param4);
        ov5_021EDCDC(param0, param3 - param4);
    }

    {
        TextureResourceManager *v0;

        v0 = TextureResourceManager_New(param5, HEAP_ID_FIELD1);

        ov5_021EDCA8(param0, v0);
        ov5_021ED7D0(param0);
        ov5_021EDCE4(param0, param6);
        ov5_021EDCEC(param0, param5 - param6);
    }
}

static void ov5_021ED2AC(UnkStruct_ov5_021ED0A4 *param0)
{
    ResourceHeap_Free(param0->unk_F8);
    ResourceHeap_Free(param0->unk_FC);
    TextureResourceManager_Delete(ov5_021EDCB0(param0));
}

static const ObjectEventGfxFileEntry *ov5_021ED2D0(int param0, int slotsMinigameDTO, const ObjectEventGfxFileEntry *param2)
{
    do {
        if (param2->id == param0) {
            return param2;
        }

        param2++;
    } while (param2->id != slotsMinigameDTO);

    return NULL;
}

static int ov5_021ED2E8(UnkStruct_ov5_021ED0A4 *param0, ResourceHeap *slotsMinigameDTO, int param2, int param3, const ObjectEventGfxFileEntry *param4)
{
    const ObjectEventGfxFileEntry *v0;

    if (ResourceHeap_HasItem(slotsMinigameDTO, param2) == 1) {
        return 0;
    }

    v0 = ov5_021ED2D0(param2, param3, param4);
    GF_ASSERT(v0 != NULL);

    {
        NARC *v1 = MapObjectMan_GetNARC(param0->unk_104);
        ResourceHeap_LoadMemberFromNARC(slotsMinigameDTO, param2, v1, v0->narcIdx, 0);
    }

    return 1;
}

static UnkEnum_ov5_021ED334 ov5_021ED334(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO, int param2, const ObjectEventGfxFileEntry *param3)
{
    TextureResourceManager *v0 = param0->unk_F0;

    if (TextureResourceManager_IsIDUnused(v0, param2) == 0) {
        return UnkEnum_ov5_021ED334_00;
    }

    if (ov5_021EDFF0(param0, param2) != 0) {
        return UnkEnum_ov5_021ED334_01;
    }

    {
        TextureResource *v1;
        const ObjectEventGfxFileEntry *v2 = ov5_021ED2D0(param2, 0xffff, param3);

        if (v2 == NULL) {
            return UnkEnum_ov5_021ED334_02;
        }

        if (ov5_021EDF3C(param0, param2, v2->narcIdx, slotsMinigameDTO) == 1) {
            return UnkEnum_ov5_021ED334_00;
        }

        return UnkEnum_ov5_021ED334_01;
    }
}

static UnkEnum_ov5_021ED334 ov5_021ED390(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    return ov5_021ED334(param0, 0, slotsMinigameDTO, gObjectEventGfxTexturesTable);
}

static UnkEnum_ov5_021ED334 ov5_021ED3A4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    return ov5_021ED334(param0, 1, slotsMinigameDTO, gObjectEventGfxTexturesTable);
}

static void ov5_021ED3B8(UnkStruct_ov5_021ED0A4 *param0, const int *slotsMinigameDTO)
{
    while ((*slotsMinigameDTO) != 0xffff) {
        ov5_021ED390(param0, *slotsMinigameDTO);
        slotsMinigameDTO++;
    }
}

static void ov5_021ED3DC(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    ResourceCollection *v0 = ov5_021EDC98(param0);

    ov5_021ED2E8(param0, param0->unk_F8, slotsMinigameDTO, 0xffff, gObjectEventGfxModelsTable);
    ov5_021ED56C(param0, slotsMinigameDTO);
}

static void ov5_021ED40C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    ResourceCollection *v0 = ov5_021EDC98(param0);

    ov5_021ED2E8(param0, param0->unk_F8, slotsMinigameDTO, 0xffff, gObjectEventGfxModelsTable);
    ov5_021ED5B4(param0, slotsMinigameDTO);
}

static void ov5_021ED43C(UnkStruct_ov5_021ED0A4 *param0, const int *slotsMinigameDTO)
{
    while ((*slotsMinigameDTO) != 0xffff) {
        ov5_021ED3DC(param0, *slotsMinigameDTO);
        slotsMinigameDTO++;
    }
}

static void ov5_021ED460(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    ResourceCollection *v0 = ov5_021EDCA0(param0);

    ov5_021ED2E8(param0, param0->unk_FC, slotsMinigameDTO, 0xffff, gObjectEventGfxFrameSeqsTable);
    ov5_021ED6A8(param0, slotsMinigameDTO);
}

static void ov5_021ED490(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    ResourceCollection *v0 = ov5_021EDCA0(param0);

    ov5_021ED2E8(param0, param0->unk_FC, slotsMinigameDTO, 0xffff, gObjectEventGfxFrameSeqsTable);
    ov5_021ED6F0(param0, slotsMinigameDTO);
}

static void ov5_021ED4C0(UnkStruct_ov5_021ED0A4 *param0, const int *slotsMinigameDTO)
{
    while ((*slotsMinigameDTO) != 0xffff) {
        ov5_021ED460(param0, *slotsMinigameDTO);
        slotsMinigameDTO++;
    }
}

static void ov5_021ED4E4(UnkStruct_ov5_021ED0A4 *param0, const int *slotsMinigameDTO, const int *param2, const int *param3)
{
    ov5_021ED3B8(param0, slotsMinigameDTO);
    ov5_021ED43C(param0, param2);
    ov5_021ED4C0(param0, param3);
}

static void ov5_021ED504(int *param0, int slotsMinigameDTO, int param2)
{
    do {
        *param0 = slotsMinigameDTO;
        param0++;
        param2--;
    } while (param2);
}

static int ov5_021ED50C(int *param0, int slotsMinigameDTO, int param2, int param3)
{
    do {
        if ((*param0) == param2) {
            *param0 = slotsMinigameDTO;
            return 1;
        }

        param0++;
        param3--;
    } while (param3);

    return 0;
}

static int ov5_021ED528(int *param0, int slotsMinigameDTO, int param2)
{
    do {
        if ((*param0) == slotsMinigameDTO) {
            return 1;
        }

        param0++;
        param2--;
    } while (param2);

    return 0;
}

static int ov5_021ED53C(int *param0, int slotsMinigameDTO, int param2, int param3)
{
    do {
        if ((*param0) == slotsMinigameDTO) {
            *param0 = param2;
            return 1;
        }

        param0++;
        param3--;
    } while (param3);

    return 0;
}

static void ov5_021ED558(UnkStruct_ov5_021ED0A4 *param0)
{
    int *v0 = ov5_021EDCBC(param0);
    ov5_021ED504(v0, 0xffff, 8);
}

static void ov5_021ED56C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0, v1;
    int *v2;

    v0 = ov5_021EDCC8(param0);
    v2 = ov5_021EDCBC(param0);

    v1 = ov5_021ED50C(v2, slotsMinigameDTO, 0xffff, v0);
    GF_ASSERT(v1 != 0);
}

static int ov5_021ED598(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0;
    int *v1;

    v0 = ov5_021EDCC8(param0);
    v1 = ov5_021EDCBC(param0);

    return ov5_021ED528(v1, slotsMinigameDTO, v0);
}

static void ov5_021ED5B4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0, v1;
    int *v2 = ov5_021EDCBC(param0);
    v2 = &v2[ov5_021EDCC8(param0)];
    v1 = ov5_021EDCD0(param0);
    v0 = ov5_021ED50C(v2, slotsMinigameDTO, 0xffff, v1);

    GF_ASSERT(v0 != 0);
}

static int ov5_021ED5E8(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0;
    int *v1 = ov5_021EDCBC(param0);
    v1 = &v1[ov5_021EDCC8(param0)];
    v0 = ov5_021EDCD0(param0);

    return ov5_021ED528(v1, slotsMinigameDTO, v0);
}

static void ov5_021ED610(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0;
    int *v1 = ov5_021EDCBC(param0);
    v1 = &v1[ov5_021EDCC8(param0)];
    v0 = ov5_021EDCD0(param0);

    ov5_021ED53C(v1, slotsMinigameDTO, 0xffff, v0);
}

static void ov5_021ED63C(MapObjectManager *param0, UnkStruct_ov5_021ED0A4 *slotsMinigameDTO)
{
    int v0;
    ResourceCollection *v2 = ov5_021EDC98(slotsMinigameDTO);
    int *v1 = ov5_021EDCBC(slotsMinigameDTO);
    v1 = &v1[ov5_021EDCC8(slotsMinigameDTO)];
    v0 = ov5_021EDCD0(slotsMinigameDTO);

    do {
        if ((*v1) != 0xffff) {
            if (ov5_021EDAB4(param0, *v1, NULL) == 0) {
                ResourceHeap_FreeItem(slotsMinigameDTO->unk_F8, *v1);
                *v1 = 0xffff;
            }
        }

        v1++;
        v0--;
    } while (v0);
}

static void ov5_021ED694(UnkStruct_ov5_021ED0A4 *param0)
{
    int *v0 = ov5_021EDCC0(param0);
    ov5_021ED504(v0, 0xffff, 8);
}

static void ov5_021ED6A8(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0, v1;
    int *v2;

    v0 = ov5_021EDCD8(param0);
    v2 = ov5_021EDCC0(param0);
    v1 = ov5_021ED50C(v2, slotsMinigameDTO, 0xffff, v0);

    GF_ASSERT(v1 != 0);
}

static int ov5_021ED6D4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0;
    int *v1;

    v0 = ov5_021EDCD8(param0);
    v1 = ov5_021EDCC0(param0);

    return ov5_021ED528(v1, slotsMinigameDTO, v0);
}

static void ov5_021ED6F0(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0, v1;
    int *v2 = ov5_021EDCC0(param0);
    v2 = &v2[ov5_021EDCD8(param0)];
    v1 = ov5_021EDCE0(param0);
    v0 = ov5_021ED50C(v2, slotsMinigameDTO, 0xffff, v1);

    GF_ASSERT(v0 != 0);
}

static int ov5_021ED724(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0;
    int *v1 = ov5_021EDCC0(param0);
    v1 = &v1[ov5_021EDCD8(param0)];
    v0 = ov5_021EDCE0(param0);

    return ov5_021ED528(v1, slotsMinigameDTO, v0);
}

static void ov5_021ED74C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0;
    int *v1 = ov5_021EDCC0(param0);
    v1 = &v1[ov5_021EDCD8(param0)];
    v0 = ov5_021EDCE0(param0);

    ov5_021ED53C(v1, slotsMinigameDTO, 0xffff, v0);
}

static void ov5_021ED778(MapObjectManager *param0, UnkStruct_ov5_021ED0A4 *slotsMinigameDTO)
{
    int v0;
    ResourceCollection *v2 = ov5_021EDCA0(slotsMinigameDTO);
    int *v1 = ov5_021EDCC0(slotsMinigameDTO);
    v1 = &v1[ov5_021EDCD8(slotsMinigameDTO)];
    v0 = ov5_021EDCE0(slotsMinigameDTO);

    do {
        if ((*v1) != 0xffff) {
            if (ov5_021EDB3C(param0, *v1, NULL) == 0) {
                ResourceHeap_FreeItem(slotsMinigameDTO->unk_FC, *v1);
                *v1 = 0xffff;
            }
        }

        v1++;
        v0--;
    } while (v0);
}

static void ov5_021ED7D0(UnkStruct_ov5_021ED0A4 *param0)
{
    int *v0 = ov5_021EDCB8(param0);
    ov5_021ED504(v0, 0xffff, 32);
}

static void ov5_021ED7E4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0, v1;
    int *v2;

    v0 = ov5_021EDCE8(param0);
    v2 = ov5_021EDCB8(param0);
    v1 = ov5_021ED50C(v2, slotsMinigameDTO, 0xffff, v0);
    GF_ASSERT(v1 != 0);
}

static int ov5_021ED810(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0;
    int *v1;

    v0 = ov5_021EDCE8(param0);
    v1 = ov5_021EDCB8(param0);
    return ov5_021ED528(v1, slotsMinigameDTO, v0);
}

static int ov5_021ED82C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    if (ov5_021ED810(param0, slotsMinigameDTO) == 1) {
        return 1;
    }

    if (ov5_021ED924(param0, slotsMinigameDTO) == 1) {
        return 2;
    }

    return ov5_021EDFF0(param0, slotsMinigameDTO);
}

static void ov5_021ED858(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0, v1;
    int *v2 = ov5_021EDCB8(param0);
    v2 = &v2[ov5_021EDCE8(param0)];
    v1 = ov5_021EDCF0(param0);
    v0 = ov5_021ED50C(v2, slotsMinigameDTO, 0xffff, v1);

    GF_ASSERT(v0 != 0);
}

static void ov5_021ED88C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0;
    int *v1 = ov5_021EDCB8(param0);
    v1 = &v1[ov5_021EDCE8(param0)];
    v0 = ov5_021EDCF0(param0);

    ov5_021ED53C(v1, slotsMinigameDTO, 0xffff, v0);
}

static void ov5_021ED8B8(MapObjectManager *param0, UnkStruct_ov5_021ED0A4 *slotsMinigameDTO)
{
    int v0, v1;
    TextureResourceManager *v3 = ov5_021EDCB0(slotsMinigameDTO);
    int *v2 = ov5_021EDCB8(slotsMinigameDTO);
    v2 = &v2[ov5_021EDCE8(slotsMinigameDTO)];
    v0 = ov5_021EDCF0(slotsMinigameDTO);

    do {
        v1 = *v2;

        if (v1 != 0xffff) {
            if (ov5_021EDA54(param0, v1, NULL) == 0) {
                TextureResourceManager_RemoveTextureWithID(v3, v1);
                ov5_021EDFBC(slotsMinigameDTO, v1);
                ov5_021EE170(slotsMinigameDTO, v1);

                *v2 = 0xffff;
            }
        }

        v2++;
        v0--;
    } while (v0);
}

static int ov5_021ED924(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0;
    int *v1 = ov5_021EDCB8(param0);
    v1 = &v1[ov5_021EDCE8(param0)];
    v0 = ov5_021EDCF0(param0);

    return ov5_021ED528(v1, slotsMinigameDTO, v0);
}

static int ov5_021ED94C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    if (ov5_021ED810(param0, slotsMinigameDTO) == 1) {
        return 0;
    }

    if (ov5_021ED924(param0, slotsMinigameDTO) == 1) {
        return 1;
    }

    return 2;
}

static int ov5_021ED974(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    if (ov5_021ED598(param0, slotsMinigameDTO) == 1) {
        return 0;
    }

    if (ov5_021ED5E8(param0, slotsMinigameDTO) == 1) {
        return 1;
    }

    return 2;
}

static int ov5_021ED99C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    if (ov5_021ED6D4(param0, slotsMinigameDTO) == 1) {
        return 0;
    }

    if (ov5_021ED724(param0, slotsMinigameDTO) == 1) {
        return 1;
    }

    return 2;
}

static void ov5_021ED9C4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0 = ov5_021ED82C(param0, slotsMinigameDTO);

    if (v0 == 0) {
        ov5_021ED3A4(param0, slotsMinigameDTO);
    }
}

static void ov5_021ED9DC(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    if (ov5_021ED974(param0, slotsMinigameDTO) == 2) {
        ov5_021ED40C(param0, slotsMinigameDTO);
    }
}

static void ov5_021ED9F4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    if (ov5_021ED99C(param0, slotsMinigameDTO) == 2) {
        ov5_021ED490(param0, slotsMinigameDTO);
    }
}

static void ov5_021EDA0C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0 = ov5_021EDD2C(slotsMinigameDTO);
    ov5_021ED9DC(param0, v0);

    v0 = ov5_021EDD38(slotsMinigameDTO);
    ov5_021ED9F4(param0, v0);
    ov5_021ED9C4(param0, slotsMinigameDTO);
}

void ov5_021EDA38(MapObjectManager *param0, UnkStruct_ov5_021ED0A4 *slotsMinigameDTO)
{
    ov5_021ED63C(param0, slotsMinigameDTO);
    ov5_021ED778(param0, slotsMinigameDTO);
    ov5_021ED8B8(param0, slotsMinigameDTO);
}

static int ov5_021EDA54(const MapObjectManager *param0, int slotsMinigameDTO, const MapObject *param2)
{
    int v0 = 0, v1;
    MapObject *v2 = NULL;

    while (MapObjectMan_FindObjectWithStatus(param0, &v2, &v0, MAP_OBJ_STATUS_0) == 1) {
        if ((param2 != NULL) && (param2 == v2)) {
            continue;
        }

        v1 = MapObject_GetGraphicsID(v2);

        if (BerryPatchGraphics_IsBerryPatch(v1) == 1) {
            v1 = BerryPatchGraphics_GetCurrentGraphicsResourceID(v2);
        }

        if (v1 == slotsMinigameDTO) {
            return 1;
        }
    }

    return 0;
}

static int ov5_021EDAB4(const MapObjectManager *param0, int slotsMinigameDTO, const MapObject *param2)
{
    int v0, v1 = 0;
    MapObject *v2 = NULL;

    while (MapObjectMan_FindObjectWithStatus(param0, &v2, &v1, MAP_OBJ_STATUS_0) == 1) {
        if ((param2 != NULL) && (param2 == v2)) {
            continue;
        }

        v0 = MapObject_GetGraphicsID(v2);

        if (v0 == 0xffff) {
            continue;
        }

        {
            const ObjectEventGfxRenderDetailsEntry *v3 = ov5_021ECD04(v2);

            if (v3->modelType != 1) {
                continue;
            }
        }

        if (BerryPatchGraphics_IsBerryPatch(v0) == 1) {
            v0 = BerryPatchGraphics_GetCurrentGraphicsResourceID(v2);
        }

        if (v0 != 0xffff) {
            if (ov5_021EDD2C(v0) == slotsMinigameDTO) {
                return 1;
            }
        }
    }

    return 0;
}

static int ov5_021EDB3C(const MapObjectManager *param0, int slotsMinigameDTO, const MapObject *param2)
{
    int v0, v1 = 0;
    MapObject *v2 = NULL;

    while (MapObjectMan_FindObjectWithStatus(param0, &v2, &v1, MAP_OBJ_STATUS_0) == 1) {
        if ((param2 != NULL) && (v2 == param2)) {
            continue;
        }

        if (v0 == 0xffff) {
            continue;
        }

        {
            const ObjectEventGfxRenderDetailsEntry *v3 = ov5_021ECD04(v2);

            if (v3->modelType != 1) {
                continue;
            }
        }

        v0 = MapObject_GetGraphicsID(v2);

        if (BerryPatchGraphics_IsBerryPatch(v0) == 1) {
            v0 = BerryPatchGraphics_GetCurrentGraphicsResourceID(v2);
        }

        if (v0 != 0xffff) {
            if (ov5_021EDD38(v0) == slotsMinigameDTO) {
                return 1;
            }
        }
    }

    return 0;
}

void ov5_021EDBC4(const MapObjectManager *param0, int slotsMinigameDTO, MapObject *param2)
{
    int v0;
    UnkStruct_ov5_021ED0A4 *v1 = sub_0206285C(param0);

    v0 = ov5_021EDD2C(slotsMinigameDTO);

    if (ov5_021ED974(v1, v0) == 1) {
        if (ov5_021EDAB4(param0, v0, param2) == 0) {
            ResourceHeap_FreeItem(v1->unk_F8, v0);
            ov5_021ED610(v1, v0);
        }
    }

    v0 = ov5_021EDD38(slotsMinigameDTO);

    if (ov5_021ED99C(v1, v0) == 1) {
        if (ov5_021EDB3C(param0, v0, param2) == 0) {
            ResourceHeap_FreeItem(v1->unk_FC, v0);
            ov5_021ED74C(v1, v0);
        }
    }

    if (ov5_021ED94C(v1, slotsMinigameDTO) == 1) {
        if (ov5_021EDA54(param0, slotsMinigameDTO, param2) == 0) {
            TextureResourceManager *v2 = ov5_021EDCB0(v1);

            TextureResourceManager_RemoveTextureWithID(v2, slotsMinigameDTO);
            ov5_021ED88C(v1, slotsMinigameDTO);
            ov5_021EDFBC(v1, slotsMinigameDTO);
            ov5_021EE170(v1, slotsMinigameDTO);
        }
    }
}

void ov5_021EDC84(UnkStruct_ov5_021ED0A4 *param0, BillboardList *slotsMinigameDTO)
{
    param0->unk_E0 = slotsMinigameDTO;
}

BillboardList *ov5_021EDC8C(UnkStruct_ov5_021ED0A4 *param0)
{
    return param0->unk_E0;
}

void ov5_021EDC94(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    param0->slotMachineVariant = slotsMinigameDTO;
}

ResourceCollection *ov5_021EDC98(const UnkStruct_ov5_021ED0A4 *param0)
{
    return param0->unk_E8;
}

ResourceCollection *ov5_021EDCA0(const UnkStruct_ov5_021ED0A4 *param0)
{
    return param0->unk_EC;
}

void ov5_021EDCA8(UnkStruct_ov5_021ED0A4 *param0, TextureResourceManager *slotsMinigameDTO)
{
    param0->unk_F0 = slotsMinigameDTO;
}

TextureResourceManager *ov5_021EDCB0(const UnkStruct_ov5_021ED0A4 *param0)
{
    return param0->unk_F0;
}

static int *ov5_021EDCB8(UnkStruct_ov5_021ED0A4 *param0)
{
    return param0->unk_60;
}

static int *ov5_021EDCBC(UnkStruct_ov5_021ED0A4 *param0)
{
    return param0->unk_20;
}

static int *ov5_021EDCC0(UnkStruct_ov5_021ED0A4 *param0)
{
    return param0->unk_40;
}

static void ov5_021EDCC4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    param0->unk_08 = slotsMinigameDTO;
}

static int ov5_021EDCC8(const UnkStruct_ov5_021ED0A4 *param0)
{
    return param0->unk_08;
}

static void ov5_021EDCCC(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    param0->slotsMinigameDTO = slotsMinigameDTO;
}

static int ov5_021EDCD0(const UnkStruct_ov5_021ED0A4 *param0)
{
    return param0->slotsMinigameDTO;
}

static void ov5_021EDCD4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    param0->unk_10 = slotsMinigameDTO;
}

static int ov5_021EDCD8(const UnkStruct_ov5_021ED0A4 *param0)
{
    return param0->unk_10;
}

static void ov5_021EDCDC(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    param0->unk_14 = slotsMinigameDTO;
}

static int ov5_021EDCE0(const UnkStruct_ov5_021ED0A4 *param0)
{
    return param0->unk_14;
}

static void ov5_021EDCE4(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    param0->unk_18 = slotsMinigameDTO;
}

static int ov5_021EDCE8(const UnkStruct_ov5_021ED0A4 *param0)
{
    return param0->unk_18;
}

static void ov5_021EDCEC(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    param0->unk_1C = slotsMinigameDTO;
}

static int ov5_021EDCF0(const UnkStruct_ov5_021ED0A4 *param0)
{
    return param0->unk_1C;
}

static void *ov5_021EDCF4(UnkStruct_ov5_021ED0A4 *param0, u32 slotsMinigameDTO, int param2)
{
    return ov5_021ECD68(param0->unk_104, slotsMinigameDTO, param2);
}

static const ObjectEventGfxModelAnimEntry *ov5_021EDD04(int param0)
{
    const ObjectEventGfxModelAnimEntry *v0 = gObjectEventGfxModelAnimsTable;

    do {
        if (v0->graphicsID == param0) {
            return v0;
        }

        v0++;
    } while (v0->graphicsID != 0xffff);

    GF_ASSERT(FALSE);
    return NULL;
}

static int ov5_021EDD2C(int param0)
{
    const ObjectEventGfxModelAnimEntry *v0 = ov5_021EDD04(param0);
    return v0->modelID;
}

static int ov5_021EDD38(int param0)
{
    const ObjectEventGfxModelAnimEntry *v0 = ov5_021EDD04(param0);
    return v0->frameSeqID;
}

static const BillboardAnim *ov5_021EDD44(int param0)
{
    const ObjectEventGfxModelAnimEntry *v0 = ov5_021EDD04(param0);
    return v0->animations;
}

static u32 ov5_021EDD50(int param0)
{
    int v0 = ov5_021EDD2C(param0);
    const int *v1 = gFogIgnoredModels;

    do {
        if (*v1 == v0) {
            return 0;
        }
    } while (*(++v1) != 0xffff);

    return 1;
}

void ov5_021EDD78(MapObject *param0, int slotsMinigameDTO)
{
    if (slotsMinigameDTO == 1) {
        MapObject_SetStatusFlagOn(param0, MAP_OBJ_STATUS_22);
    } else {
        MapObject_SetStatusFlagOff(param0, MAP_OBJ_STATUS_22);
    }
}

int ov5_021EDD94(MapObject *param0)
{
    if (MapObject_CheckStatus(param0, MAP_OBJ_STATUS_22)) {
        return 1;
    }

    return 0;
}

static void ov5_021EDDAC(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    BillboardListParams v0;
    BillboardList *v1;

    v0.maxElements = slotsMinigameDTO;
    v0.heapID = HEAP_ID_FIELD1;

    v1 = BillboardList_New(&v0);
    ov5_021EDC84(param0, v1);
    ov5_021EDC94(param0, slotsMinigameDTO);
}

static void ov5_021EDDD4(BillboardList *param0)
{
    BillboardList_Delete(param0);
}

static Billboard *ov5_021EDDDC(BillboardList *param0, const BillboardResources *slotsMinigameDTO, const VecFx32 *param2, u32 param3)
{
    int v0;
    BillboardTemplate v1;
    Billboard *v2;
    VecFx32 v3 = { FX32_ONE, FX32_ONE, FX32_ONE };

    v1.list = param0;
    v1.resources = slotsMinigameDTO;
    v1.pos = *param2;
    v1.scale = v3;

    v2 = BillboardList_Append(&v1);

    if (v2 != NULL) {
        Billboard_SetDrawFlag(v2, 0);
        Billboard_SetAnimNum(v2, 0);
        Billboard_SetAnimFrameNum(v2, 0);
        NNS_G3dMdlSetMdlFogEnableFlagAll(Billboard_GetModel(v2), param3);
        AreaLight_UseGlobalModelAttributes(Billboard_GetModel(v2));
    }

    return v2;
}

static void ov5_021EDE3C(UnkStruct_ov5_021ED0A4 *param0, u32 slotsMinigameDTO, BillboardResources *param2)
{
    {
        int v0 = ov5_021EDD2C(slotsMinigameDTO);
        void *v1 = ResourceHeap_GetItemData(param0->unk_F8, v0);

        param2->modelRes = v1;
    }

    {
        int v2 = ov5_021EDD38(slotsMinigameDTO);
        void *v3 = ResourceHeap_GetItemData(param0->unk_FC, v2);

        BillboardGfxSequence_SetData(v3, &param2->gfxSequence);
    }

    {
        TextureResourceManager *v4 = ov5_021EDCB0(param0);
        TextureResource *v5 = TextureResourceManager_FindTextureResource(v4, slotsMinigameDTO);

        param2->texture = TextureResource_GetUnderlyingResource(v5);

        {
            param2->texKey = TextureResource_GetTexKey(v5);
            param2->tex4x4Key = TextureResource_GetTex4x4Key(v5);
            param2->plttKey = TextureResource_GetPaletteKey(v5);
        }
    }

    {
        param2->anims = ov5_021EDD44(slotsMinigameDTO);
    }
}

static UnkStruct_ov5_021ED0A4 *ov5_021EDEA8(const MapObject *param0)
{
    const MapObjectManager *v0 = MapObject_MapObjectManager(param0);
    return (UnkStruct_ov5_021ED0A4 *)sub_0206285C(v0);
}

BOOL ov5_021EDEB4(MapObject *param0, Billboard *slotsMinigameDTO)
{
    BOOL v0;
    VecFx32 v1;

    ov5_021ECDA0(param0, &v1);

    v1.x += 0;
    v1.y += 0;
    v1.z += (FX32_ONE * 6);

    Billboard_SetPos(slotsMinigameDTO, &v1);

    return 0;
}

void ov5_021EDED8(MapObject *param0, Billboard *slotsMinigameDTO)
{
    int v0 = 1;

    if (MapObject_CheckStatusFlag(param0, MAP_OBJ_STATUS_HIDE) == 1) {
        v0 = 0;
    }

    if (MapObject_CheckStatusFlag(param0, MAP_OBJ_STATUS_12) == 1) {
        if (!MapObject_CheckStatusFlag(param0, MAP_OBJ_STATUS_13)) {
            v0 = 0;
        }
    }

    Billboard_SetDrawFlag(slotsMinigameDTO, v0);
}

static const int Unk_ov5_021FF4C0[] = { 0, 1, 2, 3 };

int ov5_021EDF18(int param0)
{
    return Unk_ov5_021FF4C0[param0];
}

static const int Unk_ov5_021FF4D0[] = { 4, 5, 6, 7 };

int ov5_021EDF24(int param0)
{
    return Unk_ov5_021FF4D0[param0];
}

static const int Unk_ov5_021FF4E0[] = { 4, 5, 4, 5 };

int ov5_021EDF30(int param0)
{
    return Unk_ov5_021FF4E0[param0];
}

static int ov5_021EDF3C(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO, u32 param2, int param3)
{
    UnkStruct_ov5_021EDF3C *v0 = param0->unk_100;

    if ((v0->slotMachineVariant >= v0->unk_02) || (BillboardList_IsRedrawing(param0->unk_E0) == 1)) {
        int v1 = 0;
        UnkStruct_ov5_021EDFBC *v2 = v0->slotsMinigameDTO;

        while (v1 < v0->coins) {
            if (v2->slotsMinigameDTO == NULL) {
                v2->slotsMinigameDTO = param0->unk_F0;
                v2->unk_08 = param3;
                v2->slotMachineVariant = slotsMinigameDTO;
                v2->coins = param2;
                return 0;
            }

            v1++;
            v2++;
        }

        GF_ASSERT(FALSE);
        return 0;
    }

    {
        void *v3 = ov5_021EDCF4(param0, param2, 0);

        ov5_021EE0E8(param0, slotsMinigameDTO, v3, param3);
        v0->slotMachineVariant++;
        return 1;
    }
}

static void ov5_021EDFBC(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0 = 0;
    UnkStruct_ov5_021EDF3C *v1 = param0->unk_100;
    UnkStruct_ov5_021EDFBC *v2 = v1->slotsMinigameDTO;

    while (v0 < v1->coins) {
        if ((v2->slotMachineVariant == slotsMinigameDTO) && (v2->slotsMinigameDTO != NULL)) {
            v2->slotsMinigameDTO = NULL;
            return;
        }

        v0++;
        v2++;
    }
}

static int ov5_021EDFF0(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0 = 0;
    UnkStruct_ov5_021EDF3C *v1 = param0->unk_100;
    UnkStruct_ov5_021EDFBC *v2 = v1->slotsMinigameDTO;

    while (v0 < v1->coins) {
        if ((v2->slotMachineVariant == slotsMinigameDTO) && (v2->slotsMinigameDTO != NULL)) {
            if (v2->unk_08 == 0) {
                return 3;
            }

            return 4;
        }

        v0++;
        v2++;
    }

    return 0;
}

static void ov5_021EE030(SysTask *param0, void *slotsMinigameDTO)
{
    int v0 = 0;
    UnkStruct_ov5_021ED0A4 *v1 = slotsMinigameDTO;
    UnkStruct_ov5_021EDF3C *v2 = v1->unk_100;
    UnkStruct_ov5_021EDFBC *v3 = v2->slotsMinigameDTO;

    {
        if (BillboardList_IsRedrawing(v1->unk_E0) == 1) {
            return;
        }
    }

    while ((v2->slotMachineVariant < v2->unk_02) && v0 < v2->coins) {
        if (v3->slotsMinigameDTO != NULL) {
            void *v4 = ov5_021EDCF4(v1, v3->coins, 0);

            ov5_021EE0E8(v1, v3->slotMachineVariant, v4, v3->unk_08);
            v3->slotsMinigameDTO = NULL;
            v2->slotMachineVariant++;
        }

        v3++;
        v0++;
    }

    {
        int v5;

        v3 = v2->slotsMinigameDTO;

        for (v0 = 0; v0 < (v2->coins - 1); v0++) {
            if (v3[v0].slotsMinigameDTO == NULL) {
                for (v5 = v0 + 1; v5 < v2->coins; v5++) {
                    if (v3[v5].slotsMinigameDTO != NULL) {
                        v3[v0] = v3[v5];
                        v3[v5].slotsMinigameDTO = NULL;
                        break;
                    }
                }
            }
        }
    }

    v2->slotMachineVariant = 0;
}

static void ov5_021EE0E8(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO, void *param2, int param3)
{
    TextureResource *v0 = TextureResourceManager_AddTextureAndAllocVRam(param0->unk_F0, param2, slotsMinigameDTO, 1, HEAP_ID_FIELD1);

    GF_ASSERT(v0 != NULL);
    ov5_021EE134(param0, slotsMinigameDTO);

    if (param3 == 0) {
        ov5_021ED7E4(param0, slotsMinigameDTO);
    } else {
        ov5_021ED858(param0, slotsMinigameDTO);
    }
}

static void ov5_021EE134(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0 = 0;
    UnkStruct_ov5_021EDF3C *v1 = param0->unk_100;
    UnkStruct_ov5_021EE134 *v2 = v1->unk_10;

    v1->unk_06 = 1;

    while (v0 < v1->coins) {
        if (v2->unk_08 == NULL) {
            v2->unk_08 = param0->unk_F0;
            v2->slotMachineVariant = slotsMinigameDTO;
            v2->coins = 0;

            v1->unk_06 = 0;
            return;
        }

        v2++;
        v0++;
    }

    GF_ASSERT(FALSE);
}

static void ov5_021EE170(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO)
{
    int v0 = 0;
    UnkStruct_ov5_021EDF3C *v1 = param0->unk_100;
    UnkStruct_ov5_021EE134 *v2 = v1->unk_10;

    v1->unk_06 = 1;

    while (v0 < v1->coins) {
        if ((v2->unk_08 != NULL) && (v2->slotMachineVariant == slotsMinigameDTO)) {
            v2->unk_08 = NULL;
            v2->coins = 0;
            break;
        }

        v2++;
        v0++;
    }

    v1->unk_06 = 0;
}

static void ov5_021EE1AC(SysTask *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021ED0A4 *v0 = slotsMinigameDTO;
    UnkStruct_ov5_021EDF3C *v1 = v0->unk_100;

    if (v1->unk_06 == 1) {
        return;
    }

    {
        int v2 = 0;
        UnkStruct_ov5_021EE134 *v3 = v1->unk_10;

        while (v2 < v1->coins) {
            if ((v3->coins == 0) && (v3->unk_08 != NULL)) {
                TextureResourceManager_UploadResourceToVRam(v3->unk_08, v3->slotMachineVariant);
                v3->coins = 1;
            }

            v3++;
            v2++;
        }
    }
}

static void ov5_021EE1E8(SysTask *param0, void *slotsMinigameDTO)
{
    int v0 = 0;
    UnkStruct_ov5_021ED0A4 *v1 = slotsMinigameDTO;
    UnkStruct_ov5_021EDF3C *v2 = v1->unk_100;
    UnkStruct_ov5_021EE134 *v3 = v2->unk_10;

    v2->unk_06 = 1;

    while (v0 < v2->coins) {
        if ((v3->coins == 1) && (v3->unk_08 != NULL)) {
            TextureResourceManager_DiscardTextureData(v3->unk_08, v3->slotMachineVariant);
            v3->coins = 0;
            v3->unk_08 = NULL;
        }

        v3++;
        v0++;
    }

    v2->unk_06 = 0;
}

static void ov5_021EE228(UnkStruct_ov5_021ED0A4 *param0, MapObject *slotsMinigameDTO, Billboard **param2, int param3)
{
    int v0 = 0;
    UnkStruct_ov5_021EDF3C *v1 = param0->unk_100;
    UnkStruct_ov5_021EE294 *v2 = v1->unk_08;

    while (v0 < v1->coins) {
        if (v2->slotMachineVariant == NULL) {
            v2->slotMachineVariant = slotsMinigameDTO;
            v2->unk_08 = param2;
            v2->coins = param3;

            *(v2->unk_08) = NULL;
            ov5_021EDD78(slotsMinigameDTO, 1);
            return;
        }

        v2++;
        v0++;
    }

    GF_ASSERT(FALSE);
}

static void ov5_021EE264(UnkStruct_ov5_021ED0A4 *param0, const MapObject *slotsMinigameDTO)
{
    int v0 = 0;
    UnkStruct_ov5_021EDF3C *v1 = param0->unk_100;
    UnkStruct_ov5_021EE294 *v2 = v1->unk_08;

    while (v0 < v1->coins) {
        if (v2->slotMachineVariant == slotsMinigameDTO) {
            v2->slotMachineVariant = NULL;
            v2->unk_08 = NULL;

            return;
        }

        v2++;
        v0++;
    }
}

static void ov5_021EE294(UnkStruct_ov5_021ED0A4 *param0)
{
    int v0 = 0;
    UnkStruct_ov5_021EDF3C *v1 = param0->unk_100;
    UnkStruct_ov5_021EE294 *v2 = v1->unk_08;

    while (v0 < v1->coins) {
        if (v2->slotMachineVariant != NULL) {
            ov5_021EE2D0(param0, v2);
        }

        v2++;
        v0++;
    }
}

static void ov5_021EE2C4(SysTask *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021ED0A4 *v0 = slotsMinigameDTO;
    ov5_021EE294(v0);
}

static void ov5_021EE2D0(UnkStruct_ov5_021ED0A4 *param0, UnkStruct_ov5_021EE294 *slotsMinigameDTO)
{
    if (ov5_021ED94C(param0, slotsMinigameDTO->coins) != 2) {
        *(slotsMinigameDTO->unk_08) = ov5_021ECF1C(slotsMinigameDTO->slotMachineVariant, slotsMinigameDTO->coins);
        GF_ASSERT(*(slotsMinigameDTO->unk_08) != NULL);

        ov5_021EDD78(slotsMinigameDTO->slotMachineVariant, 0);

        if (MapObject_CheckStatusFlag(slotsMinigameDTO->slotMachineVariant, MAP_OBJ_STATUS_21) == 1) {
            sub_02062BA4(slotsMinigameDTO->slotMachineVariant);
        } else {
            sub_02062B68(slotsMinigameDTO->slotMachineVariant);
        }

        slotsMinigameDTO->slotMachineVariant = NULL;
        slotsMinigameDTO->unk_08 = NULL;
    }
}

static void ov5_021EE320(UnkStruct_ov5_021ED0A4 *param0, int slotsMinigameDTO, int param2)
{
    u32 v0, v1, v2, v3, v4;
    UnkStruct_ov5_021EDF3C *v5;

    v4 = (sizeof(UnkStruct_ov5_021EE294)) * slotsMinigameDTO;
    v3 = (sizeof(UnkStruct_ov5_021EDFBC)) * slotsMinigameDTO;
    v2 = (sizeof(UnkStruct_ov5_021EE134)) * slotsMinigameDTO;
    v1 = (sizeof(UnkStruct_ov5_021EDF3C)) + v2 + v3 + v4;
    v5 = Heap_Alloc(HEAP_ID_FIELD1, v1);

    GF_ASSERT(v5 != NULL);
    memset(v5, 0, v1);

    v5->coins = slotsMinigameDTO;
    v5->unk_02 = param2;

    v0 = (u32)v5 + (sizeof(UnkStruct_ov5_021EDF3C));
    v5->unk_08 = (void *)v0;

    v0 += v4;
    v5->slotsMinigameDTO = (void *)v0;

    v0 += v3;
    v5->unk_10 = (void *)v0;

    param0->unk_100 = v5;

    v0 = MapObjectMan_GetTaskBasePriority(param0->unk_104);
    v5->unk_18 = SysTask_Start(ov5_021EE030, param0, v0 + 1);
    v5->unk_1C = SysTask_Start(ov5_021EE2C4, param0, v0 + 2);
    v5->unk_20 = SysTask_ExecuteOnVBlank(ov5_021EE1AC, param0, 0xff);
    v5->unk_24 = SysTask_ExecuteAfterVBlank(ov5_021EE1E8, param0, 0xff);
}

static void ov5_021EE3C4(UnkStruct_ov5_021ED0A4 *param0)
{
    UnkStruct_ov5_021EDF3C *v0 = param0->unk_100;

    v0->unk_06 = 1;

    SysTask_Done(v0->unk_18);
    SysTask_Done(v0->unk_1C);
    SysTask_Done(v0->unk_20);
    SysTask_Done(v0->unk_24);
    Heap_Free(v0);

    param0->unk_100 = NULL;
}

Billboard *ov5_021EE3FC(MapObject *param0, int slotsMinigameDTO, UnkFuncPtr_ov5_021EE454 param2, void *param3)
{
    if ((ov5_021EDD94(param0) == 1) || (ov5_021EB1A0(param0) == NULL)) {
        int v0 = MapObject_GetGraphicsID(param0);
        const MapObjectManager *v1 = MapObject_MapObjectManager(param0);

        sub_02061B48(param0);
        ov5_021EDBC4(v1, v0, param0);
        sub_02061AB4(param0, slotsMinigameDTO);
        return NULL;
    }

    return ov5_021EE454(param0, slotsMinigameDTO, param2, param3);
}

static Billboard *ov5_021EE454(MapObject *param0, int slotsMinigameDTO, UnkFuncPtr_ov5_021EE454 param2, void *param3)
{
    VecFx32 v0;
    int v1, v2, v3, v4;
    TextureResource *v5;
    Billboard *v6;
    const ObjectEventGfxFileEntry *v7;
    UnkStruct_ov5_021ED0A4 *v8 = ov5_021EDEA8(param0);
    BillboardList *v9 = ov5_021EDC8C(v8);
    Billboard *v10 = ov5_021EB1A0(param0);
    UnkStruct_ov5_021EE698 *v11 = Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(UnkStruct_ov5_021EE698));

    memset(v11, 0, sizeof(UnkStruct_ov5_021EE698));

    v11->coins = slotsMinigameDTO;
    v11->unk_50 = param0;

    v2 = MapObject_GetGraphicsID(param0);

    {
        v1 = 0;
        v3 = ov5_021EDD2C(v2);
        v7 = gObjectEventGfxModelsTable;

        do {
            if (v7->id == v3) {
                break;
            }

            v7++;
            v1++;
        } while (v7->id != 0xffff);

        GF_ASSERT(v7->id != 0xffff);
        v11->unk_08 = ov5_021EDCF4(v8, v7->narcIdx, 0);
    }

    {
        v1 = 0;
        v3 = ov5_021EDD38(v2);
        v7 = gObjectEventGfxFrameSeqsTable;

        do {
            if (v7->id == v3) {
                break;
            }

            v7++;
            v1++;
        } while (v7->id != 0xffff);

        GF_ASSERT(v7->id != 0xffff);
        v11->slotsMinigameDTO = ov5_021EDCF4(v8, v7->narcIdx, 0);
        BillboardGfxSequence_SetData(v11->slotsMinigameDTO, &v11->unk_14);
    }

    {
        v1 = 0;
        v3 = v2;
        v7 = gObjectEventGfxTexturesTable;

        do {
            if (v7->id == v3) {
                break;
            }

            v7++;
            v1++;
        } while (v7->id != 0xffff);

        GF_ASSERT(v7->id != 0xffff);
        v11->unk_10 = ov5_021EDCF4(v8, v7->narcIdx, 0);
    }

    BillboardResources_SetWithoutKeys(&v11->unk_28, v11->unk_08, NNS_G3dGetTex(v11->unk_10), ov5_021EDD44(v2), &v11->unk_14);

    {
        const VecFx32 *v8 = Billboard_GetPos(v10);

        v0 = *v8;
        v11->unk_24 = ov5_021EDDDC(v9, &v11->unk_28, &v0, ov5_021EDD50(v2));
        GF_ASSERT(v11->unk_24 != NULL);
        v6 = v11->unk_24;
    }

    Billboard_SetRotMatrix(v11->unk_24, Billboard_GetRotMatrix(v10));
    Billboard_SetAnimNum(v11->unk_24, Billboard_GetAnimNum(v10));
    Billboard_SetAnimFrameNum(v11->unk_24, Billboard_GetAnimFrameNum(v10));
    Billboard_SetFrameNum(v11->unk_24, Billboard_GetFrameNum(v10));
    Billboard_AdvanceAnim(v11->unk_24, 0);
    Billboard_SetDrawFlag(v11->unk_24, 1);
    Billboard_TryRequestVRAMTransfer(v11->unk_24);

    {
        if (sub_02062F64(param0) == 1) {
            VecFx32 v12;
            int v13;
            int v14 = MapObject_CalculateTaskPriority(param0, 2);
            u8 v15 = MapObject_GetTileBehaviorFromDir(param0, 1);

            if (TileBehavior_IsReflective(v15) == 1) {
                v13 = 2;
            } else if (TileBehavior_IsPuddle(v15) == 1) {
                v13 = 0;
            } else {
                v13 = 1;
            }

            MapObject_GetPosPtr(param0, &v12);
            v11->unk_54 = ov5_021F1BA4(MapObject_GetFieldEffectManager(param0), &v11->unk_28, v11->unk_24, &v12, v13, v14);
        }
    }

    sub_02061B48(param0);
    ov5_021EDBC4(v8->unk_104, v2, param0);
    sub_02061AB4(param0, slotsMinigameDTO);

    {
        int v16 = MapObjectMan_GetTaskBasePriority(v8->unk_104);
        SysTask *v17 = SysTask_ExecuteAfterVBlank(ov5_021EE698, v11, 0xff);

        GF_ASSERT(v17 != NULL);
        ov5_021EE698(v17, v11);
    }

    if (Billboard_GetState(v11->unk_24) == 0) {
        v6 = NULL;
    } else {
        v11->unk_58 = param3;
        v11->unk_5C = param2;
    }

    return v6;
}

static void ov5_021EE698(SysTask *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021EE698 *v0 = slotsMinigameDTO;
    MapObject *v1 = v0->unk_50;

    switch (v0->slotMachineVariant) {
    case 0:
        if ((sub_02062CF8(v1) == 0) || (ov5_021EDD94(v1) == 0)) {
            if (v0->unk_5C != NULL) {
                v0->unk_5C(
                    v0->unk_58, v0->unk_24);
            }

            if (v0->unk_54 != NULL) {
                OverworldAnimManager_Finish(v0->unk_54);
            }

            Billboard_Delete(v0->unk_24);
            Heap_Free(v0->unk_08);
            Heap_Free(v0->slotsMinigameDTO);
            Heap_Free(v0->unk_10);
            Heap_Free(v0);
            SysTask_Done(param0);
            return;
        }

        if (MapObject_GetGraphicsID(v1) != v0->coins) {
            v0->slotMachineVariant++;
        }
        break;
    case 1:
        if (ov5_021EDD94(v1) == 0) {
            if (v0->unk_5C != NULL) {
                v0->unk_5C(
                    v0->unk_58, v0->unk_24);
            }

            if (v0->unk_54 != NULL) {
                OverworldAnimManager_Finish(v0->unk_54);
            }

            Billboard_Delete(v0->unk_24);
            Heap_Free(v0->unk_08);
            Heap_Free(v0->slotsMinigameDTO);
            Heap_Free(v0->unk_10);
            Heap_Free(v0);
            SysTask_Done(param0);
        }
    }
}
