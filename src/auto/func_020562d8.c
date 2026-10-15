#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202b1a0(void *);                      /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */

void func_020562d8(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (M2C_FIELD(func_020197fc(), s16 *, 0x16) == 4) {
        return;
    }
    if (M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x24), s32 *, 0x38) != M2C_FIELD(temp_r4, s32 *, 0x28)) {
        return;
    }
    func_0202ec14(0xB);
    func_0202b1a0(temp_r4 + 0x1C);
    func_0202b1a0(temp_r4 + 0x20);
    M2C_FIELD(temp_r4, s32 *, 0x10) = 1;
}
