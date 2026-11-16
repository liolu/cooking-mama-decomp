/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_02000f28();                            /* extern */
M2C_UNK func_02001034();                            /* extern */
M2C_UNK func_020010ac();                            /* extern */
M2C_UNK func_0200589c();                            /* extern */
M2C_UNK func_02006074();                            /* extern */
M2C_UNK func_0200d0a4();                            /* extern */

void func_0202f040(void) {
    func_0200589c();
    func_02000f28();
    func_020010ac();
    func_02006074();
    func_0200d0a4();
    func_02001034();
    *(volatile s32 *) 0x04001000 &= ~0x10000;
}
