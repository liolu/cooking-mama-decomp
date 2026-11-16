/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */
void *func_0206e770();                              /* extern */

void func_02051b04(void) {
    s16 temp_r2;
    s16 temp_r3;
    u16 temp_r0_2;
    void *temp_r0;
    void *temp_r4;

    temp_r4   = func_0202f368();
    temp_r0   = func_0206e770();
    temp_r3   = M2C_FIELD(temp_r0, u16 *, 2) - M2C_FIELD(temp_r4, s16 *, 0x34);
    temp_r2   = (M2C_FIELD(temp_r0, u16 *, 0) - 0x10) - M2C_FIELD(temp_r4, s16 *, 0x32);
    temp_r0_2 = (temp_r2 * temp_r2) + (temp_r3 * temp_r3);
    if ((u32) M2C_FIELD(temp_r4, u16 *, 0x36) < (u32) temp_r0_2) {
        M2C_FIELD(temp_r4, u16 *, 0x36) = temp_r0_2;
    }
    M2C_FIELD(temp_r4, s32 *, 0x28) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x28) + 1);
    if ((s32) M2C_FIELD(temp_r4, s32 *, 0x28) >= 5) {
        M2C_FIELD(temp_r4, s32 *, 0x24) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x24) ^ 0x10);
    }
}
