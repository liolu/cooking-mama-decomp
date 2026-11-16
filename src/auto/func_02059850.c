/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
M2C_UNK **func_0202f368();                          /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038394(s16);                         /* extern */
M2C_UNK func_020597ac();                            /* extern */
M2C_UNK func_0206d550(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_02111b8c;
extern M2C_UNK func_02038288;
extern M2C_UNK func_02059768;

void func_02059850(void) {
    M2C_UNK **temp_r4;
    void *temp_r5;

    temp_r4 = func_0202f368();
    temp_r5 = func_020197fc();
    func_02019b4c(&data_02111b8c);
    func_0202f564(&func_02038288, 0x15);
    if (M2C_FIELD(temp_r5, s16 *, 0x16) == 4) {
        func_02038394((s16) ((0xF - (M2C_FIELD(temp_r5, u8 *, 0x30) * 5)) * 0x3C));
    } else {
        func_02038394(0x384);
    }
    func_0206d550(0xF, 0xC);
    func_020597ac();
    *temp_r4 = &func_02059768;
}
