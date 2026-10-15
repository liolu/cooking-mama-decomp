/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02011c4c(M2C_UNK, M2C_UNK, s32);       /* extern */
M2C_UNK func_02014bc0(s8 *, s32);                   /* extern */
extern s32 data_020c613c;

void func_020100d4(s8 arg0, M2C_UNK arg1) {
    s8 sp0;

    sp0 = arg0;
    func_02014bc0(&sp0, data_020c613c);
    func_02011c4c(6, arg1, data_020c613c);
}
