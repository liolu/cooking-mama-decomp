#include "m2c.h"

s32 func_02016228(s32, s32);                        /* extern */
extern void *data_0211372c;

s32 func_0206cb6c(void) {
    void *temp_r4;

    temp_r4 = data_0211372c;
    if (M2C_FIELD(temp_r4, s32 *, 0x2C) ==
        func_02016228(*M2C_FIELD(temp_r4, s32 **, 0x28) * 0xF0, M2C_FIELD(temp_r4, s32 *, 0x30))) {
        return 1;
    }
    return 0;
}
