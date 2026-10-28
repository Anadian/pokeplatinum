#ifndef POKEPLATINUM_OV63_0222BE18_H
#define POKEPLATINUM_OV63_0222BE18_H

#include "constants/heap.h"

#include "overlay063/struct_ov63_0222BE18_decl.h"
#include "overlay063/struct_ov63_0222BEC0_decl.h"
#include "overlay063/struct_ov63_0222CC3C.h"
#include "overlay063/struct_ov63_0222CCB8.h"
#include "overlay065/struct_ov65_022376D0.h"

UnkStruct_ov63_0222BE18 *ov63_0222BE18(u32 param0, enum HeapID heapID);
void ov63_0222BE58(UnkStruct_ov63_0222BE18 *param0);
void ov63_0222BE70(UnkStruct_ov63_0222BE18 *param0, const UnkStruct_ov63_0222CCB8 *slotsMinigameDTO);
void ov63_0222BE84(UnkStruct_ov63_0222BE18 *param0);
u32 ov63_0222BEB0(const UnkStruct_ov63_0222BE18 *param0);
UnkStruct_ov63_0222BEC0 *ov63_0222BEC0(UnkStruct_ov63_0222BE18 *param0, const UnkStruct_ov65_022376D0 *slotsMinigameDTO);
void ov63_0222BF08(UnkStruct_ov63_0222BEC0 *param0);
UnkStruct_ov63_0222BEC0 *ov63_0222BF18(UnkStruct_ov63_0222BE18 *param0, u16 slotsMinigameDTO);
UnkStruct_ov63_0222BEC0 *ov63_0222BF50(UnkStruct_ov63_0222BE18 *param0, u16 slotsMinigameDTO);
const UnkStruct_ov63_0222BEC0 *ov63_0222BF80(const UnkStruct_ov63_0222BE18 *param0, u16 slotsMinigameDTO);
const UnkStruct_ov63_0222BEC0 *ov63_0222BF88(const UnkStruct_ov63_0222BE18 *param0, u16 slotsMinigameDTO);
s32 ov63_0222BF90(const UnkStruct_ov63_0222BEC0 *param0, int slotsMinigameDTO);
void ov63_0222C000(UnkStruct_ov63_0222BEC0 *param0, int slotsMinigameDTO, s32 param2);
UnkStruct_ov63_0222CC3C ov63_0222C078(UnkStruct_ov63_0222CC3C param0, int slotsMinigameDTO);
int ov63_0222C0AC(int param0);
UnkStruct_ov63_0222CC3C ov63_0222C0E4(const UnkStruct_ov63_0222BEC0 *param0);
UnkStruct_ov63_0222CC3C ov63_0222C0F0(const UnkStruct_ov63_0222BEC0 *param0);
UnkStruct_ov63_0222CC3C ov63_0222C0FC(const UnkStruct_ov63_0222BEC0 *param0);
void ov63_0222C1A4(UnkStruct_ov63_0222BEC0 *param0, UnkStruct_ov63_0222CC3C slotsMinigameDTO);
void ov63_0222C1B4(UnkStruct_ov63_0222BEC0 *param0, UnkStruct_ov63_0222CC3C slotsMinigameDTO);
const UnkStruct_ov63_0222BEC0 *ov63_0222C1C4(const UnkStruct_ov63_0222BEC0 *param0, const UnkStruct_ov63_0222BE18 *slotsMinigameDTO, int param2);
const UnkStruct_ov63_0222BEC0 *ov63_0222C2AC(const UnkStruct_ov63_0222BE18 *param0, UnkStruct_ov63_0222CC3C slotsMinigameDTO);

#endif // POKEPLATINUM_OV63_0222BE18_H
