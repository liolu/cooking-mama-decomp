/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_02012a8c(u16);                             /* extern */
s32 func_020185f4(M2C_UNK);                         /* extern */
extern u16 data_020c6264;
extern s32 *data_020c6274;

s32 func_02016734(M2C_UNK arg0) {
    s32 var_r0;

    if (func_02012a8c(data_020c6264) != 0) {
        *data_020c6274 = 4;
        return -1;
    }
    if (func_020185f4(arg0) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return 0 - var_r0;
}
