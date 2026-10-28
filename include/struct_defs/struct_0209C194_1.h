#ifndef POKEPLATINUM_STRUCT_0209C194_1_H
#define POKEPLATINUM_STRUCT_0209C194_1_H

#include "struct_decls/struct_0205C22C_decl.h"

#include "field/field_system_decl.h"

#include "game_options.h"
#include "game_records.h"
#include "journal.h"
#include "savedata.h"

typedef struct {
    int coins;
    int slotMachineVariant;
    SaveData *saveData;
    UnkStruct_0205C22C *slotsMinigameDTO;
    Options *options;
    GameRecords *records;
    JournalEntry *journalEntry;
    FieldSystem *fieldSystem;
} UnkStruct_0209C194_1;

#endif // POKEPLATINUM_STRUCT_0209C194_1_H
