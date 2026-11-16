/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224();                            /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020380f0(M2C_UNK);                     /* extern */
M2C_UNK func_02051374();                            /* extern */
M2C_UNK func_02051450();                            /* extern */
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02038100;
extern M2C_UNK func_020511f4;
extern M2C_UNK func_020514f8;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_02051534(void) {
    void *temp_r4;
    void *temp_r5;

    temp_r5 = func_0202f368();
    temp_r4 = func_020197fc();
    func_02051450();
    func_02051374();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    M2C_FIELD(temp_r4, s16 *, 0x1C) = 1;
    func_0202f224();
    func_020380f0(0);
    func_0202f564(&func_020511f4, 0x10);
    M2C_FIELD(temp_r5, M2C_UNK **, 0)    = &func_02038100;
    M2C_FIELD(temp_r5, M2C_UNK **, 0x14) = &func_020514f8;
    func_0202c1a0(1);
}
