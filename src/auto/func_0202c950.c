/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_02000f2c(s32, s8);                     /* extern */
M2C_UNK func_0202ad64(s8 *, M2C_UNK, M2C_UNK);      /* extern */
s32 func_0202cab4();                                /* extern */
extern s8 data_020e834c;
extern s8 data_020e8350;

s8 func_0202c950(s32 arg0) {
    s8 var_r5;

    var_r5 = data_020e834c;
    if (func_0202cab4() == 0) {
        if (arg0 & 1) {
            if ((s32) data_020e834c > 0) {
                data_020e834c -= 1;
            }
            func_0202ad64(&data_020e834c, -0x10, 0x10);
            func_02000f2c(0x0400006C, data_020e834c);
            var_r5 = data_020e834c;
        }
        if (arg0 & 2) {
            if ((s32) data_020e8350 > 0) {
                data_020e8350 -= 1;
            }
            func_0202ad64(&data_020e8350, -0x10, 0x10);
            func_02000f2c(0x0400106C, data_020e8350);
            var_r5 = data_020e8350;
        }
    }
    return var_r5;
}
