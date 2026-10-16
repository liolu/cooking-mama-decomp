#include "m2c.h"

void func_020788b0(s32 arg0) {
    s32 i  = 0;
    u32 *p = (u32 *) arg0;
    do {
        p[i] = -1U;
        ++i;
    } while (i < 3);
}
