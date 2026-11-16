/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0201c690();                            /* extern */
M2C_UNK func_0201c7a4();                            /* extern */
M2C_UNK func_0201c800();                            /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202edb0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
extern s32 data_020d34b0;
extern s32 data_020d34b8;
extern M2C_UNK func_0201c078;
extern M2C_UNK func_0201c740;
extern M2C_UNK func_0201c874;
extern M2C_UNK func_0201c8b4;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0201c8e8(void) {
    void *temp_r4;

    temp_r4       = func_0202f368();
    data_020d34b8 = 0;
    data_020d34b0 = -1;
    func_0201c800();
    func_0201c7a4();
    func_0201c690();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(0);
    func_0202f564(&func_0201c078, 0x10);
    func_0202f564(&func_0201c740, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_0201c8b4;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0201c874;
    func_0202c1a0(1);
    func_0202edb0(1);
}
