/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02005564(M2C_UNK *, s32, M2C_UNK);     /* extern */
M2C_UNK func_02005834(s32, M2C_UNK);                /* extern */
M2C_UNK func_02006ae4(M2C_UNK, s32, M2C_UNK);       /* extern */
s32 func_02008094(M2C_UNK, s32, M2C_UNK);           /* extern */
s32 func_0200e2ac();                                /* extern */
extern M2C_UNK data_020c5570;

s32 func_0200e17c(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r0;
    s32 temp_r4;

    temp_r0 = func_0200e2ac();
    if (temp_r0 == 0) {
        return 8;
    }
    func_02006ae4(arg0, temp_r0, arg1);
    func_02005834(temp_r0, arg1);
    temp_r4 = func_02008094(0xA, temp_r0, 0);
    func_02005564(&data_020c5570, temp_r0, 1);
    if (temp_r4 < 0) {
        return 8;
    }
    return 2;
}
