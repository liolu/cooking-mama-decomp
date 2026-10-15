#include "m2c.h"

extern s32 data_020c556c;

void func_0200e320(s32 arg0, s32 arg1) {
    M2C_FIELD((data_020c556c + (arg0 * 4)), s32 *, 0x18) = arg1;
}
