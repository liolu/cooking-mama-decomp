/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02006194();                                /* extern */
M2C_UNK func_020061a8(s32);                         /* extern */
M2C_UNK func_02006440();                            /* extern */
M2C_UNK func_020129bc();                            /* extern */
extern void *data_020c613c;

void func_0201297c(void) {
    s32 temp_r4;

    temp_r4 = func_02006194();
    if (M2C_FIELD(data_020c613c, s32 *, 0x1320) == 0) {
        func_02006440();
    }
    func_020129bc();
    func_020061a8(temp_r4);
}
