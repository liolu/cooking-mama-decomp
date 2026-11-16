/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_02077614();                                /* extern */

s32 func_0202bdcc(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x28) == 0) {
        return 0;
    }
    return func_02077614();
}
