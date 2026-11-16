/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s16 func_02016228(s32, s16);                        /* extern */
extern s16 data_0210c8e4;
extern s16 data_0210c8e8;
extern M2C_UNK data_0210c900;

void func_0203830c(s16 arg0) {
    data_0210c8e8                                                 = arg0;
    M2C_FIELD(M2C_FIELD(&data_0210c900, void **, 4), s16 *, 0x10) = func_02016228(arg0 << 0x10, data_0210c8e4);
}
