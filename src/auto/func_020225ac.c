/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
s32 func_0201e140();                                /* extern */
M2C_UNK func_0202f318(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
s32 func_02038374();                                /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
s32 func_0206e37c(M2C_UNK);                         /* extern */
extern M2C_UNK func_020222d8;

void func_020225ac(void) {
    void *temp_r4;
    void *temp_r5;

    temp_r5 = func_0202f368();
    temp_r4 = func_020197fc();
    if (func_0206e37c(1) != 8) {
        return;
    }
    if (M2C_FIELD(temp_r4, s16 *, 0x1A) != 1) {
        return;
    }
    if (func_0201e140() != 0) {
        return;
    }
    M2C_FIELD(temp_r5, s32 *, 0x2C) = func_02038374();
    func_02038384(0);
    func_0202f318(1);
    M2C_FIELD(temp_r5, s32 *, 0x20)   = 0;
    M2C_FIELD(temp_r5, M2C_UNK **, 0) = &func_020222d8;
}
