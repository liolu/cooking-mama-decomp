#include "m2c.h"

M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_0205a0cc();                            /* extern */
M2C_UNK func_0205a134();                            /* extern */
extern s32 data_02111bf4;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_0205a034;
extern M2C_UNK func_0205a1d8;
extern M2C_UNK func_0205a1f4;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0205a230(void) {
    void *temp_r4;

    temp_r4       = func_0202f368();
    data_02111bf4 = 0;
    func_0205a134();
    func_0205a0cc();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0202f564(&func_0205a034, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_0205a1f4;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0205a1d8;
    func_0202c1a0(1);
}
