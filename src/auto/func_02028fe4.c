/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_020197fc();                            /* extern */
M2C_UNK func_02028dd0(void *, s32);                 /* extern */
M2C_UNK func_0202b014(void *, M2C_UNK, s16, M2C_UNK); /* extern */

void func_02028fe4(void *arg0, s32 arg1) {
    s16 temp_r6;

    func_020197fc(arg0);
    if (arg1 == 0) {
        temp_r6 = (M2C_FIELD(arg0, s32 *, 0x24) * 0x24) + 0x28;
        func_0202b014(M2C_FIELD(arg0, void **, 0x58), 0x80, temp_r6, 0x28);
        func_0202b014(M2C_FIELD(arg0, void **, 0x5C), 0x80, temp_r6, 0x26);
    } else {
        func_0202b014(M2C_FIELD(arg0, void **, 0x58), 0x80, 0x68, 0x28);
    }
    M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s16 *, 6);
    M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s16 *, 8);
    func_02028dd0(arg0, arg1);
}
