#include "engine.h"
#include "m2c.h"

void func_02000f2c(M2C_UNK, M2C_UNK);

extern s8 data_020e8350;

void func_0202cbd8(s32 arg0) {
    data_020e8350 = (s8) arg0;
    func_02000f2c(0x0400106C, arg0);
}
