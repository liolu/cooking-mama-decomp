/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0200280c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32); /* extern */

void func_0207713c(void) {
    *(s32 *) 0x04000580 = 0xBFFF0000;
    func_0200280c(0, 0xC0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, 1, 0);
    *(s32 *) 0x0400044C = 0;
    *(s32 *) 0x04000440 = 1;
}
