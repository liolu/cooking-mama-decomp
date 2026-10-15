#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_02038394(s32);                         /* extern */
M2C_UNK func_02048c94();                            /* extern */
M2C_UNK func_02049288();                            /* extern */
M2C_UNK func_0206d550(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK func_02038288;
extern M2C_UNK func_0204929c;

void func_020492e4(void) {
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x24) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x28) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x2C) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x30) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x32) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x52) = 0;
    func_02049288();
    func_02048c94();
    func_0202f564(&func_02038288, 0x15);
    func_02038384(0);
    func_02038394(0xA8C);
    func_0206d550(0x3E, 0xE);
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_0204929c;
}
