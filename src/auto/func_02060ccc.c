#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
M2C_UNK **func_0202f368();                          /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038394(s32);                         /* extern */
M2C_UNK func_02060ab8();                            /* extern */
extern M2C_UNK data_02112530;
extern M2C_UNK func_02038288;
extern M2C_UNK func_020606c8;

void func_02060ccc(void) {
    M2C_UNK **temp_r4;
    void *temp_r0;

    temp_r4 = func_0202f368();
    temp_r0 = func_020197fc();
    if (M2C_FIELD(temp_r0, s16 *, 0x16) == 4) {
        M2C_FIELD(temp_r0, s8 *, 0x31) = 5;
    }
    func_02019b4c(&data_02112530);
    func_0202f564(&func_02038288, 0x15);
    func_02038394(0x708);
    func_02060ab8();
    *temp_r4 = &func_020606c8;
}
