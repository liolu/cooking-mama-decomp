#include "m2c.h"

M2C_UNK func_020537c4(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_0202c5e4(s32 *arg0) {
    s32 temp_r0;

    temp_r0 = *arg0;
    if (temp_r0 == 0) {
        return;
    }
    func_020537c4(temp_r0, 0, 0x28);
    *arg0 = 0;
}
