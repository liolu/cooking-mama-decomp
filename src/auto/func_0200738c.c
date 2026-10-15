/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02007188();                            /* extern */
s32 func_020072f8();                         /* extern */
s32 func_020076c0();                         /* extern */

void func_0200738c(M2C_UNK arg0) {
    if (func_020072f8() != 0) {
        return;
    }
    do {

    } while (func_020076c0(0) != 0);
    if (func_020072f8(arg0) != 0) {
        return;
    }
    func_02007188();
    if (func_020072f8(arg0) != 0) {
        return;
    }
    do {
        func_020076c0(1);
    } while (func_020072f8(arg0) == 0);
}
