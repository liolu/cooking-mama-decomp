#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202304c(M2C_UNK);                     /* extern */
M2C_UNK func_02025f88();                            /* extern */
M2C_UNK func_02026068(M2C_UNK);                     /* extern */
M2C_UNK func_020261ac();                            /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202edb0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
extern s32 data_020d4578;
extern s32 data_020d457c;
extern s32 data_020d4580;
extern s32 data_020d4590;
extern s32 data_020d4594;
extern s32 data_020d4598;
extern s32 data_020d45a4;
extern M2C_UNK func_02025a3c;
extern M2C_UNK func_02025e9c;
extern M2C_UNK func_02026220;
extern M2C_UNK func_02026264;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_02026298(void) {
    void *temp_r0;
    void *temp_r4;

    temp_r4       = func_0202f368();
    temp_r0       = func_020197fc();
    data_020d4578 = 0;
    data_020d4598 = 0;
    data_020d45a4 = 0;
    data_020d4580 = 0;
    data_020d4594 = 0;
    data_020d4590 = 0;
    if (M2C_FIELD(temp_r0, s16 *, 0x16) == 3) {
        if (data_020d457c != 0) {
            func_0202304c(2);
        } else {
            func_0202304c(1);
        }
    } else {
        M2C_FIELD(temp_r0, s16 *, 0x16) = 1;
        func_0202304c(0);
    }
    func_020261ac();
    func_02026068(0);
    func_02025f88();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(0);
    func_0202f564(&func_02025a3c, 0x10);
    func_0202f564(&func_02025e9c, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02026264;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_02026220;
    func_0202c1a0(1);
    func_0202edb0(1);
}
