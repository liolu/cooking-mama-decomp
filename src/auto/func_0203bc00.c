#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_02038394(s16);                         /* extern */
M2C_UNK func_0203b950();                            /* extern */
M2C_UNK func_0203bbbc();                            /* extern */
extern M2C_UNK func_02038288;
extern M2C_UNK func_0203bbd0;

void func_0203bc00(void) {
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s16 *, 0x30) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x3C) = 0x28;
    func_0203bbbc();
    func_0203b950();
    M2C_FIELD(temp_r0, s16 *, 0x32) = 0x2BC;
    func_0202f564(&func_02038288, 0x15);
    func_02038384(0);
    func_02038394(M2C_FIELD(temp_r0, s16 *, 0x32));
    M2C_FIELD(temp_r0, s16 *, 0x28)   = -1;
    M2C_FIELD(temp_r0, s16 *, 0x2C)   = 0;
    M2C_FIELD(temp_r0, s16 *, 0x2E)   = 0;
    M2C_FIELD(temp_r0, s16 *, 0x34)   = 0;
    M2C_FIELD(temp_r0, s16 *, 0x3A)   = 0;
    M2C_FIELD(temp_r0, s32 *, 0x40)   = 0;
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_0203bbd0;
}
