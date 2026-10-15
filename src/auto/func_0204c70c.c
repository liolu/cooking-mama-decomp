#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0204c3d0();                            /* extern */
M2C_UNK func_0204c548();                            /* extern */
extern M2C_UNK func_0204c6dc;

void func_0204c70c(void) {
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x24) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x28) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x34) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x2C) = 0;
    func_0204c548();
    func_0204c3d0();
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_0204c6dc;
}
