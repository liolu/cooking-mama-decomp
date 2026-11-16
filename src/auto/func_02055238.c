/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */
s32 func_02038374();                                /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_020550dc();                            /* extern */
extern M2C_UNK func_020551b8;

void func_02055238(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_020550dc();
    if ((func_02038374() != 2) && (M2C_FIELD(temp_r4, s32 *, 0x5C) != 0x30)) {
        return;
    }
    func_02038384(0);
    M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_020551b8;
}
