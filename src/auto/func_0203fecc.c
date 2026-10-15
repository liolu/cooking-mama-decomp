#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0203fac4();                            /* extern */
M2C_UNK func_0203fe88();                            /* extern */
extern M2C_UNK func_0203fe9c;

void func_0203fecc(void) {
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x24) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x28) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x2A) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x2C) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x2E) = 0;
    func_0203fe88();
    func_0203fac4();
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_0203fe9c;
}
