#include "m2c.h"

M2C_UNK func_0202b1a0(void *);                      /* extern */
s32 func_0202bdf4(s32);                             /* extern */
void *func_0202f368();                              /* extern */

void func_0205588c(void) {
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (func_0202bdf4(M2C_FIELD(temp_r0, s32 *, 0x1C)) == 0) {
        return;
    }
    func_0202b1a0(temp_r0 + 0x1C);
    M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
}
