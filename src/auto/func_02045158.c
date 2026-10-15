#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_02038394(M2C_UNK);                     /* extern */
M2C_UNK func_02044fd8();                            /* extern */
M2C_UNK func_020450dc();                            /* extern */
M2C_UNK func_0206d550(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK func_02038288;
extern M2C_UNK func_020450f0;

void func_02045158(void) {
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x24) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x28) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x2C) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x2E) = 0;
    func_0202f564(&func_02038288, 0x15);
    func_02038384(0);
    func_02038394(0x258);
    func_0206d550(0x36, 0xF);
    func_020450dc();
    func_02044fd8();
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_020450f0;
}
