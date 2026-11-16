/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
s32 func_0202e6ac(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_02057874();                            /* extern */
M2C_UNK func_020578d4();                            /* extern */
extern s32 data_0211183c;
extern s32 data_02111840;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_0205781c;
extern M2C_UNK func_0205799c;
extern M2C_UNK func_020579f4;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_02057a30(void) {
    void *temp_r4;

    temp_r4       = func_0202f368();
    data_0211183c = 0;
    func_020578d4();
    func_02057874();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0202f564(&func_0205781c, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_020579f4;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0205799c;
    func_0202c1a0(1);
    data_02111840 = func_0202e6ac(0x2D0, 0, -0x10);
}
