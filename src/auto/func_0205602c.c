/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
void *func_0202f368();                              /* extern */
void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK func_02038394(s32);                         /* extern */
M2C_UNK func_02055e74();                            /* extern */
extern M2C_UNK data_02111630;
extern M2C_UNK func_02038288;
extern M2C_UNK func_0205580c;
extern M2C_UNK func_02055e20;

void func_0205602c(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_02019b4c(&data_02111630);
    func_0202f564(&func_02038288, 0x15);
    M2C_FIELD(temp_r4, s32 *, 0x40) = 0x800;
    func_02038394(0x708);
    func_02055e74();
    M2C_FIELD(func_0202f564(&func_0205580c, 0x16), void **, 0x20) = temp_r4;
    M2C_FIELD(temp_r4, M2C_UNK **, 0)                             = &func_02055e20;
}
