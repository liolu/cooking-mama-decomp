#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_02032174();                            /* extern */
M2C_UNK func_02032258();                            /* extern */
M2C_UNK func_020380f0(M2C_UNK);                     /* extern */
M2C_UNK func_0206df2c();                            /* extern */
extern void *data_0210b548;
extern s32 data_0210b54c;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02032068;
extern M2C_UNK func_02032300;
extern M2C_UNK func_02038100;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0203233c(void) {
    s16 var_r3;
    void *temp_r0;
    void *temp_r4;

    temp_r4       = func_0202f368();
    temp_r0       = func_020197fc();
    data_0210b548 = temp_r0;
    var_r3        = M2C_FIELD(temp_r0, s16 *, 0x14);
    if ((s32) var_r3 >= 3) {
        var_r3 = 2;
    }
    data_0210b54c                  = (s32) var_r3;
    M2C_FIELD(temp_r0, s8 *, 0x31) = 5;
    func_02032258();
    func_02032174();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0206df2c();
    func_020380f0(0);
    func_0202f564(&func_02032068, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02038100;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_02032300;
    func_0202c1a0(1);
}
