/* compiler: 1.2/sp2p3  */
#include "m2c.h"

void *func_0207a390();                              /* extern */

void func_0207a360(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_r0;

    temp_r0                         = func_0207a390();
    M2C_FIELD(temp_r0, s32 *, 0x24) = -1;
    M2C_FIELD(temp_r0, s32 *, 0x28) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x2C) = arg2;
}
