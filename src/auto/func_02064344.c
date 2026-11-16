/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_02112994;
extern M2C_UNK func_0206424c;
extern M2C_UNK func_0206425c;

void func_02064344(void) {
    void *temp_r4;

    temp_r4                                                   = func_0202f368();
    M2C_FIELD(temp_r4, void **, 0x1C)                         = func_0202b024(1, &data_02112994, 8, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 6)    = 0x80;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 8)    = 0x80;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0x1A) = 0;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14)                      = &func_0206424c;
    M2C_FIELD(temp_r4, M2C_UNK **, 0)                         = &func_0206425c;
}
