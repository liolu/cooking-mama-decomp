/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02006f8c(u8, s32);                     /* extern */
M2C_UNK func_02007048(u8);                          /* extern */
M2C_UNK func_020732f8(void *);                      /* extern */

void func_02073404(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x2C) == 2) {
        func_02006f8c(M2C_FIELD(arg0, u8 *, 0x3C), 0xFFFFFD2D);
    }
    func_02007048(M2C_FIELD(arg0, u8 *, 0x3C));
    func_020732f8(arg0);
}
