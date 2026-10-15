/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0200e0f4();                                /* extern */
s32 func_0200e1f4(M2C_UNK, M2C_UNK, s32);           /* extern */
M2C_UNK func_0200e320(M2C_UNK, M2C_UNK);            /* extern */

s32 func_0200f82c(M2C_UNK arg0, s32 arg1) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_0200e0f4();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    if ((arg1 != 0) && (arg1 != 1)) {
        return 6;
    }
    func_0200e320(0x19, arg0);
    var_r0 = func_0200e1f4(0x19, 1, arg1);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}
