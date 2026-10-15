#include "m2c.h"

extern M2C_UNK data_020e835c;

s32 func_0202cc38(s32 arg0) {
    M2C_UNK *var_r2;
    s32 var_r3;

    var_r2 = &data_020e835c;
    var_r3 = 0;
loop_1:
    if (M2C_FIELD(var_r2, s32 *, 4) == arg0) {
        return var_r3;
    }
    var_r3 += 1;
    var_r2 = (M2C_UNK *) ((s8 *) var_r2 + 0x50);
    if (var_r3 >= 0x28) {
        return -1;
    }
    goto loop_1;
}
