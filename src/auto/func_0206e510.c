#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0206e5d4();                            /* extern */
extern M2C_UNK func_0206e54c;
extern M2C_UNK func_0206e5b0;

void func_0206e510(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_0206e5d4();
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_0206e54c;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0206e5b0;
}
