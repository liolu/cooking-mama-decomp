#include "m2c.h"

s32 func_0201e140();                                /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
M2C_UNK **func_0202f368();                          /* extern */
extern M2C_UNK func_0203089c;

void func_02031788(void) {
    M2C_UNK **temp_r4;

    temp_r4 = func_0202f368();
    if (func_0201e140() != 0) {
        return;
    }
    func_0202ec14(0x35);
    *temp_r4 = &func_0203089c;
}
