#include "m2c.h"

void *func_0202f7e0();                              /* extern */

s32 func_020193bc(s32 arg0) {
    s32 var_r2;
    void *var_r0;

    var_r0 = func_0202f7e0();
    var_r2 = 0;
loop_1:
    if (arg0 == M2C_FIELD(var_r0, u8 *, 0xAE)) {
        return var_r2;
    }
    var_r2 += 1;
    var_r0 += 3;
    if (var_r2 >= 0x1E) {
        return 0;
    }
    goto loop_1;
}
