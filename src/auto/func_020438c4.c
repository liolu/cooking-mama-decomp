#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_02038394(s32);                         /* extern */
M2C_UNK func_02043758();                            /* extern */
M2C_UNK func_02043880();                            /* extern */
extern M2C_UNK func_02038288;
extern M2C_UNK func_02043894;

void func_020438c4(void) {
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x24) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x28) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x30) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x32) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x34) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x36) = 0;
    func_0202f564(&func_02038288, 0x15);
    func_02038384(0);
    func_02038394(0x2EE);
    func_02043880();
    func_02043758();
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_02043894;
}
