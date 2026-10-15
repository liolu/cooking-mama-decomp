#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_02069abc();                            /* extern */
M2C_UNK func_02069bac();                            /* extern */
extern s32 data_02113100;
extern s32 data_02113104;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02069a00;
extern M2C_UNK func_02069c34;
extern M2C_UNK func_02069c50;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_02069c8c(void) {
    s16 temp_r1;
    void *temp_r0;

    temp_r0       = func_0202f368();
    data_02113100 = 0;
    temp_r1       = M2C_FIELD(func_020197fc(), s16 *, 0x14);
    data_02113104 = (s32) temp_r1;
    if ((s32) temp_r1 >= 3) {
        data_02113104 = 0;
    }
    func_02069bac();
    func_02069abc();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0202f564(&func_02069a00, 0x10);
    M2C_FIELD(temp_r0, M2C_UNK **, 0)    = &func_02069c50;
    M2C_FIELD(temp_r0, M2C_UNK **, 0x14) = &func_02069c34;
    func_0202c1a0(1);
}
