/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02077810(void *arg0, u32 arg1) {
    void *temp_r3;

    temp_r3 = M2C_FIELD(arg0, void **, 0x18);
    if (arg1 < (u32) M2C_FIELD(temp_r3, u16 *, 0)) {
        M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(temp_r3, s32 *, 0xC) + (arg1 * 8));
        return 1;
    }
    return 0;
}
