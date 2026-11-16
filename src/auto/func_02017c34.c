/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s16 func_0200e6f0();                                /* extern */
s16 func_02016808();                                /* extern */
extern u16 data_020c6264;
extern M2C_UNK data_020c62e0;

void func_02017c34(s32 arg0) {
    M2C_FIELD(&data_020c62e0, s16 *, 0x18) = func_0200e6f0();
    M2C_FIELD(&data_020c62e0, s32 *, 8)    = arg0;
    M2C_FIELD(&data_020c62e0, u16 *, 0x32) = (u16) data_020c6264;
    M2C_FIELD(&data_020c62e0, s16 *, 0xC)  = func_02016808();
}
