#include "m2c.h"

s32 func_0202add4(void *arg0, void *arg1) {
    if (((s32) M2C_FIELD(arg0, s16 *, 0) <= (s32) M2C_FIELD(arg1, s16 *, 4)) &&
        ((s32) M2C_FIELD(arg0, s16 *, 4) >= (s32) M2C_FIELD(arg1, s16 *, 0)) &&
        ((s32) M2C_FIELD(arg0, s16 *, 2) <= (s32) M2C_FIELD(arg1, s16 *, 6)) &&
        ((s32) M2C_FIELD(arg0, s16 *, 6) >= (s32) M2C_FIELD(arg1, s16 *, 2))) {
        return 1;
    }
    return 0;
}
