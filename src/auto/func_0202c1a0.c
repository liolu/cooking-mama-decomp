#include "m2c.h"

M2C_UNK func_02000fe8();                            /* extern */
M2C_UNK func_02001034();                            /* extern */
M2C_UNK func_02006204();                            /* extern */

void func_0202c1a0(s32 arg0) {
    func_02006204();
    if (arg0 == 1) {
        func_02000fe8();
        *(s32 *) 0x04001000 |= 0x10000;
        return;
    }
    func_02001034();
    *(M2C_UNK *) 0x04001000 = (s32) (*(M2C_UNK *) 0x04001000 & ~0x10000);
}
