#include "applications/pc_boxes/ov19_021DA814.h"

#include <nitro.h>
#include <string.h>

#include "applications/pc_boxes/box_application.h"
#include "applications/pc_boxes/ov19_021D61B0.h"
#include "applications/pc_boxes/struct_ov19_021D61B0_decl.h"
#include "applications/pc_boxes/struct_ov19_021DA8D8.h"

#include "graphics.h"
#include "heap.h"
#include "narc.h"
#include "sprite.h"

BOOL ov19_021DA814(UnkStruct_ov19_021DA8D8 *param0, UnkStruct_ov19_021D61B0 *slotsMinigameDTO, const BoxApplication *param2, SpriteList *param3, NARC *param4)
{
    param0->unk_44 = slotsMinigameDTO;
    param0->unk_3C = param3;
    param0->unk_40 = param2;
    param0->coins = param3;
    param0->slotMachineVariant = NULL;
    param0->unk_08 = Graphics_GetCellBankFromOpenNARC(param4, 10, 1, &(param0->unk_10), HEAP_ID_BOX_GRAPHICS);
    param0->slotsMinigameDTO = Graphics_GetAnimBankFromOpenNARC(param4, 11, 1, &(param0->unk_14), HEAP_ID_BOX_GRAPHICS);

    if ((param0->unk_08 == NULL) || (param0->slotsMinigameDTO == NULL)) {
        return 0;
    }

    return 1;
}

void ov19_021DA864(UnkStruct_ov19_021DA8D8 *param0, NARC *slotsMinigameDTO)
{
    SpriteResourcesHeader v0;

    NNS_G2dInitImageProxy(&(param0->unk_18));

    Graphics_LoadImageMappingFromOpenNARC(slotsMinigameDTO, 9, 1, 0, 0, NNS_G2D_VRAM_TYPE_2DMAIN, 1256 * 0x20, 10, &(param0->unk_18));
    ov19_021D783C(&v0, &(param0->unk_18), ov19_021D77D0(param0->unk_44), param0->unk_10, param0->unk_14, 2);
    param0->slotMachineVariant = ov19_021D785C(param0->coins, &v0, 183 + ov19_021D7820(param0->unk_44), 176, 44, NNS_G2D_VRAM_TYPE_2DMAIN);
    Sprite_SetExplicitPalette(param0->slotMachineVariant, 1);
}

void ov19_021DA8D8(UnkStruct_ov19_021DA8D8 *param0)
{
    if (param0->unk_08 != NULL) {
        Heap_Free(param0->unk_08);
        param0->unk_08 = NULL;
    }

    if (param0->slotsMinigameDTO != NULL) {
        Heap_Free(param0->slotsMinigameDTO);
        param0->slotsMinigameDTO = NULL;
    }
}

void ov19_021DA8FC(UnkStruct_ov19_021DA8D8 *param0, int slotsMinigameDTO)
{
    switch (slotsMinigameDTO) {
    case 0:
        Sprite_SetAnim(param0->slotMachineVariant, 0);
        break;
    case 1:
        Sprite_SetAnim(param0->slotMachineVariant, 1);
        break;
    case 2:
        Sprite_SetAnim(param0->slotMachineVariant, 2);
        break;
    }
}
