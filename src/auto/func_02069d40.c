/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_0202f368();                            /* extern */
extern M2C_UNK data_021132ac;

void func_02069d40(s32 arg0) {
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;

    func_0202f368(arg0);
    if (arg0 == 0) {
        temp_r0                        = func_0202b024(1, &data_021132ac, 0, 2, 0x40);
        M2C_FIELD(temp_r0, s16 *, 6)   = 0x80;
        M2C_FIELD(temp_r0, s16 *, 8)   = 0x60;
        temp_r0_2                      = func_0202b024(1, &data_021132ac, 0, 2, 0x50);
        M2C_FIELD(temp_r0_2, s16 *, 6) = 0x80;
        M2C_FIELD(temp_r0_2, s16 *, 8) = 0x60;
        return;
    }
    temp_r0_3                        = func_0202b024(1, &data_021132ac, 0, 3, 0x40);
    M2C_FIELD(temp_r0_3, s16 *, 6)   = 0x80;
    M2C_FIELD(temp_r0_3, s16 *, 8)   = 0x60;
    M2C_FIELD(temp_r0_3, s16 *, 0xA) = 0x21;
}
