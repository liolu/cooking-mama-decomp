#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_020537c4(void *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK func_0203a6f4;

void func_0203aba0(void) {
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x24) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x28) = 0;
    func_020537c4(temp_r0 + 0x32, 0, 0x12);
    func_020537c4(temp_r0 + 0x44, 0, 0x10);
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_0203a6f4;
}
