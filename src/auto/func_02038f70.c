#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0203773c(M2C_UNK);                     /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
extern M2C_UNK func_02038fa8;

void func_02038f70(void) {
    M2C_UNK var_r0;
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, s16 *, 0x3C) == 2) {
        var_r0 = 1;
    } else {
        var_r0 = 2;
    }
    func_0203773c(var_r0);
    func_02038384(0);
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_02038fa8;
}
