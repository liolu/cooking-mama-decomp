#include "m2c.h"

s32 func_0202bdf4(void *);                          /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK func_0205fc00;

void func_0205fba4(void) {
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s32 *, 0x2C) != (M2C_FIELD(temp_r0, s32 *, 0x28) + 1)) {
        return;
    }
    if (func_0202bdf4(M2C_FIELD(temp_r0, void **, 0x20)) == 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s32 *, 0x2C) = 0;
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x20), s16 *, 0x1A) = 0x10;
    M2C_FIELD(temp_r0, M2C_UNK **, 0)                         = &func_0205fc00;
}
