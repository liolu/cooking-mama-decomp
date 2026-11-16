/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202b014(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK data_020d3f3c;
extern M2C_UNK data_020d3fa4;
extern M2C_UNK data_020d4074;

void func_0201fbf8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x24) = func_0202b024(1, &data_020d3f3c, 2, -1, 0);
    func_0202b014(M2C_FIELD(arg0, s32 *, 0x24), 0x80, 0x60, 0x1E);
    M2C_FIELD(arg0, s32 *, 0x28) = func_0202b024(1, &data_020d3fa4, 0, -1, 0);
    func_0202b014(M2C_FIELD(arg0, s32 *, 0x28), 0x80, 0x60, 0x14);
    M2C_FIELD(arg0, s32 *, 0x2C) = func_0202b024(1, &data_020d4074, -1, 2, 0);
    func_0202b014(M2C_FIELD(arg0, s32 *, 0x2C), 0xE0, 0x54, 0xA);
}
