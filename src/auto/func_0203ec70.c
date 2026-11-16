/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020380f0(M2C_UNK);                     /* extern */
M2C_UNK func_0203eaa0();                            /* extern */
M2C_UNK func_0203eb8c();                            /* extern */
extern s32 data_0210db50;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02038100;
extern M2C_UNK func_0203e9b4;
extern M2C_UNK func_0203ec34;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0203ec70(void) {
    s16 var_r1;
    void *temp_r4;

    temp_r4 = func_0202f368();
    var_r1  = M2C_FIELD(func_020197fc(), s16 *, 0x14);
    if ((s32) var_r1 >= 9) {
        var_r1 = 8;
    }
    data_0210db50 = (s32) var_r1;
    if ((var_r1 == 0) || (var_r1 == 4)) {
        data_0210db50 = 8;
    }
    func_0203eb8c();
    func_0203eaa0();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_020380f0(0);
    func_0202f564(&func_0203e9b4, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02038100;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0203ec34;
    func_0202c1a0(1);
}
