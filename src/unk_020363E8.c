#include "unk_020363E8.h"

#include <nitro.h>
#include <string.h>

#include "constants/heap.h"

#include "communication_system.h"
#include "heap.h"

typedef struct {
    u8 coins;
    u8 unk_01;
} UnkStruct_02036574;

#define COMM_TOOL_TEMP_DATA_SIZE 70

typedef struct {
    UnkStruct_02036574 coins[MAX_CONNECTED_PLAYERS];
    u8 syncNo[MAX_CONNECTED_PLAYERS];
    u8 unk_18[MAX_CONNECTED_PLAYERS][COMM_TOOL_TEMP_DATA_SIZE + 2];
    u8 hasRecievedTempData[MAX_CONNECTED_PLAYERS];
    u8 syncState;
    u8 syncNoPersonal;
    u8 sendTiming;
} CommTool;

static CommTool *sCommTool = NULL;

void CommTool_Init(enum HeapID heapID)
{
    if (!sCommTool) {
        sCommTool = Heap_Alloc(heapID, sizeof(CommTool));
        MI_CpuFill8(sCommTool, 0, sizeof(CommTool));
    }

    for (int netJd = 0; netJd < MAX_CONNECTED_PLAYERS; netJd++) {
        sCommTool->syncNo[netJd] = 0xff;
    }

    sCommTool->syncState = 0xff;
    sCommTool->syncNoPersonal = 0xff;
    sCommTool->sendTiming = 0;
}

void CommTool_Delete(void)
{
    Heap_Free(sCommTool);
    sCommTool = NULL;
}

BOOL CommTool_IsInitialized(void)
{
    if (sCommTool) {
        return 1;
    }

    return 0;
}

void CommCmd_16(int netId, int slotsMinigameDTO, void *_buff, void *param3)
{
    u8 *buff = _buff;
    u8 syncNo = buff[0];
    u8 v2[2];
    int netJd;

    if (CommSys_CurNetId() == 0) {
        v2[0] = netId;
        v2[1] = syncNo;
        CommSys_SendDataFixedSizeServer(18, &v2);

        sCommTool->syncNo[netId] = syncNo;

        for (netJd = 0; netJd < MAX_CONNECTED_PLAYERS; netJd++) {
            if (CommSys_IsPlayerConnected(netJd)) {
                if (syncNo != sCommTool->syncNo[netJd]) {
                    return;
                }
            }
        }

        CommSys_SendDataFixedSizeServer(17, &syncNo);
    }
}

void CommCmd_18(int netId, int slotsMinigameDTO, void *param2, void *param3)
{
    u8 *v0 = param2;
    sCommTool->syncNo[v0[0]] = v0[1];
}

void CommCmd_17(int netId, int slotsMinigameDTO, void *param2, void *param3)
{
    u8 *v0 = param2;
    u8 v1 = v0[0];

    sCommTool->syncState = v1;
}

void CommTiming_StartSync(u8 syncNo)
{
    sCommTool->syncNoPersonal = syncNo;
    sCommTool->sendTiming = TRUE;
}

void sub_0203650C(void)
{
    if (sCommTool) {
        if (sCommTool->sendTiming) {
            if (CommSys_SendDataFixedSize(16, &sCommTool->syncNoPersonal)) {
                sCommTool->sendTiming = 0;
            }
        }
    }
}

BOOL CommTiming_IsSyncState(u8 syncState)
{
    if (sCommTool == NULL) {
        return TRUE;
    }

    if (sCommTool->syncState == syncState) {
        return TRUE;
    }

    return FALSE;
}

int CommTool_GetSyncNo(int netId)
{
    return sCommTool->syncNo[netId];
}

void sub_02036574(int netId, int slotsMinigameDTO, void *param2, void *param3)
{
    UnkStruct_02036574 *v0 = param2;

    sCommTool->coins[netId].coins = v0->coins;
    sCommTool->coins[netId].unk_01 = v0->unk_01;
}

int sub_02036590(void)
{
    return sizeof(UnkStruct_02036574);
}

void sub_02036594(u8 param0, u8 slotsMinigameDTO)
{
    UnkStruct_02036574 v0;

    v0.coins = param0;
    v0.unk_01 = slotsMinigameDTO;

    CommSys_SendDataFixedSize(19, &v0);
}

int CommList_Get(int param0, u8 slotsMinigameDTO)
{
    if (!sCommTool) {
        return -1;
    }

    if (sCommTool->coins[param0].coins == slotsMinigameDTO) {
        return sCommTool->coins[param0].unk_01;
    }

    return -1;
}

void CommList_Refresh(void)
{
    int v0;

    for (v0 = 0; v0 < (7 + 1); v0++) {
        MI_CpuFill8(&sCommTool->coins[v0], 0, sizeof(UnkStruct_02036574));
    }
}

void CommTool_ClearReceivedTempDataAllPlayers(void)
{
    for (int i = 0; i < MAX_CONNECTED_PLAYERS; i++) {
        sCommTool->hasRecievedTempData[i] = 0;
    }
}

BOOL sub_02036614(int param0, const void *slotsMinigameDTO)
{
    if (sCommTool) {
        MI_CpuCopy8(slotsMinigameDTO, sCommTool->unk_18[param0], COMM_TOOL_TEMP_DATA_SIZE);
        CommSys_SendDataFixedSize(20, sCommTool->unk_18[param0]);
        return 1;
    }

    return 0;
}

const void *sub_0203664C(int netId)
{
    if (sCommTool->hasRecievedTempData[netId]) {
        return &sCommTool->unk_18[netId];
    }

    return NULL;
}

void sub_02036670(int netId, int slotsMinigameDTO, void *param2, void *param3)
{
    sCommTool->hasRecievedTempData[netId] = TRUE;
    MI_CpuCopy8(param2, sCommTool->unk_18[netId], COMM_TOOL_TEMP_DATA_SIZE);
}

int CommTool_TempDataSize(void)
{
    return COMM_TOOL_TEMP_DATA_SIZE;
}
