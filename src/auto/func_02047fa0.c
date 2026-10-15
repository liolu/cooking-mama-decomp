#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020380f0(M2C_UNK);                     /* extern */
M2C_UNK func_02047e58();                            /* extern */
M2C_UNK func_02047ef8();                            /* extern */
extern void *data_0210f354;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02038100;
extern M2C_UNK func_02047dd4;
extern M2C_UNK func_02047f64;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_02047fa0(void) {
    void *temp_r0;
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_02047ef8();
    func_02047e58();
    temp_r0                        = func_020197fc();
    data_0210f354                  = temp_r0;
    M2C_FIELD(temp_r0, s8 *, 0x31) = 5;
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_020380f0(0);
    func_0202f564(&func_02047dd4, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02038100;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_02047f64;
    func_0202c1a0(1);
}
