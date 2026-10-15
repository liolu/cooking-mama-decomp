#include "m2c.h"

M2C_UNK func_0201955c(M2C_UNK);                     /* extern */
M2C_UNK func_020197fc();                            /* extern */
M2C_UNK func_02027e18();                            /* extern */
M2C_UNK func_0202a888();                            /* extern */
M2C_UNK func_0202a970();                            /* extern */
M2C_UNK func_0202aa1c();                            /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202edb0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_0202f7e0();                            /* extern */
extern s32 data_020d4ee8;
extern s32 data_020d4ef8;
extern s32 data_020d4efc;
extern s32 data_020d4f04;
extern s32 data_020d4f0c;
extern M2C_UNK func_0202a458;
extern M2C_UNK func_0202a824;
extern M2C_UNK func_0202aa90;
extern M2C_UNK func_0202aad0;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0202ab04(void) {
    void *temp_r4;

    func_0201955c(0);
    func_0202f7e0();
    temp_r4 = func_0202f368();
    func_020197fc();
    data_020d4ee8 = 0;
    data_020d4ef8 = 0;
    data_020d4f04 = 0;
    data_020d4f0c = 0;
    data_020d4efc = 0;
    func_02027e18();
    func_0202aa1c();
    func_0202a970();
    func_0202a888();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(0);
    func_0202f564(&func_0202a458, 0x10);
    func_0202f564(&func_0202a824, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_0202aad0;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0202aa90;
    func_0202c1a0(1);
    func_0202edb0(1);
}
