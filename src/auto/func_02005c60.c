/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02005974(M2C_UNK, s32);                /* extern */
M2C_UNK func_02005988(M2C_UNK, s32);                /* extern */
s32 func_0200599c(M2C_UNK);                         /* extern */
s32 func_02005a88(M2C_UNK);                         /* extern */
extern s32 data_020c2e6c;

void func_02005c60(void) {
    if (data_020c2e6c != 0) {
        return;
    }
    data_020c2e6c = 1;
    func_02005988(0, func_02005a88(0));
    func_02005974(0, func_0200599c(0));
    func_02005974(2, 0);
    func_02005988(2, 0);
    func_02005988(3, func_02005a88(3));
    func_02005974(3, func_0200599c(3));
    func_02005988(4, func_02005a88(4));
    func_02005974(4, func_0200599c(4));
    func_02005988(5, func_02005a88(5));
    func_02005974(5, func_0200599c(5));
    func_02005988(6, func_02005a88(6));
    func_02005974(6, func_0200599c(6));
}
