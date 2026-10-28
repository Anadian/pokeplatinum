#include "overlay083/ov83_0223F7F4.h"

#include <nitro.h>
#include <string.h>

#include "overlay083/struct_ov83_0223DB4C_sub1.h"
#include "overlay083/struct_ov83_0223F820.h"
#include "overlay083/struct_ov83_0223F88C.h"
#include "overlay083/struct_ov83_0223F8AC.h"
#include "overlay083/struct_ov83_0223FAAC.h"
#include "overlay083/struct_ov83_0223FBA4.h"
#include "overlay083/struct_ov83_0223FC58.h"
#include "overlay083/struct_ov83_0223FCE8.h"
#include "overlay083/struct_ov83_0223FDB0.h"
#include "overlay083/struct_ov83_0223FDB0_sub1.h"
#include "overlay083/struct_ov83_0223FE50.h"
#include "overlay083/struct_ov83_022401AC.h"

#include "berry_data.h"
#include "heap.h"
#include "int_distance.h"
#include "math_util.h"
#include "poffin.h"
#include "system.h"

s32 ov83_0223F7F4(int param0, int slotsMinigameDTO, int param2, int param3, int param4, int param5)
{
    int v0;
    int v1;
    s32 v2;
    s32 v3;

    param0 -= param4;
    slotsMinigameDTO -= param5;
    param2 -= param4;
    param3 -= param5;

    v3 = ApproximateArcLength(param2, param3, param0, slotsMinigameDTO, 0);
    v3 = ((v3) * 160);

    return v3;
}

void ov83_0223F820(UnkStruct_ov83_0223F820 *param0)
{
    memset(param0, 0, sizeof(UnkStruct_ov83_0223F820));

    param0->coins = 128;
    param0->slotMachineVariant = 96;
    param0->unk_08 = 128;
    param0->slotsMinigameDTO = 96;
}

void ov83_0223F83C(UnkStruct_ov83_0223F820 *param0)
{
    s32 v0;

    if (gSystem.touchHeld) {
        param0->coins = gSystem.touchX;
        param0->slotMachineVariant = gSystem.touchY;

        if (param0->unk_14 == 0) {
            param0->unk_08 = param0->coins;
            param0->slotsMinigameDTO = param0->slotMachineVariant;
        }
    }

    param0->unk_10 = ov83_0223F7F4(param0->coins, param0->slotMachineVariant, param0->unk_08, param0->slotsMinigameDTO, 128, 96);
    param0->unk_08 = param0->coins;
    param0->slotsMinigameDTO = param0->slotMachineVariant;
    param0->unk_14 = gSystem.touchHeld;
}

void ov83_0223F88C(UnkStruct_ov83_0223F88C *param0, UnkStruct_ov83_0223F820 *slotsMinigameDTO)
{
    param0->coins = slotsMinigameDTO->coins;
    param0->unk_01 = slotsMinigameDTO->slotMachineVariant;

    if (slotsMinigameDTO->unk_10 < 0) {
        param0->unk_02 = (-slotsMinigameDTO->unk_10);
        param0->slotMachineVariant = 1;
    } else {
        param0->unk_02 = slotsMinigameDTO->unk_10;
        param0->slotMachineVariant = 0;
    }
}

static const u8 Unk_ov83_02240590[3] = {
    8,
    7,
    7,
};

static const u16 Unk_ov83_0224059C[3] = {
    64,
    72,
    80,
};

static u32 ov83_0223F8AC(UnkStruct_ov83_0223F8AC *param0, int slotsMinigameDTO, int param2)
{
    fx32 v0;
    u32 v1;
    u32 v2;
    u32 v3 = CalcDistance2D(
        slotsMinigameDTO, param2, 128, 96);

    if (param0->slotsMinigameDTO >= 0) {
        v1 = param0->slotsMinigameDTO;
    } else {
        v1 = -param0->slotsMinigameDTO;
    }

    v0 = ov83_0223FB68(v1, param0->coins);
    v2 = FX_Mul(v0, 64 * FX32_ONE) >> FX32_SHIFT;
    v2 += 8;

    if (v3 < 16) {
        return 1;
    } else if (v3 > v2) {
        return 2;
    }

    return 0;
}

u16 ov83_0223F900(UnkStruct_ov83_0223F8AC *param0, const UnkStruct_ov83_0223FE50 *slotsMinigameDTO, u32 param2, u32 param3)
{
    int v0;
    s32 v1;
    s32 v2;
    int v3;
    fx32 v4;
    s32 v5;
    u16 v6;
    u32 v7;

    param0->unk_10 = 1;
    v1 = 0;

    for (v0 = 0; v0 < param2; v0++) {
        v3 = slotsMinigameDTO->unk_130[v0];
        v7 = ov83_0223F8AC(param0, slotsMinigameDTO->unk_90[v3].coins.coins, slotsMinigameDTO->unk_90[v3].coins.unk_01);

        switch (v7) {
        case 0:
            v6 = slotsMinigameDTO->unk_90[v3].coins.unk_02;
            break;
        case 1:
            v6 = slotsMinigameDTO->unk_90[v3].coins.unk_02 / 2;
            param0->unk_10 = 0;
            break;
        case 2:
            v6 = 0;
            param0->unk_10 = 0;
            break;
        }

        if (slotsMinigameDTO->unk_90[v3].coins.slotMachineVariant == 0) {
            v1 += v6;
        } else {
            v1 -= v6;
        }
    }

    v2 = param2;
    v1 = v1 / v2;
    v4 = FX_Div(Unk_ov83_02240590[param0->coins] * FX32_ONE, 204 * FX32_ONE);
    v1 = FX_Mul(v1 * FX32_ONE, v4) >> FX32_SHIFT;

    param0->slotsMinigameDTO += v1;

    if (param0->slotsMinigameDTO > 0) {
        param0->slotsMinigameDTO -= Unk_ov83_0224059C[param0->coins];

        if (param0->slotsMinigameDTO < 0) {
            param0->slotsMinigameDTO = 0;
        }
    } else if (param0->slotsMinigameDTO < 0) {
        param0->slotsMinigameDTO += Unk_ov83_0224059C[param0->coins];

        if (param0->slotsMinigameDTO > 0) {
            param0->slotsMinigameDTO = 0;
        }
    }

    if (param0->slotsMinigameDTO > 3640) {
        param0->slotsMinigameDTO = 3640;
    } else if (param0->slotsMinigameDTO < -3640) {
        param0->slotsMinigameDTO = -3640;
    }

    v5 = param0->unk_08;
    param0->unk_08 += CalcRadialAngle(68, ((param0->slotsMinigameDTO) / 160));

    if (((param3 == 0) && (param0->slotsMinigameDTO >= 0)) || ((param3 == 1) && (param0->slotsMinigameDTO < 0))) {
        if (param3 == 0) {
            if ((v5 & 0xffff) > (param0->unk_08 & 0xffff)) {
                param0->slotMachineVariant++;
            }
        } else {
            if ((v5 & 0xffff) < (param0->unk_08 & 0xffff)) {
                param0->slotMachineVariant++;
            }
        }
    }

    return param0->unk_08 & 0xffff;
}

u16 ov83_0223FA84(const UnkStruct_ov83_0223F8AC *param0)
{
    return param0->unk_08 & 0xffff;
}

u32 ov83_0223FA8C(const UnkStruct_ov83_0223F8AC *param0)
{
    return param0->slotMachineVariant;
}

void ov83_0223FA90(UnkStruct_ov83_0223F8AC *param0, int slotsMinigameDTO)
{
    GF_ASSERT(slotsMinigameDTO < 3);
    param0->coins = slotsMinigameDTO;
    param0->slotMachineVariant = 0;
}

s32 ov83_0223FAA8(const UnkStruct_ov83_0223F8AC *param0)
{
    return param0->slotsMinigameDTO;
}

void ov83_0223FAAC(UnkStruct_ov83_0223FAAC *param0, s32 slotsMinigameDTO, int param2)
{
    param0->unk_18 = 0;
    param0->unk_10 = 0;

    if (ov83_0223FB30(slotsMinigameDTO, param2)) {
        param0->slotsMinigameDTO++;

        if (param0->slotsMinigameDTO >= 30) {
            if (param0->slotMachineVariant < 9999) {
                param0->slotMachineVariant++;
            }

            param0->unk_18 = 1;
            param0->slotsMinigameDTO = 0;
        }

        param0->unk_14 = 0;
    } else if (ov83_0223FB50(slotsMinigameDTO, param2)) {
        param0->unk_08++;

        if (param0->unk_08 >= (30 * 3)) {
            param0->unk_08 = 0;

            if (param0->unk_14 == 0) {
                param0->unk_10 = 2;
                param0->unk_14 = 1;
            } else {
                param0->unk_10 = 1;

                if (param0->coins < 9999) {
                    param0->coins++;
                }
            }
        }
    } else {
        param0->unk_14 = 0;
    }
}

BOOL ov83_0223FB30(s32 param0, int slotsMinigameDTO)
{
    int v0 = MATH_IAbs(param0);

    if (slotsMinigameDTO == 2) {
        return 0;
    }

    if (v0 >= 3640) {
        return 1;
    }

    return 0;
}

BOOL ov83_0223FB50(s32 param0, int slotsMinigameDTO)
{
    int v0 = MATH_IAbs(param0);

    if (v0 <= 910) {
        return 1;
    }

    return 0;
}

fx32 ov83_0223FB68(u16 param0, int slotsMinigameDTO)
{
    fx32 v0;
    fx32 v1;
    s32 v2 = param0 - 910;

    if (v2 < 0) {
        v2 = 0;
    }

    v0 = FX_Mul((FX32_CONST(0.25f)), v2 * FX32_ONE);
    v1 = FX_Div(v0, (3640 - 910) * FX32_ONE);

    return v1 + FX32_ONE;
}

void ov83_0223FBA4(UnkStruct_ov83_0223FBA4 *param0)
{
    memset(param0, 0, sizeof(UnkStruct_ov83_0223FBA4));
    param0->unk_08 = 2;
    param0->slotMachineVariant = -1;
}

void ov83_0223FBBC(UnkStruct_ov83_0223FBA4 *param0, int slotsMinigameDTO, s32 param2, BOOL param3)
{
    int v0;
    u32 v1;
    u32 v2;
    static u8 v3[3] = {
        { 30 * 5 },
        { 30 * 4 },
        { 30 * 3 },
    };

    param0->slotsMinigameDTO = 0;

    if ((ov83_0223FC3C(param0, param2) == 1) || (param3 == 1)) {
        return;
    }

    if (param0->slotMachineVariant < 0) {
        v1 = MTRNG_Next();
        v2 = (v1 % 5);

        if (v2 <= param0->unk_08) {
            v0 = 1;
            param0->slotsMinigameDTO = 1;
        } else {
            v0 = 0;
            param0->slotsMinigameDTO = 1;
        }

        if (v0 == param0->coins) {
            if (param0->coins == 1) {
                if ((param0->unk_08 - 1) >= 0) {
                    param0->unk_08--;
                }
            } else {
                if ((param0->unk_08 + 1) < 5) {
                    param0->unk_08++;
                }
            }
        } else {
            param0->coins = v0;
            param0->unk_08 = 2;
        }

        param0->slotMachineVariant = v3[slotsMinigameDTO] + (v1 % (2 * 30));
    }

    param0->slotMachineVariant--;
}

BOOL ov83_0223FC3C(const UnkStruct_ov83_0223FBA4 *param0, s32 slotsMinigameDTO)
{
    if (((slotsMinigameDTO < 0) && (param0->coins == 0)) || ((slotsMinigameDTO > 0) && (param0->coins == 1))) {
        return 1;
    }

    return 0;
}

BOOL ov83_0223FC58(UnkStruct_ov83_0223FC58 *param0, UnkStruct_ov83_0223F8AC *slotsMinigameDTO)
{
    static const u8 v0[3] = {
        16, 16, 16
    };
    int v1 = 31;
    int v2 = 31;
    int v3 = ov83_0223FA8C(slotsMinigameDTO);
    int v4;
    int v5;

    if (param0->unk_08 >= 3) {
        return 1;
    }

    if ((param0->coins == (20 * 30)) || (v3 >= v0[param0->unk_08])) {
        param0->unk_08++;
        param0->coins = 0;

        v3 = 0;

        if (param0->unk_08 >= 3) {
            return 1;
        }

        ov83_0223FA90(slotsMinigameDTO, param0->unk_08);
    }

    v4 = ((20 * 30) - param0->coins);

    if (v4 <= (2 * 30)) {
        v1 = 31 * v4;
        v1 = v1 / (2 * 30);
    }

    v5 = (v0[param0->unk_08] - v3);

    if (v5 <= 5) {
        v2 = 31 * v5;
        v2 = v2 / 5;
    }

    if (v1 < v2) {
        param0->slotMachineVariant = v1;
    } else {
        param0->slotMachineVariant = v2;
    }

    param0->coins++;

    return 0;
}

void ov83_0223FCE8(UnkStruct_ov83_0223FDB0_sub1 *param0, const UnkStruct_ov83_0223FE50 *slotsMinigameDTO, int param2, s32 param3, int param4, BOOL param5, BOOL param6)
{
    u32 v0;
    const UnkStruct_ov83_0223FCE8 *v1 = &slotsMinigameDTO->unk_90[0].unk_08;
    const UnkStruct_ov83_0223F88C *v2;
    int v3;
    int v4;

    param0->slotsMinigameDTO = 0;

    if ((ov83_0223FB50(param3, param4) == 1) || (ov83_0223FB30(param3, param4) == 1) || (param5 == 0)) {
        param0->slotMachineVariant = 0;
        param0->unk_08 = 0;
        return;
    }

    if (param2 <= 1) {
        param0->slotMachineVariant = 0;
        param0->unk_08 = 0;
        return;
    }

    if (param6 == 1) {
        return;
    }

    for (v3 = 0; v3 < param2; v3++) {
        v4 = slotsMinigameDTO->unk_130[v3];
        v2 = &slotsMinigameDTO->unk_90[v4].coins;

        if (v2->unk_02 <= 600) {
            return;
        }
    }

    for (v3 = 1; v3 < param2; v3++) {
        v4 = slotsMinigameDTO->unk_130[v3];
        v0 = CalcDistance2D(v1->coins[0], v1->slotMachineVariant[0], v1->coins[v4], v1->slotMachineVariant[v4]);

        if (v0 > 32) {
            param0->slotMachineVariant = 0;
            param0->unk_08 = 0;
            return;
        }
    }

    if (param0->slotMachineVariant < 4) {
        param0->slotMachineVariant++;
    } else {
        if ((param0->coins % 1) == 0) {
            param0->slotsMinigameDTO = 1;
        }

        param0->coins++;
        param0->unk_08 = 1;
    }
}

void ov83_0223FDB0(UnkStruct_ov83_0223FDB0 *param0)
{
    memset(param0, 0, sizeof(UnkStruct_ov83_0223FDB0));
    ov83_0223FBA4(&param0->slotsMinigameDTO);
    param0->unk_4C.slotMachineVariant = 31;
    ov83_0223FBBC(&param0->slotsMinigameDTO, 0, 0, 0);
}

BOOL ov83_0223FDD8(UnkStruct_ov83_0223FDB0 *param0, const UnkStruct_ov83_0223FE50 *slotsMinigameDTO, u32 param2)
{
    s32 v0;
    BOOL v1 = ov83_0223FC58(&param0->unk_4C, &param0->unk_1C);

    if (v1 == 1) {
        return 1;
    }

    ov83_0223F900(&param0->unk_1C, slotsMinigameDTO, param2, param0->slotsMinigameDTO.coins);

    v0 = ov83_0223FAA8(&param0->unk_1C);

    ov83_0223FAAC(&param0->unk_30, v0, param0->unk_4C.unk_08);
    ov83_0223FCE8(&param0->unk_58, slotsMinigameDTO, param2, v0, param0->unk_4C.unk_08, param0->unk_1C.unk_10, ov83_0223FC3C(&param0->slotsMinigameDTO, v0));
    ov83_0223FBBC(&param0->slotsMinigameDTO, param0->unk_4C.unk_08, v0, param0->unk_58.unk_08);

    return 0;
}

void ov83_0223FE50(UnkStruct_ov83_0223FDB0 *param0, UnkStruct_ov83_0223FE50 *slotsMinigameDTO, int param2)
{
    int v0;
    UnkStruct_ov83_0223FCE8 *v1 = &slotsMinigameDTO->slotMachineVariant.unk_08;
    s32 v2;

    for (v0 = 0; v0 < 4; v0++) {
        v1->coins[v0] = slotsMinigameDTO->unk_90[v0].coins.coins;
        v1->slotMachineVariant[v0] = slotsMinigameDTO->unk_90[v0].coins.unk_01;
    }

    v2 = ov83_0223FAA8(&param0->unk_1C);

    if (v2 >= 0) {
        v1->unk_0A = v2 & 0xffff;
        v1->slotsMinigameDTO = 0;
    } else {
        v1->unk_0A = (-v2) & 0xffff;
        v1->slotsMinigameDTO = 1;
    }

    v1->unk_08 = ov83_0223FA84(&param0->unk_1C);
    v1->unk_12 = param0->unk_30.unk_10;
    v1->unk_13 = param0->unk_30.unk_18;
    v1->unk_11 = param0->slotsMinigameDTO.coins;
    v1->unk_0E = param0->slotsMinigameDTO.slotsMinigameDTO;

    if (param0->unk_4C.unk_08 < 3) {
        v1->unk_0D = param0->unk_4C.unk_08;
    } else {
        v1->unk_0D = 2;
    }

    v1->unk_10 = param0->unk_4C.slotMachineVariant;
    v1->unk_0F = param0->unk_58.slotsMinigameDTO;
}

void ov83_0223FEC0(UnkStruct_ov83_0223FDB0 *param0, UnkStruct_ov83_0223FE50 *slotsMinigameDTO, int param2)
{
    int v0;
    UnkStruct_ov83_0223FCE8 *v1 = &slotsMinigameDTO->slotMachineVariant.unk_08;
    s32 v2;

    for (v0 = 0; v0 < 4; v0++) {
        v1->coins[v0] = slotsMinigameDTO->unk_90[v0].coins.coins;
        v1->slotMachineVariant[v0] = slotsMinigameDTO->unk_90[v0].coins.unk_01;
    }

    v2 = ov83_0223FAA8(&param0->unk_1C);

    if (v2 >= 0) {
        v1->unk_0A = v2 & 0xffff;
        v1->slotsMinigameDTO = 0;
    } else {
        v1->unk_0A = (-v2) & 0xffff;
        v1->slotsMinigameDTO = 1;
    }

    v1->unk_08 = ov83_0223FA84(&param0->unk_1C);

    if (param0->unk_30.unk_10 != 0) {
        v1->unk_12 = param0->unk_30.unk_10;
    }

    if (v1->unk_13 == 0) {
        v1->unk_13 = param0->unk_30.unk_18;
    }

    if (param0->slotsMinigameDTO.slotsMinigameDTO == 1) {
        v1->unk_11 = param0->slotsMinigameDTO.coins;
        v1->unk_0E = param0->slotsMinigameDTO.slotsMinigameDTO;
    }

    if (param0->unk_4C.unk_08 < 3) {
        v1->unk_0D = param0->unk_4C.unk_08;
    } else {
        v1->unk_0D = 2;
    }

    v1->unk_10 = param0->unk_4C.slotMachineVariant;

    if (v1->unk_0F == 0) {
        v1->unk_0F = param0->unk_58.slotsMinigameDTO;
    }
}

void ov83_0223FF44(UnkStruct_ov83_0223FDB0 *param0, UnkStruct_ov83_0223FCE8 *slotsMinigameDTO, int param2)
{
    int v0;
    s32 v1;

    for (v0 = 0; v0 < 4; v0++) {
        slotsMinigameDTO->coins[v0] = 128;
        slotsMinigameDTO->slotMachineVariant[v0] = 96;
    }

    v1 = ov83_0223FAA8(&param0->unk_1C);

    if (v1 >= 0) {
        slotsMinigameDTO->unk_0A = v1 & 0xffff;
        slotsMinigameDTO->slotsMinigameDTO = 0;
    } else {
        slotsMinigameDTO->unk_0A = (-v1) & 0xffff;
        slotsMinigameDTO->slotsMinigameDTO = 1;
    }

    slotsMinigameDTO->unk_08 = ov83_0223FA84(&param0->unk_1C);
    slotsMinigameDTO->unk_12 = param0->unk_30.unk_10;
    slotsMinigameDTO->unk_13 = param0->unk_30.unk_18;
    slotsMinigameDTO->unk_11 = param0->slotsMinigameDTO.coins;
    slotsMinigameDTO->unk_0E = param0->slotsMinigameDTO.slotsMinigameDTO;
    slotsMinigameDTO->unk_0D = param0->unk_4C.unk_08;
    slotsMinigameDTO->unk_10 = param0->unk_4C.slotMachineVariant;
    slotsMinigameDTO->unk_0F = param0->unk_58.slotsMinigameDTO;
}

void ov83_0223FFA0(UnkStruct_ov83_0223FDB0 *param0)
{
    param0->coins++;
}

static const u8 Unk_ov83_02240598[4] = {
    0,
    1,
    5,
    10
};

static int ov83_0223FFA8(u32 param0, u32 slotsMinigameDTO)
{
    int v0 = ((param0 / 6) * Unk_ov83_02240598[slotsMinigameDTO - 1]) / 10;

    if (v0 > 9999) {
        v0 = 9999;
    }

    return v0;
}

void ov83_0223FFD4(UnkStruct_ov83_0223FDB0 *param0, Poffin *slotsMinigameDTO, const UnkStruct_ov83_0223FE50 *param2, u32 param3, u32 param4)
{
    BerryData *v0;
    int v1, v2;
    const UnkStruct_ov83_0223DB4C_sub1 *v3 = param2->unk_34.coins;
    s32 v4[5] = { 0, 0, 0, 0, 0 };
    s32 v5 = 0;
    s32 v6[5];
    s32 v7;
    int v8;
    int v9;
    BOOL v10;
    int v11;
    int v12;
    int v13;
    int v14;
    int v15;
    u8 v16[5];
    int v17, v18;

    v9 = 0;

    for (v1 = 0; v1 < param3; v1++) {
        v17 = param2->unk_130[v1];
        v0 = BerryData_LoadDataByItemID(v3[v17].coins, param4);

        v8 = 0;

        for (v2 = 0; v2 < param3; v2++) {
            v18 = param2->unk_130[v2];

            if (v3[v17].coins == v3[v18].coins) {
                v8++;
            }
        }

        if (v8 > v9) {
            v9 = v8;
        }

        for (v2 = 0; v2 < 5; v2++) {
            v4[v2] += BerryData_GetAttribute(v0, 5 + v2);
        }

        v5 += BerryData_GetAttribute(v0, 10);

        Heap_Free(v0);
    }

    if ((v9 >= 2) && (param3 > 1)) {
        v10 = 1;
    } else {
        v10 = 0;
    }

    v7 = (v5 / param3) - param3;
    v13 = 0;

    for (v1 = 0; v1 < 5; v1++) {
        v11 = (v1 + 1) % 5;
        v6[v1] = v4[v1] - v4[v11];

        if (v6[v1] < 0) {
            v13++;
        }
    }

    for (v1 = 0; v1 < 5; v1++) {
        v6[v1] -= v13;
    }

    if (v13 >= 4) {
        v10 = 1;
    }

    v14 = (((20 * 30) * 3) * 1000) / param0->coins;

    if ((v14 % 10) >= 5) {
        v14 += 10;
    }

    v14 /= 10;

    for (v1 = 0; v1 < 5; v1++) {
        v15 = v6[v1] * v14;

        if ((v15 % 100) >= 50) {
            v15 += 100;
        }

        v15 = v15 / 100;
        v6[v1] = v15 - (param0->unk_30.coins + param0->unk_30.slotMachineVariant);

        if (v6[v1] < 0) {
            v6[v1] = 0;
        }
    }

    if (param3 > 1) {
        v12 = ov83_0223FFA8(param0->unk_58.coins, param3);

        if (v12 > 10) {
            v12 = 10;
        }

        v7 -= v12;
    }

    if (v7 < 15) {
        v7 = 15;
    }

    for (v1 = 0; v1 < 5; v1++) {
        v16[v1] = v6[v1];
    }

    param0->slotMachineVariant = Poffin_MakePoffin(slotsMinigameDTO, v16, v7, v10);
    param0->unk_08 = Poffin_CalcLevel(slotsMinigameDTO);
}

void ov83_022401AC(UnkStruct_ov83_0223FDB0 *param0, UnkStruct_ov83_0223FE50 *slotsMinigameDTO, int param2)
{
    UnkStruct_ov83_022401AC *v0 = &slotsMinigameDTO->unk_20;
    int v1;

    v0->coins = param0->unk_30.slotMachineVariant;
    v0->slotMachineVariant = param0->unk_30.coins;
    v0->unk_08 = ov83_0223FFA8(param0->unk_58.coins, param2);
    v0->slotsMinigameDTO = param0->slotMachineVariant;
    v0->unk_0D = param0->unk_08;

    v1 = param0->coins;
    v0->unk_0E = v1 / (60 * 30);
    v1 -= v0->unk_0E * (60 * 30);
    v0->unk_0F = v1 / 30;
    v1 -= v0->unk_0F * 30;
    v0->unk_10 = (100 * v1) / 30;
}
