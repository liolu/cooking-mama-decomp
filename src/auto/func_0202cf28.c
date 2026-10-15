#include "m2c.h"

M2C_UNK func_020038e8(M2C_UNK);                     /* extern */
M2C_UNK func_02009cc0(M2C_UNK);                     /* extern */
s32 func_02009cfc(s32, s32);                        /* extern */
s32 func_0202e6ac(s32, M2C_UNK, M2C_UNK);           /* extern */
extern s32 data_020e8358;

void func_0202cf28(void) {
    s32 temp_r0;
    s32 temp_r0_2;

    func_020038e8(0x40000);
    func_02009cc0(3);
    temp_r0       = func_02009cfc(0, 0);
    temp_r0_2     = func_0202e6ac(temp_r0, 0, 0x10);
    data_020e8358 = temp_r0_2;
    func_02009cfc(temp_r0_2, temp_r0);
}
