#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_02038394(s16);                         /* extern */
M2C_UNK func_0204ec4c();                            /* extern */
M2C_UNK func_0204f2b8();                            /* extern */
extern M2C_UNK func_02038288;
extern M2C_UNK func_0204f3a4;

void func_0204f3d4(void) {
    s16 var_r0;
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s16 *, 0x32) = 2;
    if (M2C_FIELD(temp_r0, s16 *, 0x30) == 0) {
        var_r0 = 0x48;
    } else {
        var_r0 = 0x28;
    }
    M2C_FIELD(temp_r0, s16 *, 0x42) = var_r0;
    func_0204f2b8();
    func_0204ec4c();
    M2C_FIELD(temp_r0, s16 *, 0x34) = 0x3E8;
    func_0202f564(&func_02038288, 0x15);
    func_02038384(0);
    func_02038394(M2C_FIELD(temp_r0, s16 *, 0x34));
    M2C_FIELD(temp_r0, s16 *, 0x28)   = -1;
    M2C_FIELD(temp_r0, s16 *, 0x2C)   = 0;
    M2C_FIELD(temp_r0, s16 *, 0x2E)   = 0;
    M2C_FIELD(temp_r0, s16 *, 0x36)   = 0;
    M2C_FIELD(temp_r0, s16 *, 0x3C)   = 0;
    M2C_FIELD(temp_r0, s16 *, 0x3E)   = 0;
    M2C_FIELD(temp_r0, s16 *, 0x40)   = 0;
    M2C_FIELD(temp_r0, s32 *, 0x48)   = 0;
    M2C_FIELD(temp_r0, s32 *, 0x44)   = 0;
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_0204f3a4;
}
