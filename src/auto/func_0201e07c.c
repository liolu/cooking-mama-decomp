#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0201dd98();                            /* extern */
M2C_UNK func_0201de04();                            /* extern */
M2C_UNK func_0201de94();                            /* extern */
M2C_UNK func_0201df2c();                            /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202edb0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
extern s32 data_020d379c;
extern M2C_UNK func_0201d884;
extern M2C_UNK func_0201dfd0;
extern M2C_UNK func_0201e03c;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0201e07c(void) {
    void *temp_r0;

    temp_r0       = func_0202f368();
    data_020d379c = 0;
    func_0201df2c();
    func_0201de94();
    func_0201de04();
    if (M2C_FIELD(func_020197fc(), s16 *, 0x16) == 3) {
        func_0201dd98();
    }
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(0);
    func_0202f564(&func_0201d884, 0x10);
    M2C_FIELD(temp_r0, M2C_UNK **, 0)    = &func_0201e03c;
    M2C_FIELD(temp_r0, M2C_UNK **, 0x14) = &func_0201dfd0;
    func_0202c1a0(1);
    func_0202edb0(7);
}
