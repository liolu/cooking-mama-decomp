/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0206eab8();                              /* extern */

void func_02028dd0(void *arg0, s32 arg1) {
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r0_6;
    void *temp_r0_7;

    temp_r0 = func_0206eab8();
    M2C_FIELD(temp_r0, u32 *, 0) =
        (u32) ((M2C_FIELD(temp_r0, s32 *, 4) * M2C_FIELD(temp_r0, u32 *, 0)) + M2C_FIELD(temp_r0, s32 *, 8));
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) (u16) ((u32) (((u32) M2C_FIELD(temp_r0, u32 *, 0) >> 0x10) * 3) >> 0x10);
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    temp_r0_2                    = func_0206eab8();
    M2C_FIELD(temp_r0_2, u32 *, 0) =
        (u32) ((M2C_FIELD(temp_r0_2, s32 *, 4) * M2C_FIELD(temp_r0_2, u32 *, 0)) + M2C_FIELD(temp_r0_2, s32 *, 8));
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (u16) ((u32) (((u32) M2C_FIELD(temp_r0_2, u32 *, 0) >> 0x10) * 2) >> 0x10);
    temp_r0_3                    = func_0206eab8();
    M2C_FIELD(temp_r0_3, u32 *, 0) =
        (u32) ((M2C_FIELD(temp_r0_3, s32 *, 4) * M2C_FIELD(temp_r0_3, u32 *, 0)) + M2C_FIELD(temp_r0_3, s32 *, 8));
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) (u16) ((u32) (((u32) M2C_FIELD(temp_r0_3, u32 *, 0) >> 0x10) * 2) >> 0x10);
    temp_r0_4                    = func_0206eab8();
    M2C_FIELD(temp_r0_4, u32 *, 0) =
        (u32) ((M2C_FIELD(temp_r0_4, s32 *, 4) * M2C_FIELD(temp_r0_4, u32 *, 0)) + M2C_FIELD(temp_r0_4, s32 *, 8));
    M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (u16) ((u32) (((u32) M2C_FIELD(temp_r0_4, u32 *, 0) >> 0x10) * 2) >> 0x10);
    temp_r0_5                    = func_0206eab8();
    M2C_FIELD(temp_r0_5, u32 *, 0) =
        (u32) ((M2C_FIELD(temp_r0_5, s32 *, 4) * M2C_FIELD(temp_r0_5, u32 *, 0)) + M2C_FIELD(temp_r0_5, s32 *, 8));
    if ((u16) ((u32) (((u32) M2C_FIELD(temp_r0_5, u32 *, 0) >> 0x10) * 2) >> 0x10) != 0) {
        M2C_FIELD(arg0, s32 *, 0x40) = -1;
    } else {
        M2C_FIELD(arg0, s32 *, 0x30) = -1;
    }
    M2C_FIELD(arg0, s32 *, 0x4C) = 2;
    if (arg1 == 0) {
        if (M2C_FIELD(arg0, s32 *, 0x28) == 0) {
            M2C_FIELD(arg0, s32 *, 0x4C) = 1;
            if (M2C_FIELD(arg0, s32 *, 0x30) != -1) {
                M2C_FIELD(arg0, s32 *, 0x30) = -1;
                temp_r0_6                    = func_0206eab8();
                M2C_FIELD(temp_r0_6, u32 *, 0) =
                    (u32) ((M2C_FIELD(temp_r0_6, s32 *, 4) * M2C_FIELD(temp_r0_6, u32 *, 0)) + M2C_FIELD(temp_r0_6, s32 *, 8));
                M2C_FIELD(arg0, s32 *, 0x40) =
                    (s32) (u16) ((u32) (((u32) M2C_FIELD(temp_r0_6, u32 *, 0) >> 0x10) * 2) >> 0x10);
            }
        }
    } else {
        M2C_FIELD(arg0, s32 *, 0x40) = -1;
        temp_r0_7                    = func_0206eab8();
        M2C_FIELD(temp_r0_7, u32 *, 0) =
            (u32) ((M2C_FIELD(temp_r0_7, s32 *, 4) * M2C_FIELD(temp_r0_7, u32 *, 0)) + M2C_FIELD(temp_r0_7, s32 *, 8));
        M2C_FIELD(arg0, s32 *, 0x30) = (s32) (u16) ((u32) (((u32) M2C_FIELD(temp_r0_7, u32 *, 0) >> 0x10) * 3) >> 0x10);
    }
    M2C_FIELD(arg0, s32 *, 0x38)                          = 0;
    M2C_FIELD(arg0, s32 *, 0x34)                          = (s32) M2C_FIELD(arg0, s32 *, 0x38);
    M2C_FIELD(arg0, s32 *, 0x48)                          = 0;
    M2C_FIELD(arg0, s32 *, 0x44)                          = (s32) M2C_FIELD(arg0, s32 *, 0x48);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s16 *, 0xC) = 0x1000;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s16 *, 0xE) = 0x1000;
}
