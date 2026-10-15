#include "m2c.h"

M2C_UNK func_0202bfe4(void *, M2C_UNK);             /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
s32 func_0206e53c();                                /* extern */

void func_0206b364(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (func_0206e53c() < 0xA) {
        return;
    }
    M2C_FIELD(temp_r4, s32 *, 0x38)                           = 0;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 0x1A) = 0;
    func_0202bfe4(M2C_FIELD(temp_r4, void **, 0x1C), 1);
    func_0202ec14(0x3E);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0x1A) = 0x1F;
    M2C_FIELD(temp_r4, s32 *, 0x28)                           = 3;
}
