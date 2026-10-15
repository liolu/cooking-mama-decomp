#include "m2c.h"

void *func_0202f368();                              /* extern */
s32 func_02038374();                                /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_02055a6c();                            /* extern */
extern M2C_UNK func_0205596c;

void func_02055ddc(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_02055a6c();
    if (((s32) M2C_FIELD(temp_r4, s32 *, 0x2C) < (s32) M2C_FIELD(temp_r4, s32 *, 0x40)) && (func_02038374() != 2)) {
        return;
    }
    func_02038384(0);
    M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_0205596c;
}
