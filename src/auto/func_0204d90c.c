#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020380f0(M2C_UNK);                     /* extern */
M2C_UNK func_0204d77c();                            /* extern */
M2C_UNK func_0204d828();                            /* extern */
extern void *data_021100c8;
extern void *data_021100cc;
extern s32 data_021100d0;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02038100;
extern M2C_UNK func_0204d630;
extern M2C_UNK func_0204d8d0;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0204d90c(void) {
    s16 var_r2;
    void *temp_r0;
    void *temp_r2;
    void *temp_r4;

    temp_r4       = func_0202f368();
    temp_r0       = func_020197fc();
    data_021100c8 = temp_r0;
    var_r2        = M2C_FIELD(temp_r0, s16 *, 0x14);
    if ((s32) var_r2 >= 6) {
        var_r2 = 5;
    }
    data_021100d0 = (s32) var_r2;
    if (M2C_FIELD(temp_r0, s16 *, 0x16) == 4) {
        data_021100d0 = 3;
    }
    temp_r2                     = temp_r0 + 0x30;
    data_021100cc               = temp_r2;
    M2C_FIELD(temp_r2, s8 *, 1) = 7;
    func_0204d828();
    func_0204d77c();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_020380f0(0);
    func_0202f564(&func_0204d630, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02038100;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0204d8d0;
    func_0202c1a0(1);
}
