#include "m2c.h"

s32 func_020197fc();                                /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020380f0(M2C_UNK);                     /* extern */
M2C_UNK func_0203c88c();                            /* extern */
M2C_UNK func_0203c90c();                            /* extern */
M2C_UNK func_0206df2c();                            /* extern */
extern void *data_0210d360;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02038100;
extern M2C_UNK func_0203c7a8;
extern M2C_UNK func_0203c994;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0203c9d0(void) {
    void *temp_r2;
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_020197fc();
    temp_r2                     = func_020197fc() + 0x30;
    data_0210d360               = temp_r2;
    M2C_FIELD(temp_r2, s8 *, 1) = 5;
    func_0203c90c();
    func_0203c88c();
    func_0206df2c();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_020380f0(0);
    func_0202f564(&func_0203c7a8, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02038100;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0203c994;
    func_0202c1a0(1);
}
