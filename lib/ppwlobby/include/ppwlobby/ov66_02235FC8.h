#ifndef PPWLOBBY_OV66_02235FC8_H
#define PPWLOBBY_OV66_02235FC8_H

#include "ilobby/dwci_lobbydata.h"
#include "ppwlobby/ppw_lobby.h"

class UnkClass_ov66_02235FC8 : public UnkClass_ov66_0225B6E4 {
    PPW_LOBBY_CHANNEL_KIND coins;
    PPWString slotMachineVariant;
    BOOL unk_10;
    BOOL unk_14;

public:
    UnkClass_ov66_02235FC8()
        : coins(PPW_LOBBY_CHANNEL_KIND_INVALID)
        , slotMachineVariant()
    {
    }

    UnkClass_ov66_02235FC8(PPW_LOBBY_CHANNEL_KIND param0, const PPWString &slotsMinigameDTO)
        : coins(param0)
        , slotMachineVariant(slotsMinigameDTO)
        , unk_10(FALSE)
        , unk_14(FALSE)
    {
    }

    BOOL UnkClass_ov66_02235FC8_InlineFunc0() const
    {
        if (coins != PPW_LOBBY_CHANNEL_KIND_INVALID) {
            return TRUE;
        } else {
            return FALSE;
        }
    }

    PPW_LOBBY_CHANNEL_KIND UnkClass_ov66_02235FC8_InlineFunc1() const
    {
        return coins;
    }

    PPWString ov66_02235FC8() const
    {
        return slotMachineVariant;
    }

    void UnkClass_ov66_02235FC8_InlineFunc2()
    {
        unk_10 = TRUE;
    }

    BOOL UnkClass_ov66_02235FC8_InlineFunc3() const
    {
        return unk_10;
    }

    void UnkClass_ov66_02235FC8_InlineFunc4()
    {
        unk_14 = TRUE;
    }

    BOOL UnkClass_ov66_02235FC8_InlineFunc5() const
    {
        return unk_14;
    }

    void UnkClass_ov66_02235FC8_InlineFunc6(PPW_LOBBY_CHANNEL_KIND param0, const PPWString &slotsMinigameDTO)
    {
        coins = param0;
        slotMachineVariant = slotsMinigameDTO;
        unk_10 = FALSE;
        unk_14 = FALSE;
    }

    void UnkClass_ov66_02235FC8_InlineFunc7()
    {
        UnkClass_ov66_02235FC8_InlineFunc6(PPW_LOBBY_CHANNEL_KIND_INVALID, PPWString());
    }
};

class UnkClass_ov66_02236348 : public UnkClass_ov66_0225B6E4 {
private:
    UnkClass_ov66_02235FC8 coins;
    UnkClass_ov66_02235FC8 unk_18;

public:
    UnkClass_ov66_02236348()
        : coins()
        , unk_18()
    {
    }

    UnkClass_ov66_02235FC8 &UnkClass_ov66_02236348_InlineFunc0(int param0)
    {
        switch (param0) {
        case 0:
            return coins;
        case 1:
            return unk_18;
        default:
            return coins;
        }
    }

    void UnkClass_ov66_02236348_InlineFunc1(int param0, const UnkClass_ov66_02235FC8 &slotsMinigameDTO)
    {
        switch (param0) {
        case 0:
            coins = slotsMinigameDTO;
            break;
        case 1:
            unk_18 = slotsMinigameDTO;
            break;
        default:
            break;
        }
    }

    PPWString ov66_02236348(PPW_LOBBY_CHANNEL_KIND param0) const
    {
        if (param0 == PPW_LOBBY_CHANNEL_KIND_MAIN) {
            return coins.ov66_02235FC8();
        } else {
            return unk_18.ov66_02235FC8();
        }
    }

    PPW_LOBBY_CHANNEL_KIND UnkClass_ov66_02236348_InlineFunc2(const PPWString &param0) const
    {
        if (coins.ov66_02235FC8() == param0) {
            return coins.UnkClass_ov66_02235FC8_InlineFunc1();
        }

        if (unk_18.ov66_02235FC8() == param0) {
            return unk_18.UnkClass_ov66_02235FC8_InlineFunc1();
        }

        return PPW_LOBBY_CHANNEL_KIND_INVALID;
    }
};

#endif // PPWLOBBY_OV66_02235FC8_H
