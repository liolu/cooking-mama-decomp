/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */

s32 func_02057ae0(void) {
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x80) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x80) + 1);
    if (M2C_FIELD(temp_r0, s32 *, 0x80) == 0x1E) {
        M2C_FIELD(temp_r0, s32 *, 0x80) = 0;
        M2C_FIELD(temp_r0, s16 *, 0x6C) = 0;
    }
    return 0;
}
