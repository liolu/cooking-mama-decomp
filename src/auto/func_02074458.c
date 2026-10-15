#include "m2c.h"

extern s32 data_02114a68;

s32 func_02074458(s32 arg0) {
    s32 temp_r2;

    temp_r2       = data_02114a68;
    data_02114a68 = arg0;
    return temp_r2;
}
