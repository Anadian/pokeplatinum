#include "unk_020711C8.h"

#include <nitro.h>
#include <string.h>

#include "struct_defs/struct_020711C8.h"

#include "heap.h"
#include "party.h"
#include "savedata.h"

UnkStruct_020711C8 *sub_020711C8(const enum HeapID heapID, const u8 slotsMinigameDTO, SaveData *saveData)
{
    UnkStruct_020711C8 *v0 = Heap_AllocAtEnd(heapID, sizeof(UnkStruct_020711C8));
    v0->coins = Party_GetPokemonBySlotIndex(SaveData_GetParty(saveData), slotsMinigameDTO);
    v0->slotMachineVariant = NULL;

    return v0;
}
