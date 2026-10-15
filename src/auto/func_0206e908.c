#include "m2c.h"

M2C_UNK func_02006440();                            /* extern */
M2C_UNK func_0200a714(M2C_UNK *);                   /* extern */
s32 func_0200a85c(M2C_UNK *);                       /* extern */
M2C_UNK func_0200a908();                            /* extern */
extern s8 data_02113994;

void func_0206e908(void) {
    u8 sp0[12];

    func_0200a908();
    if (func_0200a85c(sp0) == 0) {
        func_02006440();
    } else {
        func_0200a714(sp0);
    }
    data_02113994 = 0;
}
