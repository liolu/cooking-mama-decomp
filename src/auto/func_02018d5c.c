#include "m2c.h"

M2C_UNK func_02018e28();                            /* extern */
M2C_UNK func_02018ea0();                            /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
extern s32 data_020d3310;
extern M2C_UNK func_02018d50;
extern M2C_UNK func_02018e24;
extern M2C_UNK func_0202caf0;

void func_02018d5c(void) {
    void *temp_r4;

    temp_r4       = func_0202f368();
    data_020d3310 = 1;
    func_02018ea0();
    func_02018e28();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f224(0);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02018d50;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_02018e24;
    func_0202c1a0(1);
}
