#include "m2c.h"

M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020380f0(M2C_UNK);                     /* extern */
M2C_UNK func_0203bcb0();                            /* extern */
M2C_UNK func_0203bd34();                            /* extern */
M2C_UNK func_0206df2c();                            /* extern */
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02038100;
extern M2C_UNK func_0203bc00;
extern M2C_UNK func_0203bdc0;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0203bdfc(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_0203bd34();
    func_0203bcb0();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0206df2c();
    func_020380f0(0);
    func_0202f564(&func_0203bc00, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02038100;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0203bdc0;
    func_0202c1a0(1);
}
