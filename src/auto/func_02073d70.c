/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02073c7c();                            /* extern */

void func_02073d70(void *arg0) {
    if (((s32) (M2C_FIELD(arg0, s32 *, 0x24) << 0x1F) >> 0x1F) == 0) {
        return;
    }
    func_02073c7c(arg0);
}
