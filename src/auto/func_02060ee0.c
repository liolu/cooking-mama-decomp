#include "m2c.h"

M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_02060d5c();                            /* extern */
M2C_UNK func_02060de0();                            /* extern */
extern s32 data_021123f4;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02060ccc;
extern M2C_UNK func_02060e88;
extern M2C_UNK func_02060ea4;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_02060ee0(void) {
    void *temp_r4;

    temp_r4       = func_0202f368();
    data_021123f4 = 0;
    func_02060de0();
    func_02060d5c();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0202f564(&func_02060ccc, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02060ea4;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_02060e88;
    func_0202c1a0(1);
}
