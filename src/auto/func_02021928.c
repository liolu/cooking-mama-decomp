/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202b014(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_0202bc4c(s32, M2C_UNK);                /* extern */
M2C_UNK func_0202bea8(s32, M2C_UNK);                /* extern */
extern M2C_UNK data_020d44a8;

void func_02021928(void *arg0) {
    void *temp_r4;

    temp_r4                      = func_020197fc();
    M2C_FIELD(arg0, s32 *, 0x3C) = func_0202b024(4, &data_020d44a8, -1, 1, 0);
    func_0202b014(M2C_FIELD(arg0, s32 *, 0x3C), 0x80, 0x60, 2);
    func_0202bea8(M2C_FIELD(arg0, s32 *, 0x3C), 0x2000);
    M2C_FIELD(arg0, s32 *, 0x40) =
        func_0202b024(4, &data_020d44a8, -1, M2C_FIELD((temp_r4 + (M2C_FIELD(temp_r4, s16 *, 0x38) * 8)), s32 *, 0x40) + 3, 0);
    func_0202b014(M2C_FIELD(arg0, s32 *, 0x40), 0x80, 0x60, 0);
    if (M2C_FIELD(temp_r4, s16 *, 0x16) != 4) {
        return;
    }
    if (M2C_FIELD(temp_r4, u16 *, 0x34) != 0) {
        return;
    }
    func_0202bc4c(M2C_FIELD(arg0, s32 *, 0x40), 0);
}
