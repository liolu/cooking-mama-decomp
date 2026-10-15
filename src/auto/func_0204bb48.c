#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020380f0(M2C_UNK);                     /* extern */
M2C_UNK func_0204b978();                            /* extern */
M2C_UNK func_0204ba60();                            /* extern */
M2C_UNK func_0206df2c();                            /* extern */
extern M2C_UNK data_020b9878;
extern s16 data_0210faa0;
extern void *data_0210faa4;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02038100;
extern M2C_UNK func_0204b8b4;
extern M2C_UNK func_0204bb08;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0204bb48(void) {
    s16 var_r3;
    void *temp_r4;

    temp_r4 = func_0202f368();
    var_r3  = M2C_FIELD(func_020197fc(), s16 *, 0x14);
    if ((s32) var_r3 >= 2) {
        var_r3 = 1;
    }
    data_0210faa0 = var_r3;
    data_0210faa4 = (M2C_UNK *) ((s8 *) &data_020b9878 + (var_r3 * 0x78));
    func_0204ba60();
    func_0204b978();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0206df2c();
    func_020380f0(0);
    func_0202f564(&func_0204b8b4, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02038100;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0204bb08;
    func_0202c1a0(1);
}
