/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020775d4(void *);                      /* extern */
M2C_UNK func_020788f8(void *, M2C_UNK);             /* extern */
M2C_UNK func_020789b4(void *, M2C_UNK);             /* extern */

void func_020789d0(void *arg0, M2C_UNK arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x30) = arg2;
    M2C_FIELD(arg0, s32 *, 0x34) = -1;
    func_020788f8(arg0 + 0x38, 1);
    func_020775d4(arg0);
    func_020789b4(arg0, arg1);
}
