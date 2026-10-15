/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02074738(void *);                          /* extern */
M2C_UNK func_02076874(s32, M2C_UNK);                /* extern */
s32 func_020768d0(s32, u16);                        /* extern */

s32 func_020748f4(void *arg0) {
    if (func_020768d0(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, u16 *, 0xC)) == 0) {
        return -1;
    }
    if (func_02074738(arg0) != 0) {
        return M2C_FIELD(arg0, u16 *, 0xC) - 1;
    }
    func_02076874(M2C_FIELD(arg0, s32 *, 0), 0);
    return -1;
}
