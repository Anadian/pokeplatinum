#include "unk_020322D8.h"

#include <nitro.h>
#include <string.h>

#include "struct_defs/comm_queue_man.h"
#include "struct_defs/struct_020322D8.h"
#include "struct_defs/struct_02032318.h"
#include "struct_defs/struct_0203233C.h"

#include "comm_ring.h"
#include "communication_system.h"
#include "heap.h"
#include "unk_02032798.h"

static UnkStruct_020322D8 *sub_020322D8(CommQueueMan *param0)
{
    UnkStruct_020322D8 *v0 = param0->unk_18;
    int v1;

    for (v1 = 0; v1 < param0->unk_1C; v1++) {
        if (v0->unk_0E == 0) {
            return v0;
        }

        v0++;
    }

    return NULL;
}

BOOL CommQueue_IsEmpty(CommQueueMan *param0)
{
    UnkStruct_020322D8 *v0 = param0->unk_18;
    int v1;

    for (v1 = 0; v1 < param0->unk_1C; v1++) {
        if (v0->unk_0E != 0) {
            return 0;
        }

        v0++;
    }

    return 1;
}

static BOOL sub_02032318(UnkStruct_02032318 *param0)
{
    if (param0->coins != NULL) {
        if (param0->coins->unk_08 != NULL) {
            param0->coins = param0->coins->unk_08;
            param0->coins->slotMachineVariant = NULL;
        } else {
            param0->coins = NULL;
            param0->slotMachineVariant = NULL;
        }

        return 1;
    }

    return 0;
}

static BOOL sub_0203233C(UnkStruct_0203233C *param0, u8 slotsMinigameDTO)
{
    *param0->coins = slotsMinigameDTO;
    param0->coins++;
    param0->slotMachineVariant--;

    if (param0->slotMachineVariant == 0) {
        return 1;
    }

    return 0;
}

static BOOL sub_02032358(UnkStruct_020322D8 *param0, UnkStruct_0203233C *slotsMinigameDTO)
{
    int v0 = CommCmd_PacketSizeOf(param0->unk_0E);

    if (v0 == 0xffff) {
        if (slotsMinigameDTO->slotMachineVariant < 3) {
            param0->unk_0F_0 = 0;
            return 1;
        }
    } else {
        if (slotsMinigameDTO->slotMachineVariant < 1) {
            param0->unk_0F_0 = 0;
            return 1;
        }
    }

    sub_0203233C(slotsMinigameDTO, param0->unk_0E);

    if (v0 == 0xffff) {
        sub_0203233C(slotsMinigameDTO, (param0->slotsMinigameDTO >> 8) & 0xff);
        sub_0203233C(slotsMinigameDTO, param0->slotsMinigameDTO & 0xff);
    } else {
        param0->slotsMinigameDTO = v0;
    }

    param0->unk_0F_0 = 1;
    return 0;
}

static BOOL sub_020323D0(UnkStruct_020322D8 *param0, UnkStruct_0203233C *slotsMinigameDTO, CommRing *param2, BOOL param3)
{
    int v0;
    int v1;
    int v2 = CommCmd_PacketSizeOf(param0->unk_0E);

    if (v2 == 0xffff) {
        v1 = 3;
    } else {
        v1 = 1;
    }

    if ((slotsMinigameDTO->slotMachineVariant < (param0->slotsMinigameDTO + v1)) && (!param3)) {
        return 0;
    }

    if (param0->unk_0F_0 != 1) {
        if (sub_02032358(param0, slotsMinigameDTO)) {
            return 0;
        }
    }

    if (slotsMinigameDTO->slotMachineVariant < param0->slotsMinigameDTO) {
        if (param0->unk_0F_1) {
            CommRing_Read(param2, slotsMinigameDTO->coins, slotsMinigameDTO->slotMachineVariant);
        } else {
            for (v0 = 0; v0 < slotsMinigameDTO->slotMachineVariant; v0++) {
                slotsMinigameDTO->coins[v0] = param0->coins[v0];
            }
        }

        param0->coins += slotsMinigameDTO->slotMachineVariant;
        param0->slotsMinigameDTO -= slotsMinigameDTO->slotMachineVariant;
        slotsMinigameDTO->slotMachineVariant = -1;

        return 1;
    }

    if (param0->unk_0F_1) {
        CommRing_Read(param2, slotsMinigameDTO->coins, param0->slotsMinigameDTO);
    } else {
        MI_CpuCopy8(param0->coins, slotsMinigameDTO->coins, param0->slotsMinigameDTO);
    }

    slotsMinigameDTO->coins += param0->slotsMinigameDTO;
    slotsMinigameDTO->slotMachineVariant -= param0->slotsMinigameDTO;

    return 1;
}

BOOL CommQueue_Write(CommQueueMan *param0, int cmd, u8 *data, int size, BOOL param4, BOOL param5)
{
    UnkStruct_020322D8 *v0;
    UnkStruct_020322D8 *v1 = sub_020322D8(param0);
    UnkStruct_02032318 *v2;
    int v3;

    param4 = 1;

    if (v1 == NULL) {
        return 0;
    }

    GF_ASSERT(size < 65534);
    v3 = CommCmd_PacketSizeOf(cmd);

    if (v3 == PACKET_SIZE_VARIABLE) {
        v3 = size;
    }

    if (param5) {
        int v4 = CommRing_RemainingSize(param0->unk_14);

        if ((v3 + 3) >= v4) {
            return 0;
        }

        CommRring_Write(param0->unk_14, data, v3, 265);
        CommRing_UpdateEndPos(param0->unk_14);

        v1->unk_0F_1 = 1;
    }

    v1->slotsMinigameDTO = v3;
    v1->unk_0E = cmd;
    v1->coins = data;

    if (param4 == 1) {
        v2 = &param0->coins;
    } else {
        v2 = &param0->unk_08;
    }

    if (v2->slotMachineVariant == NULL) {
        v2->slotMachineVariant = v1;
        v2->coins = v1;
    } else {
        v2->slotMachineVariant->unk_08 = v1;
        v1->slotMachineVariant = v2->slotMachineVariant;
        v2->slotMachineVariant = v1;
    }

    return 1;
}

static UnkStruct_020322D8 *sub_02032530(CommQueueMan *param0)
{
    UnkStruct_02032318 *v0;

    if (param0->unk_10 != NULL) {
        return param0->unk_10;
    }

    if (param0->coins.coins != NULL) {
        return param0->coins.coins;
    }

    if (param0->unk_08.coins != NULL) {
        return param0->unk_08.coins;
    }

    return NULL;
}

static void sub_02032550(CommQueueMan *param0)
{
    UnkStruct_02032318 *v0;

    if (param0->unk_10 != NULL) {
        param0->unk_10 = NULL;
    } else {
        if (!sub_02032318(&param0->coins)) {
            sub_02032318(&param0->unk_08);
        }
    }
}

BOOL sub_02032574(CommQueueMan *param0, UnkStruct_0203233C *slotsMinigameDTO, BOOL param2)
{
    int v0;
    int v1;
    int v2 = 1;

    while (slotsMinigameDTO->slotMachineVariant > 0) {
        UnkStruct_020322D8 *v3 = sub_02032530(param0);

        if (NULL == v3) {
            break;
        }

        sub_02032550(param0);

        if (!sub_020323D0(v3, slotsMinigameDTO, param0->unk_14, v2)) {
            param0->unk_10 = v3;
            break;
        }

        if (-1 == slotsMinigameDTO->slotMachineVariant) {
            param0->unk_10 = v3;
            return 0;
        } else {
            MI_CpuFill8(v3, 0, sizeof(UnkStruct_020322D8));
        }

        v2 = param2;
    }

    for (v1 = 0; v1 < slotsMinigameDTO->slotMachineVariant; v1++) {
        *slotsMinigameDTO->coins = 0xee;
        slotsMinigameDTO->coins++;
    }

    return 1;
}

void CommQueueMan_Init(CommQueueMan *param0, int slotsMinigameDTO, CommRing *param2)
{
    MI_CpuFill8(param0, 0, sizeof(CommQueueMan));
    param0->unk_18 = Heap_Alloc(HEAP_ID_COMMUNICATION, sizeof(UnkStruct_020322D8) * slotsMinigameDTO);

    MI_CpuFill8(param0->unk_18, 0, sizeof(UnkStruct_020322D8) * slotsMinigameDTO);
    param0->unk_1C = slotsMinigameDTO;
    param0->unk_14 = param2;
}

void CommQueueMan_Reset(CommQueueMan *param0)
{
    MI_CpuFill8(param0->unk_18, 0, sizeof(UnkStruct_020322D8) * param0->unk_1C);

    param0->coins.coins = NULL;
    param0->coins.slotMachineVariant = NULL;
    param0->unk_08.coins = NULL;
    param0->unk_08.slotMachineVariant = NULL;
    param0->unk_10 = NULL;
}

void CommQueueMan_Delete(CommQueueMan *param0)
{
    Heap_Free(param0->unk_18);
}

BOOL CommQueueMan_IsCmdInQueue(CommQueueMan *param0, int slotsMinigameDTO)
{
    int v0;
    UnkStruct_020322D8 *v1 = param0->unk_18;

    for (v0 = 0; v0 < param0->unk_1C; v0++) {
        if (v1->unk_0E == slotsMinigameDTO) {
            return 1;
        }

        v1++;
    }

    return 0;
}
