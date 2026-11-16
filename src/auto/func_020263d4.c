/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_020193f4();                                /* extern */
s32 func_0201943c();                                /* extern */
s32 func_020194b8();                                /* extern */
M2C_UNK func_0201955c(M2C_UNK);                     /* extern */
M2C_UNK func_02019758(M2C_UNK);                     /* extern */
M2C_UNK func_0202f7e0();                            /* extern */

s32 func_020263d4(void) {
    s32 temp_r4;
    s32 var_r5;

    var_r5 = 0;
    func_020193f4();
    func_02019758(0);
    func_0202f7e0();
    func_0202f7e0();
    func_0201955c(0);
    if (func_020194b8() == 0x4C) {
        var_r5 = 1;
    }
    temp_r4 = func_0201943c();
    if (temp_r4 == func_020193f4()) {
        var_r5 += 2;
    }
    return var_r5;
}
