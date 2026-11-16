/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202ad9c(void *, M2C_UNK, M2C_UNK);    /* extern */
void *func_02076e58(s32, u16);                      /* extern */

void func_0202bbc0(void *arg0) {
    s32 var_ip;
    void *temp_r0;
    void *var_r0;
    void *var_r3;

    if (M2C_FIELD(arg0, s32 *, 0) == 1) {
        return;
    }
    func_0202ad9c(arg0 + 0xA, 0, 3);
    temp_r0 = M2C_FIELD(arg0, void **, 0x28);
    if (temp_r0 != NULL) {
        var_r0 = M2C_FIELD(temp_r0, void **, 0x2C);
    } else {
        var_r0 = func_02076e58(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x20), M2C_FIELD(arg0, u16 *, 0x18));
    }
    var_r3 = M2C_FIELD(var_r0, void **, 4);
    var_ip = 0;
    if ((s32) M2C_FIELD(var_r0, u16 *, 0) <= 0) {
        return;
    }
    do {
        var_ip += 1;
        M2C_FIELD(var_r3, u16 *, 4) = (u16) ((M2C_FIELD(var_r3, u16 *, 4) & ~0xC00) | (M2C_FIELD(arg0, s16 *, 0xA) << 0xA));
        var_r3 += 6;
    } while (var_ip < (s32) M2C_FIELD(var_r0, u16 *, 0));
}
