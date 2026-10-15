#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0201e130(M2C_UNK);                     /* extern */
M2C_UNK **func_0202f368();                          /* extern */
extern M2C_UNK func_0201e150;

void func_0201e490(void) {
    M2C_UNK **temp_r4_2;
    void *temp_r4;

    temp_r4   = func_020197fc();
    temp_r4_2 = func_0202f368();
    if (M2C_FIELD(temp_r4, s16 *, 0x1C) != 0) {
        return;
    }
    func_0201e130(1);
    *temp_r4_2 = &func_0201e150;
}
