#include "m2c.h"

extern void *data_02114a68;

void func_02074100(s32 arg0, s32 arg1) {
    M2C_FIELD((M2C_FIELD(data_02114a68, s32 *, 0x84) + (arg0 * 0x10)), s32 *, 0x14) = arg1;
}
