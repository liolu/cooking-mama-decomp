/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_020197fc();                            /* extern */
M2C_UNK func_0201e78c(void *);                      /* extern */
M2C_UNK func_0202b014(void *, M2C_UNK, s16, M2C_UNK); /* extern */

void func_0201e948(void *arg0, s32 arg1) {
    M2C_UNK var_r1;

    func_020197fc(arg0);
    if (arg1 == 0) {
        func_0202b014(M2C_FIELD(arg0, void **, 0x58), 0x80, (s16) ((M2C_FIELD(arg0, s32 *, 0x24) * 0x26) + 0x38), 0x28);
    } else {
        if (arg1 == 1) {
            var_r1 = 0x18;
        } else {
            var_r1 = 0xE8;
        }
        func_0202b014(M2C_FIELD(arg0, void **, 0x58), var_r1, (s16) ((M2C_FIELD(arg0, s32 *, 0x24) * 0x26) + 0x38), 0x27);
    }
    M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s16 *, 6);
    M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s16 *, 8);
    func_0201e78c(arg0);
}
