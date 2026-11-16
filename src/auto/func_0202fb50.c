/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
extern M2C_UNK func_0202f934;

void func_0202fb50(void) {
    s32 var_r7;
    void *temp_r0;

    var_r7 = 0;
    do {
        temp_r0                         = func_0202f564(&func_0202f934, 0x10);
        M2C_FIELD(temp_r0, s32 *, 0x24) = var_r7;
        var_r7 += 1;
        M2C_FIELD(temp_r0, s32 *, 0x28) = 0xA;
    } while (var_r7 < 0xA);
}
