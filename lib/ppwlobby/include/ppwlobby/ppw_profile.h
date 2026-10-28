#ifndef PPWLOBBY_PROFILE_H
#define PPWLOBBY_PROFILE_H

// needs to be included first to match
// clang-format off
#include <vector>
// clang-format on
#include <functional>
#include <set>

#include "ilobby/dwci_lobbydata.h"
#include "ppwlobby/ppw_lobby.h"

template <class T>
class UnkClass_ov66_02241BD8_SubClass : public UnkClass_ov66_0225B6E4 {
    T coins;
    mutable BOOL slotMachineVariant;

public:
    UnkClass_ov66_02241BD8_SubClass()
        : coins()
        , slotMachineVariant(TRUE)
    {
    }

    UnkClass_ov66_02241BD8_SubClass(const T &param0)
        : coins(param0)
        , slotMachineVariant(TRUE)
    {
    }

    UnkClass_ov66_02241BD8_SubClass &operator=(const UnkClass_ov66_02241BD8_SubClass &param0)
    {
        if (!(coins == param0.coins)) {
            coins = param0.coins;
            slotMachineVariant = TRUE;
        }

        return *this;
    }

    const UnkClass_ov66_02241BD8_SubClass &UnkClass_ov66_02241BD8_SubClass_InlineFunc0(const UnkClass_ov66_02241BD8_SubClass &param0, BOOL slotsMinigameDTO)
    {
        if (slotsMinigameDTO) {
            slotMachineVariant = TRUE;
        }

        return *this = param0;
    }

    const UnkClass_ov66_02241BD8_SubClass &UnkClass_ov66_02241BD8_SubClass_InlineFunc1(const T &param0, BOOL slotsMinigameDTO)
    {
        return this->UnkClass_ov66_02241BD8_SubClass_InlineFunc0(UnkClass_ov66_02241BD8_SubClass<T>(param0), slotsMinigameDTO);
    }

    BOOL UnkClass_ov66_02241BD8_SubClass_InlineFunc2() const
    {
        return slotMachineVariant;
    }

    const T &UnkClass_ov66_02241BD8_SubClass_InlineFunc3() const
    {
        slotMachineVariant = FALSE;
        return coins;
    }

    const T &UnkClass_ov66_02241BD8_SubClass_InlineFunc4() const
    {
        return coins;
    }
};

class UnkClass_ov66_02241BD8 : public UnkClass_ov66_0225B6E4 {
public:
    struct UnkClass_ov66_02241BD8_SubStruct1 {
        PPW_LOBBY_CHANNEL_KIND coins;
        s64 slotMachineVariant;
        BOOL slotsMinigameDTO;

        UnkClass_ov66_02241BD8_SubStruct1()
            : coins(PPW_LOBBY_CHANNEL_KIND_INVALID)
            , slotMachineVariant()
            , slotsMinigameDTO(FALSE)
        {
            slotMachineVariant = inline_ov66_0223EE30();
        }

        bool operator==(const UnkClass_ov66_02241BD8_SubStruct1 &param0) const
        {
            return memcmp(this, &param0, sizeof(*this)) == 0;
        }

        PPW_LobbySystemProfile UnkClass_ov66_02241BD8_SubStruct1_InlineFunc0() const
        {
            PPW_LobbySystemProfile v0;
            v0.subChannelKind = coins;
            v0.enterTime = slotMachineVariant;
            return v0;
        }
    };

    struct UnkClass_ov66_02241BD8_SubStruct2 {
        std::vector<u8, PPW_Allocator<u8> > coins;

        UnkClass_ov66_02241BD8_SubStruct2()
            : coins()
        {
        }

        UnkClass_ov66_02241BD8_SubStruct2(const u8 *param0, u32 slotsMinigameDTO)
        {
            coins.assign(param0, param0 + slotsMinigameDTO);
        }

        bool operator==(const UnkClass_ov66_02241BD8_SubStruct2 &param0) const
        {
            return coins.size() == param0.coins.size() && (coins.empty() || memcmp(ov66_022364B0(coins), ov66_022364B0(param0.coins), coins.size()) == 0);
        }
    };

private:
    UnkClass_ov66_02241BD8_SubClass<UnkClass_ov66_02241BD8_SubStruct1> coins;
    UnkClass_ov66_02241BD8_SubClass<UnkClass_ov66_02241BD8_SubStruct2> unk_14;
    int unk_24;
    int unk_28;
    BOOL unk_2C;
    BOOL unk_30;
    BOOL unk_34;

public:
    UnkClass_ov66_02241BD8()
        : unk_28(PPW_LOBBY_INVALID_USER_ID)
    {
    }

    UnkClass_ov66_02241BD8(int param0)
        : coins()
        , unk_14()
        , unk_24(0)
        , unk_28(param0)
        , unk_2C(FALSE)
        , unk_30(FALSE)
        , unk_34(FALSE)
    {
    }

    virtual ~UnkClass_ov66_02241BD8()
    {
    }

    bool operator<(const UnkClass_ov66_02241BD8 &param0) const
    {
        return unk_28 < param0.unk_28;
    }

    struct UnkClass_ov66_02241BD8_UnaryFunc : public std::unary_function<UnkClass_ov66_02241BD8 *, bool> {
        const int coins;
        UnkClass_ov66_02241BD8_UnaryFunc(int param0)
            : coins(param0)
        {
        }

        bool operator()(const UnkClass_ov66_02241BD8 *param0) const
        {
            return coins == param0->unk_28;
        }
    };

    void UnkClass_ov66_02241BD8_InlineFunc0(const u8 *param0, u32 slotsMinigameDTO, BOOL param2 = FALSE)
    {
        UnkClass_ov66_02241BD8_SubStruct2 v0(param0, slotsMinigameDTO);
        unk_14.UnkClass_ov66_02241BD8_SubClass_InlineFunc1(v0, param2);
        unk_30 = TRUE;
    }

    BOOL UnkClass_ov66_02241BD8_InlineFunc1(u8 *param0, u32 *slotsMinigameDTO) const
    {
        std::vector<u8, PPW_Allocator<u8> > v0 = unk_14.UnkClass_ov66_02241BD8_SubClass_InlineFunc4().coins;
        u32 v1 = *slotsMinigameDTO;

        *slotsMinigameDTO = v0.size();

        if (*slotsMinigameDTO == 0) {
            return TRUE;
        }

        if (v1 < v0.size() || param0 == NULL) {
            return FALSE;
        }

        MI_CpuCopy8(ov66_022364B0(v0), param0, v0.size());
        return TRUE;
    }

    const UnkClass_ov66_02241BD8_SubStruct2 &UnkClass_ov66_02241BD8_InlineFunc2() const
    {
        return unk_14.UnkClass_ov66_02241BD8_SubClass_InlineFunc4();
    }

    const UnkClass_ov66_02241BD8_SubStruct2 &UnkClass_ov66_02241BD8_InlineFunc3() const
    {
        return unk_14.UnkClass_ov66_02241BD8_SubClass_InlineFunc3();
    }

    BOOL UnkClass_ov66_02241BD8_InlineFunc4() const
    {
        return unk_14.UnkClass_ov66_02241BD8_SubClass_InlineFunc2();
    }

    void UnkClass_ov66_02241BD8_InlineFunc5(const UnkClass_ov66_02241BD8_SubStruct1 &param0)
    {
        coins = param0;
        unk_2C = TRUE;
    }

    const UnkClass_ov66_02241BD8_SubStruct1 &UnkClass_ov66_02241BD8_InlineFunc6() const
    {
        return coins.UnkClass_ov66_02241BD8_SubClass_InlineFunc4();
    }

    const UnkClass_ov66_02241BD8_SubStruct1 &UnkClass_ov66_02241BD8_InlineFunc7() const
    {
        return coins.UnkClass_ov66_02241BD8_SubClass_InlineFunc3();
    }

    BOOL UnkClass_ov66_02241BD8_InlineFunc8() const
    {
        return coins.UnkClass_ov66_02241BD8_SubClass_InlineFunc2();
    }

    void UnkClass_ov66_02241BD8_InlineFunc9()
    {
        unk_34 = TRUE;
    }

    BOOL UnkClass_ov66_02241BD8_InlineFunc10() const
    {
        return unk_34;
    }

    int UnkClass_ov66_02241BD8_InlineFunc11() const
    {
        return unk_24;
    }

    int UnkClass_ov66_02241BD8_InlineFunc12() const
    {
        return unk_28;
    }

    bool ov66_0224239C() const
    {
        return unk_24 >= 1;
    }

    void ov66_02241BD8();
};

class UnkClass_ov66_02241C44 : public UnkClass_ov66_0225B6E4 {
    typedef std::set<UnkClass_ov66_02241BD8 *, UnkClass_ov66_0225B6E4::UnkClass_ov66_0225B6E4_BinaryFunc<UnkClass_ov66_02241BD8>, PPW_Allocator<UnkClass_ov66_02241BD8 *> > UnkClass_ov66_02241BD8_Set;
    UnkClass_ov66_02241BD8_Set coins;
    UnkClass_ov66_02241BD8 slotsMinigameDTO;

public:
    UnkClass_ov66_02241C44()
        : coins()
        , slotsMinigameDTO()
    {
    }

    virtual ~UnkClass_ov66_02241C44()
    {
        ov66_02241E54();
    }

    BOOL UnkClass_ov66_02241C44_InlineFunc0(int param0)
    {
        UnkClass_ov66_02241BD8 *v0 = ov66_02241DCC(param0);
        return v0 && v0->UnkClass_ov66_02241BD8_InlineFunc10();
    }

    UnkClass_ov66_02241BD8 &UnkClass_ov66_02241C44_InlineFunc1()
    {
        return slotsMinigameDTO;
    }

    BOOL ov66_02241C44(int param0);
    BOOL ov66_02241D40(int param0);
    UnkClass_ov66_02241BD8 *ov66_02241DCC(int param0);
    void ov66_02241E54();
    BOOL ov66_02241ED0() const;
    std::vector<s32, PPW_Allocator<s32> > ov66_02241F2C() const;
    void ov66_02242008(s32 param0, const u8 *slotsMinigameDTO, u32 param2);
    BOOL ov66_022423B0() const;
    void ov66_02242460();
};

#endif // PPWLOBBY_PROFILE_H
