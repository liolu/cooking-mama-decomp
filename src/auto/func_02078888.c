#include "m2c.h"

s32 func_02078888(s32 arg0, s32 arg1) {
    s32 v1;
    v1 = *(s32 *) (arg0 + (arg1 << 2));
    if (v1 != -1) {
        return 1;
    }
    return 0;
}
