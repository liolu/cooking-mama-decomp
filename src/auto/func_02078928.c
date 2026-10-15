/* compiler: 1.2/sp2p3  */
#include "m2c.h"

void func_02078928(void *arg0, s16 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0) == 1) {
        M2C_FIELD(arg0, u16 *, 0x12) = (u16) (M2C_FIELD(arg0, u16 *, 0x12) | 4);
        M2C_FIELD(arg0, s16 *, 0x10) = arg1;
    }
}
