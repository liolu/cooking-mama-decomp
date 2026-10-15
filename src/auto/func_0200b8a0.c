/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0200b8dc(M2C_UNK, M2C_UNK *, s32 *);       /* extern */
M2C_UNK func_0200bdec();                            /* extern */
extern M2C_UNK func_0200bde4;

s32 func_0200b8a0(M2C_UNK arg0) {
    s32 sp0;
    s32 temp_r0;

    temp_r0 = func_0200b8dc(arg0, &func_0200bde4, &sp0);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_0200bdec();
    return sp0;
}
