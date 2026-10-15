/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0200e0f4();                                /* extern */
s32 func_0200e1f4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_0200e320(M2C_UNK, M2C_UNK);            /* extern */

s32 func_0200f7c0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, u16 arg4) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_0200e0f4();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_0200e320(0x1D, arg0);
    var_r0 = func_0200e1f4(0x1D, 4, arg1, arg2, arg3, (s32) arg4);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}
