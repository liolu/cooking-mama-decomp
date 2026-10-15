#include "m2c.h"

s32 func_0202ac30(s32, M2C_UNK);                    /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0206dd6c(M2C_UNK, M2C_UNK);            /* extern */

void func_020667c8(void) {
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, u16 *, 0x46) == 0) {
        func_0206dd6c(0xC0, 0x30);
        M2C_FIELD(temp_r0, u16 *, 0x46) = 1U;
    }
    if (func_0202ac30(M2C_FIELD(M2C_FIELD((temp_r0 + (M2C_FIELD(temp_r0, s32 *, 0x38) * 4)), void **, 0x1C), s32 *, 0x1C),
                      0) == 0) {
        return;
    }
    func_0202ec14(0xB);
    M2C_FIELD(temp_r0, u16 *, 0x46)                                                                     = 0U;
    M2C_FIELD(M2C_FIELD((temp_r0 + (M2C_FIELD(temp_r0, s32 *, 0x38) * 4)), void **, 0x1C), s32 *, 0x24) = 1;
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x30), s16 *, 0x1A)                                           = 0x1F;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x3C) + 1);
}
