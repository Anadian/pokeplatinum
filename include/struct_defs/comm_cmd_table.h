#ifndef POKEPLATINUM_STRUCT_DEF_COMM_CMD_TABLE_H
#define POKEPLATINUM_STRUCT_DEF_COMM_CMD_TABLE_H

#include "functypes/funcptr_02032868.h"
#include "functypes/funcptr_0203290C.h"
#include "functypes/funcptr_020F8E60.h"

typedef struct CommCmdTable {
    UnkFuncPtr_020F8E60 coins;
    UnkFuncPtr_02032868 slotMachineVariant;
    UnkFuncPtr_0203290C unk_08;
} CommCmdTable;

#endif // POKEPLATINUM_STRUCT_DEF_COMM_CMD_TABLE_H
