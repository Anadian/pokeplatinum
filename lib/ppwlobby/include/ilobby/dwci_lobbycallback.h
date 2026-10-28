#ifndef ILOBBY_LOBBYCALLBACK_H
#define ILOBBY_LOBBYCALLBACK_H

#include <set>

#include "ilobby/dwci_lobbybase.h"

class UnkClass_ov66_02243C74 : public UnkClass_ov66_0225B6E4 {
protected:
    u32 coins;
    void *const slotMachineVariant;

    UnkClass_ov66_02243C74(void *param0)
        : coins()
        , slotMachineVariant(param0)
    {
        static u32 Unk_ov66_0225B6E0 = 0;
        coins = Unk_ov66_0225B6E0++;
    }

public:
    UnkClass_ov66_02243C74(u32 param0, void *slotsMinigameDTO)
        : coins(param0)
        , slotMachineVariant(slotsMinigameDTO)
    {
    }

    virtual ~UnkClass_ov66_02243C74()
    {
    }

    bool operator<(const UnkClass_ov66_02243C74 &param0) const
    {
        return coins < param0.coins;
    }

    virtual u32 UnkClass_ov66_02243C74_InlineFunc0() const
    {
        return coins;
    }

    virtual void *ov66_02243C74() const
    {
        return slotMachineVariant;
    }
};

template <class T>
class UnkClass_ov66_02243B74 : public UnkClass_ov66_02243C74 {
    T coins;

public:
    UnkClass_ov66_02243B74(T param0, void *slotsMinigameDTO)
        : UnkClass_ov66_02243C74(slotsMinigameDTO)
        , coins(param0)
    {
    }

    virtual ~UnkClass_ov66_02243B74()
    {
    }

    T UnkClass_ov66_02243B74_InlineFunc0() const
    {
        return coins;
    }
};

class UnkClass_ov66_0224640C : public UnkClass_ov66_0225B6E4 {
    typedef std::set<UnkClass_ov66_02243C74 *, UnkClass_ov66_0225B6E4::UnkClass_ov66_0225B6E4_BinaryFunc<UnkClass_ov66_02243C74>, PPW_Allocator<UnkClass_ov66_02243C74 *> > UnkClass_ov66_0224640C_UnkSet;
    UnkClass_ov66_0224640C_UnkSet coins;

public:
    UnkClass_ov66_0224640C()
        : coins()
    {
    }

    ~UnkClass_ov66_0224640C()
    {
        ov66_0224649C();
    }

    template <class T>
    u32 UnkClass_ov66_0224640C_InlineFunc0(T param0, void *slotsMinigameDTO)
    {
        UnkClass_ov66_02243B74<T> *v0 = new UnkClass_ov66_02243B74<T>(param0, slotsMinigameDTO);
        coins.insert(v0);

        return v0->UnkClass_ov66_02243C74_InlineFunc0();
    }

    BOOL ov66_0224640C(u32 param0);

    template <class T>
    UnkClass_ov66_02243B74<T> *UnkClass_ov66_0224640C_InlineFunc1(u32 param0)
    {
        UnkClass_ov66_02243C74 v0(param0, NULL);
        UnkClass_ov66_0224640C_UnkSet::iterator v1 = coins.find(&v0);

        if (v1 == coins.end()) {
            return NULL;
        }

        return (UnkClass_ov66_02243B74<T> *)*v1;
    }

    void ov66_0224649C();
};

#endif // ILOBBY_LOBBYCALLBACK_H
