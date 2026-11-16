/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_0202ac30(s32, M2C_UNK);                    /* extern */
M2C_UNK func_0202b1a0(void *);                      /* extern */
void *func_0202f368();                              /* extern */

void func_0206c3d4(void) {
    s32 temp_r1;
    void *temp_r0;

    temp_r0 = func_0202f368();
    temp_r1 = M2C_FIELD(temp_r0, s32 *, 0x28);
    if ((u32) (temp_r1 - 2) <= 1U) {
        if (M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x20), s32 *, 0x48) != 2) {
            return;
        }
        goto block_5;
    }
    if (M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x20), s32 *, 0x48) != temp_r1) {
        return;
    }
block_5:
    if (M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x20), s32 *, 0x4C) != 0) {
        return;
    }
    if (func_0202ac30(M2C_FIELD(temp_r0, s32 *, 0x1C), 0) == 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x20), s32 *, 0x4C) = (s32) M2C_FIELD(temp_r0, s32 *, 0x28);
    func_0202b1a0(temp_r0 + 0x1C);
    M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
}
