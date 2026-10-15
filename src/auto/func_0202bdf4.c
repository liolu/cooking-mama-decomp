#include "m2c.h"

s32 func_0202bdf4(void *arg0) {
    void *temp_r0;

    if (arg0 == NULL) {
        return 1;
    }
    temp_r0 = M2C_FIELD(arg0, void **, 0x28);
    if (temp_r0 == NULL) {
        return 1;
    }
    if (M2C_FIELD(temp_r0, s32 *, 8) == 0) {
        return 1;
    }
    return 0;
}
