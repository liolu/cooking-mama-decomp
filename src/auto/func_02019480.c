/* compiler: 2.0/sp1p5 -O4,s */
#include "m2c.h"

s32 func_0202f7e0();                                /* extern */

s32 func_02019480(s32 arg0) {
    s32 temp_r0;
    s32 var_r2;

    temp_r0 = func_0202f7e0();
    var_r2  = 0;
loop_1:
    if (arg0 == M2C_FIELD((temp_r0 + (var_r2 * 2)), u8 *, 0xC)) {
        return var_r2;
    }
    var_r2 += 1;
    if (var_r2 >= 0x51) {
        return 0;
    }
    goto loop_1;
}
