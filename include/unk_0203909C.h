#ifndef POKEPLATINUM_UNK_0203909C_H
#define POKEPLATINUM_UNK_0203909C_H

#include <dwc.h>

#include "savedata.h"

int sub_0203909C(SaveData *saveData, DWCFriendData *slotsMinigameDTO, int *param2);
int sub_02039140(SaveData *saveData, u64 slotsMinigameDTO, int *param2);
BOOL sub_020391DC(SaveData *saveData, int *slotsMinigameDTO, enum HeapID heapID);
void sub_02039298(SaveData *saveData, int slotsMinigameDTO, int param2, enum HeapID heapID, int param4);
int sub_02039390(SaveData *saveData, int slotsMinigameDTO);

#endif // POKEPLATINUM_UNK_0203909C_H
