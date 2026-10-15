#include "m2c.h"

s32 func_0202ca14();                                /* extern */
s32 func_0202cab4();                                /* extern */
M2C_UNK func_0202cc20(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f378();                            /* extern */
void *func_0202f564(M2C_UNK *, s32);                /* extern */
s32 func_0202f6e8();                                /* extern */
extern M2C_UNK func_02018d5c;
extern M2C_UNK func_0202f7f8;

void func_0202f834(void) {
    void *temp_r0;
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (func_0202cab4() != 0) {
        return;
    }
    if ((M2C_FIELD(temp_r4, s32 *, 0x24) == 0) && (func_0202ca14() != 0x10)) {
        return;
    }
    func_0202cc20(0x10);
    func_0202f378();
    if (M2C_FIELD(temp_r4, M2C_UNK **, 0x1C) == NULL) {
        return;
    }
    temp_r0                              = func_0202f564(&func_0202f7f8, 0xFF02);
    M2C_FIELD(temp_r0, M2C_UNK **, 0x20) = (M2C_UNK *) M2C_FIELD(temp_r4, M2C_UNK **, 0x1C);
    if (func_0202f6e8() != 0) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0x20) = &func_02018d5c;
    }
}
