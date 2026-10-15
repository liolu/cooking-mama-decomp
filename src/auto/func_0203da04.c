#include "m2c.h"

s32 func_0201e140();                                /* extern */
M2C_UNK **func_0202f368();                          /* extern */
extern M2C_UNK data_0210d540;
extern M2C_UNK func_0203d760;

void func_0203da04(void) {
    M2C_UNK **temp_r4;

    temp_r4 = func_0202f368();
    if (func_0201e140() != 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0210d540, void **, 0x10C), s16 *, 8) = 0xB0;
    *temp_r4                                                       = &func_0203d760;
}
