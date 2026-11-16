/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */
void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
extern M2C_UNK func_0206ac34;

void func_0206b464(void) {
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, s32 *, 0x34) == 0) {
        M2C_FIELD(func_0202f564(&func_0206ac34, 0x11), void **, 0x20) = temp_r0;
        M2C_FIELD(temp_r0, s32 *, 0x34)                               = 1;
    }
    if (M2C_FIELD(temp_r0, s32 *, 0x2C) != 0) {
        M2C_FIELD(temp_r0, s32 *, 0x2C) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x34) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x28) = 1;
    }
}
