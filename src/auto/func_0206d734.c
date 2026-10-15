#include "m2c.h"

s32 func_0201e140();                                /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK func_0206d6a4;

void func_0206d734(void) {
    s32 temp_r0;
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (func_0201e140() != 0) {
        return;
    }
    temp_r0 = M2C_FIELD(temp_r4, s32 *, 0x24);
    if (temp_r0 > 0) {
        M2C_FIELD(temp_r4, s32 *, 0x24) = (s32) (temp_r0 - 1);
        return;
    }
    M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_0206d6a4;
}
