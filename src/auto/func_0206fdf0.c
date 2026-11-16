/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
void *func_0206eab8();                              /* extern */
extern M2C_UNK func_0206ff90;

void func_0206fdf0(void) {
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 var_r9;
    void *temp_r0;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r0_6;

    temp_r0   = func_0202f368();
    temp_r0_2 = M2C_FIELD(temp_r0, s32 *, 0x24);
    if (temp_r0_2 == 1) {
        temp_r0_3 = M2C_FIELD(temp_r0, s32 *, 0x28);
        if (temp_r0_3 < 0xE) {
            M2C_FIELD(temp_r0, s32 *, 0x28) = (s32) (temp_r0_3 + 1);
        } else {
            M2C_FIELD(temp_r0, s32 *, 0x28) = 0;
            M2C_FIELD(temp_r0, s32 *, 0x24) = 0;
        }
        return;
    }
    if (temp_r0_2 == 0) {
        func_0202ec14(0x29);
        M2C_FIELD(temp_r0, s32 *, 0x24) = 2;
        return;
    }
    M2C_FIELD(temp_r0, s32 *, 0x28) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x28) + 1);
    if ((s32) M2C_FIELD(temp_r0, s32 *, 0x28) < 0x3C) {
        var_r9 = 0;
        do {
            temp_r0_4                         = func_0202f564(&func_0206ff90, 0x11);
            M2C_FIELD(temp_r0_4, s32 *, 0x24) = 0;
            temp_r0_5                         = func_0206eab8();
            M2C_FIELD(temp_r0_5, u32 *, 0) =
                (u32) ((M2C_FIELD(temp_r0_5, s32 *, 4) * M2C_FIELD(temp_r0_5, u32 *, 0)) + M2C_FIELD(temp_r0_5, s32 *, 8));
            M2C_FIELD(temp_r0_4, s16 *, 0x20) =
                (s16) ((u16) ((u32) (((u32) M2C_FIELD(temp_r0_5, u32 *, 0) >> 0x10) * 0x50) >> 0x10) + 0x58);
            temp_r0_6 = func_0206eab8();
            var_r9 += 1;
            M2C_FIELD(temp_r0_6, u32 *, 0) =
                (u32) ((M2C_FIELD(temp_r0_6, s32 *, 4) * M2C_FIELD(temp_r0_6, u32 *, 0)) + M2C_FIELD(temp_r0_6, s32 *, 8));
            M2C_FIELD(temp_r0_4, s16 *, 0x22) =
                (s16) ((u16) ((u32) (((u32) M2C_FIELD(temp_r0_6, u32 *, 0) >> 0x10) * 0x60) >> 0x10) + 0x30);
        } while (var_r9 < 2);
        return;
    }
    M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
}
