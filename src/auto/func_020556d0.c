#include "m2c.h"

M2C_UNK func_0202c03c(void *, M2C_UNK);             /* extern */
void *func_0202f368();                              /* extern */
extern s32 data_021115c0;
extern M2C_UNK func_0205575c;

void func_020556d0(void) {
    M2C_UNK var_r1;
    s32 temp_r1;
    s32 temp_r2;
    void *temp_r0;

    temp_r0                                  = func_0202f368();
    M2C_FIELD(temp_r0, volatile s32 *, 0x24) = (s32) (M2C_FIELD(temp_r0, volatile s32 *, 0x24) + 1);
    temp_r2                                  = M2C_FIELD(temp_r0, volatile s32 *, 0x24);
    if (temp_r2 <= 0x10) {
        temp_r1 = temp_r2 * 0x38;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 8) =
            (s16) (((s32) (temp_r1 + ((u32) (temp_r1 >> 3) >> 0x1C)) >> 4) + 0x60);
        return;
    }
    M2C_FIELD(temp_r0, volatile s32 *, 0x24)               = 0;
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 8) = 0x58;
    if (data_021115c0 == 1) {
        var_r1 = 3;
    } else {
        var_r1 = 0xC;
    }
    func_0202c03c(M2C_FIELD(temp_r0, void **, 0x1C), var_r1);
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_0205575c;
}
