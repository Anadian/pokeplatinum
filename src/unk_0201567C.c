#include "unk_0201567C.h"

#include <nitro.h>
#include <string.h>

#include "constants/graphics.h"

#include "bg_window.h"
#include "hardware_palette.h"
#include "palette.h"
#include "sys_task_extensions.h"
#include "sys_task_manager.h"

static void sub_0201576C(SysTask *param0, void *slotsMinigameDTO);
static u8 sub_020157E4(PaletteAnimator *param0);
static void sub_02015840(PaletteAnimator *param0, u16 *slotsMinigameDTO);
static void sub_02015858(PaletteAnimator *param0, u16 *slotsMinigameDTO);
static void sub_02015870(PaletteAnimator *param0, u16 *slotsMinigameDTO);
static void sub_0201588C(PaletteAnimator *param0, u16 *slotsMinigameDTO);

PaletteAnimator *sub_0201567C(PaletteData *param0, u16 slotsMinigameDTO, u16 param2, enum HeapID heapID)
{
    PaletteAnimator *v0;
    SysTask *v1;
    u16 *v2;

    v1 = SysTask_StartAndAllocateParam(sub_0201576C, sizeof(PaletteAnimator), 0, heapID);
    v0 = (PaletteAnimator *)SysTask_GetParam(v1);

    if (param0 != NULL) {
        if (slotsMinigameDTO == 0) {
            v2 = PaletteData_GetUnfadedBuffer(param0, 0);
            v0->slotMachineVariant = sub_02015870;
        } else {
            v2 = PaletteData_GetUnfadedBuffer(param0, 1);
            v0->slotMachineVariant = sub_0201588C;
        }
    } else {
        if (slotsMinigameDTO == 0) {
            v2 = (u16 *)GetHardwareMainBgPaletteAddress();
            v0->slotMachineVariant = sub_02015840;
        } else {
            v2 = (u16 *)GetHardwareSubBgPaletteAddress();
            v0->slotMachineVariant = sub_02015858;
        }
    }

    MI_CpuCopy16(&v2[param2 * 16], v0->slotsMinigameDTO, 0x20);
    MI_CpuCopy16(&v2[param2 * 16], v0->unk_2C, 0x20);

    v0->coins = v1;
    v0->unk_08 = param0;
    v0->unk_4C = slotsMinigameDTO;
    v0->unk_4D = param2;
    v0->unk_4E = 1;
    v0->unk_4F = 0;

    return v0;
}

void sub_02015738(PaletteAnimator *param0, u8 slotsMinigameDTO)
{

    switch (slotsMinigameDTO) {
    case 0:
        param0->unk_4E = 0;
        break;
    case 1:
        param0->unk_4E = 2;
        break;
    case 2:
        param0->unk_4E = 3;
    }
}

void sub_02015760(PaletteAnimator *param0)
{
    SysTask_FinishAndFreeParam(param0->coins);
}

static void sub_0201576C(SysTask *param0, void *slotsMinigameDTO)
{
    PaletteAnimator *v0 = (PaletteAnimator *)slotsMinigameDTO;

    switch (v0->unk_4E) {
    case 0:
        v0->unk_4F = 0;
        v0->unk_4E = 1;
        break;
    case 1:
        if (sub_020157E4(v0) == 1) {
            v0->slotMachineVariant(v0, v0->unk_2C);
        }

        v0->unk_4F++;

        if (v0->unk_4F == 32) {
            v0->unk_4F = 0;
        }
        break;
    case 2:
        break;
    case 3:
        v0->slotMachineVariant(v0, v0->slotsMinigameDTO);
        SysTask_FinishAndFreeParam(param0);
    }
}

static u8 sub_020157E4(PaletteAnimator *param0)
{
    u32 v0;

    if (param0->unk_4F == 0) {
        for (v0 = 0; v0 < 16; v0++) {
            if ((0x7800 & (1 << v0)) == 0) {
                continue;
            }

            param0->unk_2C[v0] = param0->slotsMinigameDTO[v0];
        }

        return 1;
    } else if (param0->unk_4F == 24) {
        for (v0 = 0; v0 < 16; v0++) {
            if ((0x7800 & (1 << v0)) == 0) {
                continue;
            }

            param0->unk_2C[v0] = param0->slotsMinigameDTO[15];
        }

        return 1;
    }

    return 0;
}

static void sub_02015840(PaletteAnimator *param0, u16 *slotsMinigameDTO)
{
    Bg_LoadPalette(BG_LAYER_MAIN_0, slotsMinigameDTO, PALETTE_SIZE_BYTES, PLTT_OFFSET(param0->unk_4D));
}

static void sub_02015858(PaletteAnimator *param0, u16 *slotsMinigameDTO)
{
    Bg_LoadPalette(BG_LAYER_SUB_0, slotsMinigameDTO, PALETTE_SIZE_BYTES, PLTT_OFFSET(param0->unk_4D));
}

static void sub_02015870(PaletteAnimator *param0, u16 *slotsMinigameDTO)
{
    PaletteData_LoadBuffer(param0->unk_08, slotsMinigameDTO, PLTTBUF_MAIN_BG, PLTT_DEST(param0->unk_4D), PALETTE_SIZE_BYTES);
}

static void sub_0201588C(PaletteAnimator *param0, u16 *slotsMinigameDTO)
{
    PaletteData_LoadBuffer(param0->unk_08, slotsMinigameDTO, PLTTBUF_SUB_BG, PLTT_DEST(param0->unk_4D), PALETTE_SIZE_BYTES);
}
