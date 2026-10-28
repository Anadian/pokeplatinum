#include "overlay083/ov83_0223B5A0.h"

#include <nitro.h>
#include <string.h>

#include "generated/game_records.h"
#include "generated/trainer_score_events.h"

#include "struct_decls/tv_broadcast.h"
#include "struct_decls/wi_fi_list.h"

#include "applications/poffin_berry_selection.h"
#include "nintendo_wfc/main.h"
#include "overlay083/ov83_0223C958.h"
#include "overlay083/ov83_0223D150.h"
#include "overlay083/ov83_0223D4CC.h"
#include "overlay083/ov83_0223D6A8.h"
#include "overlay083/ov83_0223F7F4.h"
#include "overlay083/struct_ov83_0223B784.h"
#include "overlay083/struct_ov83_0223FCE8.h"
#include "savedata/save_table.h"

#include "bag.h"
#include "comm_manager.h"
#include "communication_information.h"
#include "communication_system.h"
#include "game_options.h"
#include "game_records.h"
#include "gx_layers.h"
#include "heap.h"
#include "journal.h"
#include "network_icon.h"
#include "overlay_manager.h"
#include "poffin.h"
#include "screen_fade.h"
#include "sound.h"
#include "sound_playback.h"
#include "sprite.h"
#include "system.h"
#include "tv_segment.h"
#include "unk_020363E8.h"
#include "unk_0203909C.h"
#include "vram_transfer.h"
#include "wifi_list.h"

typedef int (*UnkFuncPtr_ov83_0224024C)(PoffinBerrySelectionData *, UnkStruct_ov83_0223B784 *, int *);

typedef struct {
    UnkFuncPtr_ov83_0224024C coins;
    int slotMachineVariant;
} UnkStruct_ov83_0224024C;

int ov83_0223B5B0(ApplicationManager *appMan, int *slotsMinigameDTO);
int ov83_0223B65C(ApplicationManager *appMan, int *slotsMinigameDTO);
int ov83_0223B710(ApplicationManager *appMan, int *slotsMinigameDTO);
static int ov83_0223C344(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2);
static int ov83_0223B78C(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2);
static int ov83_0223B920(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2);
static int ov83_0223B950(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2);
static int ov83_0223B964(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2);
static int ov83_0223B9EC(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2);
static int ov83_0223BB40(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2);
static int ov83_0223BCEC(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2);
static int ov83_0223BF74(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2);
static int ov83_0223C24C(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2);
static int ov83_0223C258(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2);
static void ov83_0223C3E8(UnkStruct_ov83_0223B784 *param0);
static void ov83_0223C480(UnkStruct_ov83_0223B784 *param0);
static void ov83_0223C558(UnkStruct_ov83_0223B784 *param0);
static void ov83_0223C600(UnkStruct_ov83_0223B784 *param0);
static void ov83_0223C6D4(UnkStruct_ov83_0223B784 *param0);
static void ov83_0223C758(UnkStruct_ov83_0223B784 *param0);
static void ov83_0223C7FC(UnkStruct_ov83_0223B784 *param0);
static void ov83_0223C90C(UnkStruct_ov83_0223B784 *param0);
static void ov83_0223C82C(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO);
static void ov83_0223C87C(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO);
static BOOL ov83_0223C8B0(PoffinBerrySelectionData *param0, Poffin *slotsMinigameDTO, int param2);

static const UnkStruct_ov83_0224024C Unk_ov83_0224024C[] = {
    { ov83_0223B78C, 0x1 },
    { ov83_0223B920, 0x0 },
    { ov83_0223B950, 0x0 },
    { ov83_0223B964, 0x0 },
    { ov83_0223B950, 0x0 },
    { ov83_0223C24C, 0x2 },
    { ov83_0223B9EC, 0x0 },
    { ov83_0223BB40, 0x0 },
    { ov83_0223BCEC, 0x0 },
    { ov83_0223B950, 0x0 },
    { ov83_0223BF74, 0x0 },
    { ov83_0223B950, 0x0 },
    { ov83_0223C258, 0x3 },
    { ov83_0223C344, 0x0 }
};

static void ov83_0223B5A0(void *param0)
{
    PoffinBerrySelectionData *v0 = (PoffinBerrySelectionData *)param0;
    UnkStruct_ov83_0223B784 *v1 = v0->buffer;

    ov83_0223CBFC(v1);
    VramTransfer_Process();
}

int ov83_0223B5B0(ApplicationManager *appMan, int *slotsMinigameDTO)
{
    PoffinBerrySelectionData *v0 = ApplicationManager_Args(appMan);
    UnkStruct_ov83_0223B784 *v1;

    Heap_Create(HEAP_ID_APPLICATION, HEAP_ID_56, 0x20000);
    v1 = ApplicationManager_NewData(appMan, sizeof(UnkStruct_ov83_0223B784), HEAP_ID_56);
    memset(v1, 0, sizeof(UnkStruct_ov83_0223B784));

    v0->buffer = v1;
    v1->heapID = HEAP_ID_56;

    VramTransfer_New(16, v1->heapID);

    v1->unk_1490 = v0->isInGroup == TRUE;

    ov83_0223D150(v1, v0->ctx->trainerInfo);

    if (v0->unk_26) {
        sub_0203632C(1);
    }

    v1->unk_24 = Options_Frame(v0->ctx->options);
    v1->unk_28 = Options_TextFrameDelay(v0->ctx->options);
    v1->unk_31C = 1;

    SetVBlankCallback(ov83_0223B5A0, v0);
    DisableHBlank();
    Sound_SetSceneAndPlayBGM(SOUND_SCENE_12, SEQ_KINOMI1_sseq, 1);

    return 1;
}

int ov83_0223B65C(ApplicationManager *appMan, int *slotsMinigameDTO)
{
    int v0, v1;
    PoffinBerrySelectionData *v2 = ApplicationManager_Args(appMan);
    UnkStruct_ov83_0223B784 *v3 = (UnkStruct_ov83_0223B784 *)ApplicationManager_Data(appMan);
    const UnkStruct_ov83_0224024C *v4;

    v0 = v3->slotsMinigameDTO;
    v4 = &(Unk_ov83_0224024C[v0]);

    switch (*slotsMinigameDTO) {
    case 0:
        if (v4->coins == NULL) {
            break;
        }

        v1 = v4->slotMachineVariant;
        v3->slotsMinigameDTO = (v4->coins)(v2, v3, &v3->unk_10);

        if (v3->unk_19) {
            v3->slotsMinigameDTO = v3->unk_1A;
            v3->unk_19 = 0;
        }

        if (v0 == v3->slotsMinigameDTO) {
            break;
        }

        v3->unk_10 = 0;

        if (!v2->isInGroup) {
            break;
        }

        if (v1 == 0) {
            break;
        }

        v3->unk_08 = v1;
        *slotsMinigameDTO = 1;
        break;
    case 1:
        CommTiming_StartSync(v3->unk_08);
        *slotsMinigameDTO = 2;
        break;
    case 2:
        if (!CommTiming_IsSyncState(v3->unk_08)) {
            break;
        }

        *slotsMinigameDTO = 0;
        v3->unk_08 = 0;
        break;
    }

    ov83_0223CBA4(v3);
    CommManager_Dummy_02038A1C(v3->heapID, v3->unk_20);

    if (v3->slotMachineVariant) {
        return 1;
    } else {
        return 0;
    }
}

int ov83_0223B710(ApplicationManager *appMan, int *slotsMinigameDTO)
{
    int heapID;
    PoffinBerrySelectionData *v1 = ApplicationManager_Args(appMan);
    UnkStruct_ov83_0223B784 *v2 = (UnkStruct_ov83_0223B784 *)ApplicationManager_Data(appMan);

    heapID = v2->heapID;

    if (v1->unk_26) {
        if (CommSys_CurNetId() == 0) {
            NintendoWFC_ResetMatchmakingCancelState();
        }
    }

    ov83_0223D1EC(v2);

    SetVBlankCallback(NULL, NULL);
    DisableHBlank();
    VramTransfer_Free();
    MI_CpuClear8(v2, sizeof(UnkStruct_ov83_0223B784));
    ApplicationManager_FreeData(appMan);

    v1->buffer = NULL;

    Heap_Destroy(heapID);
    return 1;
}

void ov83_0223B774(UnkStruct_ov83_0223B784 *param0, int slotsMinigameDTO)
{
    param0->unk_18 = slotsMinigameDTO;
    param0->unk_14 = 1;
}

void ov83_0223B77C(UnkStruct_ov83_0223B784 *param0, int slotsMinigameDTO)
{
    param0->unk_1A = slotsMinigameDTO;
    param0->unk_19 = 1;
}

void ov83_0223B784(UnkStruct_ov83_0223B784 *param0)
{
    param0->slotMachineVariant = 1;
}

static int ov83_0223B78C(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2)
{
    switch (*param2) {
    case 0:

        ov83_0223C82C(param0, slotsMinigameDTO);

        if (ov83_0223D570(slotsMinigameDTO->unk_148C) == 0) {
            ov83_0223FDB0(&slotsMinigameDTO->unk_34C);
        }

        ov83_0223DEA0(&slotsMinigameDTO->unk_5B0, slotsMinigameDTO->unk_1488, &slotsMinigameDTO->unk_15E0, &slotsMinigameDTO->unk_1494, slotsMinigameDTO->unk_24, slotsMinigameDTO->heapID);
        ov83_0223E340(&slotsMinigameDTO->unk_608);
        ov83_0223E6D4(&slotsMinigameDTO->unk_6A0, slotsMinigameDTO->unk_1488, &slotsMinigameDTO->unk_15E0, &slotsMinigameDTO->unk_1494, slotsMinigameDTO->unk_24, slotsMinigameDTO->heapID);
        ov83_0223E244(&slotsMinigameDTO->unk_5E4);
        ov83_0223E244(&slotsMinigameDTO->unk_5F0);
        ov83_0223E244(&slotsMinigameDTO->unk_5FC);
        ov83_0223E5A4(&slotsMinigameDTO->unk_680, &slotsMinigameDTO->unk_1494, slotsMinigameDTO->unk_1488, slotsMinigameDTO->unk_148C);
        ov83_0223ED3C(&slotsMinigameDTO->unk_6D8);
        ov83_0223F29C(&slotsMinigameDTO->unk_AEC);
        ov83_0223F494(&slotsMinigameDTO->unk_B6C, slotsMinigameDTO->unk_1488);
        ov83_0223F820(&slotsMinigameDTO->unk_334);
        ov83_0223C958(slotsMinigameDTO);

        NetworkIcon_Init();
        GXLayers_EngineAToggleLayers(GX_PLANEMASK_OBJ, 1);

        if (slotsMinigameDTO->unk_1488 > 1) {
            ov83_0223DF84(&slotsMinigameDTO->unk_5B0);
        }

        ov83_0223E484(&slotsMinigameDTO->unk_608, 3, 1);
        ov83_0223E484(&slotsMinigameDTO->unk_608, 4, 1);
        ov83_0223E484(&slotsMinigameDTO->unk_608, 5, 1);
        ov83_0223E484(&slotsMinigameDTO->unk_608, 6, 1);
        (*param2)++;
        break;
    case 1:
        StartScreenFade(FADE_BOTH_SCREENS, 1, 1, 0xffff, 6, 1, slotsMinigameDTO->heapID);
        (*param2)++;
        break;
    case 2:
        if (IsScreenFadeDone()) {
            return slotsMinigameDTO->slotsMinigameDTO + 1;
        }
        break;
    }

    return slotsMinigameDTO->slotsMinigameDTO;
}

static int ov83_0223B920(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2)
{
    BOOL v0;

    if (ov83_0223D570(slotsMinigameDTO->unk_148C) == 0) {
        v0 = ov83_0223D508(22, NULL, 0, slotsMinigameDTO->unk_148C);

        if (v0 == 0) {
            return slotsMinigameDTO->slotsMinigameDTO;
        }
    }

    return slotsMinigameDTO->slotsMinigameDTO + 1;
}

static int ov83_0223B950(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2)
{
    if (slotsMinigameDTO->unk_14) {
        slotsMinigameDTO->slotsMinigameDTO = slotsMinigameDTO->unk_18;
        slotsMinigameDTO->unk_14 = 0;
    }

    return slotsMinigameDTO->slotsMinigameDTO;
}

static int ov83_0223B964(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2)
{
    BOOL v0;

    switch (*param2) {
    case 0:
        ov83_0223DB18(&slotsMinigameDTO->unk_3C0, slotsMinigameDTO->unk_1488);
        (*param2)++;
        break;
    case 1:
        slotsMinigameDTO->unk_1494.coins.coins = param0->item;
        {
            int v1;

            for (v1 = 0; v1 < 5; v1++) {
                slotsMinigameDTO->unk_165C[v1] = 2;
            }

            slotsMinigameDTO->unk_1666 = 2;
        }
        (*param2)++;
        break;

    case 2:
        v0 = ov83_0223D508(25, &slotsMinigameDTO->unk_1494.coins, ov83_0223D4B8(), slotsMinigameDTO->unk_148C);

        if (v0 == 1) {
            return slotsMinigameDTO->slotsMinigameDTO + 1;
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }

    return slotsMinigameDTO->slotsMinigameDTO;
}

static int ov83_0223B9EC(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2)
{
    u32 v0;
    int v1;
    BOOL v2;

    switch (*param2) {
    case 0:
        ov83_0223F790(&slotsMinigameDTO->unk_1480, slotsMinigameDTO->heapID, slotsMinigameDTO->unk_20);
        (*param2)++;
        break;
    case 1:
        ov83_0223DC68(&slotsMinigameDTO->unk_3C0);
        (*param2)++;
        break;
    case 2:
        v0 = ov83_0223DD30(&slotsMinigameDTO->unk_3C0);

        if (v0 == 1) {
            (*param2)++;
            ov83_0223DF70(&slotsMinigameDTO->unk_5B0);
            slotsMinigameDTO->unk_1C = 24;
        } else if (v0 != 0) {
            v1 = slotsMinigameDTO->unk_1494.unk_130[v0 - 2];
            ov83_0223DF30(&slotsMinigameDTO->unk_5B0, slotsMinigameDTO->unk_1494.unk_6C.coins[v1].coins);
        }
        break;
    case 3:
        if (slotsMinigameDTO->unk_1C > 0) {
            slotsMinigameDTO->unk_1C--;
            break;
        }

        ov83_0223E2FC(&slotsMinigameDTO->unk_5FC);
        (*param2)++;
        break;
    case 4:
        if (ov83_0223E32C(&slotsMinigameDTO->unk_5FC) == 0) {
            break;
        }

        ov83_0223DFAC(&slotsMinigameDTO->unk_5B0);
        ov83_0223E2E4(&slotsMinigameDTO->unk_5E4);
        (*param2)++;
        break;
    case 5:
        v2 = ov83_0223E32C(&slotsMinigameDTO->unk_5E4);
        {
            int v3 = Sprite_GetAnimFrame(slotsMinigameDTO->unk_5E4.unk_08);

            if (slotsMinigameDTO->unk_3BC != (v3 + 1) / 3) {
                if (v3 < 10) {
                    Sound_PlayEffect(SEQ_SE_DP_NM10_sseq);
                } else {
                    Sound_PlayEffect(SEQ_SE_DP_NM10_2_sseq);
                }

                slotsMinigameDTO->unk_3BC = (v3 + 1) / 3;
            }
        }

        if (v2) {
            ov83_0223E69C(&slotsMinigameDTO->unk_680, 1);
            ov83_0223E500(&slotsMinigameDTO->unk_608);

            return slotsMinigameDTO->slotsMinigameDTO + 1;
        }
        break;
    }

    return slotsMinigameDTO->slotsMinigameDTO;
}

static int ov83_0223BB40(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2)
{
    BOOL v0;

    ov83_0223F83C(&slotsMinigameDTO->unk_334);
    ov83_0223F88C(&slotsMinigameDTO->unk_1494.slotMachineVariant.coins, &slotsMinigameDTO->unk_334);

    if (ov83_0223D570(slotsMinigameDTO->unk_148C) == 0) {
        v0 = ov83_0223FDD8(&slotsMinigameDTO->unk_34C, &slotsMinigameDTO->unk_1494, slotsMinigameDTO->unk_1488);

        if (v0 == 1) {
            v0 = ov83_0223D508(23, NULL, 0, slotsMinigameDTO->unk_148C);
            return slotsMinigameDTO->slotsMinigameDTO;
        } else {
            ov83_0223FFA0(&slotsMinigameDTO->unk_34C);

            if (slotsMinigameDTO->unk_15DC == 0) {
                ov83_0223FE50(&slotsMinigameDTO->unk_34C, &slotsMinigameDTO->unk_1494, slotsMinigameDTO->unk_1488);
                slotsMinigameDTO->unk_15DC = 1;
            } else {
                ov83_0223FEC0(&slotsMinigameDTO->unk_34C, &slotsMinigameDTO->unk_1494, slotsMinigameDTO->unk_1488);
            }
        }
    }

    if (param0->unk_26) {
        slotsMinigameDTO->unk_1658++;

        if ((slotsMinigameDTO->unk_1658 % 2) == 0) {
            slotsMinigameDTO->unk_1658 = 0;

            if (ov83_0223D570(slotsMinigameDTO->unk_148C) == 0) {
                {
                    BOOL v1 = 1;
                    int v2;

                    for (v2 = 1; v2 < (7 + 1); v2++) {
                        if (CommSys_IsPlayerConnected(v2)) {
                            if (slotsMinigameDTO->unk_165C[v2] == 0) {
                                v1 = 0;
                            }
                        }
                    }

                    if (v1) {
                        v0 = ov83_0223D508(26, &slotsMinigameDTO->unk_1494.slotMachineVariant, ov83_0223D4BC(), slotsMinigameDTO->unk_148C);
                        slotsMinigameDTO->unk_15DC = 0;

                        for (v2 = 1; v2 < (7 + 1); v2++) {
                            if (CommSys_IsPlayerConnected(v2)) {
                                slotsMinigameDTO->unk_165C[v2]--;
                            }
                        }
                    }
                }
            } else {
                if (slotsMinigameDTO->unk_1666) {
                    v0 = ov83_0223D508(32, &slotsMinigameDTO->unk_1494.slotMachineVariant.coins, ov83_0223D4C8(), slotsMinigameDTO->unk_148C);
                    slotsMinigameDTO->unk_1666--;
                }
            }
        }
    } else {
        v0 = ov83_0223D508(26, &slotsMinigameDTO->unk_1494.slotMachineVariant, ov83_0223D4BC(), slotsMinigameDTO->unk_148C);
        slotsMinigameDTO->unk_15DC = 0;
    }

    if (v0 == 0) {
        (void)0;
    }

    ov83_0223C3E8(slotsMinigameDTO);
    ov83_0223EDA4(&slotsMinigameDTO->unk_6D8, &slotsMinigameDTO->unk_1494);
    ov83_0223F378(&slotsMinigameDTO->unk_AEC);
    ov83_0223F52C(&slotsMinigameDTO->unk_B6C);

    return slotsMinigameDTO->slotsMinigameDTO;
}

static int ov83_0223BCEC(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2)
{
    Poffin *v0;
    BOOL v1;

    ov83_0223EDA4(&slotsMinigameDTO->unk_6D8, &slotsMinigameDTO->unk_1494);

    switch (*param2) {
    case 0:
        ov83_0223E994(&slotsMinigameDTO->unk_6A0);
        ov83_0223F3D0(&slotsMinigameDTO->unk_AEC, 0);
        ov83_0223F3D0(&slotsMinigameDTO->unk_AEC, 1);
        ov83_0223F3D0(&slotsMinigameDTO->unk_AEC, 2);
        ov83_0223F3D0(&slotsMinigameDTO->unk_AEC, 3);
        ov83_0223E2E4(&slotsMinigameDTO->unk_5F0);

        Sound_StopEffect(1722, 0);
        Sound_StopEffect(1723, 0);
        Sound_StopEffect(1727, 0);
        Sound_StopEffect(1729, 0);
        Sound_PlayEffect(SEQ_SE_DP_NM13_sseq);

        ov83_0223E484(&slotsMinigameDTO->unk_608, 0, 0);
        ov83_0223E484(&slotsMinigameDTO->unk_608, 1, 0);
        ov83_0223E484(&slotsMinigameDTO->unk_608, 2, 0);
        (*param2)++;
        break;
    case 1:
        if (ov83_0223E32C(&slotsMinigameDTO->unk_5F0) == 0) {
            break;
        }

        StartScreenFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, COLOR_BLACK, 6, 1, slotsMinigameDTO->heapID);
        (*param2)++;
        break;
    case 2:
        if (IsScreenFadeDone()) {
            if (param0->unk_26) {
                sub_0203632C(0);
            }
            (*param2)++;
        }
        break;
    case 3: {
        GameRecords *v2 = SaveData_GetGameRecords(param0->ctx->saveData);

        if (slotsMinigameDTO->unk_1490 == 0) {
            GameRecords_IncrementTrainerScore(v2, TRAINER_SCORE_EVENT_UNK_12);
            GameRecords_IncrementRecordValue(v2, RECORD_UNK_052);
        } else {
            GameRecords_IncrementTrainerScore(v2, TRAINER_SCORE_EVENT_UNK_18);
            GameRecords_IncrementRecordValue(v2, RECORD_UNK_053);
        }
    }

        if (slotsMinigameDTO->unk_1490 != 0) {
            WiFiList *v3 = SaveData_GetWiFiList(param0->ctx->saveData);
            int v4;
            int v5, v6;
            int v7;
            DWCFriendData *v8;

            for (v4 = 0; v4 < slotsMinigameDTO->unk_1488; v4++) {
                v5 = slotsMinigameDTO->unk_1494.unk_130[v4];
                v8 = CommInfo_DWCFriendData(v5);
                v6 = sub_0203909C(param0->ctx->saveData, v8, &v7);

                switch (v6) {
                case 0:
                case 1:
                    sub_0202B1D0(v3, v7, 1);
                    break;
                default:
                    break;
                }
            }
        }

        (*param2)++;
        break;
    case 4:
        if (ov83_0223D570(slotsMinigameDTO->unk_148C) == 0) {
            v0 = Poffin_New(slotsMinigameDTO->heapID);
            ov83_0223FFD4(&slotsMinigameDTO->unk_34C, v0, &slotsMinigameDTO->unk_1494, slotsMinigameDTO->unk_1488, slotsMinigameDTO->heapID);
            v1 = ov83_0223D508(28, v0, Poffin_SizeOf(), slotsMinigameDTO->unk_148C);
            Heap_Free(v0);

            if (v1 == 1) {
                (*param2)++;
            }
        } else {
            (*param2)++;
        }
        break;
    case 5:
        if (ov83_0223D570(slotsMinigameDTO->unk_148C) == 0) {
            ov83_022401AC(&slotsMinigameDTO->unk_34C, &slotsMinigameDTO->unk_1494, slotsMinigameDTO->unk_1488);
            v1 = ov83_0223D508(27, &slotsMinigameDTO->unk_1494.unk_20, ov83_0223D4C0(), slotsMinigameDTO->unk_148C);

            if (v1 == 1) {
                (*param2)++;
            }
        } else {
            (*param2)++;
        }
        break;
    case 6:
        return slotsMinigameDTO->slotsMinigameDTO + 1;
    default:
        GF_ASSERT(FALSE);
        break;
    }

    return slotsMinigameDTO->slotsMinigameDTO;
}

static int ov83_0223BF74(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2)
{
    u32 v0;
    BOOL v1;
    u8 v2;

    switch (*param2) {
    case 0:
        ov83_0223EC4C(&slotsMinigameDTO->unk_6A0, 0);
        GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG0, 0);
        GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG1, 0);
        GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG2, 1);

        slotsMinigameDTO->unk_31C = 0;

        ov83_0223F730(&slotsMinigameDTO->unk_1478, 128, 144, slotsMinigameDTO->unk_1494.unk_58.slotsMinigameDTO, slotsMinigameDTO->heapID);
        StartScreenFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_OUT, COLOR_BLACK, 6, 1, slotsMinigameDTO->heapID);
        (*param2)++;
        break;
    case 1:
        if (IsScreenFadeDone()) {
            (*param2)++;
            slotsMinigameDTO->unk_1C = (30 * 1);
        }
        break;
    case 2:
        slotsMinigameDTO->unk_1C--;

        if (slotsMinigameDTO->unk_1C < 0) {
            ov83_0223EC4C(&slotsMinigameDTO->unk_6A0, 1);
            Sound_PlayEffect(SEQ_SE_DP_NM14_sseq);
            (*param2)++;
            slotsMinigameDTO->unk_1C = (30 * 1);
        }
        break;
    case 3:
        slotsMinigameDTO->unk_1C--;

        if (slotsMinigameDTO->unk_1C < 0) {
            ov83_0223EC4C(&slotsMinigameDTO->unk_6A0, 2);
            ov83_0223F784(&slotsMinigameDTO->unk_1478);
            Sound_PlayEffect(SEQ_SE_DP_NM14_sseq);
            (*param2)++;
            slotsMinigameDTO->unk_1C = (30 * 20);
        }
        break;
    case 4:
        slotsMinigameDTO->unk_1C--;

        if ((slotsMinigameDTO->unk_1C < 0) || (gSystem.touchPressed) || (gSystem.pressedKeys & (PAD_BUTTON_A | PAD_BUTTON_B))) {
            (*param2)++;
            break;
        }

        ov83_0223F784(&slotsMinigameDTO->unk_1478);
        break;
    case 5:
        ov83_0223F770(&slotsMinigameDTO->unk_1478);
        ov83_0223EC70(&slotsMinigameDTO->unk_6A0);
        ov83_0223C8B0(param0, slotsMinigameDTO->unk_1494.unk_100, slotsMinigameDTO->unk_1488);
        ov83_0223EC8C(&slotsMinigameDTO->unk_6A0, 0);
        slotsMinigameDTO->unk_1C = (30 * 5);
        (*param2)++;
        break;
    case 6:
        slotsMinigameDTO->unk_1C--;

        if ((gSystem.touchPressed) || (slotsMinigameDTO->unk_1C < 0) || (gSystem.pressedKeys & (PAD_BUTTON_A | PAD_BUTTON_B))) {
            (*param2)++;
        }
        break;
    case 7:
        ov83_0223EC8C(&slotsMinigameDTO->unk_6A0, 1);
        ov83_0223F7B0(&slotsMinigameDTO->unk_1480);
        (*param2)++;
        break;
    case 8:
        v0 = ov83_0223F7DC(&slotsMinigameDTO->unk_1480);

        if (v0 == YES_NO_TOUCH_MENU_YES || v0 == YES_NO_TOUCH_MENU_NO) {
            if (v0 == YES_NO_TOUCH_MENU_YES) {
                if (PoffinCase_CountFilledSlots(param0->ctx->poffinCase) >= MAX_POFFINS) {
                    ov83_0223EC8C(&slotsMinigameDTO->unk_6A0, 2);
                    (*param2) = 10;
                    slotsMinigameDTO->unk_1C = (30 * 5);
                    break;
                }

                if (Bag_HasItemsInPocket(param0->ctx->bag, POCKET_BERRIES) == FALSE) {
                    ov83_0223EC8C(&slotsMinigameDTO->unk_6A0, 5);
                    (*param2) = 10;
                    slotsMinigameDTO->unk_1C = (30 * 5);
                    break;
                }

                (*param2) = 9;
            } else {
                (*param2) = 11;
            }

            if (slotsMinigameDTO->unk_1488 > 1) {
                ov83_0223EC8C(&slotsMinigameDTO->unk_6A0, 6);
                ov83_0223E9BC(&slotsMinigameDTO->unk_6A0);
            }
        }
        break;
    case 9:
        slotsMinigameDTO->unk_3B4 = 1;
        v1 = ov83_0223D508(30, &slotsMinigameDTO->unk_3B4, ov83_0223D4B0(), slotsMinigameDTO->unk_148C);

        if (v1 == 1) {
            return slotsMinigameDTO->slotsMinigameDTO + 1;
        }
        break;
    case 10:
        slotsMinigameDTO->unk_1C--;

        if ((gSystem.touchPressed) || (slotsMinigameDTO->unk_1C < 0) || (gSystem.pressedKeys & (PAD_BUTTON_A | PAD_BUTTON_B))) {
            if (slotsMinigameDTO->unk_1488 > 1) {
                ov83_0223EC8C(&slotsMinigameDTO->unk_6A0, 6);
                ov83_0223E9BC(&slotsMinigameDTO->unk_6A0);
            }
            (*param2) = 11;
        }
        break;
    case 11:
        slotsMinigameDTO->unk_3B4 = 0;
        v1 = ov83_0223D508(30, &slotsMinigameDTO->unk_3B4, ov83_0223D4B0(), slotsMinigameDTO->unk_148C);

        if (v1 == 1) {
            return slotsMinigameDTO->slotsMinigameDTO + 1;
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }

    return slotsMinigameDTO->slotsMinigameDTO;
}

static int ov83_0223C24C(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2)
{
    return ov83_0223CB5C(slotsMinigameDTO, param2);
}

static int ov83_0223C258(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2)
{
    switch (*param2) {
    case 0:
        if (slotsMinigameDTO->unk_1494.unk_145 == 1) {
            ov83_0223EC8C(&slotsMinigameDTO->unk_6A0, 3);
            param0->unk_20 = TRUE;
        } else {
            param0->unk_20 = FALSE;

            if (slotsMinigameDTO->unk_1488 <= 1) {
                (*param2) = 2;
                break;
            } else {
                ov83_0223EC8C(&slotsMinigameDTO->unk_6A0, 4);
            }

            void *journalEntryOnlineEvent;

            if (slotsMinigameDTO->unk_1490 == 1) {
                journalEntryOnlineEvent = JournalEntry_CreateEventMadePoffins(slotsMinigameDTO->heapID);
                JournalEntry_SaveData(param0->ctx->journalEntry, journalEntryOnlineEvent, JOURNAL_ONLINE_EVENT);
            }
        }

        slotsMinigameDTO->unk_1C = (30 * 2);
        (*param2)++;
        break;
    case 1:
        slotsMinigameDTO->unk_1C--;

        if (slotsMinigameDTO->unk_1C < 0) {
            (*param2)++;
        }
        break;
    case 2:
        StartScreenFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, COLOR_BLACK, 6, 1, slotsMinigameDTO->heapID);
        (*param2)++;
        break;
    case 3:
        if (IsScreenFadeDone()) {
            (*param2)++;
        }
        break;
    case 4:
        ov83_0223CB8C(slotsMinigameDTO, param2);
        ov83_0223CAA4(slotsMinigameDTO);

        return slotsMinigameDTO->slotsMinigameDTO + 1;
    }

    return slotsMinigameDTO->slotsMinigameDTO;
}

static int ov83_0223C344(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO, int *param2)
{
    ov83_0223DB30(&slotsMinigameDTO->unk_3C0);
    ov83_0223DEC4(&slotsMinigameDTO->unk_5B0);
    ov83_0223E260(&slotsMinigameDTO->unk_5E4);
    ov83_0223E260(&slotsMinigameDTO->unk_5F0);
    ov83_0223E260(&slotsMinigameDTO->unk_5FC);
    ov83_0223E34C(&slotsMinigameDTO->unk_608);
    ov83_0223E5C0(&slotsMinigameDTO->unk_680);
    ov83_0223E6F8(&slotsMinigameDTO->unk_6A0);
    ov83_0223ED4C(&slotsMinigameDTO->unk_6D8);
    ov83_0223F2A8(&slotsMinigameDTO->unk_AEC);
    ov83_0223F4AC(&slotsMinigameDTO->unk_B6C);
    ov83_0223F7A4(&slotsMinigameDTO->unk_1480);
    ov83_0223C87C(param0, slotsMinigameDTO);
    ov83_0223B784(slotsMinigameDTO);

    return slotsMinigameDTO->slotsMinigameDTO;
}

static void ov83_0223C3E8(UnkStruct_ov83_0223B784 *param0)
{
    UnkStruct_ov83_0223FCE8 *v0 = &param0->unk_1494.unk_90[0].unk_08;
    fx32 v1;

    if (v0->slotsMinigameDTO == 0) {
        param0->unk_1654 += v0->unk_0A;
    } else {
        param0->unk_1654 -= v0->unk_0A;
    }

    ov83_0223E4A4(&param0->unk_608, param0->unk_1654);
    ov83_0223C90C(param0);

    v1 = ov83_0223FB68(v0->unk_0A, v0->unk_0D);

    ov83_0223E4C0(&param0->unk_608, v1);
    ov83_0223E51C(&param0->unk_608, v0->unk_0D);
    ov83_0223E658(&param0->unk_680);
    ov83_0223C480(param0);
    ov83_0223C758(param0);
    ov83_0223C558(param0);
    ov83_0223C600(param0);
    ov83_0223C6D4(param0);
    ov83_0223C7FC(param0);

    {
        v0->unk_13 = 0;
        v0->unk_12 = 0;
        v0->unk_0F = 0;
        v0->unk_0E = 0;
    }
}

static void ov83_0223C480(UnkStruct_ov83_0223B784 *param0)
{
    UnkStruct_ov83_0223FCE8 *v0 = &param0->unk_1494.unk_90[0].unk_08;
    static const u8 v1[3][7] = {
        { 1, 1, 0, 1, 0, 0, 5 },
        { 0, 1, 1, 0, 1, 0, 6 },
        { 0, 0, 1, 0, 0, 1, 8 },
    };

    ov83_0223E484(&param0->unk_608, 5, v1[v0->unk_0D][0]);
    ov83_0223E484(&param0->unk_608, 6, v1[v0->unk_0D][1]);
    ov83_0223E484(&param0->unk_608, 7, v1[v0->unk_0D][2]);
    ov83_0223E484(&param0->unk_608, 0, v1[v0->unk_0D][3]);
    ov83_0223E484(&param0->unk_608, 1, v1[v0->unk_0D][4]);
    ov83_0223E484(&param0->unk_608, 2, v1[v0->unk_0D][5]);

    if (v1[v0->unk_0D][6] != 8) {
        if (v0->unk_10 > 0) {
            ov83_0223E4E0(&param0->unk_608, v1[v0->unk_0D][6], v0->unk_10);
        } else {
            ov83_0223E484(&param0->unk_608, v1[v0->unk_0D][6], 0);
        }
    }
}

static void ov83_0223C558(UnkStruct_ov83_0223B784 *param0)
{
    UnkStruct_ov83_0223FCE8 *v0 = &param0->unk_1494.unk_90[0].unk_08;

    if ((v0->unk_11 == v0->slotsMinigameDTO) || (v0->unk_0A == 0) || (param0->unk_324 != 0)) {
        ov83_0223F3D0(&param0->unk_AEC, 1);
        ov83_0223F3D0(&param0->unk_AEC, 3);
        param0->unk_328 = 0;
    } else {
        if (v0->unk_11 == 0) {
            if (param0->unk_328 != 1) {
                ov83_0223F3A0(&param0->unk_AEC, 1);
                param0->unk_328 = 1;
                ov83_0223F3D0(&param0->unk_AEC, 3);
                Sound_PlayEffect(SEQ_SE_DP_NM12_2_sseq);
            }
        } else {
            if (param0->unk_328 != 2) {
                ov83_0223F3A0(&param0->unk_AEC, 3);
                param0->unk_328 = 2;
                ov83_0223F3D0(&param0->unk_AEC, 1);
                Sound_PlayEffect(SEQ_SE_DP_NM12_2_sseq);
            }
        }
    }
}

static void ov83_0223C600(UnkStruct_ov83_0223B784 *param0)
{
    UnkStruct_ov83_0223FCE8 *v0 = &param0->unk_1494.unk_90[0].unk_08;
    static const u8 v1[3] = {
        1, 3, 0
    };
    static const u8 v2[3] = {
        0, 2, 4
    };

    if ((param0->unk_328 != 0) || (param0->unk_324 != 0)) {
        ov83_0223E994(&param0->unk_6A0);
        param0->unk_330 = 0;
        param0->unk_32C = 0;
    } else {
        if (param0->unk_330 == 0) {
            if (v0->unk_13) {
                ov83_0223E994(&param0->unk_6A0);
                ov83_0223E908(&param0->unk_6A0, v1[v0->unk_0D]);
                param0->unk_330 = 1;
                param0->unk_32C = 0;
            }
        } else {
            if (ov83_0223E984(&param0->unk_6A0)) {
                param0->unk_330 = 0;
            }
        }

        if (param0->unk_32C == 0) {
            if (v0->unk_12) {
                ov83_0223E994(&param0->unk_6A0);
                ov83_0223E908(&param0->unk_6A0, v2[v0->unk_0D]);
                param0->unk_32C = 1;
                param0->unk_330 = 0;
            }
        } else {
            if (ov83_0223E984(&param0->unk_6A0)) {
                param0->unk_32C = 0;
            }
        }
    }
}

static void ov83_0223C6D4(UnkStruct_ov83_0223B784 *param0)
{
    UnkStruct_ov83_0223FCE8 *v0 = &param0->unk_1494.unk_90[0].unk_08;
    static const u32 v1[3] = {
        1714, 1720, 1720
    };
    static const u32 v2[3] = {
        1715, 1715, 1723
    };

    if (v0->unk_13) {
        ov83_0223EDDC(&param0->unk_6D8, v0->unk_0D, 2);
        Sound_PlayEffect(v1[v0->unk_0D]);
    }

    if (v0->unk_12 == 1) {
        ov83_0223EDDC(&param0->unk_6D8, v0->unk_0D, 1);
        Sound_PlayEffect(v2[v0->unk_0D]);
    } else if (v0->unk_12 == 2) {
        ov83_0223EDDC(&param0->unk_6D8, v0->unk_0D, 0);
    }

    if (ov83_0223FB50(v0->unk_0A, v0->unk_0D) == 0) {
        ov83_0223EFCC(&param0->unk_6D8);
    }
}

static void ov83_0223C758(UnkStruct_ov83_0223B784 *param0)
{
    UnkStruct_ov83_0223FCE8 *v0 = &param0->unk_1494.unk_90[0].unk_08;
    BOOL v1;

    if (v0->unk_0E) {
        if (v0->unk_11 == 0) {
            ov83_0223F3A0(&param0->unk_AEC, 0);
            ov83_0223F3D0(&param0->unk_AEC, 2);
            Sound_PlayEffect(SEQ_SE_DP_NM12_2_sseq);
            param0->unk_324 = 1;
        } else {
            ov83_0223F3A0(&param0->unk_AEC, 2);
            ov83_0223F3D0(&param0->unk_AEC, 0);
            Sound_PlayEffect(SEQ_SE_DP_NM12_2_sseq);
            param0->unk_324 = 2;
        }
    }

    if (param0->unk_324 == 1) {
        v1 = ov83_0223F3F0(&param0->unk_AEC, 0);

        if (v1 == 1) {
            param0->unk_324 = 0;
        }
    } else if (param0->unk_324 == 2) {
        v1 = ov83_0223F3F0(&param0->unk_AEC, 2);

        if (v1 == 1) {
            param0->unk_324 = 0;
        }
    }
}

static void ov83_0223C7FC(UnkStruct_ov83_0223B784 *param0)
{
    UnkStruct_ov83_0223FCE8 *v0 = &param0->unk_1494.unk_90[0].unk_08;
    int v1 = param0->unk_1494.slotMachineVariant.coins.coins;
    int v2 = param0->unk_1494.slotMachineVariant.coins.unk_01;

    if (v0->unk_0F == 1) {
        ov83_0223F544(&param0->unk_B6C, v1, v2);
        Sound_PlayEffect(SEQ_SE_DP_NM11_sseq);
    }
}

static void ov83_0223C82C(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO)
{
    int v0;

    slotsMinigameDTO->unk_1494.unk_100 = Poffin_New(slotsMinigameDTO->heapID);
    slotsMinigameDTO->unk_1494.unk_144 = ov83_0223D570(slotsMinigameDTO->unk_148C);

    for (v0 = 0; v0 < 4; v0++) {
        slotsMinigameDTO->unk_1494.unk_90[v0].coins.coins = 128;
        slotsMinigameDTO->unk_1494.unk_90[v0].coins.unk_01 = 96;
    }

    if (param0->unk_26) {
        sub_02035938(2);
    }
}

static void ov83_0223C87C(PoffinBerrySelectionData *param0, UnkStruct_ov83_0223B784 *slotsMinigameDTO)
{
    GF_ASSERT(slotsMinigameDTO->unk_1494.unk_100);

    Heap_Free(slotsMinigameDTO->unk_1494.unk_100);
    slotsMinigameDTO->unk_1494.unk_100 = NULL;

    if (param0->unk_26) {
        sub_02035938(0);
    }
}

static BOOL ov83_0223C8B0(PoffinBerrySelectionData *param0, Poffin *slotsMinigameDTO, int param2)
{
    int v0;
    u16 v1;
    int v2;
    BOOL v3 = 1;
    TVBroadcast *broadcast = SaveData_GetTVBroadcast(param0->ctx->saveData);

    for (v0 = 0; v0 < param2; v0++) {
        v1 = PoffinCase_AddPoffin(param0->ctx->poffinCase, slotsMinigameDTO);

        if (v1 == POFFIN_NONE) {
            v3 = 0;
            break;
        }
    }

    if (param0->unk_26 == 0) {
        v2 = Poffin_GetAttribute(slotsMinigameDTO, 0);
        sub_0206CFCC(broadcast, v2);
    }

    return v3;
}

static void ov83_0223C90C(UnkStruct_ov83_0223B784 *param0)
{
    UnkStruct_ov83_0223FCE8 *v0 = &param0->unk_1494.unk_90[0].unk_08;
    static const u32 v1[3] = {
        1713,
        1718,
        1722,
    };

    if (((v0->slotsMinigameDTO == 0) && (param0->unk_3B8 > v0->unk_08)) || ((v0->slotsMinigameDTO == 1) && (param0->unk_3B8 < v0->unk_08))) {
        Sound_PlayEffect(v1[v0->unk_0D]);
    }

    param0->unk_3B8 = v0->unk_08;
}
