/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020195ac(s32);                           /* extern */
void *func_020197fc();                              /* extern */

void func_02019bc8(void) {
    s32 temp_r1;
    void *temp_r0;

    temp_r0                           = func_020197fc();
    M2C_FIELD(temp_r0, s32 *, 0x10)   = (s32) M2C_FIELD((temp_r0 + (M2C_FIELD(temp_r0, s16 *, 0x38) * 8)), s32 *, 0x3C);
    M2C_FIELD(temp_r0, void **, 0x28) = func_020195ac(M2C_FIELD(temp_r0, s32 *, 0x10));
    M2C_FIELD(temp_r0, s16 *, 0x14)   = (s16) M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x28), s16 *, 0xC);
    if (M2C_FIELD(temp_r0, s16 *, 0x16) != 1) {
        return;
    }
    temp_r1 = M2C_FIELD((M2C_FIELD(temp_r0, s32 *, 0x24) + (M2C_FIELD(temp_r0, s16 *, 0x20) * 4)), s32 *, 0x18);
    if (temp_r1 > 0x129) {
        M2C_FIELD(temp_r0, s16 *, 0x1E) = (s16) (temp_r1 - 0x129);
    }
}
