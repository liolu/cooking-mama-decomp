/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_02112994;
extern M2C_UNK func_02063b84;

void func_02063be0(void) {
    void *temp_r4;

    temp_r4                                                  = func_0202f368();
    M2C_FIELD(temp_r4, void **, 0x1C)                        = func_0202b024(1, &data_02112994, 7, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 6)   = (s16) M2C_FIELD(temp_r4, s32 *, 0x28);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 8)   = (s16) M2C_FIELD(temp_r4, s32 *, 0x2C);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0xA) = 0xB;
    M2C_FIELD(temp_r4, M2C_UNK **, 0)                        = &func_02063b84;
}
