#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_02056d48();                            /* extern */
M2C_UNK func_02056e00();                            /* extern */
extern s32 data_02111698;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02056c6c;
extern M2C_UNK func_02056e88;
extern M2C_UNK func_02056ea4;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_02056ee0(void) {
    void *temp_r0;
    void *temp_r4;

    temp_r4       = func_0202f368();
    temp_r0       = func_020197fc();
    data_02111698 = 0;
    if (M2C_FIELD(temp_r0, s16 *, 0x16) == 4) {
        M2C_FIELD(temp_r0, s8 *, 0x31) = 0xF;
    }
    func_02056e00();
    func_02056d48();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0202f564(&func_02056c6c, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02056ea4;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_02056e88;
    func_0202c1a0(1);
}
