#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_0206763c();                            /* extern */
M2C_UNK func_020676c0();                            /* extern */
extern s32 data_02112d48;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02067560;
extern M2C_UNK func_02067748;
extern M2C_UNK func_02067764;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_020677a0(void) {
    void *temp_r0;
    void *temp_r4;

    temp_r4       = func_0202f368();
    temp_r0       = func_020197fc();
    data_02112d48 = 0;
    if (M2C_FIELD(temp_r0, s16 *, 0x16) == 4) {
        M2C_FIELD(temp_r0, s8 *, 0x31) = 0x14;
    }
    func_020676c0();
    func_0206763c();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0202f564(&func_02067560, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02067764;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_02067748;
    func_0202c1a0(1);
}
