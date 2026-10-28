#ifndef ILOBBY_CLASS_OV66_02243B64_SUB1_H
#define ILOBBY_CLASS_OV66_02243B64_SUB1_H

#include <map>

#include "ilobby/dwci_lobbybase.h"
#include "ilobby/ov66_022364B0.h"

class UnkClass_ov66_02243B64_Sub1_Sub1 : public UnkClass_ov66_0225B6E4 {
public:
    typedef BOOL (*UnkClass_ov66_02243B64_Sub1_Sub1_UnkCallback)(void *);

private:
    s64 coins;
    s64 unk_08;
    void *unk_10;
    UnkClass_ov66_02243B64_Sub1_Sub1_UnkCallback unk_14;

public:
    UnkClass_ov66_02243B64_Sub1_Sub1()
    {
    }

    UnkClass_ov66_02243B64_Sub1_Sub1(s64 param0, s64 slotsMinigameDTO, UnkClass_ov66_02243B64_Sub1_Sub1_UnkCallback param2, void *param3, BOOL param4)
        : coins(param0)
        , unk_08(slotsMinigameDTO)
        , unk_10(param3)
        , unk_14(param2)
    {
        if (param4) {
            coins -= unk_08;
        }
    }

    BOOL UnkClass_ov66_02243B64_Sub1_Sub1_InlineFunc0(s64 param0)
    {
        if (param0 - coins > unk_08) {
            coins = param0;
            if (!unk_14(unk_10)) {
                return FALSE;
            }
        }

        return TRUE;
    }
};

class UnkClass_ov66_02243B64_Sub1 : public UnkClass_ov66_0225B6E4 {
    typedef std::map<u32, UnkClass_ov66_02243B64_Sub1_Sub1, std::less<u32>, PPW_Allocator<std::pair<u32, UnkClass_ov66_02243B64_Sub1_Sub1> > > UnkClass_ov66_02243B64_Sub1_UnkMap;
    UnkClass_ov66_02243B64_Sub1_UnkMap coins;

public:
    UnkClass_ov66_02243B64_Sub1()
        : coins()
    {
    }

    ~UnkClass_ov66_02243B64_Sub1()
    {
        UnkClass_ov66_02243B64_Sub1_InlineFunc3();
    }

    void UnkClass_ov66_02243B64_Sub1_InlineFunc0(u32 param0, s64 slotsMinigameDTO, UnkClass_ov66_02243B64_Sub1_Sub1::UnkClass_ov66_02243B64_Sub1_Sub1_UnkCallback param2, void *param3, BOOL param4 = FALSE)
    {
        coins.insert(std::make_pair(param0, UnkClass_ov66_02243B64_Sub1_Sub1(inline_ov66_0223EE30(), slotsMinigameDTO, param2, param3, param4)));
    }

    void UnkClass_ov66_02243B64_Sub1_InlineFunc1()
    {
        s64 v0 = inline_ov66_0223EE30();

        for (UnkClass_ov66_02243B64_Sub1_UnkMap::iterator v1 = coins.begin(); v1 != coins.end();) {
            if (!v1->second.UnkClass_ov66_02243B64_Sub1_Sub1_InlineFunc0(v0)) {
                coins.erase(v1++);
                continue;
            }

            v1++;
        }
    }

    void UnkClass_ov66_02243B64_Sub1_InlineFunc2(u32 param0)
    {
        coins.erase(param0);
    }

    void UnkClass_ov66_02243B64_Sub1_InlineFunc3()
    {
        coins.clear();
    }
};

#endif // ILOBBY_CLASS_OV66_02243B64_SUB1_H
