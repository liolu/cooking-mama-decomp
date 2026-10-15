#include "m2c.h"

void *func_020197fc();                              /* extern */
s32 func_020537a0(s32);                             /* extern */
M2C_UNK func_020537dc(s32, s32, M2C_UNK);           /* extern */

s32 func_02019338(void *arg0) {
    s32 *temp_r5;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;

    temp_r5 = M2C_FIELD(func_020197fc(), s32 **, 0x24);
    if (temp_r5 == NULL) {
        return 0;
    }
    temp_r4 = M2C_FIELD(arg0, volatile s32 *, 4);
    func_020537dc(temp_r4 + (func_020537a0(temp_r4) - 9), *temp_r5, 3);
    temp_r4_2 = M2C_FIELD(arg0, volatile s32 *, 8);
    func_020537dc(temp_r4_2 + (func_020537a0(temp_r4_2) - 9), *temp_r5, 3);
    temp_r4_3 = M2C_FIELD(arg0, volatile s32 *, 0xC);
    func_020537dc(temp_r4_3 + (func_020537a0(temp_r4_3) - 9), *temp_r5, 3);
    return 1;
}
