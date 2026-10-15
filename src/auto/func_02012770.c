/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0200f330(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_0201256c(M2C_UNK, s32);                /* extern */

s32 func_02012770(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, u16 arg4) {
    s32 temp_r0;

    temp_r0 = func_0200f330(arg0, 0, arg1, arg2, (s32) arg4, 1, 3);
    func_0201256c(0xF, temp_r0);
    return temp_r0;
}
