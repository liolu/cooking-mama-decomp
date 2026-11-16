/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, s32, s32); /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_02113b6c;
extern M2C_UNK func_0206ff18;

void func_0206ff90(void) {
    void *temp_r0;

    temp_r0                           = func_0202f368();
    M2C_FIELD(temp_r0, void **, 0x1C) = func_0202b024(1, &data_02113b6c, 0, M2C_FIELD(temp_r0, s32 *, 0x24), 0);
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 6)   = (s16) M2C_FIELD(temp_r0, s16 *, 0x20);
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 8)   = (s16) M2C_FIELD(temp_r0, s16 *, 0x22);
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 0xA) = 0xE;
    M2C_FIELD(temp_r0, M2C_UNK **, 0)                        = &func_0206ff18;
}
