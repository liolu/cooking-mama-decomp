/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202b014(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK data_0210c0b0;
extern M2C_UNK data_0210c1a4;
extern M2C_UNK data_0210c20c;

void func_020372f8(void) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;

    temp_r0                             = func_0202b024(1, &data_0210c20c, 2, -1, 1);
    M2C_FIELD(&data_0210c0b0, s32 *, 0) = temp_r0;
    func_0202b014(temp_r0, 0x80, 0x60, 2);
    temp_r0_2                           = func_0202b024(1, &data_0210c1a4, 2, -1, 0);
    M2C_FIELD(&data_0210c0b0, s32 *, 4) = temp_r0_2;
    func_0202b014(temp_r0_2, 0x80, 0x58, 0xA);
    temp_r0_3                           = func_0202b024(1, &data_0210c20c, -1, 2, 0);
    M2C_FIELD(&data_0210c0b0, s32 *, 8) = temp_r0_3;
    func_0202b014(temp_r0_3, 0x80, 0x60, 3);
}
