#include "m2c.h"

void func_020057c8(void *arg0) {
    M2C_FIELD(arg0, volatile s32 *, 4)   = 0;
    M2C_FIELD(arg0, volatile s32 *, 0)   = (s32) M2C_FIELD(arg0, volatile s32 *, 4);
    M2C_FIELD(arg0, volatile s32 *, 8)   = 0;
    M2C_FIELD(arg0, volatile s32 *, 0xC) = 0;
}
