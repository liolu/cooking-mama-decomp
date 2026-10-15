#include "m2c.h"

M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020380f0(M2C_UNK);                     /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_02038394(M2C_UNK);                     /* extern */
M2C_UNK func_0204c778();                            /* extern */
M2C_UNK func_0204c7f8();                            /* extern */
extern M2C_UNK data_020b9ba8;
extern M2C_UNK *data_0210fec0;
extern M2C_UNK data_02110060;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02038100;
extern M2C_UNK func_02038288;
extern M2C_UNK func_0204c70c;
extern M2C_UNK func_0204c8a0;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0204c8dc(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_0204c7f8();
    func_0204c778();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_02019b4c(&data_02110060);
    M2C_FIELD(temp_r4, s32 *, 0x30) = 0;
    M2C_FIELD(temp_r4, s16 *, 0x3C) = 0;
    M2C_FIELD(temp_r4, s16 *, 0x3A) = 0;
    data_0210fec0                   = &data_020b9ba8;
    func_0202f564(&func_02038288, 0x15);
    func_02038384(0);
    func_02038394(0x190);
    func_020380f0(0);
    func_0202f564(&func_0204c70c, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02038100;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0204c8a0;
    func_0202c1a0(1);
}
