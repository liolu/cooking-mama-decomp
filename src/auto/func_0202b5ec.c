/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0202b5ec(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x20) == 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, u16 *, 0x1A) == 0) {
        return 0;
    }
    if ((M2C_FIELD(arg0, u16 *, 0xC) == 0) || (M2C_FIELD(arg0, u16 *, 0xE) == 0)) {
        return 0;
    }
    return 1;
}
