/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02005818(u16 *, M2C_UNK);              /* extern */
s32 func_0200e150();                                /* extern */
extern void *data_020c556c;

s32 func_0200e0f4(void) {
    s32 temp_r0;

    temp_r0 = func_0200e150();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_02005818(M2C_FIELD(data_020c556c, u16 **, 4), 2);
    if ((u32) *M2C_FIELD(data_020c556c, u16 **, 4) <= 1U) {
        return 3;
    }
    return 0;
}
