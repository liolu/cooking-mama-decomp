/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */

void func_02059084(void) {
    s32 temp_r1;
    s32 temp_r3;
    void *temp_r0;

    temp_r0 = func_0202f368();
    temp_r1 = M2C_FIELD(temp_r0, s32 *, 0x2C);
    if (temp_r1 == 0x20) {
        return;
    }
    M2C_FIELD(temp_r0, s32 *, 0x2C) = (s32) (temp_r1 + 1);
    temp_r3                         = M2C_FIELD(temp_r0, s32 *, 0x2C) * 0x1F;
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 0x1A) =
        (s16) (0x1F - ((s32) (temp_r3 + ((u32) (temp_r3 >> 4) >> 0x1B)) >> 5));
}
