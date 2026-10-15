#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038394(M2C_UNK);                     /* extern */
M2C_UNK func_0205ec20();                            /* extern */
M2C_UNK func_0206d550(M2C_UNK, s32);                /* extern */
M2C_UNK func_0206df1c(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02112114;
extern M2C_UNK data_021121e4;
extern M2C_UNK func_02038288;
extern M2C_UNK func_0205ebdc;

void func_0205edb0(void) {
    s32 var_r0;
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_02019b4c(&data_021121e4);
    func_0202f564(&func_02038288, 0x15);
    func_02038394(0xE10);
    func_0206df1c(&data_02112114);
    if (M2C_FIELD(func_020197fc(), volatile s16 *, 0x14) == 0) {
        var_r0 = 3;
    } else {
        var_r0 = 5;
    }
    M2C_FIELD(temp_r4, volatile s32 *, 0x60) = var_r0;
    func_0206d550(0x1A, M2C_FIELD(temp_r4, volatile s32 *, 0x60));
    func_0205ec20();
    M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_0205ebdc;
}
