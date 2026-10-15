#include "m2c.h"

M2C_UNK func_020241f0(void *);                      /* extern */
M2C_UNK func_0202b014(void *, s16, M2C_UNK, M2C_UNK); /* extern */

void func_02024340(void *arg0) {
    M2C_UNK var_r2;
    s16 var_r1;
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0x24);
    if (temp_r0 < 5) {
        var_r1 = ((temp_r0 - 2) * 0x2C) + 0x80;
        var_r2 = 0x60;
    } else {
        var_r1 = ((temp_r0 - 7) * 0x28) + 0x80;
        var_r2 = 0x98;
    }
    func_0202b014(M2C_FIELD(arg0, void **, 0x50), var_r1, var_r2, 0x28);
    M2C_FIELD(arg0, s16 *, 0x4C) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x50), s16 *, 6);
    M2C_FIELD(arg0, s16 *, 0x4E) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x50), s16 *, 8);
    func_020241f0(arg0);
}
