#include "m2c.h"

M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
void *func_0202f368();                              /* extern */
s32 func_0202f564(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_02038394(s32);                         /* extern */
M2C_UNK func_0206c5e8();                            /* extern */
M2C_UNK func_0206d550(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_021136c4;
extern M2C_UNK func_02038288;
extern M2C_UNK func_0206bb90;
extern M2C_UNK func_0206c3a4;

void func_0206c8d4(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_02019b4c(&data_021136c4);
    func_0202f564(&func_02038288, 0x15);
    func_02038394(0x708);
    func_0206d550(0x45, 6);
    func_0206c5e8();
    M2C_FIELD(temp_r4, s32 *, 0x1C)   = func_0202f564(&func_0206bb90, 0x11);
    M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_0206c3a4;
}
