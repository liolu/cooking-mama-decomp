/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020082e8(void *, s32);                     /* extern */
M2C_UNK func_02008464(void *, s32);                 /* extern */
M2C_UNK func_02009434();                            /* extern */
s32 func_020094d8(s32);                             /* extern */

s32 func_020093ec(void *arg0) {
    func_02008464(arg0, func_020082e8(arg0, M2C_FIELD(arg0, s32 *, 0x10)));
    if (func_020094d8(M2C_FIELD(arg0, s32 *, 8)) != 0) {
        func_02009434();
    }
    if (M2C_FIELD(arg0, s32 *, 0x14) == 0) {
        return 1;
    }
    return 0;
}
