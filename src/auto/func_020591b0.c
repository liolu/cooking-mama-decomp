/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */
extern M2C_UNK func_02059084;
extern M2C_UNK func_020590d4;

void func_020591b0(void) {
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x2C) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x2C) + 1);
    if (M2C_FIELD(temp_r0, s32 *, 0x2C) != 8) {
        return;
    }
    M2C_FIELD(temp_r0, s32 *, 0x2C) = 0;
    if (M2C_FIELD(temp_r0, s32 *, 0x30) == 1) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_02059084;
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_020590d4;
}
