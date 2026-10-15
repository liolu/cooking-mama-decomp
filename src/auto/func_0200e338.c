/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02008170(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_0200dc4c();                            /* extern */
s32 func_0200e04c(M2C_UNK, M2C_UNK);                /* extern */
s32 func_0200e150();                                /* extern */
extern s16 data_020c5568;
extern s32 data_020c556c;

s32 func_0200e338(void) {
    s32 temp_r0;

    if (func_0200e150() != 0) {
        return 3;
    }
    temp_r0 = func_0200e04c(1, 0);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_0200dc4c();
    func_02008170(0xA, 0);
    data_020c556c = 0;
    data_020c5568 = 0;
    return 0;
}
