/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_020021e8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
void *func_020197fc();                              /* extern */
M2C_UNK func_0202c3c4();                            /* extern */
M2C_UNK func_0202c490();                            /* extern */

void func_0201df2c(void) {
    if (M2C_FIELD(func_020197fc(), s32 *, 0x17C) == 0) {
        func_0202c490();
        func_0202c3c4();
    }
    *(volatile s32 *) 0x04000000 = (*(volatile s32 *) 0x04000000 & ~0x1F00) | 0x1900;
    func_020021e8(0x04000050, 0, 8, 0, 0);
    *(volatile s32 *) 0x04001000 = (*(volatile s32 *) 0x04001000 & ~0x1F00) | 0x1800;
    func_020021e8(0x04001050, 0, 8, 7, 0xC);
    *(volatile u16 *) 0x04000304 &= ~0x8000;
}
