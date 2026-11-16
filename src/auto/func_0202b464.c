/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void func_0202b464(void *arg0, s32 arg1, s32 arg2, s16 arg3, u16 arg4) {
    M2C_FIELD(arg0, s16 *, 0x14)                           = arg3;
    M2C_FIELD(arg0, u16 *, 0x16)                           = arg4;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s32 *, 0x1C) = (s32) (arg1 << 0xC);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s32 *, 0x20) = (s32) (arg2 << 0xC);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s32 *, 0x24) = (s32) ((arg1 + arg3) << 0xC);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s32 *, 0x28) = (s32) ((arg2 + arg4) << 0xC);
}
