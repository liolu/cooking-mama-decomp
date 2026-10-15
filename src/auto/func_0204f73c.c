#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
void *func_0202f564(M2C_UNK *, s32);                /* extern */
M2C_UNK func_020380f0(M2C_UNK);                     /* extern */
M2C_UNK func_0204f49c();                            /* extern */
M2C_UNK func_0204f588();                            /* extern */
M2C_UNK func_0206df2c();                            /* extern */
extern s32 data_021102c8;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02038100;
extern M2C_UNK func_0204f3d4;
extern M2C_UNK func_0204f700;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0204f73c(void) {
    s16 var_r1;
    void *temp_r0;
    void *temp_r4;

    temp_r4                         = func_0202f368();
    temp_r0                         = func_020197fc();
    M2C_FIELD(temp_r4, s16 *, 0x30) = 1;
    var_r1                          = M2C_FIELD(temp_r0, s16 *, 0x14);
    if ((s32) var_r1 >= 0xD) {
        var_r1 = 0xC;
    }
    data_021102c8 = (s32) var_r1;
    if (var_r1 == 2) {
        data_021102c8 = 1;
    }
    func_0204f588();
    func_0204f49c();
    func_0206df2c();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_020380f0(0);
    M2C_FIELD(func_0202f564(&func_0204f3d4, 0x10), s16 *, 0x30) = (s16) M2C_FIELD(temp_r4, s16 *, 0x30);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)                           = &func_02038100;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14)                        = &func_0204f700;
    func_0202c1a0(1);
}
