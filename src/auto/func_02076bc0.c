#include "m2c.h"

s32 func_02076bc0(void *arg0, u32 arg1) {
    if ((u32) M2C_FIELD(arg0, u16 *, 0) > arg1) {
        return M2C_FIELD(arg0, s32 *, 4) + (arg1 * 0x10);
    }
    return 0;
}
