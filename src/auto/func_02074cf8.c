/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02006db8(s32, s32);                    /* extern */
s32 func_02007b1c(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_02007b64(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

void func_02074cf8(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    if (arg0 == func_02007b1c(arg2, arg3)) {
        func_02007b64(arg2, arg3, 0);
    }
    func_02006db8(arg0, arg0 + arg1);
}
