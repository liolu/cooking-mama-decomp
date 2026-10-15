/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020049cc();                            /* extern */
s32 func_02006194();                                /* extern */
M2C_UNK func_020061a8(s32);                         /* extern */

void func_02004ae4(void *arg0) {
    s32 temp_r4;

    temp_r4                      = func_02006194();
    M2C_FIELD(arg0, s32 *, 0x64) = 1;
    func_020049cc();
    func_020061a8(temp_r4);
}
