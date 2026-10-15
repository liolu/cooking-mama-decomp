#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_0205ee58();                            /* extern */
M2C_UNK func_0205ef00();                            /* extern */
extern M2C_UNK data_020bcb98;
extern M2C_UNK *data_0211210c;
extern s32 data_02112110;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_0205edb0;
extern M2C_UNK func_0205efa8;
extern M2C_UNK func_0205efc4;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0205f000(void) {
    s32 var_r2;
    void *temp_r0;
    void *temp_r4;

    temp_r4       = func_0202f368();
    temp_r0       = func_020197fc();
    var_r2        = 0;
    data_02112110 = 0;
    if (M2C_FIELD(temp_r0, s16 *, 0x16) == 4) {
        M2C_FIELD(temp_r0, s8 *, 0x31) = 3;
        data_0211210c                  = &data_020bcb98;
    } else {
        if (M2C_FIELD(temp_r0, s16 *, 0x14) != 0) {
            var_r2 = 1;
        }
        data_0211210c = (M2C_UNK *) ((var_r2 * 0x3C) + (s32) &data_020bcb98);
    }
    func_0205ef00();
    func_0205ee58();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0202f564(&func_0205edb0, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_0205efc4;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0205efa8;
    func_0202c1a0(1);
}
