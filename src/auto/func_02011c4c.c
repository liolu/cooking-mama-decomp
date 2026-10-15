/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02005850(M2C_UNK, s32);                /* extern */
M2C_UNK func_02005874();                            /* extern */
M2C_UNK func_0201266c(M2C_UNK, s32, M2C_UNK);       /* extern */

void func_02011c4c(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_02005850(arg2, (arg0 + 0x1F) & ~0x1F);
    func_02005874();
    func_0201266c(arg2, arg0, arg1);
}
