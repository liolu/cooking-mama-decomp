#include "m2c.h"

s32 func_0202ac30(void *, M2C_UNK);                 /* extern */
M2C_UNK func_0202bfe4(void *, s32);                 /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */

void func_020690b8(void) {
    void *temp_r0;
    void *temp_r0_2;

    temp_r0 = func_0202f368();
    if (func_0202ac30(M2C_FIELD(temp_r0, void **, 0x20), 0) == 0) {
        return;
    }
    func_0202ec14(0x1A);
    func_0202bfe4(M2C_FIELD(temp_r0, void **, 0x20), 1);
    temp_r0_2 = M2C_FIELD(temp_r0, void **, 0x24);
    func_0202bfe4(temp_r0_2, M2C_FIELD(temp_r0_2, u16 *, 0x18) - 0xD);
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x2C), s16 *, 0x1A) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x48)                           = 5;
}
