#include "m2c.h"

s32 func_0201e140();                                /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK func_02061bec;

void func_02061d6c(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (func_0201e140() != 0) {
        return;
    }
    if (M2C_FIELD(temp_r4, volatile s32 *, 0x34) == 0) {
        func_0202ec14(0x19);
        M2C_FIELD(temp_r4, volatile s32 *, 0x34) = 1;
    }
    if ((s32) M2C_FIELD(temp_r4, volatile s32 *, 0x30) < 0x3C) {
        return;
    }
    M2C_FIELD(temp_r4, volatile s32 *, 0x24) = 1;
    M2C_FIELD(temp_r4, volatile s32 *, 0x34) = 0;
    M2C_FIELD(temp_r4, volatile s32 *, 0x30) = (s32) M2C_FIELD(temp_r4, volatile s32 *, 0x34);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)        = &func_02061bec;
}
