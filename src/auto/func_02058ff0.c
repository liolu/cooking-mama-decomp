#include "m2c.h"

M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_02058e5c();                            /* extern */
M2C_UNK func_02058f10();                            /* extern */
extern s32 data_02111914;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02058d94;
extern M2C_UNK func_02058f98;
extern M2C_UNK func_02058fb4;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_02058ff0(void) {
    void *temp_r4;

    temp_r4       = func_0202f368();
    data_02111914 = 0;
    func_02058f10();
    func_02058e5c();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0202f564(&func_02058d94, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02058fb4;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_02058f98;
    func_0202c1a0(1);
}
