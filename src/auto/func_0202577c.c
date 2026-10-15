#include "m2c.h"

void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
extern s32 data_020d4598;
extern s32 data_020d459c;
extern M2C_UNK func_0202544c;

void func_0202577c(void) {
    s32 var_r6;

    if (data_020d4598 != 0) {
        return;
    }
    if (data_020d459c == 1) {
        return;
    }
    var_r6 = 0;
    do {
        M2C_FIELD(func_0202f564(&func_0202544c, 0x20), s32 *, 0x24) = var_r6;
        var_r6 += 1;
    } while (var_r6 < 2);
}
