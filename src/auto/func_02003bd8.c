/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02006194();                                /* extern */
M2C_UNK func_020061a8(s32);                         /* extern */
s32 func_020061c0();                                /* extern */
M2C_UNK func_020061d4(s32);                         /* extern */
s32 func_02006c14(s16, void *);                     /* extern */

s32 func_02003bd8(s16 arg0, void *arg1, M2C_UNK (*arg2)(), s32 arg3) {
    s32 temp_r0;
    s32 var_r5;

    if (arg3 != 0) {
        var_r5 = func_020061c0();
    } else {
        var_r5 = func_02006194();
    }
    temp_r0 = func_02006c14(arg0, arg1);
    if (temp_r0 == 0) {
        if (arg2 != NULL) {
            arg2();
        }
        M2C_FIELD(arg1, s16 *, 4) = arg0;
    }
    if (arg3 != 0) {
        func_020061d4(var_r5);
    } else {
        func_020061a8(var_r5);
    }
    return temp_r0;
}
