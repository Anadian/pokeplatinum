#ifndef POKEPLATINUM_OV62_02248408_H
#define POKEPLATINUM_OV62_02248408_H

#include "struct_defs/battle_recording.h"

#include "field_battle_data_transfer.h"
#include "savedata.h"

void ov62_02248408(BattleRecording *param0, FieldBattleDTO *slotsMinigameDTO, enum HeapID heapID);
int ov62_02248598(SaveData *saveData, int slotsMinigameDTO, u8 param2, u16 *param3, u16 *param4);
void ov62_02248624(SaveData *saveData);
int ov62_02248658(SaveData *saveData, u64 slotsMinigameDTO, u16 *param2, u16 *param3);
int ov62_022486A4(SaveData *saveData, int slotsMinigameDTO);

#endif // POKEPLATINUM_OV62_02248408_H
