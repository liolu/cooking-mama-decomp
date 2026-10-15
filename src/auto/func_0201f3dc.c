#include "m2c.h"

s32 func_020197fc();                                /* extern */
M2C_UNK func_0201f1a4();                            /* extern */
M2C_UNK func_0201f20c();                            /* extern */
M2C_UNK func_0201f2b4();                            /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202edb0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020537c4(s32, M2C_UNK, M2C_UNK);       /* extern */
extern s32 data_020d3aec;
extern M2C_UNK func_0201f118;
extern M2C_UNK func_0201f368;
extern M2C_UNK func_0201f3a8;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0201f3dc(void) {
    void *temp_r4;

    temp_r4       = func_0202f368();
    data_020d3aec = 0;
    func_020537c4(func_020197fc(), 0, 0x180);
    func_0201f2b4();
    func_0201f20c();
    func_0201f1a4();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(0);
    func_0202f564(&func_0201f118, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_0201f3a8;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0201f368;
    func_0202c1a0(1);
    func_0202edb0(1);
}
