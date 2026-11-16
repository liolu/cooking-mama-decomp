/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
M2C_UNK **func_0202f368();                          /* extern */
void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK func_02038394(M2C_UNK);                     /* extern */
M2C_UNK func_020697ac();                            /* extern */
M2C_UNK func_0206d550(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_02113240;
extern M2C_UNK func_02038288;
extern M2C_UNK func_02068be8;
extern M2C_UNK func_0206977c;

void func_02069a00(void) {
    M2C_UNK **temp_r7;
    s32 var_r6;
    void *temp_r0;

    temp_r7 = func_0202f368();
    func_02019b4c(&data_02113240);
    func_0202f564(&func_02038288, 0x15);
    func_02038394(0xE10);
    func_0206d550(0x39, 5);
    func_020697ac();
    var_r6 = 0;
    do {
        temp_r0                               = func_0202f564(&func_02068be8, 0x11);
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x24) = temp_r7;
        M2C_FIELD(temp_r0, s32 *, 0x28)       = var_r6;
        var_r6 += 1;
    } while (var_r6 < 0x3C);
    *temp_r7 = &func_0206977c;
}
