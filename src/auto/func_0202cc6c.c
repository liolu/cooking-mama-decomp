#include "m2c.h"

extern s32 data_020e835c;

s32 func_0202cc6c(void) {
    s32 *var_r2;
    s32 var_r0;

    var_r2 = &data_020e835c;
    var_r0 = 0;
loop_1:
    if (*var_r2 == 0) {
        return var_r0;
    }
    var_r0 += 1;
    var_r2 = (s32 *) ((s8 *) var_r2 + 0x50);
    if (var_r0 >= 0x28) {
        return -1;
    }
    goto loop_1;
}
