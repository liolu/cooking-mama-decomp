/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02006194();                                /* extern */
M2C_UNK func_020061a8(s32);                         /* extern */
s32 func_0200e150();                                /* extern */
void *func_0200e16c();                              /* extern */

s32 func_0200ebac(s32 arg0) {
    s32 temp_r0;
    s32 temp_r5;

    temp_r5 = func_02006194();
    temp_r0 = func_0200e150();
    if (temp_r0 != 0) {
        func_020061a8(temp_r5);
        return temp_r0;
    }
    M2C_FIELD(func_0200e16c(), s32 *, 0xC8) = arg0;
    func_020061a8(temp_r5);
    return 0;
}
