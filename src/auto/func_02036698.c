#include "m2c.h"

s32 func_0201e140();                                /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
M2C_UNK **func_0202f368();                          /* extern */
extern s32 *data_0210bc74;
extern M2C_UNK func_020352f4;

void func_02036698(void) {
    M2C_UNK **temp_r4;

    temp_r4 = func_0202f368();
    if (func_0201e140() != 0) {
        return;
    }
    if (*data_0210bc74 == 1) {
        func_0202ec14(0x28);
    }
    *temp_r4 = &func_020352f4;
}
