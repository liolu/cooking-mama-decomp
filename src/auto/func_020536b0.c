#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020380f0(M2C_UNK);                     /* extern */
M2C_UNK func_02053524();                            /* extern */
M2C_UNK func_02053608();                            /* extern */
extern s16 data_02110da4;
extern s16 data_02110da8;
extern s16 data_02110dac;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02038100;
extern M2C_UNK func_02053408;
extern M2C_UNK func_02053674;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_020536b0(void) {
    s16 var_r1;
    s16 var_r1_2;
    s16 var_r2;
    void *temp_r4;

    temp_r4 = func_0202f368();
    var_r1  = M2C_FIELD(func_020197fc(), s16 *, 0x14);
    if ((s32) var_r1 >= 4) {
        var_r1 = 3;
    }
    data_02110da8 = var_r1;
    if (var_r1 == 0) {
        var_r2 = 0xC9;
    } else {
        var_r2 = 0xD3;
    }
    data_02110dac = var_r2;
    if (var_r1 == 0) {
        var_r1_2 = 0x52;
    } else {
        var_r1_2 = 0x50;
    }
    data_02110da4 = var_r1_2;
    func_02053608();
    func_02053524();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_020380f0(0);
    func_0202f564(&func_02053408, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02038100;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_02053674;
    func_0202c1a0(1);
}
