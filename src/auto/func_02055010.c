#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020380f0(M2C_UNK);                     /* extern */
M2C_UNK func_02054e34();                            /* extern */
M2C_UNK func_02054f18();                            /* extern */
M2C_UNK func_0206d550(M2C_UNK, s16);                /* extern */
extern M2C_UNK data_020bb706;
extern s32 data_02110ff0;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02038100;
extern M2C_UNK func_02054cf0;
extern M2C_UNK func_02054fd4;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_02055010(void) {
    s16 var_r1;
    void *temp_r4;

    temp_r4 = func_0202f368();
    var_r1  = M2C_FIELD(func_020197fc(), s16 *, 0x14);
    if ((s32) var_r1 >= 0xD) {
        var_r1 = 0xC;
    }
    data_02110ff0 = (s32) var_r1;
    func_02054f18();
    func_02054e34();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0206d550(2, *((u16 *) ((s8 *) &data_020bb706 + (data_02110ff0 * 0xC))));
    func_020380f0(0);
    func_0202f564(&func_02054cf0, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02038100;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_02054fd4;
    func_0202c1a0(1);
}
