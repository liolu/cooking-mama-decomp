#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020380f0(M2C_UNK);                     /* extern */
M2C_UNK func_02042a8c();                            /* extern */
M2C_UNK func_02042b48();                            /* extern */
M2C_UNK func_0206df2c();                            /* extern */
extern s32 data_0210e3a4;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02038100;
extern M2C_UNK func_020429d8;
extern M2C_UNK func_02042bd4;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_02042c10(void) {
    s16 var_r1;
    void *temp_r4;

    temp_r4 = func_0202f368();
    var_r1  = M2C_FIELD(func_020197fc(), s16 *, 0x14);
    if ((s32) var_r1 >= 7) {
        var_r1 = 6;
    }
    data_0210e3a4 = (s32) var_r1;
    if (var_r1 == 5) {
        data_0210e3a4 = 6;
    }
    func_02042b48();
    func_02042a8c();
    func_0206df2c();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_020380f0(0);
    func_0202f564(&func_020429d8, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02038100;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_02042bd4;
    func_0202c1a0(1);
}
