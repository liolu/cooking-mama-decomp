#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_02038394(M2C_UNK);                     /* extern */
M2C_UNK func_02046bdc();                            /* extern */
M2C_UNK func_02046e28();                            /* extern */
extern M2C_UNK func_02038288;
extern M2C_UNK func_02046e3c;

void func_02046e6c(void) {
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x20) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x26) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x24) = 5;
    func_02046e28();
    func_02046bdc();
    func_0202f564(&func_02038288, 0x15);
    func_02038384(0);
    func_02038394(0x12C);
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_02046e3c;
}
