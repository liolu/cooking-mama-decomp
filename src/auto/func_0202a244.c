#include "m2c.h"

void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
extern s32 data_020d4eec;
extern s32 data_020d4ef8;
extern M2C_UNK func_02029f20;

void func_0202a244(void) {
    s32 var_r6;

    if (data_020d4ef8 != 0) {
        return;
    }
    if ((s32) data_020d4eec <= 1) {
        return;
    }
    var_r6 = 0;
    do {
        M2C_FIELD(func_0202f564(&func_02029f20, 0x20), s32 *, 0x24) = var_r6;
        var_r6 += 1;
    } while (var_r6 < 2);
}
