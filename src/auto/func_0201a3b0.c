/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0201f4a0(s32);                         /* extern */
s32 func_0201f4ec(s32, M2C_UNK *);                  /* extern */
M2C_UNK func_0202dcb0(M2C_UNK, s32);                /* extern */
void *func_0206eab8();                              /* extern */
extern s32 data_020d34a8;
extern s32 data_020d34ac;
extern M2C_UNK data_020d3734;

void func_0201a3b0(void *arg0) {
    s16 temp_r2;
    s16 temp_r3;
    s32 var_r5;
    void *temp_r0;
    void *temp_r4;

    temp_r4 = func_020197fc();
    func_0202dcb0(4, M2C_FIELD(arg0, s32 *, 0x24));
    temp_r3 = M2C_FIELD(temp_r4, s16 *, 0x16);
    if (temp_r3 == 2) {
        temp_r0 = func_0206eab8();
        M2C_FIELD(temp_r0, u32 *, 0) =
            (u32) ((M2C_FIELD(temp_r0, s32 *, 4) * M2C_FIELD(temp_r0, u32 *, 0)) + M2C_FIELD(temp_r0, s32 *, 8));
        if ((u16) ((u32) (((u32) M2C_FIELD(temp_r0, u32 *, 0) >> 0x10) * 2) >> 0x10) != 0) {
            var_r5 = 0x39;
        } else {
            var_r5 = 0x40;
        }
    } else if ((u32) (data_020d34ac - 2) <= 1U) {
        if (data_020d34ac == 2) {
            var_r5 = 0x39;
        } else {
            var_r5 = 0x3F;
        }
        if (M2C_FIELD(temp_r4, s16 *, 0x38) == (M2C_FIELD(temp_r4, s16 *, 0x3A) - 1)) {
            var_r5 = 0x3A;
        }
    } else if (data_020d34a8 != 0) {
        var_r5 = 0x3E;
    } else {
        temp_r2 = M2C_FIELD(temp_r4, s16 *, 0x38);
        if (temp_r2 == 0) {
            var_r5 = 0x39;
            if (temp_r3 == 3) {
                if (M2C_FIELD(temp_r4, s32 *, 0) == M2C_FIELD(temp_r4, s32 *, 8)) {
                    var_r5 = M2C_FIELD((temp_r4 + ((temp_r2 - 1) * 8)), s32 *, 0x40) + 0x3B;
                }
            }
        } else if (temp_r2 == (M2C_FIELD(temp_r4, s16 *, 0x3A) - 1)) {
            var_r5 = 0x3A;
            if (temp_r3 == 3) {
                if (M2C_FIELD(temp_r4, s32 *, 0) == M2C_FIELD(temp_r4, s32 *, 4)) {
                    var_r5 = M2C_FIELD((temp_r4 + ((temp_r2 - 1) * 8)), s32 *, 0x40) + 0x3B;
                }
            }
        } else {
            var_r5 = M2C_FIELD((temp_r4 + ((temp_r2 - 1) * 8)), s32 *, 0x40) + 0x3B;
        }
    }
    func_0201f4a0(var_r5);
    M2C_FIELD(arg0, s32 *, 0x24) = func_0201f4ec(var_r5, &data_020d3734);
}
