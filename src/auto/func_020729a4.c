#include "m2c.h"

s32 func_0201e140();                                /* extern */
M2C_UNK **func_0202f368();                          /* extern */
void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
extern M2C_UNK func_02071af4;
extern M2C_UNK func_02072944;

void func_020729a4(void) {
    M2C_UNK **temp_r4;

    temp_r4 = func_0202f368();
    if (func_0201e140() != 0) {
        return;
    }
    func_02038384(1);
    M2C_FIELD(func_0202f564(&func_02071af4, 0x11), M2C_UNK ***, 0x24) = temp_r4;
    *temp_r4                                                          = &func_02072944;
}
