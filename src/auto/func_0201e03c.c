#include "m2c.h"

M2C_UNK func_0202ed64();                            /* extern */
void *func_0202f368();                              /* extern */
extern s32 data_020d379c;
extern M2C_UNK func_0202f834;

void func_0201e03c(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (data_020d379c == 0) {
        return;
    }
    func_0202ed64();
    M2C_FIELD(temp_r4, s32 *, 0x1C)   = (s32) data_020d379c;
    M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_0202f834;
}
