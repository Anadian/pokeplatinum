#include "overlay101/SlotsMinigame_Init.h"

#include <nitro.h>
#include <string.h>

#include "generated/game_records.h"

#include "struct_defs/struct_0203E348.h"

#include "overlay101/ov101_021D1A28.h"
#include "overlay101/ov101_021D59AC.h"
#include "overlay101/ov101_021D7E48.h"
#include "overlay101/struct_ov101_021D13C8.h"
#include "overlay101/struct_ov101_021D148C.h"
#include "overlay101/struct_ov101_021D1894.h"

#include "bg_window.h"
#include "char_transfer.h"
#include "enums.h"
#include "font.h"
#include "game_records.h"
#include "gx_layers.h"
#include "heap.h"
#include "message.h"
#include "narc.h"
#include "overlay_manager.h"
#include "overworld_anim_manager.h"
#include "pltt_transfer.h"
#include "render_oam.h"
#include "render_window.h"
#include "screen_fade.h"
#include "sound.h"
#include "sound_playback.h"
#include "string_gf.h"
#include "string_template.h"
#include "sys_task.h"
#include "sys_task_manager.h"
#include "system.h"
#include "text.h"
#include "vram_transfer.h"

#if !defined(DEBUG_SLOTS_MINIGAME_DEFINED)
#if defined(DEBUG_SLOTS_MINIGAME)
#include "debug.h"
#define LOG(...) EmulatorLog( __VA_ARGS__ )
#define REC_LOG0() LOG("%s: received", __func__)
#define REC_LOG1(a) LOG("%s: received %u", __func__, a)
#define REC_LOG2(a, b) LOG("%s: received %u %u", __func__, a, b)
#define RET_LOG0(a) LOG("%s: returned", __func__)
#define RET_LOG1(a) LOG("%s: returned %u", __func__, a)
#define DEBUG_SLOTS_MINIGAME_DEFINED 1
#else
#define REC_LOG0() 
#define REC_LOG1(a) 
#define REC_LOG2(a, b) 
#define RET_LOG0(a) 
#define RET_LOG1(a) 
#endif //defined(DEBUG_SLOTS_MINIGAME)
#define DEBUG_SLOTS_MINIGAME_DEFINED 1
#endif //!defined(DEBUG_SLOTS_MINIGAME_DEFINED)

// Formerly known as SlotsMinigame_ApplicationData).
typedef struct {
    SlotsMinigameDTO *slotMachineDTO;
    Overlay101State *overlayState;
} SlotsMinigame_ApplicationData;

static void SlotsMinigame_UpdateRecords(SlotsMinigame_ApplicationData *param0, Overlay101State *slotsMinigameDTO);
static Overlay101State *SlotsMinigame_CreateOverlayState(SlotsMinigameDTO *param0);
static void SlotsMinigame_FreeOverlayState(Overlay101State *param0);
static void SlotsMinigame_SetVBlankCallback(Overlay101State *param0);
static void SlotsMinigame_FreeGraphics(Overlay101State *param0);
static void SlotsMinigame_SetBanks(void);
static void SlotsMinigame_ConfigBackground(BgConfig *param0);
static void SlotsMinigame_FreeBackground(BgConfig *param0);
static void SlotsMinigame_InitWindow(void);
static void SlotsMinigame_LoadGraphics(Overlay101State *param0);
static void SlotsMinigame_InitCharacter(void);
static void SlotsMinigame_FreeCharacter(void);
static void SlotsMinigame_InitRenderer(Overlay101State *param0);
static void SlotsMinigame_FreeRenderer(Overlay101State *param0);
static void SlotsMinigame_CopyGraphicsData(Overlay101State *param0);
static void SlotsMinigame_Noop(Overlay101State *param0);
static void SlotsMinigame_InitAnimationManager(Overlay101State *param0);
static void SlotsMinigame_FreeAnimationManager(Overlay101State *param0);
static int SlotsMinigame_SoundSequence_GetIsChangeActive(Overlay101State *param0);
static void SlotsMinigame_StartSoundTask(Overlay101State *param0);
static void SlotsMinigame_StopSoundTask(Overlay101State *param0);
static void SlotsMinigame_ProcessSound_TaskCallback(SysTask *param0, void *slotsMinigameDTO);
static void SlotsMinigame_Render(void *param0);
static void SlotsMinigame_LoadArchive(Overlay101State *param0);
static void SlotsMinigame_FreeArchive(Overlay101State *param0);
static const WindowTemplate Unk_ov101_021D8588[1];
static void SlotsMinigame_FreeWindow(Overlay101State *param0);

int SlotsMinigame_Init(ApplicationManager *appMan, int *slotsMinigameDTO)
{
	LOG("%s: received appMan=%u slotsMinigameDTO=%u DEBUG_SLOTS_MINIGAME=%u DEBUG_SLOTS_MINIGAME_DEFINED=%u", __func__, appMan, *slotsMinigameDTO, DEBUG_SLOTS_MINIGAME, DEBUG_SLOTS_MINIGAME_DEFINED);
    SlotsMinigame_ApplicationData *v0;
    Overlay101State *v1;
    SlotsMinigameDTO *v2;

    SetVBlankCallback(NULL, NULL);
    DisableHBlank();
    GXLayers_DisableEngineALayers();
    GXLayers_DisableEngineBLayers();
    Heap_Create(HEAP_ID_APPLICATION, HEAP_ID_79, 0x80000);

    v0 = ApplicationManager_NewData(appMan, sizeof(SlotsMinigame_ApplicationData), HEAP_ID_79);
    memset(v0, 0, sizeof(SlotsMinigame_ApplicationData));
    v2 = ApplicationManager_Args(appMan);
    v0->slotMachineDTO = v2;
    v1 = SlotsMinigame_CreateOverlayState(v0->slotMachineDTO);
    v0->overlayState = v1;

    SlotsMinigame_LoadArchive(v1);
    SlotsMinigame_InitAnimationManager(v1);
    SlotsMinigame_SetVBlankCallback(v1);
    SlotsMinigame_LoadGraphics(v1);
    SlotsMinigame_LoadWindow(v1);
    SlotsMinigame_InitCharacter();
    SlotsMinigame_InitRenderer(v1);
    ov101_021D1A28(v1);
    ov101_021D59AC(v1);
    ov101_021D5AF0(v1);
    ov101_021D5C28(v1);
    Sound_SetSceneAndPlayBGM(SOUND_SCENE_SUB_66, SEQ_NONE, 0);
    SlotsMinigame_StartSoundTask(v1);
    StartScreenFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, COLOR_BLACK, 8, 1, HEAP_ID_79);
	LOG("%s: returned 1", __func__);

    return 1;
}

// Formerly SlotsMinigame_Main.
int SlotsMinigame_Main(ApplicationManager *appMan, int *slotsMinigameDTO)
{
	//LOG("%s: appMan=%u *slotsMinigameDTO=%u", __func__, appMan, *slotsMinigameDTO);
	REC_LOG2(appMan,*slotsMinigameDTO);
    SlotsMinigame_ApplicationData *v0 = ApplicationManager_Data(appMan);
    Overlay101State *v1 = v0->overlayState;

    switch (*slotsMinigameDTO) {
    case 0:
		LOG("%s state=%u", __func__, *slotsMinigameDTO);
        if (IsScreenFadeDone()) {
            (*slotsMinigameDTO)++;
        }
        break;
    case 1:
		LOG("%s state=%u", __func__, *slotsMinigameDTO);
        if (ov101_021D1AAC(v1) == 1) {
            (*slotsMinigameDTO)++;
            StartScreenFade(FADE_SUB_THEN_MAIN, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, COLOR_BLACK, 8, 1, HEAP_ID_79);
            SlotsMinigame_SoundSequence_StartChange(v1, UnkEnum_ov101_021D1894_00);
        }
        break;
    case 2:
		LOG("%s state=%u", __func__, *slotsMinigameDTO);
        if (IsScreenFadeDone() == FALSE) {
            break;
        }
        (*slotsMinigameDTO)++;
    case 3:
		LOG("%s state=%u", __func__, *slotsMinigameDTO);
        if (SlotsMinigame_SoundSequence_GetIsChangeActive(v1) == 0) {
            return 1; //Quit
        }
    }

    OverworldAnimManagerList_Render(v1->unk_44C);
    ov101_021D80D4(v1->unk_450);
	//LOG("%s: returned 0", __func__);
	RET_LOG1(0);
    return 0; //0 KeepPlaying, 1 Quit
}

// Formerly SlotsMinigame_Exit.
int SlotsMinigame_Exit(ApplicationManager *appMan, int *slotsMinigameDTO)
{
	LOG("%s: appMan=%u *slotsMinigameDTO=%u", __func__, appMan, *slotsMinigameDTO);
    SlotsMinigame_ApplicationData *v0 = ApplicationManager_Data(appMan);
    Overlay101State *v1 = v0->overlayState;

    SetVBlankCallback(NULL, NULL);

    SlotsMinigame_UpdateRecords(v0, v1);

    SlotsMinigame_FreeAnimationManager(v1);
    SlotsMinigame_FreeGraphics(v1);
    SlotsMinigame_FreeWindow(v1);

    ov101_021D1A4C(v1);
    SlotsMinigame_StopSoundTask(v1);

    SlotsMinigame_FreeArchive(v1);
    SlotsMinigame_FreeOverlayState(v1);

    ApplicationManager_FreeData(appMan);
    Heap_Destroy(HEAP_ID_79);
	LOG("%s: returned 1", __func__);
    return 1;
}

static void SlotsMinigame_UpdateRecords(SlotsMinigame_ApplicationData *param0, Overlay101State *slotsMinigameDTO)
{
	LOG("%s: param0=%u slotsMinigameDTO=%u", __func__, param0, slotsMinigameDTO);
    u32 v0 = slotsMinigameDTO->unk_60; //Coins

    if (v0 > 50000) {
        v0 = 50000;
    }

    (*param0->slotMachineDTO->coinsPointer) = v0;
    param0->slotMachineDTO->bonusRounds = slotsMinigameDTO->unk_20;

    if (param0->slotMachineDTO->records != NULL) {
        GameRecords_AddToRecordValue(param0->slotMachineDTO->records, RECORD_UNK_014, slotsMinigameDTO->slotsMinigameDTO);
    }
	LOG("%s: returned ", __func__);
}

static Overlay101State *SlotsMinigame_CreateOverlayState(SlotsMinigameDTO *param0) //SlotsMinigame_CreateOverlayState
{
	LOG("%s: param0=%u", __func__, param0);
    Overlay101State *v0 = SlotsMinigame_AllocateMemory(sizeof(Overlay101State));

    v0->unk_60 = *(param0->coinsPointer);
    v0->unk_88 = param0->slotMachineVariant;
    v0->msgBoxFrame = param0->msgBoxFrame;

	LOG("%s: returned v0", __func__);
    return v0;
}

static void SlotsMinigame_FreeOverlayState(Overlay101State *param0) //SlotsMinigame_FreeOverlayState
{
	LOG("%s: param0=%u", __func__, param0);
    Heap_Free(param0);
	LOG("%s: returned ", __func__);
}

static void SlotsMinigame_SetVBlankCallback(Overlay101State *param0) //SlotsMinigame_Graphics_Create
{
	LOG("%s: param0=%u", __func__, param0);
    param0->unk_43C = BgConfig_New(HEAP_ID_79);

    SlotsMinigame_SetBanks();
    SlotsMinigame_ConfigBackground(param0->unk_43C);
    SlotsMinigame_InitWindow();

    GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG0, 1);
    GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG1, 1);
    GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG2, 1);
    GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG3, 0);
    GXLayers_EngineAToggleLayers(GX_PLANEMASK_OBJ, 1);
    GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0, 0);
    GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG1, 0);
    GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG2, 0);
    GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG3, 1);
    GXLayers_EngineBToggleLayers(GX_PLANEMASK_OBJ, 1);

    G2_SetBG0Priority(0);
    G2_SetBG1Priority(1);
    G2_SetBG2Priority(2);
    G2_SetBG3Priority(3);
    G2S_SetBG0Priority(0);
    G2S_SetBG1Priority(1);
    G2S_SetBG2Priority(2);
    G2S_SetBG3Priority(3);
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_BG2, GX_BLEND_PLANEMASK_OBJ, 8, 9);

    SetVBlankCallback(SlotsMinigame_Render, param0);
	LOG("%s: returned ", __func__);
}

static void SlotsMinigame_FreeGraphics(Overlay101State *param0)
{
	LOG("%s received param0=%u", __func__, param0);
    SlotsMinigame_FreeBackground(param0->unk_43C);
    SlotsMinigame_FreeRenderer(param0);
    SlotsMinigame_FreeCharacter();
	RET_LOG0();
}

static void SlotsMinigame_SetBanks(void) //SlotsMinigame_SetBanks
{
	REC_LOG0();
    GXBanks v0 = {
        GX_VRAM_BG_128_A,
        GX_VRAM_BGEXTPLTT_NONE,
        GX_VRAM_SUB_BG_128_C,
        GX_VRAM_SUB_BGEXTPLTT_NONE,
        GX_VRAM_OBJ_128_B,
        GX_VRAM_OBJEXTPLTT_NONE,
        GX_VRAM_SUB_OBJ_16_I,
        GX_VRAM_SUB_OBJEXTPLTT_NONE,
        GX_VRAM_TEX_NONE,
        GX_VRAM_TEXPLTT_NONE
    };

    GXLayers_SetBanks(&v0);
	RET_LOG0();
}

static void SlotsMinigame_ConfigBackground(BgConfig *param0) //SlotsMinigame_Background_Config
{
	REC_LOG1(param0);
    GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB);

    {
        GraphicsModes v0 = {
            GX_DISPMODE_GRAPHICS,
            GX_BGMODE_0,
            GX_BGMODE_0,
            GX_BG0_AS_2D,
        };

        SetAllGraphicsModes(&v0);
    }

    {
        BgTemplate v1 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .screenSize = BG_SCREEN_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x0000,
            .charBase = GX_BG_CHARBASE_0x04000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = 0,
            .mosaic = FALSE,
        };

        Bg_InitFromTemplate(param0, BG_LAYER_MAIN_0, &v1, 0);
        Bg_ClearTilemap(param0, BG_LAYER_MAIN_0);
        Bg_ClearTilesRange(BG_LAYER_MAIN_0, 32, 0, HEAP_ID_79);
    }

    {
        BgTemplate v2 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .screenSize = BG_SCREEN_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x0800,
            .charBase = GX_BG_CHARBASE_0x0c000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 1,
            .areaOver = 0,
            .mosaic = FALSE,
        };

        Bg_InitFromTemplate(param0, BG_LAYER_MAIN_1, &v2, 0);
        Bg_ClearTilemap(param0, BG_LAYER_MAIN_1);
    }

    {
        BgTemplate v3 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .screenSize = BG_SCREEN_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x1000,
            .charBase = GX_BG_CHARBASE_0x14000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 2,
            .areaOver = 0,
            .mosaic = FALSE,
        };

        Bg_InitFromTemplate(param0, BG_LAYER_MAIN_2, &v3, 0);
        Bg_ClearTilemap(param0, BG_LAYER_MAIN_2);
    }

    {
        BgTemplate v4 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .screenSize = BG_SCREEN_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x1800,
            .charBase = GX_BG_CHARBASE_0x20000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 3,
            .areaOver = 0,
            .mosaic = FALSE,
        };

        Bg_InitFromTemplate(param0, BG_LAYER_SUB_3, &v4, 0);
        Bg_ClearTilemap(param0, BG_LAYER_SUB_3);
    }
	RET_LOG0();
}

static void SlotsMinigame_FreeBackground(BgConfig *param0) //SlotsMinigame_Background_Free
{
	REC_LOG1(param0);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_MAIN_0);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_MAIN_1);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_MAIN_2);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_SUB_3);
    Heap_Free(param0);
	RET_LOG0();
}

static void SlotsMinigame_InitWindow(void)
{
	REC_LOG0();
    GX_SetVisibleWnd(GX_WNDMASK_W0);
    G2_SetWnd0InsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, 1);
    G2_SetWndOutsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, 1);
    G2_SetWnd0Position(0, 0, 255, 255);
	RET_LOG0();
}

static void SlotsMinigame_LoadGraphics(Overlay101State *param0)
{
	REC_LOG1(param0);
    void *v0 = SlotsMinigame_CopyArchive(param0, 3, 0);

    NNS_G2dGetUnpackedPaletteData(v0, &param0->unk_448);
    Bg_LoadPalette(BG_LAYER_MAIN_1, param0->unk_448->pRawData, PALETTE_SIZE_BYTES * 13, 32 * 0);
    Heap_Free(v0);

    v0 = SlotsMinigame_CopyArchive(param0, 0, 0);
    NNS_G2dGetUnpackedCharacterData(v0, &param0->unk_444);
    Bg_LoadTiles(param0->unk_43C, 1, param0->unk_444->pRawData, param0->unk_444->szByte, 32 * 0);
    Heap_Free(v0);

    v0 = SlotsMinigame_CopyArchive(param0, 1, 0);
    NNS_G2dGetUnpackedScreenData(v0, &param0->unk_440);
    Bg_LoadTilemapBuffer(param0->unk_43C, 1, (void *)param0->unk_440->rawData, param0->unk_440->szByte);
    Bg_CopyTilemapBufferToVRAM(param0->unk_43C, 1);
    Heap_Free(v0);

    v0 = SlotsMinigame_CopyArchive(param0, 8, 0);
    NNS_G2dGetUnpackedCharacterData(v0, &param0->unk_444);
    Bg_LoadTiles(param0->unk_43C, 2, param0->unk_444->pRawData, param0->unk_444->szByte, 32 * 0);
    Heap_Free(v0);

    v0 = SlotsMinigame_CopyArchive(param0, 9, 0);
    NNS_G2dGetUnpackedScreenData(v0, &param0->unk_440);
    Bg_LoadTilemapBuffer(param0->unk_43C, 2, (void *)param0->unk_440->rawData, param0->unk_440->szByte);
    Bg_CopyTilemapBufferToVRAM(param0->unk_43C, 2);
    Heap_Free(v0);

    v0 = SlotsMinigame_CopyArchive(param0, 3, 0);
    NNS_G2dGetUnpackedPaletteData(v0, &param0->unk_448);
    Bg_LoadPalette(BG_LAYER_SUB_3, param0->unk_448->pRawData, PALETTE_SIZE_BYTES * 13, 32 * 0);
    Heap_Free(v0);

    v0 = SlotsMinigame_CopyArchive(param0, 2, 0);
    NNS_G2dGetUnpackedCharacterData(v0, &param0->unk_444);
    Bg_LoadTiles(param0->unk_43C, 7, param0->unk_444->pRawData, param0->unk_444->szByte, 0);
    Heap_Free(v0);

    v0 = SlotsMinigame_CopyArchive(param0, 4, 0);
    NNS_G2dGetUnpackedScreenData(v0, &param0->unk_440);
    Bg_LoadTilemapBuffer(param0->unk_43C, 7, (void *)param0->unk_440->rawData, param0->unk_440->szByte);
    Bg_CopyTilemapBufferToVRAM(param0->unk_43C, 7);
    Heap_Free(v0);
	RET_LOG0();
}

void SlotsMinigame_LoadWindow(Overlay101State *param0)
{
	REC_LOG1(param0);
    int v0;
    UnkStruct_ov101_021D148C *v1 = &param0->unk_408;

    LoadStandardWindowGraphics(param0->unk_43C, BG_LAYER_MAIN_0, 1, 15, 0, HEAP_ID_79);
    LoadMessageBoxGraphics(param0->unk_43C, BG_LAYER_MAIN_0, 1 + (18 + 12), 14, param0->msgBoxFrame, HEAP_ID_79);
    Font_LoadScreenIndicatorsPalette(PAL_LOAD_MAIN_BG, PLTT_OFFSET(15), HEAP_ID_79);

    v1->coins = MessageLoader_Init(MSG_LOADER_PRELOAD_ENTIRE_BANK, NARC_INDEX_MSGDATA__PL_MSG, TEXT_BANK_UNK_0544, HEAP_ID_79);
    v1->slotMachineVariant = StringTemplate_Default(HEAP_ID_79);

    for (v0 = 0; v0 < 1; v0++) {
        Window_AddFromTemplate(param0->unk_43C, &v1->unk_08[v0], &Unk_ov101_021D8588[v0]);
    }

    v1->unk_18 = String_Init(256, HEAP_ID_79);
	RET_LOG0();
}

void SlotsMinigame_FreeWindow(Overlay101State *param0)
{
	REC_LOG1(param0);
    int v0;
    UnkStruct_ov101_021D148C *v1 = &param0->unk_408;

    for (v0 = 0; v0 < 1; v0++) {
        Window_ClearAndCopyToVRAM(&v1->unk_08[v0]);
        Window_Remove(&v1->unk_08[v0]);
    }

    MessageLoader_Free(v1->coins);
    StringTemplate_Free(v1->slotMachineVariant);
    String_Free(v1->unk_18);
	RET_LOG0();
}

void SlotsMinigame_DrawMessageBox(Overlay101State *param0, u32 slotsMinigameDTO)
{
	REC_LOG2(param0,slotsMinigameDTO);
    UnkStruct_ov101_021D148C *v0 = &param0->unk_408;

    Window_DrawMessageBoxWithScrollCursor(&v0->unk_08[0], 1, 1 + (18 + 12), 14);
    Window_FillTilemap(&v0->unk_08[0], 15);
    MessageLoader_GetString(v0->coins, slotsMinigameDTO, v0->unk_18);
    Text_AddPrinterWithParams(&v0->unk_08[0], FONT_MESSAGE, v0->unk_18, 0, 0, TEXT_SPEED_NO_TRANSFER, NULL);
    Window_ScheduleCopyToVRAM(&v0->unk_08[0]);
	RET_LOG0();
}

void SlotsMinigame_FreeMessageBox(Overlay101State *param0)
{
	REC_LOG1(param0);
    UnkStruct_ov101_021D148C *v0 = &param0->unk_408;

    Window_EraseMessageBox(&v0->unk_08[0], 1);
    Window_FillTilemap(&v0->unk_08[0], 0);
    Window_ScheduleCopyToVRAM(&v0->unk_08[0]);
	RET_LOG0();
}

static void SlotsMinigame_InitCharacter(void)
{
	REC_LOG0();
    CharTransferTemplate v0 = {
        32, 0x4000, 0x4000, 79
    };

    CharTransfer_InitWithVramModes(&v0, GX_OBJVRAMMODE_CHAR_1D_128K, GX_OBJVRAMMODE_CHAR_1D_128K);
    PlttTransfer_Init(16, HEAP_ID_79);
    CharTransfer_ClearBuffers();
    PlttTransfer_Clear();
	RET_LOG0();
}

static void SlotsMinigame_FreeCharacter(void)
{
	REC_LOG0();
    CharTransfer_Free();
    PlttTransfer_Free();
	RET_LOG0();
}

static void SlotsMinigame_InitRenderer(Overlay101State *param0)
{
	REC_LOG1(param0);
    NNS_G2dInitOamManagerModule();

    RenderOam_Init(0, 128, 0, 32, 0, 128, 0, 32, 79);
    param0->unk_450 = ov101_021D7E48(HEAP_ID_79, 64, 32, 64, 16, 64, 32, 11, 8, 11, 11);
    SlotsMinigame_CopyGraphicsData(param0);
	RET_LOG0();
}

static void SlotsMinigame_FreeRenderer(Overlay101State *param0)
{
	REC_LOG1(param0);
    SlotsMinigame_Noop(param0);
    ov101_021D7FB4(param0->unk_450);
    RenderOam_Free();
	RET_LOG0();
}

static void SlotsMinigame_CopyGraphicsData(Overlay101State *param0)
{
	REC_LOG1(param0);
    ov101_021D80E4(param0->unk_450, NNS_G2D_VRAM_TYPE_2DMAIN, param0->unk_438, 11, 0);
    ov101_021D80E4(param0->unk_450, NNS_G2D_VRAM_TYPE_2DMAIN, param0->unk_438, 21, 1);
    ov101_021D80E4(param0->unk_450, NNS_G2D_VRAM_TYPE_2DSUB, param0->unk_438, 68, 6);
    ov101_021D80E4(param0->unk_450, NNS_G2D_VRAM_TYPE_2DSUB, param0->unk_438, 71, 7);
    ov101_021D80E4(param0->unk_450, NNS_G2D_VRAM_TYPE_2DSUB, param0->unk_438, 64, 8);
    ov101_021D80E4(param0->unk_450, NNS_G2D_VRAM_TYPE_2DSUB, param0->unk_438, 60, 9);

    ov101_021D81B4(param0->unk_450, NNS_G2D_VRAM_TYPE_2DBOTH, param0->unk_438, 10, 0);
    ov101_021D81B4(param0->unk_450, NNS_G2D_VRAM_TYPE_2DMAIN, param0->unk_438, 20, 1);
    ov101_021D81B4(param0->unk_450, NNS_G2D_VRAM_TYPE_2DSUB, param0->unk_438, 67, 6);
    ov101_021D81B4(param0->unk_450, NNS_G2D_VRAM_TYPE_2DSUB, param0->unk_438, 63, 7);

    ov101_021D8288(param0->unk_450, param0->unk_438, 12, 0);
    ov101_021D8288(param0->unk_450, param0->unk_438, 22, 1);
    ov101_021D8288(param0->unk_450, param0->unk_438, 69, 6);
    ov101_021D8288(param0->unk_450, param0->unk_438, 72, 7);
    ov101_021D8288(param0->unk_450, param0->unk_438, 65, 8);
    ov101_021D8288(param0->unk_450, param0->unk_438, 61, 9);

    ov101_021D82F0(param0->unk_450, param0->unk_438, 13, 0);
    ov101_021D82F0(param0->unk_450, param0->unk_438, 23, 1);
    ov101_021D82F0(param0->unk_450, param0->unk_438, 70, 6);
    ov101_021D82F0(param0->unk_450, param0->unk_438, 73, 7);
    ov101_021D82F0(param0->unk_450, param0->unk_438, 66, 8);
    ov101_021D82F0(param0->unk_450, param0->unk_438, 62, 9);

    ov101_021D814C(param0->unk_450, 0);
    ov101_021D814C(param0->unk_450, 1);
    ov101_021D814C(param0->unk_450, 6);
    ov101_021D814C(param0->unk_450, 7);
    ov101_021D814C(param0->unk_450, 8);
    ov101_021D814C(param0->unk_450, 9);
    ov101_021D8180(param0->unk_450, 0);
    ov101_021D8180(param0->unk_450, 1);
    ov101_021D8180(param0->unk_450, 6);
    ov101_021D8180(param0->unk_450, 7);
    ov101_021D8180(param0->unk_450, 8);
    ov101_021D8180(param0->unk_450, 9);

    ov101_021D8220(param0->unk_450, 0);
    ov101_021D8220(param0->unk_450, 1);
    ov101_021D8220(param0->unk_450, 6);
    ov101_021D8220(param0->unk_450, 7);
    ov101_021D8254(param0->unk_450, 0);
    ov101_021D8254(param0->unk_450, 1);
    ov101_021D8254(param0->unk_450, 6);
    ov101_021D8254(param0->unk_450, 7);
	RET_LOG0();
}

static void SlotsMinigame_Noop(Overlay101State *param0)
{
	REC_LOG1(param0);
	RET_LOG0();
    return;
}

static void SlotsMinigame_InitAnimationManager(Overlay101State *param0)
{
	REC_LOG1(param0);
    param0->unk_44C = OverworldAnimManagerList_New(HEAP_ID_79, 128);
	RET_LOG0();
}

static void SlotsMinigame_FreeAnimationManager(Overlay101State *param0)
{
	REC_LOG1(param0);
    OverworldAnimManagerList_FinishAndFree(param0->unk_44C);
	RET_LOG0();
}

void SlotsMinigame_SoundSequence_StartChange(Overlay101State *param0, SlotsMinigame_SoundSequenceID slotsMinigameDTO)
{ //SlotsMinigame_StartSoundSequenceFadeOut
	REC_LOG2(param0,slotsMinigameDTO);
    SlotsMinigame_SoundSequenceController *v0 = &param0->unk_424;

    if ((v0->unk_08 == slotsMinigameDTO) || (v0->slotsMinigameDTO == slotsMinigameDTO)) {
		//No sequence change needed.
		RET_LOG1(1);
        return;
    }

    v0->slotsMinigameDTO = slotsMinigameDTO;
    v0->coins = 1;
    v0->slotMachineVariant = 1;
	RET_LOG1(0);
}

static int SlotsMinigame_SoundSequence_GetIsChangeActive(Overlay101State *param0)
{ //SlotsMinigame_SoundSequence_GetIsChangeActive
	REC_LOG1(param0);
    SlotsMinigame_SoundSequenceController *v0 = &param0->unk_424;
	RET_LOG1(v0->slotMachineVariant);
    return v0->slotMachineVariant;
}

static void SlotsMinigame_StartSoundTask(Overlay101State *param0)
{
	REC_LOG1(param0);
    SlotsMinigame_SoundSequenceController *v0 = &param0->unk_424;

    v0->unk_08 = UnkEnum_ov101_021D1894_00;
    v0->slotsMinigameDTO = UnkEnum_ov101_021D1894_03;
    v0->unk_10 = SysTask_Start(SlotsMinigame_ProcessSound_TaskCallback, param0, 144);
	RET_LOG0();
}

static void SlotsMinigame_StopSoundTask(Overlay101State *param0)
{
	REC_LOG1(param0);
    SysTask_Done(param0->unk_424.unk_10);
	RET_LOG0();
}

static void SlotsMinigame_ProcessSound_TaskCallback(SysTask *param0, void *slotsMinigameDTO)
{
	//REC_LOG1(param0);
    Overlay101State *v0 = slotsMinigameDTO;
    SlotsMinigame_SoundSequenceController *v1 = &v0->unk_424;

    switch (v1->coins) {
    case 0:
        break;
    case 1:
        switch (v1->unk_08) {
        case UnkEnum_ov101_021D1894_00:
            Sound_SetBGMPlayerPaused(PLAYER_FIELD, TRUE);
            break;
        case UnkEnum_ov101_021D1894_01:
            Sound_StopBGM(SEQ_SLOT_ATARI_sseq, 0);
            break;
        case UnkEnum_ov101_021D1894_02:
            Sound_StopBGM(SEQ_SLOT_OOATARI_sseq, 0);
            break;
        }

        v1->coins++;
        break;
    case 2:
        switch (v1->slotsMinigameDTO) {
        case UnkEnum_ov101_021D1894_00:
            Sound_SetBGMPlayerPaused(PLAYER_FIELD, FALSE);
            break;
        case UnkEnum_ov101_021D1894_01:
            Sound_PlayBasicBGM(SEQ_SLOT_ATARI_sseq);
            break;
        case UnkEnum_ov101_021D1894_02:
            Sound_PlayBasicBGM(SEQ_SLOT_OOATARI_sseq);
            break;
        }

        v1->unk_08 = v1->slotsMinigameDTO;
        v1->slotsMinigameDTO = UnkEnum_ov101_021D1894_03;
        v1->slotMachineVariant = 0;
        v1->coins = 0;
    }
	//RET_LOG0();
}

static void SlotsMinigame_Render(void *param0)
{
	//REC_LOG1(param0);
    Overlay101State *v0 = param0;

    VramTransfer_Process();
    RenderOam_Transfer();
    Bg_RunScheduledUpdates(v0->unk_43C);
	//RET_LOG0();
}

void *SlotsMinigame_AllocateMemory(u32 param0)
{
	REC_LOG1(param0);
    void *v0 = Heap_Alloc(HEAP_ID_79, param0);

    GF_ASSERT(v0 != NULL);
    memset(v0, 0, param0);

	RET_LOG0();
    return v0;
}

static void SlotsMinigame_LoadArchive(Overlay101State *param0)
{
	REC_LOG1(param0);
    param0->unk_438 = NARC_ctor(NARC_INDEX_DATA__SLOT, HEAP_ID_79);
	RET_LOG0();
}

static void SlotsMinigame_FreeArchive(Overlay101State *param0)
{
	REC_LOG1(param0);
    NARC_dtor(param0->unk_438);
	RET_LOG0();
}

void *SlotsMinigame_CopyArchive(Overlay101State *param0, u32 slotsMinigameDTO, int param2)
{
	REC_LOG2(slotsMinigameDTO,param2);
    void *v0;
    u32 v1 = NARC_GetMemberSize(param0->unk_438, slotsMinigameDTO);

    if (param2 == 1) {
        v0 = Heap_Alloc(HEAP_ID_79, v1);
    } else {
        v0 = Heap_AllocAtEnd(HEAP_ID_79, v1);
    }

    GF_ASSERT(v0 != NULL);
    NARC_ReadWholeMember(param0->unk_438, slotsMinigameDTO, v0);

	RET_LOG0();
    return v0;
}

static const WindowTemplate Unk_ov101_021D8588[1] = {
    { 0x0, 0x2, 0x13, 0x1A, 0x4, 0xF, 0x3D }
};
