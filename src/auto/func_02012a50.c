/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0200f144(s32);                             /* extern */
M2C_UNK func_0201256c(M2C_UNK, s32);                /* extern */
extern void *data_020c6138;

s32 func_02012a50(void) {
    s32 var_r4;

    var_r4 = func_0200f144(M2C_FIELD(data_020c6138, s32 *, 0x508));
    func_0201256c(1, var_r4);
    if (var_r4 == 2) {
        var_r4 = 0;
    }
    return var_r4;
}
