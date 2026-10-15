#include "m2c.h"

s32 func_0201e140();                                /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
M2C_UNK **func_0202f368();                          /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_0206dd48(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK func_02060390;

void func_020606c8(void) {
    M2C_UNK **temp_r4;

    temp_r4 = func_0202f368();
    if (func_0201e140() != 0) {
        return;
    }
    func_02038384(1);
    func_0202ec14(0x2D);
    func_0206dd48(0x80, 0x60);
    *temp_r4 = &func_02060390;
}
