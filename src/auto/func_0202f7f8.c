#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(s32, s32);                    /* extern */

void func_0202f7f8(void) {
    s32 temp_r1;
    void *temp_r0;

    temp_r0                         = func_0202f368();
    temp_r1                         = M2C_FIELD(temp_r0, s32 *, 0x28);
    M2C_FIELD(temp_r0, s32 *, 0x28) = (s32) (temp_r1 + 1);
    if (temp_r1 == 0) {
        return;
    }
    func_0202f564(M2C_FIELD(temp_r0, s32 *, 0x20), 0xFF02);
    M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
}
