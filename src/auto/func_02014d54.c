/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02003a94();                            /* extern */
M2C_UNK func_020061a8(s32);                         /* extern */

void func_02014d54(s32 arg0, void *arg1) {
    if (M2C_FIELD(arg1, s32 *, 0) == 0) {
        func_02003a94(arg0);
    }
    func_020061a8(M2C_FIELD(arg1, s32 *, 4));
}
