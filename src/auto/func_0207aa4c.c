/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0207ad98(M2C_UNK, s32);                /* extern */
M2C_UNK func_0207ae64(M2C_UNK, s32, s32);           /* extern */
M2C_UNK func_0207af10(M2C_UNK, s32, s32, s32);      /* extern */

void func_0207aa4c(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    if ((arg3 != 0) && (arg1 != 0)) {
        func_0207af10(arg0, arg3, arg1, arg5);
    }
    if (arg2 != 0) {
        func_0207ae64(arg0, arg2, arg4);
    }
    if (arg1 == 0) {
        return;
    }
    func_0207ad98(arg0, arg1);
}
