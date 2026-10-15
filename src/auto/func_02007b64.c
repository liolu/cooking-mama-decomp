/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02005834(s32, M2C_UNK);                /* extern */
M2C_UNK func_02007074();                            /* extern */
M2C_UNK func_02007088();                            /* extern */

void func_02007b64(s32 arg0, s32 arg1, s32 arg2) {
    func_02007088();
    M2C_FIELD((arg0 + (arg1 * 4)), s32 *, 0x3C) = arg2;
    func_02005834(arg0 + 0x3C + (arg1 * 4), 4);
    func_02007074();
}
