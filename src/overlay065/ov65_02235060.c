#include "overlay065/ov65_02235060.h"

#include <nitro.h>
#include <string.h>

#include "overlay063/ov63_0222BCE8.h"
#include "overlay063/ov63_0222BE18.h"
#include "overlay063/ov63_0222CA88.h"
#include "overlay063/ov63_0222CCE4.h"
#include "overlay063/ov63_0222D160.h"
#include "overlay063/ov63_0222D1C0.h"
#include "overlay063/ov63_0222D77C.h"
#include "overlay063/struct_ov63_0222BEC0_decl.h"
#include "overlay063/struct_ov63_0222CC3C.h"
#include "overlay063/struct_ov63_0222CCB8.h"
#include "overlay063/struct_ov63_0222D894.h"
#include "overlay065/ov65_02236474.h"
#include "overlay065/struct_ov65_02235130.h"
#include "overlay065/struct_ov65_022354D8.h"
#include "overlay065/struct_ov65_0223582C.h"
#include "overlay065/struct_ov65_022358CC.h"
#include "overlay065/struct_ov65_02236318.h"
#include "overlay065/struct_ov65_022376D0.h"

#include "bg_window.h"
#include "graphics.h"
#include "heap.h"
#include "math_util.h"
#include "narc.h"
#include "sprite.h"
#include "sprite_resource.h"
#include "sprite_transfer.h"
#include "sprite_util.h"
#include "system.h"
#include "vram_transfer.h"

#define MCR_PCANM_DESTPL(x) ((7 * 32) + (((x) + 1) * 2))

typedef struct {
    u8 coins;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
} UnkStruct_ov65_02238BD7;

typedef struct {
    s16 coins;
    s16 unk_02;
} UnkStruct_ov65_02235C64;

static void ov65_0223560C(UnkStruct_ov65_02235130 *param0);
static BOOL ov65_02235634(const UnkStruct_ov65_02235130 *param0);
static BOOL ov65_02235654(const UnkStruct_ov65_02235130 *param0);
static void ov65_022356E8(UnkStruct_ov65_02235130 *param0);
static void ov65_0223573C(UnkStruct_ov65_02235130 *param0);
static void ov65_02235778(UnkStruct_ov65_02235130 *param0);
static const UnkStruct_ov65_022354D8 *ov65_022357A8(const UnkStruct_ov65_02235130 *param0, const UnkStruct_ov65_022354D8 *slotsMinigameDTO, int param2);
static void ov65_022357E8(UnkStruct_ov65_02235130 *param0, u32 slotsMinigameDTO, enum HeapID heapID);
static void ov65_0223581C(UnkStruct_ov65_02235130 *param0);
static void ov65_0223582C(UnkStruct_ov65_02235130 *param0, enum HeapID heapID, NARC *param2, u32 param3);
static void ov65_0223586C(UnkStruct_ov65_02235130 *param0);
static void ov65_0223587C(UnkStruct_ov65_022358CC *param0, enum HeapID heapID, NARC *param2);
static void ov65_022358CC(UnkStruct_ov65_022358CC *param0);
static void ov65_022358F8(UnkStruct_ov65_022358CC *param0, u32 slotsMinigameDTO, NARC *param2);
static void ov65_02235900(UnkStruct_ov65_022358CC *param0);
static void ov65_02235908(UnkStruct_ov65_022358CC *param0, u32 slotsMinigameDTO);
static void ov65_02235910(UnkStruct_ov65_022358CC *param0);
static void ov65_02235918(BgConfig *param0, u32 slotsMinigameDTO);
static void ov65_0223591C(BgConfig *param0);
static void ov65_02235920(BgConfig *param0, u32 slotsMinigameDTO, NARC *param2);
static BOOL ov65_02235BE8(UnkStruct_ov65_02235130 *param0);
static void ov65_02235960(UnkStruct_ov65_022358CC *param0, u32 slotsMinigameDTO, NARC *param2);
static void ov65_02235A60(UnkStruct_ov65_022358CC *param0);
static void ov65_02235A94(UnkStruct_ov65_022358CC *param0, u32 slotsMinigameDTO);
static void ov65_02235B14(UnkStruct_ov65_022358CC *param0);
static void ov65_02235B30(UnkStruct_ov65_02235130 *param0);
static void ov65_02235B78(UnkStruct_ov65_02235130 *param0);
static void ov65_02235B88(UnkStruct_ov65_02235130 *param0, UnkStruct_ov63_0222CC3C slotsMinigameDTO, u32 param2);
static void ov65_02235BD8(UnkStruct_ov65_02235130 *param0);
static void ov65_02235C64(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_02235C64 *slotsMinigameDTO, u32 param2);
static void ov65_02235D08(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_02235C64 *slotsMinigameDTO);
static UnkStruct_ov65_022354D8 *ov65_02235D7C(UnkStruct_ov65_02235130 *param0);
static void ov65_02235DAC(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO, BOOL param2);
static void ov65_02235DE4(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO, const UnkStruct_ov65_02235C64 *param2, u32 param3, u16 param4, u8 param5, int param6);
static BOOL ov65_02235E1C(const UnkStruct_ov65_022354D8 *param0);
static void ov65_02235E48(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO);
static void ov65_02235E68(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO);
static void ov65_02235E84(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO);
static void ov65_02235EC8(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO);
static void ov65_02235EF4(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO);
static void ov65_02235EF8(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO);
static void ov65_02235F94(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO);
static BOOL ov65_02236044(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO);
static BOOL ov65_02236158(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO);
static BOOL ov65_022361B0(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO);
static BOOL ov65_022361C8(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO);
static BOOL ov65_02236214(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO);
static BOOL ov65_0223622C(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO);
static void ov65_02236230(UnkStruct_ov65_02235130 *param0, s32 slotsMinigameDTO, s32 param2, s32 param3);
static void ov65_02236250(UnkStruct_ov65_02235130 *param0, s32 slotsMinigameDTO, const UnkStruct_ov65_022354D8 *param2);
static BOOL ov65_02236278(const UnkStruct_ov65_022354D8 *param0);
static void ov65_0223628C(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO, int param2);
static void ov65_022362B0(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_02236318 *slotsMinigameDTO, NARC *param2);
static void ov65_022362EC(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_02236318 *slotsMinigameDTO);
static void ov65_02236304(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_02236318 *slotsMinigameDTO);
static void ov65_02236318(UnkStruct_ov65_02236318 *param0);
static void ov65_02236384(UnkStruct_ov65_02236318 *param0);
static void *ov65_02236410(UnkStruct_ov65_02236318 *param0, u32 slotsMinigameDTO);
static void ov65_0223641C(UnkStruct_ov65_02236318 *param0);
static void ov65_02236438(UnkStruct_ov65_02236318 *param0);
static void ov65_02236440(UnkStruct_ov65_02236318 *param0, u8 slotsMinigameDTO);
static void ov65_02236464(UnkStruct_ov65_02236318 *param0);

static const UnkStruct_ov65_02238BD7 Unk_ov65_02238BD7[8] = {
    { 0x0, 0x0, 0x0, 0x1 },
    { 0x1, 0x2, 0x1, 0x0 },
    { 0x1, 0x4, 0x1, 0x1 },
    { 0x1, 0x2, 0x1, 0x0 },
    { 0x0, 0x0, 0x0, 0x1 },
    { 0x1, 0x2, 0x1, 0x1 },
    { 0x1, 0x4, 0x1, 0x0 },
    { 0x1, 0x3, 0x1, 0x1 }
};

static const u16 Unk_ov65_02238BC8[2] = {
    0x3,
    0x2
};

void ov65_02235060(UnkStruct_ov65_02235130 *param0, enum HeapID heapID, NARC *param2, BgConfig *param3, u32 param4, u32 param5)
{
    UnkStruct_ov63_0222CC3C v0;
    u32 v1;

    memset(param0, 0, sizeof(UnkStruct_ov65_02235130));

    v1 = (param5 - 1) / 8;

    param0->heapID = heapID;
    param0->unk_10 = param3;

    ov65_0223587C(&param0->unk_14, param0->heapID, param2);
    ov65_02235918(param0->unk_10, heapID);

    v0 = ov65_02236474(v1);
    param0->unk_748 = ov63_0222BCE8(v0.coins, v0.unk_02, heapID);
    ov63_0222BD50(param0->unk_748, ov65_02236480(v1));
    param0->unk_74C = ov63_0222BE18(48, heapID);

    ov65_022357E8(param0, param4, heapID);
    ov63_0222D19C(&param0->unk_754);
    ov65_0223582C(param0, heapID, param2, v1);
    ov65_02235920(param0->unk_10, heapID, param2);
    ov65_022362B0(param0, &param0->unk_734, param2);

    param0->unk_75C = ov63_0222D848(128, heapID);
    param0->coins = 1;
}

void ov65_02235130(UnkStruct_ov65_02235130 *param0)
{
    ov63_0222D880(param0->unk_75C);
    ov65_0223586C(param0);
    ov65_022362EC(param0, &param0->unk_734);
    ov65_0223560C(param0);
    ov65_0223581C(param0);
    ov63_0222BE58(param0->unk_74C);
    ov63_0222BD30(param0->unk_748);
    ov65_022358CC(&param0->unk_14);
    ov65_0223591C(param0->unk_10);

    memset(param0, 0, sizeof(UnkStruct_ov65_02235130));
}

BOOL ov65_02235194(const UnkStruct_ov65_02235130 *param0)
{
    return param0->coins;
}

u32 ov65_02235198(UnkStruct_ov65_02235130 *param0)
{
    BOOL v0;

    ov63_0222BE84(param0->unk_74C);
    ov65_0223573C(param0);
    ov65_022356E8(param0);
    ov63_0222D160(&param0->unk_754, param0->unk_730->coins);
    ov63_0222D228(param0->unk_758, &param0->unk_754);
    ov63_0222CEE4(param0->unk_750);
    ov65_02235778(param0);
    ov65_02235B78(param0);

    if (ov65_02235634(param0) == 1) {
        v0 = ov65_02235BE8(param0);

        if (v0 == 1) {
            ov65_02235B30(param0);

            if (gSystem.heldKeys & PAD_KEY_DOWN) {
                return 1;
            }
        }

        if (gSystem.pressedKeys & PAD_BUTTON_A) {
            if (ov65_02235254(param0) > 0) {
                return 2;
            } else if (ov65_02235654(param0) == 1) {
                return 3;
            }
        }
    }

    return 0;
}

void ov65_02235244(UnkStruct_ov65_02235130 *param0)
{
    if (param0->coins) {
        SpriteList_Update(param0->unk_14.coins);
    }
}

u8 ov65_02235254(const UnkStruct_ov65_02235130 *param0)
{
    GF_ASSERT(param0->unk_730 != NULL);
    return param0->unk_730->unk_0A;
}

u32 ov65_02235270(const UnkStruct_ov65_02235130 *param0)
{
    UnkStruct_ov63_0222CC3C v0;

    GF_ASSERT(param0->unk_730 != NULL);

    v0 = ov63_0222C0E4(param0->unk_730->coins);
    return ov63_0222BDE4(param0->unk_748, (v0.coins) / 16, (v0.unk_02) / 16);
}

u32 ov65_022352CC(const UnkStruct_ov65_02235130 *param0)
{
    UnkStruct_ov63_0222CC3C v0;

    GF_ASSERT(param0->unk_730 != NULL);

    v0 = ov63_0222C0E4(param0->unk_730->coins);
    return ov63_0222BDE4(param0->unk_748, (v0.coins) / 16, ((v0.unk_02) / 16) + 1);
}

void ov65_0223532C(UnkStruct_ov65_02235130 *param0, const UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    UnkStruct_ov63_0222CC3C v0;
    u32 v1;

    v0 = ov63_0222C0E4(slotsMinigameDTO->coins);
    v1 = ov63_0222D014(slotsMinigameDTO->slotMachineVariant);
    v1--;

    ov65_02235B88(param0, v0, v1 - 1);
}

void ov65_02235370(UnkStruct_ov65_02235130 *param0)
{
    ov65_02235BD8(param0);
}

void ov65_02235378(UnkStruct_ov65_02235130 *param0, BOOL slotsMinigameDTO)
{
    param0->slotsMinigameDTO = slotsMinigameDTO;
}

BOOL ov65_0223537C(const UnkStruct_ov65_02235130 *param0)
{
    return param0->slotsMinigameDTO;
}

UnkStruct_ov65_022354D8 *ov65_02235380(UnkStruct_ov65_02235130 *param0, u32 slotsMinigameDTO)
{
    UnkStruct_ov65_022354D8 *v0;
    UnkStruct_ov65_02235C64 v1;

    v0 = ov65_02235D7C(param0);

    param0->unk_730 = v0;

    ov65_02235D08(param0, &v1);
    ov65_02235DE4(param0, v0, &v1, 0, slotsMinigameDTO, 0, 0);
    ov65_02235E48(param0, v0);
    ov65_02235DAC(param0, v0, 1);
    ov63_0222D160(&param0->unk_754, param0->unk_730->coins);
    ov63_0222D228(param0->unk_758, &param0->unk_754);

    return v0;
}

UnkStruct_ov65_022354D8 *ov65_022353EC(UnkStruct_ov65_02235130 *param0, u32 slotsMinigameDTO, u8 param2)
{
    UnkStruct_ov65_022354D8 *v0;
    UnkStruct_ov65_02235C64 v1;
    UnkStruct_ov63_0222CC3C v2;

    v0 = ov65_02235D7C(param0);

    ov65_02235C64(param0, &v1, param2 - 1);

    if (param0->unk_730) {
        v2 = ov63_0222C0E4(param0->unk_730->coins);

        if ((v2.coins == v1.coins) && (v2.unk_02 == v1.unk_02)) {
            return NULL;
        }
    }

    ov65_02235DE4(param0, v0, &v1, param2, slotsMinigameDTO, 1, 4);
    ov65_02235E68(param0, v0);
    ov65_02235DAC(param0, v0, 0);

    return v0;
}

void ov65_02235478(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    s32 v0 = ov63_0222BF90(slotsMinigameDTO->coins, 6);

    slotsMinigameDTO->unk_10 = ov65_022361B0;
    slotsMinigameDTO->unk_18 = ov65_02235EF8;
    slotsMinigameDTO->slotsMinigameDTO = 2;
    slotsMinigameDTO->unk_08 = 0;

    ov63_0222CFA4(slotsMinigameDTO->slotMachineVariant, 0);
    ov63_0222CFA8(slotsMinigameDTO->slotMachineVariant);
    ov65_02236250(param0, 4, slotsMinigameDTO);
}

void ov65_022354B8(UnkStruct_ov65_022354D8 *param0)
{
    ov63_0222CECC(param0->slotMachineVariant);
    ov63_0222BF08(param0->coins);

    memset(param0, 0, sizeof(UnkStruct_ov65_022354D8));
}

u8 ov65_022354D8(const UnkStruct_ov65_022354D8 *param0)
{
    return ov63_0222BF90(param0->coins, 4);
}

int ov65_022354E8(const UnkStruct_ov65_022354D8 *param0)
{
    int v0 = ov63_0222BF90(param0->coins, 6);
    return ov63_0222C0AC(v0);
}

void ov65_022354F8(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO, int param2)
{
    u32 v0;
    UnkStruct_ov63_0222CC3C v1;

    slotsMinigameDTO->unk_14 = slotsMinigameDTO->unk_10;
    slotsMinigameDTO->unk_10 = ov65_0223622C;
    slotsMinigameDTO->unk_0E = slotsMinigameDTO->slotsMinigameDTO;
    slotsMinigameDTO->slotsMinigameDTO = 5;

    v0 = ov63_0222BF90(slotsMinigameDTO->coins, 4);

    ov65_02236230(param0, 0, param2, v0);
    ov63_0222CFA4(slotsMinigameDTO->slotMachineVariant, 0);
    ov63_0222D020(slotsMinigameDTO->slotMachineVariant, param2);

    v1.coins = ov63_0222BF90(slotsMinigameDTO->coins, 0);
    v1.unk_02 = ov63_0222BF90(slotsMinigameDTO->coins, 1);

    ov63_0222CFE0(slotsMinigameDTO->slotMachineVariant, v1);
}

void ov65_0223556C(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    if (slotsMinigameDTO == NULL) {
        return;
    }

    if (slotsMinigameDTO->unk_14 == NULL) {
        return;
    }

    slotsMinigameDTO->unk_10 = slotsMinigameDTO->unk_14;
    slotsMinigameDTO->unk_14 = NULL;
    slotsMinigameDTO->slotsMinigameDTO = slotsMinigameDTO->unk_0E;

    ov63_0222CFA4(slotsMinigameDTO->slotMachineVariant, 1);
}

void ov65_0223558C(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO, int param2)
{
    BOOL v0 = ov65_02236278(slotsMinigameDTO);

    if (v0 == 0) {
        slotsMinigameDTO->unk_0B = param2;
    } else {
        ov65_0223628C(param0, slotsMinigameDTO, param2);
    }
}

void ov65_022355B0(UnkStruct_ov65_02235130 *param0)
{
    s8 v0;

    if (ov65_02235654(param0) == 1) {
        v0 = ov65_022352CC(param0);
        v0 -= 3;

        GF_ASSERT((v0 >= 0) && (v0 < 4));

        ov65_02236440(&param0->unk_734, v0);
        return;
    }

    GF_ASSERT(FALSE);
}

void ov65_022355EC(UnkStruct_ov65_02235130 *param0)
{
    ov65_02236464(&param0->unk_734);
}

void ov65_022355FC(UnkStruct_ov65_02235130 *param0)
{
    ov65_02236304(param0, &param0->unk_734);
}

static void ov65_0223560C(UnkStruct_ov65_02235130 *param0)
{
    int v0;

    for (v0 = 0; v0 < 48; v0++) {
        if (param0->unk_1F0[v0].coins != NULL) {
            ov65_022354B8(&param0->unk_1F0[v0]);
        }
    }
}

static BOOL ov65_02235634(const UnkStruct_ov65_02235130 *param0)
{
    s32 v0 = ov63_0222BF90(param0->unk_730->coins, 5);

    if (v0 == 0) {
        return 1;
    }

    return 0;
}

static BOOL ov65_02235654(const UnkStruct_ov65_02235130 *param0)
{
    u32 v0;
    UnkStruct_ov63_0222CC3C v1;
    int v2;

    v1 = ov63_0222C0E4(param0->unk_730->coins);
    v2 = ov63_0222BF90(param0->unk_730->coins, 6);
    v1 = ov63_0222C078(v1, v2);
    v0 = ov63_0222BDE4(param0->unk_748, (v1.coins) / 16, (v1.unk_02) / 16);

    if (v2 == 0) {
        if (v0 == 2) {
            return 1;
        }
    }

    return 0;
}

static void ov65_022356E8(UnkStruct_ov65_02235130 *param0)
{
    UnkStruct_ov63_0222D894 v0;
    UnkStruct_ov63_0222CCB8 v1;
    BOOL v2;

    while (ov63_0222D8D0(param0->unk_75C, &v0) == 1) {
        v2 = ov63_0222CA88(param0->unk_748, param0->unk_74C, &v0, &v1);

        if (v2 == 1) {
            ov63_0222BE70(param0->unk_74C, &v1);
        }
    }
}

static void ov65_0223573C(UnkStruct_ov65_02235130 *param0)
{
    int v0;
    BOOL v1;

    for (v0 = 0; v0 < 48; v0++) {
        if (param0->unk_1F0[v0].coins != NULL) {
            v1 = param0->unk_1F0[v0].unk_10(param0, &param0->unk_1F0[v0]);

            if (v1 == 1) {
                ov65_022354B8(&param0->unk_1F0[v0]);
            }
        }
    }
}

static void ov65_02235778(UnkStruct_ov65_02235130 *param0)
{
    int v0;

    for (v0 = 0; v0 < 48; v0++) {
        if (param0->unk_1F0[v0].coins != NULL) {
            param0->unk_1F0[v0].unk_18(param0, &param0->unk_1F0[v0]);
        }
    }
}

static const UnkStruct_ov65_022354D8 *ov65_022357A8(const UnkStruct_ov65_02235130 *param0, const UnkStruct_ov65_022354D8 *slotsMinigameDTO, int param2)
{
    const UnkStruct_ov63_0222BEC0 *v0;
    int v1;

    v0 = ov63_0222C1C4(slotsMinigameDTO->coins, param0->unk_74C, param2);

    if (v0 != NULL) {
        for (v1 = 0; v1 < 48; v1++) {
            if (param0->unk_1F0[v1].coins == v0) {
                return &param0->unk_1F0[v1];
            }
        }
    }

    return NULL;
}

static void ov65_022357E8(UnkStruct_ov65_02235130 *param0, u32 slotsMinigameDTO, enum HeapID heapID)
{
    int v0;

    param0->unk_750 = ov63_0222CD2C(param0->unk_14.coins, NULL, 48, slotsMinigameDTO, 0, NNS_G2D_VRAM_TYPE_2DMAIN, heapID);

    ov63_0222CE30(param0->unk_750, 2, heapID);
}

static void ov65_0223581C(UnkStruct_ov65_02235130 *param0)
{
    ov63_0222CD9C(param0->unk_750);
}

static void ov65_0223582C(UnkStruct_ov65_02235130 *param0, enum HeapID heapID, NARC *param2, u32 param3)
{
    UnkStruct_ov65_0223582C v0 = {
        0,
        0,
        GX_BG_COLORMODE_16,
        GX_BG_SCRBASE_0xe000,
        GX_BG_CHARBASE_0x00000,
        GX_BG_EXTPLTT_01,
        3,
        0,
        92,
        32,
        0
    };

    v0.unk_09 += param3;
    param0->unk_758 = ov63_0222D1C0(&param0->unk_14.slotMachineVariant, param0->unk_10, &v0, heapID);
}

static void ov65_0223586C(UnkStruct_ov65_02235130 *param0)
{
    ov63_0222D214(param0->unk_758);
}

static void ov65_0223587C(UnkStruct_ov65_022358CC *param0, enum HeapID heapID, NARC *param2)
{
    int i;

    param0->coins = SpriteList_InitRendering(96, &param0->slotMachineVariant, heapID);
    SetSubScreenViewRect(&param0->slotMachineVariant, 0, (800 * FX32_ONE));

    for (i = 0; i < 4; i++) {
        param0->unk_190[i] = SpriteResourceCollection_New(16, i, heapID);
    }

    ov65_022358F8(param0, heapID, param2);
    ov65_02235908(param0, heapID);
}

static void ov65_022358CC(UnkStruct_ov65_022358CC *param0)
{
    int v0;

    ov65_02235910(param0);
    ov65_02235900(param0);

    for (v0 = 0; v0 < 4; v0++) {
        SpriteResourceCollection_Delete(param0->unk_190[v0]);
    }

    SpriteList_Delete(param0->coins);
}

static void ov65_022358F8(UnkStruct_ov65_022358CC *param0, u32 slotsMinigameDTO, NARC *param2)
{
    ov65_02235960(param0, slotsMinigameDTO, param2);
}

static void ov65_02235900(UnkStruct_ov65_022358CC *param0)
{
    ov65_02235A60(param0);
}

static void ov65_02235908(UnkStruct_ov65_022358CC *param0, u32 slotsMinigameDTO)
{
    ov65_02235A94(param0, slotsMinigameDTO);
}

static void ov65_02235910(UnkStruct_ov65_022358CC *param0)
{
    ov65_02235B14(param0);
}

static void ov65_02235918(BgConfig *param0, u32 slotsMinigameDTO)
{
    return;
}

static void ov65_0223591C(BgConfig *param0)
{
    return;
}

static void ov65_02235920(BgConfig *param0, u32 slotsMinigameDTO, NARC *param2)
{
    Graphics_LoadPaletteFromOpenNARC(param2, 30, 0, 0, 8 * 32, slotsMinigameDTO);
    Bg_MaskPalette(BG_LAYER_MAIN_0, 0);
    Graphics_LoadTilesToBgLayerFromOpenNARC(param2, 29, param0, 0, 0, 0, 0, slotsMinigameDTO);
}

static void ov65_02235960(UnkStruct_ov65_022358CC *param0, u32 slotsMinigameDTO, NARC *param2)
{
    BOOL v0;

    param0->unk_1A0.coins[0] = SpriteResourceCollection_AddTilesFrom(param0->unk_190[0], param2, 37, 0, 50, NNS_G2D_VRAM_TYPE_2DMAIN, slotsMinigameDTO);
    param0->unk_1A0.coins[1] = SpriteResourceCollection_AddPaletteFrom(param0->unk_190[1], param2, 36, 0, 50, NNS_G2D_VRAM_TYPE_2DMAIN, 1, slotsMinigameDTO);
    param0->unk_1A0.coins[2] = SpriteResourceCollection_AddFrom(param0->unk_190[2], param2, 38, 0, 50, 2, slotsMinigameDTO);
    param0->unk_1A0.coins[3] = SpriteResourceCollection_AddFrom(param0->unk_190[3], param2, 39, 0, 50, 3, slotsMinigameDTO);

    v0 = SpriteTransfer_RequestCharAtEnd(param0->unk_1A0.coins[0]);
    GF_ASSERT(v0 == 1);

    v0 = SpriteTransfer_RequestPlttFreeSpace(param0->unk_1A0.coins[1]);
    GF_ASSERT(v0 == 1);

    SpriteResource_ReleaseData(param0->unk_1A0.coins[0]);
    SpriteResource_ReleaseData(param0->unk_1A0.coins[1]);
    SpriteResourcesHeader_Init(&param0->unk_1A0.unk_10, 50, 50, 50, 50, 0xffffffff, 0xffffffff, 0, 2, param0->unk_190[0], param0->unk_190[1], param0->unk_190[2], param0->unk_190[3], NULL, NULL);
}

static void ov65_02235A60(UnkStruct_ov65_022358CC *param0)
{
    int v0;

    SpriteTransfer_ResetCharTransfer(param0->unk_1A0.coins[0]);
    SpriteTransfer_ResetPlttTransfer(param0->unk_1A0.coins[1]);

    for (v0 = 0; v0 < 4; v0++) {
        SpriteResourceCollection_Remove(param0->unk_190[v0], param0->unk_1A0.coins[v0]);
    }
}

static void ov65_02235A94(UnkStruct_ov65_022358CC *param0, u32 slotsMinigameDTO)
{
    AffineSpriteListTemplate v0;

    memset(&v0, 0, sizeof(AffineSpriteListTemplate));

    v0.list = param0->coins;
    v0.resourceData = &param0->unk_1A0.unk_10;
    v0.vramType = NNS_G2D_VRAM_TYPE_2DMAIN;
    v0.affineScale.x = FX32_ONE;
    v0.affineScale.y = FX32_ONE;
    v0.priority = 0;
    v0.heapID = slotsMinigameDTO;

    param0->unk_1A0.unk_34 = SpriteList_AddAffine(&v0);
    param0->unk_1A0.unk_38 = SpriteList_AddAffine(&v0);

    Sprite_SetDrawFlag(param0->unk_1A0.unk_34, FALSE);
    Sprite_SetDrawFlag(param0->unk_1A0.unk_38, FALSE);
    Sprite_SetAnimateFlag(param0->unk_1A0.unk_34, 1);
    Sprite_SetAnim(param0->unk_1A0.unk_38, 1);
}

static void ov65_02235B14(UnkStruct_ov65_022358CC *param0)
{
    Sprite_Delete(param0->unk_1A0.unk_34);
    Sprite_Delete(param0->unk_1A0.unk_38);
}

static void ov65_02235B30(UnkStruct_ov65_02235130 *param0)
{
    UnkStruct_ov65_02235C64 v0;
    VecFx32 v1;

    ov65_02235D08(param0, &v0);

    v0.coins += 8;
    v0.unk_02 += 32;

    v1.x = v0.coins << FX32_SHIFT;
    v1.y = v0.unk_02 << FX32_SHIFT;

    Sprite_SetPosition(param0->unk_14.unk_1A0.unk_34, &v1);
    Sprite_SetDrawFlag(param0->unk_14.unk_1A0.unk_34, TRUE);
}

static void ov65_02235B78(UnkStruct_ov65_02235130 *param0)
{
    Sprite_SetDrawFlag(param0->unk_14.unk_1A0.unk_34, FALSE);
}

static void ov65_02235B88(UnkStruct_ov65_02235130 *param0, UnkStruct_ov63_0222CC3C slotsMinigameDTO, u32 param2)
{
    VecFx32 v0;

    slotsMinigameDTO.coins += 8;
    slotsMinigameDTO.unk_02 += 0;

    v0.x = slotsMinigameDTO.coins << FX32_SHIFT;
    v0.y = slotsMinigameDTO.unk_02 << FX32_SHIFT;

    Sprite_SetPosition(param0->unk_14.unk_1A0.unk_38, &v0);
    Sprite_SetPriority(param0->unk_14.unk_1A0.unk_38, param2);
    Sprite_SetDrawFlag(param0->unk_14.unk_1A0.unk_38, TRUE);
}

static void ov65_02235BD8(UnkStruct_ov65_02235130 *param0)
{
    Sprite_SetDrawFlag(param0->unk_14.unk_1A0.unk_38, FALSE);
}

static BOOL ov65_02235BE8(UnkStruct_ov65_02235130 *param0)
{
    UnkStruct_ov63_0222CC3C v0;
    u32 v1;
    int v2;

    if (param0->unk_730 == NULL) {
        return 0;
    }

    v0 = ov63_0222C0E4(param0->unk_730->coins);
    v2 = ov63_0222BF90(param0->unk_730->coins, 6);
    v1 = ov63_0222BDE4(param0->unk_748, (v0.coins) / 16, (v0.unk_02) / 16);

    if ((v1 == 15) && (v2 == 1)) {
        return 1;
    }

    return 0;
}

static void ov65_02235C64(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_02235C64 *slotsMinigameDTO, u32 param2)
{
    u32 v0;
    u32 v1;
    int v2, v3;
    u32 v4, v5;
    u32 v6;
    u32 v7;

    v0 = param2 / 8;
    v1 = param2 % 8;
    v4 = ov63_0222BD48(param0->unk_748);
    v5 = ov63_0222BD4C(param0->unk_748);

    for (v2 = 0; v2 < v5; v2++) {
        for (v3 = 0; v3 < v4; v3++) {
            v6 = ov63_0222BDE4(param0->unk_748, v3, v2);

            if (v6 == 7 + v1) {
                v7 = ov63_0222BDE4(param0->unk_748, v3, v2 + 1);

                if (v7 == v0 + 3) {
                    slotsMinigameDTO->coins = (v3) * 16;
                    slotsMinigameDTO->unk_02 = (v2) * 16;
                    return;
                }
            }
        }
    }

    GF_ASSERT(FALSE);
}

static void ov65_02235D08(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_02235C64 *slotsMinigameDTO)
{
    int v0, v1;
    u32 v2, v3;
    u32 v4;

    v2 = ov63_0222BD48(param0->unk_748);
    v3 = ov63_0222BD4C(param0->unk_748);

    for (v0 = 0; v0 < v3; v0++) {
        for (v1 = 0; v1 < v2; v1++) {
            v4 = ov63_0222BDE4(param0->unk_748, v1, v0);

            if (v4 == 15) {
                slotsMinigameDTO->coins = (v1) * 16;
                slotsMinigameDTO->unk_02 = (v0) * 16;

                return;
            }
        }
    }

    GF_ASSERT(FALSE);
}

static UnkStruct_ov65_022354D8 *ov65_02235D7C(UnkStruct_ov65_02235130 *param0)
{
    int v0;

    for (v0 = 0; v0 < 48; v0++) {
        if (param0->unk_1F0[v0].coins == NULL) {
            return &param0->unk_1F0[v0];
        }
    }

    GF_ASSERT(FALSE);
    return NULL;
}

static void ov65_02235DAC(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO, BOOL param2)
{
    slotsMinigameDTO->slotMachineVariant = ov63_0222CE44(param0->unk_750, slotsMinigameDTO->coins, param2, param0->heapID);

    if (param2 == 0) {
        ov63_0222CFA4(slotsMinigameDTO->slotMachineVariant, 0);
        ov63_0222CFA8(slotsMinigameDTO->slotMachineVariant);
        ov63_0222D008(slotsMinigameDTO->slotMachineVariant, 0);
    }
}

static void ov65_02235DE4(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO, const UnkStruct_ov65_02235C64 *param2, u32 param3, u16 param4, u8 param5, int param6)
{
    UnkStruct_ov65_022376D0 v0;

    v0.coins = param2->coins;
    v0.unk_02 = param2->unk_02;
    v0.slotMachineVariant = param3;
    v0.unk_06 = param6;
    v0.unk_08 = param5;
    v0.unk_0A = param4;

    slotsMinigameDTO->coins = ov63_0222BEC0(param0->unk_74C, &v0);
}

static BOOL ov65_02235E1C(const UnkStruct_ov65_022354D8 *param0)
{
    switch (param0->slotsMinigameDTO) {
    case 0:
    case 3:
    case 4:
        return 1;
    case 1:
    case 2:
    case 5:
        return 0;
    default:
        break;
    }

    return 0;
}

static void ov65_02235E48(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    slotsMinigameDTO->unk_10 = ov65_02236044;
    slotsMinigameDTO->unk_18 = ov65_02235EF4;
    slotsMinigameDTO->slotsMinigameDTO = 0;

    ov65_02236250(param0, 0, slotsMinigameDTO);
}

static void ov65_02235E68(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    slotsMinigameDTO->unk_10 = ov65_02236158;
    slotsMinigameDTO->unk_18 = ov65_02235EF8;
    slotsMinigameDTO->unk_08 = 45;
    slotsMinigameDTO->slotsMinigameDTO = 1;
}

static void ov65_02235E84(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    slotsMinigameDTO->unk_10 = ov65_022361C8;
    slotsMinigameDTO->unk_18 = ov65_02235EF4;
    slotsMinigameDTO->unk_08 = 256 + (MTRNG_Next() % 1024);
    slotsMinigameDTO->slotsMinigameDTO = 3;

    ov65_02236250(param0, 0, slotsMinigameDTO);
    ov63_0222CFA4(slotsMinigameDTO->slotMachineVariant, 1);
}

static void ov65_02235EC8(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    slotsMinigameDTO->unk_10 = ov65_02236214;
    slotsMinigameDTO->unk_18 = ov65_02235F94;
    slotsMinigameDTO->unk_08 = ((6 * 2) + 16);
    slotsMinigameDTO->slotsMinigameDTO = 4;

    ov65_02236250(param0, 4, slotsMinigameDTO);
    ov63_0222CFA4(slotsMinigameDTO->slotMachineVariant, 0);
}

static void ov65_02235EF4(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    return;
}

static void ov65_02235EF8(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    UnkStruct_ov63_0222CC3C v0, v1;

    ov63_0222CFB4(slotsMinigameDTO->slotMachineVariant);

    if (ov63_0222CFFC(slotsMinigameDTO->slotMachineVariant) == 0) {
        ov63_0222D008(slotsMinigameDTO->slotMachineVariant, 1);
    }

    v0.coins = ov63_0222BF90(slotsMinigameDTO->coins, 0);
    v0.unk_02 = ov63_0222BF90(slotsMinigameDTO->coins, 1);

    v1 = v0;
    v0.unk_02 += FX_Mul(CalcSineDegrees(slotsMinigameDTO->unk_08), -192 * FX32_ONE) >> FX32_SHIFT;

    ov63_0222CFE0(slotsMinigameDTO->slotMachineVariant, v0);
    ov63_0222D060(slotsMinigameDTO->slotMachineVariant, v1);
}

static void ov65_02235F94(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    u32 v0;
    UnkStruct_ov63_0222CC3C v1, v2;
    s16 v3;

    v1.coins = ov63_0222BF90(slotsMinigameDTO->coins, 0);
    v1.unk_02 = ov63_0222BF90(slotsMinigameDTO->coins, 1);

    v2 = v1;
    v3 = slotsMinigameDTO->unk_08 - 16;

    if (v3 > 0) {
        v3 = v3 % 6;
        v0 = (180 * v3) / 6;
        v1.unk_02 -= FX_Mul(CalcSineDegrees(v0), 4 * FX32_ONE) >> FX32_SHIFT;
    }

    ov63_0222CFE0(slotsMinigameDTO->slotMachineVariant, v1);
    ov63_0222D060(slotsMinigameDTO->slotMachineVariant, v2);
    ov63_0222D020(slotsMinigameDTO->slotMachineVariant, 1);
}

static BOOL ov65_02236044(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    s32 v0;
    s32 v1;
    s32 v2;
    s32 v3;
    const UnkStruct_ov65_022354D8 *v4;

    v0 = ov63_0222BF90(slotsMinigameDTO->coins, 6);
    v1 = ov63_0222BF90(slotsMinigameDTO->coins, 4);
    v2 = ov63_0222BF90(slotsMinigameDTO->coins, 5);

    if (v2 != 0) {
        return 0;
    }

    if (gSystem.pressedKeys & PAD_BUTTON_A) {
        v4 = ov65_022357A8(param0, slotsMinigameDTO, v0);

        if (v4 != NULL) {
            if (ov65_02235E1C(v4) == 1) {
                slotsMinigameDTO->unk_0A = ov63_0222BF90(v4->coins, 4);
            } else {
                slotsMinigameDTO->unk_0A = 0;
            }
        } else {
            slotsMinigameDTO->unk_0A = 0;
        }
    }

    if (param0->slotsMinigameDTO == 1) {
        return 0;
    }

    if (gSystem.heldKeys & PAD_BUTTON_B) {
        v3 = 3;
    } else {
        v3 = 2;
    }

    if (gSystem.heldKeys & PAD_KEY_UP) {
        if (v0 == 0) {
            ov65_02236230(param0, v3, v0, v1);
        } else {
            ov65_02236230(param0, 1, 0, v1);
        }
    } else if (gSystem.heldKeys & PAD_KEY_DOWN) {
        if (v0 == 1) {
            ov65_02236230(param0, v3, v0, v1);
        } else {
            ov65_02236230(param0, 1, 1, v1);
        }
    } else if (gSystem.heldKeys & PAD_KEY_LEFT) {
        if (v0 == 2) {
            ov65_02236230(param0, v3, v0, v1);
        } else {
            ov65_02236230(param0, 1, 2, v1);
        }
    } else if (gSystem.heldKeys & PAD_KEY_RIGHT) {
        if (v0 == 3) {
            ov65_02236230(param0, v3, v0, v1);
        } else {
            ov65_02236230(param0, 1, 3, v1);
        }
    }

    return 0;
}

static BOOL ov65_02236158(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    s32 v0;
    u32 v1, v2;

    slotsMinigameDTO->unk_08--;

    if (slotsMinigameDTO->unk_08 <= 0) {
        ov63_0222CFC0(slotsMinigameDTO->slotMachineVariant);
        ov63_0222CFA4(slotsMinigameDTO->slotMachineVariant, 1);

        v1 = ov63_0222BF90(param0->unk_730->coins, 4);
        v2 = ov63_0222BF90(slotsMinigameDTO->coins, 4);

        if (v2 == v1) {
            ov65_02235E48(param0, slotsMinigameDTO);
        } else {
            ov65_0223628C(param0, slotsMinigameDTO, slotsMinigameDTO->unk_0B);
        }
    }

    return 0;
}

static BOOL ov65_022361B0(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    slotsMinigameDTO->unk_08++;

    if (slotsMinigameDTO->unk_08 > 45) {
        return 1;
    }

    return 0;
}

static BOOL ov65_022361C8(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    u32 v0;
    u32 v1;

    slotsMinigameDTO->unk_08--;

    if (slotsMinigameDTO->unk_08 <= 0) {
        slotsMinigameDTO->unk_08 = 256 + (MTRNG_Next() % 1024);

        v0 = MTRNG_Next() % 4;
        v1 = ov63_0222BF90(slotsMinigameDTO->coins, 4);

        ov65_02236230(param0, 0, v0, v1);
    }

    return 0;
}

static BOOL ov65_02236214(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    slotsMinigameDTO->unk_08--;

    if (slotsMinigameDTO->unk_08 < 0) {
        slotsMinigameDTO->unk_08 = ((6 * 2) + 16);
    }

    return 0;
}

static BOOL ov65_0223622C(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO)
{
    return 0;
}

static void ov65_02236230(UnkStruct_ov65_02235130 *param0, s32 slotsMinigameDTO, s32 param2, s32 param3)
{
    UnkStruct_ov63_0222D894 v0;

    v0.coins = slotsMinigameDTO;
    v0.unk_02 = param2;
    v0.unk_03 = param3;

    ov63_0222D894(param0->unk_75C, &v0);
}

static void ov65_02236250(UnkStruct_ov65_02235130 *param0, s32 slotsMinigameDTO, const UnkStruct_ov65_022354D8 *param2)
{
    s32 v0;
    s32 v1;

    v0 = ov63_0222BF90(param2->coins, 6);
    v1 = ov63_0222BF90(param2->coins, 4);

    ov65_02236230(param0, slotsMinigameDTO, v0, v1);
}

static BOOL ov65_02236278(const UnkStruct_ov65_022354D8 *param0)
{
    if ((u32)param0->unk_18 == (u32)ov65_02235EF8) {
        return 0;
    }

    return 1;
}

static void ov65_0223628C(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_022354D8 *slotsMinigameDTO, int param2)
{
    switch (param2) {
    case 0:
        ov65_02235E84(param0, slotsMinigameDTO);
        break;
    case 1:
        ov65_02235EC8(param0, slotsMinigameDTO);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }

    slotsMinigameDTO->unk_0B = param2;
}

static void ov65_022362B0(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_02236318 *slotsMinigameDTO, NARC *param2)
{
    memset(slotsMinigameDTO, 0, sizeof(UnkStruct_ov65_02236318));

    slotsMinigameDTO->coins = Graphics_GetPlttDataFromOpenNARC(param2, 31, &slotsMinigameDTO->slotMachineVariant, param0->heapID);
    slotsMinigameDTO->unk_08 = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
    slotsMinigameDTO->unk_09 = 0;
    slotsMinigameDTO->unk_0A = Unk_ov65_02238BC8[slotsMinigameDTO->unk_09];
}

static void ov65_022362EC(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_02236318 *slotsMinigameDTO)
{
    Heap_Free(slotsMinigameDTO->coins);
    memset(slotsMinigameDTO, 0, sizeof(UnkStruct_ov65_02236318));
}

static void ov65_02236304(UnkStruct_ov65_02235130 *param0, UnkStruct_ov65_02236318 *slotsMinigameDTO)
{
    ov65_02236318(slotsMinigameDTO);
    ov65_02236384(slotsMinigameDTO);
}

static void ov65_02236318(UnkStruct_ov65_02236318 *param0)
{
    int v0;
    u32 v1;

    param0->unk_0A--;

    if (param0->unk_0A <= 0) {
        param0->unk_09 = (param0->unk_09 + 1) % 2;
        param0->unk_0A = Unk_ov65_02238BC8[param0->unk_09];

        if (param0->unk_09 == 1) {
            v1 = 2;
        } else {
            v1 = 1;
        }

        for (v0 = 0; v0 < 4; v0++) {
            if (param0->unk_08 & (1 << v0)) {
                VramTransfer_Request(NNS_GFD_DST_2D_BG_PLTT_MAIN, MCR_PCANM_DESTPL(v0), ov65_02236410(param0, v1), 2);
            }
        }
    }
}

static void ov65_02236384(UnkStruct_ov65_02236318 *param0)
{
    BOOL v0 = 0;
    u32 v1 = 0;
    BOOL v2 = 0;

    if (Unk_ov65_02238BD7[param0->unk_0D].coins == 1) {
        param0->unk_0E--;

        if (param0->unk_0E <= 0) {
            v2 = 1;
        }
    } else {
        if (param0->unk_10) {
            param0->unk_10 = 0;
            v2 = 1;
        }
    }

    if (v2) {
        param0->unk_0D++;

        if (param0->unk_0D >= 8) {
            ov65_0223641C(param0);
            return;
        }

        param0->unk_0E = Unk_ov65_02238BD7[param0->unk_0D].unk_01;

        v0 = Unk_ov65_02238BD7[param0->unk_0D].unk_02;
        v1 = Unk_ov65_02238BD7[param0->unk_0D].unk_03;
    }

    if (v0) {
        VramTransfer_Request(NNS_GFD_DST_2D_BG_PLTT_MAIN, MCR_PCANM_DESTPL(param0->slotsMinigameDTO), ov65_02236410(param0, v1), 2);
    }
}

static void *ov65_02236410(UnkStruct_ov65_02236318 *param0, u32 slotsMinigameDTO)
{
    u16 *v0 = (u16 *)param0->slotMachineVariant->pRawData;
    return &v0[slotsMinigameDTO + 1];
}

static void ov65_0223641C(UnkStruct_ov65_02236318 *param0)
{
    param0->unk_08 |= 1 << param0->slotsMinigameDTO;
    param0->slotsMinigameDTO = 0;
    param0->unk_0D = 0;
    param0->unk_0E = 0;
    param0->unk_10 = 0;
}

static void ov65_02236438(UnkStruct_ov65_02236318 *param0)
{
    param0->unk_10 = 1;
}

static void ov65_02236440(UnkStruct_ov65_02236318 *param0, u8 slotsMinigameDTO)
{
    if (param0->unk_0D != 0) {
        ov65_0223641C(param0);
    }

    param0->unk_08 ^= 1 << slotsMinigameDTO;
    param0->slotsMinigameDTO = slotsMinigameDTO;

    ov65_02236438(param0);
}

static void ov65_02236464(UnkStruct_ov65_02236318 *param0)
{
    if (param0->unk_0D != 0) {
        ov65_02236438(param0);
    }
}
