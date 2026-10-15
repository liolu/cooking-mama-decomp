#include "m2c.h"

extern M2C_UNK data_02114500;

void func_02073c10(s32 arg0, s32 arg1) {
    *((M2C_UNK *) ((s8 *) &data_02114500 + (arg0 * 0x24))) = arg1;
}
