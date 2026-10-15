#include "m2c.h"

M2C_UNK func_0200c6f4(u16);                         /* extern */
M2C_UNK func_0200c704(u16);                         /* extern */
M2C_UNK func_0200c754();                            /* extern */
s32 func_0200cddc(M2C_UNK, s32, s32, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
s32 func_0202f768();                                /* extern */
s32 func_0202f7ec();                                /* extern */
extern u16 data_02100c94;

s32 func_0202f0c4(void) {
    s32 temp_r4;
    s32 var_r5;

    var_r5 = 0;
    func_0200c704(data_02100c94);
    temp_r4 = func_0202f768();
    if (func_0200cddc(0, func_0202f7ec(), temp_r4, 0, 0, 0, 6, 1, 0) == 0) {
        func_0200c754();
        var_r5 = 1;
    }
    func_0200c6f4(data_02100c94);
    return var_r5;
}
