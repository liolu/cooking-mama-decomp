#include "m2c.h"

M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
M2C_UNK **func_0202f368();                          /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038394(s32);                         /* extern */
M2C_UNK func_02066a10();                            /* extern */
M2C_UNK func_0206d550(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_02112ce0;
extern M2C_UNK func_02038288;
extern M2C_UNK func_020669e0;

void func_02066b78(void) {
    M2C_UNK **temp_r4;

    temp_r4 = func_0202f368();
    func_02019b4c(&data_02112ce0);
    func_0202f564(&func_02038288, 0x15);
    func_02038394(0x834);
    func_0206d550(0x2F, 5);
    func_02066a10();
    *temp_r4 = &func_020669e0;
}
