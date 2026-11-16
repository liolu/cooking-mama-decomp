/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_02112c10;
extern M2C_UNK func_02065ca4;

void func_02065cfc(void) {
    void *temp_r4;

    temp_r4                                                  = func_0202f368();
    M2C_FIELD(temp_r4, void **, 0x1C)                        = func_0202b024(1, &data_02112c10, 5, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), u16 *, 6)   = (u16) M2C_FIELD(temp_r4, u16 *, 0x28);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), u16 *, 8)   = (u16) M2C_FIELD(temp_r4, u16 *, 0x2A);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0xA) = 0xF;
    M2C_FIELD(temp_r4, M2C_UNK **, 0)                        = &func_02065ca4;
}
