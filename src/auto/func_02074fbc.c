/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02074100(M2C_UNK, s32);                /* extern */
s32 func_0207411c();                                /* extern */
s32 func_02074448();                                /* extern */
s32 func_020751ac(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32); /* extern */
extern M2C_UNK func_02074d70;

s32 func_02074fbc(M2C_UNK arg0, s32 arg1, s32 arg2) {
    s32 var_r2;
    s32 var_r4;

    var_r4 = func_0207411c();
    if (var_r4 == 0) {
        if (arg2 == 0) {
            var_r2 = 0;
        } else {
            var_r2 = func_02074448();
        }
        var_r4 = func_020751ac(arg0, &func_02074d70, var_r2, arg0, arg1);
        if ((arg2 != 0) && (var_r4 != 0)) {
            func_02074100(arg0, var_r4);
        }
    }
    return var_r4;
}
