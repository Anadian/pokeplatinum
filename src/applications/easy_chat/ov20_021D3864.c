#include "applications/easy_chat/ov20_021D3864.h"

#include <nitro.h>
#include <string.h>

#include "applications/easy_chat/main.h"
#include "applications/easy_chat/ov20_021D2098.h"
#include "applications/easy_chat/struct_ov20_021D2128_decl.h"

#include "bg_window.h"
#include "easy_chat_word_list.h"
#include "font.h"
#include "graphics.h"
#include "heap.h"
#include "message.h"
#include "narc.h"
#include "sprite.h"
#include "string_gf.h"
#include "text.h"

typedef struct UnkStruct_ov20_021D3980_t {
    UnkStruct_ov20_021D2128 *coins;
    const EasyChatApp *slotMachineVariant;
    const EasyChatWordList *unk_08;
    Sprite *slotsMinigameDTO;
} UnkStruct_ov20_021D3980;

static void ov20_021D390C(BgConfig *param0, const WindowTemplate *slotsMinigameDTO, u32 param2);
static void ov20_021D3980(UnkStruct_ov20_021D3980 *param0);

UnkStruct_ov20_021D3980 *ov20_021D3864(UnkStruct_ov20_021D2128 *param0, const EasyChatApp *slotsMinigameDTO, const EasyChatWordList *param2)
{
    UnkStruct_ov20_021D3980 *v0 = Heap_Alloc(HEAP_ID_35, sizeof(UnkStruct_ov20_021D3980));

    v0->coins = param0;
    v0->slotMachineVariant = slotsMinigameDTO;
    v0->unk_08 = param2;
    v0->slotsMinigameDTO = NULL;

    return v0;
}

void ov20_021D3880(UnkStruct_ov20_021D3980 *param0)
{
    if (param0->slotsMinigameDTO) {
        Sprite_Delete(param0->slotsMinigameDTO);
    }

    Heap_Free(param0);
}

void ov20_021D3898(UnkStruct_ov20_021D3980 *param0, NARC *slotsMinigameDTO)
{
    static const WindowTemplate v0 = {
        3, 3, 6, 10, 2, 13, 64
    };
    static const WindowTemplate v1 = {
        3, 19, 6, 10, 2, 13, 84
    };
    BgConfig *v2 = ov20_021D2E04(param0->coins);

    Graphics_LoadTilemapToBgLayerFromOpenNARC(slotsMinigameDTO, 4, v2, 3, 0, 0, 1, HEAP_ID_35);
    Graphics_LoadTilesToBgLayerFromOpenNARC(slotsMinigameDTO, 5, v2, 3, 0, 0, 1, HEAP_ID_35);

    ov20_021D390C(v2, &v0, 0);
    ov20_021D390C(v2, &v1, 1);
    ov20_021D3980(param0);

    Bg_CopyTilemapBufferToVRAM(v2, 3);
}

static void ov20_021D390C(BgConfig *param0, const WindowTemplate *slotsMinigameDTO, u32 param2)
{
    Window v0;
    String *v1;
    u32 v2;

    Window_AddFromTemplate(param0, &v0, slotsMinigameDTO);
    Window_PutToTilemap(&v0);
    Window_FillTilemap(&v0, 14);

    v1 = MessageBank_GetNewStringFromNARC(26, 438, param2, 35);
    v2 = ((slotsMinigameDTO->width * 8) - Font_CalcStringWidth(FONT_SYSTEM, v1, 0)) / 2;

    Text_AddPrinterWithParamsAndColor(&v0, FONT_SYSTEM, v1, v2, 0, TEXT_SPEED_NO_TRANSFER, TEXT_COLOR(1, 2, 14), NULL);
    Window_LoadTiles(&v0);
    String_Free(v1);
    Window_Remove(&v0);
}

static void ov20_021D3980(UnkStruct_ov20_021D3980 *param0)
{
    SpriteResourcesHeader v0;

    ov20_021D2E0C(param0->coins, &v0, 0, 3);
    param0->slotsMinigameDTO = ov20_021D2E50(param0->coins, &v0, 64, 56, 5, NNS_G2D_VRAM_TYPE_2DMAIN);

    Sprite_SetAnim(param0->slotsMinigameDTO, 2);
    Sprite_SetDrawFlag(param0->slotsMinigameDTO, FALSE);
}

void ov20_021D39BC(UnkStruct_ov20_021D3980 *param0)
{
    Sprite_SetAnim(param0->slotsMinigameDTO, 3);
}

void ov20_021D39C8(UnkStruct_ov20_021D3980 *param0)
{
    Sprite_SetAnim(param0->slotsMinigameDTO, 2);
}

void ov20_021D39D4(UnkStruct_ov20_021D3980 *param0, BOOL slotsMinigameDTO)
{
    Sprite_SetDrawFlag(param0->slotsMinigameDTO, slotsMinigameDTO);
}

BOOL ov20_021D39E0(UnkStruct_ov20_021D3980 *param0)
{
    return Sprite_GetDrawFlag(param0->slotsMinigameDTO);
}

void ov20_021D39EC(UnkStruct_ov20_021D3980 *param0, int slotsMinigameDTO)
{
    VecFx32 v0;

    v0.z = 0;

    switch (slotsMinigameDTO) {
    case 0:
    default:
        v0.x = 64 * FX32_ONE;
        v0.y = 56 * FX32_ONE;
        break;
    case 1:
        v0.x = 192 * FX32_ONE;
        v0.y = 56 * FX32_ONE;
        break;
    }

    Sprite_SetPosition(param0->slotsMinigameDTO, &v0);
    Sprite_SetAnim(param0->slotsMinigameDTO, 2);
}

void ov20_021D3A2C(UnkStruct_ov20_021D3980 *param0)
{
    Bg_SetOffset(ov20_021D2E04(param0->coins), 3, 3, 64);
}

void ov20_021D3A40(UnkStruct_ov20_021D3980 *param0)
{
    Bg_SetOffset(ov20_021D2E04(param0->coins), 3, 3, 0);
}
