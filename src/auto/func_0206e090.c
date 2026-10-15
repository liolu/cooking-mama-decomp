#include "m2c.h"

s32 func_0202cab4();                                /* extern */
M2C_UNK **func_0202f368();                          /* extern */
extern M2C_UNK func_0206df94;

void func_0206e090(void) {
    M2C_UNK **temp_r4;

    temp_r4 = func_0202f368();
    if (func_0202cab4() == 0) {
        *temp_r4 = &func_0206df94;
    }
}
