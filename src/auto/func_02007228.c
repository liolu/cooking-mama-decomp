/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02006194();                                /* extern */
M2C_UNK func_020061a8(s32);                         /* extern */
M2C_UNK func_0200790c(M2C_UNK);                     /* extern */

void func_02007228(s32 arg0, M2C_UNK arg1) {
    s32 temp_r4;

    temp_r4 = func_02006194();
    func_0200790c(arg1);
    func_020061a8(temp_r4);
}
