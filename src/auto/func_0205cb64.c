#include "m2c.h"

s32 func_0201e140();                                /* extern */
void *func_0202f368();                              /* extern */
s32 func_0202f564(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
extern M2C_UNK func_0205bba8;
extern M2C_UNK func_0205cb08;

void func_0205cb64(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (func_0201e140() != 0) {
        return;
    }
    func_02038384(1);
    M2C_FIELD(temp_r4, s32 *, 0x48)   = func_0202f564(&func_0205bba8, 0x15);
    M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_0205cb08;
}
