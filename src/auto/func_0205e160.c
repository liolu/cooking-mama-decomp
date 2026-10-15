#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
M2C_UNK **func_0202f368();                          /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038394(s32);                         /* extern */
M2C_UNK func_0205dfc4();                            /* extern */
M2C_UNK func_0206d550(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_021120a4;
extern M2C_UNK func_02038288;
extern M2C_UNK func_0205def4;

void func_0205e160(void) {
    M2C_UNK **temp_r4;

    temp_r4 = func_0202f368();
    func_02019b4c(&data_021120a4);
    func_0202f564(&func_02038288, 0x15);
    if (M2C_FIELD(func_020197fc(), s16 *, 0x16) == 4) {
        func_02038394(0xE10);
    } else {
        func_02038394(0x834);
    }
    func_0206d550(0x19, 5);
    func_0205dfc4();
    *temp_r4 = &func_0205def4;
}
