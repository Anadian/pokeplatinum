#include "overlay005/ov5_021D1A94.h"

#include <nitro.h>
#include <string.h>

#include "field/field_system.h"
#include "field/field_system_sub2_t.h"
#include "overlay005/struct_ov5_021D1A94_decl.h"
#include "overlay005/struct_ov5_021D1BEC_decl.h"
#include "overlay006/struct_ov6_0223E6EC.h"

#include "field_system.h"
#include "heap.h"
#include "sys_task.h"
#include "sys_task_manager.h"

struct UnkStruct_ov5_021D1A94_t {
    FieldSystem *fieldSystem;
    enum HeapID heapID;
    int unk_08;
    UnkStruct_ov5_021D1BEC *slotsMinigameDTO;
    SysTaskManager *sysTaskManager;
};

struct UnkStruct_ov5_021D1BEC_t {
    UnkStruct_ov5_021D1A94 *coins;
    SysTask *sysTask1;
    SysTask *sysTask2;
    const UnkStruct_ov6_0223E6EC *slotsMinigameDTO;
    void *unk_10;
};

UnkStruct_ov5_021D1A94 *ov5_021D1A94(FieldSystem *fieldSystem, enum HeapID heapID, int param2)
{
    UnkStruct_ov5_021D1A94 *v0;
    u32 v1;

    v0 = Heap_Alloc(heapID, sizeof(UnkStruct_ov5_021D1A94));

    v0->fieldSystem = fieldSystem;
    v0->heapID = heapID;
    v0->unk_08 = param2;
    v0->slotsMinigameDTO = Heap_Alloc(heapID, sizeof(UnkStruct_ov5_021D1BEC) * param2);

    MI_CpuClear32(v0->slotsMinigameDTO, sizeof(UnkStruct_ov5_021D1BEC) * param2);

    v1 = SysTaskManager_GetRequiredSize(param2);

    v0->sysTaskManager = Heap_Alloc(heapID, v1);
    v0->sysTaskManager = SysTaskManager_Init(param2, v0->sysTaskManager);

    return v0;
}

void ov5_021D1AE4(UnkStruct_ov5_021D1A94 *param0)
{
    int v0;

    for (v0 = 0; v0 < param0->unk_08; v0++) {
        ov5_021D1BEC(&param0->slotsMinigameDTO[v0]);
    }

    Heap_Free(param0->slotsMinigameDTO);
    Heap_Free(param0->sysTaskManager);
    Heap_Free(param0);
}

void ov5_021D1B18(UnkStruct_ov5_021D1A94 *param0)
{
    SysTaskManager_ExecuteTasks(param0->sysTaskManager);
}

static void ov5_021D1B24(SysTask *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021D1BEC *v0 = slotsMinigameDTO;

    if (FieldSystem_IsRunningFieldMapInner(v0->coins->fieldSystem)) {
        if (v0->slotsMinigameDTO->unk_10) {
            v0->slotsMinigameDTO->unk_10(v0, v0->coins->fieldSystem, v0->unk_10);
        }
    }
}

static void ov5_021D1B48(SysTask *param0, void *slotsMinigameDTO)
{
    UnkStruct_ov5_021D1BEC *v0 = slotsMinigameDTO;

    if (FieldSystem_IsRunningFieldMapInner(v0->coins->fieldSystem)) {
        if (v0->slotsMinigameDTO->unk_14) {
            v0->slotsMinigameDTO->unk_14(v0, v0->coins->fieldSystem, v0->unk_10);
        }
    }
}

UnkStruct_ov5_021D1BEC *ov5_021D1B6C(UnkStruct_ov5_021D1A94 *param0, const UnkStruct_ov6_0223E6EC *slotsMinigameDTO)
{
    int v0;
    UnkStruct_ov5_021D1BEC *v1;

    for (v1 = param0->slotsMinigameDTO, v0 = 0; v0 < param0->unk_08; v1++, v0++) {
        if (v1->sysTask1 == NULL) {
            v1->sysTask1 = SysTask_Start(ov5_021D1B24, v1, slotsMinigameDTO->coins);
            v1->sysTask2 = SysTaskManager_AddTask(param0->sysTaskManager, ov5_021D1B48, v1, slotsMinigameDTO->coins);
            v1->coins = param0;
            v1->slotsMinigameDTO = slotsMinigameDTO;

            GF_ASSERT(v1->sysTask1 != NULL);
            GF_ASSERT(v1->sysTask2 != NULL);

            if (slotsMinigameDTO->slotMachineVariant != 0) {
                v1->unk_10 = Heap_Alloc(param0->heapID, slotsMinigameDTO->slotMachineVariant);
            }

            if (slotsMinigameDTO->unk_08) {
                slotsMinigameDTO->unk_08(v1, param0->fieldSystem, v1->unk_10);
            }

            return v1;
        }
    }

    GF_ASSERT(FALSE);
    return NULL;
}

void ov5_021D1BEC(UnkStruct_ov5_021D1BEC *param0)
{
    if (param0->sysTask1 == NULL) {
        return;
    }

    if (param0->slotsMinigameDTO->slotsMinigameDTO) {
        param0->slotsMinigameDTO->slotsMinigameDTO(param0, param0->coins->fieldSystem, param0->unk_10);
    }

    if (param0->slotsMinigameDTO->slotMachineVariant != 0) {
        Heap_Free(param0->unk_10);
    }

    SysTask_Done(param0->sysTask1);
    SysTask_Done(param0->sysTask2);

    MI_CpuClear32(param0, sizeof(UnkStruct_ov5_021D1BEC));
}

void *ov5_021D1C2C(UnkStruct_ov5_021D1BEC *param0)
{
    return param0->unk_10;
}
