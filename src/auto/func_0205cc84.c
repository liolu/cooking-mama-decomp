#include "m2c.h"

M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
M2C_UNK **func_0202f368();                          /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038394(M2C_UNK);                     /* extern */
M2C_UNK func_0205cba8();                            /* extern */
extern M2C_UNK data_02111f00;
extern M2C_UNK func_02038288;
extern M2C_UNK func_0205cb64;

void func_0205cc84(void) {
    M2C_UNK **temp_r4;

    temp_r4 = func_0202f368();
    func_02019b4c(&data_02111f00);
    func_0202f564(&func_02038288, 0x15);
    func_02038394(0x258);
    func_0205cba8();
    *temp_r4 = &func_0205cb64;
}
