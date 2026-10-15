#include "m2c.h"

M2C_UNK func_0201955c(M2C_UNK);                     /* extern */
M2C_UNK func_020197fc();                            /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202ed64();                            /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_0202f7e0();                            /* extern */
M2C_UNK func_0203009c();                            /* extern */
M2C_UNK func_0203014c();                            /* extern */
M2C_UNK func_020301b4();                            /* extern */
extern s32 data_0210aeb8;
extern s32 data_0210aebc;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_0202fd50;
extern M2C_UNK func_02030054;
extern M2C_UNK func_0203022c;
extern M2C_UNK func_0203026c;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_020302a0(void) {
    void *temp_r4;

    func_0201955c(0);
    func_0202f7e0();
    temp_r4 = func_0202f368();
    func_020197fc();
    func_0202ed64();
    data_0210aebc = 0;
    data_0210aeb8 = 0;
    func_020301b4();
    func_0203014c();
    func_0203009c();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(0);
    func_0202f564(&func_0202fd50, 0x10);
    func_0202f564(&func_02030054, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_0203026c;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0203022c;
    func_0202c1a0(1);
}
