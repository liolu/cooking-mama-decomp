/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202bea8(void *, s32);                 /* extern */
M2C_UNK func_0207755c(void *);                      /* extern */

void func_0202be24(s32 arg0, void *arg1) {
    s32 temp_r1;

    temp_r1 = M2C_FIELD(M2C_FIELD(arg1, void **, 0x28), s32 *, 0x10);
    if (arg0 == 1) {
        if (temp_r1 < 0) {
            func_0202bea8(arg1, 0 - temp_r1);
        }
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x28), s32 *, 4)    = 0;
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x28), s32 *, 0x14) = 0;
    } else {
        if (temp_r1 > 0) {
            func_0202bea8(arg1, 0 - temp_r1);
        }
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x28), s32 *, 0x14) = arg0;
    }
    func_0207755c(M2C_FIELD(arg1, void **, 0x28));
    M2C_FIELD(M2C_FIELD(arg1, void **, 0x28), s32 *, 8) = 1;
}
