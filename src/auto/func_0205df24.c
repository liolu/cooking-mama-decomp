/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */

void func_0205df24(void) {
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, s32 *, 0x24) == 1) {
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 0x1A) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x24)                           = 0;
    }
}
