#include "m2c.h"

s32 func_0201e140();                                /* extern */
M2C_UNK **func_0202f368();                          /* extern */
extern M2C_UNK func_020722b8;

void func_02072578(void) {
    M2C_UNK **temp_r4;

    temp_r4 = func_0202f368();
    if (func_0201e140() == 0) {
        *temp_r4 = &func_020722b8;
    }
}
