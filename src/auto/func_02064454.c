/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
s32 func_0202ac30(s32, M2C_UNK);                    /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0206dd6c(M2C_UNK, M2C_UNK);            /* extern */

void func_02064454(void) {
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, u16 *, 0x70) == 0) {
        func_0206dd6c(0xC0, 0x30);
        M2C_FIELD(temp_r0, u16 *, 0x70) = 1U;
    }
    if (func_0202ac30(M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s32 *, 0x1C), 0) == 0) {
        return;
    }
    func_0202ec14(0xB);
    M2C_FIELD(temp_r0, u16 *, 0x70) = 0U;
    if (M2C_FIELD(func_020197fc(), s16 *, 0x16) != 4) {
        M2C_FIELD(M2C_FIELD((temp_r0 + (M2C_FIELD(temp_r0, s32 *, 0x60) * 4)), void **, 0x1C), s32 *, 0x24) = 1;
    }
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s16 *, 0x1A) = 0x1F;
    M2C_FIELD(temp_r0, s32 *, 0x64)                           = 1;
}
