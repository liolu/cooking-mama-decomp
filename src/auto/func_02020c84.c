/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_02020a80();                            /* extern */
M2C_UNK func_02020b74();                            /* extern */
M2C_UNK func_02020bb4();                            /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
extern s32 data_020d4144;
extern s32 data_020d4148;
extern s32 data_020d414c;
extern s32 data_020d4150;
extern s32 data_020d4154;
extern M2C_UNK func_02020960;
extern M2C_UNK func_02020c10;
extern M2C_UNK func_02020c50;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_02020c84(void) {
    void *temp_r4;

    temp_r4       = func_0202f368();
    data_020d414c = 1;
    data_020d4154 = 0;
    data_020d4144 = 0x2710;
    data_020d4148 = 0;
    data_020d4150 = 0;
    func_02020bb4();
    func_02020b74();
    func_02020a80();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0202f564(&func_02020960, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02020c50;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_02020c10;
    func_0202c1a0(1);
}
