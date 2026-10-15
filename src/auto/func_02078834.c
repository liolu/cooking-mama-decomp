#include "m2c.h"

s32 func_02078834(s32 arg0, s32 arg1) {
    if (M2C_FIELD((arg0 + (arg1 * 4)), s32 *, 8) != -1) {
        return 1;
    }
    return 0;
}
