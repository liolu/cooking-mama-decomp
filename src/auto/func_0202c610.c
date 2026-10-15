/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0202c610(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x1C) == 0) {
        return 0;
    }
    if ((M2C_FIELD(arg0, u16 *, 0x10) == 0) || (M2C_FIELD(arg0, u16 *, 0x12) == 0)) {
        return 0;
    }
    return 1;
}
