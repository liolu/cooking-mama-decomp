/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_020197fc();                            /* extern */
void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
extern M2C_UNK func_0201ba0c;

void func_0201bdf0(void) {
    s32 var_r6;

    func_020197fc();
    var_r6 = 0;
    do {
        M2C_FIELD(func_0202f564(&func_0201ba0c, 0x10), s32 *, 0x24) = var_r6;
        var_r6 += 1;
    } while (var_r6 < 2);
}
