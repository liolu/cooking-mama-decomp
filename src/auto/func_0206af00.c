#include "m2c.h"

s32 func_02000d54(s32, s32);                        /* extern */
M2C_UNK func_0202c03c(void *, M2C_UNK);             /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK func_0206add4;

void func_0206af00(void) {
    void *temp_r0;
    void *temp_r1;

    temp_r0 = func_0202f368();
    temp_r1 = M2C_FIELD(temp_r0, void **, 0x1C);
    if ((s32) (0x10000 - func_02000d54(M2C_FIELD(temp_r1, s16 *, 8) - 0x60, M2C_FIELD(temp_r1, s16 *, 6) - 0x80)) >
        (s32) M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x24), s32 *, 0x38)) {
        return;
    }
    func_0202c03c(M2C_FIELD(temp_r0, void **, 0x1C), 3);
    func_0202c03c(M2C_FIELD(temp_r0, void **, 0x20), 4);
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_0206add4;
}
