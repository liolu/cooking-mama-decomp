#include "m2c.h"

extern s32 data_02114084;

void func_020731c4(s32 arg0) {
    data_02114084 &= ~(1 << arg0);
}
