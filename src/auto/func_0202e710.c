#include "m2c.h"

s32 func_020058ec(M2C_UNK, s32, M2C_UNK);           /* extern */
s32 func_02005bb8(M2C_UNK);                         /* extern */
s32 func_02005bcc(M2C_UNK);                         /* extern */
s32 func_020762e0(s32, s32, M2C_UNK);               /* extern */
extern s32 data_021008c8;

s32 func_0202e710(void) {
    s32 temp_r0;
    s32 temp_r4;
    s32 temp_r4_2;

    temp_r4       = func_02005bb8(0);
    temp_r4_2     = (func_02005bcc(0) & ~0xF) - ((temp_r4 + 0xF) & ~0xF);
    temp_r0       = func_020762e0(func_020058ec(0, temp_r4_2, 0x10), temp_r4_2, 0);
    data_021008c8 = temp_r0;
    if (temp_r0 != 0) {
        return 1;
    }
    return 0;
}
