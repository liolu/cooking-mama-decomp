/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_02044c4c(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s16 temp_ip;
    s16 temp_r0;
    s32 temp_r2;

    temp_r2 = arg2 + arg3;
    temp_ip = M2C_FIELD(arg0, s16 *, 8) - M2C_FIELD(arg1, s16 *, 8);
    temp_r0 = M2C_FIELD(arg0, s16 *, 6) - M2C_FIELD(arg1, s16 *, 6);
    if ((s32) ((temp_r0 * temp_r0) + (temp_ip * temp_ip)) <= (s32) (temp_r2 * temp_r2)) {
        return 1;
    }
    return 0;
}
