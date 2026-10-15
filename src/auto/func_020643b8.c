#include "m2c.h"

s32 func_0202ac30(s32, M2C_UNK);                    /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
s32 func_0202f564(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_0206dc78(M2C_UNK);                     /* extern */
M2C_UNK func_0206dd6c(M2C_UNK, M2C_UNK);            /* extern */
extern s32 data_02112990;
extern M2C_UNK func_02064344;

void func_020643b8(void) {
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, u16 *, 0x70) == 0) {
        func_0206dd6c(0x40, 0x30);
        M2C_FIELD(temp_r0, u16 *, 0x70) = 1U;
    }
    if (func_0202ac30(M2C_FIELD(temp_r0, s32 *, 0x5C), 0) == 0) {
        return;
    }
    func_0202ec14(0xB);
    M2C_FIELD(temp_r0, u16 *, 0x70) = 0U;
    func_0206dc78(4);
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x58), s16 *, 0x1A) = 0x1F;
    M2C_FIELD(temp_r0, s32 *, 0x30)                           = func_0202f564(&func_02064344, 0x10);
    if (data_02112990 != 2) {
        M2C_FIELD(temp_r0, s32 *, 0x64) = 2;
        return;
    }
    M2C_FIELD(temp_r0, s32 *, 0x64) = 3;
}
