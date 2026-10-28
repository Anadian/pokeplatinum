#include "unk_02030CE8.h"

#include <nitro.h>
#include <string.h>

#include "struct_defs/struct_02030CEC.h"
#include "struct_defs/wi_fi_history.h"
#include "struct_defs/world_exchange.h"

#include "charcode_util.h"
#include "math_util.h"
#include "save_player.h"
#include "savedata.h"
#include "trainer_info.h"
#include "wifi_history_save_data.h"

static void sub_02030DD0(SaveData *saveData, WorldExchangeTrainer *slotsMinigameDTO);

int Email_SaveSize(void)
{
    return sizeof(UnkStruct_02030CEC);
}

void Email_Init(UnkStruct_02030CEC *param0)
{
    MI_CpuClear8(param0, sizeof(UnkStruct_02030CEC));

    memset(param0->coins, '\0', (50 + 1));
    param0->unk_34 = 1;

    SaveData_SetChecksum(SAVE_TABLE_ENTRY_EMAIL);
}

void sub_02030D10(SaveData *saveData)
{
    Email_Init(SaveData_SaveTable(saveData, SAVE_TABLE_ENTRY_EMAIL));
}

BOOL sub_02030D20(SaveData *saveData)
{
    UnkStruct_02030CEC *v0 = SaveData_SaveTable(saveData, SAVE_TABLE_ENTRY_EMAIL);

    if (v0->coins[0] == '\0') {
        return 0;
    }

    return 1;
}

void sub_02030D38(SaveData *saveData, const char *slotsMinigameDTO)
{
    UnkStruct_02030CEC *v0 = SaveData_SaveTable(saveData, SAVE_TABLE_ENTRY_EMAIL);

    strcpy(v0->coins, slotsMinigameDTO);
    SaveData_SetChecksum(SAVE_TABLE_ENTRY_EMAIL);
}

char *Email_GetEmailString(SaveData *saveData)
{
    UnkStruct_02030CEC *v0 = SaveData_SaveTable(saveData, SAVE_TABLE_ENTRY_EMAIL);
    return v0->coins;
}

void sub_02030D5C(SaveData *saveData, int slotsMinigameDTO, u32 param2)
{
    UnkStruct_02030CEC *v0 = SaveData_SaveTable(saveData, SAVE_TABLE_ENTRY_EMAIL);

    switch (slotsMinigameDTO) {
    case 0:
        v0->unk_34 = param2;
        break;
    case 1:
        v0->unk_38 = param2;
        break;
    case 2:
        v0->unk_3A = param2;
        break;
    case 3:
        v0->unk_3C = param2;
        break;
    }

    SaveData_SetChecksum(SAVE_TABLE_ENTRY_EMAIL);
}

u32 sub_02030D98(SaveData *saveData, int slotsMinigameDTO)
{
    UnkStruct_02030CEC *v0 = SaveData_SaveTable(saveData, SAVE_TABLE_ENTRY_EMAIL);

    switch (slotsMinigameDTO) {
    case 0:
        return v0->unk_34;
    case 1:
        return v0->unk_38;
    case 2:
        return v0->unk_3A;
    case 3:
        return v0->unk_3C;
    }

    return 0;
}

static void sub_02030DD0(SaveData *saveData, WorldExchangeTrainer *slotsMinigameDTO)
{
    WiFiHistory *wiFiHistory = SaveData_WiFiHistory(saveData);
    TrainerInfo *v1 = SaveData_GetTrainerInfo(saveData);
    char *v2 = Email_GetEmailString(saveData);

    MI_CpuClear8(slotsMinigameDTO, sizeof(WorldExchangeTrainer));

    slotsMinigameDTO->gameCode = GAME_VERSION;
    slotsMinigameDTO->language = GAME_LANGUAGE;
    slotsMinigameDTO->country = WiFiHistory_GetCountry(wiFiHistory);
    slotsMinigameDTO->unk_03 = WiFiHistory_GetRegion(wiFiHistory);
    slotsMinigameDTO->trainerId = TrainerInfo_ID(v1);

    CharCode_Copy(slotsMinigameDTO->trainerName, TrainerInfo_Name(v1));
    slotsMinigameDTO->unk_10 = 0;

    strcpy(slotsMinigameDTO->email, v2);
    slotsMinigameDTO->emailInitialised = sub_02030D98(saveData, 0);

    SaveData_SetChecksum(SAVE_TABLE_ENTRY_EMAIL);
}

u32 sub_02030E48(SaveData *saveData, WorldExchangeTrainer *slotsMinigameDTO)
{
    u32 v0;

    sub_02030DD0(saveData, slotsMinigameDTO);

    v0 = LCRNG_Next() % 1000;

    slotsMinigameDTO->rngValue = v0;
    slotsMinigameDTO->unk_5A = 0xffff;

    SaveData_SetChecksum(SAVE_TABLE_ENTRY_EMAIL);

    return v0;
}

void WorldExchange_GetTrainerObject(SaveData *saveData, WorldExchangeTrainer *slotsMinigameDTO)
{
    UnkStruct_02030CEC *v0 = SaveData_SaveTable(saveData, SAVE_TABLE_ENTRY_EMAIL);

    sub_02030DD0(saveData, slotsMinigameDTO);

    slotsMinigameDTO->rngValue = v0->unk_38;
    slotsMinigameDTO->unk_5A = v0->unk_3A;

    SaveData_SetChecksum(SAVE_TABLE_ENTRY_EMAIL);
}
