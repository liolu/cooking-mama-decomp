/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02074738();                           /* extern */
M2C_UNK func_020760f4();                /* extern */

s32 func_02074788(s32 *arg0, s32 arg1) {
    func_020760f4(((s8 *) arg0 + 4), 0xC);
    *arg0 = arg1;
    if (func_02074738(arg0) != 0) {
        return 1;
    }
    return 0;
}
