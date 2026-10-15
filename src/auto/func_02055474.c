#include "m2c.h"

M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
M2C_UNK **func_0202f368();                          /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038394(M2C_UNK);                     /* extern */
M2C_UNK func_020553c0();                            /* extern */
extern M2C_UNK data_021114f0;
extern M2C_UNK func_02038288;
extern M2C_UNK func_02055278;

void func_02055474(void) {
    M2C_UNK **temp_r4;

    temp_r4 = func_0202f368();
    func_02019b4c(&data_021114f0);
    func_0202f564(&func_02038288, 0x15);
    func_02038394(0x4B0);
    func_020553c0();
    *temp_r4 = &func_02055278;
}
