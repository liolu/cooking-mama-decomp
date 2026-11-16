/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f35c();                              /* extern */

void func_0202f378(void) {
    void *var_r2;

    var_r2 = M2C_FIELD(func_0202f35c(), void **, 8);
loop_1:
    if (M2C_FIELD(var_r2, void **, 8) != NULL) {
        M2C_FIELD(var_r2, s32 *, 0x10) = 1;
        var_r2                         = M2C_FIELD(var_r2, void **, 8);
        goto loop_1;
    }
}
