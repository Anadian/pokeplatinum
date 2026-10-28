#ifndef PPWLOBBY_PARSER_H
#define PPWLOBBY_PARSER_H

#include "ilobby/ov66_022364B0.h"
#include "ppwlobby/ppw_lobby.h"

class UnkClass_ov66_02241184 : public UnkClass_ov66_0225B6E4 {
public:
    typedef enum UnkEnum_ov66_02241184 {
        UnkEnum_ov66_02241184_0,
        UnkEnum_ov66_02241184_1
    } UnkEnum_ov66_02241184;

    struct UnkClass_ov66_02241184_SubStruct : public UnkClass_ov66_0225B6E4 {
        u32 coins;
        u32 slotMachineVariant;
        int unk_08;
        UnkEnum_ov66_02241184 slotsMinigameDTO;
        s32 unk_10;
        u32 unused;
        std::vector<u8, PPW_Allocator<u8> > unk_18;

        UnkClass_ov66_02241184_SubStruct()
            : coins(0)
            , slotMachineVariant(6)
            , unk_08(0)
            , slotsMinigameDTO(UnkClass_ov66_02241184::UnkEnum_ov66_02241184_0)
            , unk_10(0)
            , unused(0)
            , unk_18()
        {
        }
    };

    static BOOL ov66_02241184(const PPWString &param0, UnkClass_ov66_02241184_SubStruct &slotsMinigameDTO);
    static BOOL ov66_022416DC(int param0, UnkEnum_ov66_02241184 slotsMinigameDTO, s32 param2, const char *param3, std::size_t param4, PPWString &param5);
};

#endif // PPWLOBBY_PARSER_H
