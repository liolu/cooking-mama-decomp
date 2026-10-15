/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02005384();                                /* extern */
M2C_UNK func_02005974(M2C_UNK, s32);                /* extern */
M2C_UNK func_02005988(M2C_UNK, s32);                /* extern */
s32 func_0200599c(M2C_UNK);                         /* extern */
s32 func_02005a88(M2C_UNK);                         /* extern */
M2C_UNK func_02005dac(s32);                         /* extern */
M2C_UNK func_02005db4(s32);                         /* extern */
extern s32 data_020c2e70;

void func_02005be0(void) {
    func_02005988(2, func_02005a88(2));
    func_02005974(2, func_0200599c(2));
    if ((data_020c2e70 != 0) && ((func_02005384() & 3) != 1)) {
        return;
    }
    func_02005dac(0x0200002B);
    func_02005db4(0x023E0021);
}
