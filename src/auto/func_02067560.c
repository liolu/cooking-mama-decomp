/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
M2C_UNK **func_0202f368();                          /* extern */
void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK func_02038394(s32);                         /* extern */
M2C_UNK func_02067480();                            /* extern */
M2C_UNK func_0206d550(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_02112e84;
extern M2C_UNK func_02038288;
extern M2C_UNK func_02066e98;
extern M2C_UNK func_02067444;

void func_02067560(void) {
    M2C_UNK **temp_r7;
    s32 var_r6;
    void *temp_r0;

    temp_r7 = func_0202f368();
    func_02019b4c(&data_02112e84);
    func_0202f564(&func_02038288, 0x15);
    if (M2C_FIELD(func_020197fc(), s16 *, 0x16) == 4) {
        func_02038394(0xE10);
    } else {
        func_02038394(0x708);
    }
    func_0206d550(0x30, 0xA);
    func_02067480();
    var_r6 = 0;
    do {
        temp_r0                               = func_0202f564(&func_02066e98, 0x11);
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x24) = temp_r7;
        M2C_FIELD(temp_r0, s32 *, 0x28)       = var_r6;
        var_r6 += 1;
    } while (var_r6 < 0xA);
    *temp_r7 = &func_02067444;
}
