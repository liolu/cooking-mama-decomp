/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_020023b4(M2C_UNK, M2C_UNK, s32, M2C_UNK, s32); /* extern */
M2C_UNK func_0202c3c4();                            /* extern */
M2C_UNK func_0202cc20(M2C_UNK);                     /* extern */
M2C_UNK func_0207713c();                            /* extern */

void func_0202c1e8(void) {
    func_0202c3c4();
    func_020023b4(0, 0, 0x7FFF, 0, 0);
    func_0207713c();
    *(volatile u16 *) 0x04000304 &= ~0x8000;
    func_0202cc20(-0x10);
    func_0202cc20(0x10);
}
