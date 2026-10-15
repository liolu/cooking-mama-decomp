#include "m2c.h"

M2C_UNK **func_0202f368();                          /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_02038394(M2C_UNK);                     /* extern */
M2C_UNK func_02047aac();                            /* extern */
M2C_UNK func_02047d1c();                            /* extern */
M2C_UNK func_0206d550(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK func_02038288;
extern M2C_UNK func_02047da4;

void func_02047dd4(void) {
    M2C_UNK **temp_r4;

    temp_r4 = func_0202f368();
    func_0202f564(&func_02038288, 0x15);
    func_02038384(0);
    func_02038394(0x7D0);
    func_02047d1c();
    func_02047aac();
    func_0206d550(0x3D, 3);
    *temp_r4 = &func_02047da4;
}
