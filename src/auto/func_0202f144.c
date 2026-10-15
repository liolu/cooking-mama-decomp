#include "m2c.h"

M2C_UNK func_0200c6f4(u16);                         /* extern */
M2C_UNK func_0200c704(u16);                         /* extern */
s32 func_0200c754();                                /* extern */
M2C_UNK func_0200cc88();                            /* extern */
M2C_UNK func_0200cddc(s32, M2C_UNK, s32, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
s32 func_0202f768();                                /* extern */
s32 func_0202f7ec();                                /* extern */
extern u16 data_02100c94;

s32 func_0202f144(void) {
    s32 temp_r5;
    s32 var_r4;

    var_r4 = 0;
    func_0200c704(data_02100c94);
    temp_r5 = func_0202f768();
    func_0200cddc(func_0202f7ec(), 0, temp_r5, 0, 0, 1, 8, 0xA, 2);
    func_0200cc88();
    if (func_0200c754() != 0) {
        var_r4 = 1;
    }
    func_0200c6f4(data_02100c94);
    return var_r4;
}
