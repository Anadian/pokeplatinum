#include "applications/pokedex/ov21_021E1924.h"

#include <nitro.h>
#include <string.h>

#include "applications/pokedex/infomain.h"
#include "applications/pokedex/infomain_foreign.h"
#include "applications/pokedex/ov21_021D4340.h"
#include "applications/pokedex/ov21_021E29DC.h"
#include "applications/pokedex/pokedex_app.h"
#include "applications/pokedex/pokedex_data_manager.h"
#include "applications/pokedex/pokedex_graphics.h"
#include "applications/pokedex/pokedex_graphics_manager.h"
#include "applications/pokedex/pokedex_main.h"
#include "applications/pokedex/pokedex_sort.h"
#include "applications/pokedex/pokedex_sort_data.h"
#include "applications/pokedex/pokedex_text.h"
#include "applications/pokedex/pokedex_text_manager.h"
#include "applications/pokedex/struct_ov21_021D4660.h"
#include "applications/pokedex/struct_ov21_021E68F4.h"

#include "bg_window.h"
#include "brightness_controller.h"
#include "heap.h"
#include "narc.h"
#include "pltt_transfer.h"
#include "sound_playback.h"
#include "sprite.h"
#include "sprite_resource.h"
#include "sprite_transfer.h"
#include "sprite_util.h"
#include "system.h"
#include "touch_screen.h"
#include "touch_screen_actions.h"
#include "unk_02012744.h"
#include "vram_transfer.h"

#include "res/graphics/pokedex/zukan.naix"
#include "res/text/bank/pokedex.h"

typedef struct {
    int *coins;
    PokedexSortData *slotMachineVariant;
    InfoMainState *unk_08;
    PokedexScreenManager *slotsMinigameDTO;
    PokedexScreenManager *unk_10;
    const PokedexScreenManager *unk_14;
} UnkStruct_ov21_021E1A7C;

typedef struct {
    void *coins;
    void *slotMachineVariant;
} UnkStruct_ov21_021E1E8C;

typedef struct {
    TouchScreenActions *coins;
    TouchScreenHitTable *slotMachineVariant;
    UnkStruct_ov21_021E1E8C unk_08;
    int unk_10;
    int unk_14[8];
    int unk_34;
    u32 unk_38;
} UnkStruct_ov21_021E1E74;

typedef struct {
    Sprite *coins[8];
    PokedexTextData *unk_20[8];
    SpriteResource *unk_40[4];
    Sprite *unk_50[8];
    SpriteResource *unk_70[4];
    int unk_80[8];
    void *unk_A0[8];
    u32 unk_C0;
} UnkStruct_ov21_021E2588;

static UnkStruct_ov21_021E1A7C *ov21_021E199C(enum HeapID heapID, PokedexApp *slotsMinigameDTO);
static PokedexGraphicData **ov21_021E19FC(enum HeapID heapID, PokedexApp *slotsMinigameDTO);
static UnkStruct_ov21_021D4660 *ov21_021E1A24(enum HeapID heapID, PokedexApp *slotsMinigameDTO);
static void ov21_021E1A7C(UnkStruct_ov21_021E1A7C *param0);
static void ov21_021E1A90(PokedexGraphicData **param0);
static void ov21_021E1AA4(UnkStruct_ov21_021D4660 *param0);
static int ov21_021E1ACC(void);
static int ov21_021E1AD0(PokedexDataManager *dataMan, void *data);
static int ov21_021E1B14(PokedexDataManager *dataMan, void *data);
static int ov21_021E1B54(PokedexDataManager *dataMan, void *data);
static int ov21_021E1B68(void *graphics, PokedexGraphicsManager *graphicsMan, const void *data, const PokedexDataManager *dataMan);
static int ov21_021E1BFC(void *graphics, PokedexGraphicsManager *graphicsMan, const void *data, const PokedexDataManager *dataMan);
static int ov21_021E1CB8(void *graphics, PokedexGraphicsManager *graphicsMan, const void *data, const PokedexDataManager *dataMan);
static void ov21_021E2588(UnkStruct_ov21_021E2588 *param0);
static void ov21_021E25C0(UnkStruct_ov21_021E2588 *param0);
static void ov21_021E25F8(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO, const UnkStruct_ov21_021E1A7C *param2, BOOL param3);
static BOOL ov21_021E2664(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO, const UnkStruct_ov21_021E1A7C *param2, BOOL param3);
static void ov21_021E1D40(UnkStruct_ov21_021E1E74 *param0, UnkStruct_ov21_021E1A7C *slotsMinigameDTO, enum HeapID heapID);
static void ov21_021E1E00(UnkStruct_ov21_021E1E74 *param0, UnkStruct_ov21_021E1A7C *slotsMinigameDTO);
static void ov21_021E1E74(UnkStruct_ov21_021E1E74 *param0);
static void ov21_021E1E8C(u32 param0, enum TouchScreenButtonState slotsMinigameDTO, void *param2);
static void ov21_021E26A0(PokedexGraphicData **param0, Sprite *slotsMinigameDTO, PokedexTextData *textData, int param3, int param4, int param5, int *param6, enum HeapID heapID, int param8, int param9, void **param10);
static void ov21_021E274C(Sprite *param0, PokedexTextData *textData, int param2, int param3, int param4);
static void ov21_021E28D0(UnkStruct_ov21_021E2588 *param0, const UnkStruct_ov21_021E1E74 *slotsMinigameDTO);
static void ov21_021E29A4(Sprite *param0, int slotsMinigameDTO, int param2);
static void ov21_021E2968(UnkStruct_ov21_021E1E74 *param0, UnkStruct_ov21_021E1A7C *slotsMinigameDTO);
static void ov21_021E2014(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO, enum HeapID heapID);
static void ov21_021E2044(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO, enum HeapID heapID);
static void ov21_021E20A4(PokedexGraphicData **param0, enum HeapID heapID);
static void ov21_021E2180(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO, int param2);
static void ov21_021E226C(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO);
static void ov21_021E22C8(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO, int param2);
static void ov21_021E2458(UnkStruct_ov21_021E2588 *param0);
static void ov21_021E2478(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO, int param2);
static void ov21_021E256C(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO);
static void ov21_021E275C(UnkStruct_ov21_021E1E74 *param0, UnkStruct_ov21_021E1A7C *slotsMinigameDTO, int param2);
static void ov21_021E27C0(UnkStruct_ov21_021E1E74 *param0, UnkStruct_ov21_021E1A7C *slotsMinigameDTO, int param2, int param3);
static void ov21_021E2864(UnkStruct_ov21_021E1E74 *param0, UnkStruct_ov21_021E1A7C *slotsMinigameDTO);
static void ov21_021E28A8(UnkStruct_ov21_021E1E74 *param0);

static u32 const Unk_ov21_021E9D80[(7 - 2 + 1)] = {
    28 << FX32_SHIFT,
    68 << FX32_SHIFT,
    108 << FX32_SHIFT,
    148 << FX32_SHIFT,
    188 << FX32_SHIFT,
    228 << FX32_SHIFT
};

static u32 const Unk_ov21_021E9D98[(7 - 2 + 1)] = {
    0x2,
    0x4,
    0x6,
    0x8,
    0xA,
    0x0
};

void ov21_021E1924(PokedexScreenManager *param0, PokedexApp *slotsMinigameDTO, enum HeapID heapID)
{
    UnkStruct_ov21_021E1A7C *v0;
    PokedexGraphicData **v1;
    UnkStruct_ov21_021D4660 *v2;

    v0 = ov21_021E199C(heapID, slotsMinigameDTO);
    v1 = ov21_021E19FC(heapID, slotsMinigameDTO);
    v2 = ov21_021E1A24(heapID, slotsMinigameDTO);

    param0->pageData = v0;
    param0->pageGraphics = v1;
    param0->screenStates = v2;
    param0->numStates = ov21_021E1ACC();

    param0->dataFunc[0] = ov21_021E1AD0;
    param0->dataFunc[1] = ov21_021E1B14;
    param0->dataFunc[2] = ov21_021E1B54;
    param0->graphicsFunc[0] = ov21_021E1B68;
    param0->graphicsFunc[1] = ov21_021E1BFC;
    param0->graphicsFunc[2] = ov21_021E1CB8;
}

void ov21_021E1984(PokedexScreenManager *param0)
{
    ov21_021E1A7C(param0->pageData);
    ov21_021E1A90(param0->pageData); // should be pageGraphics?
    ov21_021E1AA4(param0->screenStates);
}

static UnkStruct_ov21_021E1A7C *ov21_021E199C(enum HeapID heapID, PokedexApp *slotsMinigameDTO)
{
    UnkStruct_ov21_021E1A7C *v0;
    PokedexScreenManager *v1;
    PokedexSortData *v2;
    int v3;

    v0 = Heap_Alloc(heapID, sizeof(UnkStruct_ov21_021E1A7C));

    GF_ASSERT(v0);
    memset(v0, 0, sizeof(UnkStruct_ov21_021E1A7C));

    v0->coins = ov21_021D13A0(slotsMinigameDTO);
    v0->slotMachineVariant = PokedexMain_GetSortData(slotsMinigameDTO);

    v1 = ov21_021D1430(slotsMinigameDTO, 3);
    v0->unk_14 = v1;

    v1 = ov21_021D1410(slotsMinigameDTO, 2);
    v0->unk_08 = v1->pageData;

    v1 = ov21_021D1410(slotsMinigameDTO, 3);
    v0->slotsMinigameDTO = v1;

    v1 = ov21_021D1410(slotsMinigameDTO, 4);
    v0->unk_10 = v1;

    return v0;
}

static PokedexGraphicData **ov21_021E19FC(enum HeapID heapID, PokedexApp *slotsMinigameDTO)
{
    PokedexGraphicData **v0;
    PokedexScreenManager *v1;

    v0 = Heap_Alloc(heapID, sizeof(PokedexGraphicData **));

    GF_ASSERT(v0);
    memset(v0, 0, sizeof(PokedexGraphicData **));

    *v0 = PokedexMain_GetGraphicData(slotsMinigameDTO);

    return v0;
}

static UnkStruct_ov21_021D4660 *ov21_021E1A24(enum HeapID heapID, PokedexApp *slotsMinigameDTO)
{
    UnkStruct_ov21_021D4660 *v0;
    int v1 = ov21_021E1ACC();

    v0 = Heap_Alloc(heapID, sizeof(UnkStruct_ov21_021D4660) * v1);

    GF_ASSERT(v0);
    memset(v0, 0, sizeof(UnkStruct_ov21_021D4660) * v1);

    ov21_021D4A94(heapID, &v0[0], slotsMinigameDTO, (1 << 0));
    ov21_021D4BB4(heapID, &v0[1], slotsMinigameDTO, (1 << 1));
    ov21_021D4AF8(heapID, &v0[2], slotsMinigameDTO, (1 << 2));

    return v0;
}

static void ov21_021E1A7C(UnkStruct_ov21_021E1A7C *param0)
{
    GF_ASSERT(param0);
    Heap_Free(param0);
}

static void ov21_021E1A90(PokedexGraphicData **param0)
{
    GF_ASSERT(param0);
    Heap_Free(param0);
}

static void ov21_021E1AA4(UnkStruct_ov21_021D4660 *param0)
{
    GF_ASSERT(param0);

    ov21_021D4660(&param0[0]);
    ov21_021D4660(&param0[1]);
    ov21_021D4660(&param0[2]);
    Heap_Free(param0);
}

static int ov21_021E1ACC(void)
{
    return 3;
}

static int ov21_021E1AD0(PokedexDataManager *dataMan, void *data)
{
    UnkStruct_ov21_021E1A7C *v0 = data;
    UnkStruct_ov21_021E1E74 *v1 = dataMan->pageData;
    int v2;

    v1 = Heap_Alloc(dataMan->heapID, sizeof(UnkStruct_ov21_021E1E74));
    memset(v1, 0, sizeof(UnkStruct_ov21_021E1E74));

    for (v2 = 0; v2 < 8; v2++) {
        v1->unk_14[v2] = (3 + 1);
    }

    v1->unk_10 = 0;

    ov21_021E1D40(v1, v0, dataMan->heapID);
    ov21_021E2968(v1, v0);

    dataMan->pageData = v1;

    return 1;
}

static int ov21_021E1B14(PokedexDataManager *dataMan, void *data)
{
    UnkStruct_ov21_021E1A7C *v0 = data;
    UnkStruct_ov21_021E1E74 *v1 = dataMan->pageData;

    if (dataMan->exit == 1) {
        return 1;
    }

    if (dataMan->unchanged == 1) {
        return 0;
    }

    if (ov21_021E33AC(v0->unk_14)) {
        ov21_021E28A8(v1);
        ov21_021E1E00(v1, v0);
        ov21_021E2864(v1, v0);
    }

    return 0;
}

static int ov21_021E1B54(PokedexDataManager *dataMan, void *data)
{
    UnkStruct_ov21_021E1A7C *v0 = data;
    UnkStruct_ov21_021E1E74 *v1 = dataMan->pageData;

    ov21_021E1E74(v1);
    Heap_Free(v1);

    return 1;
}

static int ov21_021E1B68(void *graphics, PokedexGraphicsManager *graphicsMan, const void *data, const PokedexDataManager *dataMan)
{
    const UnkStruct_ov21_021E1A7C *v0 = data;
    const UnkStruct_ov21_021E1E74 *v1 = dataMan->pageData;
    PokedexGraphicData **v2 = graphics;
    UnkStruct_ov21_021E2588 *v3 = graphicsMan->pageGraphics;

    switch (graphicsMan->state) {
    case 0:
        graphicsMan->pageGraphics = Heap_Alloc(graphicsMan->heapID, sizeof(UnkStruct_ov21_021E2588));
        memset(graphicsMan->pageGraphics, 0, sizeof(UnkStruct_ov21_021E2588));
        graphicsMan->state++;
        break;
    case 1:
        ov21_021E2014(v3, v2, graphicsMan->heapID);
        ov21_021E28D0(v3, v1);
        ov21_021E25F8(v3, v2, v0, 1);
        graphicsMan->state++;
        break;
    case 2:
        if (ov21_021E2664(v3, v2, v0, 1)) {
            graphicsMan->state++;
        }
        break;
    case 3:
        PokedexGraphics_SetStaticCursorSize(&(*v2)->cursorGraphics, 0);
        return 1;
    default:
        break;
    }

    return 0;
}

static int ov21_021E1BFC(void *graphics, PokedexGraphicsManager *graphicsMan, const void *data, const PokedexDataManager *dataMan)
{
    const UnkStruct_ov21_021E1A7C *v0 = data;
    const UnkStruct_ov21_021E1E74 *v1 = dataMan->pageData;
    PokedexGraphicData **v2 = graphics;
    UnkStruct_ov21_021E2588 *v3 = graphicsMan->pageGraphics;
    int v4;
    int v5;
    BOOL v6;

    if (v3->unk_C0 != v1->unk_38) {
        ov21_021E28D0(v3, v1);
        v3->unk_C0 = v1->unk_38;
    }

    for (v4 = 0; v4 <= 1; v4++) {
        v6 = 0;

        if (v4 == 0) {
            v6 = 1;
        } else {
            v6 = 1;
        }

        if (v6) {
            if (v4 == 0) {
                v5 = 4;
            } else {
                v5 = 5;
            }

            ov21_021E26A0(v2, v3->coins[v4], v3->unk_20[v4], v1->unk_14[v4], -6, v5, &v3->unk_80[v4], graphicsMan->heapID, 4, 1, &v3->unk_A0[v4]);
            ov21_021D144C(v3->unk_50[v4], v1->unk_14[v4]);
        }
    }

    for (v4 = 2; v4 < 8; v4++) {
        ov21_021E29A4(v3->coins[v4], v1->unk_14[v4], v4);
    }

    return 0;
}

static int ov21_021E1CB8(void *graphics, PokedexGraphicsManager *graphicsMan, const void *data, const PokedexDataManager *dataMan)
{
    const UnkStruct_ov21_021E1A7C *v0 = data;
    const UnkStruct_ov21_021E1E74 *v1 = dataMan->pageData;
    PokedexGraphicData **v2 = graphics;
    UnkStruct_ov21_021E2588 *v3 = graphicsMan->pageGraphics;

    switch (graphicsMan->state) {
    case 0:
        PokedexGraphics_SetStaticCursorSize(&(*v2)->cursorGraphics, 1);
        ov21_021E25F8(v3, v2, v0, 0);
        graphicsMan->state++;
        break;
    case 1:
        if (ov21_021E2664(v3, v2, v0, 0)) {
            graphicsMan->state++;
        }
        break;
    case 2:
        ov21_021E2044(v3, v2, graphicsMan->heapID);
        graphicsMan->state++;
        break;
    case 3:
        Heap_Free(graphicsMan->pageGraphics);
        graphicsMan->state++;
        break;
    case 4:
        return 1;
    default:
        break;
    }

    return 0;
}

static void ov21_021E1D40(UnkStruct_ov21_021E1E74 *param0, UnkStruct_ov21_021E1A7C *slotsMinigameDTO, enum HeapID heapID)
{
    param0->slotMachineVariant = Heap_Alloc(heapID, sizeof(TouchScreenHitTable) * 8);

    PokedexMain_SetHitTableRect(&param0->slotMachineVariant[0], 132 - (40 / 2), 132 + (40 / 2), 128 - (160 / 2), 128 + (160 / 2));
    PokedexMain_SetHitTableRect(&param0->slotMachineVariant[1], 76 - (40 / 2), 76 + (40 / 2), 128 - (160 / 2), 128 + (160 / 2));
    PokedexMain_SetHitTableRect(&param0->slotMachineVariant[2], 176 - (32 / 2), 176 + (32 / 2), 28 - (40 / 2), 28 + (40 / 2));
    PokedexMain_SetHitTableRect(&param0->slotMachineVariant[3], 176 - (32 / 2), 176 + (32 / 2), 68 - (40 / 2), 68 + (40 / 2));
    PokedexMain_SetHitTableRect(&param0->slotMachineVariant[4], 176 - (32 / 2), 176 + (32 / 2), 108 - (40 / 2), 108 + (40 / 2));
    PokedexMain_SetHitTableRect(&param0->slotMachineVariant[5], 176 - (32 / 2), 176 + (32 / 2), 148 - (40 / 2), 148 + (40 / 2));
    PokedexMain_SetHitTableRect(&param0->slotMachineVariant[6], 176 - (32 / 2), 176 + (32 / 2), 188 - (40 / 2), 188 + (40 / 2));
    PokedexMain_SetHitTableRect(&param0->slotMachineVariant[7], 176 - (32 / 2), 176 + (32 / 2), 228 - (40 / 2), 228 + (40 / 2));

    param0->unk_08.coins = slotsMinigameDTO;
    param0->unk_08.slotMachineVariant = param0;
    param0->coins = TouchScreenActions_RegisterHandler(param0->slotMachineVariant, 8, ov21_021E1E8C, &param0->unk_08, heapID);
}

static void ov21_021E1E00(UnkStruct_ov21_021E1E74 *param0, UnkStruct_ov21_021E1A7C *slotsMinigameDTO)
{
    int v0;

    for (v0 = 0; v0 < 8; v0++) {
        param0->unk_14[v0] = 3;
    }

    TouchScreenActions_HandleAction(param0->coins);

    switch (param0->unk_10) {
    case 0:
        param0->unk_14[2] = 1;
        break;
    case 1:
        param0->unk_14[3] = 1;
        break;
    case 2:
        param0->unk_14[4] = 1;
        break;
    case 3:
        param0->unk_14[5] = 1;
        break;
    case 4:
        param0->unk_14[6] = 1;
        break;
    case 5:
        param0->unk_14[7] = 1;
        break;
    default:
        break;
    }

    switch (param0->unk_34) {
    case 0:
        param0->unk_14[0] = 2;
        break;
    case 1:
        param0->unk_14[1] = 2;
        break;
    default:
        break;
    }
}

static void ov21_021E1E74(UnkStruct_ov21_021E1E74 *param0)
{
    TouchScreenActions_Free(param0->coins);
    Heap_Free(param0->slotMachineVariant);

    param0->slotMachineVariant = NULL;
}

static void ov21_021E1E8C(u32 param0, enum TouchScreenButtonState slotsMinigameDTO, void *param2)
{
    UnkStruct_ov21_021E1E8C *v0 = param2;
    UnkStruct_ov21_021E1A7C *v1 = v0->coins;
    UnkStruct_ov21_021E1E74 *v2 = v0->slotMachineVariant;
    BOOL v3;

    v2->unk_14[param0] = slotsMinigameDTO;

    switch (slotsMinigameDTO) {
    case TOUCH_BUTTON_HELD:
        switch (param0) {
        case 0:
            v2->unk_34 = 0;
            break;
        case 1:
            v2->unk_34 = 1;
            break;
        case 2:
            if (v2->unk_38 & 1) {
                if (v2->unk_10 == 0) {
                    v3 = InfoMain_SetDisplayPosition(v1->unk_08, 1);
                } else {
                    InfoMain_SetEntryOffset(v1->unk_08, 0);
                    v3 = 1;
                }

                if (v3) {
                    ov21_021E27C0(v2, v1, v2->unk_10, 0);
                    Sound_PlayEffect(SEQ_SE_DP_DENSI06_sseq);
                }
            }
            break;
        case 3:
            if (v2->unk_38 & 2) {
                if (v2->unk_10 == 1) {
                    v3 = InfoMainForeign_GetScreenStateCount(v1->unk_10);
                } else {
                    InfoMainForeign_SetEntryOffset(v1->unk_10, 0);
                    v3 = 1;
                }

                if (v3) {
                    ov21_021E27C0(v2, v1, v2->unk_10, 1);
                    Sound_PlayEffect(SEQ_SE_DP_DENSI06_sseq);
                }
            }
            break;
        case 4:
            if (v2->unk_38 & 4) {
                if (v2->unk_10 == 2) {
                    v3 = InfoMainForeign_GetScreenStateCount(v1->unk_10);
                } else {
                    InfoMainForeign_SetEntryOffset(v1->unk_10, 0);
                    v3 = 1;
                }

                if (v3) {
                    ov21_021E27C0(v2, v1, v2->unk_10, 2);
                    Sound_PlayEffect(SEQ_SE_DP_DENSI06_sseq);
                }
            }
            break;
        case 5:
            if (v2->unk_38 & 8) {
                if (v2->unk_10 == 3) {
                    v3 = InfoMainForeign_GetScreenStateCount(v1->unk_10);
                } else {
                    InfoMainForeign_SetEntryOffset(v1->unk_10, 0);
                    v3 = 1;
                }

                if (v3) {
                    ov21_021E27C0(v2, v1, v2->unk_10, 3);
                    Sound_PlayEffect(SEQ_SE_DP_DENSI06_sseq);
                }
            }
            break;
        case 6:
            if (v2->unk_38 & 16) {
                if (v2->unk_10 == 4) {
                    v3 = InfoMainForeign_GetScreenStateCount(v1->unk_10);
                } else {
                    InfoMainForeign_SetEntryOffset(v1->unk_10, 0);
                    v3 = 1;
                }

                if (v3) {
                    ov21_021E27C0(v2, v1, v2->unk_10, 4);
                    Sound_PlayEffect(SEQ_SE_DP_DENSI06_sseq);
                }
            }
            break;
        case 7:
            if (v2->unk_38 & 32) {
                if (v2->unk_10 == 5) {
                    v3 = InfoMainForeign_GetScreenStateCount(v1->unk_10);
                } else {
                    InfoMainForeign_SetEntryOffset(v1->unk_10, 0);
                    v3 = 1;
                }

                if (v3) {
                    ov21_021E27C0(v2, v1, v2->unk_10, 5);
                    Sound_PlayEffect(SEQ_SE_DP_DENSI06_sseq);
                }
            }
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

static void ov21_021E2014(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO, enum HeapID heapID)
{
    ov21_021E20A4(slotsMinigameDTO, heapID);
    ov21_021E2180(param0, slotsMinigameDTO, heapID);
    ov21_021E22C8(param0, slotsMinigameDTO, heapID);
    ov21_021E2478(param0, slotsMinigameDTO, heapID);
}

static void ov21_021E2044(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO, enum HeapID heapID)
{
    int v0;

    PokedexGraphics_LoadGraphicNarcPaletteData(*slotsMinigameDTO, background_sub_2_NCLR, 4, 4 * 32, 32, heapID);
    PokedexGraphics_LoadGraphicNarcPaletteData(*slotsMinigameDTO, background_sub_2_NCLR, 4, 5 * 32, 32, heapID);
    ov21_021E2458(param0);
    ov21_021E256C(param0, slotsMinigameDTO);
    ov21_021E226C(param0, slotsMinigameDTO);

    for (v0 = 0; v0 < 8; v0++) {
        if (param0->unk_A0[v0]) {
            Heap_Free(param0->unk_A0[v0]);
        }
    }
}

static void ov21_021E20A4(PokedexGraphicData **param0, enum HeapID heapID)
{
    void *v0;
    NNSG2dScreenData *v1;

    PokedexGraphics_LoadGraphicNarcCharacterData(*param0, entry_sub_NCGR_lz, (*param0)->bgConfig, 6, 0, 0, TRUE, heapID);

    v0 = PokedexGraphics_GetGraphicNarcTilemapData(*param0, info_sub_NSCR_lz, TRUE, &v1, heapID);

    Bg_LoadToTilemapRect((*param0)->bgConfig, 6, v1->rawData, 0, 0, v1->screenWidth / 8, v1->screenHeight / 8);
    Heap_Free(v0);

    v0 = PokedexGraphics_GetGraphicNarcTilemapData(*param0, info_sub_unpressed_NSCR_lz, TRUE, &v1, heapID);

    Bg_LoadToTilemapRect((*param0)->bgConfig, 6, v1->rawData, ((128 - (160 / 2)) / 8), ((132 - (40 / 2)) / 8), v1->screenWidth / 8, v1->screenHeight / 8);
    Heap_Free(v0);

    v0 = PokedexGraphics_GetGraphicNarcTilemapData(*param0, info_sub_pressed_NSCR_lz, TRUE, &v1, heapID);

    Bg_LoadToTilemapRect((*param0)->bgConfig, 6, v1->rawData, ((128 - (160 / 2)) / 8), ((76 - (40 / 2)) / 8), v1->screenWidth / 8, v1->screenHeight / 8);
    Heap_Free(v0);
    Bg_ScheduleTilemapTransfer((*param0)->bgConfig, 6);
}

static void ov21_021E2180(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO, int param2)
{
    PokedexGraphicData *v0 = *slotsMinigameDTO;
    NARC *v1 = PokedexGraphics_GetNARC(v0);

    param0->unk_40[0] = SpriteResourceCollection_AddTilesFrom(v0->spriteResourceCollection[0], v1, size_buttons_pressed_NCGR_lz, TRUE, size_buttons_pressed_NCGR_lz + 5000, NNS_G2D_VRAM_TYPE_2DSUB, param2);

    SpriteTransfer_RequestCharAtEnd(param0->unk_40[0]);
    SpriteResource_ReleaseData(param0->unk_40[0]);

    param0->unk_40[2] = SpriteResourceCollection_AddFrom(v0->spriteResourceCollection[2], v1, size_buttons_pressed_cell_NCER_lz, TRUE, size_buttons_pressed_cell_NCER_lz + 5000, 2, param2);
    param0->unk_40[3] = SpriteResourceCollection_AddFrom(v0->spriteResourceCollection[3], v1, size_buttons_pressed_anim_NANR_lz, TRUE, size_buttons_pressed_anim_NANR_lz + 5000, 3, param2);
    param0->unk_70[0] = SpriteResourceCollection_AddTilesFrom(v0->spriteResourceCollection[0], v1, info_language_buttons_NCGR_lz, TRUE, info_language_buttons_NCGR_lz + 5000, NNS_G2D_VRAM_TYPE_2DSUB, param2);

    SpriteTransfer_RequestCharAtEnd(param0->unk_70[0]);
    SpriteResource_ReleaseData(param0->unk_70[0]);

    param0->unk_70[2] = SpriteResourceCollection_AddFrom(v0->spriteResourceCollection[2], v1, info_language_buttons_cell_NCER_lz, TRUE, info_language_buttons_cell_NCER_lz + 5000, 2, param2);
    param0->unk_70[3] = SpriteResourceCollection_AddFrom(v0->spriteResourceCollection[3], v1, info_language_buttons_anim_NANR_lz, TRUE, info_language_buttons_anim_NANR_lz + 5000, 3, param2);
}

static void ov21_021E226C(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO)
{
    PokedexGraphicData *v0 = *slotsMinigameDTO;

    SpriteTransfer_ResetCharTransfer(param0->unk_40[0]);
    SpriteResourceCollection_Remove(v0->spriteResourceCollection[0], param0->unk_40[0]);
    SpriteResourceCollection_Remove(v0->spriteResourceCollection[2], param0->unk_40[2]);
    SpriteResourceCollection_Remove(v0->spriteResourceCollection[3], param0->unk_40[3]);

    SpriteTransfer_ResetCharTransfer(param0->unk_70[0]);
    SpriteResourceCollection_Remove(v0->spriteResourceCollection[0], param0->unk_70[0]);
    SpriteResourceCollection_Remove(v0->spriteResourceCollection[2], param0->unk_70[2]);
    SpriteResourceCollection_Remove(v0->spriteResourceCollection[3], param0->unk_70[3]);
}

static void ov21_021E22C8(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO, int param2)
{
    SpriteResourcesHeader v0;
    SpriteListTemplate v1;
    PokedexGraphicData *v2 = *slotsMinigameDTO;
    int v3;

    SpriteResourcesHeader_Init(&v0, size_buttons_pressed_NCGR_lz + 5000, info_NCLR + 2100, size_buttons_pressed_cell_NCER_lz + 5000, size_buttons_pressed_anim_NANR_lz + 5000, 0xffffffff, 0xffffffff, FALSE, 2, v2->spriteResourceCollection[0], v2->spriteResourceCollection[1], v2->spriteResourceCollection[2], v2->spriteResourceCollection[3], NULL, NULL);

    v1.list = v2->spriteList;
    v1.resourceData = &v0;
    v1.priority = 31;
    v1.vramType = NNS_G2D_VRAM_TYPE_2DSUB;
    v1.heapID = param2;

    v1.position.x = 128 << FX32_SHIFT;
    v1.position.y = 132 << FX32_SHIFT;
    v1.position.y += (192 << FX32_SHIFT);

    param0->coins[0] = SpriteList_Add(&v1);
    Sprite_SetAnim(param0->coins[0], 0);

    v1.position.x = 128 << FX32_SHIFT;
    v1.position.y = 76 << FX32_SHIFT;
    v1.position.y += (192 << FX32_SHIFT);

    param0->coins[1] = SpriteList_Add(&v1);

    Sprite_SetAnim(param0->coins[1], 0);
    SpriteResourcesHeader_Init(&v0, info_language_buttons_NCGR_lz + 5000, info_NCLR + 2100, info_language_buttons_cell_NCER_lz + 5000, info_language_buttons_anim_NANR_lz + 5000, 0xffffffff, 0xffffffff, FALSE, 2, v2->spriteResourceCollection[0], v2->spriteResourceCollection[1], v2->spriteResourceCollection[2], v2->spriteResourceCollection[3], NULL, NULL);

    v1.resourceData = &v0;
    v1.position.y = 176 << FX32_SHIFT;
    v1.position.y += (192 << FX32_SHIFT);

    for (v3 = 0; v3 < (7 - 2 + 1); ++v3) {
        v1.position.x = Unk_ov21_021E9D80[v3];
        param0->coins[v3 + 2] = SpriteList_Add(&v1);

        Sprite_SetAnim(param0->coins[v3 + 2], Unk_ov21_021E9D98[v3]);
    }

    v1.priority = 31 - 1;

    v1.position.x = (128 + (+32)) << FX32_SHIFT;
    v1.position.y = (132 + 2) << FX32_SHIFT;
    v1.position.y += (192 << FX32_SHIFT);

    param0->unk_50[0] = SpriteList_Add(&v1);
    Sprite_SetAnim(param0->unk_50[0], 13);

    v1.position.x = (128 + -32) << FX32_SHIFT;
    v1.position.y = (76 + 2) << FX32_SHIFT;
    v1.position.y += (192 << FX32_SHIFT);

    param0->unk_50[1] = SpriteList_Add(&v1);
    Sprite_SetAnim(param0->unk_50[1], 12);

    for (v3 = 1 + 1; v3 < 8; v3++) {
        param0->unk_50[v3] = NULL;
    }
}

static void ov21_021E2458(UnkStruct_ov21_021E2588 *param0)
{
    int v0;

    for (v0 = 0; v0 < 8; v0++) {
        Sprite_Delete(param0->coins[v0]);

        if (param0->unk_50[v0]) {
            Sprite_Delete(param0->unk_50[v0]);
        }
    }
}

static void ov21_021E2478(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO, int param2)
{
    Window *v0;
    PokedexDisplayBox displayBox;
    SpriteResource *v2;
    PokedexGraphicData *v3 = *slotsMinigameDTO;
    int v4;
    int v5;

    GF_ASSERT(param0->coins[0]);

    v2 = SpriteResourceCollection_Find(v3->spriteResourceCollection[1], info_NCLR + 2100);

    displayBox.textMan = v3->textMan;
    displayBox.paletteProxy = SpriteTransfer_GetPaletteProxy(v2, NULL);
    displayBox.y = -6;
    displayBox.spriteResourcePriority = 2;
    displayBox.spriteListPriority = 0;
    displayBox.vramType = NNS_G2D_VRAM_TYPE_2DSUB;
    displayBox.heapID = param2;

    v4 = PlttTransfer_GetPlttOffset(displayBox.paletteProxy, NNS_G2D_VRAM_TYPE_2DSUB);
    v0 = PokedexTextManager_NewWindow(v3->textMan, 8, 4);

    PokedexTextManager_DisplayMessage(v3->textMan, v0, TEXT_BANK_POKEDEX, pl_msg_pokedex_next, 0, 0);

    displayBox.window = v0;
    displayBox.sprite = param0->coins[0];
    displayBox.x = -32;

    param0->unk_20[0] = PokedexTextManager_NextTextData(&displayBox);

    sub_02012A60(param0->unk_20[0]->fontOAM, v4 + 4);
    PokedexTextManager_FreeWindow(v0);

    v0 = PokedexTextManager_NewWindow(v3->textMan, 8, 4);

    {
        u32 v6 = PokedexTextManager_DisplayMessage(v3->textMan, v0, TEXT_BANK_POKEDEX, pl_msg_pokedex_back, 0, 0);
        displayBox.x = 32 - v6;
    }

    displayBox.window = v0;
    displayBox.sprite = param0->coins[1];

    param0->unk_20[1] = PokedexTextManager_NextTextData(&displayBox);

    sub_02012A60(param0->unk_20[1]->fontOAM, v4 + 4);
    PokedexTextManager_FreeWindow(v0);

    for (v5 = 2; v5 < 8; v5++) {
        param0->unk_20[v5] = NULL;
    }
}

static void ov21_021E256C(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO)
{
    int v0;

    for (v0 = 0; v0 < 8; v0++) {
        if (param0->unk_20[v0]) {
            PokedexTextManager_FreeTextData(param0->unk_20[v0]);
        }
    }
}

static void ov21_021E2588(UnkStruct_ov21_021E2588 *param0)
{
    int v0;

    for (v0 = 0; v0 < 8; v0++) {
        Sprite_SetExplicitOAMMode(param0->coins[v0], GX_OAM_MODE_XLU);

        if (param0->unk_20[v0]) {
            sub_02012AF0(param0->unk_20[v0]->fontOAM, GX_OAM_MODE_XLU);
        }

        if (param0->unk_50[v0]) {
            Sprite_SetExplicitOAMMode(param0->unk_50[v0], GX_OAM_MODE_XLU);
        }
    }
}

static void ov21_021E25C0(UnkStruct_ov21_021E2588 *param0)
{
    int v0;

    for (v0 = 0; v0 < 8; v0++) {
        Sprite_SetExplicitOAMMode(param0->coins[v0], GX_OAM_MODE_NORMAL);

        if (param0->unk_20[v0]) {
            sub_02012AF0(param0->unk_20[v0]->fontOAM, GX_OAM_MODE_NORMAL);
        }

        if (param0->unk_50[v0]) {
            Sprite_SetExplicitOAMMode(param0->unk_50[v0], GX_OAM_MODE_NORMAL);
        }
    }
}

static void ov21_021E25F8(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO, const UnkStruct_ov21_021E1A7C *param2, BOOL param3)
{
    ov21_021E2588(param0);

    if (ov21_021E33A4(param2->unk_14)) {
        if (param3) {
            PokedexGraphics_InitBlendTransition(&(*slotsMinigameDTO)->blendSub, 1, -16, 0, 0, 16, (GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_BD), (GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_BD), 1);
        } else {
            PokedexGraphics_InitBlendTransition(&(*slotsMinigameDTO)->blendSub, 1, 0, -16, 16, 0, (GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_BD), (GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_BD), 1);
        }
    }
}

static BOOL ov21_021E2664(UnkStruct_ov21_021E2588 *param0, PokedexGraphicData **slotsMinigameDTO, const UnkStruct_ov21_021E1A7C *param2, BOOL param3)
{
    BOOL v0;

    if (ov21_021E33A4(param2->unk_14)) {
        v0 = PokedexGraphics_TakeBlendTransitionStep(&(*slotsMinigameDTO)->blendSub);
    } else {
        v0 = BrightnessController_IsTransitionComplete(BRIGHTNESS_SUB_SCREEN);
    }

    if (v0) {
        if (param3) {
            ov21_021E25C0(param0);
        }

        return 1;
    }

    return 0;
}

static void ov21_021E26A0(PokedexGraphicData **param0, Sprite *slotsMinigameDTO, PokedexTextData *textData, int param3, int param4, int param5, int *param6, enum HeapID heapID, int param8, int param9, void **param10)
{
    int v0;
    NNSG2dPaletteData *v1;
    BOOL v2;
    BOOL v3 = 0;
    int v4;

    ov21_021D144C(slotsMinigameDTO, param3);
    ov21_021E274C(slotsMinigameDTO, textData, param4, param8, param9);

    v0 = Sprite_GetAnimFrame(slotsMinigameDTO);

    switch (v0) {
    case 0:
    case 1:
        if (*param6 != 0) {
            v3 = 1;
            v4 = background_sub_2_NCLR;
            *param6 = 0;
        }
        break;
    case 2:
        if (*param6 != 1) {
            v3 = 1;
            v4 = background_sub_3_NCLR;
            *param6 = 1;
        }
        break;
    case 3:
        if (*param6 != 2) {
            v3 = 1;
            v4 = background_sub_1_NCLR;
            *param6 = 2;
        }
        break;
    }

    if (v3) {
        if (*param10) {
            Heap_Free(*param10);
        }

        *param10 = PokedexGraphics_GetGraphicNarcPaletteData(*param0, v4, &v1, heapID);

        v2 = VramTransfer_Request(NNS_GFD_DST_2D_BG_PLTT_SUB, param5 * 32, v1->pRawData, 32);
        GF_ASSERT(v2);
    }
}

static void ov21_021E274C(Sprite *param0, PokedexTextData *textData, int param2, int param3, int param4)
{
    ov21_021D1524(param0, textData, param2, param3, param4);
}

static void ov21_021E275C(UnkStruct_ov21_021E1E74 *param0, UnkStruct_ov21_021E1A7C *slotsMinigameDTO, int param2)
{
    int v0, v1;

    slotsMinigameDTO->unk_08->playCry = 1;
    *slotsMinigameDTO->coins |= (1 << 2);
    param0->unk_10 = 0;

    v0 = 48;
    v1 = 72;

    slotsMinigameDTO->unk_08->animationMode = 2;

    switch (param2) {
    case 0:
        slotsMinigameDTO->unk_08->displayPositionX = v0;
        slotsMinigameDTO->unk_08->displayPositionY = v1;
        slotsMinigameDTO->unk_08->animationMode = 1;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        InfoMainForeign_SetDisplayPosition(slotsMinigameDTO->unk_10, v0, v1);
        InfoMainForeign_SetAnimationMode(slotsMinigameDTO->unk_10, ANIM_BLEND);
        break;
    default:
        break;
    }
}

static void ov21_021E27C0(UnkStruct_ov21_021E1E74 *param0, UnkStruct_ov21_021E1A7C *slotsMinigameDTO, int param2, int param3)
{
    int v0, v1;
    int v2;

    switch (param3) {
    case 0:
        *slotsMinigameDTO->coins |= (1 << 2);
        param0->unk_10 = 0;
        v0 = 48;
        v1 = 72;
        slotsMinigameDTO->unk_08->animationMode = 2;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        *slotsMinigameDTO->coins |= (1 << 1);
        param0->unk_10 = param3;
        v0 = 48;
        v1 = 72;

        InfoMainForeign_SetAnimationMode(slotsMinigameDTO->unk_10, ANIM_POSITION);
        v2 = PokedexText_ForeignLanguage(param3 - 1);
        InfoMainForeign_SetLanguage(slotsMinigameDTO->unk_10, v2);
        break;
    default:
        break;
    }

    switch (param2) {
    case 0:
        slotsMinigameDTO->unk_08->displayPositionX = v0;
        slotsMinigameDTO->unk_08->displayPositionY = v1;
        slotsMinigameDTO->unk_08->animationMode = 2;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        InfoMainForeign_SetDisplayPosition(slotsMinigameDTO->unk_10, v0, v1);
        InfoMainForeign_SetAnimationMode(slotsMinigameDTO->unk_10, ANIM_POSITION);
        break;
    default:
        break;
    }
}

static void ov21_021E2864(UnkStruct_ov21_021E1E74 *param0, UnkStruct_ov21_021E1A7C *slotsMinigameDTO)
{
    BOOL v0;

    if (param0->unk_34 != 8) {
        if (param0->unk_34 == 1) {
            v0 = PokedexSort_TakeStep_Loop(slotsMinigameDTO->slotMachineVariant, -1);
        } else {
            v0 = PokedexSort_TakeStep_Loop(slotsMinigameDTO->slotMachineVariant, 1);
        }

        if (v0 == 1) {
            ov21_021E275C(param0, slotsMinigameDTO, param0->unk_10);
            ov21_021E2968(param0, slotsMinigameDTO);
            Sound_PlayEffect(SEQ_SE_DP_DENSI06_sseq);
        }
    }
}

static void ov21_021E28A8(UnkStruct_ov21_021E1E74 *param0)
{
    if (gSystem.pressedKeys & PAD_KEY_UP) {
        param0->unk_34 = 1;
        return;
    }

    if (gSystem.pressedKeys & PAD_KEY_DOWN) {
        param0->unk_34 = 0;
        return;
    }

    param0->unk_34 = 8;
}

static void ov21_021E28D0(UnkStruct_ov21_021E2588 *param0, const UnkStruct_ov21_021E1E74 *slotsMinigameDTO)
{
    if ((slotsMinigameDTO->unk_38 & 1) == 0) {
        Sprite_SetDrawFlag(param0->coins[2], FALSE);
    } else {
        Sprite_SetDrawFlag(param0->coins[2], TRUE);
    }

    if ((slotsMinigameDTO->unk_38 & 2) == 0) {
        Sprite_SetDrawFlag(param0->coins[3], FALSE);
    } else {
        Sprite_SetDrawFlag(param0->coins[3], TRUE);
    }

    if ((slotsMinigameDTO->unk_38 & 4) == 0) {
        Sprite_SetDrawFlag(param0->coins[4], FALSE);
    } else {
        Sprite_SetDrawFlag(param0->coins[4], TRUE);
    }

    if ((slotsMinigameDTO->unk_38 & 8) == 0) {
        Sprite_SetDrawFlag(param0->coins[5], FALSE);
    } else {
        Sprite_SetDrawFlag(param0->coins[5], TRUE);
    }

    if ((slotsMinigameDTO->unk_38 & 16) == 0) {
        Sprite_SetDrawFlag(param0->coins[6], FALSE);
    } else {
        Sprite_SetDrawFlag(param0->coins[6], TRUE);
    }

    if ((slotsMinigameDTO->unk_38 & 32) == 0) {
        Sprite_SetDrawFlag(param0->coins[7], FALSE);
    } else {
        Sprite_SetDrawFlag(param0->coins[7], TRUE);
    }
}

static void ov21_021E2968(UnkStruct_ov21_021E1E74 *param0, UnkStruct_ov21_021E1A7C *slotsMinigameDTO)
{
    BOOL v0;
    int v1;
    int v2;

    param0->unk_38 = 0;

    for (v1 = 0; v1 < (6 - 1); v1++) {
        v2 = PokedexText_ForeignLanguage(v1);
        v0 = ov21_021D392C(slotsMinigameDTO->slotMachineVariant, v2);

        if (v0) {
            param0->unk_38 |= 1;
            param0->unk_38 |= 1 << (v1 + 1);
        }
    }
}

static void ov21_021E29A4(Sprite *param0, int slotsMinigameDTO, int param2)
{
    int v0;

    GF_ASSERT((param2 >= 2) && (param2 < 8));

    v0 = Unk_ov21_021E9D98[param2 - 2];

    if (slotsMinigameDTO == 1) {
        Sprite_SetAnim(param0, v0 + 1);
    } else {
        Sprite_SetAnim(param0, v0);
    }
}
