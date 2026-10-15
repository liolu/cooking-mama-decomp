#include "m2c.h"

void *func_0202f368();                              /* extern */
s32 func_02038374();                                /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
extern s32 data_02113ddc;
extern M2C_UNK func_02072848;

void func_02072944(void) {
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, s32 *, 0x54) != 0) {
        return;
    }
    if ((func_02038374() != 2) && (M2C_FIELD(temp_r0, s32 *, 0x44) != data_02113ddc) &&
        ((s32) M2C_FIELD(temp_r0, s32 *, 0x48) < 3)) {
        return;
    }
    func_02038384(0);
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_02072848;
}
