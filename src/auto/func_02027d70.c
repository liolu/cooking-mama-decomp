#include "m2c.h"

s32 func_020263d4();                                /* extern */
M2C_UNK func_02027b44();                            /* extern */
M2C_UNK func_02027c80();                            /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202ed64();                            /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
extern s32 data_020d4c6c;
extern s32 data_020d4c74;
extern M2C_UNK func_0202750c;
extern M2C_UNK func_02027cf0;
extern M2C_UNK func_02027d30;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_02027d70(void) {
    void *temp_r4;

    temp_r4       = func_0202f368();
    data_020d4c74 = 0;
    data_020d4c6c = 0;
    func_0202ed64();
    func_02027c80();
    func_02027b44();
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(0);
    func_0202f564(&func_0202750c, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02027d30;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_02027cf0;
    func_0202c1a0(1);
    data_020d4c6c = func_020263d4();
}
