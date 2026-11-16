/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202b33c(void *);                      /* extern */

void func_0202bda4(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x28) == 0) {
        return;
    }
    func_0202b33c(arg0 + 0x28);
}
