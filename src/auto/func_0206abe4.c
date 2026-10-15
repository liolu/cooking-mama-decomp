#include "m2c.h"

M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
s32 func_02038374();                                /* extern */
s32 func_0206d7c8();                                /* extern */
extern M2C_UNK func_0206ab88;

void func_0206abe4(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (func_02038374() == 0) {
        return;
    }
    if (func_0206d7c8() != 0) {
        return;
    }
    func_0202ec14(0x40);
    M2C_FIELD(func_0202f564(&func_0206ab88, 0x11), s32 *, 0x20) = (s32) M2C_FIELD(temp_r4, s32 *, 0x20);
    M2C_FIELD(temp_r4, s32 *, 0x10)                             = 1;
}
