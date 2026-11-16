/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b3f8();                              /* extern */
M2C_UNK func_020537c4(void *, M2C_UNK, M2C_UNK);    /* extern */

void func_0202b4b8(void *arg0) {
    M2C_FIELD(arg0, void **, 0x24) = func_0202b3f8();
    func_020537c4(M2C_FIELD(arg0, void **, 0x24), 0, 0x3C);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s16 *, 0x1A) = 0x7FFF;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s32 *, 0x2C) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s32 *, 0x30) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s32 *, 0xC)  = (s32) (M2C_FIELD(arg0, void **, 0x20) + 0x34);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s32 *, 0x10) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x28);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s32 *, 0x14) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x54);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s16 *, 0x18) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s8 *, 0xB)   = 0x1F;
}
