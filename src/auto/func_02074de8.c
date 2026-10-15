/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02006e10(s32, s32);                    /* extern */
M2C_UNK func_02074e1c(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_02074de8(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    func_02074e1c(arg0, arg2, arg3);
    func_02006e10(arg0, arg0 + arg1);
}
