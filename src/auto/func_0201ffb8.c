#include "m2c.h"

M2C_UNK func_0201fe1c();                            /* extern */
M2C_UNK func_0201fea8();                            /* extern */
M2C_UNK func_0201fee8();                            /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
extern s32 data_020d3f04;
extern s32 data_020d3f08;
extern s32 data_020d3f0c;
extern s32 data_020d3f10;
extern M2C_UNK func_0201fcb0;
extern M2C_UNK func_0201ff44;
extern M2C_UNK func_0201ff84;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0201ffb8(void) {
    void *temp_r4;

    temp_r4       = func_0202f368();
    data_020d3f04 = 1;
    data_020d3f08 = 0;
    data_020d3f0c = 0x2710;
    data_020d3f10 = 0;
    func_0201fee8();
    func_0201fea8();
    func_0201fe1c();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0202f564(&func_0201fcb0, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_0201ff84;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0201ff44;
    func_0202c1a0(1);
}
