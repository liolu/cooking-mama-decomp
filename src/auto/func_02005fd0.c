#include "m2c.h"

extern u16 data_020c2f00;

void func_02005fd0(s32 arg0) {
    data_020c2f00 |= 1 << arg0;
}
