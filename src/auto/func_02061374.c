#include "m2c.h"

M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
s32 func_02038374();                                /* extern */
extern M2C_UNK func_020612c8;

void func_02061374(void) {
    void *temp_r1;
    void *temp_r2;
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (func_02038374() == 0) {
        return;
    }
    temp_r1 = M2C_FIELD(temp_r4, void **, 0x24);
    if (M2C_FIELD(temp_r1, s32 *, 0x2C) != 0) {
        return;
    }
    if (M2C_FIELD(temp_r1, s32 *, 0x48) == 1) {
        func_0202ec14(0x1B);
        M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x24), s32 *, 0x48) = 2;
    }
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0xA) = 0x14;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 0xA) = 0x15;
    temp_r2                                                  = M2C_FIELD(temp_r4, void **, 0x24);
    M2C_FIELD(temp_r2, s32 *, 0x3C)                          = (s32) (M2C_FIELD(temp_r2, s32 *, 0x3C) - 0xA);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)                        = &func_020612c8;
}
