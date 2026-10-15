#include "m2c.h"

M2C_UNK func_0202bda4(void *);                      /* extern */
M2C_UNK func_0202c03c(void *, M2C_UNK);             /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */

void func_0206c1fc(void) {
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, volatile u16 *, 0x56) == 0) {
        M2C_FIELD(temp_r0, volatile s32 *, 0x48)                  = 1;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x38), s16 *, 6)    = 0xC0;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x38), s16 *, 8)    = 0x30;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x38), s16 *, 0x1A) = 0x1F;
        M2C_FIELD(temp_r0, volatile u16 *, 0x56)                  = 1U;
    }
    if (M2C_FIELD(temp_r0, volatile s32 *, 0x4C) == 0) {
        return;
    }
    func_0202ec14(0xB);
    func_0202bda4(M2C_FIELD(temp_r0, void **, 0x28));
    func_0202bda4(M2C_FIELD(temp_r0, void **, 0x2C));
    func_0202c03c(M2C_FIELD(temp_r0, void **, 0x28), 1);
    func_0202c03c(M2C_FIELD(temp_r0, void **, 0x2C), 2);
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x28), s16 *, 0x1A) = 0x1F;
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x2C), s16 *, 0x1A) = 0x1F;
    M2C_FIELD(temp_r0, volatile u16 *, 0x56)                  = 0U;
    M2C_FIELD(temp_r0, volatile s32 *, 0x4C)                  = 0;
    M2C_FIELD(temp_r0, volatile s32 *, 0x48)                  = (s32) M2C_FIELD(temp_r0, volatile s32 *, 0x4C);
    M2C_FIELD(temp_r0, volatile s32 *, 0x44)                  = (s32) (M2C_FIELD(temp_r0, volatile s32 *, 0x44) + 1);
}
