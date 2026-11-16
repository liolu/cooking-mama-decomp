/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
M2C_UNK **func_0202f368();                          /* extern */
void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK func_02038394(s32);                         /* extern */
M2C_UNK func_02056b40();                            /* extern */
M2C_UNK func_0206d550(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_021117d4;
extern M2C_UNK func_02038288;
extern M2C_UNK func_0205632c;
extern M2C_UNK func_02056afc;

void func_02056c6c(void) {
    M2C_UNK **temp_r7;
    s32 var_r6;
    void *temp_r0;

    temp_r7 = func_0202f368();
    func_02019b4c(&data_021117d4);
    func_0202f564(&func_02038288, 0x15);
    if (M2C_FIELD(func_020197fc(), s16 *, 0x16) == 4) {
        func_02038394(0xE10);
    } else {
        func_02038394(0x5DC);
    }
    func_0206d550(0xA, 5);
    func_02056b40();
    var_r6 = 1;
    do {
        temp_r0                               = func_0202f564(&func_0205632c, 0x11);
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x24) = temp_r7;
        M2C_FIELD(temp_r0, s32 *, 0x28)       = var_r6;
        var_r6 += 1;
    } while (var_r6 < 5);
    *temp_r7 = &func_02056afc;
}
