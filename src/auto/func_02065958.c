#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038394(s32);                         /* extern */
M2C_UNK func_02065864();                            /* extern */
M2C_UNK func_0206d550(M2C_UNK, s32);                /* extern */
extern s32 data_02112ad0;
extern M2C_UNK data_02112ba4;
extern M2C_UNK func_02038288;
extern M2C_UNK func_02065820;

void func_02065958(void) {
    s32 var_r0;
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_02019b4c(&data_02112ba4);
    func_0202f564(&func_02038288, 0x15);
    if (M2C_FIELD(func_020197fc(), volatile s16 *, 0x16) == 4) {
        func_02038394(0xE10);
    } else {
        func_02038394(0x834);
    }
    if (data_02112ad0 == 0) {
        var_r0 = 5;
    } else {
        var_r0 = 0xA;
    }
    M2C_FIELD(temp_r4, volatile s32 *, 0x5C) = var_r0;
    func_0206d550(0x28, M2C_FIELD(temp_r4, volatile s32 *, 0x5C));
    func_02065864();
    M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_02065820;
}
